class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> dict;
        int count, ret;
        count = 0;
        ret = 0;
        int start_in = 0;
        bool z_ind = true;
        for (int i = 0; i < s.length(); i++) {
            cout << "val: " << s[i] << endl;
            if ((dict[s[i]] != 0) || (z_ind && (s[0] == s[i]) && (i != 0))) {
                if (dict[s[i]] < start_in) {
                    dict[s[i]] = 0;
                    dict[s[i]] = i;
                    cout << "1" << endl;
                    count++;
                }
                else if (z_ind && (s[0] == s[i]) && (i != 0)) {
                    if (count > ret)
                        ret = count;
                    count = i - dict[s[i]];
                    start_in = dict[s[i]] + 1;
                    dict[s[i]] = i;
                    z_ind = false;
                    cout << "yes" << endl;
                }
                else {
                    if (count > ret)
                        ret = count;
                    count = i - dict[s[i]];
                    start_in = dict[s[i]] + 1;
                    dict[s[i]] = i;
                    // cout << "2" << endl;
                }
            }
            else {
                dict[s[i]] = i;
                count++;
                cout << count << endl;
                // cout << "Store: " << dict[s[i]] << endl;
            }
        }
        if (count > ret) {
            ret = count;
            // cout << "4" << endl;
        }  
        return ret;
    }
};
