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
	double rata2 ;
	vector <double> luas;
public:
	void hitLuas()
	{
		double d = (x[1]*y[2] + x[2]*y[0] + x[0]*y[1]) - (x[1]*y[0] + x[2]*y[1] + x[0]*y[2]);
		luas.push_back(d);
		x.clear(); y.clear();
	}
	double getLuas()
	{
		return luas.back();
	}
	void hitRata2()
	{
		rata2 = 0;
		for(unsigned int i = 0; i < luas.size(); ++i)
		{
			rata2 += luas[i];
		}
		rata2/=luas.size();
	}
	double getRata2()
	{
		return rata2;
	}
	int lolos()
	{
		int d = 0;
		for(int i = 0;i < luas.size();i++)
		{
			if (luas[i] > rata2) ++d;
		}
		return d;
	}
};

class segiempat: public polygon {
private:
	double rata2;
	vector <double> luas;
public:
	void hitLuas()
	{
		keliling();
		double d = getTotal() / 4.0; d*=d;
		luas.push_back(d);
		rata2 += d;
		total.clear(); x.clear(); y.clear();
	}
	void hitRata2()
	{
		rata2 = 0;
		for(unsigned int i = 0; i < luas.size(); ++i)
		{
			rata2 += luas[i];
		}
		rata2/=luas.size();
	}
	double getRata2()
	{
		return rata2;
	}
	int lolos()
	{
		int d = 0;
		for(int i = 0;i < luas.size();i++)
		{
			if (luas[i] > rata2) ++d;
		}
		return d;
	}
};

int main()
{
	ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	double n, x[10], y[10], m;
	segitiga T;
	segiempat E;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
		// cout << x[i+2] << " " << y[i+2] << endl;
		for(int j = 0; j<3; j++)
			T.set(x[j], y[j]);
		T.hitLuas();
	}
	T.hitRata2();

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];
		for(int j = 0; j < 4; j++)
			E.set(x[j], y[j]);
		E.hitLuas();
	}
	E.hitRata2();

	cout << fixed << setprecision(2) << T.getRata2() << " " << E.getRata2() << endl;
	cout << T.lolos() << " " << E.lolos() << endl;
}