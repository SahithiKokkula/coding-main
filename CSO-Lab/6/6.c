#include<stdio.h>
int main(){
    int n;
    printf("Enter number of digits to enter in array: ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int eve=0,odd=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0) eve++;
        else odd++;
    }
    int evearr[eve],oddarr[odd];
    int j=0,k=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0) evearr[j++]=arr[i];
        else oddarr[k++]=arr[i];
    }
    printf("Odd arr: ");
    for(int i=0;i<odd;i++){
        printf("%d ",oddarr[i]);
    }
    printf("\nEven arr: ");
    for(int i=0;i<eve;i++){
        printf("%d ",evearr[i]);
    }
    return 0;
}