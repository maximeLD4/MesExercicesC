#include <math.h>


void norm_vect(vector_2D * vect )
{
    double x1 = vect->x;
    double y1 = vect->y;
    if (x1!=0 && y1!=0)
    {
        double norme = sqrt((x1*x1) + (y1*y1));
        vect->x = x1/norme;
        vect->y = y1/norme; 
    }
}


void norm_vect_xy(double * x1,double * y1)
{
    double a= *x1;
    double b= *y1;
    double norme = sqrt((a*a) + (b*b));
    *x1 = (a)/norme;
    *y1  = (b)/norme;
}
