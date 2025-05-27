class Solution {
public:
    bool areConsecutive(char c1, char c2) {
        int diff = abs(c1 - c2);
        return (diff == 1 || diff == 25);
    }

    string resultingString(string s) {
        vector<char> res_stack;

        for (char current_char : s) {
            if (!res_stack.empty() && areConsecutive(res_stack.back(), current_char)) {
                res_stack.pop_back();
            } else {
                res_stack.push_back(current_char);
            }
        }

        return string(res_stack.begin(), res_stack.end());
    }
};