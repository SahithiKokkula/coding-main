#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

bool is_square(int x) {
    if (x < 0) {
        return false;
    }
    int s = static_cast<int>(sqrt(x));
    return s * s == x;
}

void solve() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    int t;
    iss >> t;
    std::vector<int> cases(t);
    
    for (int i = 0; i < t; ++i) {
        iss >> cases[i];
    }
    
    for (int n : cases) {
        if (n == 1) {
            std::cout << -1 << std::endl;
            continue;
        }
        
        int total = n * (n + 1) / 2;
        if (is_square(total)) {
            std::cout << -1 << std::endl;
            continue;
        }
        
        if (n == 2) {
            std::cout << "2 1" << std::endl;
            continue;
        }
        
        std::vector<int> perm = {3, 2, 1};
        std::vector<int> remaining;
        for (int i = n; i > 3; --i) {
            remaining.push_back(i);
        }
        
        int current_sum = 6;
        int i = 0;
        
        while (i < remaining.size()) {
            if (i == remaining.size() - 1) {
                perm.push_back(remaining[i]);
                current_sum += remaining[i];
                i += 1;
            } else {
                int x = remaining[i];
                int next_sum = current_sum + x;
                if (is_square(next_sum)) {
                    std::swap(remaining[i], remaining[i + 1]);
                    x = remaining[i];
                    next_sum = current_sum + x;
                }
                
                perm.push_back(x);
                current_sum += x;
                i += 1;
            }
        }
        
        for (size_t j = 0; j < perm.size(); ++j) {
            std::cout << perm[j];
            if (j < perm.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    solve();
    return 0;
}

