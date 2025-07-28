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

int main()
{
    fastio();
    int n, m;
    cin >> n >> m;
    vi a(n+1,0);
    rep(n,i){
        int k;
        cin>>k;
        a[i+1]=k;
    }
    
    int kk[n + 1][m + 1] = {};

    for (int i = 1; i < n + 1; i++)
    {
        if (i == 1 && a[i])
        {
            kk[1][a[i]] = 1;
        }
        else if (i == 1 && !a[i])
        {
            rep(m, i)
            {
                kk[1][i + 1]++;
            }
        }
        else if (a[i])
        {
            ll sum = kk[i - 1][a[i]];
            if (a[i] > 1)
            {
                sum += kk[i - 1][a[i] - 1];
            }
            if (a[i] < m)
            {
                sum += kk[i - 1][a[i] + 1];
            }
            kk[i][a[i]] = sum % MOD;
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                ll sum = 0;
                sum += kk[i - 1][j];
                if (j > 1)
                    sum += kk[i - 1][j - 1];
                if (j < m)
                    sum += kk[i - 1][j + 1];
                kk[i][j] = sum % MOD;
            }
        }
    }
    ll sum = 0;
    for (int i = 1; i <= m; i++)
    {

        sum += kk[n][i];
    }
    
    cout << sum % MOD;
}