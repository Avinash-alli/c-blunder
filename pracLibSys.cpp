// Avinash kumar Thakur
// 20HCS4172
// PASSWORD=Avinash

#include <iostream>
#include <conio.h>
#include <string>
int log;
using namespace std;
class Lib
{
    int Book_Id[100];
    int Book_Price[100];
    string Book_name[100];
    int count = 0;
    int fee = 0;
    string Student_name[100];
    string name;

public:
    void returnBook()
    {
        int day;
        fee = 0;
        cout << "Enter your name" << endl;
        cin >> Student_name[count];
        cout << "Enter Book Id :";
        cin >> Book_Id[count];
        cout << "Book Name :";
        cin >> Book_name[count];
        cout << "Book price :";
        cin >> Book_Price[count];
        count++;
        cout << "Enter Nuber of days for you Issued book :";
        cin >> day;

        cout << "Your late book returned fee :" << Fee_Cal(day) << endl;

        cout << " Thanks Book has Succesfully Returned " << endl;
    }
    void Add_Book()
    {

        cout << "Enter Book Id :";
        cin >> Book_Id[count];
        cout << "Book Name :";
        cin >> Book_name[count];
        cout << "Book price :";
        cin >> Book_Price[count];
        count++;

        cout << " Thanks Book has Succesfully Added in Library " << endl;
    }
    int Fee_Cal(int d)
    {
        if (d < 7)
        {
            fee = 0;
        }
        else
        {
            for (int i = 7; i < d; i++)
            {
                fee = fee + 10;
            }
        }

        return fee;
    }

    void Show_Aval_Books()
    {
        cout << "\t===LIST OF AVAILABLE BOOKS===" << endl;
        cout << "Book_Id "
             << "     Book_Name     "
             << "       Book_Price " << endl;
        for (int i = 0; i < count; i++)
        {
            cout << Book_Id[i] << ".)"
                 << "               " << Book_name[i] << "                " << Book_Price[i] << endl;
        }
    }

    void Issue_Book()
    {
        Show_Aval_Books();
        cout << "Enter The Book Id for Issuing :";
        int temp;

        cin >> temp;

        for (int i = 0; i < count; i++)

        {
            if (temp == Book_Id[i])
            {
                Book_Id[i] = 0;
                Book_name[i] = "NA";
                Book_Price[i] = 0;

                cout << "Book has Issued Succesfully" << endl;
            }
        }
    }

    void Student_List()
    {
        cout << "\t===LIST OF Students with Issued books ===" << endl;

        cout << "Student Name  "
             << " \tBook_Id "
             << "     Book_Name     "
             << "       Book_Price " << endl;
        for (int i = 0; i < count; i++)
        {
            cout << Student_name[i] << "\t" << Book_Id[i] << ".)"
                 << "               " << Book_name[i] << "                " << Book_Price[i] << endl;
        }
    }

    void start()
    {

        int t = 0;
        cout << "\tSTUDENT   OR  TEACHER" << endl;
        cout << "Press 1 for Student " << endl;
        cout << "Press 2 for Teacher " << endl;

        cin >> log;
        do
        {
            string pass = "";
            char ch;
            cout << "Username" << endl;
            cin >> name;
            cout << "Enter password\n";
            ch = _getch();
            while (ch != 13)
            { //character 13 is enter
                pass.push_back(ch);
                cout << '*';
                ch = _getch();
            }
            if (pass == "Avinash")
            {
                cout << "\nAccess granted :P\n";
                t = 1;
            }
            else
            {
                cout << "\nAccess aborted...\n";
            }
        } while (t == 0);
    }

    void selectore()
    {

        while (true)
        {

            switch (log)
            {
            case 1:

                cout << "\tLog in as Student " << endl;
                Student_log();

                break;
            case 2:
                cout << "\tLog in as Teacher " << endl;
                teacher_log();

                break;

            default:

                break;
            }
        }
    }
    void Student_log()
    {

        while (true)
        {

            int n;

            //    cout<<"HOW TO USE SYSTEM"<<endl;
            cout << "------------------***********--------------------****************-------------------" << endl;
            cout << "Press 1 For Return Book" << endl;
            cout << "Press 2 For List of Available Books " << endl;
            cout << "Press 3 For Issue BooK" << endl;
            cout << "Press 4  for going Previos step " << endl;
            cout << "Press 5 for Exit " << endl;
            cin >> n;
            switch (n)
            {
            case 1:
                returnBook();
                break;
            case 2:
                Show_Aval_Books();
                break;
            case 3:
                Issue_Book();
                break;
            case 4:
                start();
                selectore();

                break;
            case 5:
                exit(0);
                break;

            default:
                exit(0);

                break;
            }
        }
    }
    void teacher_log()
    {
        while (true)
        {
            int n;
            //    cout<<"HOW TO USE SYSTEM"<<endl;
            cout << "------------------***********--------------------****************-------------------" << endl;

            cout << "Press 1 For Add_Book" << endl;
            cout << "Press 2 For List for Students who issued book" << endl;
            cout << "Press 3 For List of Available Books " << endl;
            cout << "Press 4 For Issue BooK" << endl;
            cout << "Press 5  for going Previos step " << endl;
            cout << "Press 5 for Exit " << endl;

            cin >> n;
            switch (n)
            {
            case 1:
                Add_Book();
                break;
            case 2:
                Student_List();
                break;
            case 3:
                Show_Aval_Books();
                break;
            case 4:
                Issue_Book();
                break;
            case 5:
                start();
                selectore();

                break;
            case 6:
                exit(0);
                break;
            default:
                exit(0);
                break;
            }
        }
    }
};

int main()
{

    cout << "\t\t *******Library Managment*********" << endl;
    cout << "\t\t"
         << "           System" << endl;
    cout << "====================================================================" << endl;
    string name;
    Lib l;

    l.start();
    l.selectore();
}
