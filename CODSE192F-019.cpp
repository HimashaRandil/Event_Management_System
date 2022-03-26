#include <iostream>
#include<string.h>
#include <conio.h>
#include <stdlib.h>
#include<fstream>
#include<windows.h>
#include <climits>
#include<iomanip>
#include<stdio.h>


using namespace std;

string Given_UserName,password;

int main_menu();
int employee_menu();
int event_menu();
int inventory_menu();
int package_menu();
int Billing();
void login_menu();


class Employee
{
protected:
    int employee_no, employee_phone_number;
    float employee_salary;
    string employee_name,employee_position,employee_department;

public:
    void Add_Employee();
    void Remove_Employee();
    void View_Employee();
    void Update_Employee();
};

class Event
{
protected:
    int event_no, host_phone_number;
    float event_payment;
    string host_name, event_package, event_type, event_date;

public:
    void View_Event();
    void Add_Event();
    void Completed_Event();
    void View_Event_History();
    void Update_Event();

};

class Inventory
{
private:
    int inv_id, in_stock;
    string description, supplier_name;
    float item_price;

public:
    void View_Inventory();
    void Add_Inventory();
    void Update_Inventory();
    float getPrice(int ,int);

} ;

class Package
{
protected:
    int add_on,quantity;
    float base_price, discount_rate, discount, total,add_on_price;
    float Registrarion_Price = 2500;
    Inventory Inv;

public:
    void View_Package();
    void Calculate_Package();
    void Show_Bill();

};

class Silver_Package : public Package
{
public:

	void Calculate_Package();

};

class Gold_Package : public Package
{
public:

	void Calculate_Package();

};

class Platinum_Package : public Package
{
public:

	void Calculate_Package();

};


void Employee::Add_Employee()
{
    system("CLS");
    char opt;
    opt ='y';
    fstream Add_Employee;
    Add_Employee.open("Employee Register.txt",ios::app);
    while(opt =='y')
    {
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"        Add Employee Record "<<endl;
    cout<<"------------------------------------\n"<<endl;
    cout<<"Insert Employee ID "<<endl;
    cin>>employee_no;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>employee_no;
    }
    cout<<"Insert Employee Name "<<endl;
    cin>>employee_name;
    cout<<"Insert Employee Phone Number "<<endl;
    cin>>employee_phone_number;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>employee_phone_number;
    }
    cout<<"Insert Employee Position "<<endl;
    cin>>employee_position;
    cout<<"Insert Employee Salary "<<endl;
    cin>>employee_salary;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>employee_salary;
    }
    cout<<"Insert Employee Department "<<endl;
    cin>>employee_department;
    Add_Employee<<setw(7)<<employee_no<<setw(15)<<employee_name<<setw(14)<<employee_phone_number<<setw(20)<<employee_position<<setw(12)<<employee_salary<<setw(15)<<employee_department<<endl;
    cout<<"\n"<<endl;
    system("pause");
    cout<<"\nDo You Want To Add Another Record ? (Yes - y / No - n)"<<endl;
    cin>>opt;
    };
    Add_Employee.close();
    cout<<"\n"<<endl;
    employee_menu();

}

void Employee::Remove_Employee()
{
    int id;
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"       Remove Employee Record "<<endl;
    cout<<"------------------------------------\n"<<endl;
    cout<<"Enter The Employee Id Of The Employee That You Want To Remove "<<endl;
    cin>>id;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>id;
    }
        fstream temp_file;
        fstream exisisting_file;
        exisisting_file.open("Employee Register.txt",ios::in);
        temp_file.open("Temp File.txt",ios::out);
        while(!exisisting_file.eof())
        {
            exisisting_file>>employee_no>>employee_name>>employee_phone_number>>employee_position>>employee_salary>>employee_department;
            if(id!=employee_no)
            {
                if(exisisting_file.eof())
                {
                    break;
                }
                temp_file<<setw(7)<<employee_no<<setw(15)<<employee_name<<setw(14)<<employee_phone_number<<setw(20)<<employee_position<<setw(12)<<employee_salary<<setw(15)<<employee_department<<endl;

            }
        }
        exisisting_file.close();
        temp_file.close();
        remove("Employee Register.txt");
        rename("Temp File.txt","Employee Register.txt");
        cout<<"\n"<<endl;
        system("pause");
        employee_menu();

}

void Employee::View_Employee()
{
    system("CLS");
    cout<<"---------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                  Employee Records "<<endl;
    cout<<"---------------------------------------------------------------------------------------------\n"<<endl;
    cout<<"ID        Employee Name       Phone Number      Position            Salary      Department  \n"<<endl;
    fstream View;
    View.open("Employee Register.txt",ios::in);
    while(View)
    {
        View>>employee_no>>employee_name>>employee_phone_number>>employee_position>>employee_salary>>employee_department;
        if(View.eof())
        {
            break;
        }
        cout<<left<<setw(10)<<setfill(' ')<<employee_no;
        cout<<left<<setw(20)<<setfill(' ')<<employee_name;
        cout<<left<<setw(18)<<setfill(' ')<<employee_phone_number;
        cout<<left<<setw(20)<<setfill(' ')<<employee_position;
        cout<<left<<setw(12)<<setfill(' ')<<employee_salary;
        cout<<left<<setw(15)<<setfill(' ')<<employee_department<<endl;
    }
    View.close();
    cout<<"\n"<<endl;
    system("pause");
    employee_menu();
}

void Employee::Update_Employee()
{
    int Id;
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"        Update Employee Record "<<endl;
    cout<<"------------------------------------\n"<<endl;
    cout<<"Enter the Employee ID which you want to update "<<endl;
    cin>>Id;
    fstream A;
    A.open("Employee Register.txt",ios::in|ios::out);
    while(!A.eof())
    {
         A>>employee_no>>employee_name>>employee_phone_number>>employee_position>>employee_salary>>employee_department;
         if(Id==employee_no)
            break;

    }
    cout<<"Insert Employee New ID "<<endl;
    cin>>employee_no;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>employee_no;
    }
    cout<<"Insert Employee New Name "<<endl;
    cin>>employee_name;
    cout<<"Insert Employee New Phone Number "<<endl;
    cin>>employee_phone_number;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>employee_phone_number;
    }
    cout<<"Insert Employee New Position "<<endl;
    cin>>employee_position;
    cout<<"Insert Employee New Salary "<<endl;
    cin>>employee_salary;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>employee_salary;
    }
    cout<<"Insert Employee New Department "<<endl;
    cin>>employee_department;
    A.seekp(A.tellg()-84,ios::beg);
    A<<setw(7)<<employee_no<<setw(15)<<employee_name<<setw(14)<<employee_phone_number<<setw(20)<<employee_position<<setw(12)<<employee_salary<<setw(15)<<employee_department<<endl;
    A.close();
    cout<<"\n"<<endl;
    system("pause");
    employee_menu();
}


void Event::View_Event()
{
    system("CLS");
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                               Event Time Line "<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------\n"<<endl;
    cout<<"ID        Event Date       Event Host's Name      Contact Number         Event Type      Event Package      Payment  \n"<<endl;
    fstream EView;
    EView.open("Event Register.txt",ios::in);
    while(EView)
    {
        EView>>event_no>>event_date>>host_name>>host_phone_number>>event_type>>event_package>>event_payment;
        if(EView.eof())
        {
            break;
        }
        cout<<left<<setw(10)<<setfill(' ')<<event_no;
        cout<<left<<setw(19)<<setfill(' ')<<event_date;
        cout<<left<<setw(22)<<setfill(' ')<<host_name;
        cout<<left<<setw(23)<<setfill(' ')<<host_phone_number;
        cout<<left<<setw(17)<<setfill(' ')<<event_type;
        cout<<left<<setw(17)<<setfill(' ')<<event_package;
        cout<<left<<setw(10)<<setfill(' ')<<event_payment<<endl;
    }
    EView.close();
    cout<<"\n"<<endl;
    system("pause");
    event_menu();
}

void Event::Add_Event()
{
    fstream Add_Event;
    Add_Event.open("Event Register.txt",ios::app);
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"           Add An Event "<<endl;
    cout<<"------------------------------------\n"<<endl;
    cout<<"Insert Event ID "<<endl;
    cin>>event_no;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>event_no;
    }
    cout<<"Insert Event Date "<<endl;
    cin>>event_date;
    cout<<"Insert Event Host's Name "<<endl;
    cin>>host_name;
    cout<<"Insert Host's Contact Number  "<<endl;
    cin>>host_phone_number;
    while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>host_phone_number;
    }
    cout<<"Insert Event Type "<<endl;
    cin>>event_type;
    cout<<"Insert Event Package "<<endl;
    cin>>event_package;
    cout<<"Insert Event Payment Amount "<<endl;
    cin>>event_payment;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>event_payment;
    }
    Add_Event<<setw(7)<<event_no<<setw(13)<<event_date<<setw(15)<<host_name<<setw(13)<<host_phone_number<<setw(15)<<event_type<<setw(10)<<event_package<<setw(10)<<event_payment<<endl;
    cout<<"\n"<<endl;
    system("pause");

    Add_Event.close();
    cout<<"\n"<<endl;
    event_menu();
}

void Event::Completed_Event()
{
    int id;
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"       Completed Event Record "<<endl;
    cout<<"------------------------------------\n"<<endl;
    cout<<"Enter The Completed Event's ID "<<endl;
    cin>>id;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>id;
    }
        fstream temp_Efile;
        fstream exisisting_Efile;
        fstream event_log_file;
        fstream income_file;
        exisisting_Efile.open("Event Register.txt",ios::in);
        temp_Efile.open("Temp File.txt",ios::out);
        event_log_file.open("Event History Register.txt",ios::app);
        income_file.open("Income.txt",ios::out|ios::in);
        while(!exisisting_Efile.eof())
        {
            exisisting_Efile>>event_no>>event_date>>host_name>>host_phone_number>>event_type>>event_package>>event_payment;
            if(id!=event_no)
            {
                if(exisisting_Efile.eof())
                {
                    break;
                }
                temp_Efile<<setw(7)<<event_no<<setw(13)<<event_date<<setw(15)<<host_name<<setw(13)<<host_phone_number<<setw(15)<<event_type<<setw(10)<<event_package<<setw(10)<<event_payment<<endl;

            }
            else if(id==event_no)
            {
                if(exisisting_Efile.eof())
                {
                    break;
                }
                event_log_file<<setw(7)<<event_no<<setw(13)<<event_date<<setw(15)<<host_name<<setw(13)<<host_phone_number<<setw(15)<<event_type<<setw(10)<<event_package<<setw(10)<<event_payment<<endl;
                float payment = event_payment;

            }
        }
        exisisting_Efile.close();
        temp_Efile.close();
        event_log_file.close();
        remove("Event Register.txt");
        rename("Temp File.txt","Event Register.txt");
        cout<<"\n"<<endl;
        system("pause");
        event_menu();

}

void Event::View_Event_History()
{
    float total = 0;
    system("CLS");
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                               Event Record History  "<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------\n"<<endl;
    cout<<"ID        Event Date       Event Host's Name      Contact Number         Event Type      Event Package      Payment  \n"<<endl;
    fstream EHView;
    EHView.open("Event History Register.txt",ios::in);
    while(EHView)
    {
        EHView>>event_no>>event_date>>host_name>>host_phone_number>>event_type>>event_package>>event_payment;
        if(EHView.eof())
        {
            break;
        }
        cout<<left<<setw(10)<<setfill(' ')<<event_no;
        cout<<left<<setw(19)<<setfill(' ')<<event_date;
        cout<<left<<setw(22)<<setfill(' ')<<host_name;
        cout<<left<<setw(23)<<setfill(' ')<<host_phone_number;
        cout<<left<<setw(17)<<setfill(' ')<<event_type;
        cout<<left<<setw(17)<<setfill(' ')<<event_package;
        cout<<left<<setw(10)<<setfill(' ')<<event_payment<<endl;
        total = total + event_payment;
    }
    EHView.close();
    cout<<"\n"<<endl;
    system("pause");
    cout<<"\n**************************************************\n"<<endl;
    cout<<"Your Total Income : Rs."<<total<<endl;
    cout<<"\n**************************************************\n"<<endl;
    system("pause");
    event_menu();
}

void Event::Update_Event()
{
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"        Update Event Record "<<endl;
    cout<<"------------------------------------\n"<<endl;
    int Id;
    cout<<"Enter the Event ID which you want to update \n";
    cin>>Id;
    fstream B;
    B.open("Event Register.txt",ios::in|ios::out);
    while(!B.eof())
    {
         B>>event_no>>event_date>>host_name>>host_phone_number>>event_type>>event_package>>event_payment;
         if(Id==event_no)
            break;

    }
    cout<<"Insert Event New ID "<<endl;
    cin>>event_no;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>event_no;
    }
    cout<<"Insert Event New Date "<<endl;
    cin>>event_date;
    cout<<"Insert Event New Host's Name "<<endl;
    cin>>host_name;
    cout<<"Insert Host's New Contact Number  "<<endl;
    cin>>host_phone_number;
    while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>host_phone_number;
    }
    cout<<"Insert New Event Type "<<endl;
    cin>>event_type;
    cout<<"Insert New Event Package "<<endl;
    cin>>event_package;
    cout<<"Insert Event New Payment Amount "<<endl;
    cin>>event_payment;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>event_payment;
    }
    B.seekp(B.tellg()-83,ios::beg);
    B<<setw(7)<<event_no<<setw(13)<<event_date<<setw(15)<<host_name<<setw(13)<<host_phone_number<<setw(15)<<event_type<<setw(10)<<event_package<<setw(10)<<event_payment<<endl;
    B.close();
    cout<<"\n"<<endl;
    system("pause");
    event_menu();
}


void Inventory::View_Inventory()
{
    system("CLS");
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"                                        Inventory  "<<endl;
    cout<<"--------------------------------------------------------------------------------------\n"<<endl;
    cout<<"ID        Description       Stock In Hand      Item Price         Supplier Name   \n"<<endl;
    fstream IView;
    IView.open("Inventory.txt",ios::in);
    while(IView)
    {
        IView>>inv_id>>description>>in_stock>>item_price>>supplier_name;
        if(IView.eof())
        {
            break;
        }
        cout<<left<<setw(12)<<setfill(' ')<<inv_id;
        cout<<left<<setw(20)<<setfill(' ')<<description;
        cout<<left<<setw(18)<<setfill(' ')<<in_stock;
        cout<<left<<setw(17)<<setfill(' ')<<item_price;
        cout<<left<<setw(17)<<setfill(' ')<<supplier_name<<endl;
    }
    IView.close();
    cout<<"\n"<<endl;
    system("pause");

}

void Inventory::Add_Inventory()
{
    fstream Add_Inven;
    Add_Inven.open("Inventory.txt",ios::app);
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"           Add Inventory "<<endl;
    cout<<"------------------------------------\n"<<endl;
    cout<<"Insert Inventory ID "<<endl;
    cin>>inv_id;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>inv_id;
    }
    cout<<"Insert Inventory Description  "<<endl;
    cin>>description;
    cout<<"Insert Stock In Hand "<<endl;
    cin>>in_stock;
    while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>in_stock;
    }
    cout<<"Insert Item Price  "<<endl;
    cin>>item_price;
    while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>item_price;
    }
    cout<<"Insert Supplier Name "<<endl;
    cin>>supplier_name;

    Add_Inven<<setw(7)<<inv_id<<setw(20)<<description<<setw(10)<<in_stock<<setw(15)<<item_price<<setw(20)<<supplier_name<<endl;
    cout<<"\n"<<endl;
    system("pause");

    Add_Inven.close();
    cout<<"\n"<<endl;
    inventory_menu();
}

void Inventory::Update_Inventory()
{

    int Id;
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"        Update Event Record "<<endl;
    cout<<"------------------------------------\n"<<endl;
    cout<<"Enter the Inventory ID which you want to update \n";
    cin>>Id;
    fstream C;
    C.open("Inventory.txt",ios::in|ios::out);
    while(!C.eof())
    {
         C>>inv_id>>description>>in_stock>>item_price>>supplier_name;
         if(Id==inv_id)
            break;

    }
    cout<<"Insert Inventory New ID "<<endl;
    cin>>inv_id;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>inv_id;
    }
    cout<<"Insert Inventory New Description  "<<endl;
    cin>>description;
    cout<<"Insert New Stock In Hand "<<endl;
    cin>>in_stock;
    while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>in_stock;
    }
    cout<<"Insert Item New Price  "<<endl;
    cin>>item_price;
    while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>item_price;
    }
    cout<<"Insert New Supplier Name "<<endl;
    cin>>supplier_name;
    C.seekp(C.tellg()-72,ios::beg);
    C<<setw(7)<<inv_id<<setw(20)<<description<<setw(10)<<in_stock<<setw(15)<<item_price<<setw(20)<<supplier_name<<endl;
    C.close();
    cout<<"\n"<<endl;
    system("pause");
    inventory_menu();
}

float Inventory::getPrice(int no,int q)
{
    fstream inv;
    inv.open("Inventory.txt",ios::in);
    while(inv)
    {
        inv>>inv_id>>description>>in_stock>>item_price>>supplier_name;
        if(inv.eof())
        {
            break;
        }
        if(no == inv_id)
        {
            return item_price;
        }

    }
    inv.close();
    return 0;
}


void Package::View_Package()
{
    system("CLS");
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                               FROST OTTER PACKAGES  "<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------\n\n\n"<<endl;
    cout<<"-----------------------------\t\t-----------------------------\t\t-----------------------------"<<endl;
    cout<<"         Silver Plan         \t\t         Gold Package        \t\t        Platinum Package     "<<endl;
    cout<<"-----------------------------\t\t-----------------------------\t\t-----------------------------\n"<<endl;
    cout<<"      Special Service        \t\t         VIP Service         \t\t         VVIP Service        "<<endl;
    cout<<"     Discounts Up to 10%     \t\t     Discounts Up to 15%     \t\t        Discounts Up to 20% "<<endl;
    cout<<"        Online Gallery       \t\t        Online Gallery       \t\t          Online Gallery    "<<endl;
    cout<<"        No albums            \t\t      1 Parental Album       \t\t        2 Parental Albums "<<endl;
    cout<<"    Excluding Photography    \t\t    Excluding Photography    \t\t      Including Photography  "<<endl;
    cout<<"     6 Hours Coverage        \t\t         8 Hours Coverage    \t\t       12 Hours Coverage         "<<endl;
    cout<<"   Package Price LKR 10,000  \t\t   Package Price LKR 25,000  \t\t     Package Price LKR 50,000 "<<endl;
    cout<<"\n-----------------------------\t\t-----------------------------\t\t-----------------------------\n\n"<<endl;
    system("pause");



}

void Package::Show_Bill()
{
    system("CLS");
    cout<<"                           BILL INVOICE       "<<endl;
    cout<<"============================================================"<<endl;
    cout<<" The Registration Price Of Your Bill     : LKR "<<Registrarion_Price<<endl;
    cout<<" The Base Price Of Your Bill             : LKR "<<base_price<<endl;
    cout<<" The Add-On Prices Of Your Bill          : LKR "<<add_on_price<<endl;
    cout<<" The Discount Rate For Your Bill         : "<<discount_rate<<endl;
    cout<<" The Final Discount For Your Bill        : LKR "<<discount<<endl;
    cout<<"\n-------------------------------------------------------------"<<endl;
    cout<<" The Total Bill Amount                   : LKR "<<total<<endl;
    cout<<"\n============================================================\n"<<endl;
    system("pause");
}

void Silver_Package::Calculate_Package()
{
    char opt ='y';
    add_on_price=0;
    total = 0;
    discount=0;
    base_price = 10000;
	discount_rate = 0.10;
	Inv.View_Inventory();
	while(opt =='y')
        {
        cout<<"\nEnter add-on ID "<<endl;
        cin>>add_on;
        cout<<"Enter Quantity"<<endl;
        cin>>quantity;
        add_on_price = add_on_price + (Inv.getPrice(add_on,quantity)*quantity);
        cout<<"\n"<<endl;
        system("Pause");
        //system("CLS");
        cout<<"\nDo You Want To Add Another Add-On ? (Yes - y / No - n)"<<endl;
        cin>>opt;
        }
	total = Registrarion_Price + base_price + (add_on_price);
	discount = total*discount_rate;
	total = total - discount;
	Show_Bill();
}

void Gold_Package::Calculate_Package()
{
    char opt ='y';
    add_on_price=0;
    total = 0;
    discount=0;
    base_price = 25000;
	discount_rate = 0.15;
	Inv.View_Inventory();
	while(opt =='y')
        {
        cout<<"\nEnter add-on ID "<<endl;
        cin>>add_on;
        cout<<"Enter Quantity"<<endl;
        cin>>quantity;
        add_on_price = add_on_price + (Inv.getPrice(add_on,quantity)*quantity);
        cout<<"\n"<<endl;
        system("Pause");
        //system("CLS");
        cout<<"\nDo You Want To Add Another Add-On ? (Yes - y / No - n)"<<endl;
        cin>>opt;
        }
	total = Registrarion_Price + base_price + (add_on_price);
	discount = total*discount_rate;
	total = total - discount;
	Show_Bill();
}

void Platinum_Package::Calculate_Package()
{
    char opt ='y';
    add_on_price=0;
    total = 0;
    discount=0;
    base_price = 50000;
	discount_rate = 0.20;
	Inv.View_Inventory();
	while(opt =='y')
        {
        cout<<"\nEnter add-on ID "<<endl;
        cin>>add_on;
        cout<<"Enter Quantity"<<endl;
        cin>>quantity;
        add_on_price = add_on_price + (Inv.getPrice(add_on,quantity)*quantity);
        cout<<"\n"<<endl;
        system("Pause");
        //system("CLS");
        cout<<"\nDo You Want To Add Another Add-On ? (Yes - y / No - n)"<<endl;
        cin>>opt;
        }
	total = Registrarion_Price + base_price + (add_on_price);
	discount = total*discount_rate;
	total = total - discount;
	Show_Bill();
}


int employee_menu()
{
    int opt;
    Employee E;
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"          EMPLOYEE MENU  "<<endl;
    cout<<"------------------------------------\n"<<endl;
    cout<<"[1]  Add Employee "<<endl;
    cout<<"[2]  Remove Employee"<<endl;
    cout<<"[3]  View All Employees"<<endl;
    cout<<"[4]  Update Employee  "<<endl;
    cout<<"[5]  Go Back To Main Menu "<<endl;
    cout<<"\n\n Insert Your Selection"<<endl;
    cin>>opt;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>opt;
    }
    switch(opt)
    {
    case 1:
        E.Add_Employee();
        break;
    case 2:
        E.Remove_Employee();
        break;
    case 3:
        E.View_Employee();
        break;
    case 4:
        E.Update_Employee();
        break;
    case 5:
        main_menu();
        break;
    default:
        cout<<"\nInvalid Input "<<endl;
        cout<<"Please Try Again "<<endl;
        system("pause");
        employee_menu();
        break;

    }

}

int event_menu()
{
    int opt;
    Event x;
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"          EVENT MENU  "<<endl;
    cout<<"------------------------------------\n"<<endl;
    cout<<"[1]  View Event Time Line "<<endl;
    cout<<"[2]  Add Event"<<endl;
    cout<<"[3]  Completed Event"<<endl;
    cout<<"[4]  View Event History"<<endl;
    cout<<"[5]  Update Event "<<endl;
    cout<<"[6]  Go Back To Main Menu"<<endl;
    cout<<"\n\n Insert Your Selection"<<endl;
    cin>>opt;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>opt;
    }
    switch(opt)
    {
    case 1:
        x.View_Event();
        break;
    case 2:
        x.Add_Event();
        break;
    case 3:
        x.Completed_Event();
        break;
    case 4:
        x.View_Event_History();
        break;
    case 5:
        x.Update_Event();
        break;
    case 6:
        main_menu();
    default:
        cout<<"\nInvalid Input "<<endl;
        cout<<"Please Try Again "<<endl;
        system("pause");
        event_menu();
        break;

    }
    return 0;

}

int inventory_menu()
{
    int opt;
    Inventory I;
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"          INVENTORY MENU  "<<endl;
    cout<<"------------------------------------\n"<<endl;
    cout<<"[1]  View Inventory "<<endl;
    cout<<"[2]  Add Inventory"<<endl;
    cout<<"[3]  Update Inventory"<<endl;
    cout<<"[4]  Go Back To Main Menu "<<endl;
    cout<<"\n\n Insert Your Selection"<<endl;
    cin>>opt;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>opt;
    }
    switch(opt)
    {
    case 1:
        I.View_Inventory();
        inventory_menu();
        break;
    case 2:
        I.Add_Inventory();
        break;
    case 3:
        I.Update_Inventory();
        break;
    case 4:
        main_menu();
    default:
        cout<<"\nInvalid Input "<<endl;
        cout<<"Please Try Again "<<endl;
        system("pause");
        inventory_menu();
        break;
    }
    return 0;
}

int package_menu()
{
    int opt;
    Package P;
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"          PACKAGE MENU  "<<endl;
    cout<<"------------------------------------\n"<<endl;
    cout<<"[1]  View Packages "<<endl;
    cout<<"[2]  Go Back To Main Menu"<<endl;
    cout<<"\n\n Insert Your Selection"<<endl;
    cin>>opt;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>opt;
    }
    switch(opt)
    {
    case 1:
        P.View_Package();
        package_menu();
        break;
    case 2:
        main_menu();
        break;
    default:
        cout<<"\nInvalid Input "<<endl;
        cout<<"Please Try Again "<<endl;
        system("pause");
        package_menu();
        break;
    }
    return 0;
}

int Billing()
{
    Package pk;
    Silver_Package SP;
    Gold_Package GP;
    Platinum_Package PP;
    int opt;
    float total = 0;
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"           BILLING MENU  "<<endl;
    cout<<"------------------------------------\n"<<endl;
    cout<<"Select Your Preferred Package  \n"<<endl;
    system("pause");
    pk.View_Package();
    cout<<"\n\n[1]  Silver Package  "<<endl;
    cout<<"[2]  Gold Package "<<endl;
    cout<<"[3]  Platinum Package"<<endl;
    cout<<"[4]  Exit "<<endl;
    cout<<"\n\n Insert Your Selection"<<endl;
    cin>>opt;
    switch(opt)
    {
    case 1:
        SP.Calculate_Package();
        Billing();
        break;
    case 2:
        GP.Calculate_Package();
        Billing();
        break;
    case 3:
        PP.Calculate_Package();
        Billing();
        break;
    case 4:
        main_menu();
        break;
    default:
        cout<<"\nInvalid Input "<<endl;
        cout<<"Please Try Again \n"<<endl;
        system("pause");
        Billing();
        break;
    }

}

int main_menu()
{
    int opt;
    system("CLS");
    cout<<"------------------------------------"<<endl;
    cout<<"           MAIN MENU  "<<endl;
    cout<<"------------------------------------\n"<<endl;
    cout<<"[1]  Employee Management "<<endl;
    cout<<"[2]  Event Management"<<endl;
    cout<<"[3]  Inventory Management"<<endl;
    cout<<"[4]  Package Management  "<<endl;
    cout<<"[5]  Billing "<<endl;
    cout<<"[6]  Log Out "<<endl;
    cout<<"\n\n Insert Your Selection"<<endl;
    cin>>opt;
    while (cin.fail())//Data Validation
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>opt;
    }
    switch(opt)
    {
    case 1:
        employee_menu();
        break;
    case 2:
        event_menu();
        break;
    case 3:
        inventory_menu();
        break;
    case 4:
        package_menu();
        break;
    case 5:
        Billing();
        break;
    case 6:
        login_menu();
        break;

    default:
        cout<<"\nInvalid Input "<<endl;
        cout<<"Please Try Again \n"<<endl;
        system("pause");
        main_menu();
        break;
    }
}

void login()
{

    int i;
    system("CLS");
    cout<<"Enter Your User Name : "<<endl;
    cin>>Given_UserName;
    ifstream readfile;
    string file = Given_UserName+".txt";
    readfile.open(file.c_str());
    if(!readfile)
    {
        cout<<"Invalid User Name! \nPlease Try Again "<<endl;
        system("pause");
        login();
    }
    else
    {
        START:
    //system("cls");
    cout<<"\nEnter Password  : \n";
    char pass[32];//to store password.
    int i = 0;
    char a;//a Temp char
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    //here we can even check for minimum digits needed
    if(i<=5)
    {
        cout<<"\nMinimum 6 digits needed.\nEnter Again";
        getch();//It was not pausing :p
        goto START;
    }

        while(readfile)
        {
            readfile>>password;
            if(readfile.eof())
            {
                break;
            }
        }
        for(int c=0;c<password.length();c++)
        {
               // GP[c]=GP[c]+100;
               pass[c] = pass[c]+100;
        }
        system("cls");

        if (string(pass)==password)
        {
            cout<<"You Have Successfully  Logged In\n"<<endl;
            system("Pause");
            main_menu();
        }
        else
        {
            cout<<"Invalid Password \nPlease Try Again \n"<<endl;
          //  cout<<pass<<endl;
          //  cout<<password<<endl;
            system("pause");
            login();
        }

    }
    readfile.close();

}

void login_menu()
{
     int choice;
     system("CLS");
     cout<<"------------------------------------"<<endl;
     cout<<"             FROST OTTER"<<endl;
     cout<<"------------------------------------\n"<<endl;
     cout<<"\n[1]  Sign in"<<endl;
     cout<<"[2]  Exit\n"<<endl;
     cout<<"Enter Your Selection "<<endl;


     cin >> choice;
     while (cin.fail())//Data Validation
     {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "\nYou can only enter numbers.\n";//Error Msg
        cout << "Enter a number.\n";
        cin >>choice;
     }
        {
        switch(choice)
        {
            case 1:
                login();
                break;

            case 2:
                exit(0);
                break;

            default:
                cout<<"\nInvalid Input "<<endl;
                cout<<"Please Try Again \n"<<endl;
                system("pause");
                login_menu();

        }
        }
}

int main()
{
    login_menu();
    return 0;
}
