#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include"clsDate.h"
#include <vector>
#include <fstream>
#include "clsUtility.h"
#include "Global.h"

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1,AddMode=2 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete=false;
 
    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }
    

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("C:\\Users\\yuki\\Downloads\\Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("C:\\Users\\yuki\\Downloads\\Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C._MarkedForDelete == false) {
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }
    struct stTransferLog;
    string _MakeTransferRecord(double Amount,clsBankClient DestClient,string Sperator="#//#") {
        string Line = "";
        Line += clsDate::GetsystemDatewithDetal() + Sperator;
        Line += _AccountNumber + Sperator;
        Line += DestClient.AccountNumber() + Sperator;
        Line += to_string(Amount) + Sperator;
        Line += to_string(_AccountBalance) + Sperator;
        Line += to_string(DestClient.AccountBalance) + Sperator;
        Line += CurrectUser.GetUserName();

        return Line;



    }
    static stTransferLog _ConvertLogLineToStructLogTransfer(string Line ,string Sperator="#//#") {
        stTransferLog stLog;
        vector<string> vLog = clsString::Split(Line,Sperator);
        stLog.LogDate = vLog[0];
        stLog.SenderAccountNumber = vLog[1];
        stLog.DestnationAccountNumber = vLog[2];
        stLog.Amount = vLog[3];
        stLog.SenderBalance = vLog[4];
        stLog.DesBalance = vLog[5];
        stLog.UserName = vLog[6];
        return stLog;


    }
    static vector<stTransferLog> _LoadLogTransferDataFromFile() {
        vector <stTransferLog> vLogTransferData;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                stTransferLog LogtransferClient = _ConvertLogLineToStructLogTransfer(Line);

                vLogTransferData.push_back(LogtransferClient);
            }

            MyFile.close();

        }

        return vLogTransferData;

    }
    

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("C:\\Users\\yuki\\Downloads\\Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
    void _AddClient() {
        _AddDataLineToFile(_ConverClientObjectToLine(*this));
        
    }
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    void _SaveTransferLogDataToFile(double Amount, clsBankClient DestClient, string Sperator = "#//#")
    {

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out|ios::app);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            
                    //we only write records that are not marked for delete.  
                    DataLine = _MakeTransferRecord(Amount,DestClient,Sperator);
                    MyFile << DataLine << endl;


            MyFile.close();

        }

    }
    
public:
    struct stTransferLog {
        string LogDate = "";
        string SenderAccountNumber = "";
        string DestnationAccountNumber = "";
        string Amount = "";
        string SenderBalance = "";
        string DesBalance = "";
        string UserName = "";
    };
    

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }
    bool GetMarkdeForDelete() {
        return _MarkedForDelete;
    }
    void SetMarkedForDelete(bool MarkedForDelete)
    {
        _MarkedForDelete = MarkedForDelete;
    }
    __declspec(property(get = GetMarkdeForDelete, put = SetMarkedForDelete)) bool MarkedForDelete;

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }

    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("C:\\Users\\yuki\\Downloads\\Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }
  

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("C:\\Users\\yuki\\Downloads\\Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1,svFaildclientIsExsist };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {

            return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }
        case enMode::AddMode: {
            if (clsBankClient::IsClientExist(_AccountNumber)) {
                return enSaveResults::svFaildclientIsExsist;
            }
            else {
                _AddClient();
                    _Mode = enMode::UpdateMode;
                    return  enSaveResults::svSucceeded;
                    
            }
            break;
        }

        }



    }
    bool Delete() {
        vector<clsBankClient> vClients = _LoadClientsDataFromFile();
        for (clsBankClient& C : vClients) {
            if (C.AccountNumber() == _AccountNumber) {
                C._MarkedForDelete = true;
               
                break;
            }

        }
        _SaveCleintsDataToFile(vClients);
        *this = _GetEmptyClientObject();

        return true;
    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }
    static clsBankClient GetNewClient(string AccountNumber) {
        return clsBankClient(enMode::AddMode, "", "", "", "", AccountNumber, "", 0);
    }
    static vector<clsBankClient> GetClientsList() {
        return _LoadClientsDataFromFile();
    }
    static float GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;

    }
    void Depose(double Amount) {
        _AccountBalance = _AccountBalance + Amount;
        Save();
    }
    bool WithDraw(double Amount) {
        if (_AccountBalance < Amount) {
            return false;
        }
        else {
            _AccountBalance = _AccountBalance - Amount;
            Save();
        }
    }
    bool Transfer(double Amount, clsBankClient& DestenationClient) {
        if (Amount > AccountBalance || (AccountNumber() == DestenationClient.AccountNumber())) {
            return false;
        }

        WithDraw(Amount);
        DestenationClient.Depose(Amount);
        _SaveTransferLogDataToFile(Amount, DestenationClient);
        
        return true;
    }
    static vector<stTransferLog> GetTransferLog() {
        return _LoadLogTransferDataFromFile();
    }

  


};





