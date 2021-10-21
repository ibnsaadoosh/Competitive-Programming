///a = 97  z = 122
///A = 65  Z = 90
///ctrl + y  del cur line

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

int n, temp, maxSum, sum;

const int MAX = 130;
int arr[MAX][MAX];


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

    cin >> n;

    lp(i, n)
    {
        lp(j, n)
        {
             cin >> arr[i][j];
             if(i > 0) arr[i][j] += arr[i-1][j];
             if(j > 0) arr[i][j] += arr[i][j-1];
             if(i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
        }
    }

    lp(i, n) lp(j, n) loop(k, i, n-1) loop(l, j, n-1)
                {
                    sum = arr[k][l];
                    if(i>0) sum -= arr[i-1][l];
                    if(j>0) sum -= arr[k][j-1];
                    if(i>0 && j>0) sum += arr[i-1][j-1];

                    maxSum = max(maxSum, sum);
                }
    cout << maxSum << endl;
    return 0;
}
