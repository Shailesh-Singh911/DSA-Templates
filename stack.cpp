int n = nums.size();
vector<int> ngeR(n);
vector<int> ngeL(n);
vector<int> nseR(n);
vector<int> nseL(n);


// NGE towards the right
stack<int> st;
ngeR[n-1] = n;
st.push(n-1);
for(int i=n-2;i>=0;i--){
    while(!st.empty() && nums[st.top()] <= nums[i]){
        st.pop();
    }
    if(st.empty()) ngeR[i] = n;
    else ngeR[i] = st.top();
    st.push(i);
}

while(!st.empty()) st.pop();
// NGE towards the left
ngeL[0] = -1;
st.push(0);

for(int i=1;i<n;i++){
    while(!st.empty() && nums[st.top()] < nums[i]){
        st.pop();
    }
    if(st.empty()) ngeL[i] = -1;
    else ngeL[i] = st.top();
    st.push(i);
}


while(!st.empty()) st.pop();

//NSE towards the right
nseR[n-1] = n;
st.push(n-1);
for(int i=n-2;i>=0;i--){
    while(!st.empty() && nums[st.top()] > nums[i]){
        st.pop();
    }
    if(st.empty()) nseR[i] = n;
    else nseR[i] = st.top();
    st.push(i);
}

while(!st.empty()) st.pop();

//NSE towards the left
nseL[0] = -1;
st.push(0);
for(int i=1;i<n;i++){
    while(!st.empty() &&  nums[st.top()] >= nums[i]){
        st.pop();
    }
    if(st.empty()) nseL[i] = -1;
    else nseL[i] = st.top();
    st.push(i);
}
