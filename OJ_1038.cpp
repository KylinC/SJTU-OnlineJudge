#include <iostream>
using namespace std;
 
int main()
{
    int num,aim=0;
    int container[10001]={0};
    cin>>num;
    for(int i=1;i<num;i++)
	{
        cin>>container[i];
    }
    for(int i=2;i<=num;i++)
    {
        aim+=container[num-i+1];
        aim%=i;
    }    
    cout<<aim+1<<endl;
    return 0;
}
