#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsCurrency.h"
class clsUpdateRateScreen:protected clsScreen
{
private:
	static float _ReadRate() {
		float NewRate = 0;
		cout << "Enter New Rate" << endl;
		NewRate=clsInputValidate::ReadFloatNumber();
		return NewRate;
	}
	static void _PrintCurrency(clsCurrency Currency) {
		cout << "Currency Card : " << endl;
		cout << "\n______________________________" << endl;
		cout << "Countey: " << Currency.Country() << endl;
		cout << "Code: " << Currency.CurrencyCode() << endl;
		cout << "Name: " << Currency.CurrencyName() << endl;
		cout << "Rate(1$): " << Currency.Rate() << endl;
		cout << "______________________________\n";

	}
public:
	static void ShowUpdateCurrencyScreen() {
		_DrawScreenHeader("\tUpdate Rate Screen");
		string CurrancyeCode = "";
		cout << "\nPlease Enter Currancye Code :";
		CurrancyeCode = clsInputValidate::ReadName();
		while (!clsCurrency::IsCurrencyExist(CurrancyeCode)) {
			cout << "\n Invalid Code , Please Enter Currancye Code :";
			CurrancyeCode = clsInputValidate::ReadName();
		}
		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrancyeCode);
		_PrintCurrency(Currency);
		char Answer='n';
		cout << "are you sure to do update Y/n ?";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			cout << "\n\nUpdate Currancye Rate:";
			cout << "_________________________" << endl;
			Currency.UpdateRate(_ReadRate());
			cout << "Update is Done :-)" << endl;
			_PrintCurrency(Currency);



		}


	}
};

