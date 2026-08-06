#include<iostream>
#include<vector>
using namespace std;
//Brute-force approach
void leftrotatebyk(vector<int> &arr, int k)
{
    k=k%arr.size();
    vector<int> temp(k);  //a temp array which will store first k elemnts
    for(int i=0;i<k;i++)
    {
        temp[i]=arr[i];
    }
    //left-shift n-k elements by k places
    for(int i=k;i<arr.size();i++)
    {
        arr[i-k]=arr[i];
    }
    //push back temp array at last of original array
    for(int i=arr.size()-k;i<arr.size();i++)
    {
        arr[i]=temp[i-arr.size()+k];
    }
}
//T.C--> O(k)+O(n-k)+O(k)-->bcz..storing k elemnts back
//total-->O(n+k)
//S.C.-->O(k)
int main()
{
    vector<int> arr={1,2,3,4,5,6,7};
    int k=3;
    leftrotatebyk(arr,k);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
