#include<stdio.h>
#include<string.h>
#define MAX 50
#define BIGMAX 100
struct newitem{
    char name[BIGMAX];
    float price;
};
struct newlist_with_address{
    char name[BIGMAX];
    char address[BIGMAX];
};
struct newlist{
    char item[BIGMAX];
};
struct allspecial{
  char name[MAX];
  float price;
  char address[MAX];
  char restaurant_name[MAX];

};
struct order{
    int order_id;

    char user_name[MAX];
    char phone_number[MAX];
    char address[MAX];

    int item_count;

    char item_name[MAX][MAX];
    int quantity[MAX];

    int order_time;
    int delivery_time;
};
struct service_time{
    int hour;
    int min;
};
struct Food_Item{
    char name[MAX];
    float price;
    struct service_time service;
    int delivery_time;
};
struct restaurants{
    char name[MAX];
    char address[BIGMAX];
    char area[BIGMAX];

    struct Food_Item item[MAX];
    int item_count;

    struct Food_Item special_item[MAX];
    int special_item_count;

    struct Food_Item special_item_of_the_day;
    struct order o[10];
    int order_count;
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------
//restaurant Mode
void insert_item_sorted(struct Food_Item arr[], int *count, struct Food_Item newItem) {
    int i=(*count) - 1;
    while(i >= 0 && strcmp(arr[i].name, newItem.name) > 0) {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=newItem;
    (*count)++;
}
void insert_special_item_sorted(struct Food_Item arr[], int *count, struct Food_Item newItem) {
    int i=(*count) - 1;
    while(i >= 0 && strcmp(arr[i].name, newItem.name) > 0) {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=newItem;
    (*count)++;
}
void insert_restaurant(struct restaurants r,struct restaurants restaurant[], int* rest){
    int i=*rest-1;
    while(i>=0 && (strcmp(restaurant[i].name, r.name)>0 || strcmp(restaurant[i].name, r.name)==0 && strcmp(restaurant[i].address, r.address)>0)){
        restaurant[i+1]=restaurant[i];
        i--;
    }
    restaurant[i+1]=r;
    (*rest)++;
}
void add_restaurant(struct restaurants restaurant[], int*rest){
    struct restaurants r;
    printf("----------------------------------------\n");
    printf("ENTER NAME OF restaurant\n");
    printf("----------------------------------------\n");
    scanf(" %[^\n]s", r.name);
    printf("ENTER ADDRESS\n");
    printf("----------------------------------------\n");
    scanf(" %[^\n]s", r.address);
    printf("ENTER AREA\n");
    printf("----------------------------------------\n");
    scanf(" %[^\n]",r.area);
    insert_restaurant(r, restaurant,rest);
    printf("ADDED SUCCESSFULLY\n");
    printf("----------------------------------------\n");
}
void add_food_item(struct restaurants restaurant[], int*rest){
    int index=*rest;
    printf("----------------------------------------\n");
    printf("SELECT restaurant\n");
    printf("----------------------------------------\n");
    for(int i=0; i<index; i++){
        printf("(%d) %s-- %s\n", i+1, restaurant[i].name,restaurant[i].address);
    }
    int choice;
    scanf("%d", &choice);
    if(choice<=index){
         struct Food_Item f;
         printf("Enter name of food item\n");
         scanf(" %[^\n]s", f.name);
         printf("Enter price\n");
         scanf("%f", &f.price);
         printf("Enter service time ( hour : min)");
         scanf("%d %d", &f.service.hour, &f.service.min);
         printf("Enter delivery time in minutes ");
         scanf("%d", &f.delivery_time);
         insert_item_sorted(restaurant[choice-1].item,&restaurant[choice-1].item_count,f);
         printf("ADDED SUCCESFULLY\n");
    }
    else{
        printf("INVALID CHOICE");
    }
}
void add_special_item(struct restaurants restaurant[], int*rest){
    int index=*rest;
    printf("----------------------------------------\n");
    printf("SELECT restaurant\n");
    printf("----------------------------------------\n");
    for(int i=0; i<index; i++){
        printf("(%d) %s - %s\n", i+1, restaurant[i].name, restaurant[i].address);
    }
    int choice;
    scanf("%d", &choice);
    if(choice<=index){
     struct Food_Item f;
     printf("Enter name of food item\n");
     scanf(" %[^\n]s", f.name);
     printf("Enter price\n");
     scanf("%f", &f.price);
     printf("Enter service time ( hour : min)");
     scanf("%d %d", &f.service.hour, &f.service.min);
     printf("Enter delivery time");
     scanf("%d", &f.delivery_time);
     insert_special_item_sorted(restaurant[choice-1].special_item, &restaurant[choice-1].special_item_count,f);
     printf("ADDED SUCESSFULLY\n");
    }
    else{
        printf("INVALID CHOICE");
        }
    }
void set_item_of_the_day(struct restaurants restaurant[], int*rest){
     int index=*rest;
    printf("----------------------------------------\n");
    printf("SELECT restaurant\n");
    printf("----------------------------------------\n");
    for(int i=0; i<index; i++){
        printf("(%d) %s-- %s\n", i+1, restaurant[i].name, restaurant[i].address);
    }
    int choice;
    scanf("%d", &choice);
    if(choice<=index){
     struct Food_Item f;
     printf("Enter name of food item\n");
     scanf(" %[^\n]s", f.name);
     printf("Enter price\n");
     scanf("%f", &f.price);
     printf("Enter service time ( hour : min)");
     scanf("%d %d", &f.service.hour, &f.service.min);
     printf("Enter delivery time");
     scanf("%d", &f.delivery_time);
     restaurant[choice-1].special_item_of_the_day=f;
     printf("ADDED SUCESSFULLY\n");
    }
    else{
        printf("INVALID CHOICE\n");
    }
}
void delete_restaurant(struct restaurants restaurant[], int* rest) {
    if (*rest==0) {
        printf("No restaurants available to delete.\n");
        return;
    }
    for(int i=0; i<*rest; i++){
        printf("(%d) %s-- %s\n", i+1, restaurant[i].name, restaurant[i].address);
    }
    char name[MAX];
    char address[BIGMAX];
    int delete_index=-1;
    printf("----------------------------------------\n");
    printf("DELETE RESTAURANT\n");
    printf("----------------------------------------\n");
    printf("ENTER NAME: ");
    scanf(" %[^\n]s", name);
    printf("ENTER ADDRESS: ");
    scanf(" %[^\n]s", address);
    int i=0;
    while (i < *rest && delete_index==-1) {
        if (strcmp(restaurant[i].name, name) == 0 && 
            strcmp(restaurant[i].address, address) == 0) {
            delete_index=i;
        }
        i++;
    }
    if (delete_index!=-1) {
        for (int j=delete_index; j<(*rest)-1; j++) {
            restaurant[j]=restaurant[j + 1];
        }
        (*rest)--; 
        printf("\nRESTAURANT '%s' DELETED SUCCESSFULLY\n", name);
    } else {
        printf("\nERROR: RESTAURANT NOT FOUND\n");
    }
    printf("----------------------------------------\n");
}
void restaurantmode(struct restaurants restaurant[],int*rest){
    printf("----------------------------------------\n");
    printf("(*)(*)(*)(*) restaurant MODE (*)(*)(*)(*)\n");
    printf("----------------------------------------\n");
    int ch=1;
    while(ch){
    printf("(1) Add restaurant\n");    // make the 1st letter capital to add in alphabetical order
    printf("(2) Add food Item\n");
    printf("(3) Add Special Item\n");
    printf("(4) Set Item of the Day\n");
    printf("(5) Delete Restaurant\n");
    printf("(6) EXIT\n");

    printf("----------------------------------------\n");
    printf("ENTER YOUR CHOICE\n");
    printf("----------------------------------------\n");
    int choice;
    int ret=1;
    scanf("%d", &choice);
    switch(choice){
        case 1: add_restaurant(restaurant , rest);
                break;
        case 2: add_food_item(restaurant, rest);
                break;
        case 3: add_special_item(restaurant, rest);
                break;
        case 4: set_item_of_the_day(restaurant, rest);
                break;
        case 5: delete_restaurant(restaurant, rest);
                break;
        case 6: printf("EXITING RESTAURANT MODE\n");
                ch=0;
                break;
        default:printf("Not valid choice enter again please");
                break;
    }
    if(ch!=0){
    printf("DO YOU WANT TO ADD ANYTHING MORE?  \n1 for YES \nand 0 for NO\n");
    scanf("%d", &ch);
    }
}
    printf("----------------------------------------\n");
    printf("THANK YOU !\n");
    printf("----------------------------------------\n");
   return;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void add_predefined_restaurants(struct restaurants restaurant[],int*rest){

    struct restaurants r;
    struct Food_Item f;

    // 1. KFC 
    strcpy(r.name, "KFC");
    strcpy(r.address, "Eternity Mall, Sitabuldi");
    strcpy(r.area, "Sitabuldi");

    r.item_count=0;
    r.special_item_count=0;

    // Generic Items
    strcpy(f.name, "French Fries");
    f.price=79.5; f.service.hour=0; f.service.min=10; f.delivery_time=10;
    insert_item_sorted(r.item, &r.item_count, f);

    strcpy(f.name, "Burger");
    f.price=120; f.service.hour=0; f.service.min=8; f.delivery_time=10;
    insert_item_sorted(r.item, &r.item_count, f);

    strcpy(f.name, "Chicken Bucket");
    f.price=299; f.service.hour=0; f.service.min=15; f.delivery_time=10;
    insert_item_sorted(r.item, &r.item_count, f);

    // Special Items
    strcpy(f.name, "Zinger Burger");
    f.price=180; f.service.hour=0; f.service.min=12; f.delivery_time=10;
    insert_special_item_sorted(r.special_item, &r.special_item_count, f);

    strcpy(f.name, "Chicken Popcorn");
    f.price=150; f.service.hour=0; f.service.min=10; f.delivery_time=10;
    insert_special_item_sorted(r.special_item, &r.special_item_count, f);

    // Item of the Day
    strcpy(r.special_item_of_the_day.name, "Special Bucket");
    r.special_item_of_the_day.price=349;
    r.special_item_of_the_day.service.hour=0;
    r.special_item_of_the_day.service.min=0;
    r.special_item_of_the_day.delivery_time=25;

    insert_restaurant(r,restaurant,rest);

    //2. DOMINOS 
    strcpy(r.name, "Dominos");
    strcpy(r.address, "Sadar");
    strcpy(r.area, "Sadar");

    r.item_count=0;
    r.special_item_count=0;

    strcpy(f.name, "Margherita Pizza");
    f.price=199; f.service.hour=0; f.service.min=12; f.delivery_time=20;
    insert_item_sorted(r.item, &r.item_count, f);

    strcpy(f.name, "Farmhouse Pizza");
    f.price=299; f.service.hour=0; f.service.min=15; f.delivery_time=20;
    insert_item_sorted(r.item, &r.item_count, f);

    strcpy(f.name, "Garlic Bread");
    f.price=120; f.service.hour=0; f.service.min=7; f.delivery_time=20;
    insert_item_sorted(r.item, &r.item_count, f);

    strcpy(f.name, "Cheese Burst Pizza");
    f.price=350; f.service.hour=0; f.service.min=15; f.delivery_time=20;
    insert_special_item_sorted(r.special_item, &r.special_item_count, f);

    strcpy(f.name, "Burger");
    f.price=320; f.service.hour=0; f.service.min=14; f.delivery_time=20;
    insert_special_item_sorted(r.special_item, &r.special_item_count, f);

    strcpy(r.special_item_of_the_day.name, "Veg Extravaganza");
    r.special_item_of_the_day.price=340;
    r.special_item_of_the_day.service.hour=0;
    r.special_item_of_the_day.service.min=16;
    r.special_item_of_the_day.delivery_time=27;

    insert_restaurant(r, restaurant, rest);

    // ===== 3. HALDIRAMS =====
    strcpy(r.name, "Haldirams");
    strcpy(r.address, "Dharampeth");
    strcpy(r.area, "Sadar");

    r.item_count=0;
    r.special_item_count=0;

    strcpy(f.name, "Raj Kachori");
    f.price=90; f.service.hour=0; f.service.min=6; f.delivery_time=20;
    insert_item_sorted(r.item, &r.item_count, f);

    strcpy(f.name, "Chole Bhature");
    f.price=120; f.service.hour=0; f.service.min=10; f.delivery_time=20;
    insert_item_sorted(r.item, &r.item_count, f);

    strcpy(f.name, "Masala Dosa");
    f.price=110; f.service.hour=0; f.service.min=8; f.delivery_time=20;
    insert_item_sorted(r.item, &r.item_count, f);

    strcpy(f.name, "Mini Thali");
    f.price=200; f.service.hour=0; f.service.min=12; f.delivery_time=20;
    insert_special_item_sorted(r.special_item, &r.special_item_count, f);

    strcpy(f.name, "Burger");
    f.price=80; f.service.hour=0; f.service.min=5; f.delivery_time=20;
    insert_special_item_sorted(r.special_item, &r.special_item_count, f);

    strcpy(r.special_item_of_the_day.name, "Deluxe Thali");
    r.special_item_of_the_day.price=250;
    r.special_item_of_the_day.service.hour=0;
    r.special_item_of_the_day.service.min=15;
    r.special_item_of_the_day.delivery_time=20;

    insert_restaurant(r, restaurant, rest);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
//Customer Mode
void getMinTime(struct restaurants restaurant[], int*rest, char item[], int qnt){    //a
    int p1=-1,p2=-1;
    int min_time=99999999;
    int time,found=0;
    int c=0;
    for(int i=0; i<*rest; i++){
        int start=0;
        int end=restaurant[i].item_count-1;
        int mid;
        found=0;
        while(start<=end && !found){
            mid=(start+end)/2;
            if(strcmp(restaurant[i].item[mid].name, item)==0){
                time=(restaurant[i].item[mid].delivery_time)*qnt;
                if(time<min_time){
                    min_time=time;
                    p1=i;
                    p2=mid;
                }
                found=1;
                c=1;
            }
            else if(strcmp(restaurant[i].item[mid].name, item)>0){
                end=mid-1;
            }
            else start=mid+1;
        }
        start=0;
        end=restaurant[i].special_item_count-1;
        found=0;
        while(start<=end && !found){
            mid=(start+end)/2;
            if(strcmp(restaurant[i].special_item[mid].name,item)==0){
                time=(restaurant[i].special_item[mid].delivery_time)*qnt;
                  if(time<min_time){
                    min_time=time;
                    p1=i;
                    p2=mid;
                }
                found=1;
                c=1;
            }
            else if(strcmp(restaurant[i].special_item[mid].name,item)>0){
                end=mid-1;
            }
            else start=mid+1;
        }
         if(strcmp(restaurant[i].special_item_of_the_day.name, item)==0){
            time=(restaurant[i].special_item_of_the_day.delivery_time)*qnt;
             if(time<min_time){
                min_time=time;
                p1=i;
             }
             found=1;
             c=1;
          }
    }   if(c==1){
            printf("--------------------------------\n");
            printf("THE MIN TIME TAKING RESTARUNT IS-\n");
            printf("Name- %s\n", restaurant[p1].name);
            printf("Address- %s\n", restaurant[p1].address);
            printf("Time Required- %d minutes\n", min_time);
            printf("---------------------------------\n");
          }
          else{
            printf("--------------------------------\n");
            printf("NO ITEM FOUND\n");
            printf("--------------------------------\n");
          }
}
void getItemAvailability(struct restaurants restaurant[], int*rest, char item[]){    //b
     int found=0;
     int c=0;
     int count=0;
     int start,mid,end;
     for(int i=0; i<*rest; i++){
        found=0;
        start=0;
        end=restaurant[i].item_count-1;
        while(start<=end && !found){
            mid=(start+end)/2;
            if(strcmp(restaurant[i].item[mid].name, item)==0){
                count++;
                printf("----------------------(%d)-----------------------\n", count);
                printf("Name of restaurant - %s\n", restaurant[i].name);
                printf("Item Name - %s\n", item);
                printf("Price - %f Rs\n", restaurant[i].item[mid].price);
                found=1;
                c=1;
            }
            else if(strcmp(restaurant[i].item[mid].name, item)>0){
                end=mid-1;
            }
            else start=mid+1;
        }

        start=0;
        end=restaurant[i].special_item_count-1;
        found=0;
         while(start<=end && !found){
            mid=(start+end)/2;
            if(strcmp(restaurant[i].special_item[mid].name, item)==0){
                count++;
                printf("----------------------(%d)-----------------------\n", count);
                printf("Name of restaurant - %s\n", restaurant[i].name);
                printf("Item Name - %s\n", item);
                printf("Price - %f Rs\n", restaurant[i].special_item[mid].price);
                found=1;
                c=1;
            }
            else if(strcmp(restaurant[i].special_item[mid].name, item)>0){
                end=mid-1;
            }
            else start=mid+1;
        }
        if(strcmp(restaurant[i].special_item_of_the_day.name, item)==0){
        count++;
        printf("----------------------(%d)-----------------------\n", count);
        printf("Name of restaurant - %s\n", restaurant[i].name);
        printf("Item Name - %s\n", item);
        printf("Price - %f Rs\n", restaurant[i].special_item_of_the_day.price);
        c=1;
        }
    }
    if(c==0){
        printf("ITEM NOT FOUND\n");
    }
                printf("------------------------------------------------\n");
}
void placeOrder(struct restaurants restaurant[], int *rest, int*currentOrderID){     //c

    char uname[MAX], phone[MAX], addr[MAX];
    printf("ENTER USER NAME:\n");
    scanf(" %[^\n]", uname);

    printf("ENTER PHONE NUMBER:\n");
    scanf(" %[^\n]", phone);

    printf("ENTER ADDRESS:\n");
    scanf(" %[^\n]", addr);

    int n;
    printf("ENTER NUMBER OF ITEMS:\n");
    scanf("%d", &n);
    (*currentOrderID)++;
    struct order tempOrders[MAX];
    int used[MAX];
    int orderMap[MAX];
    int tcount=0;
    // initialize
    for(int i=0; i<MAX; i++){
        used[i]=0;
        orderMap[i]=-1;
    }
    // show restaurants
    printf("\nAVAILABLE RESTAURANTS:\n");
    for(int i=0; i<*rest; i++){
        printf("(%d) %s | %s\n", i+1, restaurant[i].name, restaurant[i].address);
    }
    // INPUT
    for(int i=0; i<n; i++){

        char item[MAX], rname[MAX], raddr[MAX];
        int qty;

        printf("\nITEM %d\n", i+1);

        printf("ENTER ITEM NAME:\n");
        scanf(" %[^\n]", item);

        printf("ENTER QUANTITY:\n");
        scanf("%d", &qty);

        printf("ENTER RESTAURANT NAME:\n");
        scanf(" %[^\n]", rname);

        printf("ENTER RESTAURANT ADDRESS:\n");
        scanf(" %[^\n]", raddr);

        int r_index=-1;

        // find restaurant
        for(int j=0; j<*rest; j++){
            if(r_index==-1){
                if(strcmp(restaurant[j].name, rname)==0 &&
                   strcmp(restaurant[j].address, raddr)==0){
                    r_index=j;
                }
            }
        }

        if(r_index==-1){
            printf("RESTAURANT NOT FOUND! TRY AGAIN\n");
            i--;
        }
        else{
            // create order for this restaurant if first time
            if(used[r_index]==0){

                orderMap[r_index]=tcount;

                tempOrders[tcount].order_id=*currentOrderID;

                strcpy(tempOrders[tcount].user_name, uname);
                strcpy(tempOrders[tcount].phone_number, phone);
                strcpy(tempOrders[tcount].address, addr);

                tempOrders[tcount].item_count=0;

                used[r_index]=1;
                tcount++;
            }
            int t=orderMap[r_index];
            int found=0;
            // normal items
            for(int k=0; k<restaurant[r_index].item_count; k++){
                if(found==0){
                    if(strcmp(restaurant[r_index].item[k].name, item)==0){

                        int idx=tempOrders[t].item_count;

                        strcpy(tempOrders[t].item_name[idx], item);
                        tempOrders[t].quantity[idx]=qty;
                        tempOrders[t].item_count++;
                        found=1;
                    }
                }
            }

            // special items
            for(int k=0; k<restaurant[r_index].special_item_count; k++){
                if(found==0){
                    if(strcmp(restaurant[r_index].special_item[k].name, item)==0){

                        int idx=tempOrders[t].item_count;

                        strcpy(tempOrders[t].item_name[idx], item);
                        tempOrders[t].quantity[idx]=qty;
                        tempOrders[t].item_count++;

                        found=1;
                    }
                }
            }

            // item of the day
            if(found==0){
                if(strcmp(restaurant[r_index].special_item_of_the_day.name, item)==0){

                    int idx=tempOrders[t].item_count;

                    strcpy(tempOrders[t].item_name[idx], item);
                    tempOrders[t].quantity[idx]=qty;
                    tempOrders[t].item_count++;
                    found=1;
                }
            }

            if(found==0){
                printf("ITEM NOT FOUND! TRY AGAIN\n");
                i--;
            }
            else{
                printf("ITEM ADDED\n");
            }
        }
    }
    if(n>0){
        printf("\n=================================\n");
        printf("ORDER PLACED SUCCESSFULLY\n");
        printf("ORDER ID: %d\n", *currentOrderID);
        printf("=================================\n");
    }
    int any=0;

    for(int i=0; i<*rest; i++){

        if(used[i] == 1){

            int t=orderMap[i];
            int oc=restaurant[i].order_count;

            restaurant[i].o[oc]=tempOrders[t];
            restaurant[i].order_count++;

            printf("\nRESTAURANT: %s\n", restaurant[i].name);
            printf("ADDRESS: %s\n", restaurant[i].address);

            printf("ITEMS:\n");
            for(int j=0; j<tempOrders[t].item_count; j++){
                printf("%s x %d\n",
                    tempOrders[t].item_name[j],
                    tempOrders[t].quantity[j]);
            }

            printf("---------------------------------\n");
            any=1;
        }
    }
    if(any == 0){
        printf("\nNO ORDER WAS PLACED\n");
    }
}
void getItemListInSortedOrder_by_Name(struct restaurants restaurant[], int*rest){    //d

    char r[BIGMAX];
    char a[BIGMAX];
    for(int i=0; i<*rest; i++){
    printf("(%d) Name- %s| Address- %s\n", i+1, restaurant[i].name, restaurant[i].address);
     }
    printf("ENTER RESTAURANT NAME\n");
    scanf(" %[^\n]s", r);
    printf("ENTER ADDRESS OF RESTAURANT\n");
    scanf(" %[^\n]s",a);
    int start=0;
    int end=*rest-1;
    int mid;
    int found=0,index;
    int v1,v2;
    while(start<=end && !found){
        mid=(start+end)/2;
        if(strcmp(restaurant[mid].name, r)==0){
                if(strcmp(restaurant[mid].address,a)==0){
                index=mid;
                int i=0,j=0,k=0;
                v1=restaurant[mid].item_count;
                v2=restaurant[mid].special_item_count;
                struct newlist merged_list[v1+v2+1];
                while(i<v1 && j<v2){
                    if(strcmp(restaurant[mid].item[i].name, restaurant[mid].special_item[j].name)>0){
                        strcpy(merged_list[k].item,restaurant[mid].special_item[j].name);
                        k++;
                        j++;
                    }
                    else {
                        strcpy(merged_list[k].item,restaurant[mid].item[i].name);
                        k++;
                        i++;
                    }
                }
                while(i<v1){
                    strcpy(merged_list[k].item,restaurant[mid].item[i].name);
                    k++;
                    i++;
                }
                while(j<v2){
                    strcpy(merged_list[k].item,restaurant[mid].special_item[j].name);
                    k++;
                    j++;
                }
                int index=v1+v2-1;
                while(index>=0 && strcmp(merged_list[index].item, restaurant[mid].special_item_of_the_day.name)>0){
                    merged_list[index+1]=merged_list[index];
                    index--;
                }
                strcpy(merged_list[index+1].item, restaurant[mid].special_item_of_the_day.name);
                printf("----------------------------------------------\n");
                printf("                   ITEMS                      \n");
                printf("----------------------------------------------\n");
                for(int i=0; i<v1+v2+1; i++){
                printf("(%d) %s\n",i+1,merged_list[i].item);
                }
                found=1;
            }
        else if(strcmp(restaurant[mid].address,a)>0){
            end=mid-1;
        }
        else start=mid+1;
    }
        else if(strcmp(restaurant[mid].name, r)>0) end=mid-1;
        else start=mid+1;
    }
    if(found==0){
        printf("-------------------------------------------\n");
        printf("RESTAURANT NOT FOUND OOPS!\n");
        printf("--------------------------------------------\n");
    }

}
void merge_all(struct allspecial arr[], int start, int mid, int end){
    struct allspecial dummy[end-start+1];
    int i=start,j=mid+1,k=0;
    while(i<=mid && j<=end){
        if(arr[i].price>arr[j].price){
           dummy[k++]=arr[i++];
        }
        else{
            dummy[k++]=arr[j++];
        }
    }
    while(i<=mid){
          dummy[k++]=arr[i++];
    }
    while(j<=end){
           dummy[k++]=arr[j++];
    }
    k=0;
    for(int i=start; i<=end; i++){
        arr[i]=dummy[k++];
    }
}
void merge_sort(struct allspecial arr[], int start, int end){
    if(start<end){
        int mid=(start+end)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge_all(arr,start,mid,end);
    }
}
void getItemListInSortedOrder_by_Price(struct restaurants restaurant[], int*rest){   //e
    char r[BIGMAX];
    char a[BIGMAX];
    for(int i=0; i<*rest; i++){
    printf("(%d) Name- %s| Address- %s\n", i+1, restaurant[i].name, restaurant[i].address);
     }
    printf("ENTER RESTAURANT NAME\n");
    scanf(" %[^\n]s", r);
    printf("ENTER ADDRESS OF RESTAURANT\n");
    scanf(" %[^\n]s",a);
    int start=0,end=*rest-1, mid,found=0;
    while(start<=end && !found){
        mid=(start+end)/2;
        int nm=strcmp(restaurant[mid].name, r);
        if(nm==0 && !found){
            int add=strcmp(restaurant[mid].address,a);
                if(add==0){
                    found=1;
                }
                else if(add>0){
                    end=mid-1;
                }
                else start=mid+1;
        }
        else if(nm>0){
            end=mid-1;
        }
        else start=mid+1;
    }
    if(found==0){
        printf("OOPS!, NO RESTAURANT FOUND");
    }
    else{
        int p1=restaurant[mid].item_count;
        int p2=restaurant[mid].special_item_count;
        struct allspecial all[p1+p2+1];
        int k=0;
        for(int i=0; i<p1; i++){
            strcpy(all[k].name,restaurant[mid].item[i].name);
            all[k].price=restaurant[mid].item[i].price;
            k++;
        }
        for(int i=0; i<p2; i++){
            strcpy(all[k].name,restaurant[mid].special_item[i].name);
            all[k].price=restaurant[mid].special_item[i].price;
            k++;
        } 
        strcpy(all[k].name,restaurant[mid].special_item_of_the_day.name);
        all[k].price=restaurant[mid].special_item_of_the_day.price;
        k++;
        merge_sort(all,0,k-1);
        printf("----------------------------------------------\n");
        printf("                   ITEMS                      \n");
        printf("----------------------------------------------\n");
        for(int i=0; i<k; i++){
            printf("(%d) %s | PRICE: %f Rs\n", i+1, all[i].name, all[i].price);
        }
    }
}
void merge_restaurant_list(struct restaurants list[], int l, int mid, int r){
    struct restaurants dummy[r-l+1];
    int i=l;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=r){
        if(strcmp(list[i].name, list[j].name)<0){
            dummy[k++]=list[i++];
        }
        else{
            dummy[k++]=list[j++];
        }
    }
    while(i<=mid){
        dummy[k++]=list[i++];
    }
    while(j<=r){
        dummy[k++]=list[j++];
    }
    k=0;
    for(int i=l; i<=r; i++){
        list[i]=dummy[k++];
    }
}
void mergesort_restaurant(struct restaurants list[], int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort_restaurant(list,l,mid);
        mergesort_restaurant(list,mid+1,r);
        merge_restaurant_list(list,l,mid,r);
    }
}
void getItemListInAreaSortedOrder(struct restaurants restaurant[],int*rest){         //f
    printf("ENTER AREA\n");
    char area[20];
    struct restaurants list[10];
    int count=0;
    scanf(" %[^\n]s", area);
    for(int i=0; i<*rest; i++){
        if(strcmp(restaurant[i].area, area)==0){
            list[count]=restaurant[i];
            count++;
        }
    }
    mergesort_restaurant(list, 0,count-1);
    for(int i=0; i<count; i++){
        printf("(%d) restaurant: %s\n",i+1, list[i].name);
        printf("Items:\n");
        for(int j=0; j<list[i].item_count; j++){
            printf("[%d] %s\n", j+1, list[i].item[j].name);
        }
        printf("Special Items:\n");
        for(int j=0; j<list[i].special_item_count; j++){
                printf("[%d] %s\n", j+1, list[i].special_item[j].name);
            }
        printf("Item of the Day:\n");
        printf("[1] %s\n", list[i].special_item_of_the_day.name);
        printf("------------------------------------------------------------\n");
        }
    }
void merge(struct allspecial s[],int l,int m,int r){
    struct allspecial dummy[r-l+1];
    int i=l,j=m+1,k=0;
    while(i<=m && j<=r){
        if(strcmp(s[i].name,s[j].name)<0|| strcmp(s[i].name,s[j].name)==0 && s[i].price<s[j].price){
            dummy[k++]=s[i++];
        }
        else{
            dummy[k++]=s[j++];
        }
    }
    while(i<=m){
        dummy[k++]=s[i++];
    }
    while(j<=r){
        dummy[k++]=s[j++];
    }
    k=0;
    for(int i=l; i<=r; i++){
        s[i]=dummy[k++];
    }
}
void mergesort(struct allspecial s[], int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(s,l,m);
        mergesort(s,m+1,r);
        merge(s,l,m,r);
    }
}
void getAllSpecialItemListinSortedOrder(struct restaurants restaurant[], int*rest){  //g
    int n;
    printf("ENTER NO. OF restaurant TO ENTER\n");
    scanf("%d", &n);

    for(int i=0; i<*rest; i++)
    {
    printf("(%d) Name- %s| Address- %s\n", i+1, restaurant[i].name, restaurant[i].address);
     }
    int x=0;
    int found=0;
    struct newlist_with_address l[n];
    printf("ENTER THE restaurants\n");
    for(int i=0; i<n; i++){
        printf("restaurant (%d)\n", i+1);
        scanf(" %[^\n]s", l[i].name);
        printf("ADDRESS OF THIS restaurant :\n");
        scanf(" %[^\n]s", l[i].address);
    }
    struct allspecial s[BIGMAX];
    for(int i=0; i<*rest; i++){
        found=0;
        for(int j=0; j<n && !found; j++){
            if(strcmp(l[j].name, restaurant[i].name)==0 && strcmp(l[j].address, restaurant[i].address)==0){
                found=1;
            }
        }
        if(found==1){
            for(int j=0; j<restaurant[i].special_item_count; j++){
                strcpy(s[x].name, restaurant[i].special_item[j].name);
                s[x].price=restaurant[i].special_item[j].price;
                strcpy(s[x].restaurant_name, restaurant[i].name);
                strcpy(s[x].address,restaurant[i].address);
                x++;
            }
        }
    }
    //sort the items
    mergesort(s,0,x-1);

    printf("\n-------SORTED SPECIAL ITEMS FROM SELECTED LIST-------\n");
    for(int i=0; i < x; i++) {
        printf("(%d) Item: %s | Price: %f | restaurant name : %s | Address: %s\n", i+1,s[i].name, s[i].price, s[i].restaurant_name, s[i].address);
    }
    if(x==0){
        printf("ERROR\n");
    }
} 
void getItemofDayListinSortedOrder(struct restaurants restaurant[], int*rest){       //h
    char area[MAX];
    printf("ENTER THE AREA:\n");
    scanf(" %[^\n]", area);
    struct allspecial s[MAX];
    int count=0;
    for(int i=0; i<*rest; i++){
        if(strcmp(restaurant[i].area, area)==0){
            strcpy(s[count].restaurant_name, restaurant[i].name);
            strcpy(s[count].address, restaurant[i].address);
            s[count].price=restaurant[i].special_item_of_the_day.price;
            strcpy(s[count].name,restaurant[i].special_item_of_the_day.name);
            count++;
        }
    }
    if(count==0){
        printf("NO restaurant FOUND IN THAT AREA !\n");
    }
    else{
        mergesort(s,0,count-1);
        printf("\nSORTED MENU LIST FOR AREA: %s\n",area);
        for(int i=0; i<count; i++) {
            printf("--------------------------(%d)------------------------------\n",i+1);
            printf("RESTAURANT: %s\nItem of the Day - %s\nItem of Day Price: %f\n",s[i].restaurant_name,s[i].name, s[i].price);
        }
        printf("\n");
    }
}
int binarySearch(struct Food_Item arr[], int n, char key[]) {
    int low=0, high=n - 1;
    int found=0;

    while(low <= high && found == 0){
        int mid=(low + high) / 2;
        int cmp=strcmp(arr[mid].name, key);

        if(cmp == 0){
            found=1;
        }
        else if(cmp > 0){
            high=mid - 1;
        }
        else{
            low=mid + 1;
        }
    }

    return found;
}
int isPresent(struct restaurants r, char item[]) {
    int found=0;

    // normal items
    if(binarySearch(r.item, r.item_count, item)==1){
        found=1;
    }
    // special items
    if(found==0 && binarySearch(r.special_item, r.special_item_count, item)==1){
        found=1;
    }
    // item of the day
    if(found==0 && strcmp(r.special_item_of_the_day.name, item)==0){
        found=1;
    }
    return found;
}
void getCommonItem(struct restaurants restaurant[], int *rest) {                     //i
    int n;
    printf("ENTER NUMBER OF RESTAURANTS:\n");
    scanf("%d", &n);

    char names[n][MAX];
    int index[n];
    //display
    for(int i=0; i<*rest; i++){
        printf("(%d) %s\n", i+1, restaurant[i].name);
    }
    // input names
    for(int i=0; i<n; i++){
        printf("ENTER RESTAURANT NAME %d:\n", i+1);
        scanf(" %[^\n]", names[i]);
        index[i]=-1;
        for(int j=0; j<*rest; j++){
            if(strcmp(names[i], restaurant[j].name) == 0){
                index[i]=j;
            }
        }
        if(index[i]==-1){
            printf("RESTAURANT NOT FOUND\n");
            return;
        }
    }

    char common[100][MAX];
    int count=0;
    int base=index[0];
    // NORMAL ITEMS 
    for(int i=0; i<restaurant[base].item_count; i++){
        char curr[MAX];
        strcpy(curr, restaurant[base].item[i].name);
        int ok=1;
        for(int j=1; j<n; j++){
            if(isPresent(restaurant[index[j]], curr) == 0){
                ok=0;
            }
        }
        if(ok == 1){
            strcpy(common[count], curr);
            count++;
        }
    }
    // SPECIAL ITEMS
    for(int i=0; i<restaurant[base].special_item_count; i++){

        char curr[MAX];
        strcpy(curr, restaurant[base].special_item[i].name);

        int ok=1;

        for(int j=1; j<n; j++){
            if(isPresent(restaurant[index[j]], curr) == 0){
                ok=0;
            }
        }
        if(ok==1){
            strcpy(common[count], curr);
            count++;
        }
    }
    //ITEM OF THE DAY
    char curr[MAX];
    strcpy(curr, restaurant[base].special_item_of_the_day.name);

    int ok=1;

    for(int j=1; j<n; j++){
        if(isPresent(restaurant[index[j]], curr) == 0){
            ok=0;
        }
    }

    if(ok == 1){
        strcpy(common[count], curr);
        count++;
    }

    //SORT
    for(int i=0; i<count-1; i++){
        for(int j=i+1; j<count; j++){
            if(strcmp(common[i], common[j]) > 0){
                char temp[MAX];
                strcpy(temp, common[i]);
                strcpy(common[i], common[j]);
                strcpy(common[j], temp);
            }
        }
    }

    // -------- PRINT --------
    if(count == 0){
        printf("NO COMMON ITEMS FOUND\n");
    }
    else{
        printf("\n====== COMMON ITEMS ======\n");

        for(int i=0; i<count; i++){
            printf("\nITEM: %s\n", common[i]);

            for(int j=0; j<n; j++){
                int r=index[j];

                // normal
                for(int x=0; x<restaurant[r].item_count; x++){
                    if(strcmp(restaurant[r].item[x].name, common[i]) == 0){
                        printf("  %s: %f Rs\n", restaurant[r].name, restaurant[r].item[x].price);
                    }
                }
                // special
                for(int x=0; x<restaurant[r].special_item_count; x++){
                    if(strcmp(restaurant[r].special_item[x].name, common[i]) == 0){
                        printf("  %s: %f Rs\n", restaurant[r].name, restaurant[r].special_item[x].price);
                    }
                }
                // item of the day
                if(strcmp(restaurant[r].special_item_of_the_day.name, common[i]) == 0){
                    printf("  %s: %f Rs\n", restaurant[r].name, restaurant[r].special_item_of_the_day.price);
                }
             }
        }
    }
}
void getAllUniqueItem(struct restaurants restaurant[], int*rest){                    //j

    int n;
    printf("ENTER NUMBER OF RESTAURANTS:\n");
    scanf("%d",&n);

    char names[n][MAX];
    int index[n];

    for(int i=0;i<n;i++){
        printf("ENTER RESTAURANT NAME %d:\n",i+1);
        scanf(" %[^\n]",names[i]);
        index[i]=-1;

        for(int j=0;j<*rest;j++){
            if(strcmp(names[i],restaurant[j].name)==0){
                index[i]=j;
            }
        }
        if(index[i]==-1){
            printf("RESTAURANT NOT FOUND\n");
            return;
        }
    }

    struct allspecial unique[200];
    int count=0;

    for(int i=0;i<n;i++){

        int r=index[i];

        // NORMAL ITEMS
        for(int j=0;j<restaurant[r].item_count;j++){

            char curr[MAX];
            strcpy(curr,restaurant[r].item[j].name);

            int unique_flag=1;

            for(int k=0;k<n;k++){
                if(k!=i){
                    if(isPresent(restaurant[index[k]],curr)==1){
                        unique_flag=0;
                    }
                }
            }

            if(unique_flag==1){
                strcpy(unique[count].name,curr);
                unique[count].price=restaurant[r].item[j].price;
                strcpy(unique[count].restaurant_name,restaurant[r].name);
                strcpy(unique[count].address,restaurant[r].address);
                count++;
            }
        }

        // SPECIAL ITEMS
        for(int j=0;j<restaurant[r].special_item_count;j++){

            char curr[MAX];
            strcpy(curr,restaurant[r].special_item[j].name);

            int unique_flag=1;

            for(int k=0;k<n;k++){
                if(k!=i){
                    if(isPresent(restaurant[index[k]],curr)==1){
                        unique_flag=0;
                    }
                }
            }

            if(unique_flag==1){
                strcpy(unique[count].name,curr);
                unique[count].price=restaurant[r].special_item[j].price;
                strcpy(unique[count].restaurant_name,restaurant[r].name);
                strcpy(unique[count].address,restaurant[r].address);
                count++;
            }
        }

        // ITEM OF THE DAY
        char curr[MAX];
        strcpy(curr,restaurant[r].special_item_of_the_day.name);

        int unique_flag=1;

        for(int k=0;k<n;k++){
            if(k!=i){
                if(isPresent(restaurant[index[k]],curr)==1){
                    unique_flag=0;
                }
            }
        }
        if(unique_flag==1){
            strcpy(unique[count].name,curr);
            unique[count].price=restaurant[r].special_item_of_the_day.price;
            strcpy(unique[count].restaurant_name,restaurant[r].name);
            strcpy(unique[count].address,restaurant[r].address);
            count++;
        }
    }
    // SORT
    for(int i=0;i<count-1;i++){
        for(int j=i+1;j<count;j++){
            if(strcmp(unique[i].name,unique[j].name)>0 ||
              (strcmp(unique[i].name,unique[j].name)==0 && unique[i].price>unique[j].price)){

                struct allspecial temp=unique[i];
                unique[i]=unique[j];
                unique[j]=temp;
            }
        }
    }
    // PRINT
    if(count==0){
        printf("NO UNIQUE ITEMS FOUND\n");
        return;
    }
    printf("\n====== UNIQUE ITEMS ======\n");
    for(int i=0;i<count;i++){
        printf("ITEM: %s | PRICE: %f Rs\n",unique[i].name,unique[i].price);
        printf("RESTAURANT: %s\n",unique[i].restaurant_name);
        printf("ADDRESS: %s\n",unique[i].address);
        printf("-----------------------------------\n");
    }
}
void customermode(struct restaurants restaurant[],int*rest){                         
    int choice;
    int currentOrderID=0;
    printf("-------------------------------------------\n");
    printf("(*)(*)(*)(*)(*)CUSTOMER MODE(*)(*)(*)(*)(*)\n");
    printf("-------------------------------------------\n");
    int ch=1;
    while(ch){
        printf("ENTER YOUR CHOICE\n");
        printf("(1) Get Minimum Delivery Time\n");         //getMinTime();            //done
        printf("(2) Get Item Availability\n");             //getItemAvailabilty();    //done
        printf("(3) Place Order\n");                       //placeorder();
        printf("(4) Get Item List (Sorted By Name)\n");    //getItemListInSortedOrder by name();   //done
        printf("(5) Get Item list (Sorted By Price)\n");   //getItemListInSortedOredr by price();  //done
        printf("(6) Get Item List By Area\n");             //getItemListInAreaSortedOrder();               //done
        printf("(7) Get All Special Item List In Sorted Order\n");  //getAllSpecialItemListinSortedOrder();  //done
        printf("(8) Get Item Of The Day List In sorted Order By Name\n"); //getItemofDayListinSortedOrder()    //done
        printf("(9) Get All common items\n");         //getCommonItem() //done //
        printf("(10) Get All unique Items\n");        //getalluniqueitems //done 
        printf("(11) EXIT\n");

        //more functions to write
        for(int i=0; i<*rest; i++){
            restaurant[i].order_count=0;
        }
        int qnt;
        char item[MAX];
        char r[MAX];
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("ENTER FOOD ITEM\n");
                    scanf(" %[^\n]s", item);
                    printf("ENTER QUANTITY\n");
                    scanf("%d", &qnt);
                    getMinTime(restaurant,rest,item,qnt);
                    break;

            case 2: printf("ENTER FOOD ITEM\n");
                    scanf(" %[^\n]s", item);
                    getItemAvailability(restaurant,rest,item);
                    break;

            case 3: placeOrder(restaurant,rest, &currentOrderID);
                    break;

            case 4: getItemListInSortedOrder_by_Name(restaurant,rest);
                    break;

            case 5: getItemListInSortedOrder_by_Price(restaurant,rest);
                    break;

            case 6: getItemListInAreaSortedOrder(restaurant,rest);
                    break; 
            
            case 7: getAllSpecialItemListinSortedOrder(restaurant, rest);
                    break;

            case 8: getItemofDayListinSortedOrder(restaurant,rest);
                    break;

            case 9: getCommonItem(restaurant, rest);
                    break; 
            
            case 10: getAllUniqueItem(restaurant, rest);
                    break;
            case 11: printf("EXISTING RESTAURANT MODE\n");  
                     ch=0;
                     break;
            default:printf("INVALID INPUT\n");
                     break;
        }
        if(ch!=0){
            printf("DO YOU WANT TO ADD ANYTHING ELSE? \n 1 FOR YES\n 0 FOR NO\n");
            scanf("%d", &ch);
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void view(struct restaurants restaurant[], int*rest){
    int choice;
    printf("restaurant LIST\n");
    for(int i=0; i<*rest; i++){
    printf("(%d) Name- %s| Address- %s\n", i+1, restaurant[i].name, restaurant[i].address);
     } 
    printf("ENTER THE CHOICE\n");
    scanf("%d", &choice);
    printf("=================================MENU====================================\n");
    printf("ITEMS\n");
    for(int i=0; i<restaurant[choice-1].item_count; i++){
        printf("(%d) %s | Price- %f Rs\n", i+1,restaurant[choice-1].item[i].name, restaurant[choice-1].item[i].price);
    }
    printf("---------------------------------------------------------------------------\n");
    printf("SPECIAL ITEMS\n");
    for(int i=0; i<restaurant[choice-1].special_item_count; i++){
        printf("(%d) %s | Price- %f Rs\n", i+1,restaurant[choice-1].special_item[i].name, restaurant[choice-1].special_item[i].price);
    }
    printf("---------------------------------------------------------------------------\n");
    printf("SPECIAL ITEM OF THE DAY\n");
    printf("(1) %s | Price- %f Rs\n", restaurant[choice-1].special_item_of_the_day.name, restaurant[choice-1].special_item_of_the_day.price);
    printf("---------------------------------------------------------------------------\n");
}
 int main(){
    struct restaurants restaurant[20]; // array of strcutures of restaurant
    int restaurant_count=0;  
    int*rest=&restaurant_count;     //to count number of restaurants 
    int choice;
    add_predefined_restaurants(restaurant,rest);

        printf("(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)\n");
        printf("(*)             ONLINE FOOD MANAGEMENT SYSTEM               (*)\n");
        printf("(*)                     BY SAHIL SONI                       (*)\n");
        printf("(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)-(*)\n");
        int ch=1;
        while(ch){
            printf("WHATS ON YOUR MIND?\n");
            printf("(1) Customer Mode\n(2) restaurant Mode\n(3) View all\n(4) Exit\n");
            printf("----------------------------------------------------------------\n");
            scanf("%d", &choice);
            switch(choice){
                case 1: customermode(restaurant , rest);
                        break;
                case 2: restaurantmode(restaurant, rest);
                        break;
                case 3: view(restaurant,rest);
                        break;
                case 4: printf("THANKS!! VISIT AGAIN SOON\n");
                        ch=0;
                        break;
                default:printf("INVALID CHOICE TRY AGAIN!!\n");
                        break;
            }
            if(ch!=0){
            printf("DO YOU WANT TO ADD SOMETHING OR ORDER SOMETHING?\n1 FOR YES\n0 FOR NO\n");
            scanf("%d", &ch);
            }
    }
        if(ch==0){
            printf("THANK YOU ! VISIT AGAIN SOON\n");
        }
        return 0;
    }
