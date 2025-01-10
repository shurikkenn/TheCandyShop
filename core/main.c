//MAIN FILE



// ░█▀▀░█▀█░█▀█░█▀▄░█░█░░░█▀▀░█░█░█▀█░█▀█
// ░█░░░█▀█░█░█░█░█░░█░░░░▀▀█░█▀█░█░█░█▀▀
// ░▀▀▀░▀░▀░▀░▀░▀▀░░░▀░░░░▀▀▀░▀░▀░▀▀▀░▀░░



#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "libs/lib.h"

int main(void){
    //arxikopoioume tous agwgous
    int customerToShop[2],storeToCustomer[2];//[0]= read, [1]= write
    Product catalog[INVENTORY_SIZE]; //o katalogos me ta proionta

    //paraloiloi pinakes me ton catalog pou tha xrhsimopoithoune sth telikh anafora ana proion
    int requests_per_item[INVENTORY_SIZE], sales_per_item[INVENTORY_SIZE], clients_not_subsered[INVENTORY_SIZE];
    int total_requests, total_succesfull, total_failed, revenue = 0; //loipoi metrites TBD
    pid_t pid = fork();
    if(pid>=0){
        if(pid!=0){ //parent process
            printf("[*] initiate the catalog\n");
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

            close(customerToShop[1]);
            close(storeToCustomer[0]);
            int itemWanted_p; //o arithmos tou proiontos ston katalogo
            /* ELENXOS GIA TH DIATHESIMOTHTA */
            //diabazei to antikeimeno pou thelei o pelaths kai to tou stelnei thn apanthsh an yparxei meso ths flag
            int flag_p; //(0=error, 1==succsess)
            for (int i = 0; i<2; i++){
                total_requests++;
                read(customerToShop[0],&itemWanted_p, sizeof(int));
                Product temp_P; //ftoiaxnoume ena prosorino antikeimeno 
                temp_P = catalog[itemWanted_p]; //to antigrafoume sto temp
                if (temp_P.item_count >0){ 
                        //an yparxei se diathesimotita
                        temp_P.item_count--; //meiwnei to apothema kata 1
                        catalog[itemWanted_p]=temp_P; //to ksanavazoume ston katalogo
                        flag_p = 1;
                        write(storeToCustomer[1], &flag_p ,sizeof(int)); //enhmerwnoume th diergasia oti egine epitixhs h agora
                        requests_per_item[itemWanted_p]+=1; //arithmos etoimatwn gia agora
                        sales_per_item[itemWanted_p]+=1; //arithmos polhsewn
                        total_succesfull++;
                }
                else {
                    //den uparxei se diathesimothta
                    total_failed++;
                    flag_p = 0;
                    clients_not_subsered[itemWanted_p]+=1;
                    write(storeToCustomer[1], &flag_p ,sizeof(int));
                }
                sleep(1);
        }

            
        } else { //child proccess
            int itemWanted_c;
            close(customerToShop[0]);
            close(storeToCustomer[1]);
            //to flag edw xrhsimopoiete gia to antistixo flag sth parent
            int flag_c; //(0=error, 1==succsess)
            /* H PARAGKELIA */
            for (int i=0; i<2; i++){
                //arxika theloume ton arithmo tou proiontos ston katalogo apto 1 ews sto 20
                srand(time(NULL));
                itemWanted_c = (rand() % 20) + 1; //o arithmos tou proiontos ston katalogo

                // stelnoume ton arithmo tou item pou thelei o pelaths sto parent process
                write(customerToShop[1], &itemWanted_c, sizeof(int));

                //diabazoume apo to pipe tou parent an yparxei to item pou thelei o costumer
                if (read(storeToCustomer[0], &flag_c, sizeof(int)) < 0){ //sfalma kata ti th metafora dedomenon sto pipe
                    perror("\n[!] error at inter-process communication");
                    exit(1);
                } else if(read(storeToCustomer[0], &flag_c, sizeof(int)) == 0){
                    //TBD
                }
                sleep(1);
            }
            close(customerToShop[1]);
            close(storeToCustomer[0]);
        }
    } else {
        //fork failed
        perror("\n[!] error with fork()");
        exit(1);
    }
    //prints report per item in the catalog]
    printf("\n\t\treports per item");
    printf("\n Num on Catalog | Requests | Sales | Clients not served\n");
    for(int ii=0;ii<INVENTORY_SIZE;ii++){
        printf("%d)", ii);
        printf("\t\t%d", requests_per_item[ii]);
        printf("\t%d", sales_per_item[ii]);
        printf("\t%d", clients_not_subsered[ii]);
        printf("\n");
    }
    printf("\n------------------");

    //prints out the final complete report (see lib.c file)
    final_report(total_requests, total_succesfull, total_failed, revenue);


    return EXIT_SUCCESS;
}

//-------TBD---------q
