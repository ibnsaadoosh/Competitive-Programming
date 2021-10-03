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

int b, n;

const int MAX = 2e4 + 5;
int arr[MAX];

int main()
{
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

    cin >> b;

    loop(j, 1, b)
    {
        cin >> n; n--;
        lp(i, n) cin >> arr[i];


        int localMax = 0, start = 0, endI = 0, tempSt = 0;
        int globalMax = INT32_MIN;

        for(int i = 0 ; i < n ; i++)
        {
            if(arr[i] > arr[i] + localMax)
            {
                tempSt = i;
                localMax = arr[i];
            }
            else
            {
                localMax = arr[i] + localMax;
            }
            if(localMax > globalMax || (localMax == globalMax && (endI-start < i-tempSt)))
            {
                start = tempSt;
                endI = i;
                globalMax = localMax;
            }
        }
        if(globalMax <= 0) cout << "Route " << j << " has no nice parts\n";
        else cout << "The nicest part of route " << j << " is between stops " <<  start+1 << " and " << endI+2 << endl;
    }
    return 0;
}
