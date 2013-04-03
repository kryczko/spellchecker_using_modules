#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void wordFilter(string& word);
bool inDictionary(string word, string dictionry[]); 

void spell(string filename)
{
	//declare the incoming stream
	ifstream inputfile;

	//open the file entered by the user
	inputfile.open(filename.c_str());

	if (inputfile.fail())
	{
		cout << "File " << filename << " could not be opened.\n";
		exit(1);
	}
	else
	{
		cout << "The misspelled words in your file are:\n\n";
		string word;
		while(!inputfile.eof())
		{
			inputfile >> word;

			wordFilter(word);			

			ifstream dictfile;

			dictfile.open("dictionary.txt");
			int i = 0;
			string dictword, dictwords[199];
			while(!dictfile.eof())
			{
				dictfile >> dictword;
				dictwords[i] = dictword;
				i ++;
			}
				
				if (inDictionary(word, dictwords) == false)
			{
				cout << word << endl;
			}
		}

			
	}
	cout << "\n\n";
}


void wordFilter(string& word)
{
	int found1 = word.find(".");
		if (found1 >= 0) { word.replace(found1,1,""); }
 
		int found2 = word.find("!");
		if (found2 >= 0) { word.replace(found2,1,""); }
 
		int found3 = word.find("(");
		if (found3 >= 0) { word.replace(found3,1,""); }
 
		int found4 = word.find(")");
		if (found4 >= 0) { word.replace(found4,1,""); }
 
		int found5 = word.find(";");
		if (found5 >= 0) { word.replace(found5,1,""); }
 
		int found6 = word.find("?");
		if (found6 >= 0) { word.replace(found6,1,""); }
 
		int found7 = word.find(",");
		if (found7 >= 0) { word.replace(found7,1,""); }
 
		int found8 = word.find(":");
		if (found8 >= 0) { word.replace(found8,1,""); }

		int found10 = word.find("\"");
		while (found10 >= 0)
		{
			word.replace(found10,1,"");
			found10 = word.find("\"");
		}
}
bool inDictionary(string word, string dictionary[])
{
	bool flag = false;
	string dictword;
	int find = word.find_first_not_of("-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	if (find >= 0)
	{
		flag = true;
	}
	for (int i = 0; i < 199; i ++)
	{
		dictword = dictionary[i];
		if(stricmp(word.c_str(),dictword.c_str()) == 0)
		{
			flag = true;	
		}
	
	}
	return flag;
}
int main()
{
	// prompt the user to enter a text file
string filename;
cout << "Please enter the file name you would like to spell check: ";
cin >> filename;
cout << "\n\n";
spell(filename);

system("pause");
return 0;
}