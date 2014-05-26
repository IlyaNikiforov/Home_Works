#include "strings.h"
#include "string.h"
#include "iostream"

using namespace std;

Strings::Strings()
{
	length = 0;
	string = nullptr;
}

Strings::~Strings()
{
	delete[] string;
}

Strings* Strings::charToStr(char *a) //!!!!!!!!!!!!!!!
{
	Strings *str = new Strings;
	str->string = a;
	str->length = strlen(a);
	return str;
}

Strings* Strings::clone()
{
	Strings *clone = new Strings;
	char *strclone = new char[this->length + 1];

	for (int i = 0; i <= this->length; i++)
	{
		strclone[i] = this->string[i];
	}

	clone->string = strclone;
	clone->length = this->length;
	return clone;
}

void Strings::add(Strings *&add)
{
	int n = this->length + add->length;
	char *newstr = new char [n + 1];
	for (int i = 0; i < n; i++)
	{
		if (i < this->length)
			newstr[i] = this->string[i];
		else 
			newstr[i] = add->string[i - this->length];
	}
	newstr[n] = '\n';
	delete add;
	if (this->string)
		delete[] this->string;
	this->string = newstr;
	this->length = n;
}

void Strings::add(char add[])
{
	const int n = this->length + strlen(add);
	char *newstr = new char [n + 1];
	for (int i = 0; i < n; i++)
	{
		if (i < this->length)
			newstr[i] = this->string[i];
		else
			newstr[i] = add[i - this->length];
	}
	newstr[n] = '\n';
	//delete add;
	if (this->string)
		delete[] this->string;
	this->string = newstr;
	this->length = n;
}

bool Strings::isEqual(Strings *str)
{
	if (this->length != str->length)
		return 0;

	for (int i = 0; i < this->length; i++)
		if (this->string[i] != str->string[i])
			return 0;

	return 1;
}

bool Strings::isEqual(char *str)
{
	for (int i = 0; i < this->length; i++)
		if (this->string[i] != str[i])
			return 0;

	return 1;
}

bool Strings::isEmpty()
{
	return length == 0;
}

int Strings::returnLength()
{
//	if (string == nullptr)
//		return 0;

//	//if (str->length > 0)
//		//return str->length;

//	int i = 0;

//	while (string[i] != '\0')
//		i++;

//	return i;

	return length;
}

void Strings::cut(int begin, int end)
{
	if (end > length || end - begin < 0 || begin < 0)
		return;
	const int n = end - begin + 2;
	char *newstr = new char [n];
	for (int i = 0; i < n - 1; i++)
		newstr[i] = string[begin + i];
	newstr[n] = '\n';
	delete string;
	string = newstr;
	length = n - 1;
}

char* Strings::strToChar()
{
	char *newchar = new char [length];
	for (int i = 0; i < length; i++)
		newchar[i] = string[i];
	return newchar;
}

void Strings::print()
{
	for (int i = 0; i < length; i++)
		cout << string[i];
}

char Strings::element(int i)
{
	return string[i];
}
