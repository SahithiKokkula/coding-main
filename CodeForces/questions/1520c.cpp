#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    int count = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                matrix[i][j] = count++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 != 0) {
                matrix[i][j] = count++;
            }
        }
    }
    
    return matrix;
}

int main() {
    int t;
    cin >> t; 
    
    while (t--) {
        int n;
        cin >> n; 
        if (n==2){
            cout<<-1<<endl;
        }
        else{
            vector<vector<int>> matrix = generateMatrix(n);
            
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    
    return 0;
}
