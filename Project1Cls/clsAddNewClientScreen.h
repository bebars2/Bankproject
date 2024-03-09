#pragma once
#include <iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

using namespace std;
class clsAddNewClientScreen:protected clsScreen
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
public:
    static void AddNewClient() {
        if (!CheckAcessRight(clsUser::enPermissions::pAddNewClient)) {
            return;
        }

        _DrawScreenHeader("\t Add New Client Screen");
        
        string AccountNumber = "";
        cout << "enter Account Number" << endl;
        cin >> AccountNumber;
        while (clsBankClient::IsClientExist(AccountNumber)) {
            cout << "Account Number is exist Enter anouther" << endl;
            cin >> AccountNumber;
        }
        clsBankClient client = clsBankClient::GetNewClient(AccountNumber);
        _ReadClientInfo(client);
        clsBankClient::enSaveResults Resilt = client.Save();
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

};

