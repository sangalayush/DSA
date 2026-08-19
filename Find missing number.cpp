#include <iostream>
#include<vector>
using namespace std;
// Brute-force approach
int findmissing(vector<int> &nums){
    for(int i=1;i<=nums.size()+1;i++){   //check the range from 1 to N(size of arr+1)
        int flag=0;
        for(int j=0;j<nums.size();j++){     //check with each element of array the number in the range
            if(i==nums[j]){     //if the no. is found then update flag=1 and break the loop
                flag=1;         //and continue from the the next number in the range
                break;
            }
        }
        if(flag==0){          //if number not found in the array then
            return i;       //return the number
        }
    }
    return -1;
}
//T.C.->O(n*n)
//S.C.->O(1)
//--------------------------------------------------------------------------------------------------

// Better approach
int findmissing(vector<int> &nums){
    int n=nums.size()+1;
    vector<int> hash(n+1);
    for(int i=0;i<n-1;i++){
        hash[nums[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(hash[i]==0){
            return i;
            break;
        }
    }
    return -1;
}
//T.C.->O(n+n)=O(N)
//S.C.->O(N)
//------------------------------------------------------------------------------------------------------

// Optimal approach[1]->using Sum
int findmissing(vector<int> &nums){
    int n=nums.size()+1;
    int sum= (n*(n+1))/2;
    int add=0;
    for(int i=0;i<n-1;i++){
        add+= nums[i];
    }
    return sum-add;
}
//T.C.->O(N)
//S.C.->O(1)
int main(){
    vector<int> nums={1,2,3,4};
    int ans=findmissing(nums);
    cout<<ans<<endl;
    return 0;
}
