#pragma once
using namespace System;
using namespace System::Collections;

ref class Certificate
{
private:
	int certNumber = -1;
	int productID = -1;
public:
	void setCertNum(int cN);
	int getCertNum();
	void setID(int pID);
	int getID();
};

