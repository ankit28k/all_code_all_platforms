#include<bits/stdc++.h>
using namespace std;

/*
LOGIC AND INTUITION:
Every number falls into one of two categories based on its last digit:


Category 1: Ends in 0 or 5. 
- 5 turns into 0 after one operation (e.g., 5 + 5 = 10).
- 0 stays 0. These numbers stop growing.
- If ANY number is in this category, ALL numbers must be in this category, 
    and they must all reach the exact same final value to be equal.


Category 2: Ends in 1, 2, 3, 4, 6, 7, 8, 9. 
- These digits always fall into an endless cycle: 2 -> 4 -> 8 -> 6 -> 2...
- The sum of one full cycle is 2 + 4 + 8 + 6 = 20.
- To check if numbers can become equal, we advance each number's last digit 
    forward until it becomes 2.
- Since they all now end in 2 and can only grow by exactly 20 per cycle, 
    they can only become equal if the difference between them is a multiple of 20.
*/


bool fun(vector<int>& arr,int n){
    sort(arr.begin(),arr.end());

    
    bool flag = false;
    for(int i=0;i<n;i++) {
        if(arr[i]%10 == 0 || arr[i]%5 ==0) {
            flag = true;
            break;
        }
    }

    int val = -1;
    if(flag){
        for(int i=0;i<n;i++){ 

            if(arr[i]%10 == 0) {
                if(val == -1) val = arr[i] ; 
                else if(arr[i] != val) return false; 
            }

            else if(arr[i]%10 != 0 && arr[i]%5 ==0) {
                if(val == -1) val = arr[i] + 5;
                else if(arr[i] + 5 != val) return false; 

            }

            else return false;

        }

        return true;
    }

    int r = arr[n-1]%10 , maxval  =-1;
    if(r==1) maxval = arr[n-1]+1;
    else if(r==2) maxval = arr[n-1];
    else if(r==3) maxval = arr[n-1] + 3 + 6;
    else if(r==4) maxval = arr[n-1] + 4 + 8 + 6;
    else if(r==6) maxval = arr[n-1] + 6;
    else if(r==7) maxval = arr[n-1] +7+ 4 + 8 + 6;
    else if(r==8) maxval = arr[n-1] + 8 + 6;
    else if(r==9) maxval = arr[n-1] + 9 + 8 + 6;

    for(int i=0;i<n-1;i++){
        int r = arr[i]%10 ;
        if(r==1) {
            arr[i] = arr[i]+1;
            if((maxval - arr[i])%20 !=0 ) return false;
        }
        else if(r==2) {
            arr[i] = arr[i];
            if((maxval - arr[i])%20 !=0 ) return false;
        }
        else if(r==3) {
            arr[i] = arr[i] + 3 + 6;
            if((maxval - arr[i])%20 !=0 ) return false;
        }
        else if(r==4) {
            arr[i] = arr[i] + 4 + 8 + 6;
            if((maxval - arr[i])%20 !=0 ) return false;
        }
        else if(r==6) {
            arr[i] = arr[i] + 6;
            if((maxval - arr[i])%20 !=0 ) return false;
        }
        else if(r==7) {
            arr[i] = arr[i] +7+ 4 + 8 + 6;
            if((maxval - arr[i])%20 !=0 ) return false;
        }
        else if(r==8) {
            arr[i] = arr[i] + 8 + 6;
            if((maxval - arr[i])%20 !=0 ) return false;
        }
        else if(r==9) {
            arr[i] = arr[i] + 9 + 8 + 6;
            if((maxval - arr[i])%20 !=0 ) return false;
        }
    }

    return true;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        if(fun(arr,n)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}