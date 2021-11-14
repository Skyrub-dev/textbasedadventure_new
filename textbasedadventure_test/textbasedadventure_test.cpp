#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

class MMenu
{
public:

	void MainMenu()
	{
		std::cout << "Main menu:\n"
			"1. Play\n"
			"2. Settings\n"
			"3. Quit\n\n";
	}

	void Play()
	{
		
	}

	void Settings()
	{
		std::cout << "Welcome to settings test\n";
	}

protected:
	//bool quit = false;
	//int selection = 0;
};

class CharacterCreate
{
public:
	/*void setname(std::string name)
	{
		name = name;
	}*/
	std::string role;
	std::string bckgrnd[3] = { "Business", "Army", "Other" }; //obviously finish array maybe add descriptions?
	
	time_t current = time(0);
	char* datetime = ctime(&current);

	//Base personal attributes

	int strength = 0;
	int intelligence = 0;
	int agility = 0;
	int perception = 0;
	int luck = 0;

	//Base practical attributes

	int farming = 0;
	int combat = 0;
	int leadership = 0;
	int bartering = 0;

	//Base (base) stats

	bool base_located = false;
	int defence = 0;


	//special attributes

	//need to fill these out properly, potentially give buisness a boost in bartering
	int businessspecial = 0;

	void businessintro()
	{
		role = "Business";
		std::cout << "intro\n\n";
		std::cout << "These are the attributes you character will begin with:" << "\n\n";

		strength += 3;
		intelligence += 6;
		agility += 4;
		perception += 5;
		luck += 7;

		farming += 2;
		combat += 1;
		leadership += 8;
		bartering += 9;

		std::cout << "Personal skills:\n\n";
		std::cout << "Strength = " << strength << "\n";
		std::cout << "Intelligence = " << intelligence << "\n";
		std::cout << "Agility = " << agility << "\n";
		std::cout << "Perception = " << perception << "\n";
		std::cout << "Luck = " << luck << "\n\n";


		std::cout << "Practical skills:\n\n";
		std::cout << "Farming = " << farming << "\n";
		std::cout << "Combat = " << combat << "\n";
		std::cout << "Leadership = " << leadership << "\n";
		std::cout << "Bartering = " << bartering << "\n\n";

	}

	void armyintro()
	{
		role = "Army";
		std::cout << "intro\n\n";
		std::cout << "These are the attributes you character will begin with:" << "\n\n";

		strength += 7;
		intelligence += 6;
		agility += 8;
		perception += 7;
		luck += 4;

		farming += 5;
		combat += 9;
		leadership += 8;
		bartering += 5;

		std::cout << "Personal skills:\n\n";
		std::cout << "Strength = " << strength << "\n";
		std::cout << "Intelligence = " << intelligence << "\n";
		std::cout << "Agility = " << agility << "\n";
		std::cout << "Perception = " << perception << "\n";
		std::cout << "Luck = " << luck << "\n\n";


		std::cout << "Practical skills:\n\n";
		std::cout << "Farming = " << farming << "\n";
		std::cout << "Combat = " << combat << "\n";
		std::cout << "Leadership = " << leadership << "\n";
		std::cout << "Bartering = " << bartering << "\n\n";

	}
	
};

void createfile(std::string& name, std::string& role, int& strength, int& intelligence, int& agility, int& perception, int& luck)
{
	CharacterCreate newchar;
	
	std::ofstream newfile("playerstats.txt");
	newfile << "//CREATED: " << newchar.datetime;
	newfile << "\n//MODIFY AT YOUR OWN RISK\n\n";
	newfile << name << "\n";
	newfile << role << "\n\n";
	newfile << "//PERSONAL ATTRIBUTES\n";
	newfile << "Strength = " << strength << "\n";
	newfile << "Intelligence = " << intelligence << "\n";
	newfile << "Agility = " << agility << "\n";
	newfile << "Perception = " << perception << "\n";
	newfile << "Luck = " << luck << "\n";
	newfile.flush();
	newfile.close();
}

void newcharacter()
{
	CharacterCreate* intro = new CharacterCreate;
	CharacterCreate newchar;

	std::string name;
	std::string confirm;
	int choice = 0;

	std::cout << "insert intro here";
	std::cout << "What kind of hero are you?\n\n";

	std::cout << "Please enter a name:\n";
	std::cin >> name;
	
	std::cout << "Ah yes, " << name << ", It's becoming more clearer, what kind of person were they in the past?\n";
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << newchar.bckgrnd[i] << std::endl;
	}

	std::cout << "What is your choice?";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		//intro->businessintro();
		newchar.businessintro();

		std::cout << "Is this okay? Y/n ";
		std::cin >> confirm;

		if (confirm == "Y" || confirm == "y")
		{
			std::cout << "begin game here";

			//find a way to send all properties, maybe by use of a function? through to the create file function

			createfile(name, newchar.role, newchar.strength, newchar.intelligence, newchar.agility, newchar.perception, newchar.luck);

			//TO NEXT CPP FILE
		}
		else
		{
			return;
		}
	}
	case 2:
	{
		newchar.armyintro();

		std::cout << "Is this okay? Y/n ";
		std::cin >> confirm;

		if (confirm == "Y" || confirm == "y")
		{
			createfile(name, newchar.role, newchar.strength, newchar.intelligence, newchar.agility, newchar.perception, newchar.luck);
		}

	}
	}
	//come back to doing 'other' later
}



int main()
{
	std::string response;
	
	bool quit = false;
	int selection = 0;
	
	while (!quit)
	{
		MMenu* menupointer = new MMenu();
		menupointer->MainMenu();
		std::cin >> selection;

		switch (selection)
		{
			case 1:
				{
					//TEMP
					//std::string file;
					//pointer->Play();
					std::string create;
					std::string load;

					std::ifstream playerfile;
					bool present;
					playerfile.open("playerstats.txt");
					if (playerfile)
					{
						std::cout << "Save game found! Do you wish to load?\n";
						present = true;
					}
					else
					{
						std::cout << "Save game not found, do you wish to create a new one?\n";
						std::cin >> create;
						if (create == "Y" || create == "y")
						{
							present = false;
							newcharacter();
						}
						else
						{
							main(); // change to go back to menu
						}
					}
				}
			case 2:
				{
					menupointer->Settings();
				}
			case 3:
				{
					std::cout << "Are you sure you want to quit? (Y/N)";
					if (response == "Y" || "y")
					{
						quit = true;
						//delete pointer;
					}
					else
					{
						menupointer->MainMenu();
					}
				}

		}

		return 0;
	}

	//return 0;
}