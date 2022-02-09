// recursion pattern - 3
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

int sum_subseq(int a[], int n, int idx, int k, int sum)
{
    if(idx >= n)
    {
        if(sum == k) return 1;
        else return 0;
    }
    sum += a[idx];
    int l = sum_subseq(a, n, idx + 1, k, sum);
    sum -= a[idx];
    int r = sum_subseq(a, n, idx + 1, k, sum); 
    return l + r;
}
 
void solve() {
    int n, k, sum = 0;
    cin >> n >> k;
    int a[n];
    REP(i, 0, n) cin >> a[i];
    _P("%d\n", sum_subseq(a, n, 0, k, sum));
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