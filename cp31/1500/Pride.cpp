#include<bits/stdc++.h>
using namespace std;

int gcd(int a ,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int fun(vector<int>& arr,int n){

    if(n == 1) {
        if(arr[0]==1) return 0;
        else return -1;
    }
    bool flag = false;

    for(int i=0;i<n;i++){
        if(arr[i]==1) flag = true;
    }

    int cnt=0;
    
    while(!flag){
        vector<int> temp = arr;

        for(int i=0;i<n;i++){

            /* WHY WE ONLY CHECK RIGHT:
            Taking min(left_gcd, right_gcd) mixes two different subarray paths, creating "fake" numbers that don't exist. 
            Example: In [6, 30, 35], at index 1 (30), left GCD is 6, right GCD is 5. min(6,5) puts a fake '5' at index 1.
            By only doing gcd(arr[i], arr[i+1]), arr[i] perfectly tracks the true GCD of the expanding subarray starting exactly at index i.
            */

            if(i == n-1) {
                temp[i] = arr[i]; 
            }
            else{
                int g = gcd(arr[i],arr[i+1]);
                temp[i] = g;
                if(g==1) flag = true;
            }
            
            // if(i==0) {
            //     int g = gcd(arr[i],arr[i+1]);
            //     temp[i] = g;
            //     if(g==1) flag = true;
            // }

            // else if(i==n-1) {
            //     int g = gcd(arr[i],arr[i-1]);
            //     temp[i] = g;
            //     if(g==1) flag = true;
            // }

            // else{
            //     int g1= gcd(arr[i],arr[i+1]) , g2 = gcd(arr[i],arr[i-1]);
            //     temp[i] = min(g1,g2);
            //     if(g1==1 || g2==1) flag = true;
            // }

        }

        arr = temp;
        
        sort(temp.begin(),temp.end());
        if(temp[0] != 1 && (temp[0] == temp[n-1])) return -1;
        
        cnt++;
        
        if(cnt == n) return -1;
        if(flag){
            int ones =0;
            for(int i=0;i<n;i++){
                if(arr[i]==1) ones++;
            }
            //as many can become 1 at same time (parallel clone )...their count needs to be added....ones -1 as one already counted
            cnt+= ones -1; 
        }
        
    }

    

    
    // as 1 is stored in both l_one and r_one for non 1 elements as we can choose from 1st 1 ....and continue to any element ...and then chose the adjacent to make 1 so only 1 operation needed for each non 1 element

    //vector<int> r_one(n),l_one(n);
    // for(int i=0;i<n;i++){
    //     if(arr[i]==1) l_one[i]=0;
    //     else l_one[i] = 1; // as we choose adjacent....so start making 1 from first 1 got.....and only 1 operation from adjacent to make 1
    //     //else l_one[i] = i- prev; 
    // }
    
    // for(int i=n-1;i>=0;i--){
    //     if(arr[i]==1) r_one[i]=0;
    //     else r_one[i] = 1;
    //     //else r_one[i] = prev-i; 
    // }

    int sum=0;
    for(int i=0;i<n;i++){ 

        if(arr[i]!=1)  sum++; // as 1 is stored in both l_one and r_one for non 1 elements as we can choose from 1st 1 ....and continue to any element ...and then chose the adjacent to make 1 so only 1 operation needed for each non 1 element

        // if(i==0){
        //     if(arr[i]!=1)  sum+= r_one[i];
        // }
        // else if(i==n-1){
        //     if(arr[i]!=1)  sum+= l_one[i];
        // }

        // else{
        //     if(arr[i]!=1)  sum+= min(l_one[i],r_one[i]);
        // }   
        
    }

    return cnt + sum ;
}

int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<fun(arr,n)<<endl; 
}