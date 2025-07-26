// pattern 1

// #include<iostream>
// using namespace std;
// int main()
// {
//     for (int i=1;i<=5;i++){
//         for(int j=1;j<=5;j++){
//             if(i+j==4||i+j==8||i-j==2||j-i==2){
//             cout<<"* ";
//             }
//             else{
//                 cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// pattern 2


// #include<iostream>
// using namespace std;
// int main()
// {   
//     cout<<"enter rows and colums:"<<endl;
//     int rows;
//     int cols;
//     cin>>rows;
//     cin>>cols;
//     for (int i=1;i<=rows;i++){
//         for(int j=1;j<=cols;j++){
//             if(i==1||j==1||i==rows||j==cols){
//             cout<<"* ";
//             }
//             else{
//                 cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// } 




// pattern 3


// #include<iostream>
// using namespace std;
// int main()
// {   
//     cout<<"enter rows and colums:"<<endl;
//     int rows;
//     int cols;
//     cin>>rows;
//     cin>>cols;
//     for (int i=1;i<=rows;i++){
//         for(int j=1;j<=cols;j++){
//             if(i>=j){
//             cout<<"* ";
//             }
//             else{
//                 cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// } 



// pattern 4


// #include<iostream>
// using namespace std;
// int main()
// {   
//     cout<<"enter rows :"<<endl;
//     int rows;
//     int cols;
//     cin>>rows;
//     cols= rows*2-1;
//     for (int i=1;i<=rows;i++){
//         for(int j=1;j<=cols;j++){
//             if(i+j>=((cols+1)/2+1) && j-i<=((cols+1)/2-1)){
//             cout<<"* ";
//             }
//             else{
//                 cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// } 


// pattern 5


// #include<iostream>
// using namespace std;
// int main()
// {   
//     cout<<"enter :"<<endl;
//     int rows;
//     int cols;
//     cin>>rows;
//     cols=rows;
//     for (int i=0;i<=(rows-1);i++){
//         for(int j=1;j<=cols;j++){
//             if (i+j<=rows){
//                 cout<<i+j<<" ";
//             }
//             else{
//                 cout<<i+j-rows<<" ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// } 


// pattern 6

// #include<iostream>
// using namespace std;
// int main()
// {   
//     cout<<"enter rows and colums:"<<endl;
//     int rows;
//     int cols;
//     cin>>rows;
//     cin>>cols;
//     for (int i=1;i<=rows;i++){
//         for(int j=1;j<=cols;j++){
//             if((i+j)%2==0){
//             cout<<"1 ";
//             }
//             else{
//                 cout<<"2 ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// } 





// pattern 7




// #include<iostream>
// using namespace std;
// int main()
// {   
//     cout<<"enter rows"<<endl;
//     int rows;
//     int cols;
//     cin>>rows;
//     cols=(rows*2)-1;
//     for (int i=1;i<=rows;i++){
//         for (int k=1;k<=rows-i;k++){
//             cout<<"  ";
        
//         }
//         for (int j=1;j<=i;j++){
//             cout<<j<<" ";
//         }
//         for (int j=i;j>1;j--){
//             cout<<j-1<<" ";
//         }

//         cout<<endl;
//     }
//     return 0;
// } 




// pattern 8


// char(65=A)
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter number of rows: ";
//     cin>>n;
//     for (int i=1;i<=(n+1)/2;i++){
//         for (int j=1;j<=(n+1)/2-i;j++){
//             cout<<"  ";
//         }
//         for (int j=1;j<=i*2-1;j++){
//             cout<<char(64+j)<<" ";
//         }
//         cout<<endl;
//     }
//     for (int i=1;i<=(n-1)/2;i++){
//         for (int j=1;j<=i;j++){
//             cout<<"  ";
//         }
//         for (int j=1;j<=n-2*i;j++){
//             cout<<char(64+j)<<" ";
//         }
//         cout<<endl;
//     }
// }










// pattern 9



// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter number:";
//     cin>>n;
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=n;j++){
//             if(j==((n+1)/2)||i==((n+1)/2)){
//                 cout<<"+ ";
//             }
//             else{
//                 cout<<"  ";
//             }

//         }
//         cout<<endl;
//     }
// }




// pattern 10



// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter the number: ";
//     cin>>n;
//     cout<<endl;
    
// }