class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        long long ans = LLONG_MAX;

        // ----- Process Water rides for Land -> Water -----
        vector<pair<long long, long long>> water;
        for (int i = 0; i < m; i++) {
            water.push_back({waterStartTime[i], waterDuration[i]});
        }

        sort(water.begin(), water.end());

        vector<long long> wStart(m);
        vector<long long> prefMinDur(m);
        vector<long long> suffMinStartDur(m);

        for (int i = 0; i < m; i++) {
            wStart[i] = water[i].first;
            prefMinDur[i] = water[i].second;
            if (i)
                prefMinDur[i] = min(prefMinDur[i], prefMinDur[i - 1]);
        }

        for (int i = m - 1; i >= 0; i--) {
            long long val = water[i].first + water[i].second;
            suffMinStartDur[i] = val;
            if (i + 1 < m)
                suffMinStartDur[i] = min(suffMinStartDur[i],
                                         suffMinStartDur[i + 1]);
        }

        // Land -> Water
        for (int i = 0; i < n; i++) {
            long long finishLand =
                (long long)landStartTime[i] + landDuration[i];

            int pos =
                upper_bound(wStart.begin(), wStart.end(), finishLand) -
                wStart.begin();

            long long best = LLONG_MAX;

            if (pos > 0)
                best = min(best,
                           finishLand + prefMinDur[pos - 1]);

            if (pos < m)
                best = min(best,
                           suffMinStartDur[pos]);

            ans = min(ans, best);
        }

        // ----- Process Land rides for Water -> Land -----
        vector<pair<long long, long long>> land;
        for (int i = 0; i < n; i++) {
            land.push_back({landStartTime[i], landDuration[i]});
        }

        sort(land.begin(), land.end());

        vector<long long> lStart(n);
        vector<long long> prefMinDurLand(n);
        vector<long long> suffMinStartDurLand(n);

        for (int i = 0; i < n; i++) {
            lStart[i] = land[i].first;
            prefMinDurLand[i] = land[i].second;
            if (i)
                prefMinDurLand[i] =
                    min(prefMinDurLand[i],
                        prefMinDurLand[i - 1]);
        }

        for (int i = n - 1; i >= 0; i--) {
            long long val = land[i].first + land[i].second;
            suffMinStartDurLand[i] = val;
            if (i + 1 < n)
                suffMinStartDurLand[i] =
                    min(suffMinStartDurLand[i],
                        suffMinStartDurLand[i + 1]);
        }

        // Water -> Land
        for (int j = 0; j < m; j++) {
            long long finishWater =
                (long long)waterStartTime[j] + waterDuration[j];

            int pos =
                upper_bound(lStart.begin(), lStart.end(), finishWater) -
                lStart.begin();

            long long best = LLONG_MAX;

            if (pos > 0)
                best = min(best,
                           finishWater + prefMinDurLand[pos - 1]);

            if (pos < n)
                best = min(best,
                           suffMinStartDurLand[pos]);

            ans = min(ans, best);
        }

        return (int)ans;
    }
};