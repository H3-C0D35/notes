#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
/*
**Problem:**

A company has employees. Some are `Developers`, some are `Managers`, some are `TechLead` (both).

```
Employee
├── Developer
├── Manager
└── TechLead (inherits both)
```

- `Employee`: has `name`, `baseSalary`. Has a virtual method `getSalary()` that returns `baseSalary`.
- `Developer`: adds `projectBonus`. Overrides `getSalary()` to include it.
- `Manager`: adds `teamBonus`. Overrides `getSalary()` to include it.
- `TechLead`: inherits both. Overrides `getSalary()` to include all three.
*/
class Employee
{
public:
    string name;
    int baseSalary;
    Employee(string name, int baseSalary) : name(name), baseSalary(baseSalary) {}
    virtual void getSalary() { cout << "Employee: " << baseSalary << endl; }
};
class Developer : virtual public Employee
{
    int projectBonus;

public:
    Developer(string name, int baseSalary, int p) : Employee(name, baseSalary), projectBonus(p) {}
    void getSalary() override
    {
        cout << "Developer: " << baseSalary << endl;
    }
};
class Manager : virtual public Employee
{
    int teamBonus;

public:
    Manager(string name, int baseSalary, int t) : Employee(name, baseSalary), teamBonus(t) {}
    void getSalary() override
    {
        cout << "Manager: " << baseSalary << endl;
    }
};
class TechLead : public Developer, public Manager
{
public:
    TechLead(string name, int baseSalary, int p, int t) : Employee(name, baseSalary), Developer(name, baseSalary, p), Manager(name, baseSalary, t) {}
    void getSalary() override
    {
        cout << "Techlead: " << baseSalary << endl;
    }
};
int main()
{
    Employee *e[3];
    e[0] = new Developer("John", 12000, 3000);
    e[1] = new Manager("Doe", 15000, 1000);
    e[2] = new TechLead("Alice", 20000, 3000, 1000);
    for (int i = 0; i < 3; i++)
    {
        e[i]->getSalary();
    }
}

/*
----CLAUDE EX
*/
class Animal
{
public:
    string name;
    Animal(string n) : name(n) {}
    virtual void speak() // virtual function
    {
        cout << name << " makes a sound" << endl;
    }
};

class Flyable : virtual public Animal // virtual base class
{
public:
    Flyable(string n) : Animal(n) {}
    virtual void fly()
    {
        cout << name << " is flying" << endl;
    }
};

class Swimmable : virtual public Animal // virtual base class
{
public:
    Swimmable(string n) : Animal(n) {}
    virtual void swim()
    {
        cout << name << " is swimming" << endl;
    }
};

class Duck : public Flyable, public Swimmable
{
public:
    Duck(string n) : Animal(n), Flyable(n), Swimmable(n) {}
    void speak() override // overrides Animal's virtual function
    {
        cout << name << " says Quack" << endl;
    }
};

int main()
{
    Duck d("Donald");
    d.speak();
    d.fly();
    d.swim();

    Animal *a = &d;
    a->speak();
}

/*---VIRTUAL CLASS EX*/
class Staff
{
public:
    int id;
    string name;
    int baseSalary;
    Staff(int id, string name, int baseSalary) : id(id), name(name), baseSalary(baseSalary) {}
    int calculatebaseSalary()
    {
        return baseSalary + 3000;
    }
};
class Doctor : public virtual Staff
{
public:
    int patientsTreated;
    Doctor(int id, string name, int baseSalary, int patientsTreated) : Staff(id, name, baseSalary), patientsTreated(patientsTreated) {}
    int dbonus() { return patientsTreated * 500; }
};
class Nurse : public virtual Staff
{
public:
    int hours;
    Nurse(int id, string name, int baseSalary, int hours) : Staff(id, name, baseSalary), hours(hours) {}
    int nbonus() { return hours * 200; }
};
class HeadNurse : public Doctor, public Nurse
{
public:
    HeadNurse(int id, string name, int baseSalary, int patientsTreated, int hours) : Staff(id, name, baseSalary), Doctor(id, name, baseSalary, patientsTreated), Nurse(id, name, baseSalary, hours) {}
    int Total()
    {
        return calculatebaseSalary() + dbonus() + nbonus();
    }
    void display()
    {
        cout << id << endl
             << name << endl
             << baseSalary << endl
             << patientsTreated << endl
             << hours << endl
             << "staff: " << calculatebaseSalary() << endl
             << "dbonus: " << dbonus() << endl
             << "nbonus" << nbonus() << endl
             << "total: " << Total();
    }
};
int main()
{
    HeadNurse h(101, "John", 56000, 100, 5);
    h.calculatebaseSalary();
    h.dbonus();
    h.nbonus();
    h.Total();
    h.display();
}

/* COMP / AGGREG*/
class Device
{
    int id;
    int rating;
    int hours;

public:
    Device() {}
    Device(int id, int rating, int hours) : id(id), rating(rating), hours(hours) {}
    double Dailyenergy()
    {
        return rating * hours;
    }
    void display()
    {
        cout << "Device ID: " << id << " | Rating: " << rating << " | Hours: " << hours << " | Daily Energy: " << Dailyenergy() << endl;
    }
};
class Room
{
    Device *devices;
    int size;

public:
    Room() : size(0), devices(nullptr) {}
    Room(int size, Device *d) : size(size)
    {
        devices = new Device[size];
        for (int i = 0; i < size; i++)
        {
            devices[i] = d[i];
        }
    }
    double Totalenergy()
    {
        double total = 0;
        for (int i = 0; i < size; i++)
        {
            total += devices[i].Dailyenergy();
        }
        return total;
    }
    void display()
    {
        cout << "Room Devices:" << endl;
        for (int i = 0; i < size; i++)
            devices[i].display();
        cout << "Room Total Energy: " << Totalenergy() << endl;
    }
};
class House
{
    int id;
    string owner;
    Room *room;
    int size;

public:
    House() : id(0), owner(""), room(nullptr), size(0) {}
    House(int id, string owner, int size, Room *r) : id(id), owner(owner), size(size)
    {
        room = new Room[size];
        for (int i = 0; i < size; i++)
        {
            room[i] = r[i];
        }
    }
    double Houseenergy()
    {
        double total = 0;
        for (int i = 0; i < size; i++)
        {
            total += room[i].Totalenergy();
        }
        return total;
    }
    void display()
    {
        cout << "House ID: " << id << " | Owner: " << owner << endl;
        for (int i = 0; i < size; i++)
            room[i].display();
        cout << "House Total Energy: " << Houseenergy() << endl;
    }
};
int main()
{
    Device d1[] = {Device(101, 5, 6), Device(102, 2, 7)};
    Device d2[] = {Device(103, 8, 3), Device(104, 5, 4)};
    Room room[] = {Room(2, d1), Room(2, d2)};
    House h1(492, "John", 2, room);
    h1.display();
}

/*AGREG*/
class Laptop
{
public:
    string brand;
    int size;
    int battery;
    Laptop() : brand(""), size(0), battery(0) {}
    Laptop(string brand, int size, int battery) : brand(brand), size(size), battery(battery) {}
    double Time()
    {
        return (double)battery / (double)(size * 500);
    }
};

class Student
{
    int id;
    string name;
    Laptop *L;

public:
    Student() : id(0), name(""), L(nullptr) {}
    Student(int id, string name, Laptop *L) : id(id), name(name), L(L) {}
    void display()
    {
        cout << "ID: " << id << endl
             << "NAME: " << name << endl;
        cout << "BRAND: " << L->brand << endl;
        cout << "SIZE: " << L->size << endl;
        cout << "BATTERY: " << L->battery << endl;
        cout << "TIME: " << L->Time();
    }
};
int main()
{
    Laptop l1("Dell", 5, 6);
    Student s1(101, "John", l1);
    l1.Time();
    s1.display();
}
/*COMP */
class Laptop
{
public:
    string brand;
    int size;
    int battery;
    Laptop() : brand(""), size(0), battery(0) {}
    Laptop(string brand, int size, int battery) : brand(brand), size(size), battery(battery) {}
    double Time()
    {
        return (double)battery / (double)(size * 500);
    }
};

class Student
{
    int id;
    string name;
    Laptop L;

public:
    Student() : id(0), name("") {}
    Student(int id, string name, Laptop L) : id(id), name(name), L(L) {}
    void display()
    {
        cout << "ID: " << id << endl
             << "NAME: " << name << endl;
        cout << "BRAND: " << L.brand << endl;
        cout << "SIZE: " << L.size << endl;
        cout << "BATTERY: " << L.battery << endl;
        cout << "TIME: " << L.Time();
    }
};
int main()
{
    Laptop l1("Dell", 5, 6);
    Student s1(101, "John", l1);
    l1.Time();
    s1.display();
}
/*
o Data members: student ID, name, and a Laptop object.
o A constructor to initialize all data members (including laptop details).
o A member function to display complete student information, including laptop
details and calculated battery backup time.

3. In the main() function:
o Create at least two Student objects with different laptop configurations.
o Display their complete information using the display function.*/

class Course
{
    string title;
    int hrs;

public:
    Course() : title(""), hrs(0) {}
    Course(string title, int hrs) : title(title), hrs(hrs) {}
    Course(const Course &obj)
    {
        hrs = obj.hrs;
        title = obj.title;
    }
    ~Course() {}
    void display()
    {
        cout << title << endl
             << hrs << endl;
    }
};
class Teacher
{
    string name;
    string subj;
    Course *course;

public:
    Teacher() : name(""), subj(""), course(nullptr) {}
    Teacher(string name, string subj, Course c) : name(name), subj(subj)
    {
        course = new Course(c);
    }
    Teacher(const Teacher &obj) : name(obj.name), subj(obj.subj)
    {
        course = new Course(*obj.course);
    }
    ~Teacher()
    {
        delete course;
    }
    void display()
    {
        cout << name << endl
             << subj << endl;
        if (course)
            course->display();
    }
};
class School
{
    Teacher *teacher;
    int size;

public:
    School(int size) : size(size)
    {
        teacher = new Teacher[size];
    }
    School(const School &obj) : size(obj.size)
    {
        teacher = new Teacher[size];
        for (int i = 0; i < size; i++)
        {
            teacher[i] = obj.teacher[i];
        }
    }
    ~School()
    {
        delete[] teacher;
    }
    void setTeacher(string name, string subj, Course c, int i)
    {
        teacher[i] = Teacher(name, subj, c);
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "---T " << i + 1 << endl;
            teacher[i].display();
        }
    }
};
int main()
{
    Course c1("Math", 3);
    Course c2("Science", 2);
    School s1(2);
    s1.setTeacher("John", "Physics", c1, 0);
    s1.setTeacher("Doe", "OOP", c2, 1);
    School s2(s1);
    s1.display();
    s2.display();
}

/* COPY CONSTRUCTOR EX*/
class Patient
{
    string name;
    string diagnosis;

public:
    Patient() : name(""), diagnosis("") {}
    Patient(string n, string d) : name(n), diagnosis(d) {}
    Patient(const Patient &obj)
    {
        name = obj.name;
        diagnosis = obj.diagnosis;
    }
    ~Patient() {}
    void display()
    {
        cout << name << endl
             << diagnosis << endl;
    }
};
class Hospital
{
    Patient *patient;
    int size;

public:
    Hospital(int size) : size(size)
    {
        patient = new Patient[size];
    }
    Hospital(const Hospital &obj) : size(obj.size)
    {
        patient = new Patient[size];
        for (int i = 0; i < size; i++)
        {
            patient[i] = obj.patient[i];
        }
    }
    ~Hospital()
    {
        delete[] patient;
    }
    void setpatient(int i, string name, string diag)
    {
        patient[i] = Patient(name, diag);
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            patient[i].display();
        }
    }
};
int main()
{
    Hospital h1(3);
    h1.setpatient(0, "John", "Cancer");
    h1.setpatient(1, "Doe", "TB");
    h1.setpatient(2, "ALice", "Hepetitis");
    Hospital h2(h1);
    h1.setpatient(0, "John", "dead");
    h1.display();
    h2.display();
}

/* COPY CONSTRUCTOR*/
class Song
{
    char *title;

public:
    Song() : title(nullptr) {}
    Song(const char *t)
    {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
    }
    Song(const Song &obj)
    {
        title = new char[strlen(obj.title) + 1];
        strcpy(title, obj.title);
    }

    void display()
    {
        cout << title << endl;
    }
    ~Song()
    {
        delete[] title;
    }
};
class Playlist
{
    int size;
    Song *songs;

public:
    Playlist(Song *s, int size) : size(size)
    {
        songs = new Song[size];
        for (int i = 0; i < size; i++)
        {
            songs[i] = s[i];
        }
    }
    Playlist(const Playlist &obj) : size(obj.size)
    {
        songs = new Song[obj.size];
        for (int i = 0; i < size; i++)
        {
            songs[i] = obj.songs[i];
        }
    }
    void setSong(int i, Song s)
    {

        songs[i] = s;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
            songs[i].display();
    }
    ~Playlist()
    {
        delete[] songs;
    }
};
int main()
{
    Song s1[] = {Song("Candy"), Song("Roxxane")};
    Playlist p1(s1, 2);
    Playlist p2(p1);
    p1.setSong(0, Song("new"));
    cout << "P1: " << endl;
    p1.display();
    cout << endl;
    cout << "P2: " << endl;
    p2.display();
}

/*COPY CONSTRUCTOR*/

class Book
{
    char *title;
    int pages;

public:
    Book(char *t, int p) : pages(p)
    {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
    }

    Book(const Book &obj)
    {
        pages = obj.pages;
        title = new char[strlen(obj.title) + 1];
        strcpy(title, obj.title); //*can be written like this as well --> title[i] = obj.title[i] ;
    }

    ~Book()
    {
        delete[] title;
    }
    void display()
    {
        cout << title << endl;
        cout << pages << endl;
    }
};
class Author
{
    char *name;
    Book *book;

public:
    Author(char *n, Book b)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        book = new Book(b);
    }
    Author(const Author &obj)
    {
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);

        book = new Book(*obj.book);
        book = obj.book;
    }
    ~Author()
    {
        delete[] name;
        delete[] book;
    }
    void display()
    {
        cout << name;
    }
};
int main()
{
    Book b1("C++", 100);
    Author a1("Deitel", b1);
    b1.display();
    a1.display();
}

/*--------EX*/
int main()
{
    int amount;
    cin >> amount;
    int denominations[] = {5000, 1000, 500, 100, 20, 10, 5, 2, 1};

    for (int i = 0; i < 11; i++)
    {
        if (amount >= denominations[i])
        {
            int count = amount / denominations[i];
            amount %= denominations[i];
            cout << denominations[i] << " x" << count << endl;
        }
    }
}
int main()
{
    int array[3][3];
    int r = 3, c = 3;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> array[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
        {
            sum += array[j][i];
        }
        cout << sum << endl;
    }
}
int main()
{
    int array[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> array[i];
    }
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += array[i];
    }
    cout << "\nSUM: " << sum << endl;
    int size = 5;
    for (int i = 0; i < size / 2; i++)
    {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
    cout << "\nREVERSED:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << " ";
    }
}