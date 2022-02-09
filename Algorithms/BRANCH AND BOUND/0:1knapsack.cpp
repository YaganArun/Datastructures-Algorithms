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

int sum(vector<int> &a)
{
    int s = 0;
    for(auto &x : a) s += x;
    return s;
}

vector<int> knapsack(int W, int n, int idx, int wt[], int val[], vector<int> &w, vector<int> &v, vector<int> &resv)
{
    if(idx >= n)
    {
        if(sum(w) <= W)
        {
            resv.pb(sum(v));
            return resv;
        }
        return resv;
    }
    w.pb(wt[idx]); // taken [1]
    v.pb(val[idx]); // taken [1]
    knapsack(W, n, idx + 1, wt, val, w, v, resv);
    w.pop_back(); // not taken [0]
    v.pop_back(); // not taken [0]
    return knapsack(W, n, idx + 1, wt, val, w, v, resv);
}

void solve() {
    int wt[] = {10, 20, 30};
    int val[] = {140, 100, 120};
    int W = 50;
    int n = sizeof(wt) / sizeof(wt[0]);
    vector<int> w, v, resv;
    vector<int> a = knapsack(W, n, 0, wt, val, w, v, resv);
    _P(" maximum value for the given knapsack is : %d \n", *max_element(a.begin(), a.end()));
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