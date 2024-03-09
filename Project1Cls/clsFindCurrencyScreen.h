#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
using namespace std;

class clsFindCurrencyScreen:protected clsScreen
{
private:
	enum enFindWay {
		eByCountry=1,eByCode=2
	};
	enFindWay Result;
	static enFindWay _ReadFindWay() {

		return (enFindWay)clsInputValidate::ReadIntNumberBetween(1,2);

	}
	static void _PrintCurrency(clsCurrency Currency) {
		cout << "Currency Card : " << endl;
		cout << "\n______________________________"<<endl;
		cout <<"Countey: " << Currency.Country() << endl;
		cout <<"Code: "<< Currency.CurrencyCode() << endl;
		cout <<"Name: " << Currency.CurrencyName() << endl;
		cout <<"Rate(1$): " << Currency.Rate()<<endl;
		cout << "______________________________\n";

	}
	static clsCurrency _perfortFind(enFindWay FindWay) {
		switch (FindWay)
		{
		case enFindWay::eByCountry: {
			cout << "enter Country Name" << endl;
			return clsCurrency::FindByCurrencyName(clsInputValidate::ReadName());
		}
								  break;
		case enFindWay::eByCode:
			cout << "enter Currency Code" << endl;
			return clsCurrency::FindByCurrencyCode(clsInputValidate::ReadName());
			break;




		}
	}
public:
	static void ShowFindScreen() {
		_DrawScreenHeader("\tFind Currency Screen");
		cout << "Find By [1] Country OR [2] Code?";
		clsCurrency Currency = _perfortFind(_ReadFindWay());
		if (Currency.IsEmpty()) {
			cout << "not Found :-(" << endl;
		}
		else {
			cout << "Is Found :-) " << endl;
			_PrintCurrency(Currency);
		}

		

	}

};

