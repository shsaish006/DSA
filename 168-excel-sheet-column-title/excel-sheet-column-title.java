class Solution {
    public String convertToTitle(int columnNumber) {
        int n = columnNumber;
        StringBuilder sb = new StringBuilder();
        while(n != 0){
            n--;
            int rem = n % 26;
            char ch = (char) ('A' + rem);
            sb.append(ch);
            n/= 26;
        }
        return sb.reverse().toString();
    }
}