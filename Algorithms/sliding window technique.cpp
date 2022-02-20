// Sliding window technique : To maximize or minimize the sum of k consecutive elements in a given array.
#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
#define deb(x) cout << #x << " = " << x << endl
#define _P(...) (void)printf(__VA_ARGS__)
#define ZERO(a) memset(a,0,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef long double ld;

int sliding_window_max(int n, int k, int a[]){
    int window_sum = 0, max = INT_MIN;
    REP(i, k) window_sum += a[i];
    if(window_sum > max) max = window_sum;
    FOR(i, 1, n - (k - 1)){
        window_sum -= a[i - 1];
        window_sum += a[i + (k - 1)];
        if(window_sum > max) max = window_sum;
    }
    return max;
}

int sliding_window_min(int n, int k, int a[]){
    int window_sum = 0, min = INT_MAX;
    REP(i, k) window_sum += a[i];
    if(window_sum < min) min = window_sum;
    FOR(i, 1, n - (k - 1)){
        window_sum -= a[i - 1];
        window_sum += a[i + (k - 1)];
        if(window_sum < min) min = window_sum;
    }
    return min;
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    REP(i, n) cin >> a[i];
    int min = sliding_window_min(n, k, a);
    int max = sliding_window_max(n, k, a);
    _P("min : %d, max : %d\n", min, max);
}
 
int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
    REP(i, TET){
        solve();
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }

    #ifdef ONPC
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}