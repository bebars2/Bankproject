#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsShowTransferScreen
{
private:
	static void _PrintClientCard(clsBankClient Client) {

		cout << "Client Card : " << endl;
		cout << "_________________" << endl;
		cout << "Full Name: " << Client.FullName() << endl;
		cout <<"Acc.Number: "<<Client.AccountNumber() << endl;
		cout << "Balance: "<<Client.AccountBalance << endl;
		cout << "___________________" << endl;

	}
	static bool ValdChose() {
		cout << "Are you sure to do this Action" << endl;
		char Chose;
		cin >> Chose;
		if (Chose == 'Y' || Chose == 'y') {
			return true;
		}
		return false;
	}
public:
	static void ShowTransferScreen() {
		string AccountNumber = "";
		cout << "Enter Accout Number to Send Mony" << endl;
		AccountNumber = clsInputValidate::ReadName();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "This Account Number Not Exist , Enter Anouther" << endl;
			AccountNumber = clsInputValidate::ReadName();

		}
		clsBankClient SenderClient = clsBankClient::Find(AccountNumber);

		_PrintClientCard(SenderClient);

		cout << "Enter Accout Number to take Mony" << endl;
		AccountNumber = clsInputValidate::ReadName();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "This Account Number Not Exist , Enter Anouther" << endl;
			AccountNumber = clsInputValidate::ReadName();
		}
		clsBankClient DestnationClient = clsBankClient::Find(AccountNumber);
		_PrintClientCard(DestnationClient);

		cout << "enter how many mony need to send" << endl;
		double AmountToSend = clsInputValidate::ReadDblNumber();
		if (ValdChose()) {
			if (SenderClient.Transfer(AmountToSend, DestnationClient)) {
				cout << "transfer sucsses" << endl;
			}
			else {
				cout << "transfer faild" << endl;
			}


			
				

				_PrintClientCard(SenderClient);
				_PrintClientCard(DestnationClient);
			system("pause>0");
		}
		

		






	}
};

