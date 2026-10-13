#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

/* //! REVERSE A STRING RECURSIVELY
void stringreverse(const char *str)
{
    if (*str == '\0')
        return;

    stringreverse(str + 1);

    cout << *str;
}
int main()
{
    stringreverse("hello");
}
*/

/*//! STACK - array based implementation
class Stack
{
public:
    int capacity;
    int top;
    int *arr;

    Stack(int c) : capacity(c)
    {
        arr = new int[capacity];
        top = -1; // initially stack is empty
    }

    // check if it is empty and is full
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == capacity - 1; }

    // add
    void push(int val)
    {
        if (isFull())
            throw overflow_error("Stack overflow!");

        top = top + 1;
        arr[top] = val;
    }

    int pop()
    {
        if (isEmpty())
            throw underflow_error("Stack Underflow!");

        int poppedVal = arr[top]; // save val first in order to return it
        top = top - 1;
        return poppedVal;
    }

    // return the top item without removing it
    int peek()
    {
        if (isEmpty())
            throw underflow_error("Stack Underflow!");

        return arr[top];
    }

    void printstack()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " | ";
        }
        cout << endl;
    }
};
int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.printstack();
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    s.printstack();
}
*/

/*//! STACK - LL based implementation
struct Node
{
    int info;
    Node *next;
    Node() : next(nullptr) {}
    Node(int i, Node *n = 0) : info(i), next(n) {}
};
class StackLL
{
public:
    Node *top;
    StackLL() : top(nullptr) {}

    bool isEmpty() { return top == 0; }

    void push(int val)
    {
        Node *newNode = new Node(val);

        if (top == nullptr)
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    int pop()
    {
        if (isEmpty())
            throw underflow_error("Stack underflow!");

        int poppedval = top->info;
        Node *temp = top;
        top = top->next;
        delete temp;
        return poppedval;
    }


    int peek()
    {
        if (isEmpty())
            throw underflow_error("Stack underflow!");

        return top->info;
    }

    void printstack()
    {
        Node *temp = top;
        while (temp != 0)
        {
            cout << "[" << temp->info << "]" << " | ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    StackLL s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.printstack();
    cout << s.pop() << endl;
    s.printstack();
    cout << s.peek() << endl;
}
*/

/*//! QUEUE - Array based imp
class Queue
{
public:
    int *arr;
    int front, rear, capacity, size;
    Queue(int cap) : capacity(cap)
    {
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int val)
    {
        if (size >= capacity)
            throw overflow_error("Queue Overflow!");

        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int dequeue()
    {
        if (isEmpty())
            throw underflow_error("Queue Underflow!");

        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }

    int peek()
    {
        if (isEmpty())
            throw underflow_error("Queue Underflow!");

        return arr[front];
    }

    void printqueue()
    {
        for (int i = 0; i < size; i++)
        {
            int j = (front + i) % capacity;
            cout << arr[j] << " | ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.printqueue();
    cout << q.dequeue() << endl
         << q.dequeue() << endl;
    q.printqueue();
    cout << q.peek();
}
*/

/*//! QUEUE - link list imp
class Queue
{
public:
    int info;
    Queue *next;

    Queue() : next(nullptr) {}
    Queue(int i, Queue *n = 0) : info(i), next(n) {}
};

class List
{
public:
    Queue *front;
    Queue *rear;
    List() : front(0), rear(0) {}

    void enqueue(int val)
    {
        Queue *newNode = new Queue(val);
        if (front == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front = newNode;
        }
    }
    bool isEmpty() { return front == nullptr; }

    int dequeue()
    {
        if (isEmpty())
            throw underflow_error("Queue is empty!");
        Queue *temp = front;
        while (temp != rear)
        {
            temp = temp->next;
        }
        int val = temp->info;
        temp->next = nullptr;
        delete rear;
        rear = temp;
        return val;
    }

    int peek()
    {
        Queue *temp = front;
        while (temp != 0)
        {
            temp = temp->next;
        }
        return temp->info;
    }
    void printlist()
    {
        Queue *temp = front;
        while (temp != 0)
        {
            cout << "[" << temp->info << "]" << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    List x;
    x.enqueue(10);
    x.enqueue(20);
    x.enqueue(30);
    x.enqueue(40);
    x.enqueue(50);
    x.printlist();
    cout << x.dequeue() << endl
         << x.dequeue() << endl;
    x.printlist();
    cout << x.peek();
}*/

/*//! LINK LISTS
//! NOTE THAT WHEN TRYING TO RUN THE CODE, USE EITHER THE ORIGINAL OR THE IMPROVED VERSION OF THE FUNCTIONS AND NOT BOTH.
//*a link list is a way to store data. A link list contains of nodes which hold data such as numbers, chars etc + the address of the next node.
class sll //*single linked list
{
public:
    int info;  //*member that contains data
    sll *next; //*pointer variable that contains address of another node. The reason its declared using sll is because this pointer is pointing toward a whole node which contains another info + address. It does not point to the address of a single variable. Think of it like a box of data. The address part of the data points to the next whole box of data.

    sll() : next(nullptr) {} // can take as 0 as well   //* for default constructor, we will only pass the value of next.

    sll(int i, sll *n = 0) //* here n is taken as 0 in case we only pass the info and not the address, so it just takes the address to be 0 like : sll a(10);
    {
        info = i;
        next = n;
    }
};

class List
{
public:
    sll *head;
    sll *tail;

    List()
    {
        head = tail = 0; //* this expression works from right to left. we can more simply write head = null, tail = null
        //* tail = 0;
        //* head = tail;
    }

    ~List()
    {
        while (head != nullptr)
        {
            sll *temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
    }

    bool isEmpty() const
    {
        return head == nullptr; //*will return true if head == nullptr, which shows list is empty, otherwise return false
    }

    void addtoHead(int val)
    {
        head = new sll(val, head); //* a new block is initialized with val + address pointing to current head. Then the box is taken equal to head pointer so when we add a new value in the start, we get a new head.

        if (tail == 0)
        {
            tail = head; //* if tail points to null, then list has only one element, so we take tail equal to that element, due to which both tail and head point to it.
            //* [10] -> null    |
            //*   ^-- head = tail
        }
    }
    //* [10] -> null | [20] -> [10] -> null
    //*  ^--- head       ^---head

    void addtoTail(int val)
    {
        if (tail != 0)
        {
            tail->next = new sll(val); //* the next of last element points to a new block. then the tail pointer is taken equal to tail->next.
            tail = tail->next;
        }
        else
        {
            tail = new sll(val);
            head = tail;
        }
        //* if we do tail = new sll(val, tail), then a new block is taken with next pointing to the current tail. [10] -> [20] -> null  |   [10] -> [20] <- [30]
        //* in this case, tail->next is next of 20 which points to a new block, say 30, with next = null. in the nect line, tail = tail->next = the new block
        //* [10] -> [20] -> null    |   [10] -> [20] -> [30] -> null
        //*           ^--- tail                           ^--- tail
    }

    int deletefromHead()
    {
        if (isEmpty())
        {
            cout << "Cannot delete from an empty list.\n";
            return -1;
        }

        int value = head->info; //*save the first value in "value" though this step is optional. Taking this function as int is optional too, we can simply take it void and delete the first node.
        sll *temp = head;       //* we declare a temperory pointer and save the value of first node in it.

        if (head != tail)
        {
            head = head->next; //*then we shift access of first node to the second node.
        }

        //*  ↓temp
        //* [10] -> [20] -> [30] null
        //*   ^--head

        //* after head = head-> next

        //*  ↓temp
        //* [10] -> [20] -> [30] -> null
        //*           ^--head
        //* then we delete temp. If we directly just shift access of head, we will lose the access to first node but due to not being able to delete, it will still exist in heap memory, which will cause memory leak
        else
        {
            head = tail = 0;
        }

        delete temp;
        return value;
    }

    int deletefromTail()
    {
        if (isEmpty())
        {
            cout << "Cannot delete from an empty list.\n";
            return -1;
        }

        int value = tail->info;
        if (head == tail) //* if only one element exist, delete it
        {
            delete head;
            head = tail = 0;
        }
        else
        {
            sll *temp;                                               //*take a temporary pointer temp. This is the equivalent of taking int i in a for loop.
            for (temp = head; temp->next != tail; temp = temp->next) //*tail already tells us the element we have to delete, but after deleting it, how will we make the previous element point to null + how will we access the previous element at all? Even with tail not deleted at first, a SLL only holds the address of next node only, not the previous one. Therefore we use head pointer to traverse through the list.
                ;                                                    //* we take temp = head, then traverse the list and stop just before tail. this makes temp point to second last element and temp->next point to tail.
            delete tail;                                             //* Then we delete tail
            tail = temp;                                             //* and make temp the new tail
            tail->next = 0;                                          //*then make it point to null
        }
        return value;
    }

    //*Deleting by value can have three cases.
    void deletebyValue(int val) //*dry run this you will understand
    {
        if (isEmpty())
        {
            cout << "Cannot delete from an empty list.\n";
            return;
        }

        if (head != 0) //*In a non-empty list
        {
            if (head == tail && val == head->info) //* case 1: deleting a single element list
            {
                delete head;
                head = tail = 0;
            }
            else if (val == head->info) //*case 2: deleting the head itself
            {
                sll *temp;
                temp = head;
                head = head->next;
                delete temp;
            }

            sll *before, *temp; //*case 3: deleting any non-head node
            for (before = head, temp = head->next; temp != 0 && temp->info != val; before = before->next, temp = temp->next)
                ;

            if (temp != 0)
            {
                before->next = temp->next;

                if (temp == tail) //*the non head node is tail itself so deleting tail
                {
                    tail = before;
                }
                delete temp;
            }
        }
    }

    //*Improved deletebyValue
    void deletebyValue(int value)
    {
        if (isEmpty())
            throw underflow_error("Cannot delete from an empty list");

        if (value == head->info)
        {
            deletefromHead();
            return;
        }

        sll *before = head;
        sll *temp = head->next;

        while (temp != nullptr && temp->info != value)
        {
            before = temp;
            temp = temp->next;
        }

        // Value was not found
        if (temp == nullptr)
            return;

        before->next = temp->next;

        // If the deleted node was the tail, update tail
        if (temp == tail)
            tail = before;

        delete temp;
    }

    int searchforValue(int val) //*dry run this you will understand
    {

        sll *temp;
        for (temp = head; temp != 0 && temp->info != val; temp = temp->next)
            ;
        return temp->info;
    }

    //*Improved searchforValue
    bool searchbyValue(int value)
    {

        for (sll *temp = head; temp != nullptr; temp = temp->next)
        {
            if (temp->info == value)
                return true;
        }

        return false;
    }

    void printList() const
    {
        sll *current = head;

        cout << "[ ";

        while (current != nullptr)
        {
            cout << current->info << " -> ";
            current = current->next;
        }

        cout << "]\n";
    }
};

int main()
{
    List x;
    cout << "Initially: ";
    x.printList();
    cout << endl;
    //*adding elements
    x.addtoHead(10);
    x.addtoHead(8);
    x.addtoHead(20);
    cout << "List: ";
    x.printList();

    x.addtoTail(30);
    x.addtoTail(40);
    cout << "List: ";
    x.printList();

    cout << "\nSearching for 10: ";
    cout << (x.searchforValue(30) ? "Found" : "Not found") << "\n";

    cout << "Searching for 100: ";
    cout << (x.searchforValue(100) ? "Found" : "Not found") << "\n";

    cout << "\nDeleting:\n";
    cout << "Deleted value from head: " << x.deletefromHead() << "\n";
    cout << "Deleted value from tail: " << x.deletefromTail() << "\n";
    cout << "List after deleting from head and tail: ";
    x.printList();

    cout << "\nDeleting the value 10:\n";
    x.deletebyValue(10);
    x.printList();

    cout << "Deleting the value 999:\n";
    x.deletebyValue(999);
    x.printList();

    //*===================ALTERNATE MAIN=====================
    // sll a(20);   //*a.info = 20 and a.next = 0
    // sll b(8, &a);    //* b.info = 8 and b.next will give the address of node a. To access a's data members: b.next->info;  //*pretty self explanatory
    // sll c(10, &b);
    // cout << "Elements: \n";
    // cout << c.info << " -> " << b.info << " -> " << a.info << " -> " << a.next << endl;

    //*------------------------------------------------------------------------
    // sll *p = new sll(10);  //* another way to initialize is using a pointer variable p. this p points to a whole node whose info is 10 and address is 0.
    // p->next = new sll(20); //* now the address, instead of 0, points to the address of another node.
    // p->next->next = new sll(50);
    // delete p->next->next; //* Delete node 50
    // delete p->next;       //* Delete node 8
    // delete p;             //* Delete node 10
    //*The nodes should be deleted from the end toward the beginning so that no node is accessed through an already-deleted pointer.

    // //* This line below would give you the same output as the first element can access the "next" and "next next" elements:
    // cout << c.info << " -> " << c.next->info << " -> " << c.next->next->info << endl; //* "c.next->info"" means that access the info of next element and so on.

    // List y;

    // y.head = &c;
    // y.tail = &a;

    // cout << "\nList before adding new nodes: ";
    // y.printList();
    //* y currently points to stack objects c, b, and a. Calling y's destructor would try to delete stack memory. Therefore, do not use this arrangement with a normal destructor. use functions (addtoHead(), deletefromHead()) instead.
}
*/

/* //!DOUBLE LINK LIST
#include <iostream>
using namespace std;
class dll
{
public:
    int data;
    dll *prev;
    dll *next;

    //* default constructor
    dll() : data(0), prev(nullptr), next(nullptr) {}

    //* param constructor
    dll(int d, dll *p = 0, dll *n = 0) : data(d), prev(p), next(n) {}
};

class Node
{
public:
    dll *head;
    dll *tail;

    Node() : head(nullptr), tail(nullptr) {}

    void addtoHead(int value)
    {
        dll *newNode = new dll(value); // next = prev = 0
        if (head == nullptr)           // if list empty
            head = tail = newNode;
        else
        {
            newNode->next = head; // new node's next should point to current head and current head's previous should point to the new node's previous
            head->prev = newNode;
            head = newNode; // shift access
        }
    }

    void addtoTail(int value)
    {
        dll *newNode = new dll(value);
        if (head == nullptr)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
    void delfromHead()
    {
        if (isEmpty())
            throw underflow_error("List is empty.\n");

        dll *temp = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
    }

    void delfromTail()
    {
        if (isEmpty())
            throw underflow_error("List is empty.\n");

        dll *temp = tail;
        if (tail == head)
        {
            tail = head = 0;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    bool searchbyValue(int value)
    {
        dll *temp = head;
        while (temp != 0)
        {
            if (temp->data == value)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void delbyValue(int value)
    {
        if (isEmpty())
            throw underflow_error("List is empty.\n");

        if (head->data == value)
        {
            delfromHead();
            return;
        }
        dll *temp = head;
        while (temp != 0)
        {
            if (temp->data == value)
            {
                temp->prev->next = temp->next;

                if (temp->next != nullptr)
                    temp->next->prev = temp->prev;
                else
                    tail = temp->prev;

                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    void fwdprint() const
    {
        dll *temp = head;

        while (temp != nullptr)
        {
            cout << "[" << temp->data << "]";

            if (temp->next != nullptr)
                cout << " <-> ";

            temp = temp->next;
        }
        cout << endl;
    }
    void bwdprint() const
    {
        dll *temp = tail;

        while (temp != nullptr)
        {
            cout << "[" << temp->data << "]";

            if (temp->prev != nullptr)
                cout << " <-> ";

            temp = temp->prev;
        }

        cout << endl;
    }
    ~Node()
    {
        dll *current = head;

        while (current != nullptr)
        {
            dll *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main()
{
    Node list;

    list.addtoTail(10);
    list.addtoTail(20);
    list.addtoTail(15);
    list.addtoHead(5);
    list.addtoHead(2);
    cout << "Forward: ";
    list.fwdprint();

    cout << "Backward: ";
    list.bwdprint();

    cout << "Searching 5: ";
    cout << (list.searchbyValue(5) ? "Found" : "Not found") << "\n";

    cout << "Searching 99: ";
    cout << (list.searchbyValue(99) ? "Found" : "Not found") << "\n";

    list.delfromHead();
    list.delfromTail();

    cout << "After deleting head n tail: ";
    list.fwdprint();

    list.delbyValue(10);
    list.fwdprint();
    list.delbyValue(5);
    list.fwdprint();
    list.delbyValue(20);
    list.fwdprint();
    return 0;
}
*/

/* //! CIRCULAR DOUBLE LIST
#include <iostream>
using namespace std;

struct cdll
{
    int data;
    cdll *next;
    cdll *prev;

    cdll(int d, cdll *n = 0, cdll *p = 0) : data(d), next(n), prev(p) {}
};

class List
{
public:
    cdll *head;
    cdll *tail;
    List() : head(nullptr), tail(nullptr) {}
    void addTail(int value)
    {
        cdll *newNode = new cdll(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void addHead(int value)
    {
        cdll *newNode = new cdll(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
    }

    void addpos(int value, int pos)
    {

        if (pos == 1)
        {
            addHead(value);
            return;
        }

        if (pos < 1 || head == nullptr)
        {
            cout << "Position does not exist." << endl;
            return;
        }

        cdll *cur = head;

        for (int i = 1; i < pos - 1; i++)
        {
            cur = cur->next;
        }
        if (cur == tail)
        {
            addTail(value);
            return;
        }

        cdll *newNode = new cdll(value);
        newNode->next = cur->next;
        newNode->prev = cur;
        cur->next->prev = newNode;
        cur->next = newNode;
    }

    void deleteNode(int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        cdll *cur = head;

        do
        {
            if (cur->data == value)
            {
                if (head == tail)
                {
                    delete cur;
                    head = nullptr;
                    tail = nullptr;
                }
                else if (cur == head)
                {
                    head = head->next;

                    head->prev = tail;
                    tail->next = head;

                    delete cur;
                }
                else if (cur == tail)
                {
                    tail = tail->prev;

                    tail->next = head;
                    head->prev = tail;

                    delete cur;
                }
                else
                {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;

                    delete cur;
                }
                cout << "Node deleted successfully." << endl;
                return;
            }
            cur = cur->next;
        } while (cur != head);

        cout << "Value not found." << endl;
    }

    void printList()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        cdll *cur = head;
        do
        {
            cout << cur->data << " ";
            cur = cur->next;

        } while (cur != head);

        cout << endl;
    }

    void printReverse()
    {
        if (tail == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        cdll *cur = tail;

        cout << "Reverse list: ";

        do
        {
            cout << cur->data << " ";
            cur = cur->prev;

        } while (cur != tail);

        cout << endl;
    }

    // destructor
    ~List()
    {
        if (head == nullptr)
        {
            return;
        }

        cdll *cur = head->next;

        while (cur != head)
        {
            cdll *temporary = cur;
            cur = cur->next;
            delete temporary;
        }

        delete head;

        head = nullptr;
        tail = nullptr;
    }
};

int main()
{
    List list;

    int choice;
    int value;
    int pos;

    do
    {
        cout << "\n--- CDLL ---\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at beginning\n";
        cout << "3. Insert at pos\n";
        cout << "4. Delete node\n";
        cout << "5. Print list\n";
        cout << "6. Print reverse list\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.addTail(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.addHead(value);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter pos: ";
            cin >> pos;

            list.addpos(value, pos);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;

        case 5:
            list.printList();
            break;

        case 6:
            list.printReverse();
            break;

        case 7:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 7);

    return 0;
}
*/

/*//! MERGE TWO LISTS
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *mH = nullptr;
        ListNode *mT = nullptr;

        // Select the node and add it in the master merged list
        ListNode *selected = nullptr;

        while (list1 != nullptr && list2 != nullptr)
        {
            // comparison
            if (list1->val <= list2->val)
            {
                selected = list1;
                list1 = list1->next;
            }
            else
            {
                selected = list2;
                list2 = list2->next;
            }
            // detachment so that we can make sure to add only one node with none connecting it after
            selected->next = nullptr;
            if (mH == nullptr)
            {
                mH = mT = selected;
            }
            else
            {
                mT->next = selected;
                mT = selected;
            }
        }

        // if one of the node ends, continue selecting the next one.
        if (mH == nullptr)
        {
            if (list1 != nullptr)
            {
                return list1;
            }
            return list2;
        }
        if (list1 != nullptr)
            mT->next = list1;
        else
            mT->next = list2;

        return mH;
    }
};

*/

//! SEARCHES ON LINK LISTS
//! BUBBLE ON LINK LIST
//! SELECTION ON LINK LIST
//! INSERTION ON LINK LIST
//! COMB ON LINK LIST
//! SHELL ON LINK LIST

/*  //! RADIX SORT
int main()
{
    int arr[] = {500, 499, 38, 2, 770, 802};
    int n = 6;
    //* Find the max number. Reason: To get maximum number of digits which will determine how many passes will it take to sort the array.
    int maxNo = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxNo)
        {
            maxNo = arr[i];
        }
    }

    int output[6] = {0};
    //* formula to find digits: num/place  % 10
    //* for an array, digits = arr[i]/place %10
    //* we start with place = 1 because the smallest place is ones; we take the range till maxNo/place>0 because if maxNo is divided by a place greater than its' digits place, the answer becomes 0, say the largest in this case is 802. 802 divided by 1, 10 n 100 give >0 but with 1000 it gives 0; the sequence in which places increase are 1, 10 , 100, 1000. the pattern is 10 being divided each time so place*10;

    for (int place = 1; maxNo / place > 0; place *= 10)
    {
        int count[10] = {0};

        for (int i = 0; i < n; i++)
        {
            int digit = (arr[i] / place) % 10;
            count[digit]++; //* whatever the digit comes, increment that position's value.
        }

        cout << "\nCount for " << place << ": ";
        for (int i = 0; i < 10; i++)
        {
            cout << count[i] << " ";
        }
        //*this tells how many numbers are there before and at a certain digit.
        //* say count[1] = 0+2 = 2. This means there are two numbers with either 0 or 1 digit at less than equal to 1.
        //* Whatever we get from count[i], we subtract it from 1. Say count[2]= 4 -1 = 3. This shows that for pos 2, there are 3 elements with either digits -> 0, 1, and 2. After we place them accordingly, we decrement the count.
        for (int i = 1; i < 10; i++)
        {
            count[i] = count[i] + count[i - 1];
        }

        cout << "\nCount for " << place << ": ";
        for (int i = 0; i < 10; i++)
            cout << count[i] << " ";
        cout << endl;

        //* we now traverse the array from right to left for stability and add the actual numbers accordingly in output. For stability, the count array should go from left to right and the current one should go from right to left. Otherwise we get unsorted array.
        //* Think of it like this:
        //*Count for place 1: 2 0 2 0 0 0 0 0 1 1
        //*Count for place 1: 2 2 4 4 4 4 4 4 5 6

        for (int i = n - 1; i >= 0; i--) //* for the rightmose digit "802", digit = 2. then
        {
            int digit = (arr[i] / place) % 10;
            output[count[digit] - 1] = arr[i]; //*output[count[2]-1] = output[4-1] = output[3]. then output[3] = arr[5].
            count[digit]--;                    //*count[2]-- = 4-- = 3. Now when it checks for number 2, its count[i] will show 3 instead of 4.
        }

        //*count[d] always points to the "rightmost empty spot" for digit d. So to keep order, the "last element with digit d" we see should go to the "rightmost spot". To make the last element go to the rightmost spot, we have to see it last. That’s why we scan the input array backwards.
        for (int i = 0; i < n; i++)
        {
            arr[i] = output[i];
        }
    }

    cout << "\nArray: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
*/

/*  //! COMB SORT
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
        gap = gap / 1.3;
        if (gap < 1)
            gap = 1;

        //*start
        swapped = false;
        for (int i = 0; i + gap < n; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
*/

/* //! INSERTION SORT
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
*/

/* //! ARRAYS USING STRUCTS
 */

/* //! DOUBLE POINTERS (MATRIX) ALLOCATION + USING RULE OF 3
* ALLOCATION syntax -->

    int** data;
    data = new int*[rows]; //* say rows = 3, this will create space for 3 int pointers, not the rows themself. Each row pointer must be made to point to a dynamically allocated col.
    for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++){
                data[i][j] = 0;     //*merely fills in zero at all positions.
            } }
*The row structure looks like:
data
 │
 ├── data[0]  // int*
 ├── data[1]  // int*
 └── data[2]  // int*

*after the first for loop, it looks like:   the statement inside the loop allocates int space for one row pointer.
 data
 │
 ├──► data[0]: [ int ][ int ][ int ][ int ]
 ├──► data[1]: [ int ][ int ][ int ][ int ]
 └──► data[2]: [ int ][ int ][ int ][ int ]

*DELETION:
 ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];      //* first delete the ints inside each row,
        }
        delete[] data;      //*then delete the pointer holding these ints. Think of data like a cabinet and data[i] like drawers inside the cabinet. To delete the cabinet, you first delete the drawers(columns), and then delete the cabinet pointer as well.
    }   //* Also since we're using two "new's", we have to delete two times.

*DEEP COPY CONSTRUCTOR:
Matrix(const Matrix& other): rows(other.rows), cols(other.cols){    //*allocation of sizes (usual stuff)
//*allocating memory
data = new int* [rows];
for(int i = 0; i < rows; i++){
data[i] = new int[cols];

for(int j = 0; j < cols; j++){
data[i][j] = other.data[i][j];    //*copying data. Similar to when we first allocated the parameterized constructor, just this time, we copy real values instead of putting in zeros
} } }

*COPY ASSIGNMENT OPERATOR
Matrix &operator=(const Matrix &other){
if(this != &other){     //*step 1: avoid self assignment
  int** newData = new int* [other.rows];    //*step 2: allocate a new row-pointer array
//* step 3: allocate and copy every row
  for(int i = 0; i < other.rows; i++){
    newData = new int[other.cols];

  for(int j = 0; j < other.cols; j++){
    newData[i][j] = other.data[i][j];
  } }
//* step 4: delete the old matrix
  for(int i = 0; i < other.rows; i++)
    delete[] data[i];

  delete[] data;
//* step 5: take ownership
  rows = other.rows;
  cols = other.cols;
  data = newData;

}
  return *this;
}

*OPERATOR+
*we can add matrix elements normally by using loops but we cant write something like Matrix C = A + B.
Matrix& operator+(const Matrix& other){
Matrix result(rows, cols);      //* create an object in which the sum(result) is stored

for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
        result.data[i][j] = data[i][j] + other.data[i][j];
} }
return result;
}

?WHOLE PROGRAM
class Matrix
{
    int rows;
    int cols;
    int **data;

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    //* functions for bounds checking, inputting values
    bool validBounds(int r, int c)
    {
        if ((r < 0 && r >= rows) || (c < 0 && c >= cols))
            return false;
        else
            return true;
    }

    void set(int r, int c, int value)
    {
        if (validBounds(r, c))
            data[r][c] = value;
        else
            cout << "Invalid bounds.\n";
    }

    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols)
    {
        data = new int *[other.rows];
        for (int i = 0; i < other.rows; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < other.cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }
    Matrix &operator=(const Matrix &other)
    {
    if(this!=other){
        int **newData = new int *[other.rows];
        for (int i = 0; i < other.rows; i++)
        {
            newData[i] = new int[cols];
            for (int j = 0; j < other.cols; j++)
            {
                newData[i][j] = other.data[i][j];
            }
        }
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;

        rows = other.rows;
        cols = other.cols;
        data = newData;
        }
        return *this;
    }

    Matrix operator+(const Matrix &other)
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Matrix A(2, 2), B(2, 2);
    A.set(0, 0, 3);
    A.set(0, 1, 4);
    A.set(1, 0, 5);
    A.set(1, 1, 6);

    B.set(0, 0, 7);
    B.set(0, 1, 6);
    B.set(1, 0, 5);
    B.set(1, 1, 4);

    cout << "A: " << endl;
    A.display();
    cout << endl
         << "B: \n";
    B.display();
    cout << endl;

    Matrix A1(A);
    Matrix A2 = A;
    A1.set(0, 0, 30);
    A2.set(0, 0, 31);

    Matrix C = A + B;
    cout << "Sum C: \n";
    C.display();
    cout << endl;

    cout << "A1: \n";
    A1.display();
    cout << endl;
    A2.display();

    B.set(-1, 5, 100);
}

?Similar program, just easier
class DynamicArray
{
    int *arr;
    int size;
    int capacity;

public:
    DynamicArray() : size(0), capacity(2)
    {
        arr = new int[capacity];
    }
    DynamicArray(const DynamicArray &other) : size(other.size), capacity(other.capacity)
    {
        arr = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    DynamicArray &operator=(const DynamicArray &other)
    {
        if (this != &other)
        {
            int *newarr = new int[other.capacity];
            for (int i = 0; i < other.size; i++)
            {
                newarr[i] = other.arr[i];
            }
            delete[] arr;
            capacity = other.capacity;
            size = other.size;
            arr = newarr;
        }
        return *this;
    }

    ~DynamicArray()
    {
        delete[] arr;
    }

    void pushBack(int val)
    {
        if (size == capacity)
        {
            int newcap = capacity * 2;
            int *newarr = new int[newcap];
            for (int i = 0; i < size; i++)
            {
                newarr[i] = arr[i];
            }
            delete[] arr;
            capacity = newcap;
            arr = newarr;
        }

        arr[size] = val;
        size++;
    }

    int &operator[](int index)
    {
        if (index < 0 || index >= size)
            throw out_of_range("Index is out of range.\n");
        return arr[index];
    }

    const int &operator[](int index) const
    {
        if (index < 0 || index >= size)
            throw out_of_range("Index is out of range.\n");
        return arr[index];
    }

    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    DynamicArray obj;
    obj.pushBack(10);
    obj.pushBack(20);
    obj.pushBack(30);
    obj.pushBack(40);
    obj.pushBack(50);
    obj.pushBack(60);
    cout << "OBJECT: ";
    obj.print();
    cout << endl;
    DynamicArray obj2;
    obj2 = obj;
    cout << "COPY: ";
    obj2.print();
    cout << endl;
    obj2[0] = 1000;
    cout << "MODIFIED OBJ AND COPY: \n";
    obj.print();
    cout << endl;
    obj2.print();
    cout << endl;
}

*/
