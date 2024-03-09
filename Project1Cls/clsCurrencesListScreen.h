#pragma once
#include <iomanip>
#include "clsScreen.h"
#include"clsCurrency.h"
class clsCurrencesListScreen:protected clsScreen
{
	
private:
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{

		cout << "\t" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << to_string( Currency.Rate());
		

	}
public:
	static void ShowCurrencyList()
	{
		

		vector <clsCurrency> vCurrency = clsCurrency::GetListCurrences();
		_DrawScreenHeader("All Currency Screen", "Number Currency (" + to_string(vCurrency.size()) + ")");
		cout << "\n\t\t\t\t\tCurrency (" << vCurrency.size() << ") Currency(s).";
		cout << "\n\t_______________________________________________________";
		cout << "\t_________________________________________\n" << endl;

		cout << "\t| " << left << setw(30) << "country";
		cout << "| " << left << setw(8) << "code";
		cout << "| " << left << setw(45) << " Name";
		cout << "| " << left << setw(10) << "Rate(1$)";

		cout << "\n\t_______________________________________________________";
		cout << "\t_________________________________________\n" << endl;

		if (vCurrency.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsCurrency Currency : vCurrency)
			{

				_PrintCurrencyRecordLine(Currency);
				cout << endl;
			}

		cout << "\n\t_______________________________________________________";
		cout << "\t_________________________________________\n" << endl;

	}
};

