#include<iostream>
#include<vector>
#include<set>
using namespace std;
//brute-force approach
void unionoftwo(vector<int> &nums1, vector<int> &nums2, vector<int> &result){
    set<int> st;
    for(int i=0;i<nums1.size();i++){
        st.insert(nums1[i]);
    }
  //T.C.->O(n1logn)
    for(int i=0;i<nums2.size();i++){
        st.insert(nums2[i]);
    }
  //T.C.->O(n2logn)
    for(auto it:st){
        result.push_back(it);
    }
  //T.C.->O(n1+n2)->bcz if all the elemnts in nums1 and nums2 were unique so all of them would have been there in the st..
}
//total T.C.->O(n1logn+n2logN)+O(n1+n2)
//S.C.->O(n1+n2)+o(n1+n2)
int main(){
    vector<int> nums1={1,1,2,3,4};
    vector<int> nums2={1,5,6,7,7};
    vector<int> result;
    unionoftwo(nums1,nums2,result);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
