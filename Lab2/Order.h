#pragma once
using namespace System;
using namespace System::Collections;

ref class Order
{
private:
	String^ Address = "";
	int productID = -1;
	int quantity = -1;
	int orderNum = -1;
public:
	void setAddress(String^ addr);
	String^ getAddress();
	void setID(int pID);
	int getID();
	void setQuantity(int q);
	int getQuantity();
	int getOrderNum();
	void setOrderNum(int oN);
};