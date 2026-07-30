//brute force approach to find largest element in an array.. 
#include<bits/stdc++.h>
using namespace std;
int sortArr(std::vector<int> &arr)
{
    sort(arr.begin(),arr.end());    //sort the array in ascending order and then
    return arr[arr.size()-1];       //return the last element of the array, i.e. the largest one
    
}
int main()
{
    std::vector<int> arr={1,2,8,3,5};
    int largest= sortArr(arr);
    cout<<largest<<endl;
    return 0;
}
