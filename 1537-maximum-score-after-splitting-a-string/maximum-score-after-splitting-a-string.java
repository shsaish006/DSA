class Solution {
    public int maxScore(String s) {
        int len=s.length();
        int ones=0;
        for(int i=0;i<len;i++){
            if(s.charAt(i)=='1'){
                ones++;
            }
        }
        int zeros=0;
        int ms=0;
        for(int i=0;i<len-1;i++){
            if(s.charAt(i)=='0'){
                zeros++;
            }else{
                ones--;
            }
            ms=Math.max(ms,zeros+ones);
        }
        return ms;
        
    }
}