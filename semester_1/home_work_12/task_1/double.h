#pragma once

enum States 
{
	start,
	sign,
	intPart,
	point,
	frctPart,
	exponent,
	expSign,
	expValue
};

bool isDouble(char *&ch);