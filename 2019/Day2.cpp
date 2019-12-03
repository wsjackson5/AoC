// Advent of code 2019, Day 2, Part 1 & 2
// Requires "input.txt" in same directory as executable.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

bool getData(string file, vector<string> & inputData);
size_t incIndex(size_t index, int increment, vector<int> & cleanData);
int runProgram(vector<int> cleanData, int noun, int verb);
 
const int debug {0}; 	//'0' for result only, '1' for console debugging output.

int main()
{
	int noun {12}; 
	int verb {2};
	vector<string> inputData;
	bool data = getData("input.txt", inputData);
	if (data)
	{
		vector<int> cleanData;
		for(string line : inputData)
			cleanData.push_back(stoi(line));
		int x {0};
		cout << "Part 1: " << runProgram(cleanData, noun, verb) << endl;
		for (unsigned i {0}; i <= 99; i++)
		{
			for (unsigned j {0}; j <= 99; j++)
			{
				x = runProgram(cleanData, i, j);
				if (debug)
					cout << x << endl;
				if  (x == 19690720)
				{
					cout << "Part 2: " << i * 100 + j << endl;
					i = 100;
					j = 100;
				}
			}
		}
	}
	else
	{
		cout << "NO DATA" << endl;
	}
	return 0;
}

int runProgram(vector<int> cleanData, int noun, int verb)
{
	cleanData.at(1) = noun;
	cleanData.at(2) = verb;
	if (debug)
	{
		for(int line : cleanData)
			cout << line << " ";
		cout << endl << "---------------------------------------------" << endl;
	}
	int opCode {0};
	const int a {1};
	const int b {2};
	const int c {3};
	const int d {4};
	for (size_t index {0}; index <  cleanData.size(); )
	{
		opCode = cleanData.at(index);
		if (opCode == 1)
		{
			if (debug)
				cout << opCode << " ADD " <<  cleanData.at(cleanData.at(incIndex(index, a, cleanData))) << " + " << cleanData.at(cleanData.at(incIndex(index, b, cleanData))) << " store @ " << cleanData.at(incIndex(index, c, cleanData)) << endl;
			cleanData.at(cleanData.at(incIndex(index, c, cleanData))) = cleanData.at(cleanData.at(incIndex(index, a, cleanData))) + cleanData.at(cleanData.at(incIndex(index, b, cleanData)));
			index = incIndex(index, d, cleanData);
		}
		else if (opCode == 2)
		{
			if (debug)
				cout << opCode << " MULT " <<  cleanData.at(cleanData.at(incIndex(index, a, cleanData))) << " * " << cleanData.at(cleanData.at(incIndex(index, b, cleanData))) << " store @ " << cleanData.at(incIndex(index, c, cleanData)) << endl;
			cleanData.at(cleanData.at(incIndex(index, c, cleanData))) = cleanData.at(cleanData.at(incIndex(index, a, cleanData))) * cleanData.at(cleanData.at(incIndex(index, b, cleanData)));
			index = incIndex(index, d, cleanData);
		}
		else if (opCode == 99)
		{
			if (debug)
				cout << opCode << " HALT " << endl;
			index = cleanData.size();
		}
		else
		{
			if (debug)
				cout << opCode << " NOP " << endl;
			index = incIndex(index, d, cleanData);
		}
		if (debug)
		{
			cout << "---------------------------------------------" << endl;
			for(int line : cleanData)
				cout << line << " ";
			cout << endl << "---------------------------------------------" << endl;		
		}	
	}
	return cleanData.at(0);
}

bool getData(string file, vector<string> & inputData)
{
	string line;
	ifstream in(file.c_str());
	
	while (getline(in, line, ','))
	{
		if (line.size() > 0)
		{
			inputData.push_back(line);
		}
	}
	
	in.close();
	return true;
}

size_t incIndex(size_t index, int increment, vector<int> & cleanData)
{
	if (index + increment > cleanData.size())
	{
		cout << " Out of Bounds " << endl;
		index = cleanData.size();
	}
	else 
	{
		index += increment;
	}
	return index;
}
