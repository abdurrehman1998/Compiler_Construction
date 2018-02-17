#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool isIdentifier(string &);

int main()
{
	bool identifier;
	fstream inputFile("words.txt", ios::in);
	if (!inputFile)
	{
		cout << "Error FILE_OPEN" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		//cout << "Success"<<endl;
		string temp;

		while (!inputFile.eof())
		{
			getline(inputFile, temp);
			identifier = isIdentifier(temp);
			if (!identifier)
			{
				if (temp.compare("If") == 0)
					cout << temp << " is a reserve word"<<endl;
				else if (temp.compare("Else") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("Start") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("End") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("Case") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("While") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("Do") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("For") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("Input") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("Output") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("Numeric") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("PointNumeric") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("Char") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("CharSequence") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("Break") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("Default") == 0)
					cout << temp << " is a reserve word" << endl;
				else if (temp.compare("Nothing") == 0)
					cout << temp << " is a reserve word" << endl;
			}

		}
		
	}

	return 0;
}
bool isIdentifier(string & str)
{
	string s = str;
	if ((str.length() > 2) && (str.length() <= 20)) // checks length 2-20
	{
		if (!str.find('#')) // checks # at start
		{
			for (unsigned int i = 1; i < str.length(); i++)
			{
				if (!(isalpha(str.at(i)))) // checks if subsequent letters are a-z/A-Z
				{
					cout << str << " is invalid Identifier" << endl;
					return false;
				}

			}
			cout << str << " is valid Identifier" << endl;

		}
		else
		{

			cout << str << " is invalid Identifier" << endl;
			return false;
		}

	}
	else
	{
		
		for (unsigned int j = 0; j < s.length(); j++)
		{
			char ch = s.at(j);

			switch (ch)
			{
				case '/':
					cout << ch << " is Divison Sign" << endl;
					break;

				case '*':
					cout << ch << " is Multiply sign" <<endl;
					break;

				case '+':
					cout << ch << " is Plus sign" << endl;
					break;

				case '-':
					cout << ch << " is Minus sign" << endl;
					break;

				case '(':
					cout << ch << " is Left round brace" << endl;
					break;
				case ')':
						cout << ch << " is Right round brace" << endl;
						break;
				case ':':
						cout << ch << " is Case statement auxillary" << endl;
								break;
				case ';':
						cout << ch << " is Statement terminator" << endl;
						break;
				case '.':
						cout << ch << " is Input Data type Suffix" << endl;
						break;
				case '<':
						cout << ch << " is Less than operator" << endl;
						break;
				case '>':
						cout << ch << " is Greator than operator" << endl;
						break;


			}
		}
		
	}
	return false;
}
