#include<iostream>
using namespace std;
 
int step(int scale,int row,int column);
 
int main()
{
	int scale,row,column;
	cin>>scale>>row>>column;
	cout<<step(scale,row,column)-1;
} 
 
int step(int scale,int row,int column)
{
	if(row==1) return column;
	if(column==scale) return (scale+row-1);
	if(row==scale) return (3*scale-column-1);
	if(column==1) return (4*scale-row-2);
	return (4*(scale-1)+step(scale-2,row-1,column-1));
}
