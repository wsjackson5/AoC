// Advent of code 2019, Day 1, Part 1 & 2
// Requires "input.txt" in same directory as executable.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

bool getData(string file, vector<string> & inputData);
 
int main()
{
	vector<string> inputData;
	bool data = getData("input.txt", inputData);
	int sumA {0};
	int sumB {0};
	int module{0};
	
	if (data)	// Part 1
	{
		for(string line : inputData)
		{
			module = stoi(line);
			sumB += (module / 3 - 2);
		}
	}
	cout << "Part 1: " << sumB << endl;
	
	if (data)	//part 2
	{
		for(string line : inputData)
		{
			module = stoi(line);
			while (module > 0)
			{
				module = (module / 3 - 2);
				if (module > 0)
					sumA += module;
			}
			sumB = sumA;
		}
	}
	cout << "Part 2: " << sumB << endl;
}

bool getData(string file, vector<string> & inputData) 	// Open file and store lines in vector of strings.
{
	string line;
	ifstream in(file.c_str());
	
	while (getline(in, line))
	{
		if (line.size() > 0)
			inputData.push_back(line);
	}
	
	in.close();
	return true;
}
