class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            vector<vector < int>> ans;
            if (nums.empty()) return ans;
            sort(nums.begin(), nums.end());
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                long long int target2 = target - nums[i];
                for (int j = i + 1; j < n; j++)
                {
                    long long int rem = target2 - nums[j];
                    int left = j + 1;
                    int right = n - 1;
                    while (left < right)
                    {
                        long long int two_sum = nums[left] + nums[right];
                        if (two_sum < rem) left++;
                        else if (two_sum > rem) right--;
                        else
                        {
                            vector<int> temp(4, 0);
                            temp[0] = nums[i];
                            temp[1] = nums[j];
                            temp[2] = nums[left];
                            temp[3] = nums[right];
                            ans.push_back(temp);
                            while (left < right && nums[left] == temp[2]) left++;
                            while (left < right && nums[right] == temp[3]) right--;
                        }
                    }
                    while (j < n - 1 && nums[j] == nums[j + 1]) j++;
                    while (i < n - 1 && nums[i] == nums[i + 1]) i++;
                }
            }
            return ans;
        }
};