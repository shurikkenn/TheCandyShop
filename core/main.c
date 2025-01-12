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
    intro_msg();
    srand(time(NULL)); //gia th tyxaiothta ths epiloghs
    //arxikopoioume tous agwgous
    int customerToShop[2],storeToCustomer[2];//[0]= read, [1]= write
    if (pipe(customerToShop) == -1 || pipe(storeToCustomer) == -1) {
        perror("pipe failed to innitiate");
        exit(EXIT_FAILURE);
    }   
    Product catalog[INVENTORY_SIZE]; //o katalogos me ta proionta
    //gemizoume ton katalogo
    printf("[*] initiate the catalog\n");
    for(int i=0;i<=INVENTORY_SIZE;i++){
        Product newproduct;
        float innit_price;
        char innit_desc[MAX_DESC_SIZE];
        printf("[*] please fill the information for the product number %d...\n", i);
        printf("\nprice -> ");
        scanf("%f", &innit_price);
        catalog[i] = fill_catalog(innit_price, innit_desc);
    }

    //paraloiloi pinakes me ton catalog pou tha xrhsimopoithoune sth telikh anafora ana proion
    int requests_per_item[INVENTORY_SIZE], sales_per_item[INVENTORY_SIZE], clients_not_subsered[INVENTORY_SIZE];
    int total_requests = 0, total_succesfull = 0, total_failed = 0, revenue = 0; //loipoi metrites TBD
    pid_t client_pid; //tha xrhsimopoithei gia ta diadoxika forks twn pelatwn
    pid_t pid = fork();

    //arxikopoioume tous pinakes prin tis epanalhpseis
    memset(requests_per_item, 0, sizeof(requests_per_item));
    memset(sales_per_item, 0, sizeof(sales_per_item));
    memset(clients_not_subsered, 0, sizeof(clients_not_subsered));

    if(pid>=0){
        if(pid>0){ //parent process
            close(customerToShop[1]);
            close(storeToCustomer[0]);
            int itemWanted_p; //o arithmos tou proiontos ston katalogo
            /* ELENXOS GIA TH DIATHESIMOTHTA */
            //diabazei to antikeimeno pou thelei o pelaths kai to tou stelnei thn apanthsh an yparxei meso ths flag
            int flag_p; //(0=purchase not complete, >0==succsess and price)
            total_requests++;
            read(customerToShop[0],&itemWanted_p, sizeof(int));
            Product temp_P; //ftoiaxnoume ena prosorino antikeimeno 
            temp_P = catalog[itemWanted_p]; //to antigrafoume sto temp

            if (temp_P.item_count >0){ 
                    //an yparxei se diathesimotita
                    temp_P.item_count--; //meiwnei to apothema kata 1
                    catalog[itemWanted_p]=temp_P; //to ksanavazoume ston katalogo
                    flag_p = temp_P.price;
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
        

            
        } else if(pid==0) {
            //child proccess
            int itemWanted_c, temp_prices = 0;
            int p_results;

            close(customerToShop[0]);
            close(storeToCustomer[1]);
            //to flag edw xrhsimopoiete gia to antistixo flag sth parent
            int flag_c; //(0=error, 1==succsess)
            
            /* H PARAGKELIA */
            for(int pelates=0;pelates<5;pelates++){
                if((client_pid = fork()) == 0){
                    for (int i=0; i<10; i++){ //kathe loupa einai enas mia paragkelia
                        for(int j=0;j<2;j++){ //kathe paragkelia exei 2 items
                            //arxika theloume ton arithmo tou proiontos ston katalogo apto 1 ews sto 20
                            itemWanted_c = (rand() % 20) + 1; //o arithmos tou proiontos ston katalogo

                            // stelnoume ton arithmo tou item pou thelei o pelaths sto parent process
                            write(customerToShop[1], &itemWanted_c, sizeof(int));
                        }
                        p_results = read(storeToCustomer[0], &flag_c, sizeof(int));
                        //diabazoume apo to pipe tou parent an yparxei to item pou thelei o costumer
                        if (p_results < 0){ //sfalma kata ti th metafora dedomenon sto pipe
                            perror("\n[!] error at inter-process communication");
                            exit(1);
                        } else if(p_results == 0){
                            if(flag_c==0){
                                printf("Products unavailable, requests failed");
                            } else if(flag_c>0){
                                printf("Purchase complete, your total is: %d", temp_prices);
                            } else{
                                perror("invalid return flag...");
                                exit(1);
                            }
                        }
                        sleep(1);
                    }
                } else{
                    perror("failed to create a fork for the orders");
                    exit(1);
                }

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

//---------EOF--------
