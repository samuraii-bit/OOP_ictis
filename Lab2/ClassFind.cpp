#include "ClassFind.h"

void ClassFind::setClassFind(ArrayList^ productsArray, ArrayList^ certificatesArray, ArrayList^ ordersArray)
{
	if (productsArray->Count > 0 && certificatesArray->Count > 0 && ordersArray->Count > 0)
	{
		this->Certificates = certificatesArray;
		this->Products = productsArray;
		this->Orders= ordersArray;
	}
	else
	{
		return;
	}
}

ArrayList^ ClassFind::findProducts(ArrayList^ certificatesArray, ArrayList^ ordersArray)
{
	ArrayList^ productsArray = gcnew ArrayList();
	ArrayList^ claimOrders = gcnew ArrayList();
	for (int i = 0; i < ordersArray->Count; i++)
	{
		int Num = static_cast<Order^>(ordersArray[i])->getOrderNum();
		for (int j = 0; j < this->Orders->Count; j++)
		{
			int thisNum= static_cast<Order^>(this->Orders[j])->getOrderNum();
			if (Num == thisNum)
			{
				claimOrders->Add(this->Orders[j]);
			}
		}
	}
	ArrayList^ suitOrders = gcnew ArrayList();
	for (int i = 0; i < claimOrders->Count; i++)
	{
		int oPID = static_cast<Order^>(claimOrders[i])->getID();
		for (int j = 0; j < this->Products->Count; j++)
		{
			int PID = static_cast<Product^>(this->Products[j])->getID();
			int pCertNum = static_cast<Product^>(this->Products[j])->getCertNum();
			for (int k = 0; k < certificatesArray->Count; k++)
			{
				int CertNum = static_cast<Certificate^>(certificatesArray[k])->getCertNum();
				if (oPID == PID && CertNum == pCertNum)
				{
					suitOrders->Add(static_cast<Order^>(claimOrders[i]));
				}
			}
		}
	}
	for (int i = 0; i < suitOrders->Count; i++)
	{
		int sOrdNum = static_cast<Order^>(suitOrders[i])->getOrderNum();
		for (int j = 0; j < this->Products->Count; j++)
		{
			ArrayList^ pOrdres = (static_cast<Product^>(this->Products[j])->getOrders());
			for (int k = 0; k < pOrdres->Count; k++)
			{
				int pOrdNum = static_cast<Order^>(pOrdres[k])->getOrderNum();
				if (pOrdNum == sOrdNum)
				{
					productsArray->Add(this->Products[j]);
				}
			}
		}
	}
	return productsArray;
}

ClassFind::ClassFind()
{

}