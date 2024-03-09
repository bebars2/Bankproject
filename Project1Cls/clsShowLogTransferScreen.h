#pragma once
#include "clsBankClient.h"
#include <iomanip>
#include "clsScreen.h"

class clsShowLogTransferScreen:protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBankClient::stTransferLog stLogClient)
	{

		cout << "\t" << "| " << setw(20) << left << stLogClient.LogDate;
		cout << "| " << setw(6)  << left << stLogClient.SenderAccountNumber;
		cout << "| " << setw(6)  << left << stLogClient.DestnationAccountNumber;
		cout << "| " << setw(10) << left << stLogClient.Amount;
		cout << "| " << setw(10) << left << stLogClient.SenderBalance;
		cout << "| " << setw(10) << left << stLogClient.DesBalance;
		cout << "| " << setw(6)  << left << stLogClient.UserName;

	}
public:
	static void ShowLogTransferClientsList()
	{
		

		vector <clsBankClient::stTransferLog> vLogRecords = clsBankClient::GetTransferLog();
		_DrawScreenHeader("All Transfer Screen", "Number Transfer (" + to_string(vLogRecords.size()) + ")");
		cout << "\n\t\t\t\t\tTransfer List (" << vLogRecords.size() << ") Transfer(s).";
		cout << "\n\t_______________________________________________________";
		cout << "\t_________________________________________\n" << endl;

		cout << "\t| " << left << setw(20) << "Date";
		cout << "| " << left << setw(6) << "S.Acc";
		cout << "| " << left << setw(6) << "D.Acc";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "S.Balance";
		cout << "| " << left << setw(10) << "D.Balance";
		cout << "| " << left << setw(6) << "UserName";
		cout << "\n\t_______________________________________________________";
		cout << "\t_________________________________________\n" << endl;

		if (vLogRecords.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient::stTransferLog Record : vLogRecords)
			{

				_PrintClientRecordLine(Record);
				cout << endl;
			}

		cout << "\n\t_______________________________________________________";
		cout << "\t_________________________________________\n" << endl;

	}

};

