#include <iostream>
#include "site.h"
#include "viable.h"
#include "order.h"

using namespace std;


//bool is_viable(struct site *a_site);
//void site_run(int number, struct site *a_site);
void fill(struct site **a_site);

int main() {
	struct site *a_site[3];
	*a_site = new site[3];

	fill(a_site);
	bool result = is_viable(a_site[0]);
	if(result) cout << "Success" << endl;
	else cout << "Failure" << endl; 
	order(a_site);
	cout << "fitness: " << a_site[0]->fitness << ", order: " << a_site[0]->order << endl;
	cout << "fitness: " << a_site[1]->fitness << ", order: " << a_site[1]->order << endl;
	cout << "fitness: " << a_site[2]->fitness << ", order: " << a_site[2]->order << endl; 
}



void fill(struct site **a_site) {

	a_site[0]->fitness = 5;
	a_site[1]->fitness = 15;
	a_site[2]->fitness = 10; 
	a_site[0]->groups[0].page = 1;
	a_site[0]->groups[0].checked = false;
	a_site[0]->groups[0].target = 2;
	a_site[0]->groups[0].content = "a";

	a_site[0]->groups[1].page = 2;
	a_site[0]->groups[1].checked = false;
	a_site[0]->groups[1].target = 1;
	a_site[0]->groups[1].content = "b";

	a_site[0]->groups[2].page = 3;
	a_site[0]->groups[2].checked = false;
	a_site[0]->groups[2].target = 1;
	a_site[0]->groups[2].content = "c";
}
