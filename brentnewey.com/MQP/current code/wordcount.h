/* wordcount.h v0.1
   Brent Newey
   1/26/2003
   This function runs through a site as defined in site.h for a given 
   task, and returns the number of words that must be read to accomplish 
   that task. */

int wordcount(struct site temp_site, int task) {

	// We first store the page breaks.  We don't want them sorted
	// when the array gets sorted.
	bool break_array[21];
	
	for(int i = 0; i < 21; i++)
		break_array[i] = temp_site.groups[i].page_break;

	// Now, we perform selection sort on the array.
	struct content_group temp;

	temp_site.groups[task].goal = true;
	for(int i = 0; i < 21; i++) {
		int min = i;
		for(int j = i+1; j <= 20; j++) {
			if(temp_site.groups[j].priority < temp_site.groups[min].priority) min = j;
		}
		temp = temp_site.groups[min];
		temp_site.groups[min] = temp_site.groups[i];
		temp_site.groups[i] = temp;
	}

	// Return the page_breaks to their original positions.
	for(int i = 0; i < 21; i++)
		temp_site.groups[i].page_break = break_array[i];

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
