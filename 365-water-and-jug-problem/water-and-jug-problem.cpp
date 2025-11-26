class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z > x + y) return false;
        if(z == 0) return true;
        return z % std::__gcd(x, y) == 0;
    }
};
