#include <iostream>
#include<vector>
using namespace std;
//for equal no. of + & - elements
//brute-force
void rearrangeelements(vector<int> &nums){
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<0)
            neg.push_back(nums[i]);
        else
            pos.push_back(nums[i]);
    }
    for(int i=0;i<nums.size()/2;i++){
        nums[2*i]=pos[i];
        nums[2*i+1]=neg[i];
    }
}
//T.C.->O(N+N/2)
//S.C.->O(N)
int main() {
    vector<int> nums={2,3,-1,-8};
    rearrangeelements(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
//--------------------------------------------------------------------------------------------------
#include <iostream>
#include<vector>
using namespace std;
//optimal
    void rearrangeelements(vector<int> nums,vector<int> &arr){
    int posindex=0, negindex=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            arr[negindex]=nums[i];
            negindex+=2;
        }
        else
            {
                arr[posindex]= nums[i];
                posindex+=2;
            }
        
    }
}
//T.C.->O(N)
//S.C.->O(N)
int main() {
    vector<int> nums={2,3,-1,1,-8,-9};
    vector<int> arr(nums.size());
    rearrangeelements(nums,arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
//--------------------------------------------------------------------------------------
//for unequal no. of + & - elements
//i.e. if pos>neg or neg>pos
#include <iostream>
#include<vector>
using namespace std;
    void rearrangeelements(vector<int> &nums){
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }
        int p= pos.size();
        int n= neg.size();
        if(p>n){
            for(int i=0;i<n;i++){
                nums[2*i]= pos[i];
                nums[2*i+1]= neg[i];
            }
            int index= n*2;
            for(int i=n;i<p;i++){
                nums[index]= pos[i];
                index++;
            }
        }
        else{
            for(int i=0;i<p;i++){
                nums[2*i]= pos[i];
                nums[2*i+1]= neg[i];
            }
            int index= p*2;
            for(int i=p;i<n;i++){
                nums[index]= neg[i];
                index++;
            }
        }
}
//T.C.->O(N+N)=O(2N)
//S.C.->O(N)
int main() {
    vector<int> nums={1,2,3,-4,5,6,-9,-10};
    rearrangeelements(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
