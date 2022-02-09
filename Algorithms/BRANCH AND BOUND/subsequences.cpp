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

void subseq(int idx, int a[], int n, vector<int> &st)
{
    if(idx >= n)
    {
        for(auto &x : st) _P("%d ", x);
        _P("\n");
        return;
    }
    st.pb(a[idx]);
    subseq(idx + 1, a, n, st);
    st.pop_back();
    subseq(idx + 1, a, n, st);
}

void solve() {
    int n;
    vector<int> st;
    cin >> n;
    int a[n];
    REP(i, 0, n) cin >> a[i];
    subseq(0, a, n, st);
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