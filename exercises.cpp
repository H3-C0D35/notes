#include <iostream>
#include <vector>
using namespace std;

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