#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "sculptor.h"
#include "figurageometrica.h"

/**
 * @brief A Classe PutSphere.
 */
class PutSphere : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, radius;
public:
    PutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~PutSphere();
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
