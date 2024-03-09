#include <iostream>
#include"clsUtility.h"
#include"clsDate.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsMainScreen.h"
#include"clsLoginScreen.h"
#include "Global.h"



using namespace std;
void  ReadClientInfo(clsBankClient &client){
	cout << "Enter First Name :" << endl;
	client.FirstName = clsInputValidate::ReadName();
	cout << "Enter Last Name :" << endl;
	client.LastName = clsInputValidate::ReadName();
	cout << "Enter Email :" << endl;
	client.Email = clsInputValidate::ReadName();
	cout << "Enter phone :" << endl;
	client.Phone = clsInputValidate::ReadName();
	cout << "Enter pincode :" << endl;
	client.PinCode= clsInputValidate::ReadName();
	cout << "Enter Account balances :" << endl;
	client.AccountBalance = clsInputValidate::ReadDblNumber();

}
void UpdateClient() {
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
		ReadClientInfo(Client);
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
void AddNewClient() {
	string AccountNumber = "";
	cout << "enter Account Number" << endl;
	cin >> AccountNumber;
	while (clsBankClient::IsClientExist(AccountNumber)) {
		cout << "Account Number is exist Enter anouther" << endl;
		cin >> AccountNumber;
	}
	clsBankClient client = clsBankClient::GetNewClient(AccountNumber);
	ReadClientInfo(client);
	clsBankClient::enSaveResults Resilt=client.Save();
	switch (Resilt)
	{
	case clsBankClient::svSucceeded:
		cout << "seccsufet :-)" << endl;
		break;
	case clsBankClient::svFaildclientIsExsist:
		cout << "Save Fail Client Exsuist" << endl;
		break;
	default:
		break;
	}

}
void DeleteClient()
{
	string AccountNumber = "";

	cout << "\nPlease Enter Account Number: ";
	AccountNumber = clsInputValidate::ReadName();
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount number is not found, choose another one: ";
		AccountNumber = clsInputValidate::ReadName();
	}

	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	Client1.Print();

	cout << "\nAre you sure you want to delete this client y/n? ";

	char Answer = 'n';
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{


		if (Client1.Delete())
		{
			cout << "\nClient Deleted Successfully :-)\n";

			Client1.Print();
		}
		else
		{
			cout << "\nError Client Was not Deleted\n";
		}
	}
}
void PrintClientRecordLine(clsBankClient Client)
{

	cout << "| " << setw(15) << left << Client.AccountNumber();
	cout << "| " << setw(20) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(20) << left << Client.Email;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(12) << left << Client.AccountBalance;

}
void ShowClientsList()
{

	vector <clsBankClient> vClients = clsBankClient::GetClientsList();

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else

		for (clsBankClient Client : vClients)
		{

			PrintClientRecordLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

}
void PrintClientRecordBalanceLine(clsBankClient Client)
{

	cout << "| " << setw(15) << left << Client.AccountNumber();
	cout << "| " << setw(40) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.AccountBalance;

}
void ShowTotalBalances()
{

	vector <clsBankClient> vClients = clsBankClient::GetClientsList();

	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	double TotalBalances = clsBankClient::GetTotalBalances();

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else

		for (clsBankClient Client : vClients)
		{
			PrintClientRecordBalanceLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
	cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
}


int main()
{
	while (true) {
		if (!clsLoginScreen::ShowLoginScreen()) {
			break;
		}

		
	}
	system("pause>0");
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
