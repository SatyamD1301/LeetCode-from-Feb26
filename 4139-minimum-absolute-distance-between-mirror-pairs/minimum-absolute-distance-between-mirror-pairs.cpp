class Solution {
public:
    int reverseNum(int n){
        int rev = 0;
        while(n > 0){
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp; // reversed value -> latest index
        int mini = INT_MAX;

        for(int j = 0; j < nums.size(); j++){
            if(mp.find(nums[j]) != mp.end()){
                mini = min(mini, j - mp[nums[j]]);
            }

            int rev = reverseNum(nums[j]);
            mp[rev] = j;  // 🔥 always update to latest index
        }

        return (mini == INT_MAX) ? -1 : mini;
    }
};