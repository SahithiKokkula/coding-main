#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int arraySize;
        ll targetSum, requiredElement;
        cin >> arraySize >> targetSum >> requiredElement;

        vector<ll> elements(arraySize + 1), prefixSum(arraySize + 1);
        for (int i = 1; i <= arraySize; i++) {
            cin >> elements[i];
            prefixSum[i] = prefixSum[i - 1] + elements[i];
        }

        ll resultCount = 0;
        int segmentStart = 1;

        for (int i = 1; i <= arraySize + 1; i++) {
            if (i == arraySize + 1 || elements[i] > requiredElement) {
                int left = segmentStart, right = i - 1;

                if (left <= right) {
                    vector<ll> uniqueValues;
                    uniqueValues.reserve((right - left + 2) * 2);

                    for (int j = left - 1; j <= right; j++) {
                        uniqueValues.push_back(prefixSum[j]);
                        uniqueValues.push_back(prefixSum[j] - targetSum);
                    }

                    sort(uniqueValues.begin(), uniqueValues.end());
                    uniqueValues.erase(unique(uniqueValues.begin(), uniqueValues.end()), uniqueValues.end());

                    int valueCount = uniqueValues.size();
                    auto getIndex = [&](ll value) {
                        return int(lower_bound(uniqueValues.begin(), uniqueValues.end(), value) - uniqueValues.begin());
                    };

                    vector<int> frequency(valueCount);
                    ll totalSubarrays = 0;
                    frequency[getIndex(prefixSum[left - 1])]++;

                    for (int j = left; j <= right; j++) {
                        int requiredIndex = getIndex(prefixSum[j] - targetSum);
                        totalSubarrays += frequency[requiredIndex];
                        frequency[getIndex(prefixSum[j])]++;
                    }

                    // find indices where element == requiredElement
                    vector<int> matchingPositions;
                    for (int j = left; j <= right; j++) {
                        if (elements[j] == requiredElement)
                            matchingPositions.push_back(j);
                    }

                    if (!matchingPositions.empty()) {
                        ll subarraysWithoutRequired = 0;
                        int subSegmentStart = left;

                        for (int idx = 0; idx <= (int)matchingPositions.size(); idx++) {
                            int subSegmentEnd = (idx < (int)matchingPositions.size() ? matchingPositions[idx] - 1 : right);
                            if (subSegmentStart <= subSegmentEnd) {
                                fill(frequency.begin(), frequency.end(), 0);
                                frequency[getIndex(prefixSum[subSegmentStart - 1])]++;

                                for (int j = subSegmentStart; j <= subSegmentEnd; j++) {
                                    int requiredIndex = getIndex(prefixSum[j] - targetSum);
                                    subarraysWithoutRequired += frequency[requiredIndex];
                                    frequency[getIndex(prefixSum[j])]++;
                                }
                            }

                            if (idx < (int)matchingPositions.size())
                                subSegmentStart = matchingPositions[idx] + 1;
                        }

                        resultCount += (totalSubarrays - subarraysWithoutRequired);
                    }
                }

                segmentStart = i + 1;
            }
        }

        cout << resultCount << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
