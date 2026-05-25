
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*int length(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
int replace(char letter, char mystery[], char d[])
{
    int found = 0;
    int size = length(mystery);
    for (int i = 0; i < size; i++)
    {
        if (letter == mystery[i])
        {
            d[i] = letter;
            found++;
        }
    }
    return found;
}
int main()
{
    char letter, mystery[] = "woodpecker";
    char d[] = "__________";
    int tries = 0;
    char used_arr[26];
    int usedcount = 0;
    int seen = 0;
    while (tries < 10)
    {
        printf("%s", d);
        printf("\nEnter a letter: ");
        scanf(" %c", &letter);

        for (int i = 0; i < usedcount; i++)
        {
            if (used_arr[i] == letter)
            {
                seen = 1;
            }
        }
        if (seen > 0)
        {
            printf("Already guessed that. Use your brain.\n");
            continue;
        }
        used_arr[usedcount] = letter;
        usedcount++;

        int yes = replace(letter, mystery, d);

        if (yes == 0)
        {
            tries++;
        }

        printf("%s", d);
    }
    int win = 1;
    for (int i = 0; i < length(d); i++)
    {
        if (d[i] == '_')
        {
            win = 0;
        }
    }
    if (win == 1)
    {
        printf("\nYOU WON!");
    }
    else
    {
        printf("\nYOU LOST!");
    }
        return 0;
}*/

//?checking palindrome
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
    char palindrome[100];
    printf("Enter a word: ");
    scanf("%[^\n]", palindrome);
    printf("%s", palindrome);
    int size = length(palindrome);
    int flag = 1;
    for (int i = 0; i < size / 2; i++)
    {
        if (palindrome[i] != palindrome[size - 1 - i])
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        printf("\nit is a palindrome\n");
    }
    else
    {
        printf("\nnope");
    }
}*/

//?rock, paper, scissors
/*int getcompchoice()
{
    return rand() % 3;
}

int main()
{
    int user_choice;
    int comp_choice = getcompchoice();
    do
    {
        printf("(0 = rock, 1 = paper, 2 = scissors)\nEnter choice: ");
        scanf("%d", &user_choice);
        printf("Computer choice: %d\n", comp_choice);

        if (user_choice == comp_choice)
        {
            printf("Draw\n");
        }
        else if ((user_choice == 0 && comp_choice == 2) || (user_choice == 1 && comp_choice == 0) || (user_choice == 2 && comp_choice == 1))
        {
            printf("YOU WIN!\n");
        }
        else
        {
            printf("YOU LOSE!\n");
        }
    } while (user_choice != -1);
    return 0;
}*/

//? counting vowels, consonants, digits, special characs, replace numbers with #
/*int length(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
void replace(char *word)
{
    int size = length(word);

    for (int i = 0; i < size; i++)
    {
        if (word[i] >= '0' && word[i] <= '9')
        {
            word[i] = '#';
        }
    }
    printf("\n%s", word);
}

void counter(char *word)
{
    int size = length(word);
    int vowel = 0, consonant = 0, special = 0, digit = 0;
    for (int i = 0; i < size; i++)
    {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')
            vowel++;
    }
    printf("vowel count: %d\n", vowel);

    for (int i = 0; i < size; i++)
    {
        if (((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) &&
            !(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||
              word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U'))
            consonant++;
    }
    printf("consonant count: %d\n", consonant);

    for (int i = 0; i < size; i++)
    {
        if (word[i] >= '0' && word[i] <= '9')
        {
            digit++;
        }
    }
    printf("digit count: %d\n", digit);

    for (int i = 0; i < size; i++)
    {
        if (!((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')) &&
            !(word[i] >= '0' && word[i] <= '9'))
            special++;
    }
    printf("special charac count: %d", special);
}

int main()
{
    char word[50];
    printf("enter a word: ");
    scanf("%s", word);
    counter(word);
    replace(word);
}*/

//?input: cat output: c-a-t
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
    char w[20];
    printf("enter word: ");
    scanf("%s", w);
    int size = length(w);
    for (int i = 0; i < size; i++)
    {
        printf("%c", w[i]);
        if (i < size - 1)
            printf("-");
    }
    return 0;
}*/

//? reverse using pointers
/*int length(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
void reverse(char *s)
{
    int size = length(s);
    char *start = s;
    char *end = s + size - 1;
    char temp;
    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    printf("%s", s);
}
int main()
{
    char str[100];
    printf("enter: ");
    scanf("%s", str);
    reverse(str);
}
//? Reverse
/*void reverse(char *s)
{
    int start = 0;
    int end = length(s) - 1;
    char temp;
    while (start < end)
    {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }

    printf("%s", s);
}

//? lower and upper
/*void Upper(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }
    printf("new string: %s\n", s);
}
void Lower(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }
    printf("new string: %s", s);
}

int main()
{
    char s[20];
    scanf("%s", s);
    Upper(s);
    Lower(s);
}*/

//? strcmp()
/*int stringcompare(char word1[], char word2[])
{
    int i = 0;
    while (word1[i] != '\0' && word2[i] != '\0')
    {
        if (word1[i] != word2[i])
        {
            return word1[i] - word2[i];
        }
        i++;
    }
    return word1[i] - word2[i];
}
int main()
{
    char a[100], b[100];
    scanf("%s", a);
    scanf("%s", b);
    int z = stringcompare(a, b);
    if (z < 0)
        printf("%s is smaller than %s", b, a);
    else if (z > 0)
        printf("%s is bigger than %s", b, a);
    else
        printf("strings are equal");
    return 0;
}*/

//?strcpy()
/*void stringcopy(char source[], char dest[]) {
    int i = 0;
    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
    printf("Word: %s", dest);
}
int main() {
    char source[100], dest[100];
    printf("enter a word: ");
    scanf("%s", source);
    stringcopy(source, dest);
    return 0;
}
    //! -----with pointers------
    /*
*   void stringcopy(char *source, char *dest)
*    char *p = source;
*    char *q = dest;
*    stringcopy(p, q);
   */

//? strlen()
/*int length(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
/*int main()
{
    char str[100];
    printf("enter: ");
    scanf("%s", str);
    int z = length(str);
    printf("\nlenght: %d\n", z);
    reverse(str);
}*/
//!-------with pointers-------
/*
 *   char *p = str;
 *   int z = length (p);
 *   and in function definition ---> int length(char *s)
 */
