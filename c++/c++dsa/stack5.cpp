// delete middle element from stack
#include <iostream>
#include <stack>
using namespace std;
class stack5
{
public:
    void solve(stack<int> s, int count, int n)
    {

        if (count == n / 2)
        {
            s.pop();
            return;
        }

        int num = s.top();
        s.pop();
        solve(s, count++, n);
        s.push(num);
        
    }
    void dis(stack<int> s){
        cout<<s.top();
    }
};

int main()
{ stack5 s1;
    int a[100], n;
    cout << "enter size of stack:" << endl;
    cin >> n;

    stack<int> s;
    cout << "enter elements of stack:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.push(a[i]);
    }
int count=0;
    s1.solve(s, count, n);
    s1.dis(s);

    return 0;
}