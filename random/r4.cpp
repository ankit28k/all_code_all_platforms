#include <iostream>
#include <vector>
#include <queue>
#include <functional>

class Solution {
public:
    int solution(std::vector<int> &A) {
        long long current_balance = 0;
        int relocations = 0;
        // Min-priority queue to store negative numbers (expenses)
        // We use greater<int> so the top is the smallest number (most negative)
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (int x : A) {
            current_balance += x;
            if (x < 0) {
                pq.push(x);
            }

            // If balance drops below zero, remove the largest debt (smallest number)
            // seen so far to 'move it to the end'.
            while (!pq.empty() && current_balance < 0) {
                int worst_expense = pq.top();
                pq.pop();
                current_balance -= worst_expense;
                relocations++;
            }
        }
        return relocations;
    }
};

int main() {
    int N;
    if (std::cin >> N) {
        std::vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }
        Solution sol;
        std::cout << sol.solution(A) << std::endl;
    }
    return 0;
}