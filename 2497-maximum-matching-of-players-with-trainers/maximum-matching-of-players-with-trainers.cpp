class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = players.size() - 1;
        int j = trainers.size() - 1;
        int count = 0;

        while (i >= 0 && j >= 0) {
            if (trainers[j] >= players[i]) {
               
                count++;
                j--;
                i--;
            } else {
                
                i--;
            }
        }

        return count;
    }
};
