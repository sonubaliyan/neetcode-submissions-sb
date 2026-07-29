class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        for(int i =0; i< arr.size(); i++)
        {
            int melem = INT_MIN;
            for(int j =i+1; j < arr.size(); j++)
            {
                melem = max(melem, arr[j]);
            }
            arr[i] = melem;
        }
        int last = arr.size()-1;
        arr[last] = -1;
        return arr;
        
    }
};