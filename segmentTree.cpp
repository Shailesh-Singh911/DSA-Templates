class SegmentTree{
	private:
		vector<int> seg;
	public:
		SegmentTree(int n){
			seg.resize(4*n);
		}

		void buildTree(int ind, int low, int high, int[] arr){
			if(low == high) {
				seg[ind] = arr[low];
				return;
			}

			int mid = (low + high)/2;
			// 0 based Indexing
			buildTree(2*ind + 1, low, mid);
			buildTree(2*ind + 2, mid+1, high);

			seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]);
		}

		int query(int ind, int low, int high, int l, int r){

			//complete overlap
			if(low >= l && high <= r){
				return seg[ind];
			}

			//no overlap
			if(high < l || low > r){
				return INT_MAX;
			}

			// partial overlap
			int mid = (low + high) >> 1;
			int left = query(2*ind + 1, low, mid, l, r);
			int right = query(2*ind + 2, mid + 1, high, l, r);
			return min(left, right);
		}

		void update(int ind, int low, int high, int i, int val){
			if(low == high){
				seg[low] = val;
				return; 
			}

			int mid = (low + high)/2;
			if(i <= mid){
				update(2*ind + 1, low, mid, i, val);
			}else{
				update(2*ind + 2, mid + 1, high, i, val);
			}
			seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]);
		} 
};



int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}


	SegmentTree sg(n);
	seg.buildTree(0, 0, n-1, arr);

	int l, r;
	cin >> l >> r;
	sg.query(0, 0, n-1, l, r);

	int i, val;
	cin >> i >> val;
	sg.update(0, 0, n-1, i, val);
	return 0;
}
