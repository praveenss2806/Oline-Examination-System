#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct QUESTION
{
    string que;
    string fians;
    string sans;
    string tans;
    string foans;
    string nans;
    int ans[5];
    int anss;
};

class questions
{
private:
    QUESTION question;
    fstream file2;
    int c;

public:
    void ques();
    void write_new_exam();
    void add_questions();
    void read_exam();
    void input_q_and_a();
};

// Constructor Definition
void questions::ques()
{
    cout << "\n1-To set new exam\n2-Add question to existing exam\n3-View Exam Paper\nEnter:";
    cin >> c;
    if (c == 1)
    {
        write_new_exam();
    }
    else if (c == 2)
    {
        add_questions();
    }
    else if (c == 3)
    {
        read_exam();
    }
    else
    {
        cout << "\nSee you Next time!bye!\n";
    }
}

void questions::input_q_and_a()
{
    cout << "\n Enter the question:";
    fflush(stdin);
    cin >> question.que;

    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter choice " << i + 1 << " :";
        fflush(stdin);
        if (i == 0)
        {
            cin >> question.fians;
        }
        else if (i == 1)
        {
            cin >> question.sans;
        }
        else if (i == 2)
        {
            cin >> question.tans;
        }
        else if (i == 3)
        {
            cin >> question.foans;
        }
        else if (i == 4)
        {
            cin >> question.nans;
        }

        cout << "\n is it correct answer if yes press 1 else 2:";
        fflush(stdin);
        cin >> question.ans[i];

        if (question.ans[i] == 1)
        {
            question.anss = question.ans[i];
        }
    }
}

// Function definition for write_new_exam
void questions::write_new_exam()
{
    file2.open("exam.txt", ios::binary | ios::in | ios::out);
    file2.seekp(0L, ios::beg);

    input_q_and_a();

    file2.write((char *)&question, sizeof(question));
    file2.close();
}

// Add Questions Function
void questions::add_questions()
{
    file2.open("exam.txt", ios::binary | ios::in | ios::out);
    file2.seekp(0L, ios::end);

    input_q_and_a();

    file2.write((char *)&question, sizeof(question));
    file2.close();
}

void questions::read_exam()
{
    cout << "\n\t\t\t\t*********View Exam Paper*********\n";
    int coun;
    file2.open("exam.txt", ios::binary | ios::in | ios::out);
    file2.seekg(0L, ios::beg);
    while (file2.read((char *)&question, sizeof(question)))
    {
        coun = 0;
        cout << "\n"
             << question.que << "\n";
        cout << "1*)" << question.fians;
        cout << "\n2*)" << question.sans;
        cout << "\n3*)" << question.tans;
        cout << "\n4*)" << question.foans;
        cout << "\n5*)" << question.nans;
        for (const auto &i : question.ans)
        {
            ++coun;
            if (i == 1)
                cout << "\nAnswer is:" << coun;
        }
        cout << "\n\n**********";
        cout << "X******X";
        cout << "**********\n\n";
    }
    file2.close();
}
