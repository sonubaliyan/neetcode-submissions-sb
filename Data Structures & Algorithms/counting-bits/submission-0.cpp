class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++)
        {
            int count = 0;
            int temp = i;
            while(temp)
            {
                if(temp & 1)
                    count++;
                temp = temp >> 1;
            }
            res.push_back(count);
        }
        return res;
    }
};