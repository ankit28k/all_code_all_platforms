#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& ans){

    for(int i=0;i<ans.size();i++){
        if(ans[i] == 0) return false;
    }
    return true;
}
int fun(string& s,int n,vector<int>& ans){

    int lc =0 , rc =0; 
    for(int i=0;i<n;i++){
        if(s[i]=='(') lc++;
        if(s[i]==')') rc++; 
    }

    if(lc != rc) return -1;

    vector<int> temp1(n,0);

    //case of 1....check if single can work
    stack<pair<char,int>> tst1; 
    for(int i=0;i<n;i++){ 

        if(tst1.size()>0 && s[i] == ')' && tst1.top().first == '(') {
            
            temp1[i] = 1;
            temp1[tst1.top().second] = 1;
            tst1.pop(); 
        }

        else if(s[i]=='('){
            tst1.push({s[i],i}); 
        } 
    }

    if(check(temp1)) {
        ans = temp1;
        return 1;
    }

    stack<pair<char,int>> tst2; 
    vector<int> temp2(n,0);

    for(int i=0;i<n;i++){  
            
        if(tst2.size()>0 && s[i] == '(' && tst2.top().first == ')') { 
            temp2[i] = 1;
            temp2[tst2.top().second] = 1; 
            tst2.pop();
        }

        else if(s[i]==')'){
            tst2.push({s[i],i}); 
        } 
        
    }

    if(check(temp2)) {
        ans = temp2;
        return 1;
    }
    


    //case of 2

    bool fused = false;

    stack<pair<char,int>> st1; 

    for(int i=0;i<n;i++){ 

        if(st1.size()>0 && s[i] == ')' && st1.top().first == '(') {
            
            ans[i] = 1;
            ans[st1.top().second] = 1;
            st1.pop();
            fused = true;
        }

        else if(s[i]=='('){
            st1.push({s[i],i}); 
        }

        // does 2 times i++ happens causing missing and segmentation fault...and if ignore i++ in while loop...its infinite loop
        // else if(s[i]==')' && st1.empty()) {  
        //     while(s[i]==')') {
        //         i++;
        //         continue;
        //     } 
        // }
    }
    
    
    //bool sused = false;
    stack<pair<char,int>> st2; 

    for(int i=0;i<n;i++){ 

        if(ans[i] == 0){
            
            if(st2.size()>0 && s[i] == '(' && st2.top().first == ')') {
                
                if(fused) {
                    ans[i] = 2;
                    ans[st2.top().second] = 2;
                }

                else{
                    ans[i] = 1;
                    ans[st2.top().second] = 1;
                }
                //sused  = true;
                st2.pop();
            }

            else if(s[i]==')'){
                st2.push({s[i],i}); 
            }

            // else if(s[i]=='(' && st2.empty()) {
            //     while(s[i]=='(') {
            //         i++;
            //         continue;
            //     }
                 
            // }
        }
    }
    
    return 2;

    // if(fused ^ sused) return 1;
    // else return 2;

    
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        vector<int> ans(n,0);
        int colors = fun(s,n,ans);
        if(colors != -1) {
            cout<<colors<<endl;
            for(int x:ans) cout<<x<<" ";
            cout<<endl;
        }

        else cout<<-1<<endl;
    }

}