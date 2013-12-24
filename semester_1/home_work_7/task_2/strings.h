#pragma once

struct String
{
	char *begin;
	int length;
};

String* strCreate();

String* charToStr(char *a);

void strDelete(String *&str);

String* strClone(String *str);

void strAdd(String *&str, String *&add);

bool strIsEqual(String *str1, String *str2);

bool strIsEqual(String *str1, char *str2);

bool strIsEmpty(String *str);

int strLen(String *str);

void strCut(String *&str, int begin, int end);

char* strToChar(String *str);

void strPrint(String *str);

