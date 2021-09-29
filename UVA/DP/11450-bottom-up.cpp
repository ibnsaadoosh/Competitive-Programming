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
int reachable[25][205];
int p[25][25];

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
        ms(reachable, 0);
        cin >> m >> c;
        for(int ic = 0 ; ic < c ; ic++)
        {
            cin >> p[ic][0];
            for(int j = 1 ; j <= p[ic][0] ; j++)
            {
                cin >> p[ic][j];
            }
        }

        for(int i = 1 ; i <= p[0][0] ; i++)
        {
            if(m - p[0][i] >= 0)
                reachable[0][m - p[0][i]] = 1;
        }

        for(int g = 1 ; g < c ; g++)
        {
            for(int money = 1 ; money < m ; money++)
            {
                if(reachable[g-1][money])
                {
                    for(int i = 1 ; i <= p[g][0] ; i++)
                    {
                        if(money - p[g][i] >= 0)
                        {
                            reachable[g][money - p[g][i]] = 1;
                        }
                    }
                }
            }
        }

        int i;
        for (i = 0 ; i<=m && !reachable[c-1][i] ; i++);

        if (i == m + 1) cout << "no solution\n";
        else cout << m - i << endl;
    }

    return 0;
}
