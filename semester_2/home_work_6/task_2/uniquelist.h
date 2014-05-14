#pragma once
#include "set.h"
#include "listerrors.h"

template <typename type>
class UniqueList : public Set <type>
{
	public:
		void addUniqueElement(type value);
		void deleteUniqueElement( type value);
};

template <typename type>
void UniqueList <type> ::addUniqueElement(type value)
{
	if (this->isExists(value))
	{
		ListErrors::notUniqueError error;
		throw error;
	}

	this->add(value);
}

template <typename type>
void UniqueList <type> ::deleteUniqueElement(type value)
{
	if (!this->isExists(value))
	{
		ListErrors::notExistError error;
		throw error;
	}

	this->del(value);
}
