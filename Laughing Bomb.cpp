#include<iostream>
#include<string.h>
#include<queue>
#include<stdio.h>

using namespace std;

typedef struct{
int x,y,level;
}data;

int mv[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m;
        cin>>n>>m;
        int a[m+1][n+1];

        memset(a,0,sizeof(a));

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }

        int r,c;
        cin>>r>>c;

        queue<data>qt;

        data d,d1,d2;
        d.x=c;
        d.y=r;
        d.level=1;
        qt.push(d);

        a[d.x][d.y]=2;

        int tmx,tmy,tml;

        while(!qt.empty())
        {
            d1=qt.front();
            qt.pop();

            for(int k=0;k<4;k++){
                tmx=d1.x+mv[k][0];
                tmy=d1.y+mv[k][1];
                tml=d1.level+1;

                if(a[tmx][tmy]==1){
                    d2.x=tmx;
                    d2.y=tmy;
                    d2.level=tml;

                    qt.push(d2);

                    a[d2.x][d2.y]=2;
                }
            }
        }

        cout<<"Case #"<<i<<endl;
        cout<<tml-1<<endl;
    }
}
