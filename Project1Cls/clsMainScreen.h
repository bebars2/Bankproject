#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsAddNewClientScreen.h"
#include"clsClientListScreen.h"
#include"cldDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsMenuScreen.h"
#include"clsMangeUserScreen.h"
#include"Global.h"
#include"clsLogRegesterScreen.h"
#include"clsCurrencyMainMenu.h"


using namespace std;

class clsMainScreen :protected clsScreen
{
private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7,eLogRegester=8,eCurrency=9,eExit = 10
    };
    static short  _ReadMainMenueOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        return clsInputValidate::ReadIntNumberBetween(1, 10);

    }
    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }


    static void _ShowAllClientsScreen() {
        clsClientListScreen::ShowClientsList();
    }
    static void _ShowAddNewClientsScreen() {
        //cout << "here is new client screen" << endl;
        clsAddNewClientScreen::AddNewClient();
    }
    static void _ShowCurrencyMenu() {
        clsCurrencyMainMenu::ShowCurrencyScreenMenu();
    }

    static void _ShowDeleteClientScreen() {
        //cout << "here Delete Client Screen" << endl;
        cldDeleteClientScreen::showDeleteClientScreen();
    }
    static void _ShowUpdateClientScreen() {
        //cout << "here Update Client Screen";
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }
    
    static void _ShowFindClientScreen() {
       // cout << "here is Find Client Screen" << endl;
        clsFindClientScreen::ShowFindClientScreen();
    }
    static void _ShowTransactionsMenue() {
        //cout << "here is Transactions Screen" << endl;
        clsTransactionsMenuScreen::ShowTransactionScreenMenu();

    }
    static void _ShowManageUsersMenue() {
       // cout << "here is  Manage Users. Screen" << endl;
        clsMangeUserScreen::ShowUserManagerScreen();
    }
    static void _ShowLogRegesterScreen() {
        // cout << "here is  Manage Users. Screen" << endl;
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }
    static void _ShowEndScreen() {
        cout << "here Logout Screen" << endl;
    }
    static void _LogOut() {
        CurrectUser = clsUser::Find("", "");

    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eCurrency:
            system("cls");
            _ShowCurrencyMenu();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eLogRegester:
            system("cls");
            _ShowLogRegesterScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            //_ShowEndScreen();
            _LogOut();

            break;
        }

    }



public:
	static void ShowMainMenue() {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");
        
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Log Users.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Menu.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}
};

