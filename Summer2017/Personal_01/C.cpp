#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
ll Pow(ll a, ll n, ll m)
{
    ll t = 1;
    for (; n; n >>= 1, a = (a * a % m)) if (n & 1) t = (t * a % m);
    return t;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << Pow(n, n, 10) << endl;
    }
    return 0;
}
