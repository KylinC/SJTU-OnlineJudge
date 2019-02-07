#include<iostream>
using namespace std;
 
int main(){
    int a,current=0,save=0;
    bool flag=true;
    for(int i=0;i<12;i++){
        cin>>a;
        current+=300;
        if(current<a){
            cout<<"-"<<i+1;
            flag=false;
            break;
        }
        current-=a;
        save+=current-current%100;
        current%=100;
    }
    if(flag){
    current+=save*1.2;
    cout<<current;
   }
    return 0;
}
