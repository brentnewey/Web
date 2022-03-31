/* fitness.h v0.4
   Brent Newey - modified by Anitra Setchell, 1/31/03
   3/28/2003
   This function runs through a site as defined in site.h for a given
   task, and returns the number of words that must be read to accomplish
   that task.

   Fitness fn. uses the word count and frequency of the tasks to calculate a
      weighted fitness for the site.*/

void sort(struct site &sort_site);

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
	float error[18];
	float freq[18];
	float sumfit = 0;
	struct site temp_site = a_site;

	freq[0] = 0.20754;	//Korfball
	freq[1] = 0.15094;	//Horse Vaulting
	freq[2] = 0.00;		//Tchoukball
	freq[3] = 0.00;		//Crane & Tortise
	freq[4] = 0.00;		//Skijoring
	freq[5] = 0.13208;	//Skittles
	freq[6] = 0.07547;	//Pickleball
	freq[7] = 0.03774;	//Fives
	freq[8] = 0.00;		//Sepak Takraw
	freq[9] = 0.03774;	//Pachyderm Polo
	freq[10] = 0.01887;	//Octopush
	freq[11] = 0.01887;	//Kabbadi
	freq[12] = 0.13208;	//Canoe Tilting
	freq[13] = 0.00;	//Petanque
	freq[14] = 0.15094;	//Cup Stacking
	freq[15] = 0.00;	//Dressage
	freq[16] = 0.01887;	//Noodling
	freq[17] = 0.01887;	//Cooper's Hill Cheese Rolling

	error[0] = 1.00;	//Korfball
	error[1] = 1.06250;	//Horse Vaulting
	error[2] = 0.00;	//Tchoukball
	error[3] = 0.00;	//Crane & Tortise
	error[4] = 0.00;	//Skijoring
	error[5] = 1.33333;	//Skittles
	error[6] = 1.375;	//Pickleball
	error[7] = 1.00;	//Fives
	error[8] = 0.00;	//Sepak Takraw
	error[9] = 1.00;	//Pachyderm Polo
	error[10] = 1.00;	//Octopush
	error[11] = 1.25;	//Kabbadi
	error[12] = 1.21429;//Canoe Tilting
	error[13] = 0.00;	//Petanque
	error[14] = 1.21875;//Cup Stacking
	error[15] = 0.00;	//Dressage
	error[16] = 1.25;	//Noodling
	error[17] = 1.00;	//Cooper's Hill Cheese Rolling


	//NEW: fitness = freq*(wordcount + error*pagecount)
	// need to compensate for non-chosen content units

	for (int i=0; i < 18; i++)
	{
		sumfit += freq[i] * (wordcount(temp_site, i) + (error[i]*pagecount(temp_site, i)));
	}

	//cout << "Fitness complete" << endl;
	return sumfit;

}

void sort(struct site &sort_site) {
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
