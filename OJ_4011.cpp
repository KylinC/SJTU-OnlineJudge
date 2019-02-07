#include<iostream>
#include<cstring>
using namespace std;
 
class bign
{
	int num[100];
	int size;
public:
	bign(){
		memset(num,0,sizeof(num));
		num[0]=1;
		size=0;
	}
	bign(const char* tmp){*this=tmp;}
	bign(int tmp){*this=tmp;}
	bign operator =(const char* tmp)
	{
		size=strlen(tmp)-1;
		for(int i=0;i<=size;i++)
		{
			num[i]=tmp[size-i]-'0';
		}
		return *this;
	}
	bign operator = (int tmp)
	{
        char s[20]; sprintf(s, "%d", tmp);
        *this = s;
		return *this;
    }
    bign operator =(const bign& tmp)
    {
    	size=tmp.size;
    	for(int i=0;i<=size;i++)
    	{
    		num[i]=tmp.num[i];
		}
		return *this;
	}
	bign operator +(const bign& tmp)
	{
		size=(size>=tmp.size)?size:tmp.size;
		for(int i=0;i<=size;i++)
		{
			num[i]+=tmp.num[i];
			num[i+1]+=num[i]/10;
			num[i]%=10;
		}
		if(num[size+1]!=0)size++;
		return *this;
	}
	friend ostream& operator<<(ostream& out,bign & tmp);
};
 
ostream& operator<<(ostream& out,bign & tmp)
{
	for(int i=tmp.size;i>=0;i--)
	{
		out<<tmp.num[i];
	}
	return out;
}
 
int main()
{
	bign dp[51][51];
    int k,h;
    cin>>k>>h;
    for(int i=2;i<=h;i++)
    {
        for(int j=1;j<=k;j++)
            dp[j][i]=0;
        for(int j=1;j<=k;j++)
        {
            for(int t=k;t>k-j;t--)
            {
                dp[j][i]=dp[j][i]+dp[t][i-1];
            }
        }
    }
    cout<<dp[k][h];
}
