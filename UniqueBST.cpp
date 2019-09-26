//https://www.geeksforgeeks.org/total-number-of-possible-binary-search-trees-with-n-keys/

//https://practice.geeksforgeeks.org/problems/unique-bsts/0

#include<bits/stdc++.h>
#define ll long long
#define ios ios_base::sync_with_stdio(false)
#define pii pair<int, int>
#define fs first
#define sc second

using namespace std;

const ll INF=(1ll<<62)-1;
const int M=1e5+5;

ll bc(ll n,ll k)
{
    ll res=1;

    if(k>n-k)k=n-k;

    for(int i=0;i<k;i++)
    {
        res *= (n-i);
        res /= (i+1);
    }

    return res;
}

ll cat(ll n)
{
    ll cnt=bc(2*n,n);
    return cnt/(n+1);
}

 int main()
    {
        ios;
        int t,n;
        cin>>t;
        while(t--)
        {
            cin>>n;
            cout<<cat(n)<<endl;
        }
    }



