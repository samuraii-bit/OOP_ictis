#pragma once
#include "Certificate.h"
#include "Product.h"
#include "Order.h"
using namespace System;
using namespace System::Collections;

ref class ClassFind
{
private:
	ArrayList^ Products = gcnew ArrayList;
	ArrayList^ Certificates = gcnew ArrayList;
	ArrayList^ Orders = gcnew ArrayList;
public:
	ClassFind();
	ArrayList^ findProducts(ArrayList^ certificatesArray, ArrayList^ ordersArray);
	void setClassFind(ArrayList^ productsArray, ArrayList^ certificatesArray, ArrayList^ ordersArray);
};

