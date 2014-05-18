#pragma once
class Strings
{
	public:
		Strings();

		~Strings();
		
		Strings* charToStr(char *a);
		
		Strings* clone();

		char element (int i);
		
		void add(Strings *&add);

		void add(char *add);
		
		bool isEqual(Strings *str);
		
		bool isEqual(char *str);
		
		bool isEmpty();
		
		int returnLength();

		void cut(int begin, int end);
		
		char* strToChar();
		
		void print();

	private:
			char *string;
			int length;
		
};

