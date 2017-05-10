#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    double a, b, c;
    cin >> a >> b;
    c = a+b;
    cout << fixed << setprecision(2) << c << endl;
}