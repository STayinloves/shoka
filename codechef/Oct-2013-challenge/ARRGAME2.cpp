#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define N 100005
int n ;
int a[N];
pair<int , int> b[N];

int F(int x)
{
    if (x == 1)
        return -1 << 30;
    if (x == 2 || x == 4)
        return (1 << 30);
    if (x == 3)
        return 1 + (1 << 30);
    return -x;
}
void work()
{
    int i , j , x , y ; double ans = 0;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 0 ; i < n ; ++ i)
    {
        scanf("%d",&x) , b[i].se = x;
        b[i].fi = F(x);
    }
    sort(b , b + n);
    for (i = 0 ; i < n ; ++ i)
    {
        x = a[i];
        y = F(x);
        j = lower_bound(b , b + n , make_pair(y , (-1 << 30) - 1)) - b;
        ans += (double)j / n;
    }
    printf("%.6f\n" , ans);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d",&n))
        work();

    return 0;
}
