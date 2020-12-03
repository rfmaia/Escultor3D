#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include "sculptor.h"

using namespace std;

void troca(int &x, int &y){
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;

    //Alocacar
    v = new Voxel**[nx];
    for(int i = 0; i < nx; i++){
        v[i] = new Voxel*[ny];
        for(int j = 0; j < ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }

    //Preenchimento
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
                v[i][j][k].isOn = false;
            }
        }
    }
}

Sculptor::~Sculptor(){
    //Desalocar
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            delete [] v[i][j];
        }
        delete [] v[i];
    }
    delete [] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    this->r = r;
    this->g = g;
    this->b = b;
    a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::writeOFF(char *filename){
    ofstream fout;
    fout.open(filename);
    if(!fout.is_open()){
        exit(1);
    }
    fout << "OFF" << endl;

    int count_voxel = 0;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (v[i][j][k].isOn){
                    count_voxel++;
                }
            }
        }
    }
    fout << 8*count_voxel << " " << 6*count_voxel << " " << 0 << endl;

    // Vertices do voxel
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (v[i][j][k].isOn){
                    fout << -0.5+i << " " << 0.5+j << " " << -0.5+k << endl; // P0
                    fout << -0.5+i << " " << -0.5+j << " " << -0.5+k << endl; // P1
                    fout << 0.5+i << " " << -0.5+j << " " << -0.5+k << endl; // P2
                    fout << 0.5+i << " " << 0.5+j << " " << -0.5+k << endl; // P3
                    fout << -0.5+i << " " << 0.5+j << " " << 0.5+k << endl; // P4
                    fout << -0.5+i << " " << -0.5+j << " " << 0.5+k << endl; // P5
                    fout << 0.5+i << " " << -0.5+j << " " << 0.5+k << endl; // P6
                    fout << 0.5+i << " " << 0.5+j << " " << 0.5+k << endl; // P7
                }
            }
        }
    }

    // Estruturar os voxel
    int nvoxel = 0;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (v[i][j][k].isOn){
                    fout << "4 " << 0+nvoxel*8 << " " << 3+nvoxel*8 << " " << 2+nvoxel*8 << " " << 1+nvoxel*8 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl; // Face1: P0 P3 P2 P1
                    fout << "4 " << 4+nvoxel*8 << " " << 5+nvoxel*8 << " " << 6+nvoxel*8 << " " << 7+nvoxel*8 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl; // Face2: P4 P5 P6 P7
                    fout << "4 " << 0+nvoxel*8 << " " << 1+nvoxel*8 << " " << 5+nvoxel*8 << " " << 4+nvoxel*8 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl; // Face3: P0 P1 P5 P4
                    fout << "4 " << 0+nvoxel*8 << " " << 4+nvoxel*8 << " " << 7+nvoxel*8 << " " << 3+nvoxel*8 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl; // Face4: P0 P4 P7 P3
                    fout << "4 " << 7+nvoxel*8 << " " << 6+nvoxel*8 << " " << 2+nvoxel*8 << " " << 3+nvoxel*8 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl; // Face5: P7 P6 P2 P3
                    fout << "4 " << 1+nvoxel*8 << " " << 2+nvoxel*8 << " " << 6+nvoxel*8 << " " << 5+nvoxel*8 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl; // Face6: P1 P2 P6 P5
                    nvoxel++;
                }
            }
        }
    }
    fout.close();
}
