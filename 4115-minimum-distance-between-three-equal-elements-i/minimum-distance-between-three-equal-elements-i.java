
class Solution {
    public int minimumDistance(int[] nums) {
        Map<Integer, List<Integer>> map = new HashMap<>();

        // Step 1: store indices
        for (int i = 0; i < nums.length; i++) {
            map.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }

        int ans = Integer.MAX_VALUE;

        // Step 2: check triplets for each value
        for (List<Integer> list : map.values()) {
            if (list.size() < 3) continue;

            for (int i = 0; i <= list.size() - 3; i++) {
                int a = list.get(i);
                int c = list.get(i + 2);
                ans = Math.min(ans, 2 * (c - a));
            }
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}