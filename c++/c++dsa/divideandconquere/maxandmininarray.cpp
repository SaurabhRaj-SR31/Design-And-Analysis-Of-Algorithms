#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 

void findMinAndMax(vector<int> const &nums, int low, int high, int &min, int &max)
{

 
    if (low == high)                    // common comparison
    {
        if (max < nums[low]) {           // comparison 1
            max = nums[low];
        }
 
        if (min > nums[high]) {          // comparison 2
            min = nums[high];
        }
 
        return;
    }

 
    if (high - low == 1)                // common comparison
    {
        if (nums[low] < nums[high])       // comparison 1
        {
            if (min > nums[low]) {       // comparison 2
                min = nums[low];
            }
 
            if (max < nums[high]) {      // comparison 3
                max = nums[high];
            }
        }
        else {
            if (min > nums[high]) {      // comparison 2
                min = nums[high];
            }
 
            if (max < nums[low]) {       // comparison 3
                max = nums[low];
            }
        }
        return;
    }
 
    // find the middle element
    int mid = (low + high) / 2;
 
    // recur for the left subarray
    findMinAndMax(nums, low, mid, min, max);
 
    // recur for the right subarray
    findMinAndMax(nums, mid + 1, high, min, max);
}
 
int main()
{
        vector<int> nums;
    int n, b;
    cout << "enter no. of elements :" << endl;
    cin >> n;
    cout << "enter elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {

        cin >> b;
        nums.push_back(b);
    }
 
  
    int max = INT_MIN, min = INT_MAX;
 
 
    findMinAndMax(nums, 0, n - 1, min, max);
 
    cout << "The minimum array element is " << min << endl;
    cout << "The maximum array element is " << max << endl;
 
    return 0;
}