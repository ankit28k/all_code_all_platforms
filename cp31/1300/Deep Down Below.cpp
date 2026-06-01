#include<bits/stdc++.h>
using namespace std;

/*
    LOGIC BREAKDOWN: THE AVALANCHE OF ERRORS VS. THE CORRECT RUNNING TOTAL

    EXAMPLE CAVES (After Sorting by required power):
    Cave 0: Needs 10 power, has 5 monsters.
    Cave 1: Needs 12 power, has 2 monsters.
    Cave 2: Needs 25 power, has 3 monsters.

    ---------------------------------------------------------------------------
    PART 1: THE OLD (WRONG) LOGIC
    Array stored: {required_power, exit_power_of_this_specific_cave}
    arr[0] = {10, 15}  // Needs 10, exits with 10+5=15
    arr[1] = {12, 14}  // Needs 12, exits with 12+2=14
    arr[2] = {25, 28}  // Needs 25, exits with 25+3=28

    Execution:
    1. Start: ans = arr[0][0] -> ans = 10.
    2. Cave 1: if(arr[1][0] > arr[0][1]) -> if(12 > 15) -> False. ans stays 10.
    3. Cave 2: if(arr[2][0] > arr[1][1]) -> if(25 > 14) -> True. 
               ans = arr[2][0] -> ans = 25.

    FATAL FLAW: 
    - You compared Cave 2's requirement (25) against Cave 1's isolated 
      exit power (14). You completely forgot the power gained from Cave 0!
    - Setting ans = 25 overwrites the entire answer instead of just 
      adding the deficit. It forces the hero to start with 25 power 
      (massive overkill).

    ---------------------------------------------------------------------------
    PART 2: THE NEW (CORRECT) LOGIC
    Array stores: {required_power, number_of_monsters}
    arr[0] = {10, 5}
    arr[1] = {12, 2}
    arr[2] = {25, 3}

    Execution:
    1. Start: 
       ans = arr[0][0] -> ans = 10. (Guessed starting power).
       curr = ans + arr[0][1] -> curr = 15. (Actual running total after Cave 0).

    2. Cave 1: 
       if(arr[1][0] > curr) -> if(12 > 15) -> False.
       curr += arr[1][1] -> curr = 15 + 2 = 17. (We have 17 power now).

    3. Cave 2: 
       if(arr[2][0] > curr) -> if(25 > 17) -> True!
       - DEFICIT: We need 25, but only have 17. We are short by 8.
       - ans += (25 - 17) -> ans = 10 + 8 = 18. (Retroactively start with 8 more).
       - curr = 25. (We now magically arrive at this cave with exactly 25).
       - curr += arr[2][1] -> curr = 25 + 3 = 28. (Kill the 3 monsters).

    FINAL ANSWER: 18. 
    By tracking the cumulative 'curr' power, we only add the exact deficit 
    to our starting answer, rather than blindly overwriting it.
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<vector<int>> arr ;
        for(int j=0;j<n;j++){
            int k;
            cin>>k;
            vector<int> temp(k);
            for(int i=0;i<k;i++) cin>>temp[i];

            int mini =temp[0]+1 , cnt =temp[0]+1;
            for(int i=1;i<k;i++){
                cnt++;
                if(temp[i]>=cnt){
                    mini = max(mini,temp[i]+1-i);
                    cnt = temp[i] + 1;
                } 
            }

            arr.push_back({mini,k});
        }

        
        sort(arr.begin(),arr.end());

        int ans =arr[0][0], curr = ans + arr[0][1];
        for(int i=1;i<n;i++){
            if(arr[i][0]>curr){
                ans += arr[i][0] - curr;
                curr = arr[i][0];
            }
            curr += arr[i][1];

        }

        cout<<ans<<endl;
        
    }

}