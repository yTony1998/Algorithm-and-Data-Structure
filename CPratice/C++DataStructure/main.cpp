#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int i = 0;
    while(i < nums.size())
    {
        if(nums[i] == target)
            break;
        i++;
    }
    if (i < nums.size())
        return i;
    else
        return -1;
}

int binarySearch(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end )
    {
        int mid = (start + end) / 2;
        if(target == nums[mid])
        {
            return mid;
        }
        else if(target > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
     
}

int binarySearchA(vector<int> &nums, int target)
{
    int start = 0;
    int end = (int)nums.size() - 1;

    while (start+1 < end)
    {
       int mid = start + (end - start) / 2;
       if(nums[mid] == target)
       {
           end = mid;
       }
       else if (nums[mid] < target)
       {
           start = mid;
       }
       else
       {
           end = mid;
       }
    }

    if(nums[start] == target) return start;
    if(nums[end] == target) return end;
    return -1;
    
}


int main(int argc, char* argv[])
{
    vector<int> arrary;

    arrary.push_back(3);
    arrary.push_back(4);
    arrary.push_back(5);
    arrary.push_back(8);
    arrary.push_back(8);
    arrary.push_back(8);
    arrary.push_back(8);
    arrary.push_back(10);
    arrary.push_back(13);
    arrary.push_back(15);

    // for(int i=0; i<arrary.size(); i++)
    //     cout<<arrary[i]<<" ";
    // cout<<endl;
    // vector<int>::iterator it;
    // for(it = arrary.begin(); it!= arrary.end(); it++)
    //     cout<<*it<<" ";
    // cout<<endl;

    cout<<search(arrary, 8)<<endl;
    // cout<<search(arrary, 80)<<endl;
    cout<<binarySearch(arrary, 8)<<endl;
    cout<<binarySearchA(arrary, 8)<<endl;
    return 0;

}