
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//Contact Management System Class
class CMS
{
    //3 variables declared as Private Name, Phone Number and Email 
private:
    string name[100];
    string pNo[100];
    string email[100];

public:
    //Divided into functions that can be accessed through objects
    void adddata() {
        cout << "===============================";
        cout << "Enter the Following information";
        cout << "===============================";
        cout << endl;
        for (int i = 0; i < 100; i++)
        {
            char b;
            //After adding data customer can go for a loop until No is obtained
            cout << "Enter Name of the Customer :";
            cin >> name[i];
            cout << "Enter Phone Number of the Customer :";
            cin >> pNo[i];
            cout << "Enter Email Address of the Customer :";
            cin >> email[i];
            cout << endl;
            cout << "Do you want to enter Another Data (y/n) :";
            cin >> b;
            cout << "===========================";
            cout << endl;
            if (b == 'y')
            {
                continue;
            }
            else {
                break;
            }
        }
    }

    void showdata()
    {
        cout << "===========================";
        cout << "Following is the List of data";
        cout << "===========================";
        cout << endl;
        for (int i = 0; i < 100; i++)
        {
            //If there is no data added or No file existed named as Data.txt than show empty
            if (name[i].empty()) {
                break;
            }
            //Show data
            else {
                cout << "Name :" << name[i] << endl;
                cout << "Phone Number :" << pNo[i] << endl;
                cout << "Email Address :" << email[i] << endl;
            }
            cout << endl;
            cout << "=========================";
            cout << endl;
        }
    }

    void editData() {
        cout << "Enter Phone Number of the data you want to edit: ";
        string phoneNumber;
        cin >> phoneNumber;
        //There entered PhoneNumber is Matched with the Phone number in the stored data  
        //Intially Number found is False if the Number is Matched and data is edited than Number found = True
        // if Still not found and remains false than NO data entered exists
        bool Numfound = false;
        for (int i = 0; i < 100; i++)
        {
            if (pNo[i] == phoneNumber)
            {
                cout << "Enter New Data" << endl;
                cout << "Enter Name of the Customer :";
                cin >> name[i];
                cout << "Enter Phone Number of the Customer :";
                cin >> pNo[i];
                cout << "Enter Email Address of the Customer :";
                cin >> email[i];
                cout << endl;

                Numfound = true;
                break;
            }
        }

        if (!Numfound)
        {
            cout << "No record found with the given phone number." << endl;
        }
    }
    
    void deletedata()
    {
        //Data Can be easily deleted through Phone Number 
        //But Just to change the logic and try Finding the Customer through name

        cout << "Enter the Name of the Customer to delete: ";
        string dN;
        cin >> dN;

        bool found = false;
        for (int i = 0; i < 100; i++)
        {
            if (name[i] == dN)
            {
                found = true;
                //After Name is Matched than
                //For Example on index 2 its found than 2+1 = 3 
                //Index is is Set to Null / No Value or Simply Empty
                for (int j = i; j < 99; j++)
                {
                    name[j] = name[j + 1];
                    pNo[j] = pNo[j + 1];
                    email[j] = email[j + 1];
                }
                name[99] = "";
                pNo[99] = "";
                email[99] = "";
                break;
            }
        }

        if (!found)
        {
            cout << "No record found with the given name." << endl;
        }

    }

    void saveDataToFile() {
        ofstream savfile("data.txt");
        //Opening the File Data.txt
        if (!savfile) {
            cout << "Error opening file for writing." << endl;
            return;
        }
        //concatinating Data onto the File
        for (int i = 0; i < 100; i++) {
            if (name[i].empty()) {
                break;
            }
            savfile << name[i] << endl;
            savfile << pNo[i] << endl;
            savfile << email[i] << endl;
        }
        //Closing the FIle
        savfile.close();
        cout << "Data saved to file successfully." << endl;
        cout << "===========================================" << endl;
    }

    void loadFile() {
        //If File already Exists so Load Data//Before CMS Options
        cout << "Loading Data if Exists in a File" << endl;
        ifstream getfiledata("data.txt");
        if (!getfiledata) {
            cout << "File not found. A new file will be created." << endl;
            return;
        }

        int i = 0;
        while (i < 100 && getfiledata >> name[i] >> pNo[i] >> email[i]) {
            i++;
        }

        getfiledata.close();
        cout << "Data loaded from file successfully." << endl;
        cout << endl;
        cout << "========================================================================================================================" << endl;
    }
};

int main() {
    CMS object;
    int option;
    object.loadFile();
    cout << endl;
    cout << "=======================================";
    cout << "Welcome to CMS (Contact Management System)";
    cout << "=======================================" << endl;
    cout << endl;
    while (true) {
        cout << "Please Select from the following Options:" << endl;
        cout << "Press [0] if you want to add Data of the Customer in Contact Management System" << endl;
        cout << "Press [1] if you want to Show Data of the Customer in Contact Management System" << endl;
        cout << "Press [2] if you want to Edit Data of the Customer in Contact Management System" << endl;
        cout << "Press [3] if you want to Delete Certain Data of the Customer in Contact Management System" << endl;
        cout << "Press [4] if you want to Save Data of the Customer onto a File" << endl;
        cout << "Press [5] if you want to Exit (Note: Make sure to save data on the File If you want to)" << endl;
        cout << "Please Enter Valid option :";
        cin >> option;
        cout << endl;

        switch (option)
        {
        case 0:
            object.adddata();
            cout << "Data Added Successfully" << endl;
            break;
        case 1:
            object.showdata();
            break;
        case 2:
            object.editData();
            break;
        case 3:
            object.deletedata();
            cout << "Data Deleted Successfully" << endl;
            break;
        case 4:
            object.saveDataToFile();
            break;
        case 5: {
            cout << "Are you sure you want to exit (yes/no): ";
            string exit;
            cin >> exit;
            if (exit == "yes") {
                return 0;
            }
            else if (exit == "no") {
                continue;
            }
            else {
                cout << "Invalid option, try again." << endl;
            }
            break;
        }
        default:
            cout << "Invalid input. Please try again." << endl;
        }
    }
}
