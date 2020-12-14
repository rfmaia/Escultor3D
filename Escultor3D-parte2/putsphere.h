#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "sculptor.h"
#include "figurageometrica.h"

/**
 * @brief A Classe PutSphere é uma subclasse que herda de FiguraGeometrica os métodos e adicionará uma esfera de voxel.
 */
class PutSphere : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, radius;
public:
    /**
     * @brief PutSphere é o construtor da subclasse.
     * @param xcenter é o centro da esfera no eixo x.
     * @param ycenter é o centro da esfera no eixo y.
     * @param zcenter é o centro da esfera no eixo z.
     * @param radius é o raio da esfera.
     * @param r é a dosagem de vermelho(red).
     * @param g é a dosagem de verde(green).
     * @param b é a dosagem de azul(blue).
     * @param a é a dosagem de alpha(transparência).
     */
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    ~PutSphere();
    /**
     * @brief draw é o metodo abstrato herdado de FiguraGeometrica para desenhar uma esfera de voxel.
     * @param t é uma classe com nome Sculptor.
     */
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
