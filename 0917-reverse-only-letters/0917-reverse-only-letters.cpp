
class Solution {
public:
    bool isalpha(char s) {
        if ((s >= 'A' && s <= 'Z') ||
            (s >= 'a' && s <= 'z')) {
            return true;
        }
        return false;
    }

    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (isalpha(s[left]) && isalpha(s[right])) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if (!isalpha(s[left])) {
                left++;
            }
            else {
                right--;
            }
        }

        return s;
    }
};