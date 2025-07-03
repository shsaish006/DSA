class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + findK(k - 1); 
    }

    int findK(int k) {
        if (k == 0) return 0;

        
        int len = 1;
        while ((1 << len) <= k) len++;

        int offset = 1 << (len - 1);
        return (findK(k - offset) + 1) % 26;
    }
};
