//lib,c kanei implement to header file lib.h



// ░█▀▀░█▀█░█▀█░█▀▄░█░█░░░█▀▀░█░█░█▀█░█▀█
// ░█░░░█▀█░█░█░█░█░░█░░░░▀▀█░█▀█░█░█░█▀▀
// ░▀▀▀░▀░▀░▀░▀░▀▀░░░▀░░░░▀▀▀░▀░▀░▀▀▀░▀░░



#include "lib.h"
#include <stdio.h> //gia inout/output
#include <string.h> //gia tis perigrafes twn proiontwn
//#include <cstddef> //gia na dhlwnoume ta errors
#include <stdlib.h> //gia to exit()



Product add2inventory(double nPrice, const char *nDesc){
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

int innit_menu(void){
    int user_option;
    printf("░█▀▀░█▀█░█▀█░█▀▄░█░█░░░█▀▀░█░█░█▀█░█▀█\n");
    printf("░█░░░█▀█░█░█░█░█░░█░░░░▀▀█░█▀█░█░█░█▀▀\n");
    printf("░▀▀▀░▀░▀░▀░▀░▀▀░░░▀░░░░▀▀▀░▀░▀░▀▀▀░▀░░\n");
    printf("\nwelcome.");
    printf("\nplease select");
    printf("\n[1] admin (to fill the catalog)");
    printf("\n[2] customer (to begin ordering)");
    printf("\n[0] exit ");
    printf("\n~$ ");
    scanf("%d", &user_option);
    //periptwsh p ginei katlathos epilogh peran tou menu
    while(user_option < 0 || user_option > 2){
        printf("\n[ERROR] Please select only from the menu...");
        printf("\n~$ ");
        scanf("%d", &user_option);
    }
    return user_option;
}
