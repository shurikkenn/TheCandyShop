#include <stdio.h>


int main(){
    float price[5]={5.99,7.99,1.99,24.99,10.0};
    int inStock [5]={30,4,14,24,50};

    int i;
    for (i=0;i<5;i++){
        printf("item: %d",i," Price: %f",price[i]," in stock: %d\n",inStock[i]);
    }
    
    
}