//LIB FILE



// ░█▀▀░█▀█░█▀█░█▀▄░█░█░░░█▀▀░█░█░█▀█░█▀█
// ░█░░░█▀█░█░█░█░█░░█░░░░▀▀█░█▀█░█░█░█▀▀
// ░▀▀▀░▀░▀░▀░▀░▀▀░░░▀░░░░▀▀▀░▀░▀░▀▀▀░▀░░


#ifndef LIB_H
#define LIB_H

#include <stdio.h> //gia inout/output
#include <string.h> //gia tis perigrafes twn proiontwn
//#include <cstddef> //gia na dhlwnoume ta errors
#include <stdlib.h> //gia to exit()

//maximum xarakthres perigrafhs gia kathe proion
#define MAX_DESC_SIZE 120
//maximum arithmos proiontwn 5
#define INVENTORY_SIZE 20
//h parakatw domh antiprosopevei to kathe proion me tis antistixes leptomeries
//*unsgined int dioti o arithmos twn diathesimwn proiontwn de borei na einai arnhtikos
typedef struct {
    char desc[MAX_DESC_SIZE];
    float price;
    unsigned int item_count;
} Product;

//sunarthsh gia arxikopohsh tou kathe proiontos ston pinaka
Product add2inventory(float nPrice, const char *nDesc);

//to menu pou tha emfanizete kata thn ektelesh tou programmatos
//edw o xristis apofasizei an tha na einai o admin h o pelaths

void final_report(int t_requests, int t_sucessfull, int total_failed, int rev);

#endif

//-----TBD-----