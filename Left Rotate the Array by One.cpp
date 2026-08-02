#include<iostream>
#include<vector>
using namespace std;
void leftrotate(std::vector<int> &arr)
{
    int temp=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        arr[i-1]=arr[i];
    }
    arr[arr.size()-1]=temp;
}
int main()
{
    std::vector<int> arr={1,2,3,4,5}; 
    leftrotate(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
