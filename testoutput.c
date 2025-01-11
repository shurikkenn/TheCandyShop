//test output
#include <stdio.h>
#include "core/libs/lib.h"

int main(void){
    Product catalog[INVENTORY_SIZE];
    for(int i=1;i<=INVENTORY_SIZE;i++){
        Product newproduct;
        float innit_price;
        char innit_desc[MAX_DESC_SIZE];
        printf("[*] please fill the information for the product number %d...\n", i);
        printf("description -> ");
        fgets(innit_desc, sizeof(innit_desc), stdin);
        printf("\nprice -> ");
        scanf("%f", &innit_desc);
        catalog[i] = add2inventory(innit_price, innit_desc);
    }
}