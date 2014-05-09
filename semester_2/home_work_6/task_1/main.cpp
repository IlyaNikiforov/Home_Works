#include <iostream>

using namespace std;

class Class
{
	public:
		~Class()
		{
			cout << "Class destructor" << endl;
		}
};

class Exception
{
	public:
		~Exception()
		{
			cout << "Exception destructor" << endl;
		}
};

using namespace std;

int main()
{
	try
	{
		Class test;
		throw Exception();
	}
	catch (...)
	{
		cout << "Exception catched" << endl;
	}

	return 0;
}
