#include "putellipsoid.h"
#include <math.h>

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a){
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

PutEllipsoid::~PutEllipsoid(){

}

void PutEllipsoid::draw(Sculptor &t){
    // (x^2)/(a^2) + (y^2)/(b^2) + (z^2)/(c^2) = 1
    int x, y, z;
    double eq;
    for(x = xcenter - rx; x <= xcenter + rx; x++){
        for(y = ycenter - ry; y <= ycenter + ry; y++){
            for(z = zcenter - rz; z <= zcenter + rz; z++){
                eq = (pow(x - xcenter, 2)/pow(rx, 2)) + (pow(y - ycenter, 2)/pow(ry, 2)) + (pow(z - zcenter, 2)/pow(rz, 2));
                if (eq <= 1){
                    t.putVoxel(x, y, z);
                }
            }
        }
    }
}
