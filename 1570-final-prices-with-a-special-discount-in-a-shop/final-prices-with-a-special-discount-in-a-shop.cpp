class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int i=1,n=prices.size();
        stack<int> stk;
        stk.push(0);
        while(i<n){
            if(!stk.empty()&&prices[stk.top()]>=prices[i]){
                prices[stk.top()]-=prices[i];
                stk.pop();
            }else{
                stk.push(i);
                i++;
            }
        }
        return prices;
        
    }
};