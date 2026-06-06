
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

/* //! ENCAPSULATION + CONSTRUCTORS + STATIC + CONST + INLINE + HAS A + IS A + VIRTUAL + DIAMOND PROBLEM + FRIEND CLASS N FUNCTION + OPERATOR OVERLOADING + ARRAY OF OBJECTS
?Data members (private where applicable):  Person (private): string name; int age;
? Patient (derived from Person, protected where needed): int patientID; static int totalPatients; const string disease;
? Room (private):int roomNo; float bedChargesPerDay;
? Staff hierarchy (protected where needed): In Staff: string staffName;

?1. Implement Person with Encapsulation and Object Basic
?Design the Person class using encapsulation: keep data members private and provide setters/getters (use this pointer inside setters). o Implement three constructors:  Default: initializes to "Unknown" and 0  Parameterized: accepts name and age  Copy constructor: performs deep copy and prints a message like "Person Copy Constructor Called" o Implement a destructor that prints a message when a Person object is destroyed. o Write a standalone friend function printPersonSummary(const Person&) that can access and display private data (demonstrating data hiding with controlled access).

?2. Implement Patient with Constructors, Static, Const, Member Initialization
?Create a class Patient that inherits from Person and has a HAS-A relationship with Room. o Add: int patientID;, static int totalPatients;, and const string disease; o Use a member initialization list in the parameterized constructor to initialize disease. o Provide:  Default constructor  Parameterized constructor: (name, age, patientID, disease, Room)  Copy constructor that also increases totalPatients o Implement a destructor that prints "Patient object destroyed: ID ..." o Implement a member function showInfo() to display full patient details and call room.showRoom(). o Implement a static function getPatientCount() that returns total number of Patient objects created.

?3. Implement Room and Demonstrate HAS-A + Inline Function
?Implement a separate Room class with roomNo and bedChargesPerDay. o Provide a constructor that initializes both members. o Implement an inline function showRoom() that prints room details. o In Patient, include a Room object as a data member and a function assignRoom(const Room&) to update the assigned room. o Show how a Patient has-a Room by using Room inside Patient::showInfo().

?4. EmergencyPatient, AdmittedPatient, SurgicalPatient: Inheritance, Overriding & Polymorphism
?Using Patient as base, design specialized patient types: o EmergencyPatient (single inheritance): overrides showInfo() and prints a heading like "[Emergency Patient - Critical Case]" before calling Patient::showInfo(). o AdmittedPatient:  Inherits from Patient  Adds a double currentBill;  Implements double calculateBill(int days) that multiplies days by room charges and stores in currentBill.  Overrides showInfo() to also display the current bill. o SurgicalPatient:  Inherits from EmergencyPatient (multilevel inheritance)  Overrides showInfo() again, printing "[Surgical Patient - Operation Scheduled]" and then base info. In main(), use a Patient* pointer to point to different derived objects (EmergencyPatient, AdmittedPatient, SurgicalPatient) and call showInfo() to demonstrate runtime polymorphism.

?5. Operator Overloading and Friend Class for Admin Control
? o In AdmittedPatient, overload the + operator to sum the currentBill of two AdmittedPatient objects and return a new AdmittedPatient with combined bill. o Create a friend class HospitalAdmin that can modify a patient’s room and charges by accessing appropriate functions. Implement a member function changeRoom(Patient&, int newRoomNo, float newCharges) that updates the patient’s Room. o In main(), show:  Calculation of bills for two admitted patients  Use of + operator to get a combined bill  Use of HospitalAdmin to change the room of a patient and then display updated info.

?6. Multiple Inheritance, Diamond Problem & Virtual Functions with Staff
?Model hospital staff and surgical teams: o Create a base class Staff with string staffName; and a virtual function performDuty(). o Create Doctor and Nurse classes that virtually inherit from Staff and override performDuty() with role-specific messages. o Create a SurgicalTeam class that inherits from both Doctor and Nurse and overrides performDuty() to represent combined surgical duties. o In main(), create a SurgicalTeam object, store its address in a Staff* pointer, and call performDuty() to demonstrate correct resolution of the diamond problem using virtual inheritance and virtual functions.

?7. Integration & Testing in main()
?In main() you must: o Create Person and Patient objects using default, parameterized, and copy constructors. o Create an array of Patient objects to show array of objects usage. o Assign Room objects to patients (HAS-A relation). o Demonstrate static count via Patient::getPatientCount(). o Use Patient* and Staff* pointers to demonstrate polymorphism with overridden functions.

class Person
{
    string name;
    int age;

public:
    //* default
    Person() : name("Unknown"), age(0) {}
    //* para
    Person(string n, int a) : name(n), age(a) {}

    //* deep copy to print text
    //* just because this deep copy was asked to print text, doesnt it mean it wont copy data as well.
    Person(const Person &obj)
    {
        name = obj.name;
        age = obj.age;
        cout << "Person Copy Constructor Called.\n";
    }
    //* destructor to print message
    ~Person()
    {
        cout << "Destructor called.\n";
    }
    string getname() { return name; }
    int getage() { return age; }
    //* friend to print details
    friend void printPersonSummary(const Person &);
};
//* friend func
void printPersonSummary(const Person &p)
{
    cout << "Name: " << p.name << endl
         << "Age: " << p.age << endl;
}

class Room
{
    int roomNo;
    float bedChargesPerDay;

public:
    Room() : roomNo(0), bedChargesPerDay(0.0) {}
    Room(int roomno, float bedcharges) : roomNo(roomno), bedChargesPerDay(bedcharges) {}

    //* setter
    void setroomno(int r) { roomNo = r; }
    void setbed(float b) { bedChargesPerDay = b; }

    inline void showRoom()
    {
        cout << "Room No: " << roomNo << endl
             << "Bed Charges Per Day: " << bedChargesPerDay << endl;
    }
};

class HospitalAdmin;
class Patient : public Person // Person inherits Patient
{
protected:
    int patientID;
    //* static will be incremented in both para & copy constructors
    static int totalPatients;
    const string disease;
    Room r;

public:
    Patient() : patientID(0) {}
    Patient(string name, int age, int id, string d, Room r) : Person(name, age), patientID(id), disease(d), r(r)
    {
        totalPatients++;
    }

    Patient(const Patient &obj) : patientID(obj.patientID), disease(obj.disease), r(obj.r)
    {
        totalPatients++;
    }

    ~Patient()
    {
        cout << "Patient object destroyed.\nID: " << patientID << endl;
        totalPatients--;
    }
    virtual void showInfo()
    {
        cout << "Patient Name: " << getname() << endl
             << "Patient Age: " << getage() << endl
             << "Patient ID: " << patientID << endl
             << "Patient Disease: " << disease << endl;
        r.showRoom();
    }
    void assignRoom(Room &room)
    {
        int newno;
        float charge;
        cout << "Enter new room number: ";
        cin >> newno;
        cout << "Enter charges: ";
        cin >> charge;
        room.setroomno(newno);
        room.setbed(charge);
    }
    static void getPatientCount()
    {
        cout << "Total Patients: " << totalPatients << endl;
    }
    friend class HospitalAdmin;
};

int Patient::totalPatients = 0;

class EmergencyPatient : public Patient
{
public:
    EmergencyPatient() {}
    EmergencyPatient(string name, int age, int id, string d, Room r) : Patient(name, age, id, d, r) {}

    void showInfo() override
    {
        cout << "[Emergency Patient - Critical Case]\n";
        Patient::showInfo();
    }
};
class AdmittedPatient : public Patient
{
    double currentbill;

public:
    AdmittedPatient() : currentbill(0.0) {}
    AdmittedPatient(string name, int age, int id, string d, Room r, double currentbill) : Patient(name, age, id, d, r), currentbill(currentbill) {}
    double getbill() { return currentbill; }
    double calculateBill(int days)
    {
        double roomCharges = 19.9;
        currentbill = days * roomCharges;
        return currentbill;
    }

    AdmittedPatient operator+(const AdmittedPatient &obj)
    {
        AdmittedPatient a;
        a.currentbill = this->currentbill + obj.currentbill;
        return a;
    }

    void showInfo() override
    {
        cout << "[Admitted Patient]\n";
        Patient::showInfo();
        cout << "Bill: " << currentbill << endl;
    }
};
class SurgicalPatient : public EmergencyPatient
{
public:
    SurgicalPatient() {}
    SurgicalPatient(string name, int age, int id, string d, Room r) : EmergencyPatient(name, age, id, d, r) {}

    void showInfo() override
    {
        cout << "[Surgical Patient - Operation Scheduled]\n";
        Patient::showInfo();
    }
};

class HospitalAdmin
{
public:
    void changeRoom(Patient &p, int newRoomNo, float newCharges)
    {
        p.r.setroomno(newRoomNo);
        p.r.setbed(newCharges);
        cout << "Room changed\n\n";
    }
};

class Staff
{
protected:
    string staffName;

public:
    Staff() : staffName("Unknown") {}
    Staff(string name) : staffName(name) {}
    virtual void performDuty()
    {
        cout << staffName << " performs staff duty.\n";
    }
};
class Doctor : virtual public Staff
{
public:
    Doctor() {}
    Doctor(string name) : Staff(name) {}
    void performDuty() override
    {
        cout << staffName << " performs doctor duty.\n";
    }
};
class Nurse : virtual public Staff
{
public:
    Nurse() {}
    Nurse(string name) : Staff(name) {}

    void performDuty() override
    {
        cout << staffName << " performs Nurse duty.\n";
    }
};
class SurgicalTeam : public Doctor, public Nurse
{
public:
    SurgicalTeam() {}
    SurgicalTeam(string name) : Staff(name), Doctor(name), Nurse(name) {}
    void performDuty() override
    {
        cout << staffName << " performs surgical duties.\n";
    }
};
int main()
{
    Person person1;
    Person person2("Sara", 45);
    Person person3(person2);
    printPersonSummary(person3);
    cout << endl;
    Room r1(1, 12.99);
    Room r2(2, 12.99);
    Room r3(3, 15.99);
    Room r4(4, 12.99);
    EmergencyPatient p1("John", 34, 101, "Cancer", r1);

    AdmittedPatient p2("Doe", 50, 102, "AIDS", r2, 20);
    p2.calculateBill(3);

    AdmittedPatient p3("Barack", 50, 103, "AIDS", r3, 80);
    p3.calculateBill(3);

    AdmittedPatient final(p2 + p3);
    cout << "OPERATOR OVERLOADED BILL: " << final.getbill() << endl;
    SurgicalPatient p4("Alice", 24, 104, "Epilepsy", r4);

    HospitalAdmin admin;
    admin.changeRoom(p3, 2, 12.99);

    Patient *P[] = {&p1, &p2, &p3, &p4};

    for (int i = 0; i < 4; i++)
    {
        P[i]->showInfo();
        cout << endl;
    }
    Patient::getPatientCount();
    cout << endl;

    SurgicalTeam s("Doctor Brown");
    Staff *staff = &s;
    staff->performDuty();
    cout << endl;
}*/

/* //! INHERITANCE + PURE VIRTUAL + ADVANCED OPERATOR OVERLOADING + DMA + HAS-A
?EXERCISE
?Entity Class – Base Class
?Your base class must include:
?Attribute: id (int), Parameterized constructor to initialize the id, void displayDetails() — pure virtual function, virtual void addRelationship(int id, string type) — manages relations such as “studentFriend”, “groupMember”, etc., by checking the type

?Student Class – Derived from Entity
?Attributes: string name, string rollNumber, Array of Student IDs (stores classmates or study partners), Array of StudyGroup IDs (groups the student belongs to), Array of LearningPost objects (posts created by the student)
?Requirements: A parameterized constructor that also initializes all arrays, Override displayDetails() to show all class information | Override addRelationship(int id, string type), If type = "studentFriend": Add the student ID to the friends array, Only if not already added and array has space, Overload += to add a StudyGroup (ID) to the groups array, Overload + to add a LearningPost to the posts array

?LearningPost Class
?Attributes: string content, Array of comments (strings), likes (int)
?Requirements: Parameterized constructor that initializes comments array | addLikes() increments the likes count | Override displayDetails() to print post content, likes, and all comments | Overload ++ operator to insert a new comment into the post

?StudyGroup Class – Derived from Entity
?Attributes: string groupName| string subject | Array of student IDs (members of the group)
?Requirements: Parameterized constructor initializing all attributes and arrays | Override addRelationship(int id, string type) | If type = "groupMember" | Add student ID to members array| Only if not already added and array has space| Override displayDetails() to show full group details and member list

//*the way DMA is used is by declaring capacity of the array member as a member in the class and holding it const (tho it may give error in some places).
//*Then declaring another var to track count. this count makes easier to use for loops and ifs.
//*The DMA for these arrays / array of objs is done in the constructor.
*SYNTAX :
class Entity //*Parent class for holding pure virtual funcs.
{
protected:
    int id;

public:
    Entity() {}
    Entity(int id) : id(id) {}
    virtual void displayDetails() = 0;
    virtual void addRelationship(int id, string type) = 0;
};

class LearningPost
{
    string content;
    string *comments;
    int commentcount = 0;
    int ccapacity = 10;
    int likes;

public:
    LearningPost() : content(""), likes(0), commentcount(0)
    {
        comments = new string[ccapacity];
    }

    LearningPost(string c, int l) : content(c), likes(l)
    {
        comments = new string[ccapacity];
    }

    ~LearningPost() { delete[] comments; }

    int addLikes()
    {
        return likes++;
    }

    void displayDetails()
    {
        cout << "Content: " << content << endl
             << "Likes: " << likes << endl;
        for (int i = 0; i < commentcount; i++)
        {
            cout << "Comment: " << comments[i] << endl;
        }
    }

    LearningPost &operator++()
    {
        string newComment;
        cout << "Enter new comment: ";
        getline(cin, newComment);
        if (commentcount < ccapacity)
        {
            comments[commentcount] = newComment;
            commentcount++;
        }
        else
        {
            cout << "Comment capacity reached.\n";
        }
        return *this;
    }
};

class Student : public Entity
{
    string name;
    string rollNumber;
    int *studentID;
    const int scapacity = 10;
    int studentsize = 0;

    int *studyGroupID;
    int groupsize = 0;
    const int gcapacity = 10;
    LearningPost *l; // arr of objs
    const int postcapacity = 10;
    int postcount = 0;

public:
    Student() {}
    Student(int id, string name, string rN) : Entity(id), name(name), rollNumber(rN)
    {
        studentID = new int[scapacity];
        studyGroupID = new int[gcapacity];
        l = new LearningPost[postcapacity];
    }
        ~Student() {
    delete[] studentID;
    delete[] studyGroupID;
    delete[] l;
}
    void displayDetails() override
    {
        cout << "ID: " << id << endl
             << "Name: " << name << endl
             << "Roll Number: " << rollNumber << endl;
        for (int i = 0; i < studentsize; i++)
        {
            cout << "Student ID " << i + 1 << ": " << studentID[i];
        }
        for (int i = 0; i < groupsize; i++)
        {
            cout << "Study Group ID " << i + 1 << ": " << studyGroupID[i];
        }
        // learning post
    }
    void addRelationship(int id, string type) override
    {
        for (int i = 0; i < studentsize; i++)
        {
            if (studentID[i] == id)
            {
                cout << "Already added.\n";
                return;
            }
        }

        if (studentsize < scapacity)
        {

            if (type == "studentFriend")
            {
                studentID[studentsize] = id;
                studentsize++;
                cout << "ID added.\n";
            }
        }
        else
        {
            cout << "Limit exceeded.\n";
        }
    }

    Student &operator+=(int groupId)
    {
        for (int i = 0; i < groupsize; i++)
        {
            if (studyGroupID[i] == groupId)
            {
                cout << "Already added.\n";
                return *this;
            }
        }
        if (groupsize < gcapacity)
        {
            studyGroupID[groupsize] = groupId;
            groupsize++;
        }
        return *this; // usage: arr+=5
    }

    Student &operator+(const LearningPost &post)
    {
        if (postcount < postcapacity)
        {
            l[postcount] = post;
            postcount++;
        }
        return *this;
    }
};
class StudyGroup : public Entity
{
    string groupName;
    string subject;
    int *ID;
    const int idcapacity = 10;
    int idsize = 0;
public:
    StudyGroup(int i, string gN, string s) : Entity(i), groupName(gN), subject(s)
    {
        ID = new int[idcapacity];
    }

    ~StudyGroup() { delete[] ID; }

    void addRelationship(int id, string type) override
    {
        if (idsize < idcapacity)
        {
            if (type == "groupMember")
            {
                ID[idsize] = id;
                idsize++;
                cout << "ID added.\n";
            }
            else
            {
                cout << "Type dont match.\n";
            }
        }
        else
        {
            cout << "Limit reached.\n";
        }
    }
    void displayDetails() override
    {
        cout << "Group Name: " << groupName << endl
             << "Subject: " << subject << endl;
        for (int i = 0; i < idsize; i++)
        {
            cout << "ID: " << ID[i] << endl;
        }
    }
};

int main()
{
    Student s1(101, "Sara", "25K-0678");
    StudyGroup g1(102, "GROUP E", "Physics");
    LearningPost l1("AP Notes", 200);
    s1.addRelationship(101, "studentFriend");
    g1.addRelationship(102, "groupMember");
    s1 += 102; //* adds group ID 102 to student's groups
    s1 + l1;   //* adds l1 post to student's posts
    ++l1;      //* adds a comment to l1
//*  s1 += 102 calls s1.operator+=(102)
//* s1 + l1 calls s1.operator+(l1)
//* ++l1 calls l1.operator++()
    s1.displayDetails();
    cout << endl;
    g1.displayDetails();
    cout << endl;
    l1.displayDetails();
}
*/

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