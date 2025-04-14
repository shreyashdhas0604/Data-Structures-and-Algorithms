#include <bits/stdc++.h>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>>ans;
    int n = intervals.size();
    if(n==1) return {intervals[0]};
    sort(intervals.begin(),intervals.end());
    ans.push_back(intervals[0]);
    for(int i =1;i<n;i++){
        int ele1 = intervals[i][0],ele2 = intervals[i][1];
        int &first = ans.back()[0], &last = ans.back()[1];
        if(last >= ele1){
            last = max(last,ele2);
        }
        else{
            ans.push_back({ele1,ele2});
        }
    }

    return ans;
}
