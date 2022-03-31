//stest.cxx
//Tests parent selection mechanisms

#include <iostream>
#include <cstdlib>
#include <ctime>		//provides time()

#include "site.h"
#include "order.h"
#include "selection.h"	//provides parents() and selection()

using namespace std;


void fill(struct site *a_site);

int main() {
	srand((unsigned)time(0));

	struct site *a_site;
	a_site = new site[30];
	int p1, p2;				//positions in the array of 2 parents
	site c1, c2;			// 2 child sites

	fill(a_site);
	order(a_site);

	int num_parents;
	num_parents = parents(60);	//60% crossover, 40% mutation

	p1 = selection(a_site);
	c1 = a_site[p1];
	cout <<"Parent 1: " << p1 << " Fitness: " << a_site[p1].fitness << endl;
	c1.fitness = 10;
	cout <<"Parent 1 fitness: " << a_site[p1].fitness
		 << " child 1 fitness: " << c1.fitness << endl;


	if (num_parents == 2)
	{
		p2 = selection(a_site);
		c2 = a_site[p2];
		cout <<"Parent 2: " << p2 << " Fitness: " << a_site[p2].fitness << endl;
		c2.fitness = 100;
			cout <<"Parent 2 fitness: " << a_site[p2].fitness
		 << " child 2 fitness: " << c2.fitness << endl;
	}

	return 0;
}


void fill(struct site *a_site) {
	a_site[0].fitness = 5;
	a_site[1].fitness = 15;
	a_site[2].fitness = 10;
	a_site[3].fitness = 100;
	a_site[4].fitness = 30;
	a_site[5].fitness = 550;
	a_site[6].fitness = 300;
	a_site[7].fitness = 289;
	a_site[8].fitness = 223;
	a_site[9].fitness = 294;
	a_site[10].fitness = 881;
	a_site[11].fitness = 325;
	a_site[12].fitness = 150;
	a_site[13].fitness = 101;
	a_site[14].fitness = 320;
	a_site[15].fitness = 999;
	a_site[16].fitness = 543;
	a_site[17].fitness = 600;
	a_site[18].fitness = 2;
	a_site[19].fitness = 10;
	a_site[20].fitness = 998;
	a_site[21].fitness = 350;
	a_site[22].fitness = 22;
	a_site[23].fitness = 331;
	a_site[24].fitness = 50;
	a_site[25].fitness = 60;
	a_site[26].fitness = 35;
	a_site[27].fitness = 34;
	a_site[28].fitness = 722;
	a_site[29].fitness = 42;
}