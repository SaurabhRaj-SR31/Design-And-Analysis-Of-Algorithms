#include<iostream>
using namespace std;
class Shop
{
    char n[100];
    int r[100];
    int counter;

public:
    void initCounter(void) { counter = 0; }
    void setname(void);
    void displayname(void);
};
void Shop ::setname(void)
{
    cout << "Enter name of student : " << counter + 1 << endl;
    cin.get(n,10);
    fflush(stdin);
    cout << "Enter roll :" << endl;
    cin >> r[counter];
     fflush(stdin);
    counter++;
}

void Shop ::displayname(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The student " << n[i]<< " has roll " << r[i] << endl;
    }
}

int main()
{
    Shop dukaan;
    dukaan.initCounter();
    dukaan.setname();
    dukaan.setname();
    dukaan.setname();
    dukaan.displayname();
    return 0;
}