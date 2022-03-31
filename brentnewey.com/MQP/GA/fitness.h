/* wordcount.h v0.3
   Brent Newey - modified by Anitra Setchell, 1/31/03
   2/14/2003
   This function runs through a site as defined in site.h for a given
   task, and returns the number of words that must be read to accomplish
   that task.

   Fitness fn. uses the word count for the seven tasks to calculate an average
   fitness for the site.*/

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
	for(int i = 0; i < 21; i++) {
		temp_site.groups[i].page = number;
		if (temp_site.groups[i].page_break) number++;
	}

	// Determine which page that the link in each content group
	// points to.
	int location = 0;
	for (int i = 0; i < 21; i++) {
		for(; !temp_site.groups[location].page_break; location++);
		if(location >= 20) break;
		location++;
		temp_site.groups[i].target = temp_site.groups[location].page;

	}

	// Determine the reverse of above: which content group is pointing
	// to me?
	for(int i = 0; i < 21; i++) {
		for(int j = 0; j < 21; j++) {
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


int fitness(struct site a_site) {
	//task must be the target pg's position in the array.

	int *task;
	task = new int[7];
	float *error;
	error = new float[7];
	float sumfit = 0;
	struct site temp_site = a_site;

	//fill task array w/ target page's position values
	task[0] = 5;	//amphibians (dfrog is first on page) - could be 0
	task[1] = 6;	//mammals (ardolphin first on page) - could be 1
	task[2] = 14;	//dfrog - also 5
	task[3] = 16;	//dmongoose - 7
	task[4] = 17;	//tdevil - 8
	task[5] = 19;	//bmaster - 10
	task[6] = 20;	//kdragon - 11

	//error rates for the target pages
	error[0] = 1;	//amphibians
	error[1] = 1.3;	//mammals
	error[2] = 1.5;	//dfrog
	error[3] = 3.2;	//dmongoose
	error[4] = 1.8;	//tdevil
	error[5] = 1.5;	//bmaster
	error[6] = 1.9;	//kdragon

	//task fitness = 70 * error * word count
	int foo;
	for (int i=0; i < 7; i++)
	{
		sumfit += 70 * error[i] * (wordcount(temp_site, task[i]));
	}

	delete task;
	delete error;

	//return average of fitnesses
	return (sumfit/7);

}

void sort(struct site sort_site) {
	// Now, we perform selection sort on the array.
	struct content_group temp;

	for(int i = 0; i < 21; i++) {
		int min = i;
		for(int j = i+1; j <= 20; j++) {
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
	for(int i = 0; i < 21; i++) {
		temp_site.groups[i].page = number;
		if (temp_site.groups[i].page_break) number++;
	}

	// Determine which page that the link in each content group
	// points to.
	int location = 0;
	for (int i = 0; i < 21; i++) {
		for(; !temp_site.groups[location].page_break; location++);
		if(location >= 20) break;
		location++;
		temp_site.groups[i].target = temp_site.groups[location].page;

	}

	// Determine the reverse of above: which content group is pointing
	// to me?
	for(int i = 0; i < 21; i++) {
		for(int j = 0; j < 21; j++) {
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
