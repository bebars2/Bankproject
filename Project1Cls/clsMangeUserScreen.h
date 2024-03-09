#pragma once
#include<iostream>
#include <iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsShowListUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsAddNewUser.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;
class clsMangeUserScreen:protected clsScreen
{
private:

	enum enUserManagerOptions
	{
		ListUser=1,AddUser=2,DeleteUser=3,UpdateUser=4,FindUser=5,UMainMenu=6

	};
	static int _ReadUserOption() {
		return clsInputValidate::ReadIntNumberBetween(1, 6);
	}
	static void _GoToManageUserScreen() {
		system("pause>0");
		ShowUserManagerScreen();



	}

	static void _ShowListUsersScreen() {
		//cout << "user screen";
		clsShowListUserScreen::ShowUsersList();
	}
	static void _ShowAddUserScreen() {
		//cout << "add user screen";
		clsAddNewUser::ShowAddNewUserScreen();
		
	}
	static void _ShowDeleteUserScreen() {
		//cout << "Delete User Screen";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen() {
		//cout << "Update User Screen";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen() {
		//cout << "Find User";
		clsFindUserScreen::ShowFindUserScreen();

	}
	static void _GoBackMainMenu() {
		//backe to main menu Screen
	}
	static void _PerformUSerOption(enUserManagerOptions OptionUser) {
		switch (OptionUser)
		{
		case enUserManagerOptions::ListUser: {
			system("cls");
			_ShowListUsersScreen();
			_GoToManageUserScreen();
		}
										   break;
		case enUserManagerOptions::AddUser: {
			system("cls");
			_ShowAddUserScreen();
			_GoToManageUserScreen();


		}
										  break;
		case enUserManagerOptions::DeleteUser: {
			system("cls");
			_ShowDeleteUserScreen();
			_GoToManageUserScreen();

		}
											 break;
		case enUserManagerOptions::UpdateUser: {
			system("cls");
			_ShowUpdateUserScreen();
			_GoToManageUserScreen();
		}
											 break;
		case enUserManagerOptions::FindUser: {
			system("cls");
			_ShowFindUserScreen();
			_GoToManageUserScreen();
		}
										   break;
		case enUserManagerOptions::UMainMenu: {
		
		}

		}
	}

public:
	static void ShowUserManagerScreen() {
		if (!CheckAcessRight(clsUser::enPermissions::pManageUsers)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("\t\tUser Manager  Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show User List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Mian Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformUSerOption((enUserManagerOptions)_ReadUserOption());
	}

};

