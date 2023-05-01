#include<iostream>
#include<string.h>

using namespace std;
int main()
{
char str[]="abc cde abc ghi jhihfj abc";
char *s=strtok(str," ");



while(s!=NULL)
{
    cout<<s<<endl;
    s=strtok(NULL," ");
}







    return 0;
}