#include <stdio.h>

void matriceSimplifier(int size, double m[size][size]) {
    int tmp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // ta ma tse2eb division par 0 baddalet bel awwal el ligne matrah ma m[i][i] == 0 ma3 el ligne li tahta ka2ano L1 <-> L2
            if(m[i][i] == 0) {
                for(int l = 0; l < size; l++) {
                    tmp = m[i][l];
                    m[i][l] = m[i+1][l];
                    m[i+1][l] = tmp;
                }
            }
            //l facteur double ta ma ta3mel aroundisment lal jaweb 
            double facteur = m[j][i] / m[i][i];//m[j][i] -> element yali bado ysir 0; m[i][i] element yali faw2o bi sater

            for (int k = i; k < size; k++) {
                m[j][k] -= facteur * m[i][k];// ka2an L2 <- L2 - (facteur x L1)
            }
        }
    }
}

int main() {
    int size = 3;
    double m[3][3] = {
        {2, -1, 2},
        {4, 3, -3},
        {-2, 2, 1}
    };

    double m1[3][3] = {
        {1, -2, 1},
        {0, 2, -8},
        {0, -3, 10}
    };

    double m2[3][3] = {
        {1, 0, 0},
        {0, 0, 2},
        {0, 3, 4}
    };

    double m3[3][3] = {
        {0, 2, 0},
        {1, 0, 2},
        {0, 3, 0}
    };

    matriceSimplifier(size, m3);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.2f\t", m3[i][j]); // %.2f kermel to3rodle bas 2 chiffres apres la virgule
        }
        printf("\n");
    }

    return 0;
    //eh 3ezet bati5a ta y2ele l etapet taba3 l calcul fa tole3 badna njiib l facteur yali badna nodrob fi l sater
}