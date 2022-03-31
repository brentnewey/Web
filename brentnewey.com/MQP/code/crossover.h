//crossover.h
// Anitra Setchell, 1/11/2003

//you must include the C standard library, so that rand() can be used.
//For truly random numbers, use srand(time(0)) before crossover is called

int numgroups = 4;	//4 content groups in each site - UPDATE THIS AFTER TESTING

void crossover (struct site &child1, struct site &child2)
{
	int cp = rand() % numgroups;	//cross position
	int split = rand() % 2;		//split the content_group? 0-no split, 1-split

	cout << "Cross position: " << cp << endl << endl;
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
