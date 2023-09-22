#include <bits/stdc++.h>
#include <string.h>
#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;
void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

class customer
{
private:
    string name, room_no, service, address, email_id, contact_no;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};

void customer::menu()
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| HOTEL MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t Add Another Customer Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;

    case 2:
        display();
        break;

    case 3:
        modify();
        break;

    case 4:
        search();
        break;

    case 5:
        deleted();
        break;

    case 6:
        printf("!!!THANK YOU!!!");
        exit(0);

    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    getch();
    goto menustart;
}
void customer::insert() // add customer details
{
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Customer Details ---------------------------------------------" << endl;
    
    cout << "\t\t\tEnter Customer Name: ";
    cin >> name;
    cout << "\t\t\tEnter Room No.: ";
    cin >> room_no;
    cout << "\t\t\tEnter WI-FI/NON WI-FI(Y/N) ";
    cin >> service;
    cout << "\t\t\tEnter Email Id: ";
    cin >> email_id;
    cout << "\t\t\tEnter Contact No: ";
    cin >> contact_no;
    cout << "\t\t\tEnter Address: ";
    cin >> address;
    file.open("customerRecord.txt", ios::app | ios::out);
    file << " " << name << " " << room_no << " " << service << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();
}

void customer::display() // display customer details
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Customer Record Table --------------------------------------------" << endl;
    file.open("customerRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo file Is Present...";
        file.close();
    }
    else
    {
        file >> name >> room_no >> service >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Customer No.: " << total++ << endl;
            cout << "\t\t\t Customer Name: " << name << endl;
            cout << "\t\t\t Customer Room No.: " << room_no << endl;
            cout << "\t\t\t Customer WI-FI/NON WI-FI : " << service << endl;
            cout << "\t\t\t Customer Email Id.: " << email_id << endl;
            cout << "\t\t\t Customer Contact No.: " << contact_no << endl;
            cout << "\t\t\t Customer Address: " << address << endl;
            file >> name >> room_no >> service >> email_id >> contact_no >> address;
        }
        if (total == 1)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file.close();
}
void customer::modify() // Modify Customer Details
{
    system("cls");
    fstream file, file1;
    string roomno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Customer Modify Details ------------------------------------------" << endl;
    file.open("customerRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo file is Present..";
    }
    else
    {
        cout << "\nEnter Room No. of Customer which you want to Modify: ";
        cin >> roomno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> room_no >> service >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (roomno != room_no)

                file1 << " " << name << " " << room_no << " " << service << " " << email_id << " " << contact_no << " " << address << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Room No.: ";
                cin >> room_no;
                cout << "\t\t\tEnter WI-FI/NON WI-FI ";
                cin >> service;
                cout << "\t\t\tEnter Email Id: ";
                cin >> email_id;
                cout << "\t\t\tEnter Contact No.: ";
                cin >> contact_no;
                cout << "\t\t\tEnter Address: ";
                cin >> address;
                file1 << " " << name << " " << room_no << " " << service << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> name >> room_no >> service >> email_id >> contact_no >> address;
            
        }
        if (found == 0)
            {
                cout << "\n\n\t\t\t Customer Room No. Not Found....";
            }
        file1.close();
        file.close();
        remove("customerRecord.txt");
        rename("record.txt", "customerRecord.txt");
    }
}
void customer::search() // search data of customer
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("customerRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Customer Search Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No file Is Present...";
    }
    else
    {
        string roomno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Customer Search Data ------------------------------------------" << endl;
        cout << "\n Enter Room No. of Customer Which You Want to Search: ";
        cin >> roomno;
        file >> name >> room_no >> service >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (roomno == room_no)
            {
                cout << "\n\t\t\t Customer Name: " << name << endl;
                cout << "\t\t\t Customer Room No.: " << room_no << endl;
                cout << "\t\t\t Customer WI-FI/NON WI-FI: " << service << endl;
                cout << "\t\t\t Customer Email Id.: " << email_id << endl;
                cout << "\t\t\t Customer Address: " << address << endl;
                found++;
            }
            file >> name >> room_no >> service >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tCustomer Room No. Not Found...";
        }
        file.close();
    }
}
void customer::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string room;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Customer Details ------------------------------------------" << endl;
    file.open("customerRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo file is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Room No. of Customer which you want Delete Data: ";
        cin >> room;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> room_no >> service >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (room != room_no)
            {
                file1 << " " << name << " " << room_no << " " << service << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> room_no >> service >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Customer Room NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("customerRecord.txt");
        rename("record.txt", "customerRecord.txt");
    }
}
main()
{   
    string userNametxt;
    string userPasswordtxt;
    fstream file;
    file.open("Password.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo file Is Present...";
        file.close();
    }
    else
    {
        file >> userNametxt >> userPasswordtxt;
    }
    file.close();

    int loginAttempt = 0;
    system("cls");
    customer project;
    string userName;
    string userPassword;
    while (loginAttempt < 5)
    {
        cout << "----------------------------------------------------------------------------\n";
        gotoxy(0, 3);
        cout << "----------------------------------------------------------------------------\n";
        gotoxy(0, 1);
        cout << "                             User Name: ";
        cin >> userName;
        cout << "                             Password: ";
        cin >> userPassword;
        if (userName == userNametxt && userPassword == userPasswordtxt)
        {
            gotoxy(0, 0);
            system("cls");
            project.menu();
            
        }
        else
        {
            gotoxy(0, 4);
            cout << "Invalid login details. Please try again.\n"
                 << '\n';
            getch();
            system("cls");
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
        cout << "Too many login attempts! The program will now terminate.";
        return 0;
    }
    
    return 0; 
} 
