//0/1 napsack
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
int main ()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    lli wt,val,a,i,j,ans=0;
    vector<pair<lli,lli> >v;
    cin>>a;
    while(a--)
    {
        cin>>wt>>val;
        v.push_back(make_pair(wt,val));


    }
    sort(v.begin(),v.end());
    lli len=v.size();
    lli ara[100][100]= {0};
    for(i=0; i<len; i++)
    {

        for(j=0; j<=v[len-1].second; j++)
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


    cout<<ans<<endl;
    /*
    4
    1 1
    3 4
    4 5
    5 7
    ans=9
    */



}
