#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
int main(){
  srand(time(NULL));
  int num=(rand()%100)+1;
  int n;
  int count=0;
  cout<<"Guess the number between 1 and 100"<<endl;
  
  while(true){
    cin>>n;
    count++;
    if (n==num){
        cout<<"you r right!!"<<endl;
        cout<<"YAHOOOOO!!!!!!! "<<endl<<"You took "<<count<<" attempts";
        break;
    }
    else if(num>n){
        cout<<"Guessed number is smaller....Try again!!!"<<endl;
    }
    else{
        cout<<"Guessed number is larger....Try again!!!"<<endl;
    }
  }

}

