#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "sculptor.h"
#include "figurageometrica.h"

/**
 * @brief A Classe CutEllipsoid é uma subclasse que herda de FiguraGeometrica os métodos e removerá um elipsoide de voxel.
 */
class CutEllipsoid : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    /**
     * @brief CutEllipsoid é o construtor da subclasse.
     * @param xcenter é o centro do elipsóide no eixo x.
     * @param ycenter é o centro do elipsóide no eixo y.
     * @param zcenter é o centro do elipsóide no eixo z.
     * @param rx é o semieixo do elipsóide no eixo x.
     * @param ry é o semieixo do elipsóide no eixo y.
     * @param rz é o semieixo do elipsóide no eixo z.
     */
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~CutEllipsoid();
    /**
     * @brief draw é o metodo abstrato herdado de FiguraGeometrica para realizar a remoção de um elipsoide de voxel.
     * @param t é uma classe com nome Sculptor.
     */
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
