class Solution {
private:
    int findReqdHoursToEatAllBananas(int minK, vector<int>& piles) {
        int minHoursReqd = 0;
        for(int i = 0; i < piles.size(); i++) 
            minHoursReqd += (piles[i] % minK == 0) ? (piles[i] / minK) : (piles[i] / minK) + 1;
        return minHoursReqd;
    }
    int binarySearch(int start, int end, vector<int>& piles, int h) {
        int k = end;
        while(start <= end) {
            int mid = end - (end - start)/2;
            int totalHourToEat = findReqdHoursToEatAllBananas(mid, piles);
            if(totalHourToEat > h) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
                k = mid;
            }
        }
        return k;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;
        for(int i = 0; i < piles.size(); i++) maxPile = max(maxPile, piles[i]);
        int maxBananaToEat = maxPile;
        int minBananaToEat = 1;

        // Now k will be in between minBananaToEat & maxBananaToEat s.t., totalTime <= h
        return binarySearch(minBananaToEat, maxBananaToEat, piles, h);
    }
};
