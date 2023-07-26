/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums,vector<vector<int>>& ans,int index){
        //base case
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            //backtrack
            solve(nums,ans,index+1);
             swap(nums[index],nums[j]);
        }
    }
vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(nums,ans,index);
        return ans;
        
    }

int main(){

    vector<int> arr={1,2,3};

    vector<vector<int>> ans;

    ans = permute(arr);
    for(int i=0;i<ans.size();i++){
         for(int j=0;j<ans.size();j++){
            cout<<ans[i][j];
         }
         cout<<endl;
    }

    return 0;
    
}
