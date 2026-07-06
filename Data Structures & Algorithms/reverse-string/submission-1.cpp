class Solution {
public:

    vector<char> revstr(vector<char> &s)
    {
        int right = s.size()-1;
        int left = 0;
        if(right < 1)
            return s;

        while(left < right)
        {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
        return s;
    }

    void reverseString(vector<char>& s) {
        revstr(s);
    }
};