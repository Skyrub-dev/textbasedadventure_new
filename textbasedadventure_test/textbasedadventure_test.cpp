#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

/*LOWDOWN FOR FURTURE TOM: The main menu needs some tweaking to get it to work properly but for the most part
it works, once you've finished the character creator and created all the stats and imported them to the
newcharacter function etc etc, 
create a new file for the actual game, this file I'm intending to only be for the menu
and character creation, you need to create the player's file and then load it into the second cpp file
for the actual game and commence from there*/

/*Links used today:
https://www.geeksforgeeks.org/array-strings-c-3-different-ways-create/
https://mrcodehunter.com/cpp-expression-must-have-class-type-error/#:~:text=In%20c%2B%2B%20whenever%20you%20are%20calling%20any%20function,object%20then%20you%20need%20to%20use%20dot%28.%29%20.
https://www.tutorialspoint.com/the-best-way-to-check-if-a-file-exists-using-standard-c-cplusplus
https://www.tutorialspoint.com/cplusplus-array-of-strings
https://stackoverflow.com/questions/478075/creating-files-in-c
https://social.msdn.microsoft.com/Forums/vstudio/en-US/996e8247-32ce-40f7-b940-48578e970550/how-to-make-a-save-file-for-a-textbased-game-in-console-application-c

https://gamedev.net/forums/topic/499116-saving-and-loading-in-a-text-based-game/499116/
https://stackoverflow.com/questions/29958097/how-to-update-a-c-string-within-a-function
*/

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

	
};

class Business : public CharacterCreate
{
public:
	void businessintro()
	{
		std::cout << "intro\n\n";
		std::cout << "These are the attributes you character will begin with:" << "\n\n";

		strength = 3;
		intelligence = 6;
		agility = 4;
		perception = 5;
		luck = 7;

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
	//attributes of character stored here maybe?
	
};

void createfile(std::string& name, int& strength)
{
	CharacterCreate* intro = new CharacterCreate;

	CharacterCreate newchar;
	
	std::ofstream newfile("Player.txt");
	newfile << "//CREATED: " << newchar.datetime;
	newfile << "\n//MODIFY AT YOUR OWN RISK\n\n";
	newfile << name << "\n";
	newfile << newchar.bckgrnd[0] << "\n\n";
	newfile << "//PERSONAL ATTRIBUTES\n";
	newfile << strength << "\n";
	newfile << newchar.intelligence << "\n";
	newfile << newchar.agility << "\n";
	newfile << newchar.perception << "\n";
	newfile << newchar.luck << "\n";
}

void newcharacter()
{
	CharacterCreate* intro = new CharacterCreate;
	CharacterCreate newchar;

	Business* secondptr = new Business;
	Business buschar;

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
		secondptr->businessintro();

		std::cout << "Is this okay? Y/n ";
		std::cin >> confirm;

		if (confirm == "Y" || "y")
		{
			std::cout << "begin game here";

			newchar.strength += 3;
			newchar.intelligence += 6;
			newchar.agility += 4;
			newchar.perception += 5;
			newchar.luck += 7;

			newchar.farming += 2;
			newchar.combat += 1;
			newchar.leadership += 8;
			newchar.bartering += 9;

			//find a way to send all properties, maybe by use of a function? through to the create file function

			createfile(name, newchar.strength);


			//THIS WORKS BUT NEED TO REDUCE REDUNDANCY
			/*std::ofstream newfile("Player.txt");
			newfile << "//CREATED: " << newchar.datetime;
			newfile << "\n//MODIFY AT YOUR OWN RISK\n\n";
			newfile << newchar.name << "\n";
			newfile << newchar.bckgrnd[0] << "\n\n";
			newfile << "//PERSONAL ATTRIBUTES\n";
			newfile << buschar.strength << "\n";
			newfile << buschar.intelligence << "\n";
			newfile << buschar.agility << "\n";
			newfile << buschar.perception << "\n";
			newfile << buschar.luck << "\n";*/

			//TO NEXT CPP FILE
		}
		else
		{
			return;
		}
	}
	}
	//std::ofstream newfile ("Player.txt");
}



int main()
{
	std::string response;
	
	bool quit = false;
	int selection = 0;
	
	while (!quit)
	{
		MMenu* pointer = new MMenu();
		pointer->MainMenu();
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
					playerfile.open("Player.txt");
					if (playerfile)
					{
						std::cout << "Save game found! Do you wish to load?\n";
						present = true;
					}
					else
					{
						std::cout << "Save game not found, do you wish to create a new one?\n";
						std::cin >> create;
						if (create == "Y" || "y")
						{
							present = false;
							newcharacter();
						}
						else
						{
							return 0; // change to go back to menu
						}
					}
				}
			case 2:
				{
					pointer->Settings();
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
						pointer->MainMenu();
					}
				}

		}

		return 0;
	}

	//return 0;
}