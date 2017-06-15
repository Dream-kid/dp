//0/1 napsack
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int main ()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    lli wt,val,a,i,j,ans=0,sum=0,b;
 scanf("%lld",&b);
    while(b--)
    {
        lli ara[1000][1000]= {0};
        ans=0;
        sum=0;
        vector<pair<lli,lli> >v;
        scanf("%lld",&a);
        v.clear();
        while(a--)
        {
            scanf("%lld%lld",&wt,&val);
            v.push_back(make_pair(val,wt));


        }
        sort(v.begin(),v.end());
        lli len=v.size();

        cin>>a;
        while(a--)
        {
            lli lim;
          scanf("%lld",&lim);
            for(i=0; i<len; i++)
            {


                for(j=0; j<=lim; j++)
                {
                    if(i==0)
                    {

                        if(j>=v[i].first)
                        {

                            ara[j][i]=v[i].second;
                        }


                    }
                    else if(j>=v[i].first)
                    {

                        ara[j][i]=  max((v[i].second+ara[j-v[i].first][i-1]),ara[j][i-1]);


                    }
                    else
                    {


                        ara[j][i]=ara[j][i-1];
                    }

                    ans=max(ans,ara[j][i]);


                }




            }
            sum+=ans;
            ans=0;
        }


        printf("%lld\n",sum);
      

    }

}
