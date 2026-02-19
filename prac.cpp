#include <iostream>
#include <string>
#include <cmath>
using namespace std;

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
    string name, password, role;

    User(int i, string n, string p, string r)
    {
        id = i;
        name = n;
        password = p;
        role = r;
    }

    User(int i, string n, string p)
    {
        id = i;
        name = n;
        password = p;
        role = "Guest";
    }

    bool correctp(string p)
    {
        bool special = false;
        if (p.length() < 8)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < p.length(); i++)
            {
                if (!isalnum(p[i]))
                {
                    special = true;
                    break;
                }
            }
            return special;
        }
    }

* default constructor for dma. since user-made constructors have args, a custom default is made so that during
* dma, the ocnstructor can exist without parameters.
    User()
    {
        id = 0;
        name = "";
        password = "";
        role = "Guest";
    }
};
int main()
{
    int n;
    cout << "Enter number of users: ";
    cin >> n;
    User *users;
    users = new User[n];
    * normally when we use constructors, we directly initialize. But in the case of 'taking input', we
    * declare vars, use simple looping to take input and then pass them to constructors.
    int id;
    string name, password, role;
    int flag;
    for (int i = 0; i < n; i++)
    {
        cout << "Person " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> id;
        cout << "NAME: ";
        cin >> name;
        while (true)
        {
            cout << "PASSWORD: ";
            cin >> password;

            if (users[i].correctp(password))
                break;

            cout << "Password invalid! Must be at least 8 chars and include a special character.\n";
        }

        cout << "Do you want to enter a role(enter 1) or use default role(enter 0)?: ";
        cin >> flag;
        if (flag == 1)
        {
            cout << "ROLE: ";
            cin >> role;
            users[i] = User(id, name, password, role);  //*constructor args being passed
        }
        else
        {
            users[i] = User(id, name, password);
        }
        cout << "----------------------------\n";
    }


* printing
*here we print using syntax --> obj_name[i].att_name
    for (int i = 0; i < n; i++)
    {
        cout << "User " << i + 1 << ":\n";
        cout << "ID: " << users[i].id << "\n";
        cout << "Name: " << users[i].name << "\n";
        cout << "Password: " << users[i].password << "\n";
        cout << "Role: " << users[i].role << "\n";
        cout << "----------------------------\n\n";
    }

    delete[] users;
}*/

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
* to use a priv member in public as an argument in a constructor,
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

/* //! INHERITANCE
?A company has employees. Create a base class Employee with name and salary.
?Create a derived class Manager that adds department and a function
?displayManager() toshow all details. Task: Create a Manager object and display all
?details using the  functions.


class Employee
{
public:
    string name;
    double salary;
};
class Manager : public Employee
{
public:
    string department;
    void display()
    {
        cout << "\n\n-------INFORMATION:-------\n";
        cout << "\tName: " << name << endl;
        cout << "\tSalary: " << salary << endl;
        cout << "\tDepartment: " << department << endl;
    }
};

int main()
{
    Manager m;

    cout << "Enter your name: ";
    cin >> m.name;
    cout << "Enter your salary: ";
    cin >> m.salary;
    cout << "Enter your department: ";
    cin >> m.department;
    m.display();

    return 0;
}*/

/* //! INHERITANCE
?Create a derived class Car that adds a variable fuelType and a function showCarInfo()
?to display all details. Task: Create a Car object, set all values, and call both functions.

* SYNTAX FOR CREATING DERIVED CLASS:
* class class_name{
*public: };
* class class_name2 : public class_name{
* public: }

class A
{
public:
};

class Car : public A
{
public:
    char fueltype;
    void carinfo()
    {
        cout << "fuel type: " << fueltype << endl;
    }
};
int main()
{
    Car c;
    cout << "Enter fuel type: ";
    cin >> c.fueltype;
    c.carinfo();
    return 0;
}*/

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