///gcd
int gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b ); }


///fining all dividors of a number g
vector<int> dividors;
for(int i = 1 ; i <= g/i ; i++)
    {
        if(g%i == 0)
        {
            dividors.push_back(i);
            if(g/i != i) dividors.push_back(g/i);;
        }
    }
