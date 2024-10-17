#include "Product.h"
using namespace System::Collections;
void Product::setName(String^ n)
{
	if (n != "")
	{
		this->name = n;
	}
	else
	{
		return;
	}
}

String^ Product::getName()
{
	return this->name;
}

void Product::setID(int pID)
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

int Product::getID()
{
	return this->productID;
}

void Product::setCertNum(int cN)
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

int Product::getCertNum()
{
	return this->certNumber;
}

void Product::addOrder(Order^ o)
{
	this->orders->Add(o);
}

ArrayList^ Product::getOrders()
{
	return this->orders;
}