//modified by Anitra Setchell, 2/1/2003

void mutate(struct site &a_site){

	//cout << "mutate" << endl;

	int maxPriority = 1000;

	int randomContentGroup = rand() % 21;
	int randomMarkerOrPriority = rand() % 2;

	int randomAmount = rand() % 20;
	int randomNegative = rand() % 2;

	if(randomNegative)
		randomAmount = randomAmount * -1;

	/*cout<<endl;
	cout<<"randomContentGroup = "<<randomContentGroup<<endl;
	cout<<"randomMarkerOrPriority = "<<randomMarkerOrPriority<<endl;
	cout<<"randomAmount = "<<randomAmount<<endl;
	cout<<"randomNegative = "<<randomNegative<<endl<<endl;
	*/

	//toggle page_break
	if(randomMarkerOrPriority){
		if(a_site.groups[randomContentGroup].page_break)
			a_site.groups[randomContentGroup].page_break = 0;
		else
			a_site.groups[randomContentGroup].page_break = 1;
	}

	//mutate priority attribute
	else{
		if(a_site.groups[randomContentGroup].priority + randomAmount > maxPriority)
			a_site.groups[randomContentGroup].priority = a_site.groups[randomContentGroup].priority - randomAmount;
		else if(a_site.groups[randomContentGroup].priority + randomAmount < 0)
			a_site.groups[randomContentGroup].priority = a_site.groups[randomContentGroup].priority - randomAmount;
		else
			a_site.groups[randomContentGroup].priority = a_site.groups[randomContentGroup].priority + randomAmount;
	}

}