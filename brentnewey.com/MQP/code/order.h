/* order.h v0.111
   Brent Newey
   1/26/2003
   This function assigns a decending scale to an array of sites based on 
   their fitness values. */

int o_size = 3; // This is the number of sites in the array of sites.
                // Change this number when you change the number of 
                // sites to be reordered

/* This function takes a pointer to the array of sites and assigns the 
   order field of each site a number based on its fitness field.  Thus, the   
   highest fitness value would have the lowest order, and vice versa */

void order(struct site *a_site) {

	int our_size = o_size;  // A temporary variable used for assigning
                                // order values.

	// These lines assign the value for "max", the maximum fitness 
	// value in the array of sites.
	int max = 0;
	for(int i = 0; i < o_size; i++) {
		if(a_site[i].fitness > max) max = a_site[i].fitness;
	}
	
	// Now, we go through all possible fitness values, and assign them 
        // order values as we increment.
	for(int i = 0; i <= max; i++){
		for(int j = 0; j < o_size; j++) {
			if(a_site[j].fitness == i) {
				a_site[j].order = our_size;
				our_size--;
			}
		}
	}
}
