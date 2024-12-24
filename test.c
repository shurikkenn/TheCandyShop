#include <stdio.h>


int main (){
    int id = fork();
    int costumerToShop[2],storeToCostumer[2];//pipes, [0]= read, [1]= write
    if (id != 0){ //Parent process
        //ftiaxnoume to catalog

    }
    else{ //Child process
        //Ftiaxnoume tis paragkelies
        printf("Ti item thelete na agorasete?\n");
        char itemWanted[];
        scanf("%s",&itemWanted);
        write(costumerToShop[1], &itemWanted, sizeof(char) * sizeof(itemWanted));// stelnoume to name tou item pou thelei o pelaths sto parent process
        close(costumerToShop[1]);
        int flag;
        if (read(storeToCostumer[0], &flag, sizeof(int)) < 0){//diabazoume apo to pipe tou parent an yparxei to item pou thelei o costumer
            return 2;   //error has occured
        }
        else {
            read(storeToCostumer[0], &flag, sizeof(int));
            }
        close(storeToCostumer[0]);
        if (flag==0){
            printf("To Item pou thelete den yparxei");
        }
        else{

        }
        //an flag = 0 den yparxei, an flag = 1 yparxei

    }
}

