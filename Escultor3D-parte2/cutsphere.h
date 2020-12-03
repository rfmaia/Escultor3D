#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "sculptor.h"
#include "figurageometrica.h"

/**
 * @brief A Classe CutSphere.
 */
class CutSphere : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~CutSphere();
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
