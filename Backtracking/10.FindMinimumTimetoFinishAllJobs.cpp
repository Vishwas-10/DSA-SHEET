int ans = INT_MAX;
vector<int>work;
void solveBackTrack(int i,int k,int n,vector<int>&jobs){
    if(i == n){
        int maxi = *max_element(work.begin(),work.end());
        ans = min(ans,maxi);
        return ;
    }

    if(*max_element(work.begin(),work.end()) >= ans)
        return;
    for(int j = 0; j < k; j++){
        if(j > 0 and work[j] >= work[j - 1])continue;
        work[j] += jobs[i];
        solveBackTrack(i+1,k,n,jobs);
        work[j] -= jobs[i];
    }
    return ;
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    sort(jobs.begin(),jobs.end(),greater<int>());
    int n = jobs.size();
    if(n == k)return jobs[0];
    work.resize(k,0);
    solveBackTrack(0,k,n,jobs);
    return ans;
}