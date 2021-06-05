#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int target = 0;
    int n = nums.size();
    vector<vector<int>> ans;
    if (n < 3)
        return ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            vector<int> v;
            int sum = nums[i] + nums[j] + nums[k];

            if (sum == target)
            {
                v.push_back(nums[i]);
                v.push_back(nums[j]);
                v.push_back(nums[k]);
                ans.push_back(v);
                while (j < k and nums[j] == nums[j + 1])
                    j++;
                while (j < k and nums[k] == nums[k - 1])
                    k--;

                j++;
                k--;
            }
            if (sum < target)
                j++;
            else
                k--;
        }
        while (i < n - 2 and nums[i] == nums[i + 1])
            i++;
    }
    return ans;
}
