#include <iostream>
using namespace std;

// a = bq + r
// gcd(a,b) = gcd(b, r) where r = a mod b || terminal case : gcd(x,0), return here

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    else
        return gcd(b, a % b);
}

int gcd_loop(int a, int b) // using while loop
{
    while ((a % b > 0))
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    return b;
}

int main()
{
    int res = gcd(1220, 516);
    cout << res << " ";
}