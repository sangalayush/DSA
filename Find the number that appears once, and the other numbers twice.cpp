#include <iostream>
#include<vector>
using namespace std;
//Brute-force approach
int appear_once(vector<int> &nums){
    for(int i=0;i<nums.size();i++){
        int num= nums[i];
        int cnt=0;
        for(int j=0;j<nums.size();j++){
            if(num==nums[j])
                cnt++;
        }
        if(cnt==1)
            return num;
    }
    return -1;
}
//T.C.->O(N*N)
//S.C.->O(1)


//------------------------------------------------------------------------------------------

//Better approach
int maxi=0;
int appear_once(vector<int> &nums){
    for(int i=0;i<nums.size();i++){
        maxi=max(nums[i],maxi);
    }
    vector<int> hash(maxi+1);
    for(int i=0;i<nums.size();i++){
        hash[nums[i]]++;
    }
    for(int i=0;i<hash.size();i++){
        if(hash[i]==1)
            return i;
    }
    return -1;
}
//T.C.->O(N)
//S.C.->O(N)
int main(){
    vector<int> nums={2,2,1,1,3,5,5,4,4};
    int ans= appear_once(nums);
    cout<<ans<<endl;
    return 0;
}
