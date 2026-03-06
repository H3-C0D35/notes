
#define MAX_VEHICLES 100
#define MAX_LISTING 100
#include <iostream>
#include <string>
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
    Vehicle() : vehicleID(0) {}
    Vehicle(int id, string brand, string model, int year, double price, double mileage, bool isauto) : vehicleID(id), brand(brand), model(model), year(year), price(price), mileage(mileage), isauto(isauto) {}
    Vehicle(const Vehicle &obj)
        : vehicleID(obj.vehicleID),
          brand(obj.brand),
          model(obj.model),
          year(obj.year),
          price(obj.price),
          mileage(obj.mileage),
          isauto(obj.isauto)
    {
    }
    int getVehicleID() const
    {
        return vehicleID;
    }

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

    void showSpecs() const
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
class User
{
    const int userID;
    int userNumber;
    string username, password;
    string role;
    static int totalUsers;

public:
    User() : userID(0), userNumber(0) {}

    User(int id, int num, string name, string password, string role) : userID(id), userNumber(num), username(name), password(password), role(role)
    {
        totalUsers++;
    };
    static int getTotalUsers()
    {
        return totalUsers;
    }
    int getUserID() const
    {
        return userID;
    }
    string getRole() const
    {
        return role;
    }
    void updateProfile()
    {
        int choice;
        cout << "What do you want to change? \n";
        cout << "1. Name: \n2. Number\n3. Password\n4. Role\nCHOICE: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter new Name: ";
            cin >> username;
            break;

        case 2:
            cout << "Enter new number: ";
            cin >> userNumber;
            break;

        case 3:
            cout << "Enter new password: ";
            cin >> password;
            break;

        case 4:
            cout << "Enter new role: ";
            cin >> role;
            break;

        default:
            cout << "INVALID!\n";
            break;
        }
    }
};
int User::totalUsers = 0;
class Listing
{
private:
    int listingID;
    Vehicle v;     // COMPOSITION
    User *u;       // AGGREGATION
    string status; // "pending", "approved", "sold"
    string postedDate;
    static int totalListings;

public:
    Listing() : listingID(0), u(NULL), status("pending"), postedDate("") {}
    Listing(int id, Vehicle v, User *u, string date) : listingID(id), v(v), u(u), postedDate(date), status("pending")
    {
        totalListings++;
    }

    static int getTotalListings()
    {
        return totalListings;
    }

    Vehicle &getvehicle()
    {
        return v;
    }

    const Vehicle &getvehicle() const
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
int Listing::totalListings = 0;
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

class Favourites
{
    Listing *favListings[20];
    int favCount;
    int maxLimit;
    string categoryName;
    bool isPrivate;

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

    void viewFavs() const
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
    Favourites fav;
    int totalPurchases;
    string preferredBrand;
    bool verifiedBuyer;

public:
    Buyer() : budget(0) {}
    Buyer(double b) : budget(b) {}

    double getBudget() const
    {
        return budget;
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
class Company
{
    const string companyName = "PAKWHEELS";

    Listing *listings[MAX_LISTING];
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

    bool addListing(Listing *l)
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
            if (listings[i]->getListingID() == listingID)
                return listings[i];
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

    void showAllListings() const
    {
        for (int i = 0; i < listingCount; i++)
        {
            listings[i]->getvehicle().showSpecs();
        }
    }
    Listing *getListings()
    {
        return *listings;
    }

    int getListingCount() const
    {
        return listingCount;
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
    bool updateListing(int listingID, double newPrice)
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
    bool respondToMessage(Company &c, int sellerID, int buyerID, string reply)
    {
        return c.sendMessage(sellerID, buyerID, reply);
    }
};

class Admin
{
    int adminLevel;
    bool permissions;
    int totalApprovedListing;
    string adminName;
    int yearsOfService;
    bool superAdmin;

public:
    Admin(int adminlvl, bool perms, int TAL) : adminLevel(adminlvl), permissions(perms), totalApprovedListing(TAL) {}

    bool approveListing(Company &c, int listingID)
    {
        Listing *l = c.findListing(listingID);

        if (l && l->getStatus() == "pending")
        {
            l->setStatus("approved");
            totalApprovedListing++;
            return true;
        }

        return false;
    }
    bool removeListing(Company &c, int listingID)
    {
        Listing *l = c.findListing(listingID);

        if (l)
        {
            l->setStatus("removed");
            return true;
        }

        return false;
    }

    bool banUsers(User users[], int size, int id)
    {
        for (int i = 0; i < size; i++)
        {
            if (users[i].getUserID() == id)
            {
                cout << "User " << id << " banned.\n";
                return true;
            }
        }
        return false;
    }
};

class Search
{
public:
    static void searchByBrand(Listing l[], int count, const string &brand)
    {
        for (int i = 0; i < count; i++)
        {
            if (l[i].getvehicle().getbrand() == brand)
            {
                l[i].getvehicle().showSpecs();
            }
        }
    }

    static void searchByModel(Listing l[], int count, const string &model)
    {
        for (int i = 0; i < count; i++)
        {
            if (l[i].getvehicle().getmodel() == model)
            {
                l[i].getvehicle().showSpecs();
            }
        }
    }

    static void searchByYear(Listing l[], int count, int year)
    {
        for (int i = 0; i < count; i++)
        {
            if (l[i].getvehicle().getyear() == year)
            {
                l[i].getvehicle().showSpecs();
            }
        }
    }

    static void searchByPrice(Listing l[], int count, double maxPrice)
    {
        for (int i = 0; i < count; i++)
        {
            if (l[i].getvehicle().getprice() <= maxPrice)
            {
                l[i].getvehicle().showSpecs();
            }
        }
    }

    static void searchByMileage(Listing l[], int count, double maxMileage)
    {
        for (int i = 0; i < count; i++)
        {
            if (l[i].getvehicle().getmileage() <= maxMileage)
            {
                l[i].getvehicle().showSpecs();
            }
        }
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
    cout << "Enter Role (buyer/seller/admin): ";
    cin >> role;

    User u1(id, num, name, password, role);

    Company company;

    // Vehicles

    Vehicle v1(1, "Toyota", "Corolla", 2020, 4500000, 30000, false);
    Vehicle v2(2, "Mercedes", "Benz", 2020, 7600000, 40000, true);
    Vehicle v3(3, "Toyota", "Alto", 1999, 200000, 10000, false);
    // Listings
    Seller s1(4.5, 100000);
    Listing l1(101, v1, &u1, "12/3/2026");
    Listing l2(102, v2, &u1, "13/3/2026");

    company.addListing(&l1);
    company.addListing(&l2);

    Buyer buyerObj(5000000);
    Seller sellerObj(4.5, 100000);
    Admin adminObj(1, true, 0);

    int choice;

    do
    {
        cout << "\n------ MENU ------\n";
        cout << "1. Search Listings\n";
        cout << "2. Add to Favourites\n";
        cout << "3. Send Message\n";
        cout << "4. Approve Listing\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (role == "buyer")
        {
            switch (choice)
            {
            case 1:
            {
                int searchChoice;
                cout << "1.Brand\n2.Model\n3.Year\n4.Price\n5.Mileage\nChoice: ";
                cin >> searchChoice;

                switch (searchChoice)
                {
                case 1:
                {
                    string brand;
                    cout << "Enter brand: ";
                    cin >> brand;
                    Search::searchByBrand(company.getListings(), company.getListingCount(), brand);
                    break;
                }
                case 2:
                {
                    string model;
                    cout << "Enter model: ";
                    cin >> model;
                    Search::searchByModel(company.getListings(), company.getListingCount(), model);
                    break;
                }
                case 3:
                {
                    int year;
                    cout << "Enter year: ";
                    cin >> year;
                    Search::searchByYear(company.getListings(), company.getListingCount(), year);
                    break;
                }
                case 4:
                {
                    double price;
                    cout << "Enter max price: ";
                    cin >> price;
                    Search::searchByPrice(company.getListings(), company.getListingCount(), price);
                    break;
                }
                case 5:
                {
                    double mileage;
                    cout << "Enter max mileage: ";
                    cin >> mileage;
                    Search::searchByMileage(company.getListings(), company.getListingCount(), mileage);
                    break;
                }
                }
                break;
            }

            case 2:
            {
                int listingID;
                cout << "Enter Listing ID to favourite: ";
                cin >> listingID;

                Listing *found = company.findListing(listingID);
                if (found && buyerObj.addtoFavs(*found))
                    cout << "Added to favourites.\n";
                else
                    cout << "Failed to add.\n";
                break;
            }

            case 3:
            {
                int receiverID;
                string msg;
                cout << "Enter Seller ID: ";
                cin >> receiverID;
                cout << "Enter Message: ";
                cin.ignore();
                getline(cin, msg);

                if (company.sendMessage(u1.getUserID(), receiverID, msg))
                    cout << "Message sent.\n";
                else
                    cout << "Message failed.\n";
                break;
            }

            case 4:
                cout << "You do not have permission to perform this action.\n";
                break;
            }
        }
        else if (role == "seller")
        {
            if (choice == 4)
                cout << "You do not have permission to perform this action.\n";
            else
                cout << "Seller functionality can be expanded here.\n";
        }
        else if (role == "admin")
        {
            if (choice == 4)
            {
                int listingID;
                cout << "Enter Listing ID to approve: ";
                cin >> listingID;

                Listing *found = company.findListing(listingID);
                if (found)
                {
                    found->publish();
                    cout << "Approved.\n";
                }
                else
                    cout << "Listing not found.\n";
            }
            else
            {
                cout << "Admins only approve listings here.\n";
            }
        }
        else
        {
            cout << "Invalid role.\n";
        }

    } while (choice != 5);

    cout << "Exiting system.\n";

    cout << "Total Users: " << User::getTotalUsers() << endl;
    cout << "Total Listings: " << Listing::getTotalListings() << endl;
    return 0;
}