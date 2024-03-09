#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsCurrencesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"

class clsCurrencyMainMenu:protected clsScreen
{
private:
    enum enCurrencyMenuOptions {
        eLsitCurrency = 1, eFindCurrency = 2, eUpdateCurrency = 3, eCurrencyCulclat = 4,
        GoBackToMenMenu = 5
    };
    static short  _ReadCurrencyMenuOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        return clsInputValidate::ReadIntNumberBetween(1, 5);

    }
    static void  _GobackToCurrencyMenuScreen() {
        ShowCurrencyScreenMenu();
    }
    static void _ShowListCurrencyScreen() {
        //cout << "here list Currency screen" << endl;
        clsCurrencesListScreen::ShowCurrencyList();
        system("pause>0");
        
    }
    static void _ShowFindCurrencyScreen() {
       // cout << "here is Find Screen" << endl;
        clsFindCurrencyScreen::ShowFindScreen();
        
        system("pause>0");
    }
 
    static void _showUpdateCurrencyScreen() {
        //cout << "here is Update Screen" << endl;
        clsUpdateRateScreen::ShowUpdateCurrencyScreen();
        
        system("pause>0");

    }
    static void _ShowCurrencyCalculatorScreen() {
        //cout << "here Currency Calculator " << endl;
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
       
        system("pause>0");

    }
    static void _PerformCurrencyOption(enCurrencyMenuOptions OptionTran) {
        switch (OptionTran)
        {
        case enCurrencyMenuOptions::eLsitCurrency: {
            system("cls");
            _ShowListCurrencyScreen();
            _GobackToCurrencyMenuScreen();
        }
                                               break;
        case enCurrencyMenuOptions::eFindCurrency: {
            system("cls");
            _ShowFindCurrencyScreen();
            _GobackToCurrencyMenuScreen();
        }
                                                 break;
        case enCurrencyMenuOptions::eCurrencyCulclat: {
            system("cls");
            
            _ShowCurrencyCalculatorScreen();
            _GobackToCurrencyMenuScreen();
        }
                                                 break;
       

        case enCurrencyMenuOptions::eUpdateCurrency: {
            system("cls");
            _showUpdateCurrencyScreen();
            _GobackToCurrencyMenuScreen();

        }
                                                     break;
        case enCurrencyMenuOptions::GoBackToMenMenu: {
            system("cls");


        }




        }
    }
public:
    static void ShowCurrencyScreenMenu() {
       
        system("cls");
        _DrawScreenHeader("\t\tCurrency Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrencyMenue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currences .\n";
        cout << setw(37) << left << "" << "\t[2] Find Currences.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Govback To MainMenu.\n";

        cout << setw(37) << left << "" << "===========================================\n";
        _PerformCurrencyOption((enCurrencyMenuOptions)_ReadCurrencyMenuOption());
    }
};

