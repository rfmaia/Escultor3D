#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "sculptor.h"
#include "figurageometrica.h"

/**
 * @brief A Classe CutVoxel é uma subclasse que herda de FiguraGeometrica os métodos e removerá o voxel.
 */
class CutVoxel : public FiguraGeometrica{
    int x, y, z;
public:
    /**
     * @brief CutVoxel é o construtor da subclasse.
     * @param x
     * @param y
     * @param z
     */
    CutVoxel(int x, int y, int z);
    ~CutVoxel();
    /**
     * @brief draw é o metodo abstrato herdado de FiguraGeometrica para realizar a remoção de um voxel.
     * @param t é uma classe com nome Sculptor.
     */
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
