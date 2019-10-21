#include<bits/stdc++.h>
#define ll long long
#define ios ios_base::sync_with_stdio(false)
#define pii pair<int, int>
#define fs first
#define sc second

using namespace std;

const ll INF=(1ll<<62)-1;
const int M=1e5+5;

bool visited[M];
int bars[M],barCount,sumOfAllBars,maximumBarLength;

bool isMaxBarLengthPossible(int barLengthTotal){

for(int i=barCount-1;i>=0;i--){
    if(!visited[i]){
        visited[i]=true;
        int barLength=barLengthTotal-bars[i];

        if(barLength==0)return true;
        else if(barLength>0 && isMaxBarLengthPossible(barLength)==true){
            return true;
        }
        else visited[i]=false;
    }
}
return false;
}

int mxBarLength()
{
    maximumBarLength= sumOfAllBars/2;
    for(int i=maximumBarLength;i>=0;i--){
        for(int j=0;j<barCount;j++){
            visited[j]=false;
        }

    bool isPipe1Possible = isMaxBarLengthPossible(i);
    bool isPipe2Possible = false;

    if(isPipe1Possible){
        isPipe2Possible=isMaxBarLengthPossible(i);
    }

    if(isPipe1Possible && isPipe2Possible)
    {
        return maximumBarLength;
    }
    else continue;
    }
    return -1;
}

 int main()
    {
        ios;
        cin>>barCount;
        sumOfAllBars=0;

        for(int i=0;i<barCount;i++){
            cin>>bars[i];
            sumOfAllBars+=bars[i];
        }

        cout<<mxBarLength()<<endl;

    }



