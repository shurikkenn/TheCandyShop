//lib,c kanei implement to header file lib.h



// ░█▀▀░█▀█░█▀█░█▀▄░█░█░░░█▀▀░█░█░█▀█░█▀█
// ░█░░░█▀█░█░█░█░█░░█░░░░▀▀█░█▀█░█░█░█▀▀
// ░▀▀▀░▀░▀░▀░▀░▀▀░░░▀░░░░▀▀▀░▀░▀░▀▀▀░▀░░



#include "lib.h"
#include <stdio.h> //gia inout/output
#include <string.h> //gia tis perigrafes twn proiontwn
//#include <cstddef> //gia na dhlwnoume ta errors
#include <stdlib.h> //gia to exit()



Product add2inventory(float nPrice, const char *nDesc){
    Product newproduct;
    //arxika diathesima uparxoun 2 proionta sumfwna me thn ekfwnhsh
    newproduct.item_count = 2;
    newproduct.price = nPrice;
    //gia thn perigrafh prwta elenxoume oti den einai kenh
    if(nDesc != NULL){
        //h antigrafh ths neas perigrafhs
        strncpy(newproduct.desc, nDesc, sizeof(newproduct.desc) -1);
        newproduct.desc[sizeof(newproduct.desc) -1] = '\0';
    } else {
        //prepei na ksanadinei o xrhsths upotheto pros to parwn to grafw ws error kai to prograna termatizei
        fprintf(stderr, "[!] error: %s", "no description given...");
        exit(1);
    }
    return newproduct;
}

void final_report(int t_requests, int t_sucessfull, int total_failed, int rev){
    printf("\n\t\t\ttotal purchase requests = %d", t_requests);
    printf("\nRuntime stats -> ");
    printf("\ttotal succesfull purchases = %d", t_sucessfull);
    printf("\n\t\t\ttotal failed purchases = %d", total_failed);
    printf("\n\t\t\ttotal revenue accumilated = %d", rev);
    printf("\n---------END OF REPORT---------\n");
}
