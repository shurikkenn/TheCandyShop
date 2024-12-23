//---LIB FILE
#ifndef LIB_H
#define LIB_H

#include <stdio.h> //gia inout/output
#include <string.h> //gia tis perigrafes twn proiontwn
//#include <cstddef> //gia na dhlwnoume ta errors
#include <stdlib.h> //gia to exit()

//maximum xarakthres perigrafhs gia kathe proion
#define MAX_DESC_SIZE 120
//maximum arithmos proiontwn 5
#define MAX_INVENTORY_SIZE 5
//h parakatw domh antiprosopevei to kathe proion me tis antistixes leptomeries
//*unsgined int dioti o arithmos twn diathesimwn proiontwn de borei na einai arnhtikos
typedef struct {
    char desc[MAX_DESC_SIZE];
    double price;
    unsigned int item_count;
} Product;

//dhlwseis sunarthsewn
Product add2inventory(double nPrice, const char *nDesc);

#endif

//-----TBD-----