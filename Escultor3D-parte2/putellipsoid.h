#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "sculptor.h"
#include "figurageometrica.h"

/**
 * @brief A Classe PutEllipsoid é uma subclasse que herda de FiguraGeometrica os métodos e adicionará um elipsoide de voxel.
 */
class PutEllipsoid : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    /**
     * @brief PutEllipsoid é o construtor da subclasse.
     * @param xcenter é o centro do elipsóide no eixo x.
     * @param ycenter é o centro do elipsóide no eixo y.
     * @param zcenter é o centro do elipsóide no eixo z.
     * @param rx é o semieixo do elipsóide no eixo x.
     * @param ry é o semieixo do elipsóide no eixo y.
     * @param rz é o semieixo do elipsóide no eixo z.
     * @param r é a dosagem de vermelho(red).
     * @param g é a dosagem de verde(green).
     * @param b é a dosagem de azul(blue).
     * @param a é a dosagem de alpha(transparência).
     */
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    ~PutEllipsoid();
    /**
     * @brief draw é o metodo abstrato herdado de FiguraGeometrica para desenhar um elipsoide de voxel.
     * @param t é uma classe com nome Sculptor.
     */
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
