#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int i, j = 0, k = 0, n = 0;

    int flag = 0;
    char str[100], neww[100], word[100];

    cout << "Enter Any String to Remove a Word from String: ";
    gets(str);

    cout << "\n\n Enter Any Word You Want to be Removed: ";
    gets(word);

    for (i = 0; str[i] != '\0'; i++)
    {
        k = i;

        j = 0;
        while (str[i] == word[j])
        {
            i++, j++;
            if (j == strlen(word))
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            i = k;
        else
            flag = 0;

        neww[n++] = str[i];
    }

    neww[n] = '\0';

    cout << "\n\n After Removing Word From String: " << neww;
    return 0;
}