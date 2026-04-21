#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Person
{
    char surname[50];
    char address[100];
    char telNumber[20];
};

void addData()
{
    ofstream outFile("data.bin", ios::app | ios::binary);
    if (!outFile)
        return;

    int n;
    cout << "How many people do you want to add? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Person p;
        cout << "\nPerson #" << i + 1 << endl;
        cout << "Enter surname: ";
        cin >> p.surname;
        cin.ignore();
        cout << "Enter address: ";
        cin.getline(p.address, 100);
        cout << "Enter tel. number: ";
        cin >> p.telNumber;

        outFile.write((char *)&p, sizeof(Person));
    }

    outFile.close();
    cout << "\nAdded successfully!" << endl;
}

void viewData()
{
    ifstream inFile("data.bin", ios::binary | ios::ate);
    if (!inFile)
    {
        cout << "File is empty or not found." << endl;
        return;
    }

    long fileSize = inFile.tellg();
    int count = fileSize / sizeof(Person);
    inFile.seekg(0, ios::beg);

    cout << "Count of people in file: " << count << endl;

    Person p;
    while (inFile.read((char *)&p, sizeof(Person)))
    {
        cout << "------------------------" << endl;
        cout << "Person name: " << p.surname << endl;
        cout << "address: " << p.address << endl;
        cout << "phone: " << p.telNumber << endl;
    }
    inFile.close();
}

void deleteData()
{
    ifstream inFile("data.bin", ios::binary);
    if (!inFile)
        return;

    char name[50];
    cout << "Enter surname to delete: ";
    cin >> name;

    ofstream tempFile("temp.bin", ios::binary);
    Person p;
    bool found = false;

    while (inFile.read((char *)&p, sizeof(Person)))
    {
        if (strcmp(p.surname, name) != 0)
        {
            tempFile.write((char *)&p, sizeof(Person));
        }
        else
        {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("data.bin");
    rename("temp.bin", "data.bin");

    if (found)
        cout << "Deleted successfully." << endl;
    else
        cout << "Not found." << endl;
}

void findTask()
{
    ifstream inFile("data.bin", ios::binary);
    if (!inFile)
        return;

    char searchName[50];
    cout << "Enter surname to find phone: ";
    cin >> searchName;

    Person p;
    bool found = false;
    while (inFile.read((char *)&p, sizeof(Person)))
    {
        if (strcmp(p.surname, searchName) == 0)
        {
            cout << "Result: " << p.surname << " - " << p.telNumber << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Not found." << endl;
    inFile.close();
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. View data" << endl;
        cout << "2. Add data" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Individual task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter number of menu>";
        cin >> choice;

        if (choice == 1)
            viewData();
        else if (choice == 2)
            addData();
        else if (choice == 3)
            deleteData();
        else if (choice == 4)
            findTask();
        else if (choice == 5)
            break;
        else
            cout << "Unknown command." << endl;
    }
    return 0;
}
