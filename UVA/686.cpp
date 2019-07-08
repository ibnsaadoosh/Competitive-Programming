///notes : Prime Numbers.

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>   ///for funtion<>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define ll              long long
#define ld              long double
#define rep(i,n)       for(int i=0 ; i<n ; ++i)
#define loop(i, x, n)   for(int i=x ; i<=n ; ++i)

typedef vector<int> vi;
typedef deque<int> de;
typedef map<int, int> imap;
typedef map<char, int> cmap;
typedef map<string, int> strmap;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int _sieve_size;
bitset<32770> bs;
bitset<32770> bs2;
vi primes;

void sieve(int upperBound)
{
    _sieve_size = upperBound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2 ; i<= _sieve_size ; i++)
    {
        if(bs[i])
        {
            for(ll j = i*i ; j<= _sieve_size ; j += i) bs[j] = 0;
            primes.push_back(int(i));
        }
    }
}

int main()
{
    fast();
    sieve(32770);
    int n, temp, ctr;
    while(cin >> n)
    {
        temp = 0, ctr= 0; bs2.set();
        if(n == 0) break;
        for(int i = 0; primes[i] < n; i++)
        {
            temp = n - primes[i];
            if(bs[temp] && bs2[temp])
            {
                ctr++;
                bs2[primes[i]] = 0;
            }
        }
        cout << ctr << endl;
    }

    return 0;
}
