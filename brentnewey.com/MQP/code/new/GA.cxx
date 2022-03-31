//GA.cxx v1.2
//The whole genetic algorithm
//Anitra Setchell, 2/2/03

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

int main()
{
	static int CROSS_PROB = 60;		//60% crossover, 40% mutation
	static int POP_SIZE = 30;		//30 sites in a population
	static int GENERATIONS = 500;	//GA runs for 100 generations

	struct site *parent_site;
	parent_site = new site[POP_SIZE];

	struct site *child_site;
	child_site = new site[POP_SIZE];

	srand(time(0));

	//create original site and generation 0
	generator(parent_site);

	//for X generations
	for(int i=0; i < GENERATIONS; i++)
	{
		cout << "Population " << i << endl;

		//determine fitnesses for all sites in parent population
		for(int n=0; n < POP_SIZE; n++)
		{	parent_site[n].fitness = fitness(parent_site[n]);}

		//determine ordering for parent population
		order(parent_site);

		//record best, average, worst fitnesses?
		//should we also record the corresponding sites?
		if (!record(parent_site, "fitness.txt"))
			cerr << "Fitness values for generation " << i << " not recorded." << endl;

		//reproduction loop - do until child population is filled

		int child_pop = 0;

		while(child_pop < POP_SIZE)

		{
			int p1, p2;				//positions in the array of 2 parents
			struct site c1, c2;		// 2 child sites
			int num_parents;		//determines mutation or crossover

			num_parents = parents(CROSS_PROB);

			//parent selection
			p1 = selection(parent_site);
			if (p1 >=POP_SIZE)
			{
				cerr << "Selection error" << endl;
				continue;
			}
			c1 = parent_site[p1];

			if(num_parents == 2)	//crossover
			{
				p2 = selection(parent_site);
				if (p2 >=POP_SIZE)
				{
					cerr << "Selection error" << endl;
					continue;
				}
				c2 = parent_site[p2];
				crossover(c1, c2);

				//insert into child pop.
				child_site[child_pop] = c1;
				child_pop++;
				child_site[child_pop] = c2;
				child_pop++;
			}

			else	// num_parents == 1 -> mutation
			{
				mutate(c1);

				//insert into child pop.
				child_site[child_pop] = c1;
				child_pop++;
			}

		} //child population is filled

		//replace old parent population with filled child population
		for (int k=0; k < POP_SIZE; k++)
			parent_site[k] = child_site[k];

	}

}

