#include "iostream"
#include "fstream"

using namespace std;

int main ()
{
	cout << "File reader" << endl;
	cout << "The information wiil be readen from <<input.txt>>" << endl;
	ifstream in ("input.txt");
	char a[100];
	int alf[256] = {0};
	in >> a;
	while (!in.eof())
	{
		for (int i = 0; i < strlen(a); i++)
		{
			if (alf[int(a[i])] == 0)
			{
				cout << a[i];
				alf[int(a[i])]++;
			}
		}

		cout << " ";
		
		for (int i = 0; i < 256; i++)
			alf[i] = 0;
		
		in >> a;
	}

	in.close();
	cin >> a;
	return 0;
}