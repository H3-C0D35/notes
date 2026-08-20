#include <stdio.h>
#include <math.h>
// TODO: fix this later

//? Array of nested structures with pointers
/*
struct Address
{
    char city[20];
    int pin;
};

struct Student
{
    char name[20];
    int marks;
    struct Address *a;
};
int main()
{
    struct Address a1[] = {{"LA", 123}, {"NYC", 345}};
    struct Student s1[] = {{"John", 100}, {"Doe", 99}};

    for (int i = 0; i < 2; i++)
    {
        s1[i].a = &a1[i];
    } //! --------OR--------> s1[0].a = &a1[0]; s1[1].a = &a1[1];

    for (int i = 0; i < 2; i++)
    {
        printf("Name: %s | City: %s | Postal code: %d | Marks: %d\n", s1[i].name, s1[i].a->city, s1[i].a->pin, s1[i].marks);
    }
}
*/
//? Array of Nested structures
/*struct Book
{
    char title[100];
    int pages;
};

struct Library
{
    int count;
    struct Book books[5]; // array INSIDE the struct
};
int main()
{
    struct Library l;

    snprintf(l.books[0].title, sizeof(l.books[0].title), "Algo");
    l.books[0].pages = 500;

    snprintf(l.books[1].title, sizeof(l.books[1].title), "OS");
    l.books[1].pages = 300;

    for (int i = 0; i < 2; i++)
    {
        printf("Name: %s | Pages: %d\n", l.books[i].title, l.books[i].pages);
    }
}*/

//? Nested structures with pointers
/*struct Address
{
    int house;
    char city[20];
};

struct Student
{
    int roll;
    struct Address *addr; //! pointer to nested struct, without pointer no -> come, nor do we do & thing
};

int main()
{
    struct Student s;
    struct Address a = {12, "Lahore"};
    s.addr = &a; //! we did this so we can access struct address fields using struct Student variable.
    printf("City: %s\nHouse number: %d", s.addr->city, s.addr->house);
}*/

//? Array of structures
//?task: use struct, function to add more marks, call via pointer array, print before and after.
/*typedef struct
{
    int marks;
} Student;
void addmarks(Student *s[], int extra) //! when having many variables, define it like this
{
    for (int i = 0; i < 3; i++)
    {
        s[i]->marks += extra; //! arrow will be used as s[] is a pointer now
    }
    printf("Marks after:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", s[i]->marks);
    }
}
int main()
{
    Student s1, s2, s3;
    Student *p[3];
    p[0] = &s1;
    p[1] = &s2;
    p[2] = &s3;
    p[0]->marks = 90;
    p[1]->marks = 80;
    p[2]->marks = 60;

    printf("Marks before:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", p[i]->marks);
    }
    addmarks(p, 5);
}*/
//? task: Declare struct, pointer and assign addresses. then Assign marks to each via pointer and print names + marks
/*typedef struct
{
    char name[100];
    int marks;
} Student;

int main()
{
    Student s1, s2, s3;
    Student *p[3];
    p[0] = &s1;
    p[1] = &s2;
    p[2] = &s3;
    snprintf(p[0]->name, sizeof(p[0]->name), "John");  //* snprintf used to assign char.
    p[0]->marks = 8;                                  //* SYNTAX: "snprintf(ptr->field, sizeof(ptr->field), parameters)" ---> in this case names of people.
    snprintf(p[1]->name, sizeof(p[1]->name), "Alice");
    p[1]->marks = 7;
    snprintf(p[2]->name, sizeof(p[2]->name), "bob");
    p[2]->marks = 10;

    for (int i = 0; i < 3; i++)
    {
        printf("name:%s, marks:%d\n", p[i]->name, p[i]->marks);
    }
}*/
//************************************************************************************************************************************

//? Normal pointer structures
/*struct Point
{
    int x;
    int y;
};
void change(struct Point *c) //! changing values of a field using pointers + functions
{
    printf("Changed number 1: %d\n", c->x += 1); //! instead of this number, use a variable by declaring in definition.
    printf("Changed number 2: %d\n", c->y += 1); //! call --> func_name(&struct_var_name, value_1, value_2)
}
int main()
{
    struct Point *ptr;
    struct Point p = {10, 20};
    ptr = &p;
    printf("Number 1: %d\n", ptr->x);
    printf("Number 2: %d\n", ptr->y);
    change(&p);
    return 0;
}*/

//? a full mini-menu system with structs + function pointer arrays
/*int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

struct Menu
{
    char *name;
    int (*ops[3])(int, int);
};

int main()
{
    struct Menu m = {
        "Basic Calculator",
        {add, sub, mul}};

    int a = 10, b = 4; //* can take input

    printf("Add: %d\n", m.ops[0](a, b));
    printf("Sub: %d\n", m.ops[1](a, b));
    printf("Mul: %d\n", m.ops[2](a, b));
}

//? menu driven calculator
/*float mult(float a, float b) {return a * b;}
float div(float a, float b) { return a / b; }
int main()
{
    float a, b;
    printf("enter a number: ");
    scanf("%f", &a);
    printf("enter another number: ");
    scanf("%f", &b);
    float (*op[2])(float, float) = {mult, div};

    int choice;
    printf("enter choice: ");
    scanf("%d", &choice);
    if (choice == 1 || choice == 2)
        printf("RESULT: %.2f", op[choice - 2](a, b));
    else
        printf("invalid choice");
    return 0;
}
    //! if we have a calculator where for some functions we require one input only,

int fact()
{
    int a;
    printf("enter a number: ");
    scanf("%d", &a);
    int fact = 1;
    for (int i = 1; i <= a; i++)
    {
        fact *= i;
    }
    return fact;
}
int main()
{
    int (*op[2])() = {fact};
    printf("RESULT: %d", op[0]());
    return 0;
}
*/

//? array of function pointers
/*
! The main reason we have function pointers is to create menu-driven programs.
! The menus(options) are stored in an array of functions. but since we are using pointers, it becomes....

! choosing a function based on arguments
int add(int a, int b)
{
   return a + b;
}
int sub(int a, int b)
{
   return a - b;
}
int calc(int a, int b, int (*op)(int, int))
{
   return op(a, b);
}
int main()
{
   printf("%d\n", calc(10, 2, add)); // 12
   printf("%d\n", calc(10, 2, sub)); // 8
   return 0;
}
! choosing a function based on index
int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}

int main()
{
   ! using loops
   int (*op[2])(int, int) = {add, sub};
    for (int i = 0; i < 2; i++)
    {
        printf("%d\n", op[i](5, 4));
    }
}*/

//? function pointers
/*int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}

int main()
{
    int (*op)(int, int);  //* SYNTAX
    op = add; //! we dont put & when assigning function to a pointer because C automatically treats func name as address
    printf("ADD: %d\n", op(10, 3));
    op = sub;
    printf("SUB: %d\n", op(10, 3));
}*/

//? changing values of a double pointer instead of a single pointer. or changing address of a double pointer (same thing ig)
/*void change(int **dp, int b) //! or take b as a pointer as well -> int *b. if u do this, put & in function call
{
    *dp = &b;
}
int main()
{
    int a = 10;
    int b = 20;
    int *p = &a;
    printf("Before: p = %d\n", *p);
    int **dp = &p; //! not a necessary step. remove it and just call like this -> change(&p, b);
    change(dp, b); //! if b is taken as pointer -> &b.
    printf("After: p = %d", *p);
}*/

//? Reverse an array in place using start and end pointers
/*void reverse(int *arr, int size)
{
    int *start = arr, *end = arr + size - 1;
    int temp;               //! we are not using temp as pointer because for temporary storage, if values are double, use pointer temp, if values are single, use value temp.
    for (int i = 0; i < size; i++)
    {
        if (start != end)
        {
            temp = *start;
            *start = *end;
            *end = temp;
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int *p = arr;
    reverse(p, 6);
    return 0;
}*/

//? count vowels in a string using pointers
/*int countvowels(char *word)
{
    int count = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U' || word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
            count++;
    }
    //! TO COUNT WORDS:
    //! if (word[i] != '\0')
    return count;
}
int main()
{
    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);
    char *p = word;
    int z = countvowels(p);
    printf("count: %d", z);
}*/

//?Find largest element in an array using pointers
/*void largest(int *arr, int size) //! *arr = arr[]
{
    int i;
    int max = 0, *temp;
    for (i = 0; i < size; i++)
    {
        if (arr[max] < *(arr + i))
        {
            max = i;
        }
    }
    printf("largest: %d\n", *(arr + max)); //! arr[max] for simplicity
}
int main()
{
    int arr[] = {1, 3, 9, 2, 4};
    int *p = arr;
    largest(p, 5);
    return 0;
}*/

//? Swap two numbers using double pointers
/*void swap(int **a, int **b)
{
    int *temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a = 10, b = 11;
    int *p1 = &a;
    int *p2 = &b;
    swap(&p1, &p2);
    printf("a = %d\nb = %d\n", *p1, *p2);
    return 0;
} */

/*
? ---------printing arrays---------
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p = a;
    printf("a[2]: %d\n", a[2]);
    printf("*(a + 2) = %d\n", *(a + 2));
    printf("p[2] = %d\n", p[2]);
    printf("*(p + 2): %d\n", *(p + 2));
    ! • p + 1 → points to a[1]
    ! • p + 2 → points to a[2]
    !  a[i]   == *(a + i)
    !  p[i]   == *(p + i)
}
*/

//? modifying and printing array elements using pass by reference
/*void arrprint(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", *(arr + i)); // or arr[i] for simplicity
    }
}
void arrmodify(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", *(arr + i) += 1); // or arr[i]+1
    }
}
int main()
{
    int arr[4] = {10, 20, 30, 40};
    arrprint(arr, 4);
    arrmodify(arr, 4);
    return 0;
}*/

//? exercise
/*
typedef struct
{
    int ID;
    char title[30];
    char artist[30];
    char genre[30];
    int tracks;

} Library;

Library *add(Library *cd, int new_n, int n)
{
    cd = realloc(cd, new_n * sizeof(Library));
    if (cd == NULL)
    {
        printf("failed reallocation.\n");
        return cd;
    }

    for (int i = n; i < new_n; i++)
    {
        printf("-----CD %d-----\n", i + 1);
        printf("ID: ");
        scanf("%d", &cd[i].ID);
        printf("Title: ");
        scanf("%s", cd[i].title);
        printf("Artist: ");
        scanf("%s", cd[i].artist);
        printf("Genre: ");
        scanf("%s", cd[i].genre);
        printf("Tracks: ");
        scanf("%d", &cd[i].tracks);
    }
    return cd;
}
Library *delete(Library *cd, int id, int n)
{
    int idx = search(cd, id, n);
    if (idx == -1)
    {
        printf("CD NOT FOUND.\n");
        return cd;
    }
    for (int i = idx; i < n - 1; i++)
    {
        cd[i] = cd[i + 1];
    }
    return cd;
}

int search(Library *cd, int id, int n)
{
    int flag = 0;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (cd[i].ID == id)
        {
            idx = i;
        }
    }
    return idx;
}
void update(Library *cd, int n, int id)
{
    int z = search(cd, id, n);
    if (z == -1)
    {
        printf("CD not found.\n");
        return;
    }
    printf("What do you want to change?(0 = id, 1 = title, 2 = artist, 3 = genre, 4 = track): ");
    int choose;
    scanf("%d", &choose);

    switch (choose)
    {
    case 0:
        printf("updating id...\n");
        scanf("%d", &cd[z].ID);
        break;
    case 4:
        printf("updating track...\n");
        scanf("%d", &cd[z].tracks);
        break;

    case 1:
        printf("updating title...\n");
        scanf("%s", cd[z].title);
        break;

    case 2:
        printf("updating title...\n");
        scanf("%s", cd[z].artist);
        break;
    case 3:
        printf("updating genre...\n");
        scanf("%s", cd[z].genre);
        break;
    default:
        printf("invalid");
        break;
    }
}
int main()
{
    int n = 2;

    Library *cd = malloc(n * sizeof(Library));
    if (cd == NULL)
    {
        printf("Failed to allocate");
        return 0;
    }

    cd[0] = (Library){501, "Title1", "Artist1", "Genre1", 2};
    cd[1] = (Library){502, "Title2", "Artist2", "Genre2", 3};

    int choice;
    printf("1. Add\n2.Delete\n3.Search\n4.Update\nChoose an operation: ");
    scanf("%d", &choice);
    int new_n;
    int search_id;

    switch (choice)
    {
    case 1:
        printf("how many cds do you want to add?: ");
        scanf("%d", &new_n);

        cd = add(cd, new_n, n);
        n = new_n;
        break;
    case 2:
        printf("enter id to delete: ");
        scanf("%d", &search_id);
        cd = delete(cd, search_id, n);
        n--;
        cd = realloc(cd, n * sizeof(Library));
        printf("student removed ");
        break;

    case 3:
        printf("enter id to search: ");
        scanf("%d", &search_id);
        int z = search(cd, search_id, n);
        if (z == -1)
        {
            printf("no cd exist\n");
        }
        else
        {
            printf("student found\n");
        }
        break;

    case 4:
        printf("enter id to search: ");
        scanf("%d", &search_id);
        update(cd, n, search_id);
        break;
    default:
        printf("invalid\n");
        break;
    }
    free(cd);
    return 0;
}
*/
//? Struct pointer → find topper
/*typedef struct
{
    char name[20];
    int marks;
} Student;
int main()
{
    int n;
    printf("enter number of students: ");
    scanf("%d", &n);
    Student *s = malloc(n * sizeof(Student));
    if (s == NULL)
    {
        printf("failed allocation");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        printf("enter name: ");
        scanf("%s", s[i].name);
        printf("enter marks: ");
        scanf("%d", &s[i].marks);
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[max].marks < s[i].marks)
        {
            max = i;
        }
    }
    printf("Topper: %s", s[max].name);

    free(s);
}*/
//? Use realloc to grow array after input
/*int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("memory allocation failed");
        return 0;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    printf("Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    int choice;
    printf("\nDo you want to expand? (1/0): ");
    scanf("%d", &choice);

    if (choice == 0)
    {
        free(arr);
        return 0;
    }

    int new_n;
    printf("Enter new n: ");
    scanf("%d", &new_n);

    int *temp = realloc(arr, new_n * sizeof(int));
    if (temp == NULL)
    {
        printf("memory allocation failed");
        free(arr);
        return 0;
    }
    arr = temp;

    printf("Enter new elements:\n");
    for (int i = n; i < new_n; i++)
        scanf("%d", &arr[i]);

    printf("Updated array:\n");
    for (int i = 0; i < new_n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}
*/

//? Dynamic array → find max
/*int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("memory allocation failed");
    }
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(arr + max) < *(arr + i))
        {
            max = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\nlargest: %d", arr[max]);

    free(arr);
    return 0;
}*/

//?Dynamic string → reverse it
/*int length(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    char *arr = calloc(n + 1, sizeof(char)); //!  never forget n+1
    if (arr == NULL)
    {
        printf("failed to allocate memory\n");
    }
    printf("enter name: ");
    scanf("%s", arr);
    int size = length(arr);
    char *start = arr;
    char *end = arr + size - 1;
    char temp;
    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    printf("Reversed: %s\n", arr);
    free(arr);
    return 0;
}*/

//?Dynamic 2D array → column-wise sum
/*int main()
{
    int rows, cols;
    printf("input rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int **mat = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)
    {
        mat[i] = malloc(cols * sizeof(int));
    }

    printf("enter elements:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    int sum;
    for (int i = 0; i < cols; i++)
    {
        sum = 0;

        for (int j = 0; j < rows; j++)
        {
            sum += mat[i][j];
        }
        printf("the sum of col %d = %d\n", i + 1, sum);
    }
    for (int i = 0; i < rows; i++)
        free(mat[i]);
    free(mat);
}
*/