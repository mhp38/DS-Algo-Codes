#include<bits/stdc++.h>


#define ll long long
#define all(x) x.begin(), x.end()
#define fill1d(x,val) memset(x,val,sizeof(x))
#define fill2d(x,val) fill_n(*x, sizeof(x)/sizeof(**x),val);
using namespace std;

struct point{
    int x,y;
};

ll m,n,t;
vector<point> P;

bool comp1(point a,point b){
    return a.y<b.y;
}

bool comp2(point a,point b){
    return a.x<b.x;
}

int orient(int p,int q, int r){
    int val = (P[q].y - P[p].y)*(P[r].x - P[q].x) - (P[r].y - P[q].y)*(P[q].x - P[p].x);

    if(val == 0)
        return 0;
    return val > 0 ? 1 : 2;
}

void solve(){

    if(n<3 || (n==3 && orient(0,1,2)==0 )){
      cout<<"-1";
      return;
    }

    vector<point> hull;

    int l=0, cur, next;

    for(int i=0;i<n;i++)
        if(P[i].x < P[l].x)
            l = i; //finding starting point : the one that is leftmost

    cur = l;
    do{
       // cout<<"\nadd: "<<P[cur].x<<" "<<P[cur].y;
        hull.push_back(P[cur]);
        next = (cur+1)%n;

        for(int i=0;i<n;i++)
            if(orient(cur,i,next)==2)
                next = i;

        cur = next;

    }while(cur != l);

    sort(all(hull),comp1);
    sort(all(hull),comp2);

    for(int i=0;i<hull.size()-1;i++){
        if(hull[i].x==hull[i+1].x && hull[i].y==hull[i+1].y)
            hull.erase(hull.begin()+i);
    }

    for(int i=0;i<hull.size()-1;i++)
        cout<<hull[i].x<<" "<<hull[i].y<<", ";
    cout<<hull[hull.size()-1].x<<" "<<hull[hull.size()-1].y;
}

int main(){
        cin>>t;
        while(t--){
            cin>>n;
            P.resize(n);
            for(int i=0;i<n;i++)
                cin>>P[i].x>>P[i].y;

            solve();
            P.clear();
            cout<<endl;
        }
	return 0;
}
