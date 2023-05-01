#include<iostream>
#include<string.h>
using namespace std;
class dchar
{
    char str[50];
    

public:
    void getstr()
    {
        cout << "Enter the sentence:";
        cin.get(str, 50, '\n');
    }
    void deletealternate()
    {
        int i = 0, j = 0;
        while (i < strlen(str))
        {
            str[j] = str[i];
            i += 2;
            j++;
        }
        str[j] = '\0';
        cout << str;
    }
};
int main()
{
    dchar d;
    d.getstr();
    d.deletealternate();
    return 0;
}