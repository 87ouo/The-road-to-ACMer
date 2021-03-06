#include <bits/stdc++.h>
using namespace std;

#pragma optimize("-O3")

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

string to_string(string s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(const bool& b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename A>
string to_string(const A& v)
{
    bool first = true;
    string res = "{";
    for (const auto& x : v)
    {
        if (!first)
            res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
#else
#define debug(...) 42;
#define cerr \
    if (false) cout
#endif

template <typename T>
inline void _read(T& x)
{
    cin >> x;
}

template <typename A, typename B>
inline void _read(pair<A, B>& x)
{
    _read(x.first);
    _read(x.second);
}

template <typename T>
inline void _read(vector<T>& x)
{
    for (auto& v : x)
        _read(v);
}

void R() {}

template <typename T, typename... U>
void R(T& head, U&... tail)
{
    _read(head);
    R(tail...);
}

#define endl '\n'

template <typename T>
inline void _write(const T& x)
{
    cout << x << ' ';
}

template <typename A, typename B>
inline void _write(const pair<A, B>& x)
{
    _write(x.first);
    _write(x.second);
}

template <typename T>
inline void _write(const vector<T>& in)
{
    for (const auto& x : in)
        _write(x);
}

void W() { cout << endl; }

template <typename T, typename... U>
void W(const T& head, const U&... tail)
{
    _write(head);
    W(tail...);
}

#define my_sort_unique(c) (sort(c.begin(), c.end()), c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define X first
#define Y second

void go();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    go();
    return 0;
}

/****************************************************************************************************/

char buf[20];
const int INF = 0x3f3f3f3f;
void go()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    int N = 1 << n;
    vector<int> num(N), cnt(N), w(n);
    vector<vector<PII> > score(N, vector<PII>(N));
    vector<vector<int> > sum(N, vector<int>(N));

    for (int i = n - 1; ~i; i--) scanf("%d", &w[i]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1) cnt[i] += w[j];
    for (int i = 0; i < m; i++)
    {
        scanf("%s", buf);
        int tmp = stoi(buf, 0, 2);
        ++num[tmp];
    }
    // i 匹配 j 的分数
    int all = (1 << n) - 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            score[i][j].first = cnt[(~(i ^ j)) & all];
            score[i][j].second = num[j];
        }
        sort(score[i].begin(), score[i].end());
        sum[i][0] = score[i][0].second;
        for (int j = 1; j < N; j++) sum[i][j] = sum[i][j - 1] + score[i][j].second;
    }
    while (q--)
    {
        static int fuck;
        int ans = 0;
        scanf("%s%d", buf, &fuck);
        int tmp = stoi(buf, 0, 2);
        int pos = upper_bound(score[tmp].begin(), score[tmp].end(), make_pair(fuck, INF)) - score[tmp].begin() - 1;
        if (~pos) ans = sum[tmp][pos];
        printf("%d\n", ans);
    }
}