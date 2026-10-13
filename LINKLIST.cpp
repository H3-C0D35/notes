#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

// Linked List class
class LinkedList
{
private:
    Node *head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList()
    {
        clear();
    }

    // Copy constructor
    LinkedList(const LinkedList &other) : head(nullptr), size(0)
    {
        Node *current = other.head;

        while (current != nullptr)
        {
            push_back(current->data);
            current = current->next;
        }
    }

    // Assignment operator
    LinkedList &operator=(const LinkedList &other)
    {
        if (this != &other)
        {
            clear();

            Node *current = other.head;

            while (current != nullptr)
            {
                push_back(current->data);
                current = current->next;
            }
        }

        return *this;
    }

    // Insert at the beginning
    void push_front(int value)
    {
        Node *newNode = new Node(value);

        newNode->next = head;
        head = newNode;
        size++;
    }

    // Insert at the end
    void push_back(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;

            while (current->next != nullptr)
            {
                current = current->next;
            }

            current->next = newNode;
        }

        size++;
    }

    // Insert at a specific position
    bool insert_at(int value, int position)
    {
        if (position < 0 || position > size)
        {
            return false;
        }

        if (position == 0)
        {
            push_front(value);
            return true;
        }

        Node *current = head;

        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }

        Node *newNode = new Node(value);

        newNode->next = current->next;
        current->next = newNode;
        size++;

        return true;
    }

    // Remove from the beginning
    bool pop_front()
    {
        if (head == nullptr)
        {
            return false;
        }

        Node *nodeToDelete = head;
        head = head->next;

        delete nodeToDelete;
        size--;

        return true;
    }

    // Remove from the end
    bool pop_back()
    {
        if (head == nullptr)
        {
            return false;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *current = head;

            while (current->next->next != nullptr)
            {
                current = current->next;
            }

            delete current->next;
            current->next = nullptr;
        }

        size--;
        return true;
    }

    // Remove at a specific position
    bool remove_at(int position)
    {
        if (position < 0 || position >= size)
        {
            return false;
        }

        if (position == 0)
        {
            return pop_front();
        }

        Node *current = head;

        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }

        Node *nodeToDelete = current->next;
        current->next = nodeToDelete->next;

        delete nodeToDelete;
        size--;

        return true;
    }

    // Remove the first occurrence of a value
    bool remove_by_value(int value)
    {
        if (head == nullptr)
        {
            return false;
        }

        if (head->data == value)
        {
            return pop_front();
        }

        Node *current = head;

        while (current->next != nullptr &&
               current->next->data != value)
        {
            current = current->next;
        }

        if (current->next == nullptr)
        {
            return false;
        }

        Node *nodeToDelete = current->next;
        current->next = nodeToDelete->next;

        delete nodeToDelete;
        size--;

        return true;
    }

    // Search for a value
    int search(int value) const
    {
        Node *current = head;
        int index = 0;

        while (current != nullptr)
        {
            if (current->data == value)
            {
                return index;
            }

            current = current->next;
            index++;
        }

        return -1;
    }

    // Get a value at a specific position
    bool get_at(int position, int &value) const
    {
        if (position < 0 || position >= size)
        {
            return false;
        }

        Node *current = head;

        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }

        value = current->data;
        return true;
    }

    // Update a value at a specific position
    bool update_at(int position, int value)
    {
        if (position < 0 || position >= size)
        {
            return false;
        }

        Node *current = head;

        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }

        current->data = value;
        return true;
    }

    // Get the size
    int get_size() const
    {
        return size;
    }

    // Check if empty
    bool is_empty() const
    {
        return head == nullptr;
    }

    // Delete all nodes
    void clear()
    {
        while (head != nullptr)
        {
            Node *nodeToDelete = head;
            head = head->next;

            delete nodeToDelete;
        }

        size = 0;
    }

    // Reverse the list
    void reverse()
    {
        Node *previous = nullptr;
        Node *current = head;

        while (current != nullptr)
        {
            Node *nextNode = current->next;

            current->next = previous;
            previous = current;
            current = nextNode;
        }

        head = previous;
    }

    // Print the list
    void print() const
    {
        Node *current = head;

        cout << "List: ";

        while (current != nullptr)
        {
            cout << current->data;

            if (current->next != nullptr)
            {
                cout << " -> ";
            }

            current = current->next;
        }

        cout << " -> NULL" << endl;
    }

    // Print size and list
    void print_details() const
    {
        cout << "Size: " << size << ", ";
        print();
    }
};

int main()
{
    LinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);
    list.insert_at(15, 2);

    list.print_details();

    cout << "Position of 20: "
         << list.search(20) << endl;

    int value;

    if (list.get_at(2, value))
    {
        cout << "Value at position 2: "
             << value << endl;
    }

    list.update_at(2, 25);
    list.print();

    list.remove_by_value(25);
    list.print();

    list.reverse();
    list.print();

    LinkedList copyList = list;
    copyList.print();

    return 0;
}

//! ===============DOUBLE========================
#include <iostream>
using namespace std;

// Node for the doubly linked list
class dll
{
public:
    int data;
    dll *prev;
    dll *next;

    // Default constructor
    dll() : data(0), prev(nullptr), next(nullptr) {}

    // Parameterized constructor
    dll(int value, dll *previous = nullptr, dll *nextNode = nullptr)
        : data(value), prev(previous), next(nextNode) {}
};

// Doubly linked list class
class Node2
{
public:
    dll *head;
    dll *tail;
    int size;

    // Constructor
    Node2() : head(nullptr), tail(nullptr), size(0) {}

    // Copy constructor
    Node2(const Node2 &other) : head(nullptr), tail(nullptr), size(0)
    {
        dll *current = other.head;

        while (current != nullptr)
        {
            addtoTail(current->data);
            current = current->next;
        }
    }

    // Assignment operator
    Node2 &operator=(const Node2 &other)
    {
        if (this != &other)
        {
            clear();

            dll *current = other.head;

            while (current != nullptr)
            {
                addtoTail(current->data);
                current = current->next;
            }
        }

        return *this;
    }

    // Destructor
    ~Node2()
    {
        clear();
    }

    // Check if the list is empty
    bool isEmpty() const
    {
        return head == nullptr;
    }

    // Add a value to the beginning
    void addtoHead(int value)
    {
        dll *newNode = new dll(value);

        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        size++;
    }

    // Add a value to the end
    void addtoTail(int value)
    {
        dll *newNode = new dll(value);

        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        size++;
    }

    // Insert a value at a specific position
    bool insert_at(int value, int position)
    {
        if (position < 0 || position > size)
        {
            return false;
        }

        if (position == 0)
        {
            addtoHead(value);
            return true;
        }

        if (position == size)
        {
            addtoTail(value);
            return true;
        }

        dll *current;

        // Start from the closer end
        if (position < size / 2)
        {
            current = head;

            for (int i = 0; i < position; i++)
            {
                current = current->next;
            }
        }
        else
        {
            current = tail;

            for (int i = size - 1; i > position; i--)
            {
                current = current->prev;
            }
        }

        dll *newNode = new dll(value);

        newNode->prev = current->prev;
        newNode->next = current;

        current->prev->next = newNode;
        current->prev = newNode;

        size++;
        return true;
    }

    // Remove the first node
    bool delfromHead()
    {
        if (isEmpty())
        {
            return false;
        }

        dll *nodeToDelete = head;

        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }

        delete nodeToDelete;
        size--;

        return true;
    }

    // Remove the last node
    bool delfromTail()
    {
        if (isEmpty())
        {
            return false;
        }

        dll *nodeToDelete = tail;

        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete nodeToDelete;
        size--;

        return true;
    }

    // Remove a node at a specific position
    bool remove_at(int position)
    {
        if (position < 0 || position >= size)
        {
            return false;
        }

        if (position == 0)
        {
            return delfromHead();
        }

        if (position == size - 1)
        {
            return delfromTail();
        }

        dll *current;

        // Start from the closer end
        if (position < size / 2)
        {
            current = head;

            for (int i = 0; i < position; i++)
            {
                current = current->next;
            }
        }
        else
        {
            current = tail;

            for (int i = size - 1; i > position; i--)
            {
                current = current->prev;
            }
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        delete current;
        size--;

        return true;
    }

    // Search for a value
    int search(int value) const
    {
        dll *current = head;
        int index = 0;

        while (current != nullptr)
        {
            if (current->data == value)
            {
                return index;
            }

            current = current->next;
            index++;
        }

        return -1;
    }

    // Search by value
    bool searchbyValue(int value) const
    {
        return search(value) != -1;
    }

    // Remove the first node containing a value
    bool delbyValue(int value)
    {
        dll *current = head;

        while (current != nullptr)
        {
            if (current->data == value)
            {
                if (current == head)
                {
                    return delfromHead();
                }

                if (current == tail)
                {
                    return delfromTail();
                }

                current->prev->next = current->next;
                current->next->prev = current->prev;

                delete current;
                size--;

                return true;
            }

            current = current->next;
        }

        return false;
    }

    // Get the value at a specific position
    bool get_at(int position, int &value) const
    {
        if (position < 0 || position >= size)
        {
            return false;
        }

        dll *current;

        if (position < size / 2)
        {
            current = head;

            for (int i = 0; i < position; i++)
            {
                current = current->next;
            }
        }
        else
        {
            current = tail;

            for (int i = size - 1; i > position; i--)
            {
                current = current->prev;
            }
        }

        value = current->data;
        return true;
    }

    // Update the value at a specific position
    bool update_at(int position, int value)
    {
        if (position < 0 || position >= size)
        {
            return false;
        }

        dll *current;

        if (position < size / 2)
        {
            current = head;

            for (int i = 0; i < position; i++)
            {
                current = current->next;
            }
        }
        else
        {
            current = tail;

            for (int i = size - 1; i > position; i--)
            {
                current = current->prev;
            }
        }

        current->data = value;
        return true;
    }

    // Return the number of nodes
    int get_size() const
    {
        return size;
    }

    // Delete all nodes
    void clear()
    {
        dll *current = head;

        while (current != nullptr)
        {
            dll *nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Reverse the list
    void reverse()
    {
        dll *current = head;

        while (current != nullptr)
        {
            dll *temporary = current->next;

            current->next = current->prev;
            current->prev = temporary;

            current = temporary;
        }

        dll *temporary = head;
        head = tail;
        tail = temporary;
    }

    // Print from head to tail
    void fwdprint() const
    {
        dll *current = head;

        cout << "Forward: ";

        while (current != nullptr)
        {
            cout << current->data;

            if (current->next != nullptr)
            {
                cout << " <-> ";
            }

            current = current->next;
        }

        cout << " <-> NULL" << endl;
    }

    // Print from tail to head
    void bwdprint() const
    {
        dll *current = tail;

        cout << "Backward: ";

        while (current != nullptr)
        {
            cout << current->data;

            if (current->prev != nullptr)
            {
                cout << " <-> ";
            }

            current = current->prev;
        }

        cout << " <-> NULL" << endl;
    }

    // Print size and both directions
    void print_details() const
    {
        cout << "Size: " << size << endl;
        fwdprint();
        bwdprint();
    }
};

int main()
{
    Node2 list;

    // Add values to the end
    list.addtoTail(10);
    list.addtoTail(20);
    list.addtoTail(30);

    list.print_details();

    cout << endl;

    // Add values to the beginning
    list.addtoHead(5);
    list.addtoHead(1);

    list.print_details();

    cout << endl;

    // Insert at position 2
    list.insert_at(15, 2);
    list.print_details();

    cout << endl;

    // Search for a value
    int position = list.search(20);

    if (position != -1)
    {
        cout << "20 found at position " << position << endl;
    }
    else
    {
        cout << "20 was not found" << endl;
    }

    cout << endl;

    // Get a value
    int value;

    if (list.get_at(3, value))
    {
        cout << "Value at position 3: " << value << endl;
    }

    cout << endl;

    // Update a value
    list.update_at(2, 25);
    list.print_details();

    cout << endl;

    // Delete from the beginning
    list.delfromHead();
    list.print_details();

    cout << endl;

    // Delete from the end
    list.delfromTail();
    list.print_details();

    cout << endl;

    // Delete at a position
    list.remove_at(2);
    list.print_details();

    cout << endl;

    // Delete by value
    list.delbyValue(15);
    list.print_details();

    cout << endl;

    // Reverse the list
    list.reverse();
    list.print_details();

    cout << endl;

    // Copy constructor
    Node2 copiedList = list;

    cout << "Copied list:" << endl;
    copiedList.print_details();

    cout << endl;

    // Assignment operator
    Node2 assignedList;
    assignedList = list;

    cout << "Assigned list:" << endl;
    assignedList.print_details();

    cout << endl;

    // Clear the list
    list.clear();

    cout << "After clearing original list:" << endl;
    list.print_details();

    return 0;
}

//! ========================CIRCULAR==============================
#include <iostream>
using namespace std;

// Node for the circular singly linked list
class csll
{
public:
    int data;
    csll *next;

    // Default constructor
    csll() : data(0), next(nullptr) {}

    // Parameterized constructor
    csll(int value, csll *nextNode = nullptr)
        : data(value), next(nextNode) {}
};

// Circular singly linked list
class CircularLinkedList
{
public:
    csll *head;
    csll *tail;
    int size;

    // Constructor
    CircularLinkedList()
        : head(nullptr), tail(nullptr), size(0) {}

    // Copy constructor
    CircularLinkedList(const CircularLinkedList &other)
        : head(nullptr), tail(nullptr), size(0)
    {

        if (other.head == nullptr)
        {
            return;
        }

        csll *current = other.head;

        do
        {
            addtoTail(current->data);
            current = current->next;
        } while (current != other.head);
    }

    // Assignment operator
    CircularLinkedList &operator=(
        const CircularLinkedList &other)
    {
        if (this != &other)
        {
            clear();

            if (other.head != nullptr)
            {
                csll *current = other.head;

                do
                {
                    addtoTail(current->data);
                    current = current->next;
                } while (current != other.head);
            }
        }

        return *this;
    }

    // Destructor
    ~CircularLinkedList()
    {
        clear();
    }

    // Check if the list is empty
    bool isEmpty() const
    {
        return head == nullptr;
    }

    // Add a node to the beginning
    void addtoHead(int value)
    {
        csll *newNode = new csll(value);

        if (isEmpty())
        {
            head = tail = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }

        size++;
    }

    // Add a node to the end
    void addtoTail(int value)
    {
        csll *newNode = new csll(value);

        if (isEmpty())
        {
            head = tail = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    // Insert at a specific position
    bool insert_at(int value, int position)
    {
        if (position < 0 || position > size)
        {
            return false;
        }

        if (position == 0)
        {
            addtoHead(value);
            return true;
        }

        if (position == size)
        {
            addtoTail(value);
            return true;
        }

        csll *current = head;

        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }

        csll *newNode = new csll(value);

        newNode->next = current->next;
        current->next = newNode;

        size++;
        return true;
    }

    // Delete from the beginning
    bool delfromHead()
    {
        if (isEmpty())
        {
            return false;
        }

        csll *nodeToDelete = head;

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }

        delete nodeToDelete;
        size--;

        return true;
    }

    // Delete from the end
    bool delfromTail()
    {
        if (isEmpty())
        {
            return false;
        }

        csll *nodeToDelete = tail;

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            csll *current = head;

            while (current->next != tail)
            {
                current = current->next;
            }

            tail = current;
            tail->next = head;
        }

        delete nodeToDelete;
        size--;

        return true;
    }

    // Delete at a specific position
    bool remove_at(int position)
    {
        if (position < 0 || position >= size)
        {
            return false;
        }

        if (position == 0)
        {
            return delfromHead();
        }

        if (position == size - 1)
        {
            return delfromTail();
        }

        csll *current = head;

        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }

        csll *nodeToDelete = current->next;
        current->next = nodeToDelete->next;

        delete nodeToDelete;
        size--;

        return true;
    }

    // Search for a value and return its position
    int search(int value) const
    {
        if (isEmpty())
        {
            return -1;
        }

        csll *current = head;
        int index = 0;

        do
        {
            if (current->data == value)
            {
                return index;
            }

            current = current->next;
            index++;

        } while (current != head);

        return -1;
    }

    // Search for a value
    bool searchbyValue(int value) const
    {
        return search(value) != -1;
    }

    // Delete the first node containing a value
    bool delbyValue(int value)
    {
        if (isEmpty())
        {
            return false;
        }

        if (head->data == value)
        {
            return delfromHead();
        }

        csll *previous = head;
        csll *current = head->next;

        while (current != head)
        {
            if (current->data == value)
            {
                previous->next = current->next;

                if (current == tail)
                {
                    tail = previous;
                }

                delete current;
                size--;

                return true;
            }

            previous = current;
            current = current->next;
        }

        return false;
    }

    // Get the value at a specific position
    bool get_at(int position, int &value) const
    {
        if (position < 0 || position >= size || isEmpty())
        {
            return false;
        }

        csll *current = head;

        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }

        value = current->data;
        return true;
    }

    // Update the value at a specific position
    bool update_at(int position, int value)
    {
        if (position < 0 || position >= size || isEmpty())
        {
            return false;
        }

        csll *current = head;

        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }

        current->data = value;
        return true;
    }

    // Get the size
    int get_size() const
    {
        return size;
    }

    // Clear the list
    void clear()
    {
        if (isEmpty())
        {
            return;
        }

        csll *current = head;

        for (int i = 0; i < size; i++)
        {
            csll *nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Reverse the circular linked list
    void reverse()
    {
        if (size <= 1)
        {
            return;
        }

        csll *previous = tail;
        csll *current = head;

        do
        {
            csll *nextNode = current->next;

            current->next = previous;
            previous = current;
            current = nextNode;

        } while (current != head);

        csll *oldHead = head;
        head = tail;
        tail = oldHead;

        tail->next = head;
    }

    // Print the list once from head to tail
    void print() const
    {
        if (isEmpty())
        {
            cout << "List is empty." << endl;
            return;
        }

        csll *current = head;

        cout << "List: ";

        do
        {
            cout << current->data;

            if (current->next != head)
            {
                cout << " -> ";
            }

            current = current->next;

        } while (current != head);

        cout << " -> back to head" << endl;
    }

    // Print details
    void print_details() const
    {
        cout << "Size: " << size << endl;
        cout << "Head: " << head->data << endl;
        cout << "Tail: " << tail->data << endl;
        print();
    }
};

int main()
{
    CircularLinkedList list;

    // Add values to the end
    list.addtoTail(10);
    list.addtoTail(20);
    list.addtoTail(30);

    list.print_details();

    cout << endl;

    // Add values to the beginning
    list.addtoHead(5);
    list.addtoHead(1);

    list.print_details();

    cout << endl;

    // Insert at position 2
    list.insert_at(15, 2);
    list.print_details();

    cout << endl;

    // Search for a value
    int position = list.search(20);

    if (position != -1)
    {
        cout << "20 found at position " << position << endl;
    }
    else
    {
        cout << "20 was not found" << endl;
    }

    cout << endl;

    // Get a value
    int value;

    if (list.get_at(3, value))
    {
        cout << "Value at position 3: " << value << endl;
    }

    cout << endl;

    // Update a value
    list.update_at(2, 25);
    list.print();

    cout << endl;

    // Delete from the beginning
    list.delfromHead();
    list.print();

    cout << endl;

    // Delete from the end
    list.delfromTail();
    list.print();

    cout << endl;

    // Delete at a specific position
    list.remove_at(2);
    list.print();

    cout << endl;

    // Delete by value
    list.delbyValue(15);
    list.print();

    cout << endl;

    // Add values and reverse the list
    list.addtoTail(100);
    list.addtoTail(200);
    list.addtoTail(300);

    cout << "Before reverse:" << endl;
    list.print();

    list.reverse();

    cout << "After reverse:" << endl;
    list.print();

    cout << endl;

    // Copy constructor
    CircularLinkedList copiedList = list;

    cout << "Copied list:" << endl;
    copiedList.print();

    cout << endl;

    // Assignment operator
    CircularLinkedList assignedList;
    assignedList = list;

    cout << "Assigned list:" << endl;
    assignedList.print();

    cout << endl;

    // Clear the list
    list.clear();

    cout << "After clearing original list:" << endl;
    list.print();

    return 0;
}
