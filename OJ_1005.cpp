#include<iostream>
#include<cstring>
using namespace std;
 
int main()
{
	int stack_num=0,check;
	bool flag = 1;
    char con[80];
    while(cin>>con&&flag)
    {
        if(!strcmp(con,"begin"))
        {
            ++stack_num;
        }
        else if(!strcmp(con,"end"))
        {
            if(stack_num>0)
            {
                --stack_num;
            }
            else
            {
                flag = 0;
            }
        }
        else if(!strcmp(con,"if"))
        {
            check=1;
        }
        else if(!strcmp(con,"then"))
        {
            if(check==1)
            {
                check=2;
            }
            else
            {
                flag=0;
            }
        }
        else if(!strcmp(con,"else"))
        {
            if(check==2)
            {
                check=3;
            }
            else
            {
                flag=0;
            }
        }
    }
    if (flag&&stack_num==0&&check!=1)cout<<"Match!";
    else cout<<"Error!";
}
