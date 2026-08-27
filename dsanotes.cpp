#include <iostream>
using namespace std;

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

/* ! SELECTION SORT
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

//! BUBBLE SORT
