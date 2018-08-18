#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

int a[300][300];

double dientich(int a, int b, double c, double d, double e, double f)
{
    double x=sqrt((a-c)*(a-c)+(b-d)*(b-d));
    double y=sqrt((a-e)*(a-e)+(b-f)*(b-f));
    double z=sqrt((c-e)*(c-e)+(d-f)*(d-f));
    double p=1.*(x+y+z)/2;
    if (x>p)
        x=p;
    if (z>p)
        z=p;
    if (y>p)
        y=p;
    return (1.* sqrt(p* (p-x) *(p-y) *(p-z)));
}

double abss(double temp)
{
    if (temp<0)
        return -1.*temp;
    return temp;
}

bool bang(double a, double b)
{
    if (abss(a-b)<0.001 || a<=b)
        return true;
    return false;
}

int main()
{
    double t;
    int w,h,k,l,r,x1,y1,x3,y3;
    cin>>h>>w;
    cin>>l>>k>>r;
    cin>>y1>>x1>>y3>>x3;
    double x2,x4,y2,y4;
    x2=1.*(x1+x3+y3-y1)/2;
    x4=1.*(x1+x3+y1-y3)/2;
    y2=1.*(y1+y3+x1-x3)/2;
    y4=1.*(y1+y3+x3-x1)/2;
    double dthv = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*sqrt((x1-x4)*(x1-x4)+(y1-y4)*(y1-y4)),kq;
    if (x1==x3 && y1==y3)
    {
        a[x1][y1]=1;
        dthv=-10;
    }

    for (int i=0;i<w;i++)
        for (int j=0;j<h;j++)
        {
            t=1.0*sqrt(1.*(k-i)*(k-i)+ 1.*(j-l)*(j-l));
            if (t<=r)
                a[i][j]=1;
            kq=dientich(i,j,x1,y1,x2,y2)+dientich(i,j,x2,y2,x3,y3)+dientich(i,j,x1,y1,x4,y4)+dientich(i,j,x4,y4,x3,y3);
            if (bang(kq,dthv))
                a[i][j]=1;
        }

    for (int i=0;i<w;i++){
        for (int j=0;j<h;j++)
            if (a[i][j]==0)
                printf(".");
            else
                printf("#");
        cout<<endl;
    }
    return 0;
}
