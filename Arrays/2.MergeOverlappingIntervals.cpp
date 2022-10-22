/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval &a, Interval &b){
    return a.start<b.start;
}
vector<Interval> Solution::merge(vector<Interval> &v){
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = v.size();
    sort(v.begin(), v.end(), comp);
    int j = 0;
    for(int i=0;i<n;i++){
        int mn = v[i].start, mx = v[i].end;
        int k=i+1;
        for(k=i+1;k<n;k++){
            if (v[k].start>mx){
                k--;
                break;
            }else{
                mn = min(mn, v[k].start);
                mx = max(mx, v[k].end);
            }
        }
        i=k;
        v[j].start = mn;
        v[j].end = mx;
        j++;
    }
    v.erase(v.begin()+j,v.end());
    return v;
}
