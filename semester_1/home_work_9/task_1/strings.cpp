
#include "iostream"
#include "strings.h"

using namespace std;

String* strCreate()
{
	String *str = new String;
	str->length = 0;
	str->begin = nullptr;
	return str;
}

String* charToStr(char *a)
{
	String *str = strCreate();
	str->begin = a;
	str->length = strLen(str);
	return str;
}

void strDelete(String *&str)
{
	delete[] str->begin;
	str->begin = nullptr;
}

String* strClone(String *str)
{
	String *clone = strCreate();
	char *strclone = new char[str->length + 1];
	
	for (int i = 0; i <= str->length; i++)
	{
		strclone[i] = str->begin[i];
	}

	clone->begin = strclone;
	clone->length = str->length;
	return clone;
}

void strAdd(String *&str, String *&add)
{
	const int n = str->length + add->length;
	char *newstr = new char [n + 1];
	for (int i = 0; i < n; i++)
	{
		if (i < str->length)
			newstr[i] = str->begin[i];
		else 
			newstr[i] = add->begin[i - str->length];
	}
	newstr[n] = '\0';
	strDelete(add);
	delete add;
	delete[] str->begin;
	str->begin = newstr;
	str->length = n;
}

bool strIsEqual(String *str1, String *str2)
{
	if (str1->length != str2->length)
		return 0;
	
	for (int i = 0; i < str1->length; i++)
		if (str1->begin[i] != str2->begin[i])
			return 0;

	return 1;
}

bool strIsEqual(String *str1, char *str2)
{
	for (int i = 0; i < str1->length; i++)
		if (str1->begin[i] != str2[i])
			return 0;

	return 1;
}

bool strIsEmpty(String *str)
{
	return str->length == 0;
}

int strLen(String *str)
{
	if (str->begin == nullptr)
		return 0;

	//if (str->length > 0)
		//return str->length;
	
	int i = 0;
	
	while (str->begin[i] != '\0')
		i++;
	
	return i;
}

void strCut(String *&str, int begin, int end)
{
	if (end > str->length || end - begin < 0 || begin < 0)
		return;
	const int n = end - begin;
	char *newstr = new char [n + 1];
	for (int i = 0; i < n; i++)
		newstr[i] = str->begin[begin + i];
	newstr[n] = '\0';
	delete[] str->begin;
	str->begin = newstr;
	str->length = n;
}

char* strToChar(String *str)
{
	char *newchar = new char [str->length];
	newchar = str->begin;
	return newchar;
}

void strPrint(String *str)
{

	cout << endl;

	for (int i = 0; i < str->length; i++)
		cout << str->begin[i];

	cout << endl;
}


