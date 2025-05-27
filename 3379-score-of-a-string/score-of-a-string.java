class Solution {
    public int scoreOfString(String s) {
        int score=0;
        //int n=s.length();
        for(int i=0;i<s.length()-1;i++){
            score+=Math.abs(s.charAt(i) - s.charAt(i+1));
        }
        return score;
        
    }
}