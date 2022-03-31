//selection.h
// Anitra Setchell, 1/15/2003
//helper functions to parent selection
//requires srand() to have been called for truly random numbers

//determines whether crossover or mutation will be used
//cross_percent is the desired probability of crossover vs. mutation (a number between 1-100)
int parents(int cross_percent)
{
	//pick a random number between 0-99
	int prob = rand() % 100;

	if(prob < cross_percent)
		return 2;	//crossover - 2 parents
	else
		return 1;	//mutation - 1 parent
}


//returns a number 0-29, representing which site has been chosen
int selection(struct site *array)
{
	int select = rand() %464 +1;	// 465 = 30+29+...+2+1

	int count = 1;
	while (select > count)
	{
		select -= count;
		count++;
	}

	//count is a number 1-30. 30 is 30 times as likely to have been chosen as 1.
	//it represents the (linearized) fitness of the the site chosen to be a parent
	//so we can use it to find which site that is.

	int i=0;
	while (i < 30)
	{
		if (array[i].order == count)
			return i;
		i++;
	}

	return -1;

}
