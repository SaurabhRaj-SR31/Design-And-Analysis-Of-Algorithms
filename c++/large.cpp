/*#include <iostream>
using namespace std;
class large
{
    int m;
    int n;

public:
    void getdata()
    {
        cout << "enter the nos.:" << endl;
        cin >> m >> n;
    }
    void disdata()
    {
        cout << "your nos. are:" << endl;
        cout << m << " " << n << endl;
        cout << "largest no. is:" << endl;
        cout << largest(m, n);
    }
    int largest(int m, int n)
    {
        if (m >= n)
            return m;
        else
            return n;
    }
};
int main()
{

    large s;
    s.getdata();
    s.disdata();

    return 0;
}*/
#include<iostream>
using namespace std;
class Largest{

    int m;
    int n;
    public : void getdata(){
        cout<<"Enter the numbers"<<endl;
        cin>>m>>n;
    

    }
    int large(int m, int n){
        if (m>n)
        return m;
        else
        return n;

    }
    void dis_data(){
        cout<<"largest number is "<<large(m,n);
    }
};
int main(){
Largest s;
s.getdata();
s.dis_data();
    return 0;
}