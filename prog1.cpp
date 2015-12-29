#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Cstudent.h"
using namespace std;



int main()
{
	const int NUM_STUDENTS = 25;
	ifstream studentsFile("studentlist.txt");
	Cstudent students[NUM_STUDENTS],
		fresh[NUM_STUDENTS],
		soph[NUM_STUDENTS],
		jun[NUM_STUDENTS],
		sen[NUM_STUDENTS];
	string line;


	//Checks for the data file before doing anything else
	if (studentsFile.is_open())
	{
		cout << "The original data: " << endl << endl;
		//Iterates through every line in the input file
		for (int i = 0; i < NUM_STUDENTS; i++)
		{
			//reads in one line of the file and stores it as string called line
			getline(studentsFile, line);
			//Find the position of the first space in the line.
			int positionOfFirstSpace = line.find(' ');
			//Starting from the first space in the line, find the position of the next space in the line.
			int positionOfSecondSpace = line.find_first_of(' ', positionOfFirstSpace + 1);
			//Set the name as a string containing everything from the beginning of line to the second space.
			students[i].name = line.substr(0, positionOfSecondSpace);
			//Starting from the second space in the line, find the position of the third space in the line.
			int positionOfThirdSpace = line.find_first_of(' ', positionOfSecondSpace + 1);
			//Set the year as a string containing everything from the second space to the third space in the line.
			students[i].year = line.substr(positionOfSecondSpace, positionOfThirdSpace - positionOfSecondSpace);
			//Set the gpa as a string (converted to float) containing everything from the third space to the end of the line.
			stringstream convert(line.substr(positionOfThirdSpace,'\n'));
			if(!(convert >> students[i].gpa))
                students[i].gpa = 0.00;

            //Print the original data
            cout << students[i].name << ' '
                 << students[i].year << ' '
                 << fixed << setprecision(2)
                 << students[i].gpa << endl;
		}

		//Use Selection Sort to sort the list alphabetically (the master list)

		cout << endl << endl << endl << "The master list: " << endl << endl;

		//Cycle through the entire array of students to find the smallest (first alphabetically) element and save it as a string.
		for (int i = 0; i < NUM_STUDENTS; i++)
		{
			for(int j = i+1; j < NUM_STUDENTS; j++)
            {
                if(students[i].name.compare(students[j].name) > 0)
                {
                    //Swap names
                    string tempName = students[i].name;
                    students[i].name = students[j].name;
                    students[j].name = tempName;
                    //Swap years
                    string tempYear = students[i].year;
                    students[i].year = students[j].year;
                    students[j].year = tempYear;
                    //swap gpa
                    double tempGPA = students[i].gpa;
                    students[i].gpa = students[j].gpa;
                    students[j].gpa = tempGPA;
                }
            }
            //print out the master list
            cout << students[i].name << ' '
                 << students[i].year << ' '
                 << fixed << setprecision(2)
                 << students[i].gpa << endl;
		}

		//Calculate and print average gpa for master list
		double totalGPA = 0;
		for(int i = 0; i < NUM_STUDENTS; i++)
        {
            totalGPA += students[i].gpa;
        }
        cout << endl << "The average GPA for the master list is: " << totalGPA/NUM_STUDENTS;

		//Using sorted master list, create a new array of only freshman
		cout << endl << endl << endl << "The freshman list: " << endl << endl;

        //Count the number of freshman in the list
        int freshmanCounter = 0;
		for(int i = 0; i < NUM_STUDENTS; i++)
        {
            if(students[i].year == " Freshman")
                freshmanCounter++;
        }
        //Create a freshman array with number of elements equal to the number of freshmen.
        Cstudent fresh[freshmanCounter];

        //Populate the freshman array with only the freshman from the master list
        int freshmanPopulater = 0;
        for(int i = 0; i < NUM_STUDENTS; i++)
        {
            if(students[i].year == " Freshman")
            {
                fresh[freshmanPopulater].name = students[i].name;
                fresh[freshmanPopulater].year = students[i].year;
                fresh[freshmanPopulater].gpa = students[i].gpa;
                freshmanPopulater++;
            }
        }
        //print out the freshman list
        for(int i = 0; i < freshmanCounter; i++)
        {
            cout << fresh[i].name << ' '
                 << fresh[i].year << ' '
                 << fixed << setprecision(2)
                 << fresh[i].gpa << endl;
        }

		//Calculate and print average gpa for freshman
		double freshmanGPA = 0;
		for(int i = 0; i < freshmanCounter; i++)
        {
            freshmanGPA += fresh[i].gpa;
        }
        cout << endl << "The average GPA for the freshman is: " << freshmanGPA/freshmanCounter;

        //Using sorted master list, create a new array of only sophomores
		cout << endl << endl << endl << "The sophomore list: " << endl << endl;

        //Count the number of sophomores in the list
        int sophomoreCounter = 0;
		for(int i = 0; i < NUM_STUDENTS; i++)
        {
            if(students[i].year == " Sophomore")
                sophomoreCounter++;
        }
        //Create a sophomore array with number of elements equal to the number of freshmen.
        Cstudent soph[sophomoreCounter];

        //Populate the sophomore array with only the sophomore from the master list
        int sophomorePopulater = 0;
        for(int i = 0; i < NUM_STUDENTS; i++)
        {
            if(students[i].year == " Sophomore")
            {
                soph[sophomorePopulater].name = students[i].name;
                soph[sophomorePopulater].year = students[i].year;
                soph[sophomorePopulater].gpa = students[i].gpa;
                sophomorePopulater++;
            }
        }
        //print out the sophomore list
        for(int i = 0; i < sophomoreCounter; i++)
        {
            cout << soph[i].name << ' '
                 << soph[i].year << ' '
                 << fixed << setprecision(2)
                 << soph[i].gpa << endl;
        }

		//Calculate and print average gpa for sophomore
		double sophomoreGPA = 0;
		for(int i = 0; i < sophomoreCounter; i++)
        {
            sophomoreGPA += soph[i].gpa;
        }
        cout << endl << "The average GPA for the sophomores is: " << sophomoreGPA/sophomoreCounter;

        //Using sorted master list, create a new array of only juniors
		cout << endl << endl << endl << "The junior list: " << endl << endl;

        //Count the number of juniors in the list
        int juniorCounter = 0;
		for(int i = 0; i < NUM_STUDENTS; i++)
        {
            if(students[i].year == " Junior")
                juniorCounter++;
        }
        //Create a junior array with number of elements equal to the number of freshmen.
        Cstudent jun[juniorCounter];

        //Populate the junior array with only the junior from the master list
        int juniorPopulater = 0;
        for(int i = 0; i < NUM_STUDENTS; i++)
        {
            if(students[i].year == " Junior")
            {
                jun[juniorPopulater].name = students[i].name;
                jun[juniorPopulater].year = students[i].year;
                jun[juniorPopulater].gpa = students[i].gpa;
                juniorPopulater++;
            }
        }
        //print out the junior list
        for(int i = 0; i < juniorCounter; i++)
        {
            cout << jun[i].name << ' '
                 << jun[i].year << ' '
                 << fixed << setprecision(2)
                 << jun[i].gpa << endl;
        }

		//Calculate and print average gpa for juniors
		double juniorGPA = 0;
		for(int i = 0; i < juniorCounter; i++)
        {
            juniorGPA += fresh[i].gpa;
        }
        cout << endl << "The average GPA for the juniors is: " << juniorGPA/juniorCounter;

        //Using sorted master list, create a new array of only seniors
		cout << endl << endl << endl << "The senior list: " << endl << endl;

        //Count the number of seniors in the list
        int seniorCounter = 0;
		for(int i = 0; i < NUM_STUDENTS; i++)
        {
            if(students[i].year == " Senior")
                seniorCounter++;
        }
        //Create a senior array with number of elements equal to the number of freshmen.
        Cstudent sen[seniorCounter];

        //Populate the senior array with only the senior from the master list
        int seniorPopulater = 0;
        for(int i = 0; i < NUM_STUDENTS; i++)
        {
            if(students[i].year == " Senior")
            {
                sen[seniorPopulater].name = students[i].name;
                sen[seniorPopulater].year = students[i].year;
                sen[seniorPopulater].gpa = students[i].gpa;
                seniorPopulater++;
            }
        }
        //print out the senior list
        for(int i = 0; i < seniorCounter; i++)
        {
            cout << sen[i].name << ' '
                 << sen[i].year << ' '
                 << fixed << setprecision(2)
                 << sen[i].gpa << endl;
        }

		//Calculate and print average gpa for seniors
		double seniorGPA = 0;
		for(int i = 0; i < seniorCounter; i++)
        {
            seniorGPA += sen[i].gpa;
        }
        cout << endl << "The average GPA for the seniors is: " << seniorGPA/seniorCounter;

	}
	else cout << "Unable to open studentlist.txt";

	return 0;

}
