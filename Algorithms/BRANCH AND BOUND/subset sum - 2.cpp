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

void subset_sum(int a[], int n, int idx, vector<int> &ds, set<vector<int>> &res)
{
    if(idx >= n)
    {
        res.insert(ds);
        return;
    }
    ds.pb(a[idx]);
    subset_sum(a, n, idx + 1, ds, res);
    ds.pop_back();
    subset_sum(a, n, idx + 1, ds, res);
}

void solve() {
    int n;
    bool flag = true;
    cin >> n;
    int arr[n];
    vector<int> ds;
    set<vector<int>> res;
    REP(i, 0, n) cin >> arr[i];
    subset_sum(arr, n, 0, ds, res);
    _P("[");
    for(auto &x : res)
    {
        if(flag)
        {
            _P("[");
            REP(i, 0, x.size())
            {
                if(i == 0) _P("%d", x[i]);
                else _P(",%d", x[i]);
            }
            _P("]");
            flag = false;
        }
        else
        {
            _P(",[");
            REP(i, 0, x.size())
            {
                if(i == 0) _P("%d", x[i]);
                else _P(",%d", x[i]);
            }
            _P("]");
        }
    }
    _P("]");
    _P("\n");
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