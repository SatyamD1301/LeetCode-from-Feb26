class Solution {
public:
    long long solve(vector<int>& secondStart, vector<int>& secondDur,
                    vector<long long>& firstFinish) {
        int n = secondStart.size();

        vector<pair<int, int>> rides;
        for (int i = 0; i < n; i++) {
            rides.push_back({secondStart[i], secondDur[i]});
        }

        sort(rides.begin(), rides.end());

        vector<int> starts(n);
        vector<long long> prefMinDur(n);
        vector<long long> suffMinStartPlusDur(n);

        for (int i = 0; i < n; i++) {
            starts[i] = rides[i].first;

            if (i == 0)
                prefMinDur[i] = rides[i].second;
            else
                prefMinDur[i] = min(prefMinDur[i - 1],
                                    (long long)rides[i].second);
        }

        for (int i = n - 1; i >= 0; i--) {
            long long val = (long long)rides[i].first + rides[i].second;

            if (i == n - 1)
                suffMinStartPlusDur[i] = val;
            else
                suffMinStartPlusDur[i] =
                    min(suffMinStartPlusDur[i + 1], val);
        }

        long long best = LLONG_MAX;

        for (long long A : firstFinish) {
            int idx = upper_bound(starts.begin(), starts.end(), A) - starts.begin();

            long long cur = LLONG_MAX;

            // Rides already open when first ride finishes
            if (idx > 0) {
                cur = min(cur, A + prefMinDur[idx - 1]);
            }

            // Rides that open later
            if (idx < n) {
                cur = min(cur, suffMinStartPlusDur[idx]);
            }

            best = min(best, cur);
        }

        return best;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        vector<long long> landFinish, waterFinish;

        for (int i = 0; i < (int)landStartTime.size(); i++) {
            landFinish.push_back(
                (long long)landStartTime[i] + landDuration[i]);
        }

        for (int j = 0; j < (int)waterStartTime.size(); j++) {
            waterFinish.push_back(
                (long long)waterStartTime[j] + waterDuration[j]);
        }

        long long landThenWater =
            solve(waterStartTime, waterDuration, landFinish);

        long long waterThenLand =
            solve(landStartTime, landDuration, waterFinish);

        return (int)min(landThenWater, waterThenLand);
    }
};