#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "sculptor.h"
#include "figurageometrica.h"

/**
 * @brief A Classe CutVoxel.
 */
class CutVoxel : public FiguraGeometrica{
    int x, y, z;
public:
    CutVoxel(int x, int y, int z);
    ~CutVoxel();
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
