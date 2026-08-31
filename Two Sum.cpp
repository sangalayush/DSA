#include <iostream>
#include<vector>
using namespace std;
//Brute-force approach
vector<int> twosum(vector<int> &nums, int target){
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target)
                return {i,j};
                //Or we can return YES
        }
    }
    return {-1,-1};
    //Or we can return NO
}
//T.C.->O(N*N)
//.S.C.->O(1)
//--------------------------------------------------------------------------------------------------------
#include<unordered_map>
using namespace std;
//Better approach
vector<int> twosum(vector<int> &nums, int target){
    unordered_map<int,int> mpp;       // T.c. of unordered_map is O(1) in best & avg.case
                                    //  T.C. of a ordered map is always logN
    for(int i=0;i<nums.size();i++){
        int curr= nums[i];
        int more= target-curr;
        if(mpp.find(more) != mpp.end()){
            return {mpp[more],i};
            //or return "yes"
        }
        mpp[curr]=i;
    }
    return {-1,-1};
    //or return "No"
}
//T.C.->O(N)
//.S.C.->O(N)
//--------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
//Optimal approach
//Case-I where we only need to tell that is the target present or not
string twosum(vector<int> &nums, int target){
    int left=0, right=nums.size()-1;
    sort(nums.begin(),nums.end());
    while(left<right){
        int sum= nums[left]+nums[right];
        if(sum== target)    return "YES";
        else if(sum<target) left++;
        else    right--;
    }
    return "NO";
}
//T.C.->O(N*logN)
//.S.C.->O(1)

int main(){
    vector<int> nums={2,4,1,4,5,8,10};
    int target= 20;
    string ans= twosum(nums,target);
    cout<<ans<<endl;
    return 0;
}
//------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
//Optimal approach
//Case-II where we need to tell the indexes of the target sum values.
vector<int> twosum(vector<int> &nums, int target){
    vector<pair<int,int>> numbers;
    for(int i=0;i<nums.size();i++){
        numbers.push_back({nums[i],i});
    }
    int left=0, right=numbers.size()-1;
    sort(numbers.begin(),numbers.end());
    while(left<right){
        int sum= numbers[left].first + numbers[right].first;
        if(sum== target)    return {numbers[left].second, numbers[right].second};
        else if(sum<target) left++;
        else    right--;
    }
    return {-1,-1};
}
//T.C.->O(N+N*logN)
//.S.C.->O(N)

int main(){
    vector<int> nums={2,4,1,4,5,8,10};
    int target= 12;
    vector<int> ans= twosum(nums,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
