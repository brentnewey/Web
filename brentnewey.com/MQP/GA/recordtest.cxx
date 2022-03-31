//recordtest.cxx

#include <fstream>
#include "site.h"
#include "order.h"
#include "record.h"

int main()
{
	struct site *array;
	array = new site[4];

	array[0].fitness = 9000;
	array[1].fitness = 330;
	array[2].fitness = 1500;
	array[3].fitness = 20;

	array[0].order = 1;
	array[1].order = 3;
	array[2].order = 2;
	array[3].order = 4;

	if(!record(array))
		cout <<"No fitness output." << endl;
}