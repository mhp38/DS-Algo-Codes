///https://practice.geeksforgeeks.org/problems/nth-catalan-number/0

#include<bits/stdc++.h>
#define ll unsigned long long
#define ios ios_base::sync_with_stdio(false)
#define pii pair<int, int>
#define fs first
#define sc second

using namespace std;

const ll INF=(1ll<<62)-1;
const int M=1e2+5;

ll dp[M];


 int main()
    {
        ios;
        int t,n;
        ll tot=0;
        cin>>t;
        while(t--)
        {
            cin>>n;

             dp[0]=dp[1]=1;

            for(int i=2;i<=n;i++){
                dp[i]=0;

                for(int j=0;j<i;j++){
                    dp[i]+=(dp[j]*dp[i-j-1]);
                }
            }

            cout<<dp[n]<<endl;

        }
    }



