#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "sculptor.h"
#include "figurageometrica.h"

/**
 * @brief A Classe PutEllipsoid.
 */
class PutEllipsoid : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    ~PutEllipsoid();
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
