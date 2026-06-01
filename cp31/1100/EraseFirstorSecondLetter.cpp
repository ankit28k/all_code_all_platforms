#include<bits/stdc++.h>
using namespace std;

// The possible strings that can be made from given string be of length n...length n-1........length 1
// and the Distinct strings of length N be X1 , Length n-2 be ...X2.....of length 1 be Xn
// => ans = X1 + X2 + ....... Xn

// observe

//  for any given String of length n ...if i want to make a string of length i , it would have Last n-i Characters same and 
// we can remove any character from the left string. that is of length i 
//  Ex - abcad .....to convert it of length 3, we can remove any character that is a, b, c till 3 and it would form aad,cad,bad....
// where we can see last n-i characters are same
// Hands for hence for any index i, we need to find number of distinct characters till i .....
//Which can be removed to form a string of length i

 

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;

    unordered_map<char,int> m;
    vector<int> distel(n);

    int cnt=0;
    for(int i=0;i<n;i++){
      m[s[i]]++;
      if(m[s[i]] == 1) cnt++;

      distel[i] = cnt;

    }

    long long ans = 0;
    for(int i=0;i<n;i++) ans += distel[i];
    cout<<ans<<endl;












    //brute force -> O(2^n)
    // long long ans =1;
    // set<string> st;
    // st.insert(s);
    // fun(s,st,ans);
    // cout<<ans<<endl;  
  }
}


// void fun(string s,set<string>& st,long long& ans){

//   if(s.length()<2) return;
  
//   string r1idx = s , r2idx = s;
//   r1idx.erase(0,1);
//   r2idx.erase(1,1);


//   if(st.find(r1idx)==st.end()){
//     st.insert(r1idx);
//     ans++;
//     fun(r1idx,st,ans);
//   }

//   if(st.find(r2idx)==st.end()){
//     st.insert(r2idx);
//     ans++;
//     fun(r2idx,st,ans);
//   }
// }