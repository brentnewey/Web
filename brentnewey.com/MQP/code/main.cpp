#include <iostream>
#include <cstdlib>

#include "site.h"
#include "viable.h"
#include "order.h"
#include "crossover.h"

using namespace std;


void fill(struct site *a_site);
void print(struct site psite);

int NUMGROUPS = 4;		// 4 content groups for each site (see also crossover.h)

int main() {
	struct site *a_site;
	a_site = new site[3];

	fill(a_site);

	//Viability BEFORE crossover
	bool result = is_viable(a_site[0]);
	print(a_site[0]);
	if(result) cout << "Site 0: Success" << endl << endl;
	else cout << "Site 0: Failure" << endl << endl;

	bool result1 = is_viable(a_site[1]);
	print(a_site[1]);
	if(result1) cout << "Site 1: Success" << endl << endl;
	else cout << "Site 1: Failure" << endl << endl;

	crossover(a_site[0], a_site[1]);

	//Viability AFTER crossover
	bool resulta = is_viable(a_site[0]);
	print (a_site[0]);
	if(resulta) cout << "Site 0: Success" << endl << endl;
	else cout << "Site 0: Failure" << endl << endl;

	bool result1a = is_viable(a_site[1]);
	print (a_site[1]);
	if(result1a) cout << "Site 1: Success" << endl << endl;
	else cout << "Site 1: Failure" << endl << endl;

	order(a_site);
	//cout << "fitness: " << a_site[0].fitness << ", order: " << a_site[0].order << endl;
	//cout << "fitness: " << a_site[1].fitness << ", order: " << a_site[1].order << endl;
	//cout << "fitness: " << a_site[2].fitness << ", order: " << a_site[2].order << endl;
}



void fill(struct site *a_site) {

	a_site[0].fitness = 5;
	a_site[1].fitness = 15;
	a_site[2].fitness = 10;

	a_site[0].groups[0].page = 1;
	a_site[0].groups[0].priority = 1;
	a_site[0].groups[0].checked = false;
	a_site[0].groups[0].target = 2;
	a_site[0].groups[0].content = "1 to 2";

	a_site[0].groups[1].page = 2;
	a_site[0].groups[1].priority = 5;
	a_site[0].groups[1].checked = false;
	a_site[0].groups[1].target = 3;
	a_site[0].groups[1].content = "2 to 3";

	a_site[0].groups[2].page = 2;
	a_site[0].groups[2].priority = 10;
	a_site[0].groups[2].checked = false;
	a_site[0].groups[2].target = 1;
	a_site[0].groups[2].content = "2 to 1";

	a_site[0].groups[3].page = 3;
	a_site[0].groups[3].priority = 15;
	a_site[0].groups[3].checked = false;
	a_site[0].groups[3].target = 1;
	a_site[0].groups[3].content = "3 to 1";


	a_site[1].groups[0].page = 1;
	a_site[1].groups[0].priority = 2;
	a_site[1].groups[0].checked = false;
	a_site[1].groups[0].target = 2;
	a_site[1].groups[0].content = "to page 2";

	a_site[1].groups[1].page = 1;
	a_site[1].groups[1].priority = 4;
	a_site[1].groups[1].checked = false;
	a_site[1].groups[1].target = 3;
	a_site[1].groups[1].content = "to page 3";

	a_site[1].groups[2].page = 2;
	a_site[1].groups[2].priority = 6;
	a_site[1].groups[2].checked = false;
	a_site[1].groups[2].target = 1;
	a_site[1].groups[2].content = "page 2";

	a_site[1].groups[3].page = 3;
	a_site[1].groups[3].priority = 8;
	a_site[1].groups[3].checked = false;
	a_site[1].groups[3].target = 1;
	a_site[1].groups[3].content = "page 3";
}

void print(struct site psite)
{
	for (int i=0; i < NUMGROUPS; i++)
	{
		cout << "p " << psite.groups[i].page;
		cout << "  pri " << psite.groups[i].priority;
		cout << "  lt " << psite.groups[i].target <<endl;
		cout << "-------------" << endl;
	}
}