#include <iostream>
using namespace std;

//bitwise operator:
//AND && -->if any 0 then output is 0
//OR ||  -->if any 1 then output is 1
//NOT ~  -->0 to 1 and 1 to 0...check first bit for 0(+ve) or 1(-ve) and then take 2's complement
//XOR ^  -->single 1 then output is 1 (if both input bit are same then output is 0)

int main(){
    int a;
    int b;
    cout<<"enter two numbers: ";
    cin>>a>>b;

    cout<<"a&b: "<< (a & b)<<endl ;
    cout<<"a|b: "<< (a | b)<<endl ;
    cout<<"~a: "<< (~a) <<endl;
    cout<<"a^b: "<< (a ^ b)<<endl ;
    return 0;
}