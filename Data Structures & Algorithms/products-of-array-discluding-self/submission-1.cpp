class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len,1);

        for(int i=0; i< nums.size(); i++)
        {
            for(int j=0; j< nums.size(); j++){
                if(i ==j)
                    continue;
                res[i] *= nums[j];
            }
        }
        return res;
    }
};
