#include<stdio.h>
int check(int numbers[],int n,int num){
    for(int i=0;i<n;i++){
        if(numbers[i]%num!=0){
            return 0;
        }
    }
    return 1;
}
int basecdn(int numbers[],int n){
    for(int i=0;i<n;i++){
        if(numbers[i]>1){
            return 1;
        }
    }
    return 0;
}
int isfactor(int numbers[],int n,int num){
    for(int i=0;i<n;i++){
        if(numbers[i]%num==0){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n;
    printf("Enter number of numbers: \n");
    scanf("%d",&n);
    int numbers[n];
    for(int i=0;i<n;i++){
        scanf("%d",&numbers[i]);
    }
    int min=__INT_MAX__;
    for(int i=0;i<n;i++){
        if(min>numbers[i]) min=numbers[i];
    }
    int gcd=1;
    for(int i=min;i>0;i--){
        if(check(numbers,n,i)==1){
            gcd=i;
            break;
        }
    }
    printf("GCD: %d\n",gcd);
    unsigned int lcm=1;
    int i=2;
    while(basecdn(numbers,n)==1){
        while(1){
            if(isfactor(numbers,n,i)==1){
                lcm*=i;
                for(int j=0;j<n;j++){
                    if(numbers[j]%i==0){
                        numbers[j]/=i;
                    }
                }
            }
            else{
                break;
            } 
        }
        i++;
    }
    printf("LCM: %u",lcm);
    return 0;
}