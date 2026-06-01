#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, x;
    cin >> n >> k >> x;

    // Case 1: Only one number exists and it's forbidden
    if (k == 1 && x == 1) {
      cout << "NO"<<endl;;
      continue;
    }

    // Case 2: x != 1 -> use 1's
    if (x != 1) {
      cout << "YES"<<endl;
      cout << n <<endl;
      for (int i = 0; i < n; i++) cout << 1 << " ";
      cout << endl;
      continue;
    }

    // Case 3: x == 1 -> can't use 1
    if (n % 2 == 0) {
      // Even sum -> use pairs of 2's
      cout << "YES "<<endl;
      cout << n / 2 <<endl;
      for (int i = 0; i < n / 2; i++) cout << 2 << " ";
      cout <<endl;;

    } 
    else {
      if (k < 3)  cout << "NO"<<endl;
      
      else {
        // Use one 3, rest with 2's
        cout << "YES"<<endl;
        cout << (n - 3) / 2 + 1 << endl;
        cout << 3 << " ";
        for (int i = 0; i < (n - 3) / 2; i++) cout << 2 << " ";
        cout << endl;
      }
    }
  }
  
}




// #include <bits/stdc++.h>
// using namespace std;

 
// void printsequence(int n,int k,int x){

//   vector<int> ans;
//   while(n){
//     if(k==x) {
//       k--;
//       continue;
//     }
//     if(k<=n) {
//       ans.push_back(k);
//       n = n-k; 
//     }
//     if(k>n) k--;
//   }

//   cout<<ans.size()<<endl;
//   for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
//   cout<<endl;
// }

// int main(){
//   int t;
//   cin>>t;
//   while (t--)
//   {
//     int n,k,x;
//     cin>>n>>k>>x;

//     if(k==1 && x==1){
//       cout<<"NO"<<endl;
//       continue;
//     }
//     if(x != 1){
//       cout<<"YES"<<endl;
//       printsequence(n,k,x);
//       continue;
//     }

//     else{
//       if(n%2 == 1) {
//         cout<<"NO"<<endl;
//         continue;
//       }
//       else {
//         cout<<"YES"<<endl;
//         printsequence(n,k,x);
//       }
//     }
//   }
  
// }