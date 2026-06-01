#include<bits/stdc++.h>
using namespace std;

string mex(string& s,int n){

    for(int i=97 ;i<=122;i++){
        char c = (char)i;
        if(s.find(c) == string::npos) return string(1,c);
    }

    for(int i=97 ;i<=122;i++){
         
        string temp = "";
        char c = (char)i;
        temp.push_back(c);

        for(int j=97 ;j<=122;j++){

            char c2 = (char)j; 
            temp.push_back(c2);
            
            if(s.find(temp) == string::npos) return temp;
            temp.pop_back();
        }
         
    }

    for(int i=97 ;i<=122;i++){
         
        string temp = "";
        char c = (char)i;
        temp.push_back(c);

        for(int j=97 ;j<=122;j++){

            char c2 = (char)j; 
            temp.push_back(c2);

            for(int k=97 ;k<=122;k++){

                char c3 = (char)k; 
                temp.push_back(c3);
                
                if(s.find(temp) == string::npos) return temp;
                temp.pop_back();
            }

            temp.pop_back();
        }
         
    }

    return "-1";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<mex(s,n)<<endl;
    }

}