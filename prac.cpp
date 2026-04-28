#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;

/* //! OPERATOR OVERLOADING
*We do this when we want to add objects. since objects dont know what +, - or any of that is, we tell it by making its member functions and passing them in it.
* SYNTAX : class_name op_name op_symbol (const class_name& onj_name)

class Number
{
public:
    int value;
    Number(int v = 0) : value(v) {}

    void display() const
    {
        cout << "c: " << value << endl;
    }
    //* addition
    Number operator+(const Number &p)
    {
        Number a;
        a.value = this->value + p.value;
        return a;
    }

    //* sub
    Number operator-(const Number &p)
    {
        Number a;
        a.value = this->value - p.value;
        return a;
    }

    //* assign add
    Number &operator+=(const Number &p)
    {
        this->value += p.value;
        return *this;
    }

    //* assign sub
    Number &operator-=(const Number &p)
    {
        this->value -= p.value;
        return *this;
    }

    //* unary
    Number operator-()
    {
        Number a;
        a.value = -this->value;
        return a;
    }

    //* prefix inc
    Number &operator++()
    {
        this->value++;
        return *this;
    }

    //* postfix inc
    Number operator++(int)
    {
        Number a = *this;
        this->value++;
        return a;
    }
};

int main()
{
    Number a(10), b(2), c;
    c = a + b;
    c.display();
    c = a - b;
    c.display();

    a += b;
    a.display();
    b -= a;
    b.display();

    c = -a;
    c.display();

    c = a++;
    c.display();
    c = ++b;
    c.display();
}
*When we want to print an object, we cant just cout<<obj as it doesnt know what that means. so in order to print, we do friend functions
*SYNTAX --> friend ostream& operator<<(ostream &print, const classname& obj);
*then implement it,
ostream& operator<<(ostream &print, const classname& obj){ print<<obj.membername; return print; }

? EXERCISE --- friend function for displaying
class Distance
{
    int value;

public:
    Distance(int v = 0) : value(v) {}
    Distance operator+(const Distance &p)
    {
        Distance d;
        d.value = this->value + p.value;
        return d;
    }
    bool operator>(const Distance &p)
    {
        if (this->value > p.value)
            return true;
        else
            return false;
    }
    bool operator==(const Distance &p)
    {
        if (p.value == this->value)
            return true;
        else
            return false;
    }
    friend ostream &operator<<(ostream &out, const Distance &d);
};
ostream &operator<<(ostream &out, const Distance &d)
{
    out << d.value << endl;
    return out;
}

int main()
{
    Distance d1(10), d2(15), d3;
    d3 = d1 + d2;
    cout << d3;
    if (d1 > d2)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    if (d1 == d2)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}

?EXERCISE --- performing arithmetic operations on objects using numbers instead of other objects.

class BankAccount
{
    string id;
    double balance;

public:
    BankAccount() : id("unknown"), balance(0.0) {}
    BankAccount(string id, double b) : id(id), balance(b) {}

    double getbalance()
    {
        return balance;
    }
    void setbalance(double b)
    {
        balance = b;
    }
    string getid()
    {
        return id;
    }
    BankAccount operator+(const BankAccount &obj)
    {
        BankAccount b1;
        b1.balance = this->balance + obj.balance;
        b1.id = this->id;
        return b1;
    }

    *passing amount as we want to minus this specific number. In main, just write the number
    BankAccount operator-(double amount)
    {
        BankAccount b1;
        b1.balance = this->balance - amount;
        b1.id = this->id;
        if (b1.balance >= 0)
            return b1;
        else
        {
            b1.setbalance(0);
            return b1;
        }
    }

    bool operator>(const BankAccount &obj)
    {
        return this->balance > obj.balance;
    }

    friend ostream &operator<<(ostream &print, const BankAccount &b);
};
ostream &operator<<(ostream &print, const BankAccount &b)
{
    print << "ID: " << b.id << endl;
    print << "Balance: " << b.balance;
    return print;
}
int main()
{
    BankAccount b1("ACC001", 1000.0);
    BankAccount b2("ACC002", 2500.0);
    BankAccount b3 = b1 + b2;
    cout << b3 << endl;
    b1 = b1 - 1500;
    cout << b1 << endl;
    cout << b2 << endl;
    cout << (b2 > b1);
}

?EXERCISE -- Using friend function for arithmetic operators
class Number
{
    int answer;

public:
    Number(int a) : answer(a) {}

    friend Number operator+(int num, const Number &obj); //*The reason why friend is used for + is because it allows to add left operand + right object, like: 5 + obj. normal operator+ only work if it is obj + 5. but doing this as a friend can work both ways
    friend ostream &operator<<(ostream &print, const Number n);
};
Number operator+(int num, const Number &obj)
{
    return Number(num + obj.answer); //*Constructor will be used for returning.
}
ostream &operator<<(ostream &print, const Number n)
{
    print << n.answer << endl;
    return print;
}
int main()
{
    Number n(10);
    Number c = 5 + n;
    cout << c; //*15
}


?Implementing
?Point p1(1, 2), p2(3, 4);
?Point p3 = p1 + p2;
#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int x, int y) : x(x), y(y) {}
    Point operator+(const Point &p)
    {
        return Point(this->x + p.x, this->y + p.y); //*here this = p1 and p = p2 so this->x = p1.x and p.x = p2.x
    }
    friend ostream &operator<<(ostream &print, const Point &p);
};
ostream &operator<<(ostream &print, const Point &p)
{
    print << "(" << p.x << ", " << p.y << ")";
    return print;
}

int main()
{
    Point p1(1, 2), p2(2, 3);
    Point p3 = p1 + p2;
    cout << p3;
}



*/

// 6. Hotel Room Reservation with Inheritance A seaside hotel has three types of rooms: StandardRoom, DeluxeRoom, and SuiteRoom.
// Each room type has different pricing and amenities. The hotel wants a basic reservation
// system that captures guest details, assigns rooms, and computes total charges.
// However, internal pricing rules (like seasonal multipliers or discounts) must not be
// directly modifiable from outside the room classes.
// Requirements:
// Create a base class Room with:
// Room number, base price per night, and occupancy status.
// A constructor that initializes the room number and base price.
// Create derived classes:
// Use constructors and destructors to:
// Display messages when reservations are created and destroyed, simulating allocation and release of booking resources.
// The system should allow a tester to:
// Create rooms of various types.
// Create reservations.
// Attempt to book an already occupied room and see that it is prevented by internal
// logic (not by manipulating fields directly).

/* //!FRIEND CLASS
 *every friend class can access the members of the class they are declared in.
class Engine; //*declaring here is important otherwise we wont be able to use it in class Car.

class Car {
    int horsepower = 400;
    friend class Engine;
};

*definition
class Engine {
public:
    void tune(Car c) {
        cout << c.horsepower;
    }
};
 */

/* //! FRIEND FUNCTION
 *declared inside class but defined outside as they dont belong to the class. The class decide whom the friends are and then shares its private / protected members with it. This prevents excess getters/setters.

 */

/*//! JIST OF INHERITANCE CONCEPTS + POLYMORPHISM
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

/* //! INHERITANCE
*THERE ARE TYPES OF INHERITANCE: *SINGLE
*MULTIPLE : where one parent has a child who has another child.
*MULTILEVEL : where one child has more than one parent

class VehicleInfo //*PARENT 1
{
public:
    int vehicleID;
    string model;
    VehicleInfo() {}
    VehicleInfo(int id, string model) : vehicleID(id), model(model) {}
};
class RentalInfo //*PARENT 2
{
public:
    double rentalPricePerDay;
    string status;
    RentalInfo() {}
    RentalInfo(string status) : rentalPricePerDay(30.5),
status(status) {}
};

class RentalVehicle : public VehicleInfo, public RentalInfo //*CHILD
{
public:

    int days;
    RentalVehicle(int id, string model, string status, int days) :
VehicleInfo(id, model), RentalInfo(status), days(days) {}
    double totalCost()
    {
        return days * rentalPricePerDay;
    }
    void display()
    {
        cout << "-----DETAILS-----" << endl;
        cout << "VEHICLE ID: " << vehicleID << endl
             << "MODEL: " << model << endl
             << "STATUS: " << status << endl
             << "TOTAL COST: " << totalCost();
    }
};
int main()
{
    RentalVehicle r1(432, "Corolla", "available", 7);
    r1.totalCost();
    r1.display();
    return 0;
}

*HIERARCHICAL: where one parent has many children
class Staff
{
public:
    int staffID;
    string name;
    double baseSalary;
public:
    Staff(int id, string n, double bs)
        : staffID(id), name(n), baseSalary(bs) {}
    double CalculateBaseSalary()
    {
        return baseSalary + 2000;
    }
    void DisplayDetails()
    {
        cout &lt;&lt; &quot;Staff ID: &quot; &lt;&lt; staffID &lt;&lt; endl;
        cout &lt;&lt; &quot;Name: &quot; &lt;&lt; name &lt;&lt; endl;
        cout &lt;&lt; &quot;Base Salary with Allowance: &quot; &lt;&lt;
CalculateBaseSalary() &lt;&lt; endl;
    }
};
class Driver : public Staff
{
private:
    int tripsCompleted;
public:
    Driver(int id, string n, double bs, int trips)
        : Staff(id, n, bs), tripsCompleted(trips) {}
    double CalculateBonus()
    {
        return tripsCompleted * 500;
    }
    void DisplayDetails()

    {
        Staff::DisplayDetails();
        cout &lt;&lt; &quot;Trips Completed: &quot; &lt;&lt; tripsCompleted &lt;&lt; endl;
        cout &lt;&lt; &quot;Bonus: &quot; &lt;&lt; CalculateBonus() &lt;&lt; endl;
        cout &lt;&lt; &quot;Total Salary: &quot; &lt;&lt; CalculateBaseSalary() +
CalculateBonus() &lt;&lt; endl;
    }
};
class Loader : public Staff
{
private:
    int itemsHandled;
public:
    Loader(int id, string n, double bs, int items)
        : Staff(id, n, bs), itemsHandled(items) {}
    double CalculateBonus()
    {
        return itemsHandled * 200;
    }
    void DisplayDetails()
    {
        Staff::DisplayDetails();
        cout &lt;&lt; &quot;Items Handled: &quot; &lt;&lt; itemsHandled &lt;&lt; endl;
        cout &lt;&lt; &quot;Bonus: &quot; &lt;&lt; CalculateBonus() &lt;&lt; endl;
        cout &lt;&lt; &quot;Total Salary: &quot; &lt;&lt; CalculateBaseSalary() +
CalculateBonus() &lt;&lt; endl;
    }
};
int main()
{
    Driver driver1(101, &quot;Alice&quot;, 30000, 10);
    Loader loader1(102, &quot;Bob&quot;, 25000, 50);
    cout &lt;&lt; &quot;Driver Details:&quot; &lt;&lt; endl;

    driver1.DisplayDetails();
    cout &lt;&lt; endl;
    cout &lt;&lt; &quot;Loader Details:&quot; &lt;&lt; endl;
    loader1.DisplayDetails();
    return 0;
}

*HYBRID : inbreeding
*TO PREVENT AMBIGUITY WITHOUT USING VIRTUAL, USE SCOPE RESOLUTION
*EXAMPLE -->

class Animal
{
public:
    string name;
    Animal() {}
    Animal(string name) : name(name) {}
    void describe()
    {
        cout << "I am " << name << endl;
    }
};
class FlyingCreature : public Animal
{

public:
    int max_Altitude;
    FlyingCreature() {}
    FlyingCreature(string n1, int max) : Animal(n1), max_Altitude(max) {}
    void fly()
    {
        cout << "The max altitude is: " << max_Altitude << endl;
    }
};
class SwimCreature : public Animal
{
public:
    int max_depth;
    SwimCreature() {}
    SwimCreature(string n1, int max) : Animal(n1), max_depth(max) {}
    void swim()
    {
        cout << "The max depth is: " << max_depth << endl;
    }
};

class Duck : public FlyingCreature, public SwimCreature
{
public:
    Duck() {}
    Duck(string n1, string n2, int maxA, int maxD) : FlyingCreature(n1, maxA), SwimCreature(n2, maxD) {}
};
int main()
{
    Duck d("Sparrow", "Duck", 45, 56);
    d.FlyingCreature::describe();
    d.fly();
    d.SwimCreature::describe();
    d.swim();
}

*DIAMOND PROBLEM:

!virtual in inheritance:
class Light : public virtual Device {};
*This is about memory layout. Tells the compiler to share one Device subobject instead of duplicating it. Diamond problem solver.
!virtual on functions:
virtual void turnOn() { ... }
*This is about runtime dispatch. Tells the compiler to call the correct overridden version when accessed through a base pointer.
Device* d = &L;
d->turnOn();  //* calls Light::turnOn() if overridden, not Device::turnOn()
*Without virtual on the function, it would call Device::turnOn() regardless of the actual object type.
*The virtual on functions (turnOn, turnOff) is independent — you keep those regardless of which inheritance structure you use. They solve a completely different problem.
*/

/* //! ARRAY OF OBJECTS
 *Can be initialized in two ways:
 *----without default constructor----
Laptop laptops[] = { Laptop("HP", 8), Laptop("Dell", 16), Laptop("Asus", 32) };

*----with default constructor----
Laptop() : brandname("Unknown"), price(0.0) {};   //*constructor
Laptop laptops[3];      //* then in main

*default Constructor is Required if the elements of the array need to be automatically initialized without specifying parameters.
*Explicit Initialization is used If you initialize each object with parameters, then you can avoid the need for a default constructor.


 */

/* //! COMPOSITION AND AGGREGATION
*Objects can be created in classes using composition and aggregation.
*Distinction between composition and aggregation is lifecycle of object.
*COMPOSITION: If object of a class is dependent on another class, it has strong relationship with object
*AGGREGATION: If object is independent it is aggreg and has a weak relationship with class. It can stay alive even if the class is destroyed because a reference is passed as object in it.
*Aggregation uses pointers/adresses

*In aggregation, objects can be initialized using constructors through several ways:
class Student {
public:
    int id;
    string name;
    Laptop *L; //* Pointer to a Laptop

    Student(int id, string name, Laptop *Lap) {
        this->id = id;
        this->name = name;
        this->L = Lap; //* Assign Laptop pointer
    }

        *IF USING MEMBER INITIALIZATION LIST,
    Student(int id, string name, Laptop *Lap) : Lap(L) {}
    *then in main, use "->" when using any members of Laptop.

        *IF USING REFERENCE,
    class Student {
    public:
    int id;
    string name;
    Laptop &L;

    Student(int id, string name, Laptop &Lap) : id(id), name(name), L(Lap) {}
    *then in main, use "." when using any members of Laptop.

    *------------WAYS TO DISPLAY DETAILS:-----------
*USING REF &
    Laptop lap1("HP", 8, 4000);
    Laptop lap2("Dell", 8, 6000);
    Student s1(501, "Ahlele", lap1);
    Student s2(502, "Ahlelas", lap2);

*USING POINTERS
    Laptop lap1("HP", 8, 4000);
    Laptop lap2("Dell", 8, 6000);
    Student s1(501, "Ahlele", &lap1);
    Student s2(502, "Ahlelas", &lap2);

*USING DMA with POINTERS
    Laptop *lap1 = new Laptop("HP", 8, 4000);
    Laptop *lap2 = new Laptop("Dell", 8, 6000);
    Student s1(501, "Ahlele", lap1);
    Student s2(502, "Ahlelas", lap2);
    delete lap1;
    delete lap2;


 */

/* //! STATIC
 *Static means:
 * 1. Belongs to the class not to any object 2.Exists even if zero objects exist
 *So if you want to display it without creating an object, you use a static member function.
 *Because static functions: Don’t need an object, Can only access static members
 *STATIC MEMBER FUNCTION SYNTAX:
 *static return_type func_name() {}
 *static is mostly used to count how many objects have been created.
? a class Machine which has id, constant base Hours as parameters, counts how many machines if base hours > 5 and calculates efficiency for each machine.
 class Machine
{
public:
    int id;
    const double baseHours;
    static int runningMachines;
    Machine(int id, double baseHours) : baseHours(baseHours)
    {
        this->id = id;
        if (baseHours > 5)
        {
            runningMachines++;
        }
    }
    void calculateEfficiency(double extraHours)
    {

        double efficiency = (baseHours + extraHours) * runningMachines;
        cout << "Efficiency: " << efficiency << endl;
        cout << "----------------------" << endl;
    }
    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Base Hours: " << baseHours << endl;
    }
    static void runningmachines_display()
    {
        cout << "Running machines: " << runningMachines << endl;
    }
    ~Machine()
    {

        if (baseHours > 5)
            runningMachines--;
        cout << "Destruction occured :(" << endl;
    }
};
int Machine::runningMachines = 0;
int main()
{
    Machine m1(501, 8.0);
    double extra;
    cout << "Enter extra hours for machine " << m1.id << ": ";
    cin >> extra;
    m1.display();
    m1.calculateEfficiency(extra);
    Machine m2(502, 6.5);
    cout << "Enter extra hours for machine " << m2.id << ": ";
    cin >> extra;
    m2.display();
    m2.calculateEfficiency(extra);

    Machine m3(503, 10.0);
    cout << "Enter extra hours for machine " << m3.id << ": ";
    cin >> extra;
    m3.display();
    m3.calculateEfficiency(extra);

    Machine m4(504, 4.5);
    cout << "Enter extra hours for machine " << m4.id << ": ";
    cin >> extra;
    m4.display();
    m4.calculateEfficiency(extra);

    Machine::runningmachines_display();
}
 */

/* //! STATIC EXAMPLE 2
class User
{
public:
    static int totalUsers;
    int id;
    string name;
    const int accessLevel;
    bool wasCounted;

    User(int id, string name, int accessLevel) : accessLevel(accessLevel)
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
*/

/* //! DMA WITH CLASSES
?An administrator is responsible for creating, managing, and deleting user accounts. Each user
?must have an ID, name, password, and role (Admin, User, or Guest).
?Requirements:
?Implement a User class with attributes: ID, name, password, and role.
?Use constructor overloading to create users with or without an assigned role.
?Store user records in an array (dynamic memory allocation using pointers).
?Implement password validation (length, special character check).
class User
{
public:
    int id;
    string name;
    string password;
    string role;

    User() : id(0), name(""), password(""), role("Guest") {}

    User(int id, string name, string password)
        : id(id), name(name), password(password), role("Guest") {}

    User(int id, string name, string password, string role)
        : id(id), name(name), password(password), role(role) {}
};

class UserManager
{
private:
    User *users;
    int userCount;
    int capacity;
    int nextId;

    int findIndex(int id)
    {
        for (int i = 0; i < userCount; i++)
            if (users[i].id == id)
                return i;
        return -1;
    }

public:
    UserManager(int capacity) : capacity(capacity), userCount(0), nextId(1)
    {
        users = new User[capacity];
    }

    ~UserManager()
    {
        delete[] users;
    }

    void addUser()
    {
        if (userCount >= capacity)
        {
            cout << "Capacity full. Cannot add more users.\n";
            return;
        }

        string name, password, role;
        int flag;

        cout << "NAME: ";
        cin >> name;
        cout << "PASSWORD: ";
        cin >> password;
        cout << "Assign role? (1 = custom, 0 = Guest): ";
        cin >> flag;

        if (flag == 1)
        {
            cout << "ROLE (Admin/User/Guest): ";
            cin >> role;
            if (role != "Admin" && role != "User" && role != "Guest")
            {
                cout << "Invalid role. Defaulting to Guest.\n";
                role = "Guest";
            }
            users[userCount] = User(nextId++, name, password, role);
        }
        else
        {
            users[userCount] = User(nextId++, name, password);
        }

        userCount++;
        cout << "User added. Assigned ID: " << users[userCount - 1].id << "\n";
    }

    void removeUser()
    {
        if (userCount == 0)
        {
            cout << "No users to remove.\n";
            return;
        }

        int id;
        cout << "Enter ID to remove: ";
        cin >> id;

        int idx = findIndex(id);
        if (idx == -1)
        {
            cout << "User not found.\n";
            return;
        }

        for (int j = idx; j < userCount - 1; j++)
            users[j] = users[j + 1];

        userCount--;
        cout << "User removed.\n";
    }

    void displayAll()
    {
        if (userCount == 0)
        {
            cout << "No users registered.\n";
            return;
        }

        for (int i = 0; i < userCount; i++)
        {
            cout << "\n--- USER " << i + 1 << " ---\n";
            cout << "ID       : " << users[i].id << "\n";
            cout << "NAME     : " << users[i].name << "\n";
            cout << "PASSWORD : " << users[i].password << "\n";
            cout << "ROLE     : " << users[i].role << "\n";
        }
        cout << "\n";
    }

    void changeRole()
    {
        int id, flag;
        string role;

        cout << "Enter ID to change role: ";
        cin >> id;

        int idx = findIndex(id);
        if (idx == -1)
        {
            cout << "User not found.\n";
            return;
        }

        cout << "Assign role? (1 = custom, 0 = Guest): ";
        cin >> flag;

        if (flag == 1)
        {
            cout << "ROLE (Admin/User/Guest): ";
            cin >> role;
            if (role != "Admin" && role != "User" && role != "Guest")
            {
                cout << "Invalid role. Defaulting to Guest.\n";
                role = "Guest";
            }
            users[idx].role = role;
        }
        else
        {
            users[idx].role = "Guest";
        }

        cout << "Role updated to: " << users[idx].role << "\n";
    }
};

int main()
{
    int n;
    cout << "Max users to store: ";
    cin >> n;

    UserManager manager(n);

    int choice;
    do
    {
        cout << "\n1. Add User\n2. Remove User\n3. Display All\n4. Change Role\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: manager.addUser();   break;
        case 2: manager.removeUser(); break;
        case 3: manager.displayAll(); break;
        case 4: manager.changeRole(); break;
        case 0: cout << "Exiting.\n"; break;
        default: cout << "Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}
*/

/* //! COPY CONSTRUCTORS

!         SHALLOW COPY vs DEEP COPY
Shallow copy — copies the pointer (address) both objects now point to SAME memory
Deep copy    — copies the data the pointer points to both objects have their OWN separate memory

! 1. SHALLOW COPY — what C++ does by default
class Routine {
public:
    int    count;
    int   *data;          // pointer to heap memory

    Routine(int n) {
        count = n;
        data  = new int[n];
    }
};

Routine A(3);             // A.data ──► [ 10 | 20 | 30 ]  (on heap)
A.data[0] = 10;
A.data[1] = 20;
A.data[2] = 30;

Routine B = A;            // default copy constructor fires — SHALLOW

   ? What just happened in memory:

     A.data ──────────────────► [ 10 | 20 | 30 ]
                                         ▲
     B.data ──────────────────────────── ┘

     B.data is not a copy of the array. B.data is a copy of the ADDRESS. both point to the SAME block

B.data[0] = 99;           // you think you're changing B only you just changed A.data[0] too — same memory

   ? THE DISASTER:
delete[] A.data;          // frees the memory
delete[] B.data;          // double delete — undefined behavior, crash B.data still points to freed memory


   ! 2. DEEP COPY — user-defined constructor
class Routine {
public:
    int  count;
    int *data;

       ? regular constructor
    Routine(int n) {
        count = n;
        data  = new int[n];
    }

       ? deep copy constructor
    Routine(const Routine &other) {
        count = other.count;
        data  = new int[count];          // allocate NEW separate block
        for (int i = 0; i < count; i++)
            data[i] = other.data[i];     // copy the VALUES, not the address
    }

       ? destructor — always write this when you have heap memory
    ~Routine() {
        delete[] data;
    }
};

Routine A(3);
A.data[0] = 10;
A.data[1] = 20;
A.data[2] = 30;

Routine B = A;            // deep copy constructor fires now

   ? What happens in memory:
     A.data ──► [ 10 | 20 | 30 ]   (block 1)

     B.data ──► [ 10 | 20 | 30 ]   (block 2 — separate allocation)

     two pointers, two blocks, same values

B.data[0] = 99;               only changes B's block. A.data[0] is still 10

delete[] A.data;          // frees block 1 — fine
delete[] B.data;          // frees block 2 — fine, separate memory


   ! COPY CONSTRUCTOR SYNTAX — breakdown
Routine(const Routine &other)
            passes by reference — no copy made of other
            const — guarantees you won't modify the source

   ! SIDE BY SIDE
     ┌──────────────────┬────────────────────────┬──────────────────────────┐
     │                  │     Shallow Copy       │       Deep Copy          │
     ├──────────────────┼────────────────────────┼──────────────────────────┤
     │ What's copied    │ the address (pointer)  │ the actual data          │
     │ Separate memory? │ no — shared block      │ yes — own block          │
     │ Change B affects │ A too                  │ only B                   │
     │ Delete risk      │ double delete = crash  │ safe, independent        │
     │ Who writes it    │ compiler (default)     │ you                      │
     └──────────────────┴────────────────────────┴──────────────────────────┘

   ! THE ONE RULE
     if your class has a RAW POINTER as a member
     → always write deep copy constructor + destructor

     if your class has NO pointers (just ints, strings, plain members)
     → default shallow copy is fine, no shared memory to worry about

*COPY CONSTRUCTOR IS CALLED WHEN object is initialized or copied, a value is passed to a function or a function returns some value.
*/
/*//! SHALLOW COPY WIHTOUT USING ANY COPY CONSTRUCTOR
class Book
{
private:
    string title;
    const int id;

public:
    Book(string title, int id) : title(title), id(id) {}

    string getTitle()
    {
        return title;
    }

    int getid()
    {
        return id;
    }
    void display()
    {
        cout << "TTILE: " << title << endl;
        cout << "ID: " << id << endl;
    }
};
int main()
{
    Book b1("OOP GUIDE", 101);
    Book b2 = b1;
    b2.display();
}
*/

/* //! DEEP COPY EXAMPLE
class Library {
private:
    int size;
    int* books;

public:
* Parameterized constructor
    Library(int s) : size(s) {
        books = new int[size];      //* Allocate memory for books

* Initialize books with some default values (optional)
        for (int i = 0; i < size; ++i) {
            books[i] = 0;
        }
    }

* Destructor
    ~Library() {
        delete[] books;
    }

//*    Deep Copy constructor
    Library(const Library& otherbook) : size(otherbook.size) {      //*since its in private otherwise do size = otherbook.size
        books = new int[size];              //* Allocate new memory for books
        //* Perform deep copy using a loop
        for (int i = 0; i < size; ++i) {
            books[i] = otherbook.books[i];
        }
    }
};
*/

/* //! CONSTRUCTOR III
?Create a generalized class named Vehicle with public mems make and model and displayInfo(). create a
?specialized class Car that inherits from Vehicle. The Car class should have a public memb engineType
?and its own displayInfo() method that calls the base class method and then prints the engineType.
* Gen = base, spec = derived
* when creating classes with constructors,
*SYNTAX OF BASE CLASS: Constructor_name (data_type var,...) : att_name(var),... {}
*SYNTAX OF DERIVED CLASS:
* Constructor_name(data_type var,...) : base_att_name(var),..., att_name(var){}
! if use methods and want to access members of base class
* SYNTAX: func_name(){
*base_Class_name :: base_func_name; }

class Vehicle
{
public:
    string make;
    string model;

    Vehicle(string ma, string mo) : make(ma), model(mo) {}
    void displayInfo()
    {
        cout << "Make: " << make << endl
             << "Model: " << model << endl;
    }
};

class Car : public Vehicle
{
public:
    string engineType;
    Car(string ma, string mo, string eng) : Vehicle(ma, mo), engineType(eng) {}
    void displayInfo()
    {
        Vehicle::displayInfo();
        cout << "Engine type: " << engineType << endl;
    }
};

int main()
{
    Vehicle v("Ford", "Mustang");
    v.displayInfo();
    cout << endl;
    Car c("Toyota", "Camry", "V-type");
    c.displayInfo();
    return 0;
}*/

/* //! CONSTRUCTOR II
/*
?Define a Concrete class with private string data member message. should have a constructor
?that takes string as argument and initializes the message data member. have a public
?func that prints the stored message. A concrete class provides an implementation for all of its methods.
* to use a priv member in public as an argument in a constructor, use ""member initialization list"
*SYNTAX : Constructor_name(return_type var_name) : private_Att(var_name){};
* TO CALL IT : Constructor_name obj_name(var);

using namespace std;
class Concrete
{
private:
    string message;

public:
    Concrete(string s) : message(s) {
    }
    void displayMessage()
    {
        cout << message << endl;
    }
};
int main()
{
    string m;
    m = "This is a message";
    Concrete c(m);
    c.displayMessage();
}
*/

/*//! Constructor

//*"this" keyword is only used if both the arguments passed in constructors and attribute names are exaclty the same. Otherwise, use them normally when equating.
class Student
{
public:
    string name;
    int age;
    double gpa;
    Student(string name, int age, double gpa)
    {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }
};
int main()
{
    Student s1("Sam", 25, 1.9);
    Student s2("John", 33, 1.99);
    cout << "name: " << s2.name << endl;
    cout << "age: " << s2.age << endl;
    cout << "gpa: " << s2.gpa << endl;
}
/*
? A school wants to print report cards for different types of students. Create a base class Student with a variable name and a virtual
? function showResult() that prints"General student result".Create a derived class ScienceStudent that
? overrides showResult() to print "Science studentresult: Physics-90, Chemistry-85".
?Create another derived class ArtsStudent that overrides showResult() to print "Arts studentresult: History-88, Literature-92".
?Task:Create objects for ScienceStudent and ArtsStudent. Use a Student* pointer array to call showResult() for each student.
class Student
{
public:
    int var;
    virtual void showresult()
    {
        cout << "General student result\n";
    }
};
class sci_Student : public Student
{
public:
    void showresult() override
    {
        cout << "Science studentresult: Physics-90, Chemistry-85\n";
    }
};
class art_student : public Student
{
public:
    void showresult() override
    {
        cout << "Arts studentresult: History-88, Literature-92\n";
    }
};
int main()
{
    Student *s;
    sci_Student s1;
    art_student s2;
    s = &s1;
    s->showresult();

    s = &s2;
    s->showresult();

    return 0;
}

/*
? Create a class Car with the following private data members:
? string brand
? int mileage
? Make these members accessible in main() using getters and setters

! GETTER/SETTER + ENCAPSULATION
*/
/*
class Car
{
private:
    string brand;
    int mileage;

public:
    string getbrand()
    {
        return brand;
    }

    int getmileage()
    {
        return mileage;
    }

    void setbrand(string b)
    {
        brand = b;
    }
    void setmileage(int m)
    {
        mileage = m;
    }

    int drive(int km)
    {
        if (km < 0)
        {
            cout << "No negative values allowed!";
            exit(0);
        }
        else
        {
            mileage += km;
        }
    }

    int service()
    {
        mileage = 0;
        return mileage;
    }
};

int main()
{
    Car c;
    string brand;
    int mileage;
    cout << "Brand name: ";
    cin >> brand;
    c.setbrand(brand);

    cout << "Mileage: ";
    cin >> mileage;
    c.setmileage(mileage);

    int km;
    cout << "Enter km: ";
    cin >> km;

    if (mileage < 10000)
    {
        c.drive(km);
    }
    else
    {
        c.service();
    }

    cout << "Brand name: " << c.getbrand() << endl;
    cout << "Mileage: " << c.getmileage() << endl;
}*/
/* //! NORMAL

?An online store wants to calculate discounts for different orders. Create a Discount
?class with a function applyDiscount().Overload applyDiscount() as follows:
?One version takes 2 items and returns 10% discount on the total. Another version
?takes 3 items and returns 15% discount on the total. Task: Create a Discount object
?and call both functions with sample prices. Display the discounted amount for each case.
class Discount
{
public:
    double applyDiscount(double a, double b)
    {
        double total = a + b;
        double discount = total - (total * 0.10);
        return discount;
    }

    double applyDiscount(double a, double b, double c)
    {
        double total = a + b + c;
        double discount = total - (total * 0.15);
        return discount;
    }
};

int main()
{
    Discount d;
    double two = d.applyDiscount(100, 200);
    double three = d.applyDiscount(100, 200, 300);
    cout << "Two items: " << two << endl;
    cout << "three items: " << three << endl;

    return 0;
}*/

/* //! WITH VIRTUAL + OVERRIDIN
 class Animal {
  public:
    virtual void sound() {   //*Use virtual only in the base class
      cout << "Animal sound\n";
    }
};

class Dog : public Animal {
  public:
    void sound() override {  //*Use override (optional, but recommended) in the derived class


      cout << "Dog barks\n";
    }
};

int main() {
  Animal* a;
  Dog d;
  a = &d;
  a->sound(); //* Outputs: Dog barks
  return 0;
}
  */

/* //! WITHOUT VIRTUAL
 class Animal {
  public:
    void sound() {
      cout << "Animal sound\n";
    }
};

class Dog : public Animal {
  public:
    void sound() {
      cout << "Dog barks\n";
    }
};

int main() {
  Animal* a;  //* Declare a pointer to the base class (Animal)
  Dog d;  //* Create an object of the derived class (Dog)
  a = &d;  //* Point the base class pointer to the Dog object
  a->sound(); //* Call the sound() function using the pointer. Since sound() is not virtual, this calls Animal's version
  return 0;
}
*/

/* //! DMA
! syntax for DMA --> pointer_name = new return_type 'or' return_type[size];
int main(){
char *gradesptr = NULL; //good practice to first take it as null

*size
int n;
cout<<"How many grades do u want: "   ;
cin>>n;
gradesptr = new char[n];

* array input & output
for(int i = 0; i < n; i++){
    cout<<"Enter grade num: "<<i+1<<": ";
    cin>>gradesptr[i];
}
for(int i = 0; i < n; i++){
    cout<<gradesptr[i]<<" ";
}
* for deleting array, add [] in front of delete.
delete[] gradesptr;
}
*/