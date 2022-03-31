//Modified 2/2/03 Anitra Setchell

void generator(struct site *a_site) {

	cout << "Generator";
	int maxPriority = 1000;
	int randomPriority;
	int randomPage_break;

	char* titleArray[21] = {"Amphibian", "Mammals ", "Reptiles", "PGiantS1", "Mantella ", "DarwinFrog", "ADolphin", "Dmongoose", "TasDevil", "Xenosaur", "Bmaster1", "Kdragon1", "PGiantS2", "Mantella2", "DarwinFrog2", "ADolphin2", "Dmongoose2", "TasDevil2", "Xenosaur2", "Bmaster2", "Kdragon2"};
	char* contentArray[21] = {"Amphibians include frogs, toads, and salamanders. They have moist, smooth skin and are cold-blooded. Amphibians start life as aquatic larvae, but undergo metamorphosis to become land-dwelling adults. Frogs and toads lose their tails in this metamorphosis, but salamanders do not.",
							  "Mammals are warm-blooded and have four limbs. Most give birth to live young, and all feed their young milk. Not all adult mammals have hair, but all mammals have hair at the beginning of their lives. Mammals include whales, dolphins, humans, cats, rodents, dogs, and many other animals. Mammals are also the only animal with a diaphragm, or with three bones in their ears.",
							  "Reptiles have dry, scaly skin. This class of animals includes turtles, snakes, lizards, and crocodiles. Like the amphibians, they are cold-blooded. Unlike the amphibians, they either lay terrestrial eggs or give birth to live young. Reptiles vary quite a bit in their other physical characteristics. Snakes do not have legs, and lizards have legs appropriate to their lifestyle - short and powerful for burrowers, or long for fast-moving lizards. All snakes and crocodiles are predators, but some lizards and turtles are herbivorous.",
							  "The Pacific Giant Salamander is found in temperate rainforests located in the Pacific northwest. They also can be found in cool, moist forests of the western coast of United States and British Columbia. Their diet consists of small rodents, insects, worms, frogs, and smaller snakes. Thier enemies are snakes, weasals, mink, otters and large birds.",
							  "The Mantella is found in the rainforests and moist areas of Madagascar. They eat mainly insects and spiders.Their enemies are mammals, snakes, and birds. Humans also pose a threat to the Mantella due to pet trade and habitat loss.",
							  "You can find Darwin's Frog in the temperate South American rainforests of Chile and Argentina. They also can be found on the forest floor. Their diet consists of insects mainly. Their enemies consist mostly of birds of prey and reptiles. Humans also pose a threat to this frog due to modern industrialization.",
							  "The Amazon River Dolphin can be found in South America in the Amazon and Orinoco river systems. It's diet consists mainly of crabs, shrimp and other fish (especially piranha and the armored catfish). It's enemies are humans and fishermen nets.",
							  "The Dwarf Mongoose's is found in parts of eastern and south-central Afica. It's habitat is mostly bush, semi-desert, woodlands, savanna, and sometimes rainforest. Since it is mostly omnivorous it's diet consists of small mammals, birds, reptiles, insects, eggs and fruit. It's enemies are humans, due to destruction of habitat, larger mammals and snakes.",
							  "You can find the Tasmanian Devil in a variety of habitats on the Island of Tasmania, including temperate like rainforest. It's diet consists mainly of small animals (like wallabies and wombats) and birds, dead animals, reptiles, amphibians, and insects. They are carnivores. It's enemies are mainly humans.",
							  "The Xenosaur can be found in parts of Mexico, Guatemala, and China. They can live in either dry scrub to wet or cloud forest. They eat mainly insects such as ants and termites. Some will eat small fish. Their enemies are large snakes, larger birds and mammals.",
							  "Bush Masters can be found in the rainforests of Central and South America. They can also be found on the forest floors of Colombia, East Ecuador, Brazil, Venezuela, Surinam, French Guiana, Guyana, Trinidad, NE/E Peru, and North Bolivia. They eat mostly smaller mammals. Their enemies are larger birds of prey, especially when they are young.",
							  "The Komodo Dragon lives on the Islands of Indonesia. They are meat eaters (snakes, birds, deer, rodents, and other animals).They also will eat eggs. They are most threatened by poachers (humans).",
							  "Salamanders are species of amphibians that have tails (they are part of the order Caudata, family Salamandridae). There are two species of the Pacific Giant Salamander. They both have very powerful jaws and have a very painful bite. While living mostly on the ground, a few have been found up in trees. One of the few salamanders that is vocal, they will sort of 'bark' when they are frightened. They mate in the spring and the female lays about 100 eggs near a river or stream. Loss of habitat has caused them to be close to an endangered species in British Columbia. Mostly nocturnal, they hide under damp mosses and logs during the day. They do burrow and can dig (they have hard nails). These salamanders love to be near cooler lakes and streams. The Pacific Giant Salamander will discharge a terrible tasting milky substance from the top of their tails to help fight off predators.",
							  "Mantellas are only found on the island of Madagascar. There are about 13 different species of Mantellas. While some are poisonous and even look like poison arrow frogs, they are not the same. Most Mantellas are one to two inches in length. Males have been known to fight with each other over territory. Mantella males 'call' during the day, probably trying to attract females. Mantellas can be found in a variety of colors and patterns. Unlike many amphibians, they do not have webbing on their hands and feet. The female lays small, jelly covered patches of 12-24 eggs on the ground. Some species may lay more eggs. Mantellas are generally found on the ground, however, some species will climb and breed in trees.",
							  "Darwin's frog belongs to the Rhinodermatidae family of frogs. This frog was discovered and named after Charles Darwin. They are usually about 2-3 centimeters in length, have a triangular head, and a nose that sticks out. Darwin's frog is normally greenish or brownish in color. They are well known for their strange reproductive habits. The female lays the eggs and the male guards them for about 2-3 weeks. When he sees movement in the eggs he places (swallows) them in his vocal sac and carries them around. The young are able to feed off their own egg yolk. When they are fully developed froglets, the male releases them and they are ready to begin life as a Darwin's frog. They have a local name of 'Cowboy Frog' in their native countries. It might be because their 'call' sounds like the whistle that herders use to call their cattle. Darwin's frog is threatened by loss of habitat due to human expansion into its territory.",
							  "These dolphins can be pink or gray in color. They are one of only 5 species of freshwater dolphin in the world. They are also the largest of the freshwater dolphins. Their diet consists of 43 species of 19 families of fish; they have developed three stomachs to digest these boney fish, turtles, etc. They have an unfused vertebra in their spine so they can more their heads from side to side. No other aquatic mammal has this unfused vertebra. The Amazon River Dolphin is also known as boto. They are known in Peru as 'Bufeo Colorado' but the correct name is 'Bufeo Rosado,' meaning pink, not red. They can be up to 9 feet long or more and usually weigh between 190-285 pounds. Their echo-location ability is excellent. During the rainy season, when the Amazon River floods, they swim amongst the rainforest trees, which are under water. Unlike most dolphin species, this dolphin does not have a dorsal fin, but instead has a ridge on its back. The Amazon River Dolphin is born a dark gray, but gets pinker as it gets older. Scientists are not quite sure why. They often hunt and feed alone, but are sometimes found in groups of 5-8.",
							  "These mongooses have four or five toes on each foot and have non-retractable claws. They have 35-40 teeth. They can live up to 10 years of age. Some live longer, some live less. Dwarf Mongooses live in a pack and are highly socialized. The average pack size is about 8. They live in termite-like dens, sometimes actually in old abandoned termite mounds. During the mating season the mother has 2-3 litters of 1-6 young. The young are born with fur and are blind. Dwarf Mongooses have a highly developed inner ear and their hearing and eyesight are excellent. They are diurnal which means most of their activities occur during the daytime.",
							  "The Tasmanian devil is a marsupial. They are mostly black, but do have some white markings (usually on the chest and rump). Males are larger than females and can weigh up to 12 kg, and stand about 30 cm high at the shoulder. Their life span is about 7 -8 years. They have an excellent sense of smell. Tasmanian devils live in underground burrows. They are nocturnal and mostly solitary (except when mating or feeding together). Females give birth to up to four pups. With their jet black appearance, frightening screams, and powerful teeth and jaws, the Tasmanian devil sometimes strikes fear into people. In reality, younger devils are easily handled by children.  Tasmanian devils are scavengers and will eat everything from a dead carcass except the very largest bones. Many times they will feed on a dead animal together. As scavengers, they are good for the land because they remove dead carcasses. However, they are also predators, and have a very strong jaw with a powerful set of teeth. While mostly found on the ground, they can climb trees. Tasmania, the home of the Tasmanian devil, has the highest average rainfall of any Australian State.",
							  "Xenosaurs are one of four species of lizards that belong to the Xenosauridae Family. They range in size from 10-15 cm. They are mainly nocturnal land animals, who will sometimes enter the water. Xenosaurs are found in hollow logs, holes in trees, and very narrow crevices. They don't move around too much and mainly wait for prey to come to them. They give birth to 4-7 live young at a time, instead of laying eggs. Xenosaurs can deliver a painful bite, but they are not poisonous.",
							  "The Bushmaster is one of the largest venomous snakes in the Americas and its bite can be fatal. They are mostly solitary and nocturnal. There are three subspecies of bushmaster snakes: Lachesis muta muta,Lachesis muta noctivaga, and Lachesis muta rhombeata. Their young are born from eggs, which is unusual because most vipers bear live young. Adult bushmasters reach a length of about 8 - 12 feet. They are gray and brown and they blend in perfectly with leaf litter on the rainforest floor. When threatened they shake their tail like a rattlesnake.",
							  "The largest of the monitor lizards, the Komodo dragon can grow up to 10 feet long. The males (up to 300 pounds) are bigger than females (up to 200 pounds).  They usually live around 20 years, but can live longer. They shed and replace their teeth, just like a shark. They are capable of swimming and are very fast runners, but only for a short distance. If hungry enough they will eat other Komodo dragons. The Komodo dragon has a very keen sense of smell. They are an endangered species."};

	int linkWordArray[21] = {40, 64, 82, 55, 39, 52, 40, 53, 47, 47, 55, 31, 156, 123, 163, 204, 111, 196, 86, 92, 90};

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

		//cout<<"Generating site #"<<i<<endl;

		for(int j=0; j<21; j++) {

		//	cout<<"Generating site #"<<i<<" group #"<<j<<endl;

			randomPriority = rand() % maxPriority;
			randomPage_break = rand() % 2;

			a_site[i].groups[j].priority = randomPriority;
			a_site[i].groups[j].page_break = randomPage_break;

			a_site[i].groups[j].content = contentArray[j];
			a_site[i].groups[j].title = titleArray[j];
			a_site[i].groups[j].link_words = linkWordArray[j];
			a_site[i].groups[j].page = -1;
			a_site[i].groups[j].target = -1;
			a_site[i].groups[j].linked_from = -1;
			a_site[i].groups[j].goal = false;

		}

	}

}
