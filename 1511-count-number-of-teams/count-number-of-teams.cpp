class Solution {
public:
    int numTeams(vector<int>& rating) {
        int total=0;
        int n=rating.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if((rating[i]<rating[j]&&rating[j]<rating[k]) || (rating[i]>rating[j]&&rating[j]>rating[k]))
                    total++;
                }
            }
        }
        return total;
        
    }
};