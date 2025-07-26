#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, x, k;
        cin >> n >> x >> k;
        string s;
        cin >> s;

        long long time = 0; // Current time step
        long long no_of_zero_hit = 0; // Number of times position hits 0
        long long position = x; // Current position

        // Map to store states (position, index) and their corresponding time and hit count
        map<pair<long long, long long>, pair<long long, long long>> state_map;

        // Simulate until k steps are completed or a cycle is detected
        while (time < k) {
            // Check if the current state has been visited before
            auto current_state = make_pair(position, time % n);
            if (state_map.find(current_state) != state_map.end()) {
                // Cycle detected
                auto prev_state = state_map[current_state];
                long long cycle_time = time - prev_state.first; // Cycle length in time steps
                long long cycle_hits = no_of_zero_hit - prev_state.second; // Hits in one cycle

                // Calculate the number of full cycles in the remaining steps
                long long remaining_time = k - time;
                long long full_cycles = remaining_time / cycle_time;
                no_of_zero_hit += full_cycles * cycle_hits;
                time += full_cycles * cycle_time;

                // Break out of the loop as further steps will repeat the cycle
                break;
            }

            // Record the current state
            state_map[current_state] = make_pair(time, no_of_zero_hit);

            // Update position based on the current character
            long long index = time % n; // Current index in the string
            if (s[index] == 'L') {
                position--;
            } else {
                position++;
            }

            time++; // Increment time step

            // Check if position hits 0
            if (position == 0) {
                no_of_zero_hit++;
            }
        }

        // Output the total number of times position hits 0
        cout << no_of_zero_hit << endl;
    }
    return 0;
}