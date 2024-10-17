#include "Certificate.h"

void Certificate::setCertNum(int cN)
{
	if (cN > 0)
	{
		this->certNumber = cN;
	}
	else
	{
		return;
	}
}

int Certificate::getCertNum()
{
	return this->certNumber;
}

void Certificate::setID(int pID)
{
	if (pID > 0)
	{
		this->productID = pID;
	}
	else
	{
		return;
	}
}

int Certificate::getID()
{
	return this->productID;
}