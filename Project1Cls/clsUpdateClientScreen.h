#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsBankClient.h"
using namespace std;
class clsUpdateClientScreen:protected clsScreen
{
private:
	static void  _ReadClientInfo(clsBankClient& client) {
		cout << "Enter First Name :" << endl;
		client.FirstName = clsInputValidate::ReadName();
		cout << "Enter Last Name :" << endl;
		client.LastName = clsInputValidate::ReadName();
		cout << "Enter Email :" << endl;
		client.Email = clsInputValidate::ReadName();
		cout << "Enter phone :" << endl;
		client.Phone = clsInputValidate::ReadName();
		cout << "Enter pincode :" << endl;
		client.PinCode = clsInputValidate::ReadName();
		cout << "Enter Account balances :" << endl;
		client.AccountBalance = clsInputValidate::ReadDblNumber();

	}
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
	static void ShowUpdateClientScreen() {
		if (!CheckAcessRight(clsUser::enPermissions::pUpdateClients)) {
			return;
		}
		_DrawScreenHeader("\tthis Update Client Screen");
		string AccountNumber = "";
		cout << "enter AccountNumber : " << endl;
		cin >> AccountNumber;
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "enter AccountNumber : " << endl;
			cin >> AccountNumber;

		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Client.Print();
		if (!Client.IsEmpty()) {
			_ReadClientInfo(Client);
			clsBankClient::enSaveResults resalt = Client.Save();
			switch (resalt)
			{
			case clsBankClient::enSaveResults::svSucceeded:cout << "process sucssfult ;-) " << endl;
				break;
			case clsBankClient::enSaveResults::svFaildEmptyObject:cout << "process faild ;-(" << endl;
				break;
			}
		}
		else {
			cout << "no Client like that !!!!!!!! " << endl;
		}




	}
};

