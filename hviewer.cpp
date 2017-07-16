//Sasha Morgan
#include "dynamic_array_list.h"
using namespace std;
#include <chrono>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using std::cin;


struct info
{
	time_t search_date; //The Date
	string search_name; //name of the website
	string search_loca; //The location
};

int main(int argc, char *argv[])
{

	//User display provides the user with welcome information and all of the commands
	cout << "Welcome, you have entered the Browers Editor by Sasha Morgan" << endl;
	cout << "While the system loads here are a few instruction:" << endl << endl;
	cout << "To show all of your history enter s 0" << endl;
	cout << "To view sites from today enter s 1" << endl;
	cout << "To view sites from yesterday enter s 2" << endl;
	cout << "To view sites from the previous week enter s 3" << endl;
	cout << "To view sites from the current month enter s 4" << endl;
	cout << "To search by filename or location press f, to overwrite the file press w, to remove an entry press r" << endl;
	cout << "To exit the program press C^z or C^d, I hope you enjoy the program" << endl << endl;
	cout << "Please enter a command: ";

	string input; //The command entered by the user
	cin >> input; //stores the user input 

	int num; //the number entered by the use
	cin >> num;

	//Variable Declaration and Assignment that corresponds to the user input
	string begin = "history.csv";

	//Takes in the file
	ifstream retrieve(begin);
	ofstream unload(begin);

	//I will use the dynamic array list to find the information from the file
	DynamicArrayList<info> userhistory;

	//Creates a loop that will run as long as the file is not failing
	while (!retrieve.fail())
	{
		info dataset; //creates a new data set

		time_t now;  //creates a variable that keeps track of te current time
		retrieve >> now; //retrieves the current information

		string webname; //creates a variable for the name of the website
		retrieve >> webname; //retrieves teh name 

		string place; //The location of the information
		retrieve >> place;

		dataset.search_date = time(&now); //finds the current time and sets the variable
		dataset.search_loca = place;  //sets te datasets location equal to the location
		dataset.search_name = webname;

		userhistory.insert(0, dataset); //inserts the information into the beginning of the arraylist
		cout << now << endl; //displays the current date
	}
	do
	{
		int i = 0; //loop counter
		if (input == "s") //makes sure that the user has entered a valid commond
		{
			if (num == 0 || num == 1 || num == 2 || num == 3 || num == 4)
			{
				while (i < userhistory.getLength() - 1)
				{
					time_t currentdate = time(NULL);
					tm* pointer = localtime(&currentdate);
					info list = userhistory.getEntry(i); //gets the information from each entry

					if (num == 0)
					{
						if (list.search_date == pointer->tm_yday) //checks to see if the informaiton was from today
						{
							cout << list.search_date << ", " << list.search_loca << ", " << list.search_name << endl; //prints the information
						}
					}
					if (num == 1)
					{
						if (list.search_date == pointer->tm_yday) //checks to see if the informaiton was from today
						{
							cout << list.search_date << ", " << list.search_loca << ", " << list.search_name << endl; //prints the information
						}
					}
					if (num == 2)
					{
						if (list.search_date == pointer->tm_yday - 1) //checks to see if the information was from yesterday
						{
							cout << list.search_date << ", " << list.search_loca << ", " << list.search_name << endl; //prints the information
						}
					}
					if (num == 3)
					{
						if (list.search_date - pointer->tm_yday - 7 >= 0 && list.search_date - pointer->tm_yday - 7 < 8) //checks to see if the information was from week ago
						{
							cout << list.search_date << ", " << list.search_loca << ", " << list.search_name << endl; //prints the information
						}
					}
					if (num == 4)
					{
						if (list.search_date - pointer->tm_yday <= 31) //checks to see if the information was from week ago
						{
							cout << list.search_date << ", " << list.search_loca << ", " << list.search_name << endl; //prints the information
						}
					}
					i++;
				}//end of while
			}//end of it
		}//end of do

		//If the user want to search by a specific name or location
		else if (input == "f")
		{
			string curs; //input variable
			cin >> curs;
			int i = 0;
			while (i < userhistory.getLength()) //runs through the length of the array
			{
				info pres = userhistory.getEntry(i); //gets the curret entry
				if (pres.search_loca == curs || pres.search_name == curs) //checks to see if te name or location matches the entered information
				{
					cout << pres.search_date << ", " << pres.search_loca << ", " << pres.search_name << endl; //prints the information
				}
				i++;
			}
		} //end of f
		else if (input == "w")
		{
			int i = 0;
			while (i < userhistory.getLength())
			{
				info pres = userhistory.getEntry(i); //gets the curret entry
				cout << pres.search_date << ", " << pres.search_loca << ", " << pres.search_name << endl; //prints the information
			}
		}
		else if (input == "r")
		{
			int cur;
			cin >> cur;
			if (cur == 0)
			{
				userhistory.clear();
			}
			else
			{
				userhistory.remove(cur);
				cout << "This entry " << cur << "has been terminated" << endl;
			}
		}
		else
		{
			cout << "Hault, Who goes there?  Command. Command Who? Oh wait, this command doesnt exist.  Try again." << endl;
		}
		
	} while (input != "C^z" || input != "C^d");
	if (input == "C^z" || input != "C^d")
	{
		cout << "Why do Java Programers wear Glasses? Because they can't C#.  Thank you for stoping in." << endl;
	}
	return 0;
}
