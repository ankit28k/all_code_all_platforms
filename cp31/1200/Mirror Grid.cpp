#include<bits/stdc++.h>
using namespace std;

int fun(vector<vector<char>>& arr,int n){
    if(n==1) return 0;
    int cnt=0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){

            int nzero = 0, none = 0;
            if(arr[i][j] =='0') nzero++;
            else none++;

            if(arr[n-1-j][i] =='0') nzero++;
            else none++;

            if(arr[n-1-i][n-1-j] =='0') nzero++;
            else none++;

            if(arr[j][n-1-i] =='0') nzero++;
            else none++;

            cnt += min(none,nzero);


            // Here is a quick example of why: Imagine your four symmetric cells are 0, 1, 0, 1.
            // Your first if compares 0 and 1. They don't match, so it flips the 0 to 1. (cnt = 1).
            // Your second if compares your new 1 with the next 0. They don't match, so it flips the 1 back to 0. (cnt = 2).
            // Your third if compares your new 0 with the last 1. They don't match, so it flips the 0 back to 1. (cnt = 3).
            //Your code calculates 3 operations. But the actual minimum operations to make all four cells match is just 2 (either flip the two 0s to 1s, or the two 1s to 0s).

            // if(arr[i][j] != arr[n-1-j][i] ){
            //     if(arr[i][j]=='0') arr[i][j] = '1';
            //     else arr[i][j] = '0';
            //     cnt++;
            // }

            // if(arr[i][j] != arr[n-1-i][n-1-j] ){
            //     if(arr[i][j]=='0') arr[i][j] = '1';
            //     else arr[i][j] = '0';
            //     cnt++;
            // }

            // if(arr[i][j] != arr[j][n-1-i]){
            //     if(arr[i][j]=='0') arr[i][j] = '1';
            //     else arr[i][j] = '0';
            //     cnt++;
            // }

             
        }
    }

    return cnt/4;  
    // The nested loops (i from 0 to n, j from 0 to n) iterate over every single cell in the entire grid. However, the logic inside groups cells into sets of 4 symmetric counterparts.
    // This means as the loops traverse the grid, every 4-cell group gets evaluated exactly 4 separate times (once when the loops land on each of its 4 coordinates). 
    //Dividing the final accumulated cnt by 4 corrects this overcounting to give the true minimum number of flips. 
    // Example for a 3x3 grid (n = 3):
    // The four corners form one symmetric group: (0,0), (0,2), (2,2), and (2,0).
    
    // As the nested loops run, you calculate and add the minimum flips for 
    // this exact same group four different times:
    // 1. When i = 0, j = 0 -> checks (0,0), (2,0), (2,2), (0,2)
    // 2. When i = 0, j = 2 -> checks (0,2), (0,0), (2,0), (2,2)
    // 3. When i = 2, j = 0 -> checks (2,0), (2,2), (0,2), (0,0)
    // 4. When i = 2, j = 2 -> checks (2,2), (0,2), (0,0), (2,0)
    
    // Because the required operations for this group are added to 'cnt' 4 times 
    // instead of just once, dividing by 4 at the end corrects the total.


}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<char>> arr(n,vector<char>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        } 

        cout<<fun(arr,n)<<endl;
    }

}