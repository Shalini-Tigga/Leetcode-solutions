class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
    int n = moveTime.size(), m = moveTime[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    
    int dx[4] = {-1, 1, 0, 0}; // directions up, down , left , right
    int dy[4] = {0, 0, -1, 1};  
    priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
    pq.push({0,0,0});// {time, x, y}

    while(!pq.empty()) {
      auto top = pq.top();

      int time = top[0];
      int x = top[1];
      int y = top[2];
 
      pq.pop();

      moveTime[x][y] = -1;// mark the node as visited
           

      if(x == n-1 && y == m-1) { // reach the destination return time
           return time;
      }

      for(int d = 0; d < 4; d++) {// traverse in the 4 direction of each
          // adjacent node
          int n_x = x + dx[d];
          int n_y = y + dy[d];

          // check if node is valid and not visited before
          if(n_x<0 || n_y<0 || n_x>=n || n_y>=m || moveTime[n_x][n_y] == -1) {
                continue;
          }
                
          int time_n = max(moveTime[n_x][n_y], time);
          // calculate new time, in case of current time is less than the
          // time required to reach the node, then new time will be the time
          // required to reach the node

          if(dist[n_x][n_y] > time_n+1) {
               dist[n_x][n_y] = time_n+1; // maintain the time to reach the cell
               pq.push({time_n+1, n_x, n_y});// push the node to the cell
          }
      }

   }
   return dist[n-1][m-1]; //redundant as we are already returning it while 
   // processing the queue.
}
};
