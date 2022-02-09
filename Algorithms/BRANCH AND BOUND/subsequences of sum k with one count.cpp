// recursion pattern - 2

#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#define REP(a, b, c) for (int a = b; a < c; a++)
#define deb(x) cout << #x << " = " << x << endl
#define _P(...) (void)printf(__VA_ARGS__)
#define ZERO(a) memset(a,0,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef long double ld;

bool sum_subseq(int a[], int n, int idx, int k, int sum, vector<int> &ds)
{
    if(idx >= n)
    {
        if(sum == k)
        {
            for(auto &x : ds) _P("%d ", x);
            _P("\n");
            return true;
        }
        else return false;
    }
    sum += a[idx];
    ds.pb(a[idx]);
    if(sum_subseq(a, n, idx + 1, k, sum, ds)) return true;
    sum -= a[idx];
    ds.pop_back();
    if(sum_subseq(a, n, idx + 1, k, sum, ds)) return true;
    return false;
}
 
void solve() {
    int n, k, sum = 0;
    vector<int> res;
    cin >> n >> k;
    int a[n];
    REP(i, 0, n) cin >> a[i];
    sum_subseq(a, n, 0, k, sum, res);
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
    REP(i, 0, TET){
        solve();
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }

    #ifdef ONPC
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}