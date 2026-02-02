class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            pq.push(i);
        }
    }

    int reserve() {
        int seat = pq.top();
        pq.pop();
        return seat;
    }

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
