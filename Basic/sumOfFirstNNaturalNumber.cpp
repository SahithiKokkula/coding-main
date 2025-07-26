#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int sum=0;
    int c=1;
    while (c<=n) {
        sum=sum+c;
        c++;
    }
    cout<<"Sum ="<<sum;

} // namespace std
