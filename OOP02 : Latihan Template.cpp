#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
T rata(T hit, T nn)
{
    T result = hit/nn;
    return (result);
}

int main()
{
    ios::sync_with_stdio(0);
    double n;
    double suma, sumb;
    cin >> n;
    int a; double b;
    suma = 0, sumb = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        suma+=a; sumb+=b;
    }
    // cout << suma << ' ' << sumb << endl;
    cout << fixed << setprecision(2) << rata(suma, n) << " " << rata(sumb, n) << endl;
}