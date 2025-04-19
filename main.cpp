/****************************************************************
                         PROJECT
*****************************************************************
             CUSTOMER SERVICE MANAGEMENT SYSTEM
****************************************************************/

/****************************************************************
                    HEADER FILE
****************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// CLASS -
class customer_management
{
private:
    char choice;
    string customer_name, customer_mobile_no, customer_password;
    string customer_name2, customer_mobile_no2, customer_password2;
    string service_work, service_mobile_no, service_id, service_fees;
    string password;
    string match, match2;
    int x = 0, y = 0;
    char c;

public:
    fstream file;
    fstream file2;
    fstream file3;

    void register_customer();
    void customer_login();
    void see_all_customer();
    void search_customer();
    void delete_customer();
    void update_customer();
    void customer_amount();
    void employee_login();
    void add_service();
    void search_service();
    void update_service();
    void delete_service();
    void view_all_service();
    void total_amount();
} cm;
/**************************************************************
                   MAIN FUNCTION
***************************************************************/
int main()
{
    char choice;
    do
    {
        cout << "*********************************************\n";
        cout << "     CUSTOMER SERVICE MANAGEMENT SYSTEM   \n";
        cout << "*********************************************\n";
        cout << "--------------------------------\n";
        cout << "            WELCOME             \n";
        cout << "--------------------------------\n";
        cout << "1. Register customer\n";
        cout << "2. Customer Login\n";
        cout << "3. Search customer\n";
        cout << "4. See all customer\n";
        cout << "5. Update customer profile\n";
        cout << "6. Delete customer profile\n";
        cout << "7. Employee Login \n";
        cout << "8. Exit\n";

        cout << "Enter your choice : ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case '1':
            cm.register_customer();
            break;
        case '2':
            cm.customer_login();
            break;
        case '3':
            cm.search_customer();
            break;
        case '4':
            cm.see_all_customer();
            break;
        case '5':
            cm.update_customer();
            break;
        case '6':
            cm.delete_customer();
            break;
        case '7':
            cm.employee_login();
            break;
        case '8':
            break;
        default:
            cout << "! Wrong choice number ! \n\n";
        }
    } while (choice != '8');

    if (choice == '8')
    {
        cout << " !! Thank you !! \n\n";
    }
    return 0;
}
/**************************************************************
        CLASS - customer_management
                 all member implement
 **************************************************************/
void customer_management::register_customer()
{
    file.open("customer.txt", ios::out | ios::app);
    cout << "Enter coustomer name : ";
    cin >> customer_name;
    cout << "Enter mobile number : ";
    cin >> customer_mobile_no;
    cout << "Enter password : ";
    cin >> customer_password;

    file << customer_name << "*" << customer_mobile_no << "*" << customer_password << '\n';
    file.close();

    cout << "Successfully register customer.\n";
}
void customer_management::search_customer()
{
    file.open("customer.txt", ios::in | ios::app);
    cout << "Enter customer name : ";
    cin >> match;
    x = 0;
    while (getline(file, customer_name, '*') &&
           getline(file, customer_mobile_no, '*') &&
           getline(file, customer_password, '\n'))
    {

        if (customer_name == match)
        {
            cout << "Customer name : " << customer_name << "\nMobile number : " << customer_mobile_no << endl;
            x++;
            break;
        }
    }
    if (x == 0)
    {
        cout << "This name customer not found.\n";
    }
    file.close();
}
void customer_management::see_all_customer()
{
    file.open("customer.txt", ios::in | ios::app);
    cout << "S.No.  ";
    cout << "Customer    ";
    cout << "Mobile number\n";
    x = 0;
    while (getline(file, customer_name, '*') &&
           getline(file, customer_mobile_no, '*') &&
           getline(file, customer_password, '\n'))
    {
        cout << ++x << " . " << customer_name << "   " << customer_mobile_no << endl;
    }
    cout << endl;
    file.close();
}
void customer_management::update_customer()
{
    file.open("customer.txt", ios::in | ios::app);
    file2.open("temp.txt", ios::out | ios::app);
    cout << "Customer name :  ";
    cin >> match;
    cout << "Enter password : ";
    cin >> match2;
    x = 0;
    while (getline(file, customer_name, '*') &&
           getline(file, customer_mobile_no, '*') &&
           getline(file, customer_password, '\n'))
    {
        if ((customer_name != match) || (customer_password != match2))
        {
            file2 << customer_name << "*" << customer_mobile_no << "*" << customer_password << '\n';
        }
        else if ((customer_name == match) && (customer_password == match2))
        {
            cout << "Enter new customer name : ";
            cin >> customer_name;
            cout << "Enter mobile number : ";
            cin >> customer_mobile_no;
            cout << "Enter new password : ";
            cin >> customer_password;
            file2 << customer_name << "*" << customer_mobile_no << "*" << customer_password << '\n';
            x++;
        }
    }

    if (x > 0)
        cout << "customer name - " << match << " is updated.\n\n";

    else
        cout << "Customer name and password is not match.\n\n";

    file.close();
    file2.close();
    remove("customer.txt");
    rename("temp.txt", "customer.txt");
}
void customer_management::delete_customer()
{

    file.open("customer.txt", ios::in | ios::app);
    file2.open("temp.txt", ios::out | ios::app);
    cout << "Customer name :  ";
    cin >> match;
    cout << "Enter password : ";
    cin >> match2;
    x = 0;
    while (getline(file, customer_name, '*') &&
           getline(file, customer_mobile_no, '*') &&
           getline(file, customer_password, '\n'))
    {
        if (customer_name != match || customer_password != match2)
            file2 << customer_name << "*" << customer_mobile_no << "*" << customer_password << '\n';
        else
            x++;
    }

    if (x == 0)
        cout << "Customer name and password is not match.\n\n";

    else
        cout << "customer name - " << match << " is deleted.\n\n";

    file.close();
    file2.close();
    remove("customer.txt");
    rename("temp.txt", "customer.txt");
}

void customer_management::customer_login()
{
    search_customer();
    if (x > 0)
    {
        cout << "Enter password : ";
        cin >> password;
        if (customer_password == password)
        {
            do
            {
                cout << "----------------------\n";
                cout << "   WELCOME CUSTOMER\n";
                cout << "----------------------\n";
                cout << "1. Book a service \n";
                cout << "2. See all service\n";
                cout << "3. Previous book service\n";
                cout << "4. Back to home\n\n";
                cout << "Enter your choice : ";
                cin >> choice;
                cout << endl;

                switch (choice)
                {
                case '1':
                    x = 0;
                    file3.open("customer_data.txt", ios::out | ios::app);
                    search_service();
                    if (x > 0)
                    {
                        cout << "book the service : \nEnter  : y\\n -  ";
                        cin >> c;

                        if (c == 'y' || c == 'Y')
                        {
                            file3 << customer_name << "*" << customer_mobile_no << "*" << customer_password << "\n"
                                  << service_id << "*" << service_work << "*" << service_mobile_no << "*" << service_fees << "\n";

                            cout << "Sucessfully booked the service.\n\n";
                        }
                        file3.close();
                    }
                    break;
                case '2':
                    view_all_service();
                    break;
                case '3':
                    customer_amount();
                    break;
                case '4':
                    break;
                default:
                    cout << "! Wrong choice number ! \n\n";
                }
            } while (choice != '4');
        }
        else
        {
            cout << "Incorrect password.\nPlease try again\n\n";
        }
    }
}

void customer_management::customer_amount()
{
    file3.open("customer_data.txt", ios::in | ios::app);
    int amount = 0;
    int value;
    x = 0;
    match = customer_name;
    cout << "----------------------------------\n";
    while (
        getline(file3, customer_name2, '*') && getline(file3, customer_mobile_no2, '*') &&
        getline(file3, customer_password2, '\n') &&
        getline(file3, service_id, '*') && getline(file3, service_work, '*') &&
        getline(file3, service_mobile_no, '*') && getline(file3, service_fees, '\n'))
    {
        if (match == customer_name2)
        {
            cout << ++x << ". " << customer_name2 << "  " << customer_mobile_no2 << "\n";
            cout << service_id << "  " << service_work << "  " << service_mobile_no << "  " << service_fees << "\n";
            cout << "----------------------------------\n";
            value = stoi(service_fees);
            amount = amount + value;
        }
    }
    cout << "----------------------------------\n";
    cout << "Total amount is      " << amount << endl;
    cout << "----------------------------------\n\n";
    file3.close();
}

void customer_management::employee_login()
{
    cout << "Enter your password : ";
    cin >> password;

    if (password == "login")
    {
        cout << "----------------------\n";
        cout << "   WELCOME EMPLOYEE\n";
        cout << "----------------------\n";
        do
        {
            cout << "1. Add service\n";
            cout << "2. Search service\n";
            cout << "3. See all service\n";
            cout << "4. Upadate service\n";
            cout << "5. Delete service\n";
            cout << "6. Total earn\n";
            cout << "7. Back to home\n\n";
            cout << "Enter your choice : ";
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case '1':
                add_service();
                break;
            case '2':
                search_service();
                break;
            case '3':
                view_all_service();
                break;
            case '4':
                update_service();
                break;
            case '5':
                delete_service();
                break;
            case '6':
                total_amount();
                break;
            case '7':
                break;

            default:
                cout << "! Wrong choice number ! \n\n";
            }
        } while (choice != '7');
    }
    else
    {
        cout << "Wrong password pleasse try again\n";
    }
}

void customer_management::add_service()
{
    file.open("service.txt", ios::out | ios::app);
    cout << "Enter service id : ";
    cin >> service_id;
    cout << "Enter service name : ";
    cin >> service_work;
    cout << "Enter mobile number : ";
    cin >> service_mobile_no;
    cout << "Enter fees of provide service : ";
    cin >> service_fees;

    file << service_id << "*"
         << service_work << "*" << service_mobile_no << "*" << service_fees << "\n";
    file.close();
    cout << "\nAdd new service successfully.\n\n";
}
void customer_management::search_service()
{
    file.open("service.txt", ios::in | ios::app);
    cout << "Enter service id : ";
    cin >> match;
    while (!file.eof())
    {
        getline(file, service_id, '*');
        getline(file, service_work, '*');
        getline(file, service_mobile_no, '*');
        getline(file, service_fees, '\n');

        if (service_id == match)
        {
            cout << "ID  details.\n";
            cout << "ID     ";
            cout << "Service work    ";
            cout << "Mobile number    ";
            cout << "Service fees\n";
            cout << service_id << "  " << service_work << "   " << service_mobile_no << "  " << service_fees << endl
                 << endl;
            x++;
            break;
        }
    }
    if (x == 0)
        cout << "This service ID is not found.\n\n";

    file.close();
}
void customer_management::view_all_service()
{
    file.open("service.txt", ios::in | ios::app);
    cout << "ID     ";
    cout << "Service work    ";
    cout << "Mobile number    ";
    cout << "Service fees\n";
    while (getline(file, service_id, '*') &&
           getline(file, service_work, '*') &&
           getline(file, service_mobile_no, '*') &&
           getline(file, service_fees, '\n'))
    {
        cout << service_id << "     " << service_work << "     " << service_mobile_no << "    " << service_fees << endl;
    }
    cout << endl;
    file.close();
}
void customer_management::update_service()
{
    file.open("service.txt", ios::in | ios::app);
    file2.open("temp.txt", ios::out | ios::app);
    cout << "Upadate ID :\nEnter ID number : ";
    cin >> match;
    x = 0;
    while (getline(file, service_id, '*') &&
           getline(file, service_work, '*') &&
           getline(file, service_mobile_no, '*') &&
           getline(file, service_fees, '\n'))
    {
        if (service_id != match)
            file2 << service_id << "*" << service_work << "*" << service_mobile_no << "*" << service_fees << endl;
        else if (service_id == match)
        {
            cout << "Enter new service id : ";
            cin >> service_id;
            cout << "Enter new service name : ";
            cin >> service_work;
            cout << "Enter new mobile number : ";
            cin >> service_mobile_no;
            cout << "Enter new fees of provide service : ";
            cin >> service_fees;
            file2 << service_id << "*" << service_work << "*" << service_mobile_no << "*" << service_fees << endl;
            x++;
        }
    }
    if (x > 0)
        cout << "Your Id - " << match << " is updated.\n\n";
    else

        cout << match << " id number is not found. \nEnter correct id number.\n\n";
    file.close();
    file2.close();
    remove("service.txt");
    rename("temp.txt", "service.txt");
}
void customer_management::delete_service()
{
    file.open("service.txt", ios::in | ios::app);
    file2.open("temp.txt", ios::out | ios::app);
    cout << "ID delete:\nEnter ID number : ";
    cin >> match;
    x = 0;
    while (getline(file, service_id, '*') &&
           getline(file, service_work, '*') &&
           getline(file, service_mobile_no, '*') &&
           getline(file, service_fees, '\n'))
    {
        if (service_id != match)
            file2 << service_id << "*" << service_work << "*" << service_mobile_no << "*" << service_fees << endl;
        else
            x++;
    }
    if (x > 0)
        cout << "Your Id - " << match << " is deleted.\n\n";
    else
        cout << match << " id number is not found. \nEnter correct id number.\n\n";
    file.close();
    file2.close();
    remove("service.txt");
    rename("temp.txt", "service.txt");
}

void customer_management::total_amount()
{
    file3.open("customer_data.txt", ios::in | ios::app);
    int amount = 0;
    int value;
    x = 0;
    while (
        getline(file3, customer_name, '*') && getline(file3, customer_mobile_no, '*') && getline(file3, customer_password, '\n') && getline(file3, service_id, '*') && getline(file3, service_work, '*') && getline(file3, service_mobile_no, '*') && getline(file3, service_fees, '\n'))
    {
        cout << "----------------------------------\n";
        cout << ++x << ". " << customer_name << "  " << customer_mobile_no << "\n";
        cout << service_id << "  " << service_work << "  " << service_mobile_no << "  " << service_fees << "\n";
        value = stoi(service_fees);
        amount = amount + value;
    }
    cout << "----------------------------------\n";
    cout << "----------------------------------\n";
    cout << "Total amount is " << amount << endl;
    cout << "----------------------------------\n\n";
    file3.close();
}
