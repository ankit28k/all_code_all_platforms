#include<bits/stdc++.h>
using namespace std; 

/*
LOGIC & INTUITION:
The given condition is a[i] * a[j] = i + j. 
Since the maximum possible indices are n, the maximum possible value for i + j is 2*n - 1.
This implies we only need to look for pairs where a[i] * a[j] <= 2*n - 1. 
By sorting the array based on its values, as soon as a[i] * a[j] > 2*n - 1, we know that any subsequent a[j] will only result in an even larger product. Because of this, we can safely 'break' out of the inner loop early.

EXAMPLE:
n = 5, array = [3, 1, 5, 9, 2]
Max possible sum (i+j) is 2*5 - 1 = 9.
Sorted pairs (value, original_index): (1, 2), (2, 5), (3, 1), (5, 3), (9, 4)
- i=0 (val=1): 1*2=2, 1*3=3, 1*5=5, 1*9=9 (all <= 9, loop completes)
- i=1 (val=2): 2*3=6 (<= 9). Next is 2*5=10 (> 9). Break!
- i=2 (val=3): 3*5=15 (> 9). Break!
Notice how the 'break' stops the inner loop from checking useless, larger pairs.

WHY IT IS O(N log N) AND NOT O(N^2):
The outer loop fixes the first element; let's call its value 'x'.
The inner loop runs as long as x * y <= 2*n, which algebraically means y <= (2*n) / x.
Because all elements in the array are guaranteed to be distinct integers, the number of valid 'y' iterations is at most (2*n) / x.
If we sum the maximum number of inner loop iterations for all possible values of 'x' from 1 to 2*n:
Total Iterations = (2*n)/1 + (2*n)/2 + (2*n)/3 + ... + (2*n)/(2*n)
Total Iterations = 2*n * (1/1 + 1/2 + 1/3 + ... + 1/(2*n))
The series (1/1 + 1/2 + 1/3 + ... + 1/K) is the Harmonic Series, which mathematically converges to roughly log(K).
Therefore, the maximum number of total inner loop steps is bounded by 2*n * log(2*n). This makes the time complexity strictly O(N log N).
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<pair<long long,long long>> temp(n);
        for(int i=0;i<n;i++){
            temp[i] = {arr[i],i+1};
        }

        sort(temp.begin(),temp.end());

        long long cnt=0;

        //nlogn
        for(int i=0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if(temp[i].first*temp[j].first > 2*n -1) break;

                if(temp[i].first*temp[j].first == temp[i].second + temp[j].second)  cnt++;
            }
        }

        cout<<cnt<<endl;

        
    }

}