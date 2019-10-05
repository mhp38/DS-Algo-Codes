// https://blog.csdn.net/lihenair/article/details/17227667

#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>

using namespace std;

int N, max_jewel;
bool visited[11][11];
int T,t, arr[11][11],i,j;
int path[11][11];
int out[11][11];

void save_path(){
int i, j;

for(i=0;i<N;i++)
    for(j=0;j<N;j++)
        out[i][j]=path[i][j];

}

void Khoj_the_search(int row, int col, int total){

    visited[row][col] = true;
    path[row][col] = 3;
    //printf("%d %d %d %d\n",row,col,total,max_jewel);
    if(row==0&&col==0&&arr[row][col]==2) total++;

    if(row==N-1&&col==N-1) {
     if( total > max_jewel) {
            max_jewel = total;
            save_path();
     }
     visited[row][col]=false;
     return;
    }

    if(col+1<=N-1){
        if( arr[row][col+1]!=1 && !visited[row][col+1] ) {
            if(arr[row][col+1]==2)
            Khoj_the_search(row,col+1,total+1);
            else
            Khoj_the_search(row,col+1,total);

            path[row][col+1] = arr[row][col+1];
        }
        //total--;
        //visited[row][col+1] = false;
    }

    if(col-1>=0){
        if( arr[row][col-1]!=1 && !visited[row][col-1] )
        {
            if(arr[row][col-1]==2)    Khoj_the_search(row,col-1,total+1);
            else                      Khoj_the_search(row,col-1,total);
            path[row][col-1] = arr[row][col-1];
        }
        //total--;
        //visited[row][col-1] = false;
    }

    if(row+1<=N-1){
        if( arr[row+1][col]!=1 && !visited[row+1][col] )
           {
            if(arr[row+1][col]==2)
            Khoj_the_search(row+1,col,total+1);
            else
            Khoj_the_search(row+1,col,total);

            path[row+1][col] = arr[row+1][col];
           }
        //total--;
        //visited[row+1][col] = false;
    }

    if(row-1>=0){
        if( arr[row-1][col]!=1 && !visited[row-1][col] )
        {
            if(arr[row-1][col]==2)
            Khoj_the_search(row-1,col,total+1);
            else
                Khoj_the_search(row-1,col,total);

            path[row-1][col] = arr[row-1][col];

        }
        //total--;
        //visited[row-1][col] = false;
    }





visited[row][col] = false;
return;
}

int main(){

    //freopen("picking_jewels_testcase.txt","r",stdin);
    //freopen("picking_jewels_out.txt","w",stdout);
    int total_zero;
    scanf("%d",&T);

    for(t=1;t<=T;t++){

    scanf("%d",&N);
    memset(visited,false,sizeof(visited));
    total_zero=0;
    max_jewel = -1;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            {
                scanf("%d",&arr[i][j]);
                if(arr[i][j]==0) total_zero++;
            }

    if(total_zero<N*N){
                                Khoj_the_search(0,0,0); // row, col, totl
                                for(i=0;i<N;i++)
                                    for(j=0;j<N;j++)
                                        if(out[i][j]!=3) out[i][j]=arr[i][j];
                                for(i=0;i<N;i++){
                                    for(j=0;j<N;j++)
                                        printf("%d ",out[i][j]);
                                    printf("\n");
                                }
                                    printf("%d\n\n",max_jewel); // need 2 newline, because, every output is separated by a blank line
                        }

                else{
                                for(i=0;i<N;i++){
                                    for(j=0;j<N;j++)
                                        printf("0 ");
                                    printf("\n");
                                }
                                        printf("0\n\n");

                }

    }

return 0;
}


