///a = 97  z = 122
///A = 65  Z = 90

#include <bits/stdtr1c++.h>

using namespace std;

#define endl                "\n"
#define pb                  push_back
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define mp                  make_pair
#define x                   first
#define y                   second
#define all(v)                ((v).begin()), ((v).end())
#define sz(v)                ((int)((v).size()))
#define ll                  long long
#define rep(i, n)            for(int i=0 ; i<sz(n) ; i++)
#define repit(it, m)        for(it = m.begin(); it!=m.end(); it++)
#define reprit(it, m)       for(it = rbegin(); it!=rend() ; it++)
#define lp(i, n)            for(int i = 0 ; (int)i<n ; i++)
#define loop(i, x, n)       for(int i=x ; (int)i<=n ; i++)
#define ms(arr, v)          memset(arr, v, sizeof arr)

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))

int n, m, c, res;
int memo[205][25];
int p[25][25];

int solve(int money, int g)
{
    if(money < 0)   return -1;
    if(g == c) return m - money;

    if(memo[money][g] >= 0) return memo[money][g];
    int ans = -1;
    loop(i, 1, p[g][0])
        ans = max(ans, solve(money - p[g][i], g+1));
    return memo[money][g] =  ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

    cin >> n;
    while (n--)
    {
        res = -1;
        ms(memo, -1);
        cin >> m >> c;
        for(int ic = 0 ; ic < c ; ic++)
        {
            cin >> p[ic][0];
            for(int j = 1 ; j <= p[ic][0] ; j++)
            {
                cin >> p[ic][j];
            }
        }
        res = solve(m, 0);

        if (res < 0) cout << "no solution\n";
        else cout << res << endl;
    }

    return 0;
}
