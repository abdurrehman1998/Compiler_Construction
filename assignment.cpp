#include <iostream>
#include <fstream>

using namespace std;
enum Reserve{
	 Break, Case, Char, CharSequence, Default, Do, End, Else,
	For, Input, If, Numeric, Nothing, Output, PointNumeric, Start, Switch, While
};
Reserve words;
void Analyze(fstream &);
void Parser();
int main()
{
	
	fstream file("input.txt", ios::in);
	if (!file){
		cout << "Failed to open file" << endl;
		//exit(0);
		return 0;
	}
	
	Analyze(file);
	
	return 0;
}
void Analyze(fstream &file)
{
	char ch=0;
	char chAhead = 0;
	string temp="";
	
	long pos = 0;
	while (! file.eof())
	{
		file.get(ch);
		switch (ch)
		{
		case '*':
				file.get(chAhead);
				if (chAhead == '/')
					cout << ch <<chAhead<< " is an Ending Block Comment" << endl; // for ending block comment # signed use
				else
				{
					cout << ch << " is a Multiplication Operator" << endl;
					pos= (long)file.tellp();
					file.seekp(pos - 1);
				}
				break;
			case ';':
				cout << ch << " is a Statement Terminator" << endl;
				break;
			case':':
				cout << ch << " is a Case Auxillary" << endl;
				break;
			case '!':
				cout << ch << " is a Negation Operator" << endl;
				break;
			case '(':
				cout << ch << " is a Left Parenthesis" << endl;
				break;
			case ')':
				cout << ch << " is a Right Parenthesis" << endl;
				break;
			case '%':
				cout << ch << " is a Modolous Operator" << endl;
				break;
			case '+':
				file.get(chAhead);
				if (chAhead == '+')
					cout << ch << chAhead << " is an Increment Operator" << endl;
				else{
					cout << ch << " is an Addition Operator" << endl;
					pos= (long)file.tellp();
					file.seekp(pos - 1);
				}
				break;
			case '-':
				file.get(chAhead);
				if (chAhead == '-')
					cout << ch << chAhead << " is a Decrement Operator" << endl;
				else{
					cout << ch << " is a Subtraction Operator" << endl;
					pos= (long)file.tellp();
					file.seekp(pos - 1);
				}
				break;
			case '/':
				file.get(chAhead);
				if (chAhead == '/')
					cout << ch << chAhead << " is a Single Line Comment" << endl;
				else if (chAhead == '#')
					cout << ch << chAhead << " is a Starting Block Comment" << endl;  
				else{
					cout << ch << " is a Division Operator" << endl;
					pos= (long)file.tellp();
					file.seekp(pos - 1);
				}
				break;
			case '<':
				file.get(chAhead);
				if (chAhead == '>')
					cout << ch << chAhead << " is a Not-Equal Operator" << endl;
				else if (chAhead == '=')
					cout << ch << chAhead << " is a Less Than OR Equal Operator" << endl;
				else{
					cout << ch << " is a Less Than Operator" << endl;
					pos= (long)file.tellp();
					file.seekp(pos - 1);
				}
				break;
			case '>':
				file.get(chAhead);
				if (chAhead == '=')
					cout << ch << chAhead << " is a Greater Than OR Equal Operator" << endl;
				else{
					cout << ch << " is a Greater Than Operator" << endl;
					pos= (long)file.tellp();
					file.seekp(pos - 1);
				}
				break;
			case '=':
				file.get(chAhead);
				if (chAhead == '=')
					cout << ch << chAhead << " is an Equal To Operator" << endl;
				else{
					cout << ch << " is an Assignment Operator" << endl;
					pos= (long)file.tellp();
					file.seekp(pos - 1);
				}
				break;
			case ' ':
				break;
			case '#':
				temp = ch;
				file.get(chAhead);
				if (chAhead == '/')
				{
					temp += chAhead;
					cout << temp.c_str() << " is ending block Comment" << endl;
				}
				else
				{
				
					while (isalpha(chAhead))
					{

						temp += chAhead;
						file.get(chAhead);

					}
					if ((temp.length() >= 2) && (temp.length() <= 20) && (!isdigit(chAhead)))
					{

						cout << temp.c_str() << " is an Identifier" << endl;
					}
					else
					{
						
						while (isalnum(chAhead))
						{
							file.get(chAhead);
							if (isalnum(chAhead))
								temp += chAhead;
						}
						cout << temp.c_str() << " is invalid" << endl;
					}
					pos = (long)file.tellp();
					file.seekp(pos - 1);
				}
				
				break;
			case 'B':

				temp = ch;
				while (isalpha(ch))
				{
					file.get(ch);
					if (isalpha(ch))
						temp += ch;
				}
				if (temp.compare("Break") == 0)
				{
					words = Break;
					cout << "Break is a reserve word" << endl;
				}
				else
					cout << temp.c_str()<<" is invalid" << endl;

				pos= (long)file.tellp();
				file.seekp(pos - 1);
				break;
			case '&':
					file.get(chAhead);
					if (chAhead == '&')
					{
						cout << ch << chAhead << " is AND Operator" << endl;
					}
					else {
						cout << ch << "is invalid character" << endl;
						pos = (long)file.tellp();
						file.seekp(pos - 1);
					}
				break;
			case '|':
					file.get(chAhead);
					if (chAhead == '|')
					{
						cout << ch << chAhead << " is OR Operator" << endl;
					}
					else {
						cout << ch << "is invalid character" << endl;
						pos = (long)file.tellp();
						file.seekp(pos - 1);
					}
					break;
			case 'C':
				file.get(chAhead);
				if (chAhead == 'a')
				{

					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					if (temp.compare("Case") == 0)
					{
						cout << "Case is a reserve word" << endl;
						words = Case;
					}
					else
						cout << temp.c_str() << " is invalid" << endl;

				}
				else if (chAhead == 'h')
				{

					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					if (temp.compare("Char") == 0) {
						cout << "Char is a reserve word" << endl;
						words = Char;

					}
					else if (temp.compare("CharSequence") == 0)
					{
						cout << "CharSequence is a reserve word" << endl;
						words = CharSequence;
					}
					else
						cout << temp.c_str() << " is invalid" << endl;
				}
				else
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if(isalpha(ch))
						temp += ch;
					}
					cout << temp.c_str() << " is invalid" << endl;
				}
				pos= (long)file.tellp();
				file.seekp(pos - 1);
				break;
			case 'D':
				file.get(chAhead);
				if (chAhead == 'e')
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					if (temp.compare("Default") == 0)
					{
						words = Default;
						cout << "Default is a reserve word" << endl;
					}
					else
						cout << temp.c_str() << " is invalid" << endl;

				}
				else if (chAhead == 'o')
				{

					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					if (temp.compare("Do") == 0)
					{
						cout << "Do is a reserve word" << endl;
						words = Do;
					}
					else
						cout << temp.c_str() << " is invalid" << endl;
				}
				else
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					cout << temp.c_str() << " is invalid" << endl;
				}
				pos= (long)file.tellp();
				file.seekp(pos - 1);
				break;
			case 'E':
				file.get(chAhead);
				if (chAhead == 'n')
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					if (temp.compare("End") == 0)
					{
						words = End;
						cout << "End is a reserve word" << endl;
					}
					else
						cout << temp.c_str() << " is invalid" << endl;

				}
				else if (chAhead == 'l')
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					if (temp.compare("Else") == 0)
					{
						words = Else;
						cout << "Else is a reserve word" << endl;
					}
					else
						cout << temp.c_str() << " is invalid" << endl;

				}
				else
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					cout << temp.c_str() << " is invalid" << endl;
				}
				pos= (long)file.tellp();
				file.seekp(pos - 1);
				break;
			case 'F':

				temp = ch;
				while (isalpha(ch))
				{
					file.get(ch);
					if (isalpha(ch))
						temp += ch;
				}
				if (temp.compare("For") == 0)
				{
					cout << "For is a reserve word" << endl;
					words = For;
				}
				else
					cout << temp.c_str() << " is invalid" << endl;
				pos= (long)file.tellp();
				file.seekp(pos - 1);
				break;
			case 'I':
				file.get(chAhead);
				if (chAhead == 'f')
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					if (temp.compare("If") == 0)
					{
						cout << "If is a reserve word" << endl;
						words = If;
					}
					else
						cout << temp.c_str() << " is invalid" << endl;
					
				}
				else if (chAhead == 'n')
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					if (temp.compare("Input") == 0)
					{
						words = Input;
						cout << "Input is a reserve word" << endl;
					}
					else
						cout << temp.c_str() << " is invalid" << endl;

				}
				else
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					cout << temp.c_str() << " is invalid" << endl;
				}
				pos= (long)file.tellp();
				file.seekp(pos - 1);
				break;

			case 'N':
				file.get(chAhead);
				if (chAhead == 'u')
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					if (temp.compare("Numeric") == 0)
					{
						words = Numeric;
						cout << "Numeric is a reserve word" << endl;

					}
					else
						cout << temp.c_str() << " is invalid" << endl;
				}
				else if (chAhead == 'o')
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					if (temp.compare("Nothing") == 0)
					{
						words = Nothing;
						cout << "Nothing is a reserve word" << endl;

					}
					else
						cout << temp.c_str() << " is invalid" << endl;
				}
				else
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					cout << temp.c_str() << " is invalid" << endl;
				}
				pos= (long)file.tellp();
				file.seekp(pos - 1);
				break;
			case 'O':
				temp = ch;
				while (isalpha(ch))
				{
					file.get(ch);
					if (isalpha(ch))
						temp += ch;
				}
				if (temp.compare("Output") == 0)
				{
					cout << "Output is a reserve word" << endl;
					words = Output;
				}
				else
					cout << temp.c_str() << " is invalid" << endl;
				pos= (long)file.tellp();
				file.seekp(pos - 1);
				break;
			case 'P':
				temp = ch;
				while (isalpha(ch))
				{
					file.get(ch);
					if (isalpha(ch))
						temp += ch;
				}
				if (temp.compare("PointNumeric") == 0)
				{
					cout << "PointNumeric is a reserve word" << endl;
					words = PointNumeric;
				}
				else
					cout << temp.c_str() << " is invalid" << endl;
				pos= (long)file.tellp();
				file.seekp(pos - 1);
				break;
			case 'S':
				file.get(chAhead);
				if (chAhead == 't')
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					if (temp.compare("Start") == 0)
					{
						words = Start;
						cout << "Start is a reserve word" << endl;
					}
					else
						cout << temp.c_str() << " is invalid" << endl;
				}
				else if (chAhead == 'w')
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					if (temp.compare("Switch") == 0)
					{
						words = Switch;
						cout << "Switch is a reserve word" << endl;
					}
					else
						cout << temp.c_str() << " is invalid" << endl;
				}
				else
				{
					temp = ch;
					temp += chAhead;
					while (isalpha(ch))
					{
						file.get(ch);
						if (isalpha(ch))
							temp += ch;
					}
					cout << temp.c_str() << " is invalid" << endl;
				}
				pos= (long)file.tellp();
				file.seekp(pos - 1);
				break;
			case 'W':
				temp = ch;
				while (isalpha(ch))
				{
					file.get(ch);
					if (isalpha(ch))
						temp += ch;
				}
				if (temp.compare("While") == 0)
				{
					cout << "While is a reserve word" << endl;
					words = While;
				}
				else
					cout << temp.c_str() << " is invalid" << endl;
				pos= (long)file.tellp();
				file.seekp(pos - 1);
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case'5':
			case '6':
			case '7':
			case '8':
			case '9':
				file.get(chAhead);
				temp = ch;
				
				while (isdigit(chAhead))
				{
					temp += chAhead;
					file.get(chAhead);
					
						
				}
				
				if(!isalpha(chAhead))
				{
					cout << temp.c_str() << " is valid Numeric" << endl;
					

				}
				else
				{
					temp += chAhead;
					while (isalnum(chAhead))
					{
						file.get(chAhead);
						if (isalnum(chAhead))
							temp += chAhead;
					}
					cout << temp.c_str() << " is invalid" << endl;
					
				}
				pos = (long)file.tellp();
				file.seekp(pos - 1);
				break;
			case '"':
				temp = ch;
				file.get(chAhead);
				while (chAhead != '"') 
				{
					temp += chAhead;
					file.get(chAhead);
				}
				temp += chAhead;
				cout << temp.c_str() << " is a CharSequence" << endl;
				break;
			default:
				temp = ch;
				if (isalnum(ch))
				{
					while (isalnum(ch))
					{
						file.get(ch);
						if (isalnum(ch))
							temp += ch;
					}
					cout << temp.c_str() << " is Invalid" << endl;
				}
				break;
				
		}
	}
}
