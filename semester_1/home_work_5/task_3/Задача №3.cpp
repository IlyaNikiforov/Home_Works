#include "iostream"
#include "fstream"

using namespace std;


int main()
{
	FILE *string;
	string = fopen("input.txt", "r");
	char a;
	while (!feof(string))
	{
		a = fgetc(string);
		if (a == '"')
		{
			do
				a = fgetc(string);
			while (a != '"');
		}
		
		if (a == '/')
		{
			a = fgetc(string);
			
			if (a == '*')
			{
				char b;
				do 
				{
					b = a;
					a = fgetc(string);
				}
				while (a != '/' || b != '*');
			}

			else if (a == '/')
			{
				cout << "//";
				do 
				{
					a = fgetc(string);
					cout << a;
				}
				while (a != '\n' && !feof(string));
				
				cout << endl;
			}
		}
	}
	
	int n = 0;
	cin >> n;
	return 0;
}
