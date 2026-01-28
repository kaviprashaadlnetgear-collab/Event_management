#include<stdio.h>

#include "EventHandler.h"

int main(){

    int mod_size,event_size;

    char mod[5][20]={"Notification","Y","Z","P","Q"};

    mod_size=5;

    char event[5][20]={"Event1","Event2","Event3","Event4","Event5"};

    event_size=5;



    int active_mod[mod_size];

    int active_mod_ct=0;

    int active_event_ct=0;

    int active_event[event_size];

    printf("\n AVailable Modules \n");

    for(int i=0;i<mod_size;i++){

        printf("%d.%s\n",i,mod[i]);

    }

    printf("Enter no of modules need to select:");

    int n_mod;

    scanf("%d",&n_mod);

    printf("\nSelect the module\n");

    int j=0;

    for(int i=0;i<n_mod;i++){

        int k;

        printf("Enter the choice:");

        scanf("%d",&k);

        if(k>=0 && k<mod_size){

            active_mod[j]=k;

            printf("Module %s is enabled\n",mod[k]);

            j++;



        }

        else{

            printf("invalid input");

            i=i-1;

        }

    }

    active_mod_ct=j;

    printf("\n AVailable Events \n");

    for(int i=0;i<mod_size;i++){

        printf("%d.%s\n",i,event[i]);

    }

    printf("Enter no of events need to select:");

    scanf("%d",&n_mod);

    printf("\nSelect the event\n");

    j=0;

    for(int i=0;i<n_mod;i++){

        int k;

        printf("Enter the choice:");

        scanf("%d",&k);

        if(k>=0 && k<event_size){

            active_event[j]=k;

            printf(" %s is enabled\n",event[k]);

            j++;



        }

        else{

            printf("invalid input");

            i=i-1;

        }

    }

    active_event_ct=j;

    printf("         Printing you selected modules          \n");

    for(int i=0;i<active_mod_ct;i++){

        printf("%s\n",mod[active_mod[i]]);



    }

    printf("         Printing your selected events           \n");

    for(int i=0;i<active_event_ct;i++){

        printf("%s\n",event[active_event[i]]);



    }

    int subscribe[active_mod_ct][active_event_ct];

    for(int i=0;i<active_mod_ct;i++){

        printf("Select the event to subscribe to this module %s",mod[active_mod[i]]);

        printf("\nAvailbale Event if yes enter 1 ,no-> 0\n  ");

        for(int p=0;p<active_event_ct;p++)

        {

            printf("%s\t",event[active_event[p]]);

            printf("Enetr your choice");

            scanf("%d",&subscribe[i][p]);

        }



    }

     for(int i=0;i<active_mod_ct;i++){

        for(int p=0;p<active_event_ct;p++)

        {

            printf("%d\t",subscribe[i][p]);

        }

        printf("\n");



    }





    printf("\n \nTriggering an event\n \n");

    int stat=1;

     int eNo;

    while(stat){

        printf("Availabe Event\n");

        for(int i=0;i<active_event_ct;i++){

            printf("%d . %s\n",i,event[active_event[i]]);



        }

        printf("Enter the event no to trigger or -1 to leave:-");

        scanf("%d",&eNo);

        if(eNo==-1){

            stat=0;

            continue;

        }

        else if(eNo >=0 && eNo<active_event_ct){

            for(int i=0;i<active_mod_ct;i++){

                if(subscribe[i][eNo]==1){

                    int mod_idx=active_mod[i];

                    module_trigger(mod_idx);



                }

            }

        }

        else{

            printf("Invalid input");

        }







        

    }



}



