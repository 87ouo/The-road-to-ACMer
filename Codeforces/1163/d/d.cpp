/* Generated by powerful Codeforces Tool
 * Author: lonelam
 * Time: 2019-05-09 23:27:33
**/

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

const int N = 1 << 10;
char c[N], s[N], t[N];
int fs[N], ft[N];
int slen, tlen;
int dp[1005][55][55];

void go(int i, char x)
{
    for (int j = 0; j < slen; ++j)
    {
        for (int k = 0; k < tlen; ++k)
        {
            if (dp[i - 1][j][k] < -1e4) continue;
            int pre = dp[i - 1][j][k], nj = j, nk = k;
            while (nj && s[nj + 1] != x) nj = fs[nj];
            if (s[nj + 1] == x) ++nj;
            if (nj == slen) ++pre, nj = fs[nj];
            while (nk && t[nk + 1] != x) nk = ft[nk];
            if (t[nk + 1] == x) ++nk;
            if (nk == tlen) --pre, nk = ft[nk];
            dp[i][nj][nk] = max(dp[i][nj][nk], pre);
        }
    }
}

void go()
{
    scanf("%s%s%s", c + 1, s + 1, t + 1);
    fs[1] = ft[1] = 0;
    for (int i = 2, j = 0; s[i]; i++)
    {
        while (j && s[i] != s[j + 1]) j = fs[j];
        if (s[i] == s[j + 1]) ++j;
        fs[i] = j;
    }
    for (int i = 2, j = 0; t[i]; i++)
    {
        while (j && t[i] != t[j + 1]) j = ft[j];
        if (t[i] == t[j + 1]) ++j;
        ft[i] = j;
    }
    memset(dp, 0xcf, sizeof(dp));
    dp[0][0][0] = 0;
    slen = strlen(s + 1);
    tlen = strlen(t + 1);
    for (int i = 1; c[i]; i++)
    {
        if (c[i] == '*')
            for (char x = 'a'; x <= 'z'; x++)
                go(i, x);
        else
            go(i, c[i]);
    }
    int ans = 0xcfcfcfcf;
    int clen = strlen(c + 1);
    for (int i = 0; i < slen; i++)
        for (int j = 0; j < tlen; j++)
            ans = max(ans, dp[clen][i][j]);
    printf("%d\n", ans);
}
