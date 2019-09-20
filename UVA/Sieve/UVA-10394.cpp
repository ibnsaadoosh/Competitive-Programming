#include <bits/stdtr1c++.h>

using namespace std;

#define endl            "\n"
#define pb              push_back
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define ll              long long
#define ld              long double
#define rep(i,n)        for(int i=0 ; i<sz(n) ; i++)
#define lp(i, n)        for(int i = 0 ; (int)i<n ; i++)
#define loop(i, x, n)   for(int i=x ; (int)i<=n ; i++)

typedef vector<int> vi;
typedef deque<int> de;
typedef map<int, int> imap;
typedef map<char, int> cmap;

const double PI = 3.14159265358979323846;
const double EPSILON = 1e-9;
const ll INF = 1e15;
const int MOD = 1e9 + 7;

const int MAX =20000007;
bitset<MAX> bs;
ll sieve_size;
vector<ll> primes;

void sieve(ll upperbound)
{
    sieve_size = upperbound + 1;
    bs.set();
    for(ll i = 2 ; i <= sieve_size ; i++)
    {
        if(bs[i])
        {
            for(ll j = i*i ; j <= sieve_size ; j += i) bs[j] = 0;
            primes.pb(i);
        }
    }
}

ll n;
vector<pair<ll, ll>> pr;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#else
	#endif
    sieve(20000000);
    for(int i = 0 ; i<sz(primes) - 1; i++)
    {
        if(primes[i] == primes[i+1] - 2)
        {
            pr.pb(make_pair(primes[i], primes[i+1]));
        }
    }
    while(cin >> n)
    {
        n--;
        cout << '(' << pr[n].first << ", " << pr[n].second << ')' << endl;
    }

    return 0;
}

