#include<bits/stdc++.h>
#define ll long long
#define ios ios_base::sync_with_stdio(false)

using namespace std;
const int M=500;
int path[M],adj[M][M];
bool vis[M];

int n,e;
int k,l;

int recur(int node,int counter)
{
    path[counter]=node;

    for(int y=0;y<n;y++)
    {
        if(adj[node][y])
        {
            if(vis[y])//cycle paisi
            {
                k=y;
                l=node;
                return -1;
            }
            vis[y]=true;//Eikhane vis true kora mane hoilo eita visit korsi ekhon eita theke recursion chalabo

            int i=recur(y,counter+1);

            if(i==-1)return -1;

            vis[y]=false;
        }
    }
}

void driver()
{
    for(int x=0;x<n;x++)
    {
        vis[x]=true;
        path[0]=x;
        for(int y=0;y<n;y++)
        {
            if(adj[x][y])
            {
                if(vis[y]==true)
                {
                   if(x==y)
                   {
                     k=-1;
                     return;
                   }
                }
                vis[y]=true;

                int ret=recur(y,1);

                if(ret==-1)return;
                vis[y]=false;
            }
        }
    }
}

void output()
{
    cout<<endl;
    if(k==-2)//cycle nai k er value initial -2 e asey
    {
        cout<<-1<<endl;
        return;
    }
    if(k==-1)//self loop
    {
        cout<<path[0]<<endl;//Eita may be na dileo hobe but tao dio kono case a lagtey parey
        return;
    }
    int start_index=0;

    for(int i=0;i<500;i++)
    {
        if(path[i]==k)start_index=i;
    }
    for(int i=start_index;i<500;i++)
    {
        if(path[i]==l){
            cout<<path[i]<<"->";
            break;
        }
        cout<<path[i]<<"->";
    }
    cout<<path[start_index]<<endl;
}

 int main()
    {
        ios;

        int t;
        cin>>t;
        while(t--)
        {
            //First a reset kortey hobe tai input neoar agey reset korlam shobe(3 tai)
            for(int i=0;i<500;i++)
            {
               for(int j=0;j<500;j++)
               {
                adj[i][j]=0;
                vis[i]=false;
                path[i]=-1;
               }
            }

            k=-2,l=-2;//Emeni -2 ekta value dhorlam r ki


            cin>>n>>e;// node and edge
            for(int i=0;i<e;i++)
            {
                int x,y;
                cin>>x>>y;
                adj[x][y]=1;//adjacency
            }

            driver();
            output();
        }
    }



