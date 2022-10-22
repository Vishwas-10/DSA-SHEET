vector<int> Solution::nextPermutation(vector<int> &v){
    int n = v.size();
    if (n<=1){
        return v;
    }
    int i = n-1;
    while(i>0 && v[i]<v[i-1]){
        i--;
    }
    // cout<<i<<", ";
    if (i==0){
        sort(v.begin(), v.end());
        return v;
    }
    int j = n-1;
    for(j=n-1;j>i;j--){
        if (v[j]>v[i-1]){
            break;
        }
    }
    swap(v[i-1], v[j]);
    reverse(v.begin()+i,v.end());
    return v;
}
