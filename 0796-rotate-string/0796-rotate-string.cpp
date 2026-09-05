class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        if (n != goal.size())
            return false;

        if (s == goal)
            return true;

        // Find where goal[0] occurs in s
        for (int k = 0; k < n; k++) {

            if (s[k] == goal[0]) {

                string temp = s;

                // Reverse complete string
                reverse(temp.begin(), temp.end());

                // Reverse first n-k characters
                reverse(temp.begin(), temp.begin() + (n - k));

                // Reverse last k characters
                reverse(temp.begin() + (n - k), temp.end());

                if (temp == goal)
                    return true;
            }
        }

        return false;
    }
};