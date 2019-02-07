#include <iostream>
#include <stack>
using namespace std;
class disjointSet
{
private:
    int size;
    int *parent;
 
public:
    disjointSet(int s);
    ~disjointSet(){delete [] parent;}
    void Union(int root1, int root2);
    int find(int x);
};
 
disjointSet::disjointSet(int s)
{
    size = s+1;
    parent = new int[size];
    for(int i=0; i<size; ++i) parent[i] = -1;
}
 
int disjointSet::find(int x)
{
    int start=x,tmp;
    while(!(parent[x]<0)) x = parent[x];
    while(start!=x){
        tmp = parent[start];
        parent[start] = x;
        start = tmp;
    }
    return x;
}
 
void disjointSet::Union(int root1, int root2)
{
    if(root1==root2) return;
    if(parent[root1]>parent[root2]){
        parent[root2] += parent[root1];
        parent[root1] = root2;
    }
    else{
        parent[root1] += parent[root2];
        parent[root2] = root1;
    }
}
 
int getrow(int x)
{
    int row=1;
    while(row*(row+1)/2<x)
        ++row;
    return row;
}
 
void DFS(int pos, const int end, const int s, int **matrix, int *record)
{
    if(pos==end) return;
    for(int i=1; i<s; ++i){
        if(matrix[pos][i]==1&&(record[i]==-1||record[i]>record[pos]+1)){
            record[i] = record[pos]+1;
            DFS(i, end, s, matrix, record);
        }
    }
}
 
int main()
{
    int n,in,out,x,dir,row;
    int **matrix;
    int *record;
    stack<int> road;
 
    cin >> n >> in >> out;
    disjointSet ds(n*(n+1)/2);
    record = new int [n*(n+1)/2+1];
    matrix = new int *[n*(n+1)/2+1];
    for(int i=0; i<n*(n+1)/2+1; ++i)
        matrix[i] = new int[n*(n+1)/2+1];
    for(int i=1; i<n*(n+1)/2+1; ++i)
        for(int j=1; j<n*(n+1)/2+1; ++j)
            matrix[i][j] = 0;
    for(int i=1; i<n*(n+1)/2+1; ++i)
        record[i] = -1;
 
    //break walls
    while(ds.find(in)!=ds.find(out)){
        cin >> x >> dir;
        row = getrow(x);
        if(dir==0){
            if(x!=row*(row-1)/2){
                ds.Union(ds.find(x),ds.find(x-row));
                matrix[x][x-row] = 1;
                matrix[x-row][x] = 1;
            }
        }
        else if(dir==1){
            if(x!=row*(row+1)/2){
                ds.Union(ds.find(x),ds.find(x-row+1));
                matrix[x][x-row+1] = 1;
                matrix[x-row+1][x] = 1;
            }
        }
        else if(dir==2){
            ds.Union(ds.find(x),ds.find(x+row));
            matrix[x][x+row] = 1;
            matrix[x+row][x] = 1;
        }
        else{
            ds.Union(ds.find(x),ds.find(x+row+1));
            matrix[x][x+row+1] = 1;
            matrix[x+row+1][x] = 1;
        }
    }
 
    //DFS
    record[in] = 1;
    DFS(in, out, n*(n+1)/2+1, matrix, record);
    int pos=out;
    road.push(pos);
    while(road.top()!=in){
        pos = road.top();
        for(int i=1; i<n*(n+1)/2+1; ++i){
            if(matrix[pos][i]==1&&record[i] == record[pos]-1){
                road.push(i);
                break;
            }
        }
    }
    while(!road.empty()){
        cout << road.top() << ' ';
        road.pop();
    }
 
    return 0;
}
