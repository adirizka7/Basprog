#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
  
class polygon {
protected:
    int nEdge;
    vector <double> x, y, total;
public:
    void set(double xt, double yt)
    {
        x.push_back(xt);
        y.push_back(yt);
    }
    void keliling()
    {
        for(unsigned int i=0;i<x.size()-1;i++)
        {
            double ex = (x[i]-x[i+1])*(x[i]-x[i+1]);
            double ye = (y[i]-y[i+1])*(y[i]-y[i+1]);
            double d = sqrt(ex+ye);
            total.push_back(d);
        }
        double ex = (x[0]-x[x.size()-1])*(x[0]-x[x.size()-1]);
        double ye = (y[0]-y[x.size()-1])*(y[0]-y[x.size()-1]);
        double d = sqrt(ex+ye);
        total.push_back(d);//cout << d << endl;
    }
    double getTotal()
    {
        return accumulate(total.begin(), total.end(), 0.0);
    }
    double getxAwal()
    {
        return x[0];
    }
    double getxAkhir()
    {
        return x[x.size()-1];
    }
    double getyAwal()
    {
        return y[0];
    }
    double getyAkhir()
    {
        return y[x.size()-1];
    }
};
 
class segitiga: public polygon {
private:
    double rata2, ratak;
    vector <double> keliling, luas;
public:
    void hitLuas()
    {
        double d = (x[1]*y[2] + x[2]*y[0] + x[0]*y[1]) - (x[1]*y[0] + x[2]*y[1] + x[0]*y[2]);
        luas.push_back(d);
        x.clear(); y.clear();
    }
    void hitKeliling()
    {
        double d, e, f = 0.0;
        for(int i = 0 ; i < 3; i++)
        {
            for(int j = i+1 ; j < 3 ; j++)
            {
                d = (x[i]-x[j]); d*=d;
                e = (y[i]-y[j]); e*=e;
                f += sqrt(d+e);
            }
        }
        keliling.push_back(f);
    }
    double getLuas()
    {
        return luas.back();
    }
    void hitRata2()
    {
        rata2 = 0; ratak = 0;
        for(unsigned int i = 0; i < luas.size(); ++i)
        {
            rata2 += luas[i];
            ratak += keliling[i];
        }
        rata2/=luas.size();
        ratak/=keliling.size();
    }
    double getRata2()
    {
        return rata2;
    }
    pair<int, int>  lolos()
    {
        int a = 0, b = 0;
        for(int i = 0;i < luas.size();i++)
        {
            if (luas[i] > rata2) ++a;
            if (keliling[i] > ratak) ++b;
        }
        return make_pair(a, b);
    }
};
 
class lingkaran: public polygon{
private:
    double ratal, ratak;
    vector<double> luas, keliling;
public:
    void set(double r)
    {
        double d = 2*3.14*r;
        keliling.push_back(d);
        d = 3.14*r*r;
        luas.push_back(d);
        // cout << keliling.back() << " " << luas.back() << endl;
    }
    void rata2()
    {
        ratal = 0; ratak = 0;
        for(unsigned int i = 0; i < luas.size(); ++i)
        {
            ratal += luas[i]; ratak += keliling[i];
        }
        ratal/=luas.size(); ratak/=keliling.size();
        // cout << ratal << " " << ratak << endl;
    }
    pair<int, int> lolos()
    {
        int a = 0, b = 0;
        for(unsigned int i = 0; i < luas.size(); i++)
        {
            if (luas[i] > ratal) ++a;
            if (keliling[i] > ratak) ++b; 
        }
        return make_pair(a, b);
    }
};
 
int main()
{
    ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    double x[4], y[4], r;
    int n, m;
    lingkaran L;
    segitiga T;
    cin >> n >> m;
    while(n--)
    {
        cin >> x[0] >> y[0] >> r;
        L.set(r);
    }
    L.rata2();
    while(m--)
    {
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
        for(int i = 0 ; i < 3; ++i)
        {
            T.set(x[i], y[i]);
        }
        T.hitLuas(); T.hitKeliling();
    }
    T.hitRata2();
    cout << L.lolos().second << " " << T.lolos().first << endl;
    cout << L.lolos().first << " " << T.lolos().second << endl;
}
