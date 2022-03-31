void generator(struct site *a_site) {

	srand(time(0));

	int maxPriority = 1000;

	int randomPriority;
	int randomPage_break;

	char* contentArray[21] = {"Amphibians", "Mammals", "Reptiles", "Pacific Giant Salamander", "Mantella", "Darwins Frog",
							  "Amazon River Dolphin", "Dwarf Mongoose", "Tasmanian Devil", "Xenosaur", "Bushmaster", "Komodo Dragon",
							  "Pacific Giant Salamander Info", "Mantella Info", "Darwins Frog Info", "Amazon River Dolphin Info", "Dwarf Mongoose Info", "Tasmanian Devil Info",
							  "Xenosaur Info", "Bushmaster Info", "Komodo Dragon Info"};

	int linkWordArray[21] = {129, 345, 234, 123, 564, 345, 342, 235,
							  345, 678, 453, 234, 657, 940, 434, 342,
							  453, 485, 982, 345, 245};

	//initializing original site into a_site[0]
	a_site[0].groups[0].page_break = 0;
	a_site[0].groups[0].priority = 10;
	a_site[0].groups[1].page_break = 0;
	a_site[0].groups[1].priority = 20;
	a_site[0].groups[2].page_break = 1;
	a_site[0].groups[2].priority = 30;
	a_site[0].groups[3].page_break = 0;
	a_site[0].groups[3].priority = 40;
	a_site[0].groups[4].page_break = 0;
	a_site[0].groups[4].priority = 50;
	a_site[0].groups[5].page_break = 1;
	a_site[0].groups[5].priority = 60;
	a_site[0].groups[6].page_break = 0;
	a_site[0].groups[6].priority = 70;
	a_site[0].groups[7].page_break = 0;
	a_site[0].groups[7].priority = 80;
	a_site[0].groups[8].page_break = 1;
	a_site[0].groups[8].priority = 90;
	a_site[0].groups[9].page_break = 0;
	a_site[0].groups[9].priority = 100;
	a_site[0].groups[10].page_break = 0;
	a_site[0].groups[10].priority = 110;
	a_site[0].groups[11].page_break = 1;
	a_site[0].groups[11].priority = 120;
	a_site[0].groups[12].page_break = 1;
	a_site[0].groups[12].priority = 130;
	a_site[0].groups[13].page_break = 1;
	a_site[0].groups[13].priority = 140;
	a_site[0].groups[14].page_break = 1;
	a_site[0].groups[14].priority = 150;
	a_site[0].groups[15].page_break = 1;
	a_site[0].groups[15].priority = 160;
	a_site[0].groups[16].page_break = 1;
	a_site[0].groups[16].priority = 170;
	a_site[0].groups[17].page_break = 1;
	a_site[0].groups[17].priority = 180;
	a_site[0].groups[18].page_break = 1;
	a_site[0].groups[18].priority = 190;
	a_site[0].groups[19].page_break = 1;
	a_site[0].groups[19].priority = 200;
	a_site[0].groups[20].page_break = 1;
	a_site[0].groups[20].priority = 210;

	for(int j=0; j<21; j++) {
		a_site[0].groups[j].content = contentArray[j];
		a_site[0].groups[j].link_words = linkWordArray[j];
		a_site[0].groups[j].page = -1;
		a_site[0].groups[j].target = -1;
		a_site[0].groups[j].linked_from = -1;
		a_site[0].groups[j].goal = -1;
	}

	a_site[0].fitness = -1;
	a_site[0].order = -1;

	for(int i=1; i<30; i++){

		a_site[i].fitness = -1;
		a_site[i].order = -1;

		//cout<<"Generating site #"<<i<<endl;

		for(int j=0; j<21; j++) {

		//	cout<<"Generating site #"<<i<<" group #"<<j<<endl;

			randomPriority = rand() % maxPriority;
			randomPage_break = rand() % 2;

			a_site[i].groups[j].priority = randomPriority;
			a_site[i].groups[j].page_break = randomPage_break;

			a_site[i].groups[j].content = contentArray[j];
			a_site[i].groups[j].link_words = linkWordArray[j];

			a_site[i].groups[j].page = -1;
			a_site[i].groups[j].target = -1;
			a_site[i].groups[j].linked_from = -1;
			a_site[i].groups[j].goal = -1;

		}

	}

}