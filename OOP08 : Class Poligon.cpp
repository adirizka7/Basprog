#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;

class polygon 
{
private:
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

int main()
{
	ios::sync_with_stdio(false);
	int t; double a, b;
	polygon A;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		A.set(a, b);
	}
	A.keliling();
	cout << fixed << setprecision(2) << "[" << A.getxAwal() << "," << A.getyAwal() << "]-[" << A.getxAkhir() << "," << A.getyAkhir() << "]" << endl;
	cout << fixed << setprecision(2) << A.getTotal() << endl;
}
