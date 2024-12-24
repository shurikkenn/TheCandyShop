#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>



int main (){
    int costumerToShop[2],storeToCostumer[2];//pipes, [0]= read, [1]= write
    int id = fork();
    if (id<0) {
        printf("Error sto fork");
        return 1;
    }
    else if (id != 0){ //Parent process
        //ftiaxnoume to catalog
        close(costumerToShop[1]);
        close(storeToCostumer[0]);
        int flag=0;
        
        while(flag==0){
            wait(0.5);
        }
    }
    else{ //Child process
        //Ftiaxnoume tis paragkelies
        int itemWanted;
        int flag,numberOfItems;
        //auta ta variable einai gia tous random arithmous
        int n,i;
        time_t t;
        n=10;//10 paragkeleies exei o kathe pelaths
        srand((unsigned)time(&t));

        close(costumerToShop[0]);
        close(storeToCostumer[1]);

        for (i=0; i<n; i++){
            printf("Ti item thelete na agorasete?\n");
            scanf("%d",&itemWanted);
            itemWanted=rand() %21 + 1;// pernoume ton arithmo tou random item gia na agorasei o pelaths

            if (write(costumerToShop[1], &itemWanted, sizeof(int)) <0 ){  // stelnoume to name tou item pou thelei o pelaths sto parent process
                return 1;//error
            }
            else{
                write(costumerToShop[1], &itemWanted, sizeof(int));
            }

            if (read(storeToCostumer[0], &flag, sizeof(int)) < 0){//diabazoume apo to pipe tou parent an yparxei to item pou thelei o costumer
                return 2;   //error 
            }
            else {
                read(storeToCostumer[0], &flag, sizeof(int));
            }
     
            if (flag==0){   //an flag = 0 den yparxei, an flag = 1 yparxei
                printf("To Item pou thelete den yparxei");
            }
            else{
                if (write(costumerToShop[1], &numberOfItems, sizeof(int)) < 0 ){
                    return 3;// error
                }
                else {
                    //pernei 1 item apo auto pou thelei o pelaths an exei
                }
            }
            wait(1);
        }
        close(costumerToShop[1]);
        close(storeToCostumer[0]);
    }
}

