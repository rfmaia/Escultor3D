#include "putsphere.h"
#include <math.h>

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius){
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;
}

PutSphere::~PutSphere(){

}

void PutSphere::draw(Sculptor &t){
    // x^2 + y^2 + z^2 = r^2
    int x, y, z;
    double r;
    for(x = xcenter - radius; x <= xcenter + radius; x++){
        for(y = ycenter - radius; y <= ycenter + radius; y++){
            for(z = zcenter - radius; z <= zcenter + radius; z++){
                r = sqrt(pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - zcenter, 2));
                if (r <= radius){
                    t.putVoxel(x, y, z);
                }
            }
        }
    }
}
