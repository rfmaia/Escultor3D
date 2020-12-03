#include <iostream>
#include <vector>
#include "sculptor.h"
#include "figurageometrica.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "interpretador.h"

using namespace std;

int main(){
    Sculptor *s1;

    Interpretador parser;

    vector<FiguraGeometrica*> figs;

    figs = parser.parse("D:/escultura.txt");

    s1 = new Sculptor(parser.getDimX(), parser.getDimY(), parser.getDimZ());

    for(size_t i = 0; i < figs.size(); i++){
        cout << "draw\n";
        figs[i]->draw(*s1);
    }

    //s1->limpaVoxels();

    s1->writeOFF((char*)"D:/saida.off");
    for(size_t i = 0; i < figs.size(); i++){
        delete figs[i];
    }
    delete s1;
    return 0;
}
