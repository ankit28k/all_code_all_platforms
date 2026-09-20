#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void merge(int low,int mid,int high,vector<int>& arr,int k,long long& ans){

        int l=low,r=mid+1;
        while(r<=high){
            while(l<=mid && arr[l]<=arr[r]+k) l++;
            ans += l-low;
            r++;
        }

        int i=low,j=mid+1;
        vector<int> temp;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
            
        }

        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }

        for(int i=low;i<=high;i++) arr[i] = temp[i-low];
    }
    void mgs(int low,int high,int k,vector<int>& arr,long long& ans){
        if(low>=high) return;
        int mid = (low + high)/2;

        mgs(low,mid,k,arr,ans);
        mgs(mid+1,high,k,arr,ans);
        merge(low,mid,high,arr,k,ans);
    }
    long long countFairPairs(int n, const std::vector<int>& score, const std::vector<int>& popularity, int k) {
        // Core logic to count the number of fair pairs goes here.
        long long count = 0;
        vector<int> sp(n);
        for(int i=0;i<n;i++){
            sp[i] = score[i] - popularity[i];
        }
        mgs(0,n-1,k,sp,count);
        return count;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> score(n);
    for (int i = 0; i < n; ++i) {
        cin >> score[i];
    }

    vector<int> popularity(n);
    for (int i = 0; i < n; ++i) {
        cin >> popularity[i];
    }

    int k;
    cin >> k;

    Solution sol;
    long long result = sol.countFairPairs(n, score, popularity, k);

    cout << result << std::endl;

    return 0;
}