class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length==0) return 0;
        Set<Integer> set= new HashSet<>();
        for(int ele: nums) set.add(ele);
        int cnt=1,max=1;
        for(int ele:nums){
          if(set.contains(ele+1) || set.contains(ele-1)){
            int nxt=ele;
            int prev=ele;
            while(true){
                if(set.contains(nxt+1)){
                   cnt++;
                   set.remove(nxt);
                   nxt++;
                }
                else if(set.contains(prev-1)){
                    cnt++;
                    set.remove(prev);
                    prev--;
                }
                else break;
            }
          }
          max=Math.max(cnt,max);
          cnt=1;
        }
        return max;
    }
}
