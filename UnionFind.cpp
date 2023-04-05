class DisjointSet{
	vector<int> rank, parent; 

	vector<int> size;
public:

	// constructor
	DisjointSet(int n){
		// 1 based indexing
		rank.resize(n+1, 0);
		for(int i=0;i<=n;i++){
			parent.push_back(i);
		}

		for(int i=0;i<=n;i++){
			size.push_back(1);
		}	
	}

	int findUltimateParent(int node){
		if(parent[node] == node){
			return node;
		}
		return parent[node] = findUltimateParent(parent[node]);
		/* we are storing the result in parent[node] because we want to
		 do Path Compression */
	}

	void unionByRank(int u, int v){
		int UltimateParentOfu = findUltimateParent(u);
		int UltimateParentOfv = findUltimateParent(v);

		if(UltimateParentOfv == UltimateParentOfu) return;
		// if u and v already belong to the same component, then we
		// do not need to do anything


		if(rank[UltimateParentOfu] < rank[UltimateParentOfv]){
			parent[UltimateParentOfu] = UltimateParentOfv;
		}
		else if(rank[UltimateParentOfv] < rank[UltimateParentOfu]){
			parent[UltimateParentOfv] = UltimateParentOfu;
		}else{
			//when ranks are equal
			parent[UltimateParentOfu] = UltimateParentOfv;
			rank[UltimateParentOfv]++;
		}
	}

	void unionBySize(int u, int v){
		int UltimateParentOfu = findUltimateParent(u);
		int UltimateParentOfv = findUltimateParent(v);

		if(UltimateParentOfv == UltimateParentOfu) return;
		// if u and v already belong to the same component, then we
		// do not need to do anything


		if(size[UltimateParentOfu] < size[UltimateParentOfv]){
			parent[UltimateParentOfu] = UltimateParentOfv;
			size[UltimateParentOfv] += size[UltimateParentOfu];
		}
		else if(rank[UltimateParentOfv] < rank[UltimateParentOfu]){
			parent[UltimateParentOfv] = UltimateParentOfu;
			size[UltimateParentOfu] += size[UltimateParentOfv];
		}else{
			//when ranks are equal
			parent[UltimateParentOfu] = UltimateParentOfv;
			size[UltimateParentOfv] += size[UltimateParentOfu];
		}
		
	}
};





//short version, for use in LEETCODE
class Union{
    public:
    vector<int> parent;
    vector<int> rank;
    Union(int n){
        for(int i=0;i<n;i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int findUltimateParent(int x){
        if(x == parent[x]) return x;
        return parent[x] = findUltimateParent(parent[x]);
    }

    int unionRank(int u, int v){
        u = findUltimateParent(u);
        v = findUltimateParent(v);

        if(u == v) return 0;
        if(rank[u] < rank[v]){
            parent[u] = v;
        }else if(rank[v] < rank[u]){
            parent[v] = u;
        }else{
            parent[v] = u;
            rank[u]++;
        }
        return 1;
    }
};
