#include <iostream>
#include "vector"
#include "algorithm"
#include "time.h"
#include <map>
#include <cmath>
using namespace std;
const double u=0;
const double g=10;
class Norm{
private: double x;
    double F;
public:
    Norm(double x) : x(x) {}
    double getX()  {
        return x;
    }
    double getF()  {
        return (exp(-(x-u)*(x-u)/(2*g*g)))/(g*sqrt(2*3.14));
    }
};
template <class T>
void Vivod(vector<T> AA){
    for(int i=0; i<AA.size(); i++){
        cout<<AA[i]<<endl;}
}
double Randd (double fMin, double fMax){
    double f=(double)rand()/ RAND_MAX;
    return fMin+f*(fMax-fMin);
}
int main() {
    vector<double> N;
    for(int x=-10; x<10; x++){
        Norm Ni(x);
        N.push_back(Ni.getF());
    }
    double sum=0;
    for(auto it: N) sum=sum+it;
    for (int i=0; i<N.size(); i++) N[i]=(N[i]/sum);
    double sum1=0;
    vector<double> M;
    for(int i=0; i<N.size(); i++){
        sum1=sum1+N[i];
        M.push_back(sum1);
    }
    Vivod(M);
    vector<double > X;
    for (double i=-10; i<11; i+=1)
        X.push_back(i);

    srand(time(NULL));
    map<double,double > map1;
    for (double i=0; i<M.size(); i++) {
        map1.emplace(M[i], X[i]);
        cout <<"   "<<sum1 << endl;
    }
    cout<<endl;

    vector <double> POINTS;

    for (int i = 0;i<M.size();i++) {
        double r = Randd(0,1);
        double xx = 0;
        for (auto &x: map1) {
            if (x.first > r) {
                xx = x.second;
                POINTS.push_back(xx);
                break;
            }
        }
        cout<<r<<"   "<<xx<<endl;
    }

    double Sum = 0;
    for (double i=0; i<POINTS.size(); i++) {
        Sum += POINTS[i];
    }
    double mean = Sum/POINTS.size();
    cout << mean << endl;

    double var;
    for (double i=0; i<POINTS.size(); i++) {
        var+= ((POINTS[i]-mean)*(POINTS[i]-mean));

    }
    cout << var/(POINTS.size()-1) << endl;
}