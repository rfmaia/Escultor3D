#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

/**
 * @brief A Classe FiguraGeometrica é uma classe abstrata que será utilizada para desenhas as figuras.
 */
class FiguraGeometrica{
protected:
    float r, g, b, a;
public:
    /**
     * @brief ~FiguraGeometrica é o destrutor da classe abstrata.
     */
    virtual ~FiguraGeometrica();
    /**
     * @brief draw é o método abstrato.
     * @param t é uma classe com nome Sculptor.
     */
    virtual void draw(Sculptor &t)=0;
};

#endif // FIGURAGEOMETRICA_H
