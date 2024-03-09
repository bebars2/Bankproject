#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

class clsWithdrawScreen:protected clsScreen
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

	static void ShowWithDrawScreen() {
		_DrawScreenHeader("\tWithdraw Screen");
		string AcouuntNumber = "";
		cout << "Enter Account Number \n";
		AcouuntNumber = _ReadAccountNumner();
		while (!clsBankClient::IsClientExist(AcouuntNumber)) {

			cout << "this Account Number " << AcouuntNumber << " is wrong Enter Anuther\n";
			AcouuntNumber = _ReadAccountNumner();
		}
		clsBankClient Client = clsBankClient::Find(AcouuntNumber);

		_PrintClient(Client);
		cout << "Enter Withdraw amount?";
		double WithDrawAmount = clsInputValidate::ReadDblNumber();
		char ACcept;
		cout << "Are ypu sure to Withdraw " << WithDrawAmount << endl;
		cin >> ACcept;//to check if you sure to add amount 
		
		if (tolower(ACcept) == 'y') {
			if (Client.WithDraw(WithDrawAmount)) {
				cout << "New Balance " << Client.AccountBalance << endl;
			}
			else {
				cout << "Withdraw amount is :" << WithDrawAmount << endl;
				cout << "your balance is :" << Client.AccountBalance << endl;
				cout << "you can't WithDraw this Amount" << endl;
			}
			
			


		}
		else {
			cout << "Operation was canceld" << endl;
		}




	}
};

