class Solution {
public:
    int distinctPoints(string s, int k) {
        set<pair<int,int>> seen;

        int x = 0, y = 0;

        // Total movement
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'U') y++;
            if(s[i] == 'D') y--;
            if(s[i] == 'L') x--;
            if(s[i] == 'R') x++;
        }

        // Initially remove first k characters
        for(int i = 0; i < k; i++) {
            if(s[i] == 'U') y--;
            if(s[i] == 'D') y++;
            if(s[i] == 'L') x++;
            if(s[i] == 'R') x--;
        }

        seen.insert({x, y});

        // Slide window
        for(int i = k; i < s.size(); i++) {

            // Add new character back
            if(s[i] == 'U') y--;
            if(s[i] == 'D') y++;
            if(s[i] == 'L') x++;
            if(s[i] == 'R') x--;

            // Remove old character
            if(s[i-k] == 'U') y++;
            if(s[i-k] == 'D') y--;
            if(s[i-k] == 'L') x--;
            if(s[i-k] == 'R') x++;

            seen.insert({x, y});
        }

        return seen.size();
    }
};