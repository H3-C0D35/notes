#include <iostream>
using namespace std;

//! LINK LISTS
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

    int searchforValue(int val) //*dry run this you will understand
    {

        sll *temp;
        for (temp = head; temp != 0 && temp->info != val; temp = temp->next)
            ;
        return temp->info;
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

/* //! SELECTION SORT
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
