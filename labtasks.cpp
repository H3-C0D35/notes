
#define MAX_VEHICLES 100
#define MAX_LISTING 100
#include <iostream>
#include <string>
/*
sellerListings[sellerCount++] = &marketplaceListings[index];
1user
2admin
3buyer
4seller
5search/filter
6listings
7vehicle
8Inbox
9favourites*/
using namespace std;

class Vehicle
{
    int vehicleID;
    string brand;
    string model;
    int year;
    double price;
    double mileage;
    bool isauto;

public:
    Vehicle() {}
    Vehicle(int id, string brand, string model, int year, double price, double mileage, bool isauto) : vehicleID(id), brand(brand), model(model), year(year), price(price), mileage(mileage), isauto(isauto) {}
    string getbrand() const
    {
        return brand;
    }
    string getmodel() const
    {
        return model;
    }
    int getyear() const
    {
        return year;
    }
    double getprice() const
    {
        return price;
    }
    void setprice(double p)
    {
        price = p;
    }
    double getmileage() const
    {
        return mileage;
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
        cout << "AUTOMATIC: " << (isauto ? "YES" : "NO") << endl;
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

    bool approveListing(Listing l[], int size, int listingID)
    {
        for (int i = 0; i < size; i++)
        {
            if (l[i].getListingID() == listingID)
            {
                if (l[i].getStatus() == "pending")
                {
                    l[i].setStatus("approved");
                    totalApprovedListing++;
                    return true;
                }
            }
        }
        return false;
    }
    bool removeListing(int listingID)
    {
        return true;
    }
    bool banUsers(int id)
    {
        cout << "Enter list ID: ";
        cin >> id;
        return true;
    }
};
class Favourites
{
    Listing *favListings[20];
    int favCount;

public:
    int getFavCount() const
    {
        return favCount;
    }
    Favourites()
    {
        favCount = 0;
    }

    bool addToFav(Listing &l)
    {
        if (favCount >= 20)
            return false;

        favListings[favCount++] = &l;
        return true;
    }

    bool removeFromFav(int listingID)
    {
        for (int i = 0; i < favCount; i++)
        {
            if (favListings[i]->getListingID() == listingID)
            {
                for (int j = i; j < favCount - 1; j++)
                    favListings[j] = favListings[j + 1];

                favCount--;
                return true;
            }
        }
        return false;
    }

    void viewFavs()
    {
        for (int i = 0; i < favCount; i++)
        {
            favListings[i]->getvehicle().showSpecs();
        }
    }
};
class Buyer
{

    double budget;
    bool sendmessage;
    Favourites fav;

public:
    Buyer() {}
    Buyer(double budget, bool sendMessage) : budget(budget), sendmessage(sendMessage) {}
    Buyer(double b) : budget(b) {}

    void viewSavedVehicles(int savecount)
    {
        for (int i = 0; i < savecount; i++)
        {
            cout << "ID: "; // todo:  VEHICLE OBJ
            cout << "Name: ";
        }
    }
    void sendMessage(int sellerID, string message) // todo: MESSAGE OBJ
    {
    }
    bool addtoFavs(Listing &l) // todo VEHICLE OBJ
    {
        return fav.addToFav(l);
    }
    bool remfromFavs(int listingID)
    {
        return fav.removeFromFav(listingID);
    }
    void viewFavourites()
    {
        fav.viewFavs();
    }
};
class Seller
{
    double sellerRating;
    bool verifiedStatus;
    double accountBalance;
    Listing *sellerListings[50];
    int listingCount;

public:
    Seller(double sellerRating, double accountBalance) : sellerRating(sellerRating), accountBalance(accountBalance)
    {
        listingCount = 0;
        verifiedStatus = false;
    }
    bool addListing(Listing &l)
    {
        if (listingCount >= 50)
            return false;
        sellerListings[listingCount] = &l;
        listingCount++;
        return true;
    }
    bool updateListing(int listingID)
    {
        for (int i = 0; i < listingCount; i++)
        {

            if (sellerListings[i]->getListingID() == listingID)
            {
                if (sellerListings[i]->getStatus() != "approved")
                {
                    cout << "Listing not approved yet.\n";
                    return false;
                }
                double newPrice;
                cout << "Enter new price: ";
                cin >> newPrice;
                sellerListings[i]->updateListing(newPrice);
                return true;
            }
        }
        return false;
    }
    bool deleteListing(int listingID)
    {
        for (int i = 0; i < listingCount; i++)
        {
            if (sellerListings[i]->getListingID() == listingID)
            {
                for (int j = i; j < listingCount - 1; j++)
                {
                    sellerListings[j] = sellerListings[j + 1];
                }
                listingCount--;
                return true;
            }
        }
        return false;
    }

    bool respondToMessage(User buyer[], int size, int buyerID, string reply)
    {
        for (int i = 0; i < size; i++)
        {
            if (buyer[i].getUserID() == buyerID)
            {
                cout << "Message: " << reply << endl;
                cout << "Reply sent to " << buyerID << endl;
                return true;
            }
        }
        cout << "Invalid buyer ID" << endl;
        return false;
    }
};
class User
{
    int userID, userNumber;
    string username, password;
    string role;

public:
    User() {}
    User(int id, int num, string name, string password, string role) : userID(id), userNumber(num), username(name), password(password), role(role) {};
    int getUserID() const
    {
        return userID;
    }
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
class Listing
{
private:
    int listingID;
    Vehicle v;     // COMPOSITION
    User *u;       // AGGREGATION
    string status; // "pending", "approved", "sold"
    string postedDate;

public:
    Listing() {}
    Listing(int id, Vehicle v, User *u, string date) : listingID(id), v(v), u(u), postedDate(date) {}
    Vehicle &getvehicle()
    {
        return v;
    }
    void publish()
    {
        if (status == "pending")
        {
            status = "approved";
            cout << "Listing published successfully.\n";
        }
        else
        {
            cout << "Listing is already published or sold.\n";
        }
    }
    void markSold()
    {
        if (status == "approved")
        {
            status = "sold";
            cout << "Listing marked as sold.\n";
        }
        else
        {
            cout << "Listing cannot be marked as sold.\n";
        }
    }
    void updateListing(double newprice)
    {
        v.setprice(newprice);
        cout << "Listing price updated successfully.\n";
    }

    int getListingID() const
    {
        return listingID;
    }
    string getStatus() const
    {
        return status;
    }
    void setStatus(string s)
    {
        status = s;
    }
};
class Company
{
    Listing listings[MAX_LISTING];
    int listingCount;

    User users[50];
    int userCount;

    Message messages[100];
    int messageCount;

public:
    Company()
    {
        listingCount = 0;
        userCount = 0;
        messageCount = 0;
    }

    bool addListing(Listing &l)
    {
        if (listingCount >= MAX_LISTING)
            return false;

        listings[listingCount++] = l;
        return true;
    }

    Listing *findListing(int listingID)
    {
        for (int i = 0; i < listingCount; i++)
        {
            if (listings[i].getListingID() == listingID)
                return &listings[i];
        }
        return NULL;
    }

    bool sendMessage(int senderID, int receiverID, string text)
    {
        if (messageCount >= 100)
            return false;

        messages[messageCount++] = Message(messageCount, senderID, receiverID, text);
        return true;
    }

    void viewMessages(int userID)
    {
        for (int i = 0; i < messageCount; i++)
        {
            if (messages[i].getReceiverID() == userID)
            {
                messages[i].display();
            }
        }
    }

    void showAllListings()
    {
        for (int i = 0; i < listingCount; i++)
        {
            listings[i].getvehicle().showSpecs();
        }
    }
};
/*Well u could add data member like search brand, model etc, then make extra function to
use those data member for searching and add settee function to ask for input */
class Search
{

    string searchbrand, searchmodel;
    int year;
    double price, mileage;

public:
    Search() {}

    void searchbyV(Listing l[], int count, int choice)
    {
        string b, m;
        int y;
        double ma, p;
        switch (choice)
        {
        case 1:
            cout << "Filter by brand name: ";
            cin >> b;
            for (int i = 0; i < count; i++)
            {
                if (l[i].getvehicle().getbrand() == b)
                {
                    l[i].getvehicle().showSpecs();
                }
            }
            break;

        case 2:
            cout << "Filter by Model name: ";
            cin >> m;
            for (int i = 0; i < count; i++)
            {
                if (l[i].getvehicle().getmodel() == m)
                {
                    l[i].getvehicle().showSpecs();
                }
            }
            break;

        case 3:
            cout << "Filter by year: ";
            cin >> y;
            for (int i = 0; i < count; i++)
            {
                if (l[i].getvehicle().getyear() == y)
                {
                    l[i].getvehicle().showSpecs();
                }
            }
            break;

        case 4:
            cout << "Filter by price: ";
            cin >> p;
            for (int i = 0; i < count; i++)
            {
                if (l[i].getvehicle().getprice() == p)
                {
                    l[i].getvehicle().showSpecs();
                }
            }
            break;

        case 5:
            cout << "Filter by Mileage: ";
            cin >> ma;
            for (int i = 0; i < count; i++)
            {
                if (l[i].getvehicle().getmileage() == ma)
                {
                    l[i].getvehicle().showSpecs();
                }
            }
            break;
        default:
            cout << "INVALID!\n";
            break;
        }
    }
};
class Message
{
    int messageID;
    int senderID;
    int receiverID;
    string content;

public:
    Message() {}

    Message(int id, int sender, int receiver, string text)
        : messageID(id), senderID(sender), receiverID(receiver), content(text) {}

    int getMessageID() const
    {
        return messageID;
    }
    int getReceiverID() const
    {
        return receiverID;
    }

    int getSenderID() const
    {
        return senderID;
    }

    void display() const
    {
        cout << "From: " << senderID << " -> "
             << "To: " << receiverID << endl;
        cout << "Message: " << content << endl;
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

    Vehicle v1[MAX_VEHICLES];
    int vehiCount = 0;
    Listing listings[MAX_LISTING];
    int listingCount = 0;
    v1[vehiCount++] = Vehicle(1, "Toyota", "Corolla", 2020, 4500000, 30000, false);
    v1[vehiCount++] = Vehicle(2, "Mercedes", "Benz", 2007, 6700000, 40000, true);
    v1[vehiCount++] = Vehicle(3, "Bugatti", "Cheron", 2020, 1200000, 40000, true);
    listings[listingCount++] = Listing(101, v1[0], &u1, "12/3/2026");
    listings[listingCount++] = Listing(102, v1[1], &u1, "13/3/2026");

    Search s1;
    Buyer b1;
    if (role == "buyer")
    {
        int choice;
        cout << "1.Search\n2.Add to Favs\n3.Send Message\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int choicetoSearch;
            cout << "1.Brand\n2.Model\n3.Year\n4.Price\n5.Mileage\nHow do you wish to search vehicles by?: ";
            cin >> choicetoSearch;
            s1.searchbyV(listings, listingCount, choicetoSearch);
            break;

        case 2:;

        case 3:
        }
    }
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

/*if(role == "buyer")
{
    int choice;
    cout << "1.Search\n2.Add to Favs\n3.Send Message\n";
    cin >> choice;

    if(choice == 1)
    {
        s1.searchbyV(listings, listingCount, filterChoice);
    }
    else if(choice == 2)
    {
        buyer.addtoFavs(vehicleID);
    }
    else
    {
        cout << "Invalid option.\n";
    }
}
else if(role == "seller")
{
    int choice;
    cout << "1.Add Listing\n2.Update\n3.Delete\n";
    cin >> choice;

    // seller functions here
}
else if(role == "admin")
{
    int choice;
    cout << "1.Approve Listing\n2.Remove Listing\n";
    cin >> choice;

    // admin functions here
}
else
{
    cout << "Access denied.\n";
}*/