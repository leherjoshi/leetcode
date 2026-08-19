#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Edge case: if t is empty or t is longer than s
        if (t.empty() || s.empty() || t.size() > s.size()) {
            return "";
        }
        
        // Create a frequency map for characters in t
        unordered_map<char, int> dictT;
        for (char c : t) {
            dictT[c]++;
        }
        
        int required = dictT.size(); // Number of unique chars in t that need to be satisfied
        int formed = 0; // Number of unique chars in current window with desired frequency
        
        // Left and right pointers
        int left = 0, right = 0;
        
        // Window frequency map
        unordered_map<char, int> windowCounts;
        
        // Result: [window length, left, right]
        int ansLen = INT_MAX;
        int ansLeft = 0, ansRight = 0;
        
        while (right < s.size()) {
            // Add character from the right to the window
            char c = s[right];
            windowCounts[c]++;
            
            // Check if frequency of current character matches desired count in t
            if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c]) {
                formed++;
            }
            
            // Try to contract the window until it's no longer valid
            while (left <= right && formed == required) {
                c = s[left];
                
                
                if (right - left + 1 < ansLen) {
                    ansLen = right - left + 1;
                    ansLeft = left;
                    ansRight = right;
                }
                
                // The character at left is no longer part of the window
                windowCounts[c]--;
                if (dictT.find(c) != dictT.end() && windowCounts[c] < dictT[c]) {
                    formed--;
                }
                
                // Move the left pointer ahead for the next iteration
                left++;
            }
            
            // Keep expanding the window by moving right pointer
            right++;
        }
        
        // Return the smallest window or empty string if no such window exists
        return (ansLen == INT_MAX) ? "" : s.substr(ansLeft, ansLen);
    }
};