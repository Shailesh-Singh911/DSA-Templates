// BFS on a graph
void BFS(int i, vector<int>& adj[], vector<int>& visited){
	queue<int> q;
	q.push(i);
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int x = q.front();
    		q.pop();
    		visited[x] = 1;
    		for(auto it : adj[x]){
    			if(!visited[it]) q.push(it);
    		}
		}
	}
}


// BFS on a grid in 4 directional movement
void BFS(){
    queue<pair<int, int>> q;
    int m = grid.size();
    int n = grid[0].size();
	int ans = 0 ;
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + row[i];
                int nc = c + col[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == 1){
                    grid[nr][nc] = 2 ;
                    q.push({nr, nc});
                }
            }
        }
        ans++;
    }
}

// for 8 directional movement
    void BFS(int i, int j, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        int m = grid.size();
        int n = grid[0].size();
    	int ans = 0 ;
        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=-1; i <= 1; i++){
                    for(int j = -1; j <= 1; j++){
                        if(i==0 && j==0) continue;
                        int nr = r + i;
                        int nc = c + j;
                        
                        if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == '1' ){
                            grid[nr][nc] = '2' ;
                            q.push({nr, nc});
                        }
                    }
                }
            }
            ans++;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                     BFS(i, j, grid);
                     cnt ++;
                }
            }
        }
        return cnt;
    }
