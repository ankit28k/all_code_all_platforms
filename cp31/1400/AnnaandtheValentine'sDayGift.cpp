#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<string> s(n);

        for(int i=0;i<n;i++){

            string temp = to_string(arr[i]);

            int j=temp.length()-1 ;

            while(temp[j]=='0') {
                temp.pop_back();
                j--;
            }
            s[i] = temp;

        }

        sort(s.begin(),s.end());
        
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += s[i].length();
        }

        if(sum >= m) cout<<"Sasha"<<endl;
        else cout<<"Anna"<<endl;

    }

}