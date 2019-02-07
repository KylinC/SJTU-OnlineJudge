#include<cstdio>
#include<cstring>
using namespace std;
 
char result[1002];
char preOrder[28],midOrder[28];
 
void level(char ch,int out_p,int pre_p,int mid_p,int max)
{
	result[out_p]=ch;
	int check_p=mid_p;
	while(midOrder[check_p]!=ch)++check_p;
	if(mid_p<check_p)level(preOrder[pre_p+1],out_p*2,pre_p+1,mid_p,check_p-1);
	if(check_p<max)level(preOrder[pre_p+check_p+1-mid_p],out_p*2+1,pre_p+check_p+1-mid_p,check_p+1,max);
}
 
int main()
{
	int index;
	scanf("%s", &preOrder);
	scanf("%s", &midOrder);
	level(preOrder[0],1,0,0,strlen(preOrder)-1);
	for(int i=1001;i>=0;i--)
	{
		if(result[i]!=0)
		{
			index=i;
			break;
		}
	}
	for(int i=1;i<=index;i++)
	{
		if(result[i])printf("%c ",result[i]);
		else printf("NULL ");
	}
	return 0;
}
