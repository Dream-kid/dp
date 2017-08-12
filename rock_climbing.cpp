#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
int ara[30005],dp[30005][500],n,d;

int call(int l,int step)
{
    cout<<l<<" "<<step<<endl;
    if(l<0 || l>30000 || (step+d)<=0)
        return 0;
    int &ret=dp[l][step];

    if(ret!=-1)
        return ret;
    ret=0;
    ret=max(ret,call(l+d+step,step));
    cout<<"...............1st.............."<<endl;
   
 
    ret=max(ret,call(l+d+step-1,step-1)); 
    cout<<"...............2nd.............."<<endl;
    ret=max(ret,call(l+d+step+1,step+1));  
     cout<<"...............3rd.............."<<endl;

    ret+=ara[l]; 
        cout<<"...............4th.............."<<endl;
       
    return ret;
     cout<<"...............5th.............."<<endl;

}


int main()
{
    freopen("out.txt","w",stdout);
	int t,cas=0;

	cin>>n>>d;
	for(lli i=0;i<n;i++)
	{
	   lli  p;
	    cin>>p;
	    ara[p]++;
	}
	memset(dp,-1,sizeof(dp));

	cout<<call(d,0);

/*4 10
10
21
27
27*/

}
