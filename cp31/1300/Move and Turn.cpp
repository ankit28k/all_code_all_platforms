#include<bits/stdc++.h>
using namespace std; 

int main(){ 

    int n;
    cin>>n;

    // let k be no. of step ...in a axis....=> k+1 is no. of places it can travel....ex = k=1 -> 2 places (0,1) and (0,-1) in y axis .... and
    //-> 2 places (1,0) and (-1,0) in x axis

    long long ans=0;
    if(n%2 == 0){ //n/2 in x and n/2 in y...=> n/2 + 1 in x and n/2 + 1 in y...=> (n/2 + 1)^2
        ans = (n/2 + 1) * (n/2 + 1);
    }
    
    else{ //n/2 + 1 in x and n/2 + 2 in y or vice versa...as total 2K + 1 ...=>  2*((n/2 + 1) * (n/2 + 2))
        ans = 2*((n/2 + 1) * (n/2 + 2));

    }

    cout<<ans<<endl;
//     // Time Complexity: O(n^3 * log n)
//     // Space Complexity: O(n^3)
//     // Explanation: At any step 'k', there are O(k^2) distinct valid states. 
//     // Summing O(k^2) across all levels from 1 to n gives O(n^3) total states 
//     // stored in the queue and set. The set insertion adds an O(log n) time factor.
//     vector<pair<int,int>> movy = {{0,-1},{0,1}};
//     vector<pair<int,int>> movx = {{1,0},{-1,0}};

//     set<pair<int,int>> ans;
    

//     // {x,y} , {prev,level} -> 0 for x direction and 1 for y direction movement....
//     queue< pair< pair<int,int> , pair<int,int> > > q; 

//    // Track { {x, y}, {direction, step} } because the robot can cross the same point at different steps.
//     // Example: For n=4, a valid path is (0,0) -> North(0,1) -> East(1,1) -> South(1,0) -> West(0,0).
//     // If we only track {x, y}, the point (1,0) is marked visited at step 1, wrongly blocking this path at step 3!
//     set<pair< pair<int,int> , pair<int,int> > > vis;

//     q.push({{0,1} , {1,1}});
//     q.push({{0,-1} , {1,1}});
//     q.push({{1,0} , {0,1}});
//     q.push({{-1,0} , {0,1}});
    
     
//     vis.insert({{0,1} , {1,1}});
//     vis.insert({{0,-1} , {1,1}});
//     vis.insert({{1,0} , {0,1}});
//     vis.insert({{-1,0} , {0,1}});
//     //vis.insert({0,0});


//     while(!q.empty() && q.front().second.second <= n){

//         auto node = q.front();
//         q.pop();

//         int prev = node.second.first;
//         int level = node.second.second;
//         int x = node.first.first , y = node.first.second;

//         if(level == n) ans.insert({x,y});
                

//         if(prev){ //in y direction

//             for(auto mov : movx){
//                 int childx = x + mov.first;
//                 int childy = y + mov.second; 

//                 if(vis.find({{childx,childy},{0,level+1}}) == vis.end()) {
//                     vis.insert({{childx,childy},{0,level+1}});
//                     q.push({{childx,childy},{0,level+1}});
//                 }
                
//             }

//         }
//         else{

//             for(auto mov : movy){
//                 int childx = x + mov.first;
//                 int childy = y + mov.second; 

//                 if(vis.find({{childx,childy},{1,level+1}}) == vis.end()) {
//                     vis.insert({{childx,childy},{1,level+1}});
//                     q.push({{childx,childy},{1,level+1}});
//                 }
                
                
//             }
//         }
//     }

//     cout<<ans.size()<<endl;
    

}