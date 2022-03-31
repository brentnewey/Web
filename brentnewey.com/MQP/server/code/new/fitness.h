/* fitness.h v0.4
   Brent Newey - modified by Anitra Setchell, 1/31/03
   3/28/2003
   This function runs through a site as defined in site.h for a given
   task, and returns the number of words that must be read to accomplish
   that task.

   Fitness fn. uses the word count and frequency of the tasks to calculate a
      weighted fitness for the site.*/

void sort(struct site sort_site);

int pagecount(struct site temp_site, int task);

int wordcount(struct site temp_site, int task) {

	// We first store the page breaks.  We don't want them sorted
	// when the array gets sorted.
	/*
	bool break_array[21];

	for(int i = 0; i < 21; i++)
		break_array[i] = temp_site.groups[i].page_break;
	*/
	temp_site.groups[task].goal = true;

	sort(temp_site);

	// Return the page_breaks to their original positions.
	/*
	for(int i = 0; i < 21; i++)
		temp_site.groups[i].page_break = break_array[i];
	*/

	// Determine what page each content unit is on
	int number = 1;
	for(int i = 0; i < 18; i++) {
		temp_site.groups[i].page = number;
		if (temp_site.groups[i].page_break) number++;
	}

	// Determine which page that the link in each content group
	// points to.
	int location = 0;
	for (int i = 0; i < 18; i++) {
		for(; !temp_site.groups[location].page_break; location++);
		if(location >= 17) break;
		location++;
		temp_site.groups[i].target = temp_site.groups[location].page;

	}

	// Determine the reverse of above: which content group is pointing
	// to me?
	for(int i = 0; i < 18; i++) {
		for(int j = 0; j < 18; j++) {
			if(temp_site.groups[j].page == temp_site.groups[i].target) {
				temp_site.groups[j].linked_from = i;
			}
		}
		if(temp_site.groups[i].goal) task = i;
	}

	// Move up the array from the goal and add up all the words.
	// When there are still content units above me in the page,
	// use them.  If not, use the linked_from attribute.
	int total_words = 0;
	while(task >= 0) {
		total_words += temp_site.groups[task].link_words;
		if(temp_site.groups[task].page == temp_site.groups[task - 1].page) task--;
		else task = temp_site.groups[task].linked_from;
	}
	return total_words;

}

//FITNESS FUNCTION
int fitness(struct site a_site) {
	//cout << "Fitness" << endl;

	//task must be the target pg's position in the array.
	float hc[18];
	float sumfit = 0;
	struct site temp_site = a_site;

	//"human constant" - error * (normalized)frequency
	hc[0] = 0.20754;	//Korfball
	hc[1] = 0.16037;	//Horse Vaulting
	hc[2] = 0.00;		//Tchoukball
	hc[3] = 0.00;		//Crane & Tortise
	hc[4] = 0.00;		//Skijoring
	hc[5] = 0.17611;	//Skittles
	hc[6] = 0.10377;	//Pickleball
	hc[7] = 0.03774;	//Fives
	hc[8] = 0.00;		//Sepak Takraw
	hc[9] = 0.03774;	//Pachyderm Polo
	hc[10] = 0.01887;	//Octopush
	hc[11] = 0.02359;	//Kabbadi
	hc[12] = 0.16038;	//Canoe Tilting
	hc[13] = 0.00;		//Petanque
	hc[14] = 0.18396;	//Cup Stacking
	hc[15] = 0.00;		//Dressage
	hc[16] = 0.02359;	//Noodling
	hc[17] = 0.01887;	//Cooper's Hill Cheese Rolling

	//OLD task fitness = wordcount + Weighted(error*pagecount)

	//NEW: fitness = wordcount * error * frequency
	// error * frequency is the "human constant"

	for (int i=0; i < 18; i++)
	{
		sumfit += wordcount(temp_site, i) * hc[i];
	}

	//cout << "Fitness complete" << endl;
	return sumfit;

}

void sort(struct site sort_site) {
	// Now, we perform selection sort on the array.
	struct content_group temp;

	for(int i = 0; i < 18; i++) {
		int min = i;
		for(int j = i+1; j <= 17; j++) {
			if(sort_site.groups[j].priority < sort_site.groups[min].priority) min = j;
		}
		temp = sort_site.groups[min];
		sort_site.groups[min] = sort_site.groups[i];
		sort_site.groups[i] = temp;
	}
}


int pagecount(struct site temp_site, int task) {

	temp_site.groups[task].goal = true;

	sort(temp_site);

	// Return the page_breaks to their original positions.
	/*
	for(int i = 0; i < 21; i++)
		temp_site.groups[i].page_break = break_array[i];
	*/

	// Determine what page each content unit is on
	int number = 1;
	for(int i = 0; i < 18; i++) {
		temp_site.groups[i].page = number;
		if (temp_site.groups[i].page_break) number++;
	}

	// Determine which page that the link in each content group
	// points to.
	int location = 0;
	for (int i = 0; i < 18; i++) {
		for(; !temp_site.groups[location].page_break; location++);
		if(location >= 17) break;
		location++;
		temp_site.groups[i].target = temp_site.groups[location].page;

	}

	// Determine the reverse of above: which content group is pointing
	// to me?
	for(int i = 0; i < 18; i++) {
		for(int j = 0; j < 18; j++) {
			if(temp_site.groups[j].page == temp_site.groups[i].target) {
				temp_site.groups[j].linked_from = i;
			}
		}
		if(temp_site.groups[i].goal) task = i;
	}

	// Move up the array from the goal and add up all the words.
	// When there are still content units above me in the page,
	// use them.  If not, use the linked_from attribute.
	int total_pages = 0;
	while(task >= 0) {
		if(temp_site.groups[task].page == temp_site.groups[task - 1].page) task--;
		else {
			task = temp_site.groups[task].linked_from;
			total_pages++;
		}
	}
	return (total_pages - 1);
}
