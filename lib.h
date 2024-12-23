//---LIB FILE
#ifndef LIB.H
#define LIB_h

//code base

//maximum xarakthres perigrafhs gia kathe proion
#define MAX_DESC_SIZE 120

//h parakatw domh antiprosopevei to kathe proion me tis antistixes leptomeries
//*unsgined int dioti o arithmos twn diathesimwn proiontwn de borei na einai arnhtikos

typedef struct {
    char desc[MAX_DESC_SIZE];
    double price;
    unsigned int item_count;
} product;

int add2inventory(product *p){
    //
}

#endif

//-----TBD-----