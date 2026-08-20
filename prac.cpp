#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

/* //! QUICK SORT
#include <iostream>
using namespace std;
int partition(int arr[], int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main()
{
    int arr[] = {10, 22, 0, 2, 9, 4, 3, 9};
    int n = 8;
    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

*/

/*//! CUSTOM EXCEPTIONS

class MyException : public std::exception {
    string message;
public:
    MyException(string msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

//*USAGE
throw MyException("something went wrong");

try { ... }
catch (MyException& e) {
    cout << e.what();
}
*/

/* //!TEMPLATE
 *templates are used as data types.
 *SYNTAX --> template <typename T>
 *now T can be used as a class, func or value data type.
  T add(T a, T b){
  return a+b; }
  add<int>(5, 6); //* Specify the type of function like this --> func_name<dtype>(args);
  add<double>(9.34+6.3);
*but lets say you want different types for "T add(T a, T b)", then you declare different variables as one "T" is same across all the places its being used.
*SYNTAX-->
template<typename T>
template<typename A>
template<typename B>
T add(A a, B b){};
*then in main,
T<void, int, int>(3, 2.4);
*=======================================================================*

*with classes:
template <typename T>
class Box {
private:
    T value;

public:
    Box(T val) : value(val) {}

    T get() {
        return value;
    }

    void set(T val) {
        value = val;
    }
};

Box<int> intBox(42); //*intBox and strBox are objects. syntax when a class has T members and funcs is --> classname<dtype> obj_name;
Box<string> strBox("hello");

intBox.get();   // returns int
strBox.get();   // returns string

*multiple parameters
template <typename K, typename V>
class Pair {
public:
    K key;
    V value;

    Pair(K k, V v) : key(k), value(v) {}
};

Pair<string, int> p("age", 25);

? EXERCISE -- Making stack (push, pop, peep) using templates.
template <typename T>
class Stack
{
    T *arr;
    int capacity;
    int size;

public:
    Stack(int n) : capacity(n), size(0)
    {
        arr = new T[n];
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(T val)
    {
        if (size == capacity)
        {
            cout << "Stack is full.\n";
        }
        else
        {
            arr[size] = val;
            size++;
        }
    }
    bool isEmpty()
    {
        return size == 0;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw runtime_error("NO ELEMENTS TO POP.\n");
        }
        else
        {
            size--;
            return arr[size];
        }
    }
    T peek()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack is empty");
        }
        return arr[size - 1];
    }
};
int main()
{
    Stack<int> obj(3);
    obj.push(10);
    obj.push(20);
    obj.push(30);

    cout << "PEEK: " << obj.peek() << endl;

    cout << "POP: " << obj.pop() << endl;
    cout << "PEEK: " << obj.peek() << endl;
    cout << "POP: " << obj.pop() << endl;
    cout << "POP: " << obj.pop() << endl;
    try
    {
        obj.pop(); // stack empty — throws exception
    }
    catch (runtime_error &e)
    {
        cout << e.what() << "\n";
    }
}

?EXERCISE - QUEUE that has Enqueue(push data), Dequeue(pull data from the front/staring element), Front(display front without removing it).
template <typename T>
class Queue
{
    T *arr;
    int capacity;
    int rear;
    int front;

public:
    Queue(int c) : capacity(c), rear(0), front(0)
    {
        arr = new T[c];
    }
    void enqueue(T value)
    {
        if (rear < capacity)
        {
            arr[rear] = value;
            rear++;
        }
        else
        {
            cout << "QUEUE IS FULL\n";
        }
    }
    bool isEmpty()
    {
        return front == rear;
    }
    T dequeue()
    {
        if (!isEmpty())
            return arr[front++];

        else
            throw runtime_error("CANT DEQUEUE.\n");
    }
    T Front()
    {

        if (!isEmpty())
            return arr[front];

        else
            throw runtime_error("NO FRONT TO DISPLAY.\n");
    }
};

int main()
{
    Queue<int> obj(4);
    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.enqueue(40);
    obj.enqueue(50);
    cout << "FRONT: " << obj.Front() << endl;
    cout << "DEQUEUE: " << obj.dequeue() << endl;
    cout << "FRONT: " << obj.Front() << endl;
    cout << "DEQUEUE: " << obj.dequeue() << endl;
    cout << "DEQUEUE: " << obj.dequeue() << endl;
    cout << "DEQUEUE: " << obj.dequeue() << endl;

    try
    {
        cout << "DEQUEUE: " << obj.dequeue() << endl;
        cout << "FRONT: " << obj.Front() << endl;
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }
}


?Create a template class SmartArray: Supports dynamic array storage, Overloads the operator[] to access elements, Throws a OutOfBoundsException if the index is invalid.
?Sample Input/Output:
??Array size: 5
?Enter elements: 1 2 3 4 5
?Accessing index 2: 3
?Accessing index 5:
?OutOfBoundsException caught: Invalid index access attempted!
?template <typename T>
//*template<class T>    <-- either is correct
class SmartArray
{
    T *arr;
    int capacity;
    int size;

public:
    SmartArray(int c) : capacity(c), size(0)
    {
        arr = new T[c];
    }
    ~SmartArray()
    {
        delete[] arr;
    }
    void Input()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << "Enter the elements" << i + 1 << ": ";
            cin >> arr[size];
            size++;
        }
    }
    T &operator[](int idx) //*this is operator overloading. in main when you write objname[index], it will call this func. recap of operator overloading syntax--> dtype& operator symbol(args);
    {
        if (idx < 0 || idx >= size)
            throw runtime_error("Invalid index access attempted!");
        return arr[idx];
    }
};
int main()
{
    cout << "Enter capacity of the array: ";
    int n;
    cin >> n;
    SmartArray<int> obj(n);
    obj.Input();
    cout << "ACCESSING OBJ: " << obj[5] << endl;
}
*=====================================================================================
*TEMPLATES WITH INHERITANCE:
*CASE 1 -- Template base, normal derived
template <typename T>
class Base {
public:
T basevalue;
Base(T v) : basevalue(v) {}
void show() { cout << basevalue << "\n"; }
};

class Derived : public Base<int> {  //*T fixed to int. Can be fixed to any dtype.
int derivevalue
public:
Derived(int bv, int dv) : Base<int>(bv), derivevalue(dv) {}
};
?EXAMPLE: Template base class — Container<T> -stores a single item of type T, has getItem(), setItem().
?         Normal derived class — NamedContainer -inherits Container<string>, adds a string attribute: label, has describe() that prints label + item
template <typename T>
class Container
{
T item;

public:
Container() {}
Container(T i) : item(i) {}
T getItem()
{
    return item;
}
void setitem(T it)
{
    item = it;
}
};
class NamedContainer : public Container<string>
{
string label;

public:
NamedContainer(string l) : label(l) {}
void describe()
{
    cout << "Label: " << label << " | Item: " << getItem() << endl;
}
};
int main()
{
NamedContainer o("Y");
o.setitem("X");
o.describe();
}

*CASE 2 -- Template base, Template derived
template <typename T>
class Base {
public:
T value;
Base(T v) : value(v) {}
};

template <typename T>
class Derived : public Base<T> {  //* T passed through
public:
Derived(T v) : Base<T>(v) {}
void show() { cout << this->value << "\n"; } //* "this" is important here otherwise it wont show anything on the output screen.
};

Derived<int> d(42);
Derived<string> d2("hello");

?EXAMPLE - Template base class — Animal<T> - has a T attribute called `sound`, speak() that prints sound
?          Template derived class — Dog<T> - inherits Animal<T> - adds a method fetch() that prints "Fetching!"
template <typename T>
class Animal
{
protected:
T sound;

public:
Animal(T s) : sound(s) {}
void speak()
{
    cout << "Animal goes " << sound << endl;
}
};

template <typename T>
class Dog : public Animal<T>
{
public:
Dog(T s) : Animal<T>(s) {}
void speak()
{
    cout << "Dog goes " << this->sound << endl; //* prints woof
}

void fetch()
{
    cout << "Fetching!" << endl;
}
};
int main()
{
Animal<string> a("generic");
Dog<string> d("woof");
a.speak();
d.speak();
d.fetch();
}

*CASE 3 - Normal base, template derived
class Base {
public:
    void identify() { cout << "I am base\n"; }
};

template <typename T>
class Derived : public Base {
public:
    T data;
    Derived(T d) : data(d) {}
};

*=========================================================
*GENERIC AND SPECIALIZED TEMPLATE CLASSES
*
?EXERCISE
class Base
{
public:
    virtual void showDetails() = 0;
    virtual void drive() = 0;
};
template <typename T>
class Vehicle : public Base
{
    string name;
    int vehicleID;
    T fuelCapacity;
    string category;

public:
    Vehicle() : name(""), vehicleID(0), fuelCapacity(), category("") {}
    Vehicle(string n, int v, T f, string c) : name(n), vehicleID(v), fuelCapacity(f), category(c) {}
    void showDetails() override
    {
        cout << "Name: " << name << endl
             << "Vehicle ID: " << vehicleID << endl
             << "Fuel Capacity: " << fuelCapacity << endl
             << "Category: " << category << endl;
    }

    void drive() override
    {
        if (category == "Car")
            cout << "Car is cruising on the road...\n";
        else if (category == "Truck")
            cout << "Truck is transporting goods...\n";
        else if (category == "Electric Scooter")
            cout << "Electric scooter is gliding silently...\n";
    }
};
template <>
class Vehicle<string> : public Base
{
    string name;
    int vehicleID;
    string fuelCapacity; // "Solar", "Hybrid", "BioFuel"
    string category;

public:
    Vehicle(string n, int v, string f, string c) : name(n), vehicleID(v), fuelCapacity(f), category(c) {}
    void showDetails() override
    {
        cout << "Name: " << name << endl
             << "Vehicle ID: " << vehicleID << endl
             << "Fuel Capacity: " << fuelCapacity << endl
             << "Category: " << category << endl;
    }
    void drive()
    {
        if (fuelCapacity == "Solar")
            cout << "Operating in solar-charging mode.\n";
        else if (fuelCapacity == "Hybrid")
            cout << "Switching between electric and combustion modes.\n ";
        else if (fuelCapacity == "BioFuel")
            cout << "Running on clean biofuel mode.\n";
    }
};
int main()
{
    Vehicle<int> car("Vehicle 1", 101, 45, "Car");
    car.drive();
    car.showDetails();
    cout << endl;
    Vehicle<double> truck("Vehicle 2", 102, 47.9, "Truck");
    truck.drive();
    truck.showDetails();
    cout << endl;
    Vehicle<float> scooter("Vehicle 3", 103, 23.68, "Electric Scooter");
    scooter.drive();
    scooter.showDetails();
    cout << endl;
    Vehicle<string> solar("Vehicle 4", 104, "Solar", "Car");
    solar.drive();
    solar.showDetails();
    cout << endl;
    Vehicle<string> hybrid("Vehicle 4", 104, "Hybrid", "Car");
    hybrid.drive();
    hybrid.showDetails();
    cout << endl;
}

?SIMILAR EXERCISE + inheritance, array of pointers
//*This class is the parent class which has pure virtual functions and its two child classes (Appliance<T> and Appliance<string>) inherit them functions from it.
//*This way we can store the children under the same pointer type.
class ApplianceBase
{
public:
    virtual void operate() = 0;
    virtual void showDetails() = 0;
};

template <typename T>
class Appliance : public ApplianceBase
{
protected:
    string name;
    int modelNumber;
    T powerRating;

public:
    Appliance() : name(""), modelNumber(0), powerRating() {}
    Appliance(string n, int mN, T pR) : name(n), modelNumber(mN), powerRating(pR) {}
    void showDetails() override
    {
        cout << "Name: " << name << endl
             << "Model Number: " << modelNumber << endl
             << "Power Rating: " << powerRating << endl;
    }
};

template <>
class Appliance<string> : public ApplianceBase
{
protected:
    string name;
    int modelNumber;
    string category; // inputs:"Solar-Powered", "Low-Energy", or "Hybrid".

public:
    Appliance() : name(""), modelNumber(0), category("") {}
    Appliance(string n, int mN, string category) : name(n), modelNumber(mN), category(category) {}
    void showDetails()
    {
        cout << "Name: " << name << endl
             << "Model Number: " << modelNumber << endl
             << "Category: " << category << endl;
    }
    void operate()
    {
        if (category == "Solar-Powered")
            cout << "Operating in Solar Power mode.\n";
        else if (category == "Low-Energy")
            cout << "Operating in Low Energy mode.\n";
        else
            cout << "Operating in hybrid mode.\n";
    }
};

template <typename T>
class WashingMachine : public Appliance<T>
{
public:
    WashingMachine() {}
    WashingMachine(string n, int mN, T powerRating) : Appliance<T>(n, mN, powerRating) {} //*dont forget the <T> with Appliance
    void operate() override
    {
        cout << "Washing clothes..." << endl;
    }

    void washMode()
    {
        cout << "Washing cycle started\n";
    }
};
template <typename T>
class AirCondition : public Appliance<T>
{
public:
    AirCondition() {}
    AirCondition(string n, int mN, T powerRating) : Appliance<T>(n, mN, powerRating) {}

    void operate() override
    {
        cout << "Cooling the room..." << endl;
    }
    void coolMode()
    {
        cout << "Cooling mode activated\n";
    }
};
template <typename T>
class SmartLight : public Appliance<T>
{
public:
    SmartLight() {}
    SmartLight(string n, int mN, T powerRating) : Appliance<T>(n, mN, powerRating) {}

    void operate() override
    {
        cout << "Adjusting room lighting..." << endl;
    }
    void dimMode()
    {
        cout << "Brightness adjusted.\n";
    }
};
int main()
{
    ApplianceBase *baseptr[6]; //*Array of base pointers
    baseptr[0] = new WashingMachine<int>("Washing Machine", 1, 220);
    baseptr[1] = new AirCondition<double>("Air Condition", 2, 230.8);
    baseptr[2] = new SmartLight<float>("Smart Light", 3, 110.67);
    baseptr[3] = new Appliance<string>("Eco Unit 1", 4, "Solar-Powered");
    baseptr[4] = new Appliance<string>("Eco Unit 2", 5, "Low-Energy");
    baseptr[5] = new Appliance<string>("Eco Unit 3", 6, "Hybrid");

    for (int i = 0; i < 6; i++)
    {
        baseptr[i]->operate();
        baseptr[i]->showDetails();
        cout << endl;
    }

    for (int i = 0; i < 6; i++)
    {
        delete baseptr[i];
    }
}

*/

/* //! FILING
*ifstream   → file to program     (reading)
*ofstream   → program to file     (writing)
*fstream    → both directions
*for filing, include the library.

*Syntax for creating and editing a file is -->
ofstream name("filename.txt");
name << "content";
*OR
ofstream name;
name.open("filename.txt");
name<<"content";

*for example,
#include <fstream>
ofstream file("textfile.txt");
file <<"my first text/\n";

*to close the file -->
name.close();

*in classes
class Filing
{
    ofstream file;
    string fname;

public:
    Filing(string s) : fname(s)
    {
        file.open(fname);
        if (!file)
        {
            cout << "Cannot open file.\n";
            exit(0);
        }
    }
    void writeData(string message)
    {
        if (file.is_open())
            file << message;
    }
    void closefile()
    {
        if (file.is_open())
        {
            file.close();
            cout << "File closed\n";
        }
    }
};

int main()
{
    Filing h("output.txt");
    h.writeData("hello my name is anz.\n");
    h.writeData("im 19 years old.\n");
    h.closefile();
}
*--------------------------------------------
*ios::app: used to add contents at the end of the file.
class FileAppender
{
    ofstream file;
    string fname;

public:
*Constructor used to open the file.
    FileAppender(string t) : fname(t)
    {
        file.open(fname, ios::app);
        if (!file)
        {
            cout << "Could not create file.\n";
            exit(1);
        }
    }
*Desctructor used to close the file.
    ~FileAppender()
    {
        file.close();
        cout << "Data written successfully.\n";
    }

    void append(string text)
    {
        file << text;
    }
};
int main()
{
    FileAppender f("output.txt");
    f.append("hello my name is anz\n");
    f.append("im 19.\n");
}

?EXERCISE
int main()
{
    string name, email;
    ofstream file("file.txt", ios::app);
    cout << "How many users?: ";
    int users;
    cin >> users;
    for (int i = 0; i < users; i++)
    {
        cout << "Name: ";
        cin >> name;
        cout << "Email: ";
        cin >> email;
        file << "Name: " << name << endl
             << "Email: " << email << endl;
    }
    file.close();
}

*--------------------------------------------
*cerr is used to write errors in the terminal. cout types content in file while cerr does it in the terminal.
cerr << "error opening file.\n";

*-------------------------------------------
//*If we want to display using classes, have to make constructors, destructors and so forth but in main,
int main()
{
    string line;
    ifstream file("file.txt");
    //* line by line
    while (getline(file, line))
    {
    use cout<< to print
    }

    //* word by word
    while (file >> line)
    {
    }

    //* char by char
    while (file.get(line)){}
}

*--------------------------------------------
class FileReader
{
    ifstream file;

public:
    FileReader(const string &name)
    {
        file.open(name);
        if (!file.open())
        {
            cout << "unable to open file.\n";
            exit(1);
        }
    }
    ~FileReader()
    {
        file.close();
        cout << "File edited successfully\n";
    }
    void display()
    {
        string line;
        if (file.is_open())
        {
            while (getline(file, line))
            {
                cout << line << endl;
            }
        }
    }
};
int main()
{
    FileReader f("file.txt");
    f.display();
}
*---------------------------------------------
*for binary files, cast your variable into char, and mention its size.
* ofstream.write((char *)&variable, sizeof(variable)); (writing into it)
* ifstream.read((char *)&variable, sizeof(variable)); (reading from it)
* in order to read or write raw binary data,




class Student
{
public:
    int id;
    char name[50];
};
int main()
{
    Student s1 = {101, "Abdullah Shaikh"};
    ofstream outfile("Student.dat", ios::binary);
    outfile.write((char *)&s1, sizeof(s1));
    outfile.close();

    Student s2;
    ifstream infile("student.dat", ios::binary);

    infile.read((char *)&s2, sizeof(s2));
    infile.close();
    cout << "ID: " << s2.id<< endl;
    cout << "Name: " << s2.name<< endl;
}

*s1 in memory:  [101][A][b][d][u][l][l][a][h]...
                 ↓
            written to disk
                 ↓
            read from disk
                 ↓
*s2 in memory:  [101][A][b][d][u][l][l][a][h]...
*The variable being different doesn't matter. What matters is what bytes are sitting in that memory at the time of printing.

?EXERCISE
struct Student
{
    char name[50];
    int id;
    float gpa;
};
int main()
{
    int u;
    Student student;
    cout << "Number of students: ";
    cin >> u;
    ofstream file("Student.dat", ios::binary);
    for (int i = 0; i < u; i++)
    {
        cout << "Name: ";
        cin >> student.name;
        cout << "ID: ";
        cin >> student.id;
        cout << "GPA: ";
        cin >> student.gpa;
        file.write((char *)&student, sizeof(student));
    }

    file.close();

    ifstream afile("Student.dat", ios::binary);
    for (int i = 0; i < u; i++)
    {
        afile.read((char *)&student, sizeof(student));
        cout << "Name: " << student.name << " | ID: " << student.id << " | GPA: " << student.gpa << endl;
    }
    afile.close();
}

*-------------------------------------------
*FILE POINTERS are used to go to a certain position in a binary file.
*get pointer: track position for reading(ifstream)
*put pointer: track position for writing(ofstream)
*use put when you are moving the pointer with the intention of editing its file contents

*infile.tellg()        // tells where the get pointer is right now
*infile.seekg(pos)     // move get pointer to position pos
*outfile.tellp()       // tells where the put pointer is right now
*outfile.seekp(pos)    // move put pointer to position pos

*seekg/seekp are directional and they use the following
*seekg(n, ios::beg)   // move n bytes from start of file
*seekg(n, ios::cur)   // move n bytes from current position
*seekg(n, ios::end)   // move n bytes from end of file (usually n is taken negative here)

?CONCRETE EXAMPLE:
int n = 2;      //* 0-indexed, so 3rd object
infile.seekg(n * sizeof(Student), ios::beg);
infile.read((char*)&s, sizeof(Student));
*here n*sizeof is taken because each student occupies sizeof(Student) space in the files. for the 3rd student, the space will be 2*sizeof(Student).

? Go to the middle of the file and print 10 lines after it.
int main()
{
    ifstream file("file.txt");
    file.seekg(0, ios::end); //* move the pointer to the end.
    int size = file.tellg(); //* and calculate file size using tellg

    file.seekg(size / 2, ios::beg); //*move halfway from beg
    string line;
    cout << "LINES: \n";
    int count = 0;
    while (getline(file, line) && count < 10) //*using counter to print 10 lines only.
    {
        cout << line << endl;
        count++;
    }
    file.close();
}

? OpenAIAnthropicGoogleMeta
? skip first 6 characters and read the next 9 into a buffer and print em.
int main()
{
    ifstream file("file.txt", ios::binary);
    if (!file)
    {
        cerr << "ERROR\n";
        return 1;
    }
    file.seekg(6, ios::beg);
    char buffer[10] = {0};
    file.read(buffer, 9);
    cout.write(buffer, 9);      //* cout<<buffer; but this will stop at \0. but the one i wrote will print exactly 9 bytes.
}
*-----------------------------------------------------
*to find the something in the file(line, word, number):

*NUMBER
int main()
{
    fstream file("a1.txt");
    file.seekg(0, ios::beg);
    int target; //*target = [number]
    string line;
    streampos pos;
    while (pos = file.tellg(), getline(file, line))
    {
        if (line == to_string(target))
        {
            file.seekp(pos);
            cout << "number to overwrite.\n";
            break;
        }
    }
}
*tho its better to use the number as a string and then find it using the word finding method below. just convert the number to string
*WORD
 while (pos = file.tellg(), getline(file, line))
    {
        if (line.find(target) != string::npos) //*becomes line.find(to_string(target)) in the case of number
        {
            file.seekp(pos + (streampos) line.find(target) );
            cout << "[word to overwrite.]";
            break;
        }
    }

*LINE
 while (pos = file.tellg(), getline(file, line))
    {
        if (line == target)
        {
            file.seekp(pos);
            cout << "line to overwrite.\n";
            break;
        }
    }
*if anything lags just use clear() after if
?Alice075
?Bobby099
?Carol100
?EXERCISE --- edit 075 to 090
int main()
{
    fstream file("a1.txt");
    file.seekg(0, ios::beg); //*move the pointer to start;
    string num = "075";
    string line;
    streampos pos;
    while (pos = file.tellg(), getline(file, line))
    {
        if (line.find(num) != string::npos)
        {
            file.seekp(pos + (streampos)line.find(num));
            file << "095";
            break;
        }
    }
}
*---------------------------------------------
?EXERCISE --- the quick brown fox jumps over teh lazy dog
? change teh to the.

int main()
{
    fstream file("file.txt");
    string h;
    streampos pos;
    while (file >> h)
    {
        if (h == "teh")
            pos = file.tellg() - (streampos)h.length(); //*tellg moves us after the word and minus length moves us befores it.
    }
    string p = "the";
    *After while loop finishes reading, the stream is in EOF state. When a stream hits EOF, it sets a fail flag — and any operations after that, including seekp and write, silently do nothing.
    *use clear for this reason.
    file.clear();
    file.seekp(pos);
    file.write(p.c_str(), p.length());
}

?EXERCISE---  change 18 to 21
John20
Jane18
Jack25

int main()
{
    fstream file("file.txt");
    file.seekp(14, ios::beg);
    string str = "099";
    file.write(str.c_str(), str.length()); //*.write() takes in const char* therefore c_str() is used to conver str to char. we can also directy write "099", 3. .length is used in case we dont know the length otherwise just write the length.
    file.seekg(0, ios::beg);               //*after editing, move to the beginning of the file to print the whole thing
    string line;
    while (getline(file, line)) //*if the file contents are written with \n, use getline. otherwise use buffer
    {
        cout << line << endl;
    }
}
? EXERCISE--- change 30 to 99
int main()
{

    fstream file("file.txt");
    string num;
    streampos pos;
    while (true)
    {
        pos = file.tellg();
        file >> num;
        if (num == "30")
        {
            break;
        }
    }
    file.clear();

    file.seekp(pos);
    file.write(" 99", 3);
    string line;
    file.seekg(0, ios::beg);
    while (getline(file, line))
    {
        cout << line << endl;
    }
}

?EXERCISE
?1. EnrollmentRecord Class
?Design a class EnrollmentRecord with the following:
?Data Members:  enrollmentID (int)  studentName (string)  courseName (string)  courseFee (double)
?Requirements:  A parameterized constructor that initializes all fields  A member function showDetails() to display the enrollment record

?2. Input Validation & Exception Handling
?Use built-in C++ exceptions (std::invalid_argument, etc.) to ensure data validity. Validation Rules:  Throw an exception if: o studentName is empty o courseFee < 0 o courseName is NOT one of the allowed options:  "Programming"  "DataScience"  "CyberSecurity" Requirements:  Use try–catch blocks while taking user input  If invalid input is entered, show the error and allow user to re-enter the record until valid

?3. File Handling
?Create a class EnrollmentFileManager that includes:
?Functions:  writeEnrollments() o Writes all enrollment records to a file enrollments.txt o Must throw an exception if the file fails to open  readEnrollments() o Reads back stored records using getline() o Displays each record cleanly

?4. Main Function
?Requirements:  Ask user for n enrollment entries  Validate each entry using exception handling  Store all records in the file  Display saved records Read back and print all records from the file

#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;
class EnrollmentRecord
{

public:
    int enrollmentID;
    string studentName;
    string courseName;
    double courseFee;

    EnrollmentRecord() : enrollmentID(0), studentName(""), courseName(""), courseFee(0.0) {}
    EnrollmentRecord(int id, string studentname, string coursename, double coursefee) : enrollmentID(id), studentName(studentname), courseName(coursename), courseFee(coursefee) {}

    void showDetails()
    {
        cout << "Enrollment ID: " << enrollmentID << endl
             << "Student Name: " << studentName << endl
             << "Course Name: " << courseName << endl
             << "Course Fee: " << courseFee << endl;
    }
};
class EnrollmentManager
{
    fstream file;
    string name;

public:
    EnrollmentManager(string n) : name(n)
    {
        file.open(name, ios::out | ios::in | ios::trunc); //*have to write the type of stuff that would be done to the file i.e. reading writing and so on
        if (!file)
            throw runtime_error("Error!");
    }
    ~EnrollmentManager()
    {
        if (file.is_open())
        {
            file.close();
            cout << "File closed.\n";
        }
    }

    void writeEnrollments(EnrollmentRecord &Er)
    {
        if (!file.is_open())
            throw runtime_error("Could not open file");
        //*to write in a txt file, do "file<<" , but if its a binary file, do "file.write()"
        file << "Enrollment ID: " << Er.enrollmentID << endl
             << "Student Name: " << Er.studentName << endl
             << "Course Name: " << Er.courseName << endl
             << "Course Fee: " << Er.courseFee << endl;
    }

    void readEnrollments()
    {
        file.seekg(0, ios::beg); //*moving the pointer at the start for printing.
        string line;
        cout << "\n--- Records from file ---\n";
        while (getline(file, line))
        {
            cout << line << endl;
        }
    }
};
int main()
{
    int n;
    cout << "How many enrollment entries?: ";
    cin >> n;
    EnrollmentRecord *record = new EnrollmentRecord[n];
    EnrollmentManager e1("enrollment.txt");

    for (int i = 0; i < n; i++)
    {

        int enrollmentID;
        string studentName;
        string courseName;
        double courseFee;

        cout << "- - -ENTRY " << i + 1 << "- - -\n";
        cout << "Enter enrollment ID: ";
        cin >> enrollmentID;
        do
        {
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, studentName);
            try
            {
                if (studentName.empty())
                    throw invalid_argument("Name cannot be empty!");
            }
            catch (invalid_argument &e)
            {
                cout << e.what() << "\n";
                studentName = ""; // ensure loop continues
            }
        } while (studentName.empty());

        do
        {
            cout << "Enter Course Name(Programming, DataScience, CyberSecurity): ";
            cin >> courseName;
            try
            {
                if (courseName != "Programming" && courseName != "DataScience" && courseName != "CyberSecurity")
                    throw invalid_argument("Course not available. Choose from the given options");
            }
            catch (invalid_argument &f)
            {
                cout << f.what() << endl;
            }
        } while (courseName != "Programming" && courseName != "DataScience" && courseName != "CyberSecurity");

        do
        {

            cout << "Enter Course Fee: ";
            cin >> courseFee;
            try
            {
                if (courseFee < 0)
                    throw invalid_argument("Invalid");
            }
            catch (invalid_argument &g)
            {
                cout << g.what() << endl;
            }
        } while (courseFee < 0);

todo ::IMPORTANT THING TO NOTE
        record[i] = EnrollmentRecord(enrollmentID, studentName, courseName, courseFee);
        e1.writeEnrollments(record[i]);
    }

    e1.readEnrollments();

    delete[] record;
}

?A backup program needs to monitor file size after every log entry.
?Requirements:
?• Accept log messages from the user. | Append each to backup_log.txt.
?• After every write, display the current file size using tellp().
?Expected Behaviour: User sees how much the file grows with each entry.

int main()
{
    fstream file("a1.txt", ios::app);
    string message;
    cin.ignore();
    do
    {
        getline(cin, message);
        file << message << endl;
        streampos pos = file.tellp();
        cout << "Size: " << pos << endl;
    } while (message != "exit");
}

?EXERCISE - Count line,word, char, punct mark, digit
int main()
{
    string line;
    string word;
    char ch;
    int linecount = 0, wordcount = 0, chcount = 0, markcount = 0, numcount = 0;
    fstream file("a1.txt");
    while (getline(file, line))
        linecount++;

    file.clear();
    file.seekg(0, ios::beg);

    while (file >> word)
        wordcount++;

    file.clear();
    file.seekg(0, ios::beg);

    while (file.get(ch))
    {
        if (isalpha(ch))
            chcount++;
        else if (isdigit(ch))
            numcount++;
        else if (!ispunct(ch))
            markcount++;
    }
    file.clear();
    file.seekg(0, ios::beg);

    cout << "Line count = " << linecount << endl << "Word Count = " << wordcount << endl << "Character count = " << chcount << endl << "Mark count = " << markcount << endl << "Number count = " << numcount << endl;
}

A file debugger tool lets users jump around a file and inspect contents.
Requirements:
• Allow user to input a byte offset.
• Use seekg() to go there.
• Read and display the next 100 characters.
• Show pointer position before and after.
Expected Behaviour:
Program behaves like a mini file explorer/debugger.
int main()
{
    fstream file("file.txt");
    char c;
    int count = 0;
    while (file.get(c))
    {
        count++;
    }
    cout << count << endl;
    file.clear();
    file.seekg(0, ios::beg);
    cout
        << "Input a byte offset: ";
    int byte;
    cin >> byte;
    file.seekg((streampos)byte, ios::beg);
    char buffer[101] = {0};
    file.read(buffer, 100);
    cout << buffer;
}
*OR
int main()
{
    fstream file("a1.txt");
    int byteoff;
    cout << "Enter byte offset: ";
    cin >> byteoff;
    file.seekg((streampos)byteoff, ios::beg);
    int count = 0;
    char ch;
    while (file.get(ch) && count < 100)
    {
        cout << ch;
        count++;
    }
}


class Student
{
public:
    int roll;
    string name;
    int marks;

    void fileInput()
    {
        fstream file("file.txt", ios::app);
        cout << "Enter roll number: ";
        cin >> roll;

        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter marks: ";
        cin >> marks;
        file << "\nRoll number: " << roll << " | Name: " << name << " | Marks: " << marks << endl;
    }
    void display()
    {
        fstream file("file.txt");
        string line;
        cout << "----DETAILS----\n";
        while (getline(file, line))
        {
            cout << line << endl;
        }
    }
};
int main()
{
    //* fstream file("file.txt", ios::trunc | ios::in | ios::out);
    Student student;
    student.fileInput();
    student.display();
}

?EXERCISE - writing the quote into the file and making one of its word allcaps and printing it.
int main()
{
    string quote = "In the middle of difficulty, lies opportunity. ~Albert Einstien";
    fstream file("file.txt");
    file << quote << endl;
    file.seekg(0, ios::beg);
    streampos pos;
    string word;
    while (true)
    {
        pos = file.tellg();
        file >> word;
        if (word == "middle")
        {
            break;
        }
    }
    file.clear();
    file.seekp(pos);
    file.write("MIDDLE", 6);
    file.seekg(0, ios::beg);
    while (getline(file, quote))
    {
        cout << quote << endl;
    }
    file.clear();
    file.seekg(0, ios::beg);
}

*OR


int main()
{
    string quote = "In the middle of difficulty, lies opportunity. ~Albert Einstien";
    fstream file("a1.txt");
    file << quote << endl;
    file.seekg(0, ios::beg);
    string target = "middle";
    string line;
    streampos pos;
    while (pos = file.tellg(), getline(file, line))
    {
        if (line.find(target) != string::npos)
        {
            file.seekp(pos + (streampos)line.find(target));
            file << "MIDDLE";
        }
    }
    file.clear();
    file.seekg(0, ios::beg);
    while (getline(file, quote))
    {
        cout << quote << endl;
    }
}
*-------------------------------------------
*to change something that appears multiple times at once,

?EXERCISE - replace a with #
file.seekg(0, ios::beg);
streampos pos;
char ch;
while (pos = file.tellg(), file.get(ch))
{
    if (ch == 'a')
    {
        file.seekp(pos);
        file << '#';
    }
}

?Replace a word/number
file.seekg(0, ios::beg);
streampos pos;
string line;
string target;
while(pos = file.tellg(), getline(file, line)){
size_t found = line.find(target);
while(streampos found != string::npos){
file<<"wordtoreplace";
found = line.find(target, found+1) } }

*/

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

 ?EXERCISE -
?Commission Rules: ~Emerging Artist: 8% of sale price + €300 | ~Renowned Artist: 4% of sale price + €300
?Artwork Class
?Data Members: title | artistName | yearCreated | basePrice | salePrice | artistCategory (e.g., "Emerging", "Renowned")
?Tasks:  Create a parameterized constructor  Implement inputArtwork() to enter full artwork details including final sale price  Implement showArtwork() to display artwork information  The class must contain a CommissionEngine object (has-a relation)

?CommissionEngine Class
?Requirements:  Contains a friend function  double computeCommission(Artwork&)  This function must access Artwork’s private data and compute commission based on: o Artist category o Final sale price

?Main Function
?Tasks:  Create an Artwork object  Take sale price input from user  Call computeCommission()  Display artwork details + the computed commission amount

class Artwork;
class CommissionEngine
{
public:
    friend double computeCommission(Artwork &a);
};
class Artwork
{
    string title;
    string artistName;
    int yearCreated;
    double basePrice;
    double salePrice;
    string artistCategory; //(e.g., "Emerging", "Renowned")
    CommissionEngine e;

public:
    Artwork() : title(""), artistName(""), yearCreated(0), basePrice(0.0), salePrice(0.0), artistCategory("") {}
    Artwork(string title, string artistname, int year, double basep, double salep, string category) : title(title), artistName(artistname), yearCreated(year), basePrice(basep), salePrice(salep), artistCategory(category) {}

    //*using get function to modify their values. for modification put &. otherwise this error appears: "expression must be a modifiable lvalue"
    //*another thing to note is that the purpose of friend is to access private members but here only question requirement is fulfilled (by using getter/setter)
    double &getsaleprice() { return salePrice; }
    string &getartistcategory() { return artistCategory; }

    void inputArtwork()
    {
        string title;
        string artistName;
        int yearCreated;
        double basePrice;
        double salePrice;
        string artistCategory;
        cout << "---INPUT ARTWORK INFO---\n";

        cout << "Enter title: ";
        getline(cin, title);

        cout << "Enter artist name: ";
        getline(cin, artistName);

        cout << "Enter year created: ";
        cin >> yearCreated;

        cout << "Enter base price: ";
        cin >> basePrice;

        cout << "Enter sale price: ";
        cin >> salePrice;

        cin.ignore();

        cout << "Enter artist category(e.g., Emerging, Renowned): ";
        getline(cin, artistCategory);

        //*When wanting the input logic to be inside the function of the same class, use this->. but if do in main use constructor.
        this->title = title;
        this->artistName = artistName;
        this->yearCreated = yearCreated;
        this->basePrice = basePrice;
        this->salePrice = salePrice;
        this->artistCategory = artistCategory;
    }
    void showArtwork()
    {
        cout << "\n---ARTWORK DETAILS---\n";
        cout << "Title: " << title << endl;
        cout << "Artist Name: " << artistName << endl;
        cout << "Year Created: " << yearCreated << endl;
        cout << "Base Price: $" << basePrice << endl;
        cout << "Sale Price: $" << salePrice << endl;
        cout << "Artist Category: " << artistCategory << endl;
        cout << "Final Price: $" << basePrice - salePrice << endl;
    }
};

double computeCommission(Artwork &a)
{
    double com = 0;
    if (a.getartistcategory() == "Emerging")
    {
        com = a.getsaleprice() + 249.9;
    }
    else if (a.getartistcategory() == "Renowned")
    {
        com = a.getsaleprice() + 399.9;
    }
    return com;
}

int main()
{
    Artwork a;
    a.inputArtwork();
    double com = computeCommission(a);
    a.showArtwork();
    cout << "Commission: $" << com << endl;
}
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
    */
/* //! ══════════════════════════════THEORY═════════════════════════════════
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
\\
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
*  ═══════════════════════════════════════════════════════════════
*         ARRAY OF OBJECTS — COMPLETE REFERENCE
*  ═══════════════════════════════════════════════════════════════

*THE 4 WAYS
*   1. Device d[10]          — stack array of objects
*   2. Device *d             — heap array of objects (via new)
*   3. Device *d[10]         — stack array of pointers to objects
*   4. Device **d            — heap array of pointers (via new)

*  1. Device d[10] — stack array of objects
*     Objects live on stack. Fixed size. No new, no delete.

* INITIALIZATION
Device d[3];  //default constructor called 3x
Device d[3] = {Device("D1","OFF"), Device("D2","OFF"), Device("D3","OFF")}; // explicit init

* ACCESS
d[0].turnOn();         dot — d[i] gives the object directly
d[1].getID();

* PASSING TO FUNCTION
void foo(Device d[], int size);
void foo(Device *d,  int size);     identical — array decays to pointer
foo(d, 3);

* MEMORY

   stack
   ┌──────────┬──────────┬──────────┐
   │ d[0]     │ d[1]     │ d[2]     │
   │ Device   │ Device   │ Device   │
   └──────────┴──────────┴──────────┘

*   2. Device *d — heap array of objects (via new)
*     Objects live on heap. Size can be decided at runtime.

* INITIALIZATION
int n = 5;
Device *d = new Device[n];                 // default constructor called n times | NOTE: Device MUST have default constructor

* ASSIGNING VALUES AFTER
d[0] = Device("D1", "OFF");
d[1] = Device("D2", "OFF");

* ACCESS
d[0].turnOn();         //dot — d[i] gives the object, not a pointer
d[1].getID();

* PASSING TO FUNCTION
void foo(Device *d, int size);
foo(d, n);

* MEMORY

   stack          heap
   ┌───────┐      ┌──────────┬──────────┬──────────┐
   │   d   │─────►│  d[0]    │  d[1]    │  d[2]    │
   │ (ptr) │      │ Device   │ Device   │ Device   │
   └───────┘      └──────────┴──────────┴──────────┘

* CLEANUP
delete[] d;            frees entire block — [] is mandatory here

*  3. Device *d[10] — stack array of pointers
*     Pointers on stack. Objects can be anywhere (stack or heap).
*     USE WHEN: polymorphism needed.

* INITIALIZATION
Device *d[10];          10 pointer slots, uninitialized
Device *d[10] = {};     all nullptr — safe

* POINT TO EXISTING STACK OBJECTS
Light  L("L1", "OFF");
Camera C("C1", "OFF");
d[0] = &L;
d[1] = &C;

* OR HEAP ALLOCATE EACH SLOT INDIVIDUALLY
d[0] = new Light("L1",   "OFF");
d[1] = new Camera("C1",  "OFF");
d[2] = new Device("D1",  "OFF");

* ACCESS
d[0]->turnOn();        arrow — d[i] gives a pointer, not the object
d[1]->getID();

* PASSING TO FUNCTION
void foo(Device *d[], int size);
void foo(Device **d,  int size);     identical to compiler
foo(d, 3);

* MEMORY

   stack
   ┌────────┬────────┬────────┐
   │  d[0]  │  d[1]  │  d[2]  │   ← pointers
   └───┬────┴───┬────┴───┬────┘
       │        │        │
       ▼        ▼        ▼
    [Light]  [Camera]  [Device]    ← objects anywhere in memory

* CLEANUP — only if heap allocated
for (int i = 0; i < 3; i++)
    delete d[i];


    * 4. Device **d — heap array of pointers (via new)
*     Both the pointer array AND objects on heap.
 *    USE WHEN: size of array unknown at compile time + polymorphism.

* INITIALIZATION
int n = 5;
Device **d = new Device*[n];       allocates array of n pointers on heap
for (int i = 0; i < n; i++)
    d[i] = nullptr;                safe — set all to nullptr

* ASSIGN OBJECTS TO EACH SLOT
d[0] = new Light("L1",  "OFF");
d[1] = new Camera("C1", "OFF");
d[2] = new Device("D1", "OFF");

* ACCESS
d[0]->turnOn();        arrow — d[i] is a pointer
d[1]->getID();

* PASSING TO FUNCTION
void foo(Device **d, int size);
foo(d, n);

* MEMORY

   stack         heap                    heap
   ┌───────┐     ┌────────┬────────┬────────┐
   │   d   │────►│  d[0]  │  d[1]  │  d[2]  │   ← pointer array
   │ (ptr) │     └───┬────┴───┬────┴───┬────┘
   └───────┘         │        │        │
                     ▼        ▼        ▼
                  [Light]  [Camera] [Device]      ← objects

* CLEANUP — two stages, order matters
for (int i = 0; i < n; i++)
    delete d[i];       1. delete each object first
delete[] d;            2. delete the pointer array itself



*  SIDE BY SIDE

   ┌─────────────────┬───────────────┬──────────────┬──────────────────┬─────────────────────┐
   │                 │  Device d[10] │  Device *d   │  Device *d[10]   │     Device **d      │
   ├─────────────────┼───────────────┼──────────────┼──────────────────┼─────────────────────┤
   │ Array lives on  │ stack         │ heap         │ stack            │ heap                │
   │ Objects live on │ stack         │ heap         │ stack or heap    │ heap                │
   │ Size at runtime │ no            │ yes          │ no               │ yes                 │
   │ Polymorphism    │ no            │ no           │ yes              │ yes                 │
   │ Access syntax   │ d[i].         │ d[i].        │ d[i]->           │ d[i]->              │
   │ delete needed   │ no            │ delete[] d   │ delete d[i]      │ delete d[i] + []d   │
   │ Function param  │ Device *d     │ Device *d    │ Device **d       │ Device **d          │
   └─────────────────┴───────────────┴──────────────┴──────────────────┴─────────────────────┘

  THE ONE RULE (same as before)
   d[i] gives an object  →  dot    ( Device d[]  and  Device *d  )
   d[i] gives a pointer  →  arrow  ( Device *d[] and  Device **d )

  WHEN TO USE WHICH
   fixed size + no polymorphism + simple          →  Device d[10]
   dynamic size + no polymorphism                 →  Device *d  (new)
   fixed size + polymorphism                      →  Device *d[10]
   dynamic size + polymorphism                    →  Device **d (new)

?EXERCISE---
class Person
{
    string name;
    int age;

public:
    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}
    virtual void display()
    {
        cout << "Name: " << name << " | Age: " << age;
    }
};
class Student : public Person
{
    int id;
    int gpa;

public:
    Student(string n, int a, int id, int gpa) : Person(n, a), id(id), gpa(gpa) {}
    void display() override
    {
        Person::display();
        cout << " | ID: " << id << " | GPA: " << gpa << endl;
    }
};

class Teacher : public Person
{
    string subject;
    int salary;

public:
    Teacher(string n, int a, string sub, int salary) : Person(n, a), subject(sub), salary(salary) {}
    void display() override
    {
        Person::display();
        cout << " | Subject: " << subject << " | Salary: " << salary << endl;
    }
};

int main()
{
    Person *p[2];
 p[0] = new Student("Sara", 17, 101, 3.4);
 p[1] = new Teacher("ALi", 34, "Physics", 34555);

* OR
Student s1("Sara", 17, 101, 3.4);
Teacher t1("ALi", 34, "Physics", 34555);
p[0] = &s1;
p[1] = &t1;

 *OR
 Person *p1[] = {&s1, &t1};

 *----display(for first and third method only, use delete)---
 for (int i = 0; i < 2; i++)
    {
        p[i]->display();
    }
    for (int i = 0; i < 2; i++)
    {
        delete p[i];
    }
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
    Laptop *L;  * Pointer to a Laptop

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

?EXERCISE---
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