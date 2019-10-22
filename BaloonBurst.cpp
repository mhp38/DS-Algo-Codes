#include<iostream>
using namespace std;

const int M=501;

int baloons[M],baloonLength,maxPoints;
bool isBusrst[M];

int isLeftPossible(int index)
{
    if(index >-1 )
    {
        for(int j=index;j>=0;j--){
            if(!isBusrst[j])return baloons[j];
        }
    }
    return 1;//left a r nai tai 1 multiply hobe
}

int isRightPossible(int index)
{
    if(index < baloonLength)
    {
        for(int j=index;j<baloonLength;j++){
            if(!isBusrst[j])return baloons[j];
        }
    }
    return 1;//right a r nai tai 1 multiply hobe
}

int calcPoints(int index)
{
    int left = isLeftPossible(index-1);//1 minus coz left er ta check kortesey
    int right = isRightPossible(index+1);//1 add cz right er ta check kortesey

    if(left==1 && right==1){//maney left ba right a nai tai oita e return korbe cz 1 diye multiply kora r oita rakha same kotha
        return baloons[index];//Maney 1 tai element baki just oi element tai niba
    }
    else return left*right;
}



void maximumPoint(int count,int currentPoints)
{
    if(count==baloonLength){
        if(currentPoints>maxPoints){
            maxPoints=currentPoints;
            return;
        }
    }
    else{
        for(int i=0;i<baloonLength;i++){
            if(!isBusrst[i]){
                isBusrst[i]=true;
                maximumPoint(count+1,currentPoints + calcPoints(i));
                isBusrst[i]=false;
            }
        }
    }
}

int main()
{
    cin>>baloonLength;
    for(int i=0;i<baloonLength;i++){
        cin>>baloons[i];
        isBusrst[i]=false;
    }
    maxPoints=0;
    maximumPoint(0,0);
    cout<<maxPoints<<endl;
}
