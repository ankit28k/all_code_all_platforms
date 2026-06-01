#include <bits/stdc++.h>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int size;
        cin >> size;

        vector<int> numbers(size);
        int freq[1001] = {0};  

        for (int i = 0; i < size; i++) {
            cin >> numbers[i];
            freq[numbers[i]]++;
        }

        bool hasDuplicate = false;
        for (int i = 0; i <= 1000; i++) {
            if (freq[i] > 1) {
                hasDuplicate = true;
                break;  
            }
        }

        cout << (hasDuplicate ? "YES\n" : "NO\n");
    }

    return 0;
}

