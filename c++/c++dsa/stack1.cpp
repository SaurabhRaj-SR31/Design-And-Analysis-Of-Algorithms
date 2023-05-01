//stl creation of stack
#include<iostream>
#include<stack>
using namespace std;
int main(){
stack<int> s;
s.push(1);
s.push(2);
s.push(3);
s.push(5);
cout<<s.top();
s.pop();
s.pop();
s.pop();
cout<<" "<<s.top();



    return 0;
}
/*//stl creation of stack
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int a[100],n;
    cout<<"enter size of stack:"<<endl;
    cin>>n;

stack<int> s;
cout<<"enter elements of stack:"<<endl;
for(int i=0;i<n;i++)
{
   cin>>a[i];
    s.push(a[i]);
}
cout<<s.top()<<" ";


    return 0;
}*/