#include<stdio.h>
int main(){
    int n;
    printf("Enter number of digits to enter in array: ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    printf("Mean of data is: %f\n",sum/((float)n));

    
    float median=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }

    if(n%2==0){
        median=(arr[n/2-1]+arr[n/2])/2.0;
    }
    else{
        median=arr[(n+1)/2-1];
    }
    printf("Median of data is: %f\n",median);

    int maxidx=0;
    for (int i=0;i<n;i++){
        if(arr[i]>arr[maxidx]) maxidx=i;
    }
    int freq[arr[maxidx]+1];
    for(int i=0;i<arr[maxidx]+1;i++){
        freq[i]=0;
    }
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    int maxfreq=0;
    for(int i=0;i<arr[maxidx]+1;i++){
        if(maxfreq<freq[i]){
            maxfreq=freq[i];
        }
    }
    printf("Mode of data is: ");
    for(int i=0;i<arr[maxidx]+1;i++){
        if(freq[i]==maxfreq){
            printf("%d ",i);
        }
    }
    return 0;
}