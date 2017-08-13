#http://www.lightoj.com/volume_showproblem.php?problem=1004

#include<bits/stdc++.h>
typedef long long  lli;
using namespace std;

lli ara[400][400],dp[400][400],a;
lli rock_climbing(lli dis,lli pos)
{
    if(dis<0||dis>2*a||(pos+a<=0)) return 0;
    lli &p=dp[dis][pos];
    if(p!=-1) return p;
    p=0;
    p=max(p,rock_climbing(dis+1,pos));
    p=max(p,rock_climbing(dis+1,pos+1));
    p=max(p,rock_climbing(dis+1,pos-1));
    p+=ara[dis][pos];
    return p;


}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    lli g,p1=1;
    cin>>g;
    while(g--)
    {
        cin>>a;
        lli s=a;
        s--;
        lli t=a;
        for(lli i=1; i<=a; i++)
        {
            lli k=1;
            for(lli h=1; h<=s; h++) k++;
            s--;
            for( lli j=k; j<=t; j++)
            {

                lli p;
                scanf("%lld",&p);
                ara[i][j]=p;
                j++;
            }
            t++;

        }
        lli p=2*a;

        s=1;
        for(lli i=a+1; i<=2*a-1; i++)
        {
            lli k=1;
            for(lli h=1; h<=s; h++) k++;
            s++;
            p--;
            for(lli j=k; j<=p; j++)
            {

                lli p1;
                cin>>p1;
                ara[i][j]=p1;
                j++;
            }

        }


        memset(dp,-1,sizeof(dp));
        lli y=rock_climbing(1,a);
        printf("Case %lld: %lld\n",p1++,y);

        memset(ara,0,sizeof(ara));

    }
}
