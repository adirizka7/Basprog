#include <iostream>
#include <iomanip>
using namespace std;

class Person
{
private:
    string nama;
    int usia, tinggi;
    double bb;
public:
    void setPerson(string s, int u, int t, double b)
    {
        nama = s; usia = u; tinggi = t; bb = b;
    }
    string getName() const {return nama;};
    int getUsia() const {return usia;};
    int getTinggi() const {return tinggi;};
};
 
int main()
{
    ios::sync_with_stdio(0);
    int n, usia, tinggi;
    double bb;
    string nama;
    Person a[1000];
    cin >> n;
    double sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> nama >> usia >> tinggi >> bb;
        a[i].setPerson(nama, usia, tinggi, bb);
        cout << a[i].getName() << " " << a[i].getUsia() << endl;
        sum+=a[i].getTinggi();
    }
    double rata = sum/n;
    cout << fixed << setprecision(2) << rata << endl;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        double t = 1.0*a[i].getTinggi();
        if (t > rata) cnt++;
    }
    cout << cnt << endl;
}