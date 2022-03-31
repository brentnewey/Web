/* site.h v0.114
   Brent Newey
   1/26/2003
   Defines the content_group and site structures for use with the genetic 
   algorithm. */

struct content_group {

	// Things we can change
	bool page_break; // Associated page.
	int priority;    // Location on page.

	// Internal variables (nothing to do with site)
	int page;        // Assigned page numbers.
	int target;
	int linked_from; // Connection information.
	bool goal;	

	// Things we can't change
	char* content;   // The content string.
	int link_words;  // Words before the link.
};


struct site {

	struct content_group groups[21];

	int fitness;     // Fitness of the site
	int order;       // Order deterimined by fitness

};
