///a = 97  z = 122
///A = 65  Z = 90

#include <bits/stdtr1c++.h>

using namespace std;

#define endl                "\n"
#define pb                  push_back
#define pii                 pair<int, int>
#define mp                  make_pair
#define x                   first
#define y                   second
#define all(v)			    ((v).begin()), ((v).end())
#define sz(v)			    ((int)((v).size()))
#define ll                  long long
#define rep(i,n)            for(int i=0 ; i<sz(n) ; i++)
#define lp(i, n)            for(int i = 0 ; (int)i<n ; i++)
#define loop(i, x, n)       for(int i=x ; (int)i<=n ; i++)
#define ms(arr, v)      memset(arr, v, sizeof arr)
typedef vector<vector<char>> vcc;
typedef vector<int> vi;
typedef deque<int> de;

int x, y;
int func(int n)
{
    if(n == 1) return 1;
    if(n % 2 == 0) return (func((n / 2)) + 1);
    if(n % 2 == 1) return (func(3*n + 1)  + 1);
}
int mx; bool _swap;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    while(cin >> x >> y)
    {
        mx = -1; _swap = false;
        if(x > y)
        {
            swap(x, y);
            _swap = true;
        }

        for(int i = x ; i <= y ; i++)
        {
            mx = max(mx, func(i));
        }
        if(_swap)
            cout << y << " " << x << " " << mx << endl;
        else
            cout << x << " " << y << " " << mx << endl;
    }
}
