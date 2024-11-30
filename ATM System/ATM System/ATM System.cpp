#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

const string ClientFileName = "Client.txt";  

struct stClient
{
    string Account_Number;
    string PIN_Code;
    string Name;
    string Phone;
    double Account_Balance;

    bool Mark_Client_For_Delete = false;
};

stClient Current_Client;  


void Show_ATM_Main_Menue_Screen();
void Login();     
void Show_Quick_Withdraw_Screen(); 
void Show_Normal_Withdraw_Screen();


vector <string> Split_String(string S1, string Delimiter = "#//#") {

    short Pos = 0;
    string sWord;

    vector <string> vString;

    while ((Pos = S1.find(Delimiter)) != std::string::npos) {

        sWord = S1.substr(0, Pos);

        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, Pos + Delimiter.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}


stClient Convert_ClientDataLine_To_Record(string Line, string Delimiter = "#//#") {

    vector <string> vRecord = Split_String(Line);
    stClient Client;

    Client.Account_Number = vRecord[0];
    Client.PIN_Code = vRecord[1];
    Client.Name = vRecord[2];
    Client.Phone = vRecord[3];
    Client.Account_Balance = stod(vRecord[4]);

    return Client;
}


vector <stClient> Load_ClientData_From_File(string FileName) {

    fstream My_File;

    string Line;
    stClient Client;

    vector <stClient> vClient;

    My_File.open(FileName, ios::in);

    if (My_File.is_open())
    {
        while (getline(My_File, Line)) {

            Client = Convert_ClientDataLine_To_Record(Line);
            vClient.push_back(Client);
        }

        My_File.close();
    }

    return vClient;
}



string Convert_ClientData_Record_To_Line(stClient Client, string Delimiter = "#//#") {

    string Line = "";

    Line += Client.Account_Number + Delimiter;
    Line += Client.PIN_Code + Delimiter;
    Line += Client.Name + Delimiter;
    Line += Client.Phone + Delimiter;
    Line += to_string(Client.Account_Balance);

    return Line;
}



vector <stClient> Save_Client_Data_To_File(string FileName, vector<stClient> vClient) {

    fstream My_File;
    string Line;

    My_File.open(FileName, ios::out);

    if (My_File.is_open())
    {
        for (stClient& Client : vClient)
        {

            if (Client.Mark_Client_For_Delete == false)
            {
                Line = Convert_ClientData_Record_To_Line(Client);
                My_File << Line << endl;
            }

        }

        My_File.close();
    }

    return vClient;
}


bool Deposit_Balance_To_Client_By_Account_Number(string Account_Number, vector<stClient>& vClient, double Amount) {

    char Answer = 'n';

    cout << "\nAre U Sure U Want Perform This Transaction? (Y/N)? ";
    cin >> Answer;

    if (toupper(Answer) == 'Y')
    {
        for (stClient& Client : vClient)
        {
            if (Client.Account_Number == Account_Number)
            {
                Client.Account_Balance += Amount;
                Save_Client_Data_To_File(ClientFileName, vClient);

                cout << "\nDone Successfully. New Balance is : " << Client.Account_Balance << endl;
                return true;
            }
        }

        return false;
    }
    else
    {
        return false;
    }
}


short Read_Quick_Withdraw_Option() {
    short Option = 0;

    do
    {
        cout << "Choose What To Do From [1] => [9]? ";
        cin >> Option;

    } while (Option < 1 || Option > 9);

    return Option;
}


short Get_Quick_WithDraw_Amount(short Option) {

    switch (Option)
    {
    case 1:
        return 20;

    case 2:
        return 50;

    case 3:
        return 100;

    case 4:
        return 200;

    case 5:
        return 400;

    case 6:
        return 600;

    case 7:
        return 800;

    case 8:
        return 1000;

    default:
        return 0;
    }
}


void Perform_Quick_Withdraw_Option(short Option) {

    if (Option == 9)
        return;         

    short Amount = Get_Quick_WithDraw_Amount(Option);

    if (Amount > Current_Client.Account_Balance) {

        cout << "The Amount Exceeds Ur Balance, Make Another Choice.\n";
        cout << "Press Any Key To Continue...";
        system("pause>0");

        Show_Quick_Withdraw_Screen();
        return;
    }

    vector <stClient> vClient = Load_ClientData_From_File(ClientFileName); 

    if (Deposit_Balance_To_Client_By_Account_Number(Current_Client.Account_Number, vClient, Amount * -1))  
    {
        Current_Client.Account_Balance -= Amount;  
    }
    
}




void Show_Quick_Withdraw_Screen() {

    system("cls");

    cout << "\n---------------------------------------------\n";
    cout << "\t  Quick Withdraw Screen ";
    cout << "\n---------------------------------------------\n";

    cout << "\t  [1] 20  \t[2] 50  \n";
    cout << "\t  [3] 100 \t[4] 200 \n";
    cout << "\t  [5] 400 \t[6] 600 \n";
    cout << "\t  [7] 800 \t[8] 1000\n";
    cout << "\t  [9] Exit";
     
    cout << "\n---------------------------------------------\n";

    cout << "Your Balance is " << Current_Client.Account_Balance << endl; 

    Perform_Quick_Withdraw_Option(Read_Quick_Withdraw_Option());

}


int Read_Amount_Multiple_Of_5() {
    int Amount;

    do
    {
        cout << "\nEnter An Amount Multiple Of 5's  ";
        cin >> Amount;

    } while (Amount % 5 != 0);

    return Amount;
}


void Perform_Normal_Withdraw_Option() {

    int Amount = Read_Amount_Multiple_Of_5();  

    if (Amount > Current_Client.Account_Balance) {     

        cout << "The Amount Exceeds Ur Balance, Make Another Choice.\n";  
        cout << "Press Any Key To Continue..."; 
        system("pause>0");

        Show_Normal_Withdraw_Screen();
        return;
    }

    vector <stClient> vClient = Load_ClientData_From_File(ClientFileName); 

    if (Deposit_Balance_To_Client_By_Account_Number(Current_Client.Account_Number, vClient, Amount * -1)) 
    {
        Current_Client.Account_Balance -= Amount;  
    }

}
    


void Show_Normal_Withdraw_Screen() {

    system("cls");

    cout << "\n---------------------------------------------\n";
    cout << "\t  Normal Withdraw Screen ";
    cout << "\n---------------------------------------------\n";

    Perform_Normal_Withdraw_Option();
}


double Read_Deposit_Amount() {
    double Amount;

    do
    {
        cout << "Enter A Positive Deposit Amount? ";
        cin >> Amount; 

    } while (Amount <= 0);

    return Amount; 
}


void Perform_Deposit_Option() {
    
    double Amount = Read_Deposit_Amount();
    vector <stClient> vClient = Load_ClientData_From_File(ClientFileName);

    if (Deposit_Balance_To_Client_By_Account_Number(Current_Client.Account_Number, vClient, Amount)) 
    {
        Current_Client.Account_Balance += Amount;      
    }
   
}


void Show_Deposit_Screen() {

    system("cls");

    cout << "\n---------------------------------------------\n";
    cout << "\t\t Deposit Screen ";
    cout << "\n---------------------------------------------\n";

    Perform_Deposit_Option();
}


void Show_Check_Balance_Screen() {  

    system("cls");

    cout << "\n---------------------------------------------\n";
    cout << "\t  Check Balance Screen ";
    cout << "\n---------------------------------------------\n";

    cout << "Your Balance is " << Current_Client.Account_Balance << endl;  
}




enum enATMMainMenueOptions {
    eQuickWithdraw = 1, eNormalWithdraw = 2, eDeposit = 3, eCheckBalance = 4, eLogout = 5
};


void Back_To_ATM_Main_Menue_Screen() { 

    cout << "\n\nPress Any Key To Go Back To ATM Main Menue... ";  
    system("pause>0"); 

    Show_ATM_Main_Menue_Screen(); 
}


short Read_ATM_Main_Menue_Option() {
    short Option = 0;

    do
    {
        cout << "Choose What Do U Want To Do? [1 To 5]? ";
        cin >> Option;

    } while (Option < 1 || Option > 5);

    return Option; 
}




void Perform_ATM_Main_Menue_Option(enATMMainMenueOptions Option) {

    switch (Option)
    {
    case enATMMainMenueOptions::eQuickWithdraw:

        Show_Quick_Withdraw_Screen();
        Back_To_ATM_Main_Menue_Screen();
        break;

    case enATMMainMenueOptions::eNormalWithdraw:

        Show_Normal_Withdraw_Screen();
        Back_To_ATM_Main_Menue_Screen();
        break;

    case enATMMainMenueOptions::eDeposit:

        Show_Deposit_Screen();
        Back_To_ATM_Main_Menue_Screen();
        break;

    case enATMMainMenueOptions::eCheckBalance:

        Show_Check_Balance_Screen();
        Back_To_ATM_Main_Menue_Screen();  
        break;


    case enATMMainMenueOptions::eLogout:

        Login();
        break;

    }
}




void Show_ATM_Main_Menue_Screen() {

    system("cls");

    cout << "\n Welcome " << Current_Client.Name; 
    cout << "\n Date : ";

    cout << "\n=================================================\n";
    cout << "\t  ATM Main Menue Screen";
    cout << "\n=================================================\n";

    cout << "\t [1] Quick Withdraw.\n";
    cout << "\t [2] Normal Withdraw.\n";
    cout << "\t [3] Deposit.\n";
    cout << "\t [4] Check Balance.\n";
    cout << "\t [5] Logout.\n";
    cout << "=================================================\n";

    Perform_ATM_Main_Menue_Option((enATMMainMenueOptions)Read_ATM_Main_Menue_Option());
}



void Show_Login_Screen() {

    system("cls");

    cout << "\n---------------------------------------------\n";
    cout << "\t\t Login Screen ";
    cout << "\n---------------------------------------------\n";
}


bool Find_Client_By_Account_Number_And_PIN_Code(string Account_Number, string PIN_Code, stClient&  Client) {

    vector <stClient> vClient = Load_ClientData_From_File(ClientFileName);

    for (stClient& C : vClient)
    {
        if (C.Account_Number == Account_Number && C.PIN_Code == PIN_Code)
        {
            Client = C;
            return true;
        }
    }
    return false;
}


bool Load_Client_Info(string Account_Number, string PIN_Code) {

    if (Find_Client_By_Account_Number_And_PIN_Code(Account_Number,PIN_Code,Current_Client))
    {
        return true;
    }
    return false;
}


void Login() {

    bool Login_Faild = false;
    string Account_Number, PIN_Code;

    do
    {
        Show_Login_Screen();

        if (Login_Faild)
        {
            cout << "Invalid Account Number/PIN_Code! " << endl;
        }


        cout << "Enter Account_Number? ";
        getline(cin >> ws, Account_Number);

        cout << "Enter PIN_Code? ";
        getline(cin >> ws, PIN_Code);

         
        Login_Faild = !Load_Client_Info(Account_Number, PIN_Code); 

    } while (Login_Faild);

    Show_ATM_Main_Menue_Screen();
}



int main()
{
    system("color f3");


    Login();

    system("pause>0");
    return 0;
}