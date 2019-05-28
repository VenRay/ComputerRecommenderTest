#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

const double PI = acos(-1);
int main()
{
    double x0,y0,z0,x1,y1,z1;
    double r,v;
    scanf("%lf%lf%lf%lf%lf%lf",&x0,&y0,&z0,&x1,&y1,&z1);
    r = sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)+(z1-z0)*(z1-z0));
    v = pow(r,3)*PI*4/3;
    printf("%.3f %.3f",r,v);
    return 0;
}