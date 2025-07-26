for (int i=1;i<=pow(n,0.5);i++){
        if (n%i==0){
            if(i==1||i==n) continue;
            else return 0;
        }
    }
    return 1;