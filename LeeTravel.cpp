#include<bits/stdc++.h>
#define ll long long
#define ios ios_base::sync_with_stdio(false)
#define pii pair<int, int>
#define fs first
#define sc second

using namespace std;

const ll INF=(1ll<<62)-1;
const int M=50;

int airfare[M][M];
bool visOffice[M];
int officesCount;

int mnFare=INT_MAX;

void minimumAirfare(int cityCount, int currentCity,int costTillnow)
{
    if((cityCount == officesCount) && airfare[currentCity][0] != 0){/// As No. 1 office is regarded as his company (Departure point).
        if(costTillnow + airfare[currentCity][0] < mnFare){
            mnFare = costTillnow + airfare[currentCity][0];
            return;
        }
    }

    for(int i=0;i<officesCount;i++){
        if(!visOffice[i] && airfare[currentCity][i] != 0){
            visOffice[i] = true;
            minimumAirfare(cityCount+1, i ,costTillnow + airfare[currentCity][i]);
            visOffice[i] = false;
        }
    }
}

 int main()
    {
        ios;
        int t;
        cin>>t;
        while(t--)
        {

            cin>>officesCount;
            for(int i=0;i<officesCount;i++){
                for(int j=0;j<officesCount;j++){
                    cin>>airfare[i][j];
                }
            }

            for(int i=0;i<officesCount;i++)visOffice[i]=false;

            visOffice[0]=true;

            minimumAirfare(1,0,0);

            cout<<mnFare<<endl;
        }
    }



