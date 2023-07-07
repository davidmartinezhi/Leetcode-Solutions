class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int left = 0;
        int right = nums.size();

        while (left < right)
        {

            int m = ((right - left) / 2) + left;

            // check if found
            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
                left = m + 1;
            else
                right = m;
        }

        return -1;
    }
};