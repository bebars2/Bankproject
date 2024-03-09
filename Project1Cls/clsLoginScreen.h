#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include"clsMainScreen.h"
#include "Global.h"

class clsLoginScreen:protected clsScreen
{
private:

	
	static bool _Login() {
		bool FalieResult = false;
		string UserName, Password;
		short NumberToTryLogin = 3;
		do {

			
			
			if (FalieResult) {
				NumberToTryLogin--;
				cout << "Invalde UserName or Password" << endl;
				cout << "you Have " << NumberToTryLogin << " trials to login" << endl;
			}
			if (NumberToTryLogin == 0) {
				cout << "you have 3 failed login you are blocked" << endl;
				return false;
			}
			cout << "UserName : ";
			cin >> UserName;
			cout << "Password : ";
			cin >> Password;
			CurrectUser = clsUser::Find(UserName, Password);

			FalieResult = CurrectUser.IsEmpty();


		} while (FalieResult);
		CurrectUser.RegesterLogin();
		
		clsMainScreen::ShowMainMenue();
		return true;

		
	}


public:
	static bool ShowLoginScreen() {



		_DrawScreenHeader("\t Login Screen","", false);
		return _Login();




	}
	

	

};

