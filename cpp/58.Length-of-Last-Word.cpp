class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0, index = s.length()-1;
        
        while (index >= 0) {
            if (s[index] != ' ')
                result++;            
            
            if (result != 0 && s[index] == ' ')
                return result;
                
            index--;
        }

        return result;
    }
};