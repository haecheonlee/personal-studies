class Solution {
public:
    bool isSubsequence(string s, string t) {
        int current_index = 0;
        int to_compare_index = 0;

        bool result;
        if(s.size() > t.size()) {
            result = false;
        } else {
            result = true;
            for(int i=0; i<s.size(); i++) {
                int index = -1;
                for(int j=0; j<t.size(); j++) {
                    if(s[i] == t[j]) { index = j; break; }
                }

                if(index == -1) {
                    result = false;
                    break;
                } else {
                    t.erase(0, index + 1);
                }
            }
        }

        return result;
    }
};
