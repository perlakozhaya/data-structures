#include <stdio.h>

void matriceSimplifier(int size, double m[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {

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

    matriceSimplifier(size, m);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.2f\t", m[i][j]); // %.2f kermel to3rodle bas 2 chiffres apres la virgule
        }
        printf("\n");
    }

    return 0;
    //eh 3ezet bati5a ta y2ele l etapet taba3 l calcul fa tole3 badna njiib l facteur yali badna nodrob fi l sater
}
