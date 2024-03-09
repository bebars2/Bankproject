#pragma once
#include<iostream>
#include <iomanip>
#include"clsUser.h"
#include"clsScreen.h"
class clsShowListUserScreen:protected clsScreen
{
private:
	static void _PrintUserRecordLine(clsUser User)
	{

		cout << "\t" << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(20) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;

	}
public:
	static void ShowUsersList()
	{

		vector <clsUser> vUser = clsUser::GetUsersList();
		_DrawScreenHeader("All User Screen", "Number Users (" + to_string(vUser.size()) + ")");
		cout << "\n\t\t\t\t\tClient List (" << vUser.size() << ") User(s).";
		cout << "\n\t_______________________________________________________";
		cout << "\t_________________________________________\n" << endl;

		cout << "\t| " << left << setw(15) << "User Number";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << "\n\t_______________________________________________________";
		cout << "\t_________________________________________\n" << endl;

		if (vUser.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsUser User : vUser)
			{

				_PrintUserRecordLine(User);
				cout << endl;
			}

		cout << "\n\t_______________________________________________________";
		cout << "\t_________________________________________\n" << endl;

	}


};

