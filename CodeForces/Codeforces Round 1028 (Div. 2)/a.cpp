#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve() {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        
        // Gellyfish's knight can kill Flower's knight in one hit
        if (c >= d) {
            // Flower's knight is dead, Gellyfish's knight can attack Flower directly
            // Number of attacks needed: b
            // Gellyfish wins if b <= (number of attacks Gellyfish's knight can make)
            // Since Gellyfish's knight can attack every odd round, it can make ceil(b / 1) attacks
            // But Flower can also attack Gellyfish's knight if it's alive, but here it's dead
            // So Gellyfish's knight can attack Flower every odd round until Flower's HP is zero
            // So Gellyfish wins if b <= (number of attacks before Flower can kill Gellyfish)
            // But since Flower's knight is dead, Flower can't attack Gellyfish's knight
            // So Gellyfish's knight can attack Flower every odd round, and Flower can't attack back
            // So Gellyfish wins if b <= (number of attacks Gellyfish's knight can make)
            // Which is infinite since Flower's knight is dead
            // So Gellyfish wins
            cout << "Gellyfish" << endl;
        } else {
            // Flower's knight can kill Gellyfish's knight in one hit
            // Gellyfish's knight is dead, Flower's knight can attack Gellyfish directly
            // Number of attacks needed: a
            // Flower wins if a <= (number of attacks Flower's knight can make)
            // Since Flower's knight can attack every even round, it can make ceil(a / 1) attacks
            // But Gellyfish can also attack Flower's knight if it's alive, but here it's dead
            // So Flower's knight can attack Gellyfish every even round until Gellyfish's HP is zero
            // So Flower wins if a <= (number of attacks before Gellyfish can kill Flower)
            // But since Gellyfish's knight is dead, Gellyfish can't attack Flower's knight
            // So Flower's knight can attack Gellyfish every even round, and Gellyfish can't attack back
            // So Flower wins if a <= (number of attacks Flower's knight can make)
            // Which is infinite since Gellyfish's knight is dead
            // So Flower wins
            cout << "Flower" << endl;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin >> t;
    while (t--) {
        solution.solve();
    }
    return 0;
}
