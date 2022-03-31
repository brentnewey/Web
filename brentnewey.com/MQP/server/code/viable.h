
#define INDEX 1

int size = 3;

bool is_viable(struct site *a_site);
void site_run(int number, struct site *a_site);

bool is_viable(struct site *a_site) {
	site_run(INDEX, a_site);
	for(int i = 0; i < size; i++) {
		if(a_site->groups[i].checked == false)
			return false;
	}
	return true;
}

void site_run(int number, struct site *a_site) {
	for(int i = 0; i < size; i++) {
		if(a_site->groups[i].page == number) {
			a_site->groups[i].checked = true;
			for(int j = 0; j < size; j++) {
				if(a_site->groups[j].page == a_site->groups[i].target) {
					if(a_site->groups[j].checked == false) {
						site_run((j+1), a_site);
					}
				}
			}
		}
	}
}