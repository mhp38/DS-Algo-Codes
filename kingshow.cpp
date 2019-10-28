#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>

using namespace std;

typedef struct{
 int x,y,level;
}data;

int mv[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m;
        cin>>n>>m;
        int a[n+1][m+1];
        memset(a,0,sizeof(a));
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;

        queue<data>qt;

        data d,d1,d2;
        int steps;

        d.x=r1;
        d.y=c1;
        d.level=0;

        qt.push(d);

        a[d.x][d.y]=2;

        bool f=false;
        int tmx,tmy,tml;

        while(!qt.empty())
        {
            if(f)break;

            d1=qt.front();
            qt.pop();

            for(int k=0;k<8;k++)
            {
                tmx=d1.x + mv[k][0];
                tmy=d1.y + mv[k][1];
                tml=d1.level + 1;

                if(tmx>=1 && tmx<=n && tmy>=1 && tmy<=m && a[tmx][tmy]==0)
                {
                    if(tmx==r2 && tmy==c2){
                        steps =tml;
                        f=true;
                        break;
                    }


                d2.x=tmx;
                d2.y=tmy;
                d2.level=tml;

                qt.push(d2);

                a[d2.x][d2.y]=2;

                }
            }

        }

        if(!f)
        {
            steps=-1;
        }

        cout<<"Case #"<<i<<endl;
        cout<<steps<<endl;

    }
}
