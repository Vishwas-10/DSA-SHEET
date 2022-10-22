int Solution::solve(vector<string> &A){
    int n = A.size();
    if (n<3){
        return false;
    }
    vector<double> v;
    for(auto x:A){
        v.push_back(stod(x));
    }
    sort(v.begin(), v.end());
    int i = 0, j = v.size()-1;
    while(abs(i-j)>=2){
        double k = v[i]+v[i+1]+v[j];
        if (k>=2){
            j--;
        }else if(k<1){
            i++;
        }else{
            return true;
        }
    }
    return false;
}
