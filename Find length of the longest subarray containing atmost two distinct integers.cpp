class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int left = 0, right = 0;
        int maxLength = 0;
        unordered_map<int, int> freq; // Stores count of elements in the window
        
        while (right < arr.size()) {
            freq[arr[right]]++; // Add current element to window
            
            // If more than 2 distinct elements exist, shrink window
            while (freq.size() > 2) {
                freq[arr[left]]--; 
                if (freq[arr[left]] == 0) 
                    freq.erase(arr[left]);
                left++; // Move left pointer
            }
            
            maxLength = max(maxLength, right - left + 1); // Update max length
            right++;
        }
        
        return maxLength;
    }
};
