#include<bits/stdc++.h>

using namespace std;

const int M=25;

int n,c,rare[10][10],area[25][25],visited[M][M],dist[M][M][M];

int min(int a,int b)
{
    return a>b? b:a;
}
int max(int a,int b)
{
    return a>b? a:b;
}

void bfs(int k,int i,int j,int dis)
{
    if(i<0 || i>n-1 || j<0 || j>n-1)return;
    if(area[i][j]==0)return;

    if(visited[i][j] !=0 && dist[i][j][k]<dis)return;

    visited[i][j]=1;
    dist[i][j][k]=dis;

    bfs(k,i+1,j,dis+1);
    bfs(k,i-1,j,dis+1);
    bfs(k,i,j+1,dis+1);
    bfs(k,i,j-1,dis+1);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        int i,j,k;
        for(int i=0;i<c;i++){
            cin>>rare[i][0]>>rare[i][1];
            rare[i][0]--;
            rare[i][1]--;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                visited[i][j]=0;
                cin>>area[i][j];

                for(int k=0;k<c;k++){
                    dist[i][j][k]=-1;
                }
            }
        }

        for(int i=0;i<c;i++)
        {
            bfs(i,rare[i][0],rare[i][1],0);

            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    visited[j][k]=0;
                }
            }
        }

        int ans=10000007,f=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(area[i][j]==1){
                    int mx=0;
                    for(int k=0;k<c;k++){
                        if(dist[i][j][k]==-1)f=1;

                        if(dist[i][j][k]>mx)mx=dist[i][j][k];
                    }

                    if(ans>mx)ans=mx;
                }
            }
        }

        if(f==1)cout<<"NO answer"<<endl;
        else cout<<ans<<endl;
    }
}
