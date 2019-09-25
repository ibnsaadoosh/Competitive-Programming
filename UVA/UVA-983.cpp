///a = 97  z = 122
///A = 65  Z = 90

#include <bits/stdtr1c++.h>

using namespace std;

#define endl            "\n"
#define pb              push_back
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define ll              long long
#define rep(i,n)        for(int i=0 ; i<sz(n) ; i++)
#define lp(i, n)        for(int i = 0 ; (int)i<n ; i++)
#define loop(i, x, n)   for(int i=x ; (int)i<=n ; i++)

typedef vector<int> vi;
typedef deque<int> de;
typedef map<int, int> imap;
typedef map<char, int> cmap;

const int N = 1e3 + 5;
int arr[N][N];
int res[N][N];
int n, m, rn, sum;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#else
	#endif
	int line = 0;
    while(cin >> n >> m)
    {
        if(line++) cout << endl;
        rn = n - m + 1; sum = 0;
        lp(i, n) lp(j, n) {cin >> arr[n-i-1][j];}
        lp(i,n)
        {
            lp(j, n)
            {
                if(i) arr[i][j] += arr[i-1][j];
                if(j) arr[i][j] += arr[i][j-1];
                if(i && j) arr[i][j] -= arr[i-1][j-1];
            }
        }
        lp(i,rn)
        {
            lp(j,rn)
            {
                res[i][j] = arr[i + (m-1)][j + (m-1)];
                if(i) res[i][j] -= arr[i-1][j + (m-1)];
                if(j) res[i][j] -= arr[i + (m-1)][j-1];
                if(i && j) res[i][j] += arr[i-1][j-1];
                sum += res[i][j];
            }
        }
        lp(i, rn) lp(j, rn) cout << res[rn-i-1][j] << "\n";

        cout << sum << endl;
    }
    return 0;
}
