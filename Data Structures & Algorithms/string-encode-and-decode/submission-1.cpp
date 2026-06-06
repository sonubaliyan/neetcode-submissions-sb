class Solution {
public:

    string encode(vector<string>& strs) {
        string encode = "";
        for(string str : strs)
        {
            encode += to_string(str.length()) + "#" + str;
        }
        return encode;

    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        
        while (i < s.length()) {
            // 1. Find where the '#' delimiter is
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            // 2. Extract the length string and convert it back to an integer
            int length = stoi(s.substr(i, j - i));
            
            // 3. Extract the actual string using the known length
            // It starts immediately after the '#' (at index j + 1)
            string str = s.substr(j + 1, length);
            decoded.push_back(str);
            
            // 4. Move the pointer 'i' to the beginning of the next encoded block
            i = j + 1 + length;
        }
        
        return decoded;
    }
};
