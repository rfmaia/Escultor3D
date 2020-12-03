#include "putbox.h"

PutBox::PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a){
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
    this->z0 = z0;
    this->z1 = z1;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

PutBox::~PutBox(){

}

void PutBox::draw(Sculptor &t){
    int x, y, z;
    t.setColor(r, g, b, a);
    if (x0 > x1) troca(x0, x1);
    if (y0 > y1) troca(y0, y1);
    if (z0 > z1) troca(z0, z1);
    for(x = x0; x < x1; x++){
        for(y = y0; y < y1; y++){
            for(z = z0; z < z1; z++){
                t.putVoxel(x, y, z);
            }
        }
    }
}


