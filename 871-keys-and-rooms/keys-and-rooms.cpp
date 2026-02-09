// class Solution {
// public:
//     vector<int> &vis;
//     void DFS(int src,vis){
//         for(auto edge:rooms){
//             if(vid[edge]==1) continue;
//             else{
//                 vis[edge]=1;
//                 DFS(edge,vis);
//             }
//         }
//     }

//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         for(int i=0;i<vis.size();i++){
//             if(vis[i]==false){
//                 return false;
//             }
//         }
//         return true;
//     }
// };
class Solution {
public:
    void DFS(int src, vector<vector<int>>& rooms, vector<bool>& vis) {
        vis[src] = true;

        for (int key : rooms[src]) {
            if (!vis[key]) {
                DFS(key, rooms, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);

        DFS(0, rooms, vis);  // room 0 se start

        for (int i = 0; i < n; i++) {
            if (!vis[i]) return false;
        }
        return true;
    }
};
