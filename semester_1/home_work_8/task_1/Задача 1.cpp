#include "iostream"
#include "fstream"

using namespace std;

int main()
{
	cout << "Empty string finder" << endl;
	cout << "Information will be readen from \"input.txt\" file" << endl;
	
	FILE *in;
	in = fopen("input.txt", "r");
	
	if (!in)
	{
		cout << "Error reading from file" << endl;
		int n = 0;
		cin >> n;
		return 1;
	}

	int count = 0;
	char str[1000];
	int i = 0;

	while  (!feof(in))
	{
		fgets (str, 1000, in);
		i = 0;

		while (str[i] != '\n')
		{
			if (str[i] != ' ' && str[i] != '\t')
			{
				count ++;
				break;
			}
			
			i++;
		}
	}

	cout << "There is(are) " << count << " not empty string(s) in file" << endl;

	fclose(in);

	cin >> i;
	return 0;
}