
#define MAX_VEHICLES 100
#include <iostream>
#include <string>
/*1user
2admin
3buyer
4seller
5search/filter
6listings
7vehicle
8Inbox
9favourites*/
using namespace std;
class Search
{
    Vehicle v;

public:
    Search() {}

    void searchbyV(Vehicle v[], int count, int choice)
    {
        string b, m;
        int y;
        double ma, p;
        Search s1;
        switch (choice)
        {
        case 1:
            cout << "Filter by brand name: ";
            cin >> b;
            for (int i = 0; i < count; i++)
            {
                if (v[i].getbrand() == b)
                {
                    v[i].showSpecs();
                }
            }
            break;

        case 2:
            cout << "Filter by Model name: ";
            cin >> m;
            for (int i = 0; i < count; i++)
            {
                if (v[i].getmodel() == m)
                {
                    v[i].showSpecs();
                }
            }
            break;

        case 3:
            cout << "Filter by year: ";
            cin >> y;
            for (int i = 0; i < count; i++)
            {
                if (v[i].getyear() == y)
                {
                    v[i].showSpecs();
                }
            }
            break;

        case 4:
            cout << "Filter by price: ";
            cin >> p;
            for (int i = 0; i < count; i++)
            {
                if (v[i].getprice() == p)
                {
                    v[i].showSpecs();
                }
            }
            break;

        case 5:
            cout << "Filter by Mileage: ";
            cin >> ma;
            for (int i = 0; i < count; i++)
            {
                if (v[i].getmileage() == ma)
                {
                    v[i].showSpecs();
                }
            }
            break;
        default:
            cout << "INVALID!\n";
            break;
        }
    }
};
class Vehicle
{
    int vehicleID;
    string brand;
    string model;
    int year;
    double price;
    double mileage;
    string isauto;

public:
    Vehicle() {}
    Vehicle(int id, string brand, string model, int year, double price, double mileage) : vehicleID(id), brand(brand), model(model), year(year), price(price), mileage(mileage) {}
    string getbrand()
    {
        return brand;
    }
    string getmodel()
    {
        return model;
    }
    int getyear()
    {
        return year;
    }
    double getprice()
    {
        return price;
    }
    double getmileage()
    {
        return mileage;
    }
    void isAutomatic()
    {
        if (price > 70000)
        {
            isauto = "YES";
        }
        else
        {
            isauto = "NO";
        }
    }
    void showSpecs()
    {
        cout << "\n-------DETAILS-------\n";
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Mileage: " << mileage << endl;
        cout << "AUTOMATIC: ";
        isAutomatic();
        cout << "\n";
    }
};

class Admin
{
    int adminLevel;
    bool permissions;
    int totalApprovedListing;
    /*why we do inheritance?
    is it efficient?

    "it has a unique attribute"*/
public:
    Admin(int adminlvl, bool perms, int TAL) : adminLevel(adminlvl), permissions(perms), totalApprovedListing(TAL) {}

    bool approveListing(int listingID)
    {
        cout << "Enter list ID: ";
        cin >> listingID;
        return true;
    }
    bool removeListing(int listingID)
    {
        cout << "Enter list ID: ";
        cin >> listingID;
        return true;
    }
    bool banUsers(int id)
    {
        cout << "Enter list ID: ";
        cin >> id;
        return true;
    }
};
class Buyer
{

    double budget;
    bool sendmessage;
    string savedVehicles[20];

public:
    Buyer(double budget, bool sendMessage, string savedV[20]) : budget(budget), sendmessage(sendMessage)
    {
        for (int i = 0; i < 20; i++)
        {
            savedVehicles[i] = savedV[i];
        }
    }
    void viewSavedVehicles()
    {
        for (int i = 0; i < savedVehicles->length(); i++)
        {
            cout << "ID: "; // todo:  VEHICLE OBJ
            cout << "Name: ";
        }
    }
    void sendMessage(int sellerID, string message) // todo: MESSAGE OBJ
    {
        cout << "Enter Seller ID: ";
        cin >> sellerID;
        cout << "MESSAGE: \n";
        cin >> message;
    }
    bool addtoFavs(int vehicleID) // todo VEHICLE OBJ
    {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;
        if (vehicleID)
        {
            cout << "Added to Favs!\n";
            return true;
        }
        else
        {
            cout << "Invalid vehicle ID.\n";
            return false;
        }
    }
    bool remfromFavs(int vehicleID)
    {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;
        if (vehicleID)
        {
            cout << "Removed to Favs!\n";
            return true;
        }
        else
        {
            cout << "Invalid vehicle ID.\n";
            return false;
        }
    }
};
class User
{
    int userID, userNumber;
    string username, password;
    string role;

public:
    User(int id, int num, string name, string password, string role) : userID(id), userNumber(num), username(name), password(password), role(role) {};

    void updateProfile()
    {
        int choice;
        cout << "What do you want to change? \n";
        cout << "1. ID\n2. Name: \n3. Number\n4. Password\n5. Role\nCHOICE: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter new ID: ";
            cin >> userID;
            break;

        case 2:
            cout << "Enter new Name: ";
            cin >> username;
            break;

        case 3:
            cout << "Enter new number: ";
            cin >> userNumber;
            break;

        case 4:
            cout << "Enter new password: ";
            cin >> password;
            break;

        case 5:
            cout << "Enter new role: ";
            cin >> role;
            break;

        default:
            cout << "INVALID!\n";
            break;
        }
    }

    void viewDashboard()
    {
    }
};

int main()
{
    int id, num;
    string name, password, role;
    cout << "Enter User ID: ";
    cin >> id;
    cout << "Enter Number: ";
    cin >> num;
    cout << "Enter Username: ";
    cin >> name;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Role: ";
    cin >> role;
    User u1(id, num, name, password, role);

    int choice;

    cout << "1.Brand\n2.Model\n3.Year\n4.Price\n5.Mileage\nHow do you wish to search vehicles by?: ";
    cin >> choice;
    Vehicle v1[MAX_VEHICLES];
    int vehiCount = 0;
    Search s1;
    s1.searchbyV(v1, vehiCount, choice);
}

/*Design and implement a Car Marketplace System similar to PakWheels (www.pakwheels.com)
using Object-Oriented Programming principles. The assignment is intended to assess your
understanding and application of classes, polymorphism, aggregation, composition, constructors,
constants, static members, and arrays of objects.
Requirements
1. Classes: 5 marks
○ Identify at least 10 classes
○ Each class must have 5–6 data members
○ Each class must have 4 member functions other than getters and setters
2. Constructors, setters and getters: 3 marks
○ Use default, parameterized, and copy constructors wherever it makes sense
○ Explain why you used a particular constructor for that class
○ You may use constructor overloading if necessary with proper reasoning
○ Use setters and getters wherever necessary, for private data members.
3. Constants & Constant Functions: 2 marks
○ Use at least five constant data members, constant pointer, and constant function in your program

4. Static Members: 2 marks
○ Use at least two static data member and static member function
○ Explain why you made it static
5. Composition & Aggregation: 5 marks
○ You must identify and implement at least 2 composition and 2 aggregation
relationship

6. Array of Objects: 5 marks
○ Use array of objects for at least two classes
7. Functionality: 12 marks
Your program should at least do the following:
○ Add, update, delete vehicle listings.
○ Search and filter vehicles by attributes (brand, model, price, year, mileage).
○ Buyer can save favorites.
○ Buyer can send messages to Seller.
○ Admin can approve/remove listings.
8. Class Diagram: 6 marks
○ Draw a proper class diagram showing:
■ Classes with their attributes & methods.
■ aggregation, and composition relationships.
*/