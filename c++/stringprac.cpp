#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{

    string str = "saurabh";
    cout << str.find("h");
    int s = 0;
    int e = str.length() - 1;
    while (s < e)
    {
        swap(str[s++], str[e--]);
    }

    sort(str.begin(), str.end());
    cout << str;
    return 0;
}