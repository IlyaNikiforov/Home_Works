#pragma once
#include "iostream"

template <int dimension>
class Vector
{
public:

	Vector();
	~Vector();

	/// copy constructor
	Vector(Vector<dimension> const &newVector);
	Vector(double coord[dimension]);
	/// return is it zero or not
	bool isZero();

	Vector operator+(Vector<dimension> &vector2);
	Vector operator-(Vector<dimension> &vector2);
	double operator*(Vector<dimension> &vector2);
	bool operator==(Vector<dimension> &vector2);
	void print();
private:
	double *coordinates;
};

template<int dimension>
Vector<dimension>::Vector()
{
	coordinates = new double [dimension];
	for (int i = 0; i < dimension; i++)
		coordinates[i] = 0;
}

template<int dimension>
Vector<dimension>::~Vector()
{
	delete coordinates;
}

template <int dimension>
Vector<dimension>::Vector(Vector<dimension> const &newVector)
{
	coordinates = new double [dimension];
	for (int i = 0; i < dimension; i++)
		coordinates[i] = newVector.coordinates[i];
}

template <int dimension>
Vector<dimension>::Vector (double coord[dimension])
{
	coordinates = new double [dimension];
	for (int i = 0; i < dimension; i++)
		coordinates[i] = coord[i];
}

template <int dimension>
bool Vector<dimension>::isZero()
{
	for (int i = 0; i < dimension; i++)
		if (coordinates[i] != 0)
			return false;
	return true;
}

template <int dimension>
Vector<dimension> Vector<dimension>::operator+(Vector<dimension> &secondVector)
{
	Vector<dimension> newVector;
	for (int i = 0; i < dimension; i++)
		newVector.coordinates[i] = this->coordinates[i] + secondVector.coordinates[i];
	return newVector;
}

template <int dimension>
Vector<dimension> Vector<dimension>::operator-(Vector<dimension> &secondVector)
{
	Vector<dimension> newVector;
	for (int i = 0; i < dimension; i++)
		newVector.coordinates[i] = this->coordinates[i] - secondVector.coordinates[i];
	return newVector;
}

template <int dimension>
double Vector<dimension>::operator*(Vector<dimension> &secondVector)
{
	double result = 0;
	for (int i = 0; i < dimension; i++)
	result += this->coordinates[i] * secondVector.coordinates[i];
	return result;
}

template <int dimension>
bool Vector<dimension>::operator==(Vector<dimension> &secondVector)
{
	for (int i = 0; i < dimension; i++)
		if (this->coordinates[i] != secondVector.coordinates[i])
			return false;
	return true;
}

template <int dimension>
void Vector<dimension>::print()
{
	for (int i = 0; i < dimension; i++)
		std::cout << coordinates[i] << " ";
}
