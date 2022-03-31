/* viable.h v0.11
   Brent Newey
   1/13/2003 */

#define INDEX 1  // The value of the index page.

int size = 3;    // The number of content groups in the site.
bool *the_array; // An array of true/false values to keep track of what
                 // content groups have been visited in the recursion 
                 // tree.

bool is_viable(struct site a_site);
void site_run(int number, struct site a_site);
void convert(struct site a_site);

/* Takes a site and returns a true/false value dictating whether the graph 
   of the site formed by linking the content groups is connected. */

bool is_viable(struct site a_site) {
	the_array = new bool[size]; // Dynamically assign the size of the 
                                    // array.

        // Initialize all values to false.
	for (int i = 0; i < size; i++) {
		the_array[i] = false;
	}

	convert(a_site);
	cout << a_site.groups[0].target_page << endl;
	site_run(INDEX, a_site);    // Begin recursion.

        // If any of the boolean array values or false, then the graph is 
        // not connected, and we return false.
	for(int i = 0; i < size; i++) {
		if(the_array[i] == false) {
			return false;
		}
	}
	return true;
}

void convert(struct site a_site) {
	for(int i = 0; i < size; i++) {
		a_site.groups[i].target_page = a_site.groups[a_site.groups[i].target].page;
	}
}

/* This function does the recursion.  It takes in a number as the current 
   page number and the website, and fills in the values of the boolean 
   array. */

void site_run(int number, struct site a_site) {
	for(int i = 0; i < size; i++) {
		if(a_site.groups[i].page == number) {

			// Here, we check for the page that corresponds to 
                        // the current page, starting with the index.
			the_array[i] = true;

			// Now, take all the pages connected to this page 
                        // that have not been checked yet, and recurse for 
                        // each.
			for(int j = 0; j < size; j++) {
				if(a_site.groups[j].page == a_site.groups[i].target_page) {
					if(the_array[j] == false) {
						site_run((j+1), a_site);
					}
				}
			}
		}
	}
}
