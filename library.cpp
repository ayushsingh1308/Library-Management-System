#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Library
{
public:
    int bookID;
    string title;
    string author;
    bool issued;

    void addBook()
    {
        cout << "\nEnter Book ID: ";
        cin >> bookID;

        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        issued = false;

        ofstream file("library.txt", ios::app);

        file << bookID << endl;
        file << title << endl;
        file << author << endl;
        file << issued << endl;

        file.close();

        cout << "\nBook Added Successfully!\n";
    }
};

void displayBooks()
{
    ifstream file("library.txt");

    int id;
    string title, author;
    bool issued;

    cout << "\n========== BOOK LIST ==========\n";

    while (file >> id)
    {
        file.ignore();

        getline(file, title);
        getline(file, author);

        file >> issued;

        cout << "\nBook ID      : " << id;
        cout << "\nBook Title   : " << title;
        cout << "\nAuthor       : " << author;

        if (issued)
            cout << "\nStatus       : Issued\n";
        else
            cout << "\nStatus       : Available\n";
    }

    file.close();
}

void searchBook()
{
    string search;
    bool found = false;

    cin.ignore();

    cout << "\nEnter Book Title or Author: ";
    getline(cin, search);

    ifstream file("library.txt");

    int id;
    string title, author;
    bool issued;

    while (file >> id)
    {
        file.ignore();

        getline(file, title);
        getline(file, author);

        file >> issued;

        if (title == search || author == search)
        {
            found = true;

            cout << "\nBook Found!";
            cout << "\nBook ID    : " << id;
            cout << "\nTitle      : " << title;
            cout << "\nAuthor     : " << author;

            if (issued)
                cout << "\nStatus     : Issued\n";
            else
                cout << "\nStatus     : Available\n";
        }
    }

    file.close();

    if (!found)
    {
        cout << "\nBook Not Found!\n";
    }
}

void issueBook()
{
    int searchID;
    bool found = false;

    cout << "\nEnter Book ID to Issue: ";
    cin >> searchID;

    ifstream file("library.txt");
    ofstream temp("temp.txt");

    int id;
    string title, author;
    bool issued;

    while (file >> id)
    {
        file.ignore();

        getline(file, title);
        getline(file, author);

        file >> issued;

        if (id == searchID)
        {
            found = true;

            if (!issued)
            {
                issued = true;
                cout << "\nBook Issued Successfully!\n";
            }
            else
            {
                cout << "\nBook Already Issued!\n";
            }
        }

        temp << id << endl;
        temp << title << endl;
        temp << author << endl;
        temp << issued << endl;
    }

    file.close();
    temp.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (!found)
    {
        cout << "\nBook Not Found!\n";
    }
}

void returnBook()
{
    int searchID;
    bool found = false;

    cout << "\nEnter Book ID to Return: ";
    cin >> searchID;

    ifstream file("library.txt");
    ofstream temp("temp.txt");

    int id;
    string title, author;
    bool issued;

    while (file >> id)
    {
        file.ignore();

        getline(file, title);
        getline(file, author);

        file >> issued;

        if (id == searchID)
        {
            found = true;

            if (issued)
            {
                issued = false;
                cout << "\nBook Returned Successfully!\n";
            }
            else
            {
                cout << "\nBook Was Not Issued!\n";
            }
        }

        temp << id << endl;
        temp << title << endl;
        temp << author << endl;
        temp << issued << endl;
    }

    file.close();
    temp.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (!found)
    {
        cout << "\nBook Not Found!\n";
    }
}

int main()
{
    int choice;
    Library book;

    do
    {
        cout << "\n\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            book.addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            returnBook();
            break;

        case 6:
            cout << "\nThank You For Using Library Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

        system("pause");

    } while (choice != 6);

    return 0;
}