class TopVotedCandidate {
    vector<int> times;
    vector<int> leaders;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        
        unordered_map<int, int> count;
        int leader = -1;
        int maxVotes = 0;

        for (int i = 0; i < persons.size(); i++) {
            count[persons[i]]++;

           
            if (count[persons[i]] >= maxVotes) {
                leader = persons[i];
                maxVotes = count[persons[i]];
            }
            leaders.push_back(leader);
        }
    }

   int q(int t) {
    int l = 0, r = times.size() - 1;
    int ans = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (times[mid] <= t) {
            ans = mid;       
            l = mid + 1;     
        } else {
            r = mid - 1;
        }
    }
    return leaders[ans];
}

};
