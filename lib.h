//---LIB FILE
#ifndef LIB.H
#define LIB_h

//viovliothikes
#include <stdio.h> //gia inout/output
#include <string.h> //gia tis perigrafes twn proiontwn
#include <cstddef> //gia na dhlwnoume ta errors
#include <cstdlib> //gia to exit()

//maximum xarakthres perigrafhs gia kathe proion
#define MAX_DESC_SIZE 120

//h parakatw domh antiprosopevei to kathe proion me tis antistixes leptomeries
//*unsgined int dioti o arithmos twn diathesimwn proiontwn de borei na einai arnhtikos

typedef struct {
    char desc[MAX_DESC_SIZE];
    double price;
    unsigned int item_count;
} Product;

//to inline benei dioti dhlwnoume sunarthseis se header file
inline void add2inventory(Product *newproduct, double nPrice, const char *nDesc){
    //Product newproduct;
    //arxika diathesima uparxoun 2 proionta sumfwna me thn ekfwnhsh
    newproduct->item_count = 2;
    newproduct->price = nPrice;
    //gia thn perigrafh prwta elenxoume oti den einai kenh
    if(nDesc != NULL){
        //h antigrafh ths neas perigrafhs
        strncpy(newproduct->desc, nDesc, sizeof(newproduct->desc) -1);
        newproduct->desc[sizeof(newproduct->desc) -1] = '\0';
    } else {
        //prepei na ksanadinei o xrhsths upotheto pros to parwn to grafw ws error kai to prograna termatizei
        fprintf(stderr, "[!] error: %s", "no description given...");
        exit(1);
    }
}

#endif

//-----TBD-----