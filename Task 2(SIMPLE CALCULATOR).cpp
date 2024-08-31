#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    char op;
    cout<<"Enter the operator '+' / '-' / '*' / '/' "<<endl;
    cin>>op;
    cout<<"The result is ";
    switch(op){
        
        case '+':cout<<(a+b)<<endl;
        break;
        case '-':cout<<(a-b)<<endl;
        break;
        case '/':cout<<(a/b)<<endl;
        break;
        case '*':cout<<(a*b)<<endl;
        break;
    }
    

}
