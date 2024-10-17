#pragma once
#include "Order.h"
using namespace System;
using namespace System::Collections;

ref class Product
{
private:
	String^ name = "";
	int productID = -1;
	int certNumber = -1;
	ArrayList^ orders = gcnew ArrayList();
public:
	void setName(String^ n);
	String^ getName();
	void setID(int pID);
	int getID();
	void setCertNum(int cN);
	int getCertNum();
	void addOrder(Order^ o);
	ArrayList^ getOrders();
};

