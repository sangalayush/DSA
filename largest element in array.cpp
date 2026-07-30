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

//Optimal approach
#include<iostream>
#include<vector>
using namespace std;
int func_large(std::vector<int> arr)
{
    int largest=arr[0];             //let the largest element be the arr[0]
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>largest)      //check through arr[0]-->arr[n-1] if the element is greater than the previous element
        {
            largest=arr[i];     //update the value of lagest with the new element
        }
    }
    return largest;
}

int main()
{
    std::vector<int> arr={5,7,3,5,8,9};
    int ans=func_large(arr);
    cout<<"largest element: "<<ans<<endl;
    return 0;
}
