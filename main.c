//MAIN FILE
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int main(void){

    //ousiastika h vasikh domh p emperiexei ta proionta
    Product catalog[MAX_INVENTORY_SIZE];
    //h epanalhpsh p gemizei to catalog
    for(int i=0;i<MAX_INVENTORY_SIZE;i++){
        Product newproduct;
        double innit_price;
        char innit_desc[MAX_DESC_SIZE];

        printf("description: ");
        fgets(innit_desc, sizeof(innit_desc), stdin); //gia asfaleia mnhmhs
        printf("\nprice: ");
        scanf("%lf", &innit_price);
        catalog[i] = add2inventory(innit_price, innit_desc);
    }
    return EXIT_SUCCESS;
}

//-------TBD---------q