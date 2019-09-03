#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[],int n)
{
    //72351
    for(int i=1;i<=n-1;i++){
    int hole=i;
    int value=a[i];

    while(hole>0 && a[hole-1]>value){
        a[hole]=a[hole-1];
        hole--;
    }
    a[hole]=value;
}

}

int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
   insertion_sort( a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}
