//coin change
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int main ()
{

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    lli a,b,sum=100000,j;
    cin>>a;
    lli ara[100];
    lli i=0;
    while(a--)
    {
        cin>>ara[i];
        i++;


    }
    lli p=i;
    sort(ara,ara+i);
    cin>>b;
    lli ara1[100][100]= {0};
    for(i=0; i<p; i++)
    {

        for(j=0; j<=b; j++)
        {
            if(i==0)
            {
                if(ara[i]<=j) ara1[j][i]=1+ara1[j-ara[i]][i];


            }
            else    if(ara[i]<=j)
            {

                ara1[j][i]=min((1+ara1[j-ara[i]][i]),ara1[j][i-1]);


            }
            else
            {

                ara1[j][i]=ara1[j][i-1];

            }



        }
        sum=min(sum,ara1[j-1][i]);


    }
    cout<<sum<<endl;



}
