#pragma once
#include <iostream>
#include"clsUser.h"
#include"Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "",bool DateAndUser=true)
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        if (DateAndUser) {
            clsDate Date = clsDate();
            cout << "\t\t\t\t\t User : " << CurrectUser.FullName() << "\n";
            cout << "\t\t\t\t\t Date : "<<clsDate::DateToString(Date)<<"\n";
        }
    }
    static bool CheckAcessRight(clsUser::enPermissions Perm) {
        if (!CurrectUser.ChickUserHaveAccsesPermaion(Perm)) {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t You Don't have permission to do this  ";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;

        }
        else {
            return true;
        }
    }


};

