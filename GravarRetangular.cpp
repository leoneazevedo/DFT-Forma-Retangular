
#define N 8
#define M 8
#define fs 8000
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

main() {
    ofstream saida("DFTRetangular.txt");
    double xn=0,ts=(double)1/fs;
    double xmi=0;
    double xmr=0;
    double xm=0;
//-----------------------------------------------------------------------
    for (int m=0; m<N ;m++){
        xmr=0;
        xmi=0;
        for (int n=0;n<M;n++) {
            xn=sin(2*M_PI*1000*n*ts)+0.5*sin(2*M_PI*2000*n*ts+3*M_PI/4);
            xmr+=xn*cos((2*M_PI*n*m)/N);//Calculo do real
            xmi+=(xn*(-sin(2*M_PI*n*m/N)));//Calculo imaginário
        }
//Aproximação------------------------------------------------------------
        xmr*=10000.0;
        xmr= (int) xmr;
        xmr/=10000.0;

        xmi*=10000.0;
        xmi=(int) xmi;
        xmi/=10000.0;
//-----------------------------------------------------------------------
            saida <<"x("<<m<<")= "<< setiosflags (ios::fixed) << setprecision (2)<<"("<<xmr<<")"<<"+"<<"("<<xmi<<"(j)"<<")"<< endl;
            //cout <<"x("<<m<<")= "<< setiosflags (ios::fixed) << setprecision (2)<<"("<<xmr<<")"<<"+"<<"("<<xmi<<"(j)"<<")"<< endl;
        }
}
