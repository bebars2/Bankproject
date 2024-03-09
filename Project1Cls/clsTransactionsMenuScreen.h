#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsDeposeScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalances.h"
#include"clsShowTransferScreen.h"
#include"clsShowLogTransferScreen.h"
using namespace std;
class clsTransactionsMenuScreen:protected clsScreen
{
private:
    enum enTransactionsMenuOptions {
        eDepose = 1, ewithDraw = 2, eTotalBalance = 3,etransfer=4,eLogTransfer=5,
        GoBackToMenMenu = 6
    };
    static short  _ReadTransactionsMenuOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        return clsInputValidate::ReadIntNumberBetween(1, 6);

    }
    static void  _GobackToTransactionScreen() {
        ShowTransactionScreenMenu();
    }
    static void _ShowTransferScreen() {
        //cout << "here Transfer screen" << endl;
        clsShowTransferScreen::ShowTransferScreen();
    }
    static void _ShowDeposeScreen() {
        //cout << "here is DeposeScreen" << endl;
        clsDeposeScreen::ShowDeposeScreen();
        system("pause>0");
    }
    static void _ShowLogTransferScreen() {
        //cout << "here is Log Transfer Screen" << endl;
        clsShowLogTransferScreen::ShowLogTransferClientsList();
        system("pause>0");
    }
    static void _showwithDrawScreen() {
        //cout << "here is withDrawScreen" << endl;
        clsWithdrawScreen::ShowWithDrawScreen();
        system("pause>0");

    }
    static void _ShowTotalBalanceScreen() {
        //cout << "here is Total Balance" << endl;
        clsTotalBalancesScreen::ShowTotalBalances();
        system("pause>0");
        
    }
    static void _PerformTransactionOption(enTransactionsMenuOptions OptionTran) {
        switch (OptionTran)
        {
        case enTransactionsMenuOptions::eDepose: {
            system("cls");
            _ShowDeposeScreen();
            _GobackToTransactionScreen();
        }
            break;
        case enTransactionsMenuOptions::ewithDraw: {
            system("cls");
            _showwithDrawScreen();
            _GobackToTransactionScreen();
        }
           break;
        case enTransactionsMenuOptions::etransfer: {
            system("cls");
            _ShowTransferScreen();
            _GobackToTransactionScreen();
        }
                                                 break;
        case enTransactionsMenuOptions::eLogTransfer: {
            system("cls");
            _ShowLogTransferScreen();
            _GobackToTransactionScreen();
        }
                                                 break;

        case enTransactionsMenuOptions::eTotalBalance: {
            system("cls");
            _ShowTotalBalanceScreen();
            _GobackToTransactionScreen();

        }
           break;
        case enTransactionsMenuOptions::GoBackToMenMenu:{
               system("cls");
               

           }
                    break;


        
            
        }
    }
public:
    static void ShowTransactionScreenMenu() {
        if (!CheckAcessRight(clsUser::enPermissions::pTranactions)) {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t\tTransaction Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransactionMenue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit .\n";
        cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Log transfer.\n";
        cout << setw(37) << left << "" << "\t[6] Govback To MainMenu.\n";
        
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformTransactionOption((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
    }
};

