#include <iostream>
#include <string.h>

using namespace std;
class bank
{
    char name[50];
    long acc;
    char type[50];
    float balance;

public:
    bank(char n[], long a, char t[], float b)
    {
        strcpy(name, n);
        acc = a;
        strcpy(type, t);
        balance = b;
    }

    void deposit()
    {
        float d;
        cout << "enter amount of deposit:" << endl;
        cin >> d;
        balance += d;
    }
    void withdraw()
    {
        float w;
        cout << "enter amount of deposit:" << endl;
        cin >> w;
        if (w > balance)
            cout << "insufficient balance" << endl;
        balance -= w;
    }
    void display()
    {
        cout << "name       :" << name << endl;

        cout << "account no.:" << acc << endl;

        cout << "type       :" << type << endl;

        cout << "balance    :" << balance << endl;
    }
};

int main()
{
    char n[50];
    long a;
    char t[50];
    float b;
    cout << " enter details:" << endl;
    cout << "................." << endl;
    cout << "enter name :" << endl;
    gets(n);
    cout << "enter account no.:" << endl;
    cin >> a;
    fflush(stdin);
    cout << "enter acc. type :" << endl;
    gets(t);
    cout << "enter balance :" << endl;
    cin >> b;
    bank b1(n, a, t, b);
    b1.deposit();
    b1.withdraw();
    b1.display();

    return 0;
}
