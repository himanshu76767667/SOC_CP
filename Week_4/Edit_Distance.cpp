#include <bits/stdc++.h>
using namespace std;

#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define rep(x, i) for (int i = 0; i < (x); ++i)
#define in(x) for (auto &i : x)
#define chmin(a, b) (a = min((a), (b)))
#define chmax(a, b) (a = max((a), (b)))
#define vsort(v) sort(all(v))
#define print(x)          \
    for (auto i : x)      \
        cout << i << " "; \
    cout << endl;
#define take(x)                 \
    for (int i = 0; i < n; ++i) \
        cin >> x[i];
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endlc '\n'
#define lb lower_bound
#define ub upper_bound
#define uniq(v) v.erase(unique(all(v)), v.end())

const int INF = 1e9 + 5;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
string s1, s2;
int cost(int a, int b)
{
    if (s1[a] == s2[b])
    {
        return 0;
    }
    else
        return 1;
}

int main()
{
    fastio();

    cin >> s1 >> s2;
    int l1 = s1.length();
    int l2 = s2.length();

    int aa[l1 + 1][l2 + 1] = {};
    for (int i = 0; i <= l1; ++i)
        aa[i][0] = i;
    for (int j = 0; j <= l2; ++j)
        aa[0][j] = j;

    rep(l1, i)
    {
        rep(l2, j)
        {
            aa[i + 1][j + 1] = min({aa[i][j + 1] + 1, aa[i + 1][j] + 1, aa[i][j] + cost(i, j)});
        }
    }
    cout << aa[l1][l2];

    return 0;
}