/* wordcount.h v0.1
   Brent Newey
   1/26/2003
   This function runs through a site as defined in site.h for a given 
   task, and returns the number of words that must be read to accomplish 
   that task. */

int wordcount(struct site *a_site, int task) {

	struct site *temp_site;
	temp_site = new site[21];
	temp_site = a_site;

	temp_site.groups[task].goal = true;

	for(int i = 0; i < 20; i++) {
		int min = i;
		for(int j = i+1; j <= right; j++)
			if(temp_site.groups[j].priority < temp_site.groups[min].priority) min = j;
		struct content_group temp = temp_site.groups[j];
		temp_site.groups[min] = temp_site.groups[i];
		temp_site.groups[i] = temp;
	}

	int number = 1;
	for(int i = 0; i < 20; i++) {
		temp_site.groups[i].page = number;
		if (temp_site.groups[i].page_break) number++;
	}

	int location = 0;
	for (int i = 0; i < 20; i++) {
		for(; !temp_site.groups[location].page_break; location++);
		if(location >= 20) break;
		location++;
		temp_site.groups[i].target = temp_site.groups[location].page;

	}

	for(int i = 0; i < 20; i++) {
		temp_site.groups[temp_site.groups[i].target].linked_from = i;
		if(temp_site.groups[i].goal) task = i;
	}

	int total_words = 0;
	while(task >= 0) {
		total_words += temp_site.group[task].link_words;
		if(temp_site.groups[task].page == temp_site.groups[task - 1].page) task--;
		else task = temp_site.group[task].linked_from;
	}

	return total_words;
}
