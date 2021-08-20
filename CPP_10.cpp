class Solution { // given nums array find indices of numbers that add to target
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int i, j;
        i = 0;
        for (auto& it1 : nums) {
            j = 0;
            for (auto& it2 : nums) {
                if (j == i)
                    continue;
                if ((it1 + it2) == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
                j++;
                    
            }
            i++;
        }
        ret.push_back(i);
        ret.push_back(j);
        return ret;
    }
};
