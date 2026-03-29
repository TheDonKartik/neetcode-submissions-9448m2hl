class Solution {
public:
    bool isPalindrome(string s) {
        int j = s.size() - 1;
        
        for (int i = 0; i < j + 1; i++){
            if ( i >= j) return true;

            // check s[i] is valid char
            if (!isalnum(s[i])){
                continue;
            }
            // check s[b] is valid char
            if (!isalnum(s[j])){
                // cout << s[j] << endl;
                j--;
                i--;
                continue;
            }
            // compare

            if (tolower(s[i]) != tolower(s[j])){
                cout << s[i] << " " << s[j] << endl;
                return false;
            }
            j--;
        }
        return true;
    }
};
