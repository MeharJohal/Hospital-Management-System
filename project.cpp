#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void login()
{
    char username[] = "hs_hospital";
    char password[] = "27072003";
    char uname[20], p[20];
    do
    {
        cout << "Please enter the username:\t";
        cin >> uname;
        fflush(stdin);
        cout << "Please enter the password:\t";
        cin >> p;
        fflush(stdin);
        if (strcmp(uname, username) || strcmp(p, password))
        {
            cout << "Invalid username or password\n";
        }
    } while (strcmp(uname, username) || strcmp(p, password));
    cout << "Login successful\n";
}

class patientCheckup
{
protected:
    char name[100];
    char sex;
    int age;
    char date[30];
    char doctor[100];
    int fees = 300;
    static int serialNo;
    friend void calculateEarnings(patientCheckup , int, int);

public:
    void setPrescription()
    {
        fflush(stdin);
        cout << "Please enter the following details:\n";
        cout << "Name of patient:\t";
        cin.getline(name, 99);
        fflush(stdin);
        cout << "Sex:\t";
        cin >> sex;
        fflush(stdin);
        cout << "Age:\t";
        cin >> age;
        fflush(stdin);
        cout << "Date:\t";
        cin.getline(date, 29);
        fflush(stdin);
        cout << "Consulting to:\t";
        cin.getline(doctor, 99);
        fflush(stdin);
    }
    virtual void display()
    {
        serialNo++;
        cout << "\n\n\n\n";
        cout.width(80);
        cout << "********MEHAR HOSPITAL********\n\n";
        cout << setw(90) << "Hoshiarpur Road, Ladhewali chowk, Ramamandi, Jalandhar\n\n";
        cout << setw(72) << "Punjab - 144005\n\n";
        cout << setw(85) << "Phone Number: 0181-775645, +918744536278\n\n";
        cout << "-------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout << setw(20) << "Serial number:\t" << serialNo;
        cout << setw(80) << "Name of patient:\t" << name << endl;
        cout << setw(20) << "Sex:\t" << sex;
        cout << setw(80) << "Age:\t" << age << endl;
        cout << setw(20) << "Date:\t" << date;
        cout << setw(70) << "Consulting to:\t" << doctor << endl;
        cout << setw(20) << "Fees:\t" << fees;
        cout << setw(78) << "BP/Pulse:\t" << endl
             << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
    void operator+=(int n)
    {
        fees += n;
    }
    static int getSerialNumber()
    {
        return serialNo;
    }
};

int patientCheckup ::serialNo = 0;

inline void calculateEarnings(patientCheckup p, int app=0, int emer=0)
{
    int earnings;
    int n;
    n = patientCheckup::getSerialNumber();
    earnings = n * p.fees + app * 100 + emer * 200;
    cout << "Earnings today till now:\t" << earnings << endl;
}
class Appointment : public patientCheckup
{
private:
    char time[30];

public:
    void bookAppointment()
    {
        setPrescription();
        fflush(stdin);
        cout << "Time:\t";
        cin.getline(time, 29);
        fflush(stdin);
    }
    void displayAppointment()
    {
        patientCheckup ::display();
    }
    void saveAppointment();
    void display();
};

void Appointment ::saveAppointment()
{
    bookAppointment();
    ofstream fout;
    fout.open("Appointments.txt", ios::app);
    fout.write((char *)this, sizeof(*this));
    fout.close();
}

void Appointment ::display()
{
    fflush(stdin);
    char n[100];
    cout << "Please enter the name of the patient:\t";
    cin.getline(n, 100);
    ifstream fin;
    ofstream fout;
    int counter = 0;
    fin.open("Appointments.txt", ios::in);
    if (!fin)
    {
        cout << "\nFile not found!!!\n";
    }
    else
    {
        fout.open("temp.txt", ios::out);
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            if (!strcmp(n, name))
            {
                counter++;
                (*this) += 100;
                displayAppointment();
            }
            if (strcmp(name, n))
            {
                fout.write((char *)this, sizeof(*this));
            }
            fin.read((char *)this, sizeof(*this));
        }
        if (counter == 0)
        {
            cout << "Sorry!! no appointment with this name\n";
        }
        fin.close();
        fout.close();
        remove("Appointments.txt");
        rename("temp.txt", "Appointments.txt");
    }
}

class Emergency :public patientCheckup{
    public:
    void display(){
        patientCheckup::display();
    }
};

class Hospital
{
protected:
    char name[100];
    char sex;
    int age;
    char DOB[20];
    char address[500];
    char phoneNo[15];
    char id[10];

public:
    Hospital() {}
    Hospital(char n[], char s, int a, char b[], char add[], char ph[], char i[]) : sex(s), age(a)
    {
        strcpy(name, n);
        strcpy(DOB, b);
        strcpy(address, add);
        strcpy(phoneNo, ph);
        strcpy(id, i);
    }
    void getDetails()
    {
        fflush(stdin);
        cout << "Please enter the following details\n";
        cout << "ID:\t";
        cin >> id;
        fflush(stdin);
        cout << "Name:\t";
        cin.getline(name, 100);
        fflush(stdin);
        cout << "Age:\t";
        cin >> age;
        fflush(stdin);
        cout << "Sex:\t";
        cin >> sex;
        fflush(stdin);
        cout << "DOB:\t";
        cin.getline(DOB, 20);
        fflush(stdin);
        cout << "Address:\t";
        cin.getline(address, 500);
        fflush(stdin);
        cout << "Phone number:\t";
        cin.getline(phoneNo, 15);
        fflush(stdin);
    }
    void displayDetails()
    {
        cout.setf(ios::left, ios::adjustfield);
        cout.width(20);
        cout << "ID:";
        cout << id << endl;
        cout.width(20);
        cout << "Name:";
        cout << name << endl;
        cout.width(20);
        cout << "Age:";
        cout << age << endl;
        cout.width(20);
        cout << "Sex:";
        cout << sex << endl;
        cout.width(20);
        cout << "DOB:";
        cout << DOB << endl;
        cout.width(20);
        cout << "Address:";
        cout << address << endl;
        cout.width(20);
        cout << "Phone Number:";
        cout << phoneNo << endl;
    }
};

class DoctorDetails : public Hospital
{
private:
    char qualification[300];
    char speciality[300];
    char procedureFocus[2000];

public:
    DoctorDetails() {}
    DoctorDetails(char n[], char s, int a, char b[], char add[], char ph[], char i[], char q[], char sp[], char p[]) : Hospital(n, s, a, b, add, ph, i)
    {
        strcpy(qualification, q);
        strcpy(speciality, sp);
        strcpy(procedureFocus, p);
    }
    void getSpecificDetails()
    {
        Hospital::getDetails();
        fflush(stdin);
        cout << "Procedure Focus:";
        cin.getline(procedureFocus, 2000);
        fflush(stdin);
        cout << "Qualification:";
        cin.getline(qualification, 300);
        fflush(stdin);
        cout << "Speciality:";
        cin.getline(speciality, 300);
        fflush(stdin);
    }
    void displaySpecificDetails()
    {
        Hospital::displayDetails();
        cout.width(20);
        cout << "Procedure Focus:" << procedureFocus << endl;
        cout.width(20);
        cout << "Qualification:" << qualification << endl;
        cout.width(20);
        cout << "Speciality:" << speciality << endl;
    }
};

class Doctor : private DoctorDetails
{
private:
    void getData()
    {
        getSpecificDetails();
    }
    void displayInfo()
    {
        displaySpecificDetails();
    }

public:
    Doctor() {}
    Doctor(char n[], char s, int a, char b[], char add[], char ph[], char i[], char q[], char sp[], char p[]) : DoctorDetails(n, s, a, b, add, ph, i, q, sp, p) {}
    void insertRecord();
    void deleteRecord();
    void searchRecord();
    void updateRecord();
    void viewAllRecords();
};

void Doctor ::insertRecord()
{
    getData();
    ofstream fout;
    fout.open("doctor.txt", ios::app);
    fout.write((char *)this, sizeof(*this));
    fout<<endl;
    fout.close();
    cout << "\nRecord inserted successfully\n\n";
}

void Doctor ::viewAllRecords()
{
    ifstream fin;
    fin.open("doctor.txt", ios::in);
    if (!fin)
    {
        cout << "\nFile not found\n";
    }
    else
    {
        fin.read((char *)this, ((sizeof(*this))+1));
        while (!(fin.eof()))
        {
            displayInfo();
            fin.read((char *)this, ((sizeof(*this))+1));
        }
        fin.close();
    }
}

void Doctor ::searchRecord()
{
    char i[10];
    fflush(stdin);
    cout << "Please enter the ID of the doctor:\t";
    cin >> i;
    fflush(stdin);

    ifstream ffin;
    int flag = 0;
    ffin.open("doctor.txt", ios::in);
    if (!ffin)
    {
        cout << "\nFile not found\n";
    }
    else
    {
        ffin.read((char *)this, sizeof(*this)+1);
        while (!ffin.eof())
        {
            if (!strcmp(i, id))
            {
                flag++;
                displayInfo();
            }
            ffin.read((char *)this, sizeof(*this)+1);
        }
        if (flag == 0)
        {
            cout << "\nRecord not found\n";
        }
        ffin.close();
    }
}

void Doctor ::deleteRecord()
{
    fflush(stdin);
    char i[10];
    cout << "Please enter the ID of the doctor:\t";
    cin.getline(i, 10);
    fflush(stdin);
    int flag =0;

    ifstream fin;
    ofstream fout;
    fin.open("doctor.txt", ios::in);
    if (!fin)
    {
        cout << "\nFile not found\n";
    }
    else
    {
        fout.open("tempfile.txt", ios::app);
        fin.read((char *)this, sizeof(*this)+1);
        while (!fin.eof())
        {
            if (!strcmp(i, id))
            {
                flag++;
            }
            if ((strcmp(i, id)))
            {
                fout.write((char *)this, sizeof(*this)+1);
            }
            fin.read((char *)this, sizeof(*this)+1);
        }
        if(flag){
            cout<<"\nRecord deleted successfully\n";
        }
        else{
            cout<<"\nNo record with this id\n";
        }
    }
    fin.close();
    fout.close();
    remove("doctor.txt");
    rename("tempfile.txt", "doctor.txt");
}

int main()
{
    int a, b;
    patientCheckup *patientPtr;
    patientCheckup patient;
    Emergency emer;
    Appointment app;
    login();
    int choice;
    Doctor d, e, f, g, h;
    while (1)
    {
        cout << "*****Options*****" << endl;
        cout << "'1' - Patient visiting a doctor\n";
        cout << "'2' - Taking an appointment\n";
        cout << "'3' - Inserting the record of a doctor\n";
        cout << "'4' - Deleting the record of a doctor\n";
        cout << "'5' - Searching the record of a doctor\n";
        cout << "'6' - Viewing the records of all the doctors\n";
        cout << "'7' - total earnings today\n";
        cout << "'8' - exit\n";
        cout << "Please enter your choice:\t";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int type;
            cout << "Please enter 0 for regular patient, 1 for a patient having an appointment and 2 for emergency:\t";
            cin >> type;
            if (type == 0)
            {
                patientPtr = &patient;
                patientPtr->setPrescription();
                patientPtr->display();
            }
            else if (type == 1)
            {
                patientPtr = &app;
                patientPtr->display();
            }
            else if (type == 2)
            {
                patientPtr = &emer;
                patientPtr->setPrescription();
                (*patientPtr)+=200;
                patientPtr->display();
            }
            else
            {
                cout << "\nInvalid choice....\n";
            }
            break;
        case 2:
            app.saveAppointment();
            break;
        case 3:
            d.insertRecord();
            break;
        case 4:
            e.deleteRecord();
            break;
        case 5:
            f.searchRecord();
            break;
        case 6:
            h.viewAllRecords();
            break;
        case 7:
            cout << "Please enter the number of patients with appointments:\t";
            cin >> a;
            cout << "Please enter the number of patients with emergency:\t";
            cin >> b;
            calculateEarnings(patient, a, b);
            break;
        case 8:
            cout << "\n*******Thank you!!!*******\n";
            exit(0);
        default:
            cout << "\nInvalid choice!!!\n";
        }
    }
    return 0;
}