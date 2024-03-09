#pragma once
#include<iostream>
#include<vector>
#include "clsString.h"
#include<fstream>
#include<string>
using namespace std;
class clsCurrency
{
private:

	enum enMode {
		eEmptyMode = 0, eUpdateMode = 1
	};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static string _ConverCurrencyObjectToLine(clsCurrency Currency,string Sperator="#//#") {
		string Line="";
		Line += Currency._Country + Sperator;
		Line += Currency._CurrencyCode + Sperator;
		Line += Currency._CurrencyName + Sperator;
		Line += to_string( Currency._Rate);
		return Line;

	}
	static clsCurrency _ConvertLineToCurrencyObject(string Line ,string Sperator="#//#") {
		vector<string>vCurrences = clsString::Split(Line,Sperator);


		return clsCurrency(enMode::eUpdateMode,vCurrences[0], vCurrences[1], vCurrences[2],stof(vCurrences[3]));

	}
	static void _SaveCurrencesDataToFile(vector <clsCurrency> Currencies)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency C : Currencies)
			{
			
					DataLine = _ConverCurrencyObjectToLine(C);
					MyFile << DataLine << endl;

				

			}

			MyFile.close();

		}

	}
	static vector<clsCurrency> _LoadDataFromFile() {
		vector<clsCurrency> vCurrency;
		
		string Line;
		fstream File;
		File.open("Currencies.txt", ios::in);
		if (File.is_open()) {
			while (getline(File, Line)) {

				
				vCurrency.push_back(_ConvertLineToCurrencyObject(Line));

			}
			File.close();
		}
		return vCurrency;
	}
	static clsCurrency _GetEmptyObject() {

		return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
	}
	void _Update() {
		vector<clsCurrency>vCur = _LoadDataFromFile();

		for (clsCurrency &C : vCur) {
			if (C.CurrencyCode() == _CurrencyCode) {
				C = *this;
			}
		}
		_SaveCurrencesDataToFile(vCur);
	}

	

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	bool IsEmpty() {
		return (_Mode == enMode::eEmptyMode);
	}
	string CurrencyCode() {
		return _CurrencyCode;
	}
	string Country() {
		return _Country;
	}
	string CurrencyName() {
		return _CurrencyName;
	}
	float Rate() {
		return _Rate;
	}
	void UpdateRate(float Rate) {
		_Rate = Rate;
		_Update();

	}
	static  clsCurrency FindByCurrencyCode(string CurrencyCode) {
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream File;
		string Line;
		File.open("Currencies.txt", ios::in);
		if (File.is_open()) {
			while (getline(File, Line)) {


				clsCurrency C = _ConvertLineToCurrencyObject(Line);
				if (C.CurrencyCode() == CurrencyCode) {
					File.close();
					return C;
				}

			}
			return _GetEmptyObject();
			
		}
		

	}
	static  clsCurrency FindByCurrencyName(string CountryName) {
		CountryName = clsString::UpperAllString(CountryName);
		fstream File;
		string Line;
		File.open("Currencies.txt", ios::in);
		if (File.is_open()) {
			while (getline(File, Line)) {


				clsCurrency C = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(C.Country()) == CountryName) {
					File.close();
					return C;
				}

			}
			return _GetEmptyObject();

		}


	}
	static bool IsCurrencyExist(string CurrencyCode) {
		clsCurrency C = FindByCurrencyCode(CurrencyCode);
		return (!C.IsEmpty());

	}
	static vector<clsCurrency> GetListCurrences() {
		return _LoadDataFromFile();
	}
	float ConvertFromDollar(float Amount) {
		return Amount * _Rate;

	}
	float ConvertToDollar(float Amount) {
		return (Amount / _Rate);
	}
	float ConvertToAnoutherCurrencye(clsCurrency AnoutherCurrency,float Amount) {

		float AmountInDollar = ConvertToDollar(Amount);
		if (AnoutherCurrency.CurrencyCode() == "USD") {
			return float(AmountInDollar);
		}
		return (float)AnoutherCurrency.ConvertFromDollar(AmountInDollar);



	}


	

};

