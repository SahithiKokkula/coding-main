#include <iostream>
using namespace std;

int main() {
    unsigned long long n;
    cin >> n;
    int pos = 0;
    while (n >>= 1) {
        pos++;
    }
    cout << pos << endl;
    return 0;
}