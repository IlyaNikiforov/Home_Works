#pragma once

template <typename type>
class SharedPointer
{
public:
	SharedPointer() : pointer() {}
	SharedPointer(type *value) : pointer(new Pointer(value)) {}
	/// constructor of copy
	SharedPointer(SharedPointer &newPointer): pointer(newPointer.pointer)
	{
		pointer->count++;
	}

	~SharedPointer();

	/// returns pointer
	type *getPointer();

	/// returns count of pointers
	int getCount();

	/// changing '=' operator
	SharedPointer& operator= (SharedPointer &newPointer);

private:
	struct Pointer
	{
		Pointer() : value(nullptr), count(0) {}
		~Pointer()
		{
			delete value;
		}
		Pointer(type *newPointer) : value(newPointer), count(1) {}
		type *value;
		int count;
	};
	Pointer *pointer;
};

template <typename type>
SharedPointer<type>::~SharedPointer()
{
	pointer->count--;
	if (pointer->count == 0)
		delete pointer;
}

template <typename type>
type* SharedPointer<type>::getPointer()
{
	return pointer->value;
}

template <typename type>
int SharedPointer<type>::getCount()
{
	return pointer->count;
}

template <typename type>
SharedPointer<type>& SharedPointer<type>::operator=(SharedPointer &newPointer)
{
	this->pointer->count--;
	if (this->pointer->count == 0)
		delete this->pointer;
	pointer = newPointer.pointer;
	pointer->count++;
	return *this;
}
