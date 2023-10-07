#pragma once
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include "questions.h"
using namespace std;

struct SECURITY
{
    string username;
    string password;
};

class admin
{
private:
    SECURITY security;
    fstream file;
    int ch;
    int flag;
    questions q;

public:
    admin();
    void Register();
    int login();
};

// Constructor Definition
admin::admin()
{
    cout << "\t\t\t\t********Welcome To the Administrator Section********\n";
    cout << "\n1-Register\n2-Login\nEnter:";
    cin >> ch;
    if (ch == 1)
    {
        Register();
    }
    else if (ch == 2)
    {
        flag = login();
        if (flag)
        {
            cout << "\nLogin successful!!\n";
            q.ques();
        }
        else
        {
            cout << "\nIncorrect Username or Password!!\nRegister to change Username & Password\n\n";
        }
    }
    else
    {
        cout << "\nGood Bye!!\n";
    }
}

// Register Function Definition
void admin::Register()
{
    file.open("security.txt", ios::binary | ios::in | ios::out);
    file.seekp(0L, ios::beg);
    cout << "\nEnter new Username:";
    fflush(stdin);
    cin >> security.username;
    cout << "\nEnter new Password:";
    fflush(stdin);
    cin >> security.password;
    file.write((char *)&security, sizeof(security));
    file.close();
    cout << "\nThank You for registering\n";
}

// Login Function Definition
int admin::login()
{
    string uname;
    string passwd;
    file.open("security.txt", ios::binary | ios::in | ios::out);
    file.seekg(0L, ios::beg);
    cout << "\nENTER USERNAME:";
    fflush(stdin);
    cin >> uname;
    cout << "\nENTER PASSWORD:";
    fflush(stdin);
    cin >> passwd;
    file.read((char *)&security, sizeof(security));
    if ((uname == security.username) && (passwd == security.password))
        flag = 1;
    else
        flag = 0;
    file.close();
    if (flag == 1)
        return 1;
    else
        return 0;
}
