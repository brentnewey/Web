//sitewords.cxx

#include <iostream>
#include <cstdlib>
#include <ctime>		//provides time()

#include "site.h"
#include "generator.h"
#include "fitness.h"

int main() {

	srand(time(0));

	struct site *s;
	s = new site[30];

	generator(s);

	cout << "Amphibians: " << wordcount(s[0], 5) << endl
		 << "Mammals: " << wordcount(s[0], 6) << endl
		 << "Dfrog: " << wordcount(s[0], 14) << endl
		 << "Dmongoose: " << wordcount(s[0],16) << endl
		 << "Tdevil: " << wordcount(s[0], 17) << endl
		 << "Bmaster: " << wordcount(s[0], 19) << endl
		 << "Kdragon: " << wordcount(s[0], 20) << endl;

}