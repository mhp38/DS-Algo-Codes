    #include<iostream>
        using namespace std;

        void merge(int *,int,int,int);
        void mergesort(int *a,int low,int high){
        int mid=(high+low)/2;

        if(low<high){

        mergesort(a,low,mid);

         mergesort(a,mid+1,high);
     merge(a,low,high,mid);

        }
        return;
        }

        void merge(int *a,int low,int high,int mid ){
        int i=low,j=mid+1,k=low,c[100];
        while(i<=mid && j<= high){
            if(a[i]<a[j]){
                c[k]=a[i];
                i++;
                k++;
            }

            else {
                c[k]=a[j];
                k++;
                j++;
            }
        }
        while(i<=mid){
            c[k]=a[i];
            i++;
            k++;
        }

         while(j<=high){
            c[k]=a[j];
            j++;
            k++;
        }

        for(i=0;i<k;i++){
            a[i]=c[i];
        }

        }

    int main()
    {
        int n,a[100],i;
        cin>>n;

        for(i=0;i<n;i++){
            cin>>a[i];
        }

        mergesort(a,0,n-1);

         for(i=0;i<n;i++){
            cout<<a[i]<<" ";
        }

    }
