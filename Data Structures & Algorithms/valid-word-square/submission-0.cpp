class Solution {
public:
    bool validWordSquare(vector<string>& words) {

        int r = words.size();
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < words[i].size(); j++) {
                if(j >= r || i >= words[j].size() || words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};