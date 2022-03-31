//Modified 3/27/03 Mike Wicks
//contentArray removed

#include <stdlib.h>

void generator(struct site *a_site) {
	cout << "Generator\n";
	int maxPriority = 1000;
	int randomPriority;
	int randomPage_break;

	char* titleArray[18] = {"Korfball", "Horse Vaulting", "Tchoukball", "C & T Relay", "Skijoring", "Skittles", "Pickleball", "Eton Fives", "Sepak Takraw", "Pachyderm Polo", "Octopush", "Kabbadi ", "Canoe Tilting", "Petanque", "Cup Stacking", "Dressage", "Noodling", "Cheese Rolling"};
	int linkWordArray[18] = {120,94,125,129,167,170,118,167,196,193,259,205,96,138,57,186,209,117};

	//initializing original site into a_site[0]
	a_site[0].groups[0].page_break = 0;
	a_site[0].groups[0].priority = 10;
	a_site[0].groups[1].page_break = 1;
	a_site[0].groups[1].priority = 20;
	a_site[0].groups[2].page_break = 0;
	a_site[0].groups[2].priority = 30;
	a_site[0].groups[3].page_break = 1;
	a_site[0].groups[3].priority = 40;
	a_site[0].groups[4].page_break = 0;
	a_site[0].groups[4].priority = 50;
	a_site[0].groups[5].page_break = 1;
	a_site[0].groups[5].priority = 60;
	a_site[0].groups[6].page_break = 0;
	a_site[0].groups[6].priority = 70;
	a_site[0].groups[7].page_break = 0;
	a_site[0].groups[7].priority = 80;
	a_site[0].groups[8].page_break = 0;
	a_site[0].groups[8].priority = 90;
	a_site[0].groups[9].page_break = 0;
	a_site[0].groups[9].priority = 100;
	a_site[0].groups[10].page_break = 1;
	a_site[0].groups[10].priority = 110;
	a_site[0].groups[11].page_break = 0;
	a_site[0].groups[11].priority = 120;
	a_site[0].groups[12].page_break = 1;
	a_site[0].groups[12].priority = 130;
	a_site[0].groups[13].page_break = 0;
	a_site[0].groups[13].priority = 140;
	a_site[0].groups[14].page_break = 1;
	a_site[0].groups[14].priority = 150;
	a_site[0].groups[15].page_break = 0;
	a_site[0].groups[15].priority = 160;
	a_site[0].groups[16].page_break = 0;
	a_site[0].groups[16].priority = 170;
	a_site[0].groups[17].page_break = 1;
	a_site[0].groups[17].priority = 180;

	for(int j=0; j<18; j++) {
		a_site[0].groups[j].link_words = linkWordArray[j];
		a_site[0].groups[j].title = titleArray[j];		a_site[0].groups[j].page = -1;		a_site[0].groups[j].target = -1;
		a_site[0].groups[j].linked_from = -1;
		a_site[0].groups[j].goal = false;
	}

	a_site[0].fitness = -1;
	a_site[0].order = -1;
	a_site[0].goal = -1;

	for(int i=1; i<30; i++){

		a_site[i].fitness = -1;
		a_site[i].order = -1;
		a_site[i].goal = -1;

		for(int j=0; j<18; j++) {

			randomPriority = rand() % maxPriority;
			randomPage_break = rand() % 2;

			a_site[i].groups[j].priority = randomPriority;
			a_site[i].groups[j].page_break = randomPage_break;

			a_site[i].groups[j].title = titleArray[j];
			a_site[i].groups[j].link_words = linkWordArray[j];
			a_site[i].groups[j].page = -1;
			a_site[i].groups[j].target = -1;
			a_site[i].groups[j].linked_from = -1;
			a_site[i].groups[j].goal = false;

		}

	}

}
