#include <iostream>
#include <sculptor.h>

using namespace std;

int main(){
    Sculptor teste(31,31,41);
    teste.setColor(0.357,0.357,0.345,1);
    teste.putEllipsoid(16,16,16,5,6,7);
    teste.cutSphere(10,10,10,7);
    teste.cutEllipsoid(16,16,16,4,4,6);
    teste.setColor(0.486, 0.988, 0, 1);
    teste.putVoxel(22,22,22);
    teste.putVoxel(22,22,23);
    teste.cutVoxel(22,22,22);
    teste.writeOFF((char*)"D:/teste.off");

    Sculptor caixa(20,10,10);
    caixa.setColor(0,1,1,1);
    caixa.putBox(0,19,0,9,0,9);
    caixa.cutBox(1,18,1,8,1,9);
    caixa.writeOFF((char*)"D:/caixa.off");

    Sculptor tree(31,31,41);
    tree.setColor(0.486, 0.988, 0, 1);
    tree.putBox(0, 30, 0, 31, 0, 1);
    tree.setColor(0.588, 0.294, 0, 1);
    tree.putBox(14, 19, 14, 19, 1, 16);
    tree.setColor(0.388, 0.792, 0, 1);
    tree.putEllipsoid(16,16,20,10,10,12);
    tree.putSphere(5, 5, 1, 5);
    tree.setColor(0.514, 0.843, 0.933, 1);
    for(int i = 0; i < 30;i++){
        tree.putVoxel(rand() % 30, rand() % 30, rand() % 40);
    }
    tree.writeOFF((char*)"D:/tree.off");
    return 0;
}
