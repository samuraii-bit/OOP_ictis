#include "Order.h"

void Order::setID(int pID)
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

int Order::getID()
{
	return this->productID;
}

void Order::setAddress(String^ addr)
{
	if (addr != "")
	{
		this->Address = addr;
	}
	else
	{
		return;
	}
}

String^ Order::getAddress()
{
	return this->Address;
}

void Order::setQuantity(int q)
{
	if (q > 0)
	{
		this->quantity = q;
	}
	else
	{
		return;
	}
}

int Order::getQuantity()
{
	return this->quantity;
}

int Order::getOrderNum()
{
	return this->orderNum;
}

void Order::setOrderNum(int oN)
{
	if (oN > 0)
	{
		this->orderNum = oN;
	}
	else
	{
		return;
	}
}