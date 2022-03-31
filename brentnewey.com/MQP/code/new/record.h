//record.h
// records (best, worst, average) fitness values for the given array of sites
// 1/27/03
// Anitra Setchell


void printsite(struct site temp)
{
	for (int i=0; i < 18; i++)
	{
		cout << temp.groups[i].title << "\tPriority: " << temp.groups[i].priority
			 <<"\tBreak: " << temp.groups[i].page_break
			 << "\tWords: " <<temp.groups[i].link_words << endl;
	}
	cout << "SITE FITNESS: " << temp.fitness << endl;
}

bool record(struct site *a_site, char* filename)
{
    const int POP_SIZE = 30;
    int best, worst, average;
    int sum = 0;

    for(int i=0; i < POP_SIZE; i++)
    {
	    //average fitnesses
	    sum += a_site[i].fitness;

	    //record fitness/site with order=MAX, order=1
	    if (a_site[i].order == 1)
	    	worst = a_site[i].fitness;

	    if (a_site[i].order == POP_SIZE) {

	    	best = a_site[i].fitness;
	    	cout <<endl << "Best site: " << endl;
	    	struct site temp = a_site[i];
	    	sort(temp);
	    	printsite(temp);
		}

	}

	average = sum/POP_SIZE;

    //print out to a file
    ofstream out;
    out.open(filename, ios::app);
    if (!out.is_open())
    	return false;

    out << best << "\t" << average << "\t" << worst << endl;
    out.close();

    //if everything went smoothly with output, return true
    return true;
}
