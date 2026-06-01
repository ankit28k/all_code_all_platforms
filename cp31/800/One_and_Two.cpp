#include <bits/stdc++.h>
using namespace std;


int onetwo(vector<int> &arr ,int count1 , int count2 ){

  int n = arr.size();
  if(count2 == 0) return 1;

  else{

    if(count2%2 != 0) return -1;

    else{

      int midc = count2/2 , count = 0;

      for(int i=0 ; i< n ;i++){

        if(arr[i] == 2) count++;
        if(count == midc) return i+1;  
      }

    }

  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin>>n;

    vector<int> arr(n);
    int count1 = 0, count2 = 0;

    for(int i=0;i<n;i++){
      
      cin>>arr[i];

      if(arr[i] == 1)  count1++;
      if(arr[i] == 2)  count2++;
      
    }

    cout<<onetwo(arr,count1,count2)<<endl; 
    
  }
}