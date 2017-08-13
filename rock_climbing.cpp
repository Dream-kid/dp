//http://codeforces.com/problemset/problem/505/C
#include<bits/stdc++.h>
typedef long long  lli;
using namespace std;

lli ara[30010],dp[30010][502],b;
lli rock_climbing(lli dis,lli pos)
{
    if(dis<0||dis>30000||(b+pos)<=0) return 0;
    lli &p=dp[dis][pos];
    if(p!=-1) return p;
    p=0;
    p=max(p,rock_climbing(dis+pos+b,pos));
    p=max(p,rock_climbing(dis+pos+b+1,pos+1));
    p=max(p,rock_climbing(dis+pos+b-1,pos-1));
    p+=ara[dis];
    return p;


}
int main()
{
    lli a;
    cin>>a>>b;
    for(lli i=0; i<a; i++)
    {
        lli p;
        cin>>p;
        ara[p]++;

    }
    memset(dp,-1,sizeof(dp));
    cout<<rock_climbing(b,0);


}
