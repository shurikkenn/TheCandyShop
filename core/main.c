//MAIN FILE



// ░█▀▀░█▀█░█▀█░█▀▄░█░█░░░█▀▀░█░█░█▀█░█▀█
// ░█░░░█▀█░█░█░█░█░░█░░░░▀▀█░█▀█░█░█░█▀▀
// ░▀▀▀░▀░▀░▀░▀░▀▀░░░▀░░░░▀▀▀░▀░▀░▀▀▀░▀░░



#include <stdlib.h>
#include <stdio.h>
#include "libs/lib.h"

int main(void){
    //innitial menu launch
    //h metavlhth mode tha kathorisei an prokeite gia diaxeirsth pou tha genisei ton katalogo h gia pelath
    int mode;
    mode = innit_menu(); //deite sto arxeuio libs.h
    if(mode==0){
        //o xrhsths epelekse na termatisei to programma
        printf("\nbye...");
        exit(0);
    } else if(mode==1) {
        //o xrhsths epelekse na einai diaxhristeis kai na gemisei ton katalogo
        //h vasikh domh p emperiexei ta proionta
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
    } else if(mode==2){
        //o xrhsths epelekse na einai pelatjs
        //TBD
    }

    return EXIT_SUCCESS;
}

//-------TBD---------q