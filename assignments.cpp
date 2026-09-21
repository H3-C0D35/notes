/*//!ASSIGNMENT
class Product
{
public:
    int id;
    string name;
    string cat;
    double price;
    Product *next;

    Product() : next(nullptr) {}
    Product(int id, string n, string cat, double p, Product *next = 0) : id(id), name(n), cat(cat), price(p), next(next) {}
};

class Node
{
public:
    Product *head;
    Product *tail;
    Node() : head(0), tail(0) {}

    // run time input of link list vals
    Product *createProduct()
    {
        Product *newNode = new Product();
        cout << "ID: ";
        cin >> newNode->id;

        cin.ignore();
        cout << "Name: ";
        getline(cin, newNode->name);

        cin.ignore();
        cout << "Category: ";
        getline(cin, newNode->cat);

        cout << "Price: ";
        cin >> newNode->price;

        newNode->next = nullptr;

        return newNode;
    }

    void addProduct()
    {
        Product *newNode = createProduct();
        sortlist(newNode);
    }
    void printlist(const string &listname)
    {
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }
        Product *temp = head;
        cout << "\n----" << listname << "----\n";
        while (temp != 0)
        {
            cout << "ID: " << temp->id << " | Name: " << temp->name << " | Category " << temp->cat << " | Price: " << temp->price << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    void sortlist(Product *&newNode)
    {
        if (head == 0)
        {
            head = tail = newNode;
            return;
        }
        // insert before head
        else if (head->id > newNode->id)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Product *cur = head;
        while (cur != 0 && cur->next->id < newNode->id)
        {
            cur = cur->next;
        }

        if (cur->next != nullptr && cur->next->id == newNode->id)
        {
            Product *dup = cur->next;

            if (newNode->price < dup->price)
            {
                newNode->next = dup->next;
                cur->next = newNode;

                if (dup == tail)
                    tail = newNode;

                delete dup;
            }
            else
            {
                delete newNode;
            }

            return;
        }

        newNode->next = cur->next;
        cur->next = newNode;
        if (newNode->next = 0)
        {
            tail = newNode;
        }
    }

    Product *mergeList(Product *&gc, Product *&bh)
    {
        Product *mergeHead = nullptr;
        Product *mergeTail = nullptr;
        // if gc is empty, just select beauty hub blocks
        while (gc != nullptr && bh != nullptr)
        {
            Product *selected = nullptr;
            if (gc == nullptr)
            {
                selected = bh;
                bh = bh->next;
            }
            else if (bh == nullptr)
            {
                selected = gc;
                gc = gc->next;
            }
            else if (gc->id < bh->id)
            {
                selected = gc;
                gc = gc->next;
            }
            else if (gc->id > bh->id)
            {
                selected = bh;
                bh = bh->next;
            }
            else
            {
                Product *discarded = nullptr;
                if (gc->price <= bh->price)
                {
                    selected = gc;
                    discarded = bh;
                }
                else
                {
                    selected = bh;
                    discarded = gc;
                }
                gc = gc->next;
                bh = bh->next;
                delete discarded;
            }

            // detachment
            selected->next = nullptr;

            if (mergeHead == nullptr)
            {
                mergeHead = mergeTail = selected;
            }
            else
            {
                mergeTail->next = selected;
                mergeTail = selected;
            }
        }
        return mergeHead;
    }
};
int main()
{
    Node glowCare;
    Node beautyHub;
    Node masterList;

    int glowCount;
    int beautyCount;

    cout << "How many products for GlowCare? ";
    cin >> glowCount;

    for (int i = 0; i < glowCount; i++)
    {
        cout << "\nEnter GlowCare product " << i + 1 << ":\n";
        glowCare.addProduct();
    }

    cout << "\nHow many products for BeautyHub? ";
    cin >> beautyCount;

    for (int i = 0; i < beautyCount; i++)
    {
        cout << "\nEnter BeautyHub product " << i + 1 << ":\n";
        beautyHub.addProduct();
    }

    glowCare.printlist("GlowCare Products");
    beautyHub.printlist("BeautyHub Products");

    Node *glowHead = glowCare.getHead();
    Node *beautyHead = beautyHub.getHead();

    Product *masterHead =
        ProductList::mergeLists(glowHead, beautyHead, masterTail);

    // The original lists no longer own their nodes.

    masterList.printlist("Master Product List");

    cout << "\nTotal number of products: "
         << masterList.countProducts() << endl;

    cout << "Total inventory value: $"
         << masterList.totalValue() << endl;

    return 0;
}
*/

/*//! ASGN 1
struct Node
{
    char command; // R, L, J, B
    int pos;      // 0 , 1 , 2
    Node *next;

    Node(char c, int p, Node *n = 0) : command(c), pos(p), next(n) {}
};
class Stack
{
public:
    Node *top;

    Stack() : top(nullptr) {}

    bool isEmpty() { return top == nullptr; }

    void push(char c, int p)
    {
        Node *newNode = new Node(c, p, top);
        top = newNode;
    }

    bool pop(int &pos)
    {
        if (isEmpty())
        {
            return false;
        }

        Node *temp = top;
        pos = temp->pos;
        top = top->next;
        delete temp;

        return true;
    }

    void display()
    {
        Node *temp = top;

        if (isEmpty())
        {
            cout << "list empty";
            return;
        }

        while (temp != 0)
        {
            cout << "Command: " << temp->command << " | Position: " << temp->pos << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    Stack movements;
    int pos = 0;
    int successfulMovements = 0;
    int successfulUndos = 0;

    for (int i = 0; i < n; i++)
    {
        char command;
        cin >> command;

        if (command == 'R')
        {
            int newpos = pos + 1;

            if (newpos >= 0)
            {
                pos = newpos;
                movements.push(command, 1);
                successfulMovements++;
            }
        }
        else if (command == 'L')
        {
            int newpos = pos - 1;
            if (newpos >= 0)
            {
                pos = newpos;
                movements.push(command, -1);
                successfulMovements++;
            }
        }
        else if (command == 'J')
        {
            int newpos = pos + 2;
            if (newpos >= 0)
            {
                pos = newpos;
                movements.push(command, 2);
                successfulMovements++;
            }
        }
        else if (command == 'B')
        {
            int lastMovement;
            if (movements.pop(lastMovement))
            {
                pos -= lastMovement;
                successfulUndos++;
            }
        }
    }
    cout << "Final position: " << pos << '\n';
    cout << "Successful movements: " << successfulMovements << '\n';
    cout << "Successful undos: " << successfulUndos << '\n';
    cout << "Remaining stack: ";
    movements.display();
    cout << '\n';

    return 0;
}*/