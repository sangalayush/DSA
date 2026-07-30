#include<iostream>
#include<vector>
using namespace std;
bool checknondecreasingorder(std::vector<int> &arr)
{
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]>=arr[i-1])
        {
            
        }
        else
            return false;
    }
    return true;    
}
int main()
{
    std::vector<int> arr={1,2,3,3,3,4};
    cout<<checknondecreasingorder(arr);
    return 0;
}
