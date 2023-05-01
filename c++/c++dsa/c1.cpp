// reverse a no. and display if no. not in range give 0?
#include <iostream>
using namespace std;

int main()
{

    int x;
    cout << "enter no.:" << endl;
    cin >> x;
int rev = 0,rem;
    while (x != 0)
    {
        rem = x % 10;
        rev=rev*10 + rem;
        x = x / 10;
    }
if((rev<INT64_MIN)||(rev<INT64_MAX))
{
    rev=0;
    
}
else
    cout << "reversed no.:" << endl<<rev;

    return 0;
}