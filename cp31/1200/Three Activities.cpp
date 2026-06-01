#include<bits/stdc++.h>
using namespace std; 

bool comp(pair<int,int>& a,pair<int,int>& b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

// int fun(vector<pair<int,int>>& arr,vector<pair<int,int>>& brr,vector<pair<int,int>>& crr,int n){
    
//     if(arr[0].second == brr[0].second && arr[0].second == crr[0].second && brr[0].second == crr[0].second){
//         // if(arr[0].first == brr[0].first && arr[0].first == crr[0].first && brr[0].first == crr[0].first){
//         //     int max1 = arr[0].first + max(arr[1].first + brr[2].first , arr[1].first + crr[2].first) ; //first of second element is max
//         //     int max2 = arr[0].first + max(brr[1].first + arr[2].first , brr[1].first + crr[2].first) ; //first of second element is max
//         //     int max3 = arr[0].first + max(crr[1].first + arr[2].first , crr[1].first + brr[2].first) ; //first of second element is max
//         //     return max(max1 , max(max2,max3)) ;
//         // }
//         //else { down } 

//         int max1 = arr[0].first + max(brr[1].first + crr[2].first , crr[1].first + brr[2].first) ; //first is max
//         int max2 = brr[0].first + max(arr[1].first + crr[2].first , crr[1].first + arr[2].first) ; //second is max
//         int max3 = crr[0].first + max(arr[1].first + brr[2].first , brr[1].first + arr[2].first) ; //third is max

//         return max(max1 , max(max2,max3)) ;
//     }

//     else if(arr[0].second == brr[0].second){
//         return crr[0].first + max(arr[0].first + brr[1].first , brr[0].first + arr[1].first) ;
//     }

//     else if(arr[0].second == crr[0].second){
//         return brr[0].first + max(arr[0].first + crr[1].first , crr[0].first + arr[1].first) ;
//     }

//     else if(brr[0].second == crr[0].second){
//         return arr[0].first + max(brr[0].first + crr[1].first , crr[0].first + brr[1].first) ;
//     }

//     else return arr[0].first + brr[0].first + crr[0].first  ;

    
// }

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> arr(n),brr(n),crr(n); 

        for(int i=0;i<3;i++) {

            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                if(i==0) arr[j] = {x,j};
                else if(i==1) brr[j] = {x,j};
                else crr[j] = {x,j};
                
            } 
        } 
        sort(arr.begin(),arr.end(),comp);
        sort(brr.begin(),brr.end(),comp);
        sort(crr.begin(),crr.end(),comp);

        // cout<<fun(arr,brr,crr,n)<<endl;
        int ans = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                for(int k=0; k<3; k++){
                    if(arr[i].second != brr[j].second && arr[i].second != crr[k].second && brr[j].second != crr[k].second){
                        ans = max(ans, arr[i].first + brr[j].first + crr[k].first);
                    }
                }
            }
        }
        cout<<ans<<endl; 
 
    }

}