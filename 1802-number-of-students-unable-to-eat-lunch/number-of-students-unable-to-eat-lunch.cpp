class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        int i=0;
        int count=0;
        while(i<sandwiches.size()){
            if(q.front()==sandwiches[i]){
                q.pop();
                count=0;
                i++;
            }else{
                q.push(q.front());
                q.pop();
                count++;
                if(count==q.size())
                break;
            }
        }
        if(i==sandwiches.size()) return 0;
        else return q.size();
        
    }
};