#include<iostream>
using namespace std;
int main(){
    int n,a,temp,sum=0,count=0;
    cin>>n;
    temp=n;
    while(n>0){
        count++;
        n=n/10;
    }
    while(n>0){
        a=n%10;
        
        sum=sum+a*a*a;
        n=n/10;
    }
    if(sum==temp){
        cout<<"the number is armstrong";
    }
    else{
        cout<<"not an armstrong number";
    }
}
