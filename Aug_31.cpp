class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        if (nums.size() == 3)
            return max(max(nums[0], nums[1]),nums[2]);
        nums[2] += nums[0];
        int i;
        bool i_3 = true, i_2 = false, i_1 = true, temp;
        for (i = 3; i < nums.size() - 1; i++) {
            nums[i] += max(nums[i-2], nums[i-3]);
            temp = i_1;
            if (i_3 & i_2)
                i_1 = true;
            else if (nums[i-2] > nums[i-3])
                i_1 = i_2;
            else if (nums[i-2] < nums[i-3])
                i_1 = i_3;
            else
                i_1 = false;
            i_3 = i_2;
            i_2 = temp;
        }
        // cou << 
        int prev_1 = (i_2) ? nums[i-2]-nums[0] : nums[i-2];
        int prev_2 = (i_3) ? nums[i-3]-nums[0] : nums[i-3];
        nums[i] += max(prev_1, prev_2);
        return max(nums[i-1], nums[i]);
    }
};

// 2,3,4
// 2,3,4,8,7
// true, false, true
// false, true, false
// if (last_item & true) can choose but negate zero item or choose false
// chosen_ind_bool == true then i_1 = true

// 0, 1, 15, 1, 3
//0, 1, 15, 2, 4

// 2,2,3,6, 

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        if (nums.size() == 3)
            return max(max(nums[0], nums[1]),nums[2]);
        nums[2] += nums[0];
        if (nums.size() == 4)
            return max(nums[2], nums[3] + nums[1]);
        
        int i;
        int i_3 = 0, i_2 = -1, temp, i_1;
        
        if (nums[0] > nums[1]) {
            nums[3] += nums[0];
            i_1 = 1;
        }
        else {
            nums[3] += nums[1];
            i_1 = 0;
        }

        for (i = 4; i < nums.size() - 1; i++) {
            nums[i] += max(nums[i-2], nums[i-3]);
            temp = i_1;
            if (nums[i-2] > nums[i-3])
                i_1 = i_2;
            else if (nums[i-2] < nums[i-3])
                i_1 = i_3;
            else
                i_1 = (i_3 & i_2) ? (i_3 == 1 || i_2 == 1) ? 1 : -1 : 0;
            i_3 = i_2;
            i_2 = temp;
        }
        int prev_1 = (i_2) ? nums[i-2]-nums[0] : nums[i-2];
        prev_1 += (i_2 == 1) ? nums[1] : 0;
        int prev_2 = (i_3) ? nums[i-3]-nums[0] : nums[i-3];
        prev_2 += (i_3 == 1) ? nums[1] : 0;
        // cout << prev_1 << endl;
        // cout << prev_2 << endl;
        
        nums[i] += max(prev_1, prev_2);
        
        return max(max(nums[i-1], nums[i]), nums[i-2]);
    }
};

// 2,3,4
// 2,3,4,8,7
// true, false, true
// false, true, false
// if (last_item & true) can choose but negate zero item or choose false
// chosen_ind_bool == true then i_1 = true

// 0, 1, 15, 1, 3
//0, 1, 15, 2, 4

// 2,2,3,6, 
