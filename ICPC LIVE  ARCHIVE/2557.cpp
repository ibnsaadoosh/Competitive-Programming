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

const int N = 1e2 + 5;
int arr[N];
int q, n, ctr;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#else
//	#endif
    cin >> q;
    lp(i, q)
    {
        ctr = 0;
        memset(arr, 0, sizeof arr);
        cin >> n;
        loop(i, 1, n)
        {
            for(int j = i ; j<=n ; j+=i)
            {
                arr[j] ^= 1;
            }
        }
        loop(i, 1, n) ctr += arr[i];
        cout << ctr << endl;
    }
    return 0;
}
