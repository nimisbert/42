#include <spiegel10.h>

double distanceBetweenPoints(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}

double slopeBetweenPoints(double x1, double y1, double x2, double y2)
{
    return (y2 - y1)/(x2 - x1);
}

line lineBetweenPoints(double x1, double y1, double x2, double y2)
{
    static line l;
    l.m = slopeBetweenPoints(x1,y1,x2,y2);
    l.b = y1 - l.m*x1;
    return l;
}

double angleBetweenLines(line line1, line line2)
{
    double tanPhi = (line2.m - line1.m) / (1 + line1.m*line2.m);
    return atan(tanPhi);
}

double triangleAreaFromVertices(point v1, point v2, point v3)
{
    double a = 0.5*(v1.x*v2.y + v1.y*v3.x + v3.y*v2.x - v2.y*v3.x - v1.y*v2.x - v1.x*v3.y);
    a = (a<0.0)? -a : a;
    return a;
}

point pointTransformPureTranslation(point p, double x0, double y0)
{
    static point r;
    r.x = p.x -x0;
    r.y = p.y -y0;
    return r;
}

point pointTransformPureRotation(point p, double alpha)
{
    static point r;
    r.x = p.x*cos(alpha) + p.y*sin(alpha);
    r.y = p.y*cos(alpha) - p.x*sin(alpha);
    return r;
}

point pointTransform(point p, double x0, double y0, double alpha)
{
    static point r;
    r.x = (p.x - x0)*cos(alpha) + (p.y - y0)*sin(alpha);
    r.y = (p.y - y0)*cos(alpha) - (p.x - x0)*sin(alpha);
    return r;
}

point toPlanar(point p)
{
    p.x = p.r * cos(p.theta);
    p.y = p.r * sin(p.theta);
    return p;
}

point toPolar(point p)
{
    static point r;
    r.x = p.x;
    r.y = p.y;
    r.r = sqrt(p.x*p.x + p.y*p.y);
    printf("x = %lf ,y/x = %lf\r\n",p.x,p.y/p.x);
    if(abs(p.x)==0.0)
        r.theta = atan(p.y/p.x);
    else
        r.theta = 0.0;
    return r;
}

unsigned char pIsOnCirclePlanar(point p, double x0, double y0, double R)
{
    if(pow(p.x-x0,2)+pow(p.y-y0,2)-R*R == 0.0)
        return 1;
    return 0;
}

unsigned char pIsOnCirclePolar(point p, double R, double alpha)
{
    printf("Local : %lf\r\n",2*R*cos(p.theta-alpha)-p.r);
    if(abs(2*R*cos(p.theta-alpha)-p.r) == 0.0)
        return 1;
    return 0;
}