#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsBankClient.h"
using namespace std;
class clsFindClientScreen:protected clsScreen
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
public:
	static void ShowFindClientScreen() {
		if (!CheckAcessRight(clsUser::enPermissions::pFindClient)) {
			return;
		}
		_DrawScreenHeader("\tthis Client Find Screen");
		string AccountNumber = "";
		cout << "Enter Account Number" << endl;
		cin >> AccountNumber;
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Account Number is not Exist Enter anouther" << endl;
			cin >> AccountNumber;
			
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		if (Client.IsEmpty()) {
			cout << "Client isnot Empty :-)" << endl;
		}
		else {
			cout << "Client is Empty :-(" << endl;
		}
		_PrintClient(Client);







	}

};

