#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

class clsDeposeScreen:protected clsScreen 
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountBalance;
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
	static string  _ReadAccountNumner() {
		return clsInputValidate::ReadName();

	}
public:

	static void ShowDeposeScreen() {
		_DrawScreenHeader("\tDepose Screen");
		string AcouuntNumber = "";
		cout << "Enter Account Number \n";
		AcouuntNumber = _ReadAccountNumner();
		while (!clsBankClient::IsClientExist(AcouuntNumber)) {
		
			cout<<"this Account Number "<< AcouuntNumber <<" is wrong Enter Anuther\n" ;
			AcouuntNumber = _ReadAccountNumner();
		}
		clsBankClient Client = clsBankClient::Find(AcouuntNumber);
		
		_PrintClient(Client);
		cout << "Enter Depose amount?";
		double DepseAmount = clsInputValidate::ReadDblNumber();
		char ACcept;
		cout<<"Are ypu sure to Depsoe "<<DepseAmount<<endl;
		cin >> ACcept;//to check if you sure to add amount 
		if (tolower(ACcept) == 'y') {
			Client.Depose(DepseAmount);
			cout << "New Balance " << Client.AccountBalance << endl ;
			

		}
		else {
			cout << "Operation was canceld" << endl;
		}
		

		
		
	}
};

