#include <iostream>
using namespace std;
class User
{
    int userID;
    string name;
    int number;
    string password;
    string role;

public:
    void login();
    void logout();
    void updateprofile();
    void viewDashboard();
};
class Buyer : public User
{
public:
    string savedVehicles[100];
    bool messageSent;
    string location;
    double budget;
    double buyerRating;
    // funcs
    void saveToFav();
    void removeFromFav();
    void sendMessage();
    void viewSavedVehicles();
};
class Seller : public User
{
public:
    double sellerRating;
    int totalListings;
    bool verifiedStatus;
    int lisitngs[100];
    double accountBalance;
    // funcs
    void addListing();
    void updateListing();
    void deleteListing();
    void respondToMessage();
};

class Admin : public User
{
    int AdminLevel;
    bool permissions;
    int totalApprovedListings;
    int reportsHandled;
    string lastLogin;

    // Functions:
    int approveListing();
    void removeListing();
    void banUser();
    void generateReport();
};
// class 2
class Vehicle
{
public:
    int vehicleID;
    string brand;
    string model;
    int year;
    double mileage;
    double price;
    // func
    void displayInfo();
    void updatePrice();
    void calcDeprication();
    void matchSearch();
};
class Car : public Vehicle
{
    string engineType;
    string transmission;
    double fuelType;
    int doors;
    string condition;

    // func
    void showSpecs();
    void calcResaleValue();
    void isAutomatic(); // todo: bool
    // void compareWith();
};

class Bike : public Vehicle
{
    string engineType;
    string bikeType;
    double fuelType;
    double weight;
    string condition;

    // funcs
    void showSpecs();
    void estimateMileage();

    // void compareWith();
};

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
○ Use at least five constant data members, constant pointer, and constant function in
your program

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