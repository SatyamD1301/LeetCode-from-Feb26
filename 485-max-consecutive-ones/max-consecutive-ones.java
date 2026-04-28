class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxi=0;
        int len=0;
        for(int i=0;i<nums.length;i++){
            
            if(nums[i]==1) {
                len++;
            }
            else len=0;
            maxi=Math.max(maxi,len);

        }
        return maxi;

        
    }
}