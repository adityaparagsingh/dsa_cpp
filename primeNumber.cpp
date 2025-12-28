#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter any number to check for prime number: ";
    cin>>n;
    for (int i = 2; i < n; i++)
    {
        if(n%i==0){
            cout<<"not a prime number"<<endl;
            break;
        }
        else{
            continue;
            cout<<" prime number"<<endl;
        }
    }
    
    return 0;
}