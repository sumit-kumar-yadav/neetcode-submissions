class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++) um[nums[i]]++;
        
        int maxConscutive = 0;
        for(int i = 0; i < nums.size(); i++) {
            int conscutiveCount = 0;
            
            // Check if previous element is present
            int currNum = nums[i];
            while(um.count(currNum) > 0) {
                conscutiveCount++;
                um.erase(currNum);
                currNum--;
            }

            // Check if next element is present
            int nextElement = nums[i]+1;
            while(um.count(nextElement) > 0) {
                conscutiveCount++;
                um.erase(nextElement);
                nextElement++;
            }
            if(conscutiveCount > maxConscutive) maxConscutive = conscutiveCount;
        }
        return maxConscutive;
    }
};
