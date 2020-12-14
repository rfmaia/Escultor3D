#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "sculptor.h"
#include "figurageometrica.h"

/**
 * @brief A Classe CutSphere é uma subclasse que herda de FiguraGeometrica os métodos e removerá uma esfera de voxel.
 */
class CutSphere : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, radius;
public:
    /**
     * @brief CutSphere é o construtor da subclasse.
     * @param xcenter é o centro da esfera no eixo x.
     * @param ycenter é o centro da esfera no eixo y.
     * @param zcenter é o centro da esfera no eixo z.
     * @param radius é o raio da esfera.
     */
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~CutSphere();
    /**
     * @brief draw é o metodo abstrato herdado de FiguraGeometrica para realizar a remoção de uma esfera de voxel.
     * @param t é uma classe com nome Sculptor.
     */
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
