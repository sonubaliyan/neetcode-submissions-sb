class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {

        for(auto row : shift)
        {
            int dir = row[0];
            int amount = row[1] % s.length();

            // if dir = 0 left shift
            if(dir == 0)
            {
                s = s.substr(amount) + s.substr(0, amount);
            }


            // if dir = 1 right shift
            else {
                s = s.substr(s.length() - amount) + s.substr(0, s.length() - amount);
            }
        }
        return s;
    }
};
