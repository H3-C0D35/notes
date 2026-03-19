#include <iostream>
#include <vector>
using namespace std;
/* //! DIAMOND PROBLEM INHERITANCE + VIRTUAL + ARRAY TO POINTER OBJECTS
class Device
{
    string device_ID;
    string status;

public:
    Device() : device_ID(""), status("OFF") {} //* Better way to do default constructors
    Device(string id, string status) : device_ID(id), status(status) {}
    string getid()
    {
        return device_ID;
    }
    string getStatus()
    {
        return status;
    }
    //*virtual will be used not just with class names but also parent class's member functions
    virtual void turnOn()
    {
        status = "ON";
        cout << "Device " << device_ID << " has been turned on.\n";
    }
    virtual void turnOf()
    {
        status = "OFF";
        cout << "Device " << device_ID << " has been turned off.\n";
    }
};
class Light : public virtual Device
{
public:
    int brightness;
    Light() : Device(), brightness(100) {}
    Light(string id, string status) : Device(id, status), brightness(100) {}
    void dim(int n)
    {
        if (n <= brightness)
        {
            brightness -= n;
            cout << "Light" << getid() << " has been dimmed to " << brightness << endl;
        }
        else if (n < 0)
        {
            brightness = 0;
        }
        else
        {
            cout << "Not a valid number.\n";
        }
    }
};
class Camera : public virtual Device
{
public:
    bool isRecording;
    Camera() : Device(), isRecording(false) {}
    Camera(string id, string status) : Device(id, status), isRecording(false) {}
    void StartRecording()
    {
        isRecording = true;
        cout << "Camera " << getid() << " started recording.\n";
    }
};

class Thermostat : public Light, public Camera
{
public:
    int temperature;
    Thermostat() : Device(), temperature(20) {}
    Thermostat(string id, string status) : Device(id, status), Light(id, status), Camera(id, status), temperature(20) {}
    void setTemperature(int t)
    {
        temperature = t;
        cout << "Temperature set to " << temperature << endl;
    }
};

class Routine
{
public:
    static const int MDEVICES = 10;
    string routinID;
    string name;
    int deviCount = 0;
    Device *d[MDEVICES];

    void addDevice(Device *dev) // adding one device
    {
        if (deviCount < MDEVICES)
        {
            d[deviCount++] = dev;
            cout << "Device added successfully.\n";
        }
        else
            cout << "Not enough space.\n";
    }

    void addDevices(Device *dev[], int count) // adding multiple devices
    {
        if (deviCount + count < MDEVICES)
        {
            for (int i = 0; i < count; i++)
            {
                d[deviCount++] = dev[i];
            }
            cout << "Device added successfully.\n";
        }
        else
            cout << "Not enough space.\n";
    }
    void execute()
    {
        cout << "Executing devices of routine" << name << endl;
        for (int i = 0; i < deviCount; i++)
        {
            d[i]->turnOn();
        }
    }
};
class Homeowner
{
public:
    static const int MROUTINE = 20;
    string homeownerID;
    string name;
    int routineCount = 0;
    Routine *routine[MROUTINE];

    void createRoutine(Routine *r)
    {
        if (routineCount < MROUTINE)
        {
            routine[routineCount++] = r;
            cout << "Routine " << name << " created.\n";
        }
        else
            cout << "No space to create new routine.\n";
    }
};

int main()
{
    Light L("L1", "OFF");
    Camera C("C1", "OFF");
    Thermostat T("T1", "OFF");
    L.turnOn();
    L.dim(30);
    C.StartRecording();
    T.setTemperature(22);
    Homeowner H;
    Routine R;
    R.name = "Morning Mode";
    R.routinID = "R1";
    Device *D[] = {&L, &C, &T};
    R.addDevices(D, 3);
    H.createRoutine(&R);
    R.execute();
    return 0;
}
//! ══════════════════════════════THEORY═════════════════════════════════

/* //! LINE ____
*Both Light and Camera inherit from Device. If Thermostat inherits from both, we get two copies of Device inside Thermostat — ambiguity on every function call.
*The fix is virtual inheritance on both Light and Camera — which we already have. That tells the compiler: merge the two Device subobjects into one.
*So the correct structure is:
class Light : public virtual Device { ... };
class Camera : public virtual Device { ... };
class Thermostat : public Light, public Camera { ... };
*And Thermostat's constructor "must explicitly call Device()" because with virtual inheritance, the most-derived class is responsible for constructing the virtual base.
! SIMPLER WAY TO DO IT
* we can directly do "class Thermostat : public Device" and remove the "virtual keyword" from class Light and Camera.
*This means no diamond problem, hence, no virtual inheritance needed. But it also means we cannot directly access Light and Camera member functions in Thermostat.
*We would have to add them directly using composition.
class Thermostat : public Device {
public:
    Light light;
    Camera camera;
    int temperature;

    Thermostat(string id, string s) : Device(id, s), light(id, s), camera(id, s), temperature(20) {}

    void dim(int n)           { light.dim(n); }
    void startRecording()     { camera.startRecording(); }
    void setTemperature(int t) {
        temperature = t;
        cout << "Thermostat " << getID() << " set to " << temperature << "°C\n";
    }
};
*This goes against our actual program.
*/
/* //! THEORY OF ABOVE EXERCISE
!------POINTER WORKINGS
*A derived object(taking example of Device(base) and Light(derived)) looks like this:
*Light :
┌───────────┬────────┬────────────┐
│ device_ID │ status │ brightness │
└───────────┴────────┴────────────┘

*and Device looks like this:
┌───────────┬────────┐
│ device_ID │ status │
└───────────┴────────┘
*  now when we do
Light L; Device d = L;
*brightness "slices" up and data is lost as there is physically no space for Device to hold any more than 2 data members of Light.

!THIS IS WHEN POINTERS COME INTO PLAY
*no copy = no slice || and this is exactly what pointers do as they copy nothing, merely store the address / point to the address
Device *d = &L;
d ───────────────►┌───────────┬────────┬────────────┐
                  │ device_ID │ status │ brightness │
                  └───────────┴────────┴────────────┘

*pass by value is the same problem therefore we use pass by pointer or pass by reference
!PASS BY POINTER
void addDevice(Device *dev) {   //* dev is just an address
    devices[count++] = dev;
}
addDevice(&L);   // passes address of L, nothing copied

*Memory:
Light L:
┌───────────┬────────┬────────────┐
│ device_ID │ status │ brightness │
└───────────┴────────┴────────────┘
                ▲
                │
dev ────────────┘   //*(just holds address, no copy made)

!PASS BY REFERENCE
void addDevice(Device &dev) {   //* dev is an alias for whatever you pass
    dev.turnOn();
}

addDevice(L);   //* no copy, dev IS L, just a different name for it

*Memory:
L (original):
┌───────────┬────────┬────────────┐
│ device_ID │ status │ brightness │
└───────────┴────────┴────────────┘
    ▲
    │
dev ┘   //*(alias — same memory location, not a new box)

!The one rule:
────────────────────────────────────────────
│     JOB     │ Value │ Pointer │ Reference │
│─────────────│───────│─────────│───────────│
│Copies       │   YES │   NO    │    NO     │
│Slice risk   │   YES │   NO    │    NO     │
│Modifies orig│   NO  │   YES   │    YES    │
────────────────────────────────────────────
*/
/*
! ═══════════════════════════════════════════════════════════════
!         DEVICE POINTER / ARRAY — COMPLETE REFERENCE
! ═══════════════════════════════════════════════════════════════

! ─────────────────────────────────────────────────────────────
! 1. Device *d — pointer to one object OR dynamic array
!    USE WHEN: size unknown at compile time, heap allocation needed
! ─────────────────────────────────────────────────────────────

? INITIALIZATION
Device *d = new Device("D1", "OFF");  // single object on heap
Device *d = new Device[10];           // dynamic array on heap
Device *d = &L;                       // point to existing object

? ACCESS — single object
d->turnOn();                          // arrow for pointer
d->getID();
(*d).turnOn();                        // same as above, uglier

? ACCESS — dynamic array
d[0].turnOn();                        // dot — d[i] gives the object, not pointer
d[1].getID();

? PASSING TO FUNCTION
void foo(Device *d);
foo(d);                               // pass directly

? CLEANUP
delete d;                             // single object
delete[] d;                           // dynamic array



! ─────────────────────────────────────────────────────────────
! 2. Device d[10] — stack array of objects
!    USE WHEN: size fixed at compile time, no polymorphism needed
! ─────────────────────────────────────────────────────────────

? INITIALIZATION
Device d[3];                                             // default constructors called
Device d[3] = {Device("D1","OFF"), Device("D2","OFF")}; // explicit init

? ACCESS — always dot, d[i] is the object directly
d[0].turnOn();
d[1].getID();

? PASSING TO FUNCTION
void foo(Device d[], int size);
void foo(Device *d,  int size);  // identical to compiler — array decays to pointer
foo(d, 3);

? CLEANUP — none, lives on stack, dies when scope ends



! ─────────────────────────────────────────────────────────────
! 3. Device *d[10] — array of pointers
!    USE WHEN: polymorphism needed (Light, Camera, Thermostat as Device*)
! ─────────────────────────────────────────────────────────────

? INITIALIZATION
Device *d[10];       // 10 pointer slots, uninitialized
Device *d[10] = {};  // all slots set to nullptr (safe)

? POINT TO EXISTING OBJECTS
Light  L("L1", "OFF");
Camera C("C1", "OFF");
d[0] = &L;
d[1] = &C;

? OR HEAP ALLOCATE EACH SLOT
d[0] = new Light("L1",  "OFF");
d[1] = new Camera("C1", "OFF");

? ACCESS — arrow because each element IS a pointer
d[0]->turnOn();
d[1]->getID();

? PASSING TO FUNCTION
void foo(Device *d[], int size);
void foo(Device **d,  int size);  // identical to compiler
foo(d, 3);

? CLEANUP — if heap allocated
for (int i = 0; i < 3; i++)
    delete d[i];



! ─────────────────────────────────────────────────────────────
! SIDE BY SIDE
! ─────────────────────────────────────────────────────────────

  ┌────────────────┬────────────────┬─────────────────┬──────────────────────────────────┐
  │                │   Device *d    │   Device d[10]  │         Device *d[10]            │
  ├────────────────┼────────────────┼─────────────────┼──────────────────────────────────┤
  │ Lives on       │ heap (usually) │ stack           │ stack (ptrs), heap (objects)     │
  │ Access syntax  │ d-> or d[i].   │ d[i].           │ d[i]->                           │
  │ Polymorphism   │ yes            │ no              │ yes                              │
  │ Needs delete   │ yes (if new)   │ no              │ yes (if new)                     │
  │ Function param │ Device *d      │ Device *d       │ Device **d  or  Device *d[]      │
  └────────────────┴────────────────┴─────────────────┴──────────────────────────────────┘

! ─────────────────────────────────────────────────────────────
! THE ONE RULE
*thing you have IS a pointer  →  use  ->
*thing you have IS an object  →  use  .
*/

/* //! ALL MID 1 CONCEPTS

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
}*/

/* //! COMPOSITION + ARRAY OF OBJECTS
class Laptop
{
public:
    string brand_name;
    int GB;
    int mAh;
    Laptop(string brand_name, int GB, int mAh)
    {
        this->brand_name = brand_name;
        this->GB = GB;
        this->mAh = mAh;
    }
    double Backup_time()
    {
        double battery = (double)mAh / (GB * 500);
        return battery;
    }
};
class Student
{
public:
    int id;
    string name;
    Laptop *L;
    Student(int id, string name, Laptop *Lap) : L(Lap)
    {
        this->id = id;
        this->name = name;
    }
    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "---LAPTOP DETAILS---" << endl;
        cout << "Brand name: " << L->brand_name << endl;
        cout << "RAM: " << L->GB << " GB" << endl;

        cout << "Battery Capacity: " << L->mAh << " mAh" << endl;
        cout << "Backup Time: " << L->Backup_time() << "hours"<<endl<<
endl;
    }
};
int main()
{
    Laptop l1("HP", 8, 4000);
    Laptop l2("Dell", 8, 6000);
    Student s1(501, "Ahlele", &amp;l1);
    Student s2(502, "Ahlelas", &amp;l2);
    s1.display();
    s2.display();
}
*/

/* //! COMPOSITION + ARRAY OF OBJECTS + VECTORS
class Device
{
public:
    int ID;
    double power_rating;
    double hours;
    Device() : ID(0), power_rating(0.0), hours(0.0) {}
    Device(int ID, double power_rating, double hours)
    {
        this->ID = ID;
        this->power_rating = power_rating;

        this->hours = hours;
    }
    double daily_energy_use()
    {
        return power_rating * hours;
    }
    void display()
    {
        cout << "Device ID: " << ID << endl;
        cout << "Power Rating: " << power_rating << " W" << endl;
        cout << "Hours used per day: " << hours << endl;
        cout << "Daily energy usage: " << daily_energy_use() << " Wh"
<< endl;
    }
};
class Room
{
public:
    string roomName;
    vector<Device> device;
    Room() : roomName("") {};
    Room(string roomName) : roomName(roomName) {};
    void AddDevices(Device &amp;dev)
    {
        device.push_back(dev);
    }
    double room_energy_use()
    {
        double TotalUsage = 0.0;
        for (int i = 0; i < device.size(); i++)
        {
            TotalUsage += device[i].daily_energy_use();
        }
        return TotalUsage;

    }
    void display()
    {
        cout << "\nRoom Name: " << roomName << endl;
        for (int i = 0; i < device.size(); i++)
        {
            device[i].display();
        }
        cout << "Total Energy Usage per room: " << room_energy_use()
<< "Wh" << endl;
    }
};
class House
{
public:
    int houseID;
    string owner;
    vector<Room> rooms;
    House(int houseID, string owner) : houseID(houseID), owner(owner)
{}
    void AddRooms(Room &amp;r)
    {
        rooms.push_back(r);
    }
    double House_consumption()
    {
        double totalHouseconsump = 0.0;
        for (int i = 0; i < rooms.size(); i++)
        {
            totalHouseconsump += rooms[i].room_energy_use();
        }
        return totalHouseconsump;
    }

    void display()
    {
        cout << "\nOwner Name: " << owner << endl;
        cout << "House ID: " << houseID << endl;
        for (int i = 0; i < 2; i++)
        {
            rooms[i].display();
        }
        cout << "\nTotal House consumption: " << "Wh" <<
House_consumption();
    }
};
int main()
{
    int houseID;
    string owner;
    cout << "Enter house ID: ";
    cin >> houseID;
    cout << "Enter Owner name: ";
    cin >> owner;
    House myHouse(houseID, owner);
    int roomNo;
    cout << "Enter number of rooms: ";
    cin >> roomNo;
    for (int i = 0; i < roomNo; i++)
    {
        string roomName;
        cout << "\nEnter name of room " << i + 1 << ": ";
        cin >> roomName;
        Room r(roomName);
        int deviceNo;
        cout << "Enter number of devices in " << roomName << endl;
        cin >> deviceNo;
        for (int j = 0; j < deviceNo; j++)
        {

            int id;
            double power, hours;
            cout << "\nDevice " << j + 1 << endl;
            cout << "Enter Device ID: ";
            cin >> id;
            cout << "Enter Power rating: ";
            cin >> power;
            cout << "Enter Hours used per day: ";
            cin >> hours;
            Device d(id, power, hours);
            r.AddDevices(d);
        }
        myHouse.AddRooms(r);
    }
    myHouse.display();
    return 0;
}*/

/* //! STATIC

class User
{
public:
    static int totalUsers;

    int id;
    string name;
    const int accessLevel;
    bool wasCounted;
    User(int id, string name, int accessLevel) :
accessLevel(accessLevel)
    {
        this->id = id;
        this->name = name;
        if (accessLevel > 3)
        {
            totalUsers++;
            this->wasCounted = true;
        }
        else
        {
            this->wasCounted = false;
        }
    }
    void display()
    {
        cout << "ID: " << id << endl
             << "Name: " << name << endl
             << "Access Level: " << accessLevel << endl
             << "------------------------" << endl;
    }
    static void usercountdisplay()
    {
        cout << "Total Users: " << totalUsers << endl;
    }
    ~User()
    {
        if (wasCounted == true)
        {
            totalUsers--;
        }
        cout << "Destruction occured :(" << endl;

    }
};
int User::totalUsers = 0;
int main()
{
    User u1(199, "LeBron", 100);
    User u2(200, "Kris", 1);
    User u3(201, "Sheldon", 999);
    User u4(202, "Luffy", 1000);
    User u5(203, "Kirk", 0);
    u1.display();
    u2.display();
    u3.display();
    u4.display();
    u5.display();
    User::usercountdisplay();
    return 0;
}*/

/* //! Composition + Aggregation + Constructor + Arrays + Array of objects
class Furniture
{
public:
    string type;
    int quantity;
    //* constructor
    Furniture(string type, int quantity) : type(type), quantity(quantity) {}

    void display()
    {
        cout << "FURNITURE DETAILS: ";
        cout << "Furniture type: " << type << endl;
        cout << "Quantity: " << quantity << endl;
    }
};
class Student
{
public:
    int ID;
    string name;
    string department;

    //* default
    Student() : ID(0), name(""), department("") {}

    //* para
    Student(int ID, string name, string department) : ID(ID), name(name), department(department) {}
    void displayS()
    {
        cout << "STUDENT DETAILS:\n";
        cout << "ID: " << ID << endl
             << "Name: " << name << endl
             << "Department: " << department << endl;
        cout << "----------------\n";
    }
};
class Room
{
public:
    int roomNo;
    int maxCapacity;
    int currentCount;
    Student *s[4];
    Furniture furniture;

    //* since max capacity doesnt need no input and it is fixed so...yeah
    //* Student s is not in constructor the same way furniture is because Room owns the furniture. A room cannot exist without furniture in this case. Students exist independently. f you forced students into constructor:
    //* Room(int roomNo, Furniture f, Student s1, Student s2, ...)

    Room(int roomNo, Furniture furniture) : roomNo(roomNo), furniture(furniture)
    {
        currentCount = 0;
        maxCapacity = 4;
        for (int i = 0; i < 4; i++)
        {
            s[i] = nullptr; //*cleanin
        }
    }

    void addStudent(Student &st)
    {
        if (currentCount < maxCapacity)
        {
            s[currentCount] = &st;
            currentCount++;
        }
        else
        {
            cout << "Room full\n";
        }
    }
    void removeStudent(int studentID)
    {
        for (int i = 0; i < currentCount; i++)
        {
            if (s[i]->ID == studentID)
            {
                for (int j = i; j < currentCount - 1; j++)
                {
                    s[j] = s[j + 1]; //*s[j] get overwritten
                } //*here currentcount - 1 is equal to j+1
                s[currentCount - 1] = nullptr;
                currentCount--;
                cout << "Student removed\n";
                return;
            }
        }
        cout << "Student not found\n";
    }
    void displayR()
    {
        cout << "ROOM DETAILS: ";
        cout << "Room number: " << roomNo << endl;
        cout << "Capacity: " << currentCount << "/" << maxCapacity << endl;
        furniture.display();
        cout << endl;
        for (int i = 0; i < currentCount; i++)
        {
            s[i]->displayS();
        }
    }
};
int main()
{
    Student s1(11, "John", "CS");
    Student s2(12, "Doe", "EE");
    Student s3(13, "Alice", "CY");
    Student s4;
    Furniture f1("Bed", 4);
    Room r1(101, f1);
    r1.addStudent(s1);
    r1.addStudent(s2);
    r1.addStudent(s3);
    r1.addStudent(s4);
    r1.displayR();
    cout << "Removing 4th student...\n";
    r1.removeStudent(0);
    r1.displayR();
}*/

/* //! CONST KEYWORD + DEFAULT & PARA CONSTRUCTORS + DMA(in taking inputs) + LOGIC
?Create a class for PicnicManagement
?a. Create member variables, accessors and mutators, default and parameterized constructors with the following constraints:
?The total number of tickets, and total budget should not change once they have been
?initialized. The default number of tickets should be 2,000. The default total budget should be 2,000,000/=
?The number of tickets and budget should not be negative. In case of wrong inputs, default values should be used.
?b. Write a member function called bool utilizeFunds(int amount). These funds should be
?deducted from the remaining budget. If the funds exceed the remaining budget, and
?appropriate message should be displayed and false should be returned.
?c. Write a member function called int sellTicket(int amount) which can be used by contact persons
?to sell tickets. A maximum of two, and a minimum one ticket can be sold at a time. Whenever a
?ticket is sold, it should add 1,500/= to the remaining budget. During the function call, if the
?number of tickets remaining is lesser than the number of tickets to sell, it should sell the
?maximum possible tickets and then return the number of tickets that were not sold. (If I want to
?sell 2 tickets, and there is only 1 ticket left, it should sell me the 1 ticket and return 1)

class PicnicManagement
{
private:
    const int totalTickets;
    const double totalBudget;
    int ticketSold;
    double remainingBudget;

public:
    //* para
    PicnicManagement(int totalTickets, double totalBudget, int ticketSold, double remainingBudget) : totalTickets(totalTickets), totalBudget(totalBudget), ticketSold(ticketSold), remainingBudget(remainingBudget)
    {
    }
    //* default
    PicnicManagement() : totalTickets(2000), totalBudget(2000000), ticketSold(0), remainingBudget(2000000) {}

    bool utilizeFunds(int amount)
    {

        if (amount > remainingBudget)
        {
            cout << "Not enough funds!\n";
            return false;
        }
        else
        {
            remainingBudget -= amount;
            return true;
        }
    }

    int sellTicket(int amount)
    {
        if (amount < 1)
            amount = 1;
        if (amount > 2)
            amount = 2;
        int remaining = totalTickets - ticketSold;
        int ticketsToSell;
        if (remaining >= amount)
        {
            ticketsToSell = amount;
        }
        else
        {
            ticketsToSell = remaining;
        }
        int unsold = amount - ticketsToSell;
        ticketSold += ticketsToSell;
        remainingBudget += ticketsToSell * 1500;
        return unsold;
    }
};

int main()
{

    int totalTickets;
    double totalBudget;
    int ticketSold;
    double remainingBudget;
    cout << "Enter total tickets to sell: ";
    cin >> totalTickets;
    cout << "Enter total tickets sold: ";
    cin >> ticketSold;
    cout << "Enter total budget: ";
    cin >> totalBudget;
    cout << "Enter remaining budget: ";
    cin >> remainingBudget;
    PicnicManagement *p1;
    if (totalTickets < 0 || totalBudget < 0 || ticketSold < 0 || remainingBudget < 0)
    {
        cout << "USING DEFAULT VALUES\n";
        p1 = new PicnicManagement();
    }
    else
    {
        p1 = new PicnicManagement(totalTickets, totalBudget, ticketSold, remainingBudget);
    }

    int funds;
    cout << "Do you want to utilize funds?: ";
    int flag;
    cin >> flag;
    if (flag == 1)
    {
        cout << "Enter amount needed: ";
        cin >> funds;
        p1->utilizeFunds(funds);
    }
    int amount;
    cout << "Enter amount of tickets you want to buy: ";
    cin >> amount;
    cout << "Unsold: " << p1->sellTicket(amount);
    delete p1;
}
    */