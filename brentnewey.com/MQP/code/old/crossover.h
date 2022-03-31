//crossover.h
// Anitra Setchell, 1/11/2003
// v 1.3 1/30
//you must include the C standard library, so that rand() can be used.
//For truly random numbers, use srand(time(0)) before crossover is called

int numgroups = 21;		//21 content groups in each site

void crossover (struct site &child1, struct site &child2)
{
	int cp = rand() % numgroups;	//cross position
	int split = rand() % 2;		//split a content_group? 0-no split, 1-split

	//cout << "Cross position: " << cp << endl;
	for(int i=0; i < cp; i++)
	{
		content_group temp;
		temp = child1.groups[i];
		child1.groups[i] = child2.groups[i];
		child2.groups[i] = temp;
	}
	if(split)
	{
		int temp;
		temp = child1.groups[cp].priority;
		child1.groups[cp].priority = child2.groups[cp].priority;
		child2.groups[cp].priority = temp;
	}
	else
	{
		content_group temp;
		temp = child1.groups[cp];
		child1.groups[cp] = child2.groups[cp];
		child2.groups[cp] = temp;
	}
}
