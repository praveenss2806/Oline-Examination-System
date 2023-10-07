#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include "test.h"
using namespace std;

struct DETAIL
{
    string name;
    string rollno;
};

class student
{
private:
    DETAIL detail;
    fstream sfile;
    test exm;

public:
    student();
};

student::student()
{
    cout << "\t\t\t\t********Welcome Students********\n";
    cout << "\nPlease Enter your name and roll no to start the exam\n";

    sfile.open("details.txt", ios::in | ios::out);
    sfile.seekp(0L, ios::beg);

    cout << "\nEnter your name:";
    fflush(stdin);
    cin >> detail.name;

    cout << "\nEnter your rollno:";
    fflush(stdin);
    cin >> detail.rollno;

    sfile.write((char *)&detail, sizeof(detail));
    sfile.close();

    cout << "\n\t\t\t\t******All the Best for the Exam******\n";

    exm.start();
}
