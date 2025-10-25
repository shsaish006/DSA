class Solution {
public:
    int totalMoney(int n) {
        int fullWeeks = n / 7, remainingDays = n % 7, total = 0;
        for (int i = 0; i < fullWeeks; i++) {
            total += 7 * (i + 1) + 21; 
        }
        for (int i = 0; i < remainingDays; i++) {
            total += fullWeeks + 1 + i;
        }
        return total;
    }};