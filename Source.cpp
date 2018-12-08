// Dakota Wilson
// Program 7 - Texas Idol with Arrays
// CMPS 1044 - Dr. Halverson
// 12/4/18
// This program uses 4 prototypes to find the highest score of five scores
//read from an input file that a contestant receives, the lowest score a 
//contestant receives, the average of all scores given with the lowest and 
//highest one omitted, and one that locates the index of the highest average 
//inside of an array. There are 2 arrays in this program one that holds the 
//average scores that were given by the function Calculate_Score and one that 
//holds a string of names given by the input file. It will then use all of 
//these functions an output a nice table that will state the names and averages
//of all contestants. Lastly it will then print the highest average from the 
//array and the name of that person declaring them the winner.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
double Find_Highest(double Num1A, double Num2A, double Num3A, double Num4A,
	double Num5A);
double Find_Lowest(double Num1B, double Num2B, double Num3B, double Num4B,
	double Num5B);
double Calculate_Score(double Num1C, double Num2C, double Num3C, double Num4C,
	double Num5C);
int FindWinner(double ArrayScore[], int Number);
int main()
{
	string Name[35]; //makes an array of string for a name
	int Count, ArrCount, WinIndex;
	double Num1, Num2, Num3, Num4, Num5, Avg[35];

	ifstream infile;
	infile.open("Input.txt");// opens input file
	ofstream outfile;
	outfile.open("Output.txt");// opens output file

	outfile << "Programmer: Dakota Wilson\n";
	outfile << "  Name     Avg.Score\n";
	outfile << "____________________________________\n";

	Count = 0;
	while (infile >> Name[Count] >> Num1 >> Num2 >> Num3 >> Num4 >> Num5) 
		//inputs a Name then 5 inputs from the file until empty
	{
		Avg[Count] = Calculate_Score(Num1, Num2, Num3, Num4, Num5);//calls the 
						   //function to find average score with omited
		Count++;
	}// done reading data from file so countinues on reading the code
	
	for (ArrCount = 0; ArrCount < Count; ArrCount++)
		//used to incrementy index of array to produce names and averages
	{
		outfile << left << setw(8) << Name[ArrCount] << right << setw(10) 
			<< fixed << setprecision(3) << Avg[ArrCount] << '\n';// Formats 
		                                          //the inside of the table
	}// Done outputing data goes to reading rest of code
	
	ArrCount -= 1;// Used so that the function uses the 26 values in the array
	              //and not 27

	WinIndex = FindWinner(Avg, ArrCount);//calls the function to find 
	                                     //the index of the winning average

	outfile << "\nThe winner is " << Name[WinIndex] << " with a score of " 
		<< Avg[WinIndex] << "!";

	infile.close();
	outfile.close();
	return 0;
}

// Function: Find_Highest
// Input: the 5 judges score
// Process: print the highest value of 5 given numbers
// Output: none
// This is used to calculate the highest number of the 5 given scores
double Find_Highest(double Num1A, double Num2A, double Num3A, double Num4A,
	double Num5A)
{
	double Highest;

	if (Num1A > Num2A && Num1A > Num3A && Num1A > Num4A && Num1A > Num5A)
		Highest = Num1A;// Makes it so that the first number given is highest
	else if (Num2A > Num3A && Num2A > Num4A && Num2A > Num5A)
		Highest = Num2A;//Makes it so that the second number given is highest
	else if (Num3A > Num4A && Num3A > Num5A)
		Highest = Num3A;// Makes it so that the third number given is highest
	else if (Num4A > Num5A)
		Highest = Num4A;// Makes it so that the fourth number given is highest
	else
		Highest = Num5A;// Makes it so that the fifth number given is highest

	return  Highest;// gives highest value
}

// Function: Find_Lowest
// Input: the 5 judges score
// Process: print the lowest value of 5 given numbers
// Output: none
// This is used to calculate the lowest number of the 5 given scores
double Find_Lowest(double Num1B, double Num2B, double Num3B, double Num4B,
	double Num5B)
{
	double Lowest;

	if (Num1B < Num2B && Num1B < Num3B && Num1B < Num4B && Num1B < Num5B)
		Lowest = Num1B;// Makes it so that the first number given is lowest
	else if (Num2B < Num3B && Num2B < Num4B && Num2B < Num5B)
		Lowest = Num2B;// Makes it so that the second number given is lowest
	else if (Num3B < Num4B && Num3B < Num5B)
		Lowest = Num3B;// Makes it so that the third number given is lowest
	else if (Num4B < Num5B)
		Lowest = Num4B;// Makes it so that the fourth number given is lowest
	else
		Lowest = Num5B;// Makes it so that the fifth number given is lowest

	return  Lowest;// gives lowest value
}

// Function: Calculate_Score
// Input: the 5 judges score
// Process: calculate the average of the 5 given numbers while omiting the 
//highest and lowest
// Output: none
// This is used to take the 5 inputs and omit the highest and lowest to then
//calculate the avrage of the 3 remaning scores
double Calculate_Score(double Num1C, double Num2C, double Num3C, double Num4C,
	double Num5C)
{
	double Average, HighestScore, LowestScore;

	LowestScore = Find_Lowest(Num1C, Num2C, Num3C, Num4C, Num5C);// uses the 
				 //function for finding the lowest number an gives its value
	HighestScore = Find_Highest(Num1C, Num2C, Num3C, Num4C, Num5C);//uses the
				 //function for finding the highest number an gives its value

	Average = ((Num1C + Num2C + Num3C + Num4C + Num5C) -
		(LowestScore + HighestScore)) / 3; //formula that omits the highest and
										  //lowest value and calculates average

	return Average;// gives average
}

// Function: Find_Winner
// Input: the total number of contestants and the array of average scores
// Process: find the postion of the highest average in the array
// Output: none
// This is used to find the largest average number held in the array and
//returns the position in which that average is located at.
int FindWinner(double ArrayScore[], int Number)
{
	int WinningPos, Inc;
	double WinningScore;// Makes it so avrage scores apear with decimels
	
	WinningScore = 0;
	WinningPos = 0;

	for (Inc = 0; Inc <= Number; Inc++)
		//Used to incremnt arrays to find wining avrage index
	{
		if (WinningScore < ArrayScore[Inc])
		{
			WinningPos = Inc;// when the score is higher then 
			              //the previous one states its index
			WinningScore = ArrayScore[Inc];// makes the 
				  //highest value at the index of the winning 
			      //position the new wining score
		}
	}
	return WinningPos;// Gives index of winning average
}