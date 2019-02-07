#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int maxn = 100010, mod = 99999997;
 
int n, ans = 0, d[maxn],c[maxn];
 
struct node
{
    int x, id;
}a[maxn], b[maxn];
 
bool cmp(node a, node b)
{
    return a.x < b.x;
}
 
void update(int x, int v)
{
    while (x <= n)
    {
        d[x] += v;
        x += x & (-x);
    }
}
 
int sum(int x)
{
    int cnt = 0;
    while (x)
    {
        cnt += d[x];
        x -= x & (-x);
    }
    return cnt;
}
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].x);
        a[i].id = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i].x);
        b[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        c[a[i].id] = b[i].id;
    for (int i = 1; i <= n; i++)
    {
        update(c[i], 1);
        ans = (ans + i - sum(c[i])) % mod;
    }
 
 
    printf("%d\n", ans % mod);
    return 0;
}
