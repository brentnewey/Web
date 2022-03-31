#include <iostream>
#include <cstdlib>
#include <ctime>		//provides time()
#include <fstream>

#include "site.h"		//provides site and content_group structs
#include "order.h"
#include "fitness.h"	//wordcount() & fitness() fns.
#include "crossover.h"	//uses rand()
#include "mutator2.h"	//uses rand()
#include "selection.h"
#include "generator2.h"	//uses rand()
#include "record.h"		//uses ofstream - prints fitness vals to a file

int main() {

	static int POP_SIZE = 30;

	struct site *parent_site;
	parent_site = new site[POP_SIZE];

	generator(parent_site);
	mutate(*parent_site);

	for (int i = 0; i < 4; i++)
		printsite (parent_site[i]);
	return 0;

}