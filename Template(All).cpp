    #include<bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp> // Common file
    #include <ext/pb_ds/tree_policy.hpp> // Including
    using namespace std;
    using namespace __gnu_pbds;

    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<ll> vl;
    typedef vector<vi> vvi;
    typedef vector<vl> vvl;
    typedef pair<int,int> pii;
    typedef pair<double, double> pdd;
    typedef pair<ll, ll> pll;
    typedef vector<pii> vii;
    typedef vector<pll> vll;

    template<typename T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    template<typename F, typename S>
    using ordered_map = tree<F, S, less<F>, rb_tree_tag, tree_order_statistics_node_update>;

    //#define pb push_back
    #define pb emplace_back
    #define F first
    #define S second
    #define mp make_pair
    #define endl '\n'
    #define pf printf
    #define sf scanf
    #define left __left
    #define right __right
    #define tree __tree

    const double PI = acos(-1);
    const double eps = 1e-9;
    const int inf = 2000000000;
    const ll infLL = 9000000000000000000;
    #define MOD 1000000007
    //#define harmonic(n) 0.57721566490153286l+log(n)

    #define mem(a,b) memset(a, b, sizeof(a) )
    #define gcd(a,b) __gcd(a,b)
    #define lcm(a,b) (a*(b/gcd(a,b)))
    #define sqr(a) ((a) * (a))

    #define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

    typedef vector<int>::iterator vit;
    typedef set<int>::iterator sit;

    inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
    inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
    inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

    int dx[] = {0, 0, +1, -1};
    int dy[] = {+1, -1, 0, 0};
    //int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
    //int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};

    inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
    inline bool isLeapYear(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }
    inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
    inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
    inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
    inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
    inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
    inline ll modInverse(ll a) { return modPow(a, MOD-2); }
    inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

    /*
    bool isPrime(int n) 
   { 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6){
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
       }
  
    return true; 
   } 
   */

    /*
    bool seive[1010000];
    vi prime;

    void seiveGen(int limit) {
        limit += 100;
        int sqrtn = sqrt(limit);
        for(int i = 3; i <= sqrtn; i += 2) {
                if(!seive[i>>1]) {
                        for(int j = i * i; j < limit; j += i + i) {
                                seive[j>>1] = 1;
                        }
                }
        }
        prime.PB(2);
        for(int i = 3; i < limit; i += 2) {
                if(!seive[i>>1]) prime.PB(i);
        }
    }
    */

    //
    //debug
    #ifdef Pias
    template < typename F, typename S >
    ostream& operator << ( ostream& os, const pair< F, S > & p ) {
                return os << "(" << p.first << ", " << p.second << ")";
    }

    template < typename T >
    ostream &operator << ( ostream & os, const vector< T > &v ) {
                os << "{";
                    for(auto it = v.begin(); it != v.end(); ++it) {
                                    if( it != v.begin() ) os << ", ";
                                            os << *it;
                                                }
                        return os << "}";
    }

    template < typename T >
    ostream &operator << ( ostream & os, const set< T > &v ) {
                os << "[";
                    for(auto it = v.begin(); it != v.end(); ++it) {
                                    if( it != v.begin() ) os << ", ";
                                            os << *it;
                                                }
                        return os << "]";
    }

    template < typename T >
    ostream &operator << ( ostream & os, const multiset< T > &v ) {
                os << "[";
                    for(auto it = v.begin(); it != v.end(); ++it) {
                                    if( it != v.begin() ) os << ", ";
                                            os << *it;
                                                }
                        return os << "]";
    }

    template < typename F, typename S >
    ostream &operator << ( ostream & os, const map< F, S > &v ) {
                os << "[";
                    for(auto it = v.begin(); it != v.end(); ++it) {
                                    if( it != v.begin() ) os << ", ";
                                            os << it -> first << " = " << it -> second ;
                                                }
                        return os << "]";
    }

    #define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

    clock_t tStart = clock();
    #define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

    void faltu () {
                cerr << endl;
    }

    template <typename T>
    void faltu( T a[], int n ) {
                for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
                    cerr << endl;
    }

    template <typename T, typename ... hello>
    void faltu( T arg, const hello &... rest) {
                cerr << arg << ' ';
                    faltu(rest...);
    }
    #else
    #define dbg(args...)
    #endif //Pias

    int deg[101000];

    int main() {

    }
