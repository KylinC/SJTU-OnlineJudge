#include <iostream>
#include <string>
using namespace std;
 
bool judge(string light, string dark, int num, int len)
{
    int part=len/num;           
    string *substring = new string[part];
    for (int j=0; j<part; j++)
	{
        substring[j] = light.substr(num*j,num);
    }
    string *newsubstring = new string[num];
    for (int i=0;i<num; i++)
	{
        for (int j=0; j<part; j++)
        {
            newsubstring[i]+=substring[j][i];
        }
    }
 
    string newstring = "";
    for (int i=0; i<num; i++)
    {
        newstring += newsubstring[i];
    }
 
    delete []substring;
    delete []newsubstring;
    if (newstring == dark)
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
int main()
{
    bool flag=true;
    string light, dark;
    cin>>light>>dark;
    int len=light.length();
    for(int i=2;i<=len;i++)
	{
        if(len%i!=0)           
        {
            continue;
        }
        if(judge(light,dark,i,len))
		{
            cout<<i<<endl;
            flag=false;
            break;
        }
    }
    if(flag)
    {
        cout<<"No Solution"<<endl;
    }
    return 0;
}
