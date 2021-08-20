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

class Solution { // map holds number to count and each time adding to map or removing from map as needed
public:
    int maxOperations(vector<int>& nums, int k) { // map better solution than parsing through back to back for loops O(N^2)
        
        unordered_map<int,int>track;    // track number occuerence count
        
        int c = 0;  // count sum pairs
        for(auto &t : nums)
        {
            if(track[k-t]>0)    // complement of t exists and so increment count c
            {
                track[k-t]--;   // decrement complement item count in Map 
                c++;
            }   
            else track[t]++;    // no complement found and so increase item t count in Map
        }
        
        return c;
    }
};
