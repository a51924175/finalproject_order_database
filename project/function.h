#include"import.h"

//賣家刪除商品 完成
void DEL_product(product_for_sell** head, char* product_name) {
    if (*head == NULL) {
        printf("there is no any product !\n");
        return;
    }

    if (strcmp((*head)->product_name_sell, product_name) == 0) {
        product_for_sell* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    product_for_sell* cur = *head;
    product_for_sell* prev = NULL;
    while (cur != NULL) {
        if (strcmp(cur->product_name_sell, product_name) == 0) {
            prev->next = cur->next;
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("product not found !\n");
}

//賣家以鍵盤新增商品 完成
void seller_add_stdin(product_for_sell** head ){
    char seller_add_by_stdin[20]={'\0'};
    while(strstr(seller_add_by_stdin,"!exit")==NULL){
        printf("---------------\n");
        printf("please enter the name of the product you want\n");
        printf("enter ""!exit"" to quit add section\n");
        printf("---------------\n");
        scanf("%s",seller_add_by_stdin);
        if(strstr(seller_add_by_stdin,"!exit")!=NULL){
            break;
        }

        float seller_add_by_stdin_per_price;
        printf("please enter the price of the product\n");
        scanf(" %f",&seller_add_by_stdin_per_price);

        int seller_add_by_stdin_amount;
        printf("please enter the amount you want to add\n");
        scanf(" %d",&seller_add_by_stdin_amount);

        product_for_sell *tmp=*head;
        int is_name_already=0 , is_price_match=0;
        while(tmp!=NULL){
            if(strstr(seller_add_by_stdin,tmp->product_name_sell)!=NULL && strlen(seller_add_by_stdin)==strlen(tmp->product_name_sell)){
                is_name_already=1;
                if(seller_add_by_stdin_per_price==tmp->product_price_sell){
                    is_price_match=1;
                    tmp->product_amount_sell+=seller_add_by_stdin_amount;
                    printf("the amount of %s have been add %d\n",seller_add_by_stdin,seller_add_by_stdin_amount);
                    break;
                }
                else{
                    is_price_match=0;
                    printf("there is already the product %s\n",seller_add_by_stdin);
                    break;
                }
            }
            tmp=tmp->next;
        }
        if(is_name_already==1){
            continue;
        }
        tmp=*head;
        product_for_sell *cur =(product_for_sell*)malloc(sizeof(product_for_sell));
        strcpy(cur->product_name_sell,seller_add_by_stdin);
        cur->next=NULL;
        cur->product_price_sell=seller_add_by_stdin_per_price;
        cur->product_amount_sell=seller_add_by_stdin_amount;

        if(*head==NULL){
            *head=cur;
        }

        else{
            while(tmp->next!=NULL){
                tmp=tmp->next;
            }
            tmp->next=cur;
            tmp=tmp->next;
        } 
    }
}

//賣家以file input 新增商品 完成
void seller_add_fileIO(product_for_sell** head,char* filename){
    FILE *seller_add_from_file = fopen(filename,"r");
    if(seller_add_from_file==NULL){
        printf("file : %s not found !\n",filename);
        return;
    }
    else{
        char getspace[10];
        fgets(getspace,1,seller_add_from_file);
        while(!feof(seller_add_from_file)){
            product_for_sell *tmp=*head;
            char seller_add_by_file[20];
            float seller_add_by_file_per_price;
            int seller_add_by_file_amount;
            fscanf(seller_add_from_file,"%s %f %d",seller_add_by_file,&seller_add_by_file_per_price,&seller_add_by_file_amount);
            int is_name_already=0 , is_price_match=0;
            while(tmp!=NULL){
                if(strstr(seller_add_by_file,tmp->product_name_sell)!=NULL && strlen(seller_add_by_file)==strlen(tmp->product_name_sell)){
                    is_name_already=1;
                    if(seller_add_by_file_per_price==tmp->product_price_sell){
                        is_price_match=1;
                        tmp->product_amount_sell+=seller_add_by_file_amount;
                        printf("the amount of %s have been add %d\n",seller_add_by_file,seller_add_by_file_amount);
                        break;
                    }
                    else{
                        is_price_match=0;
                        printf("there is already the product %s\n",seller_add_by_file);
                        break;
                    }
                }
                tmp=tmp->next;
            }
            if(is_name_already==1){
                continue;
            }
            tmp=*head;
            product_for_sell *cur =(product_for_sell*)malloc(sizeof(product_for_sell));
            strcpy(cur->product_name_sell,seller_add_by_file);
            cur->next=NULL;
            cur->product_price_sell=seller_add_by_file_per_price;
            cur->product_amount_sell=seller_add_by_file_amount;

            if(*head==NULL){
                *head=cur;
            }

            else{
                while(tmp->next!=NULL){
                    tmp=tmp->next;
                }
                tmp->next=cur;
                tmp=tmp->next;
            }
            
        }
    }
    fclose(seller_add_from_file);
}

//取得現在時間 完成
void getTime(char *timeget) {
    time_t time_ptr;
    struct tm *tmp_ptr = NULL;
    int day, hour, minute, sec;

    time(&time_ptr);
    tmp_ptr = localtime(&time_ptr);

    day = tmp_ptr->tm_mday;
    hour = tmp_ptr->tm_hour;
    minute = tmp_ptr->tm_min;
    sec = tmp_ptr->tm_sec;

    if (day >= 10) {
        int ten_num;
        ten_num = day / 10;
        day %= 10;
        timeget[0] = ten_num + '0';
        timeget[1] = day + '0';
    } else {
        timeget[0] = '0';
        timeget[1] = day + '0';
    }

    if (hour >= 10) {
        int ten_num;
        ten_num = hour / 10;
        hour %= 10;
        timeget[2] = ten_num + '0';
        timeget[3] = hour + '0';
    } else {
        timeget[2] = '0';
        timeget[3] = hour + '0';
    }

    if (minute >= 10) {
        int ten_num;
        ten_num = minute / 10;
        minute %= 10;
        timeget[4] = ten_num + '0';
        timeget[5] = minute + '0';
    } else {
        timeget[4] = '0';
        timeget[5] = minute + '0';
    }

    if (sec >= 10) {
        int ten_num;
        ten_num = sec / 10;
        sec %= 10;
        timeget[6] = ten_num + '0';
        timeget[7] = sec + '0';
    } else {
        timeget[6] = '0';
        timeget[7] = sec + '0';
    }

    timeget[8] = '\0';  // 添加字符串終止符

    return;
}

//更新商品表txt 完成 已修正
void save_product_fileIO(product_for_sell** head){
    product_for_sell* tmp=*head;
    if(*head==NULL){
        return;
    }
    FILE *save_list = fopen("product_list.txt","w");
    while(tmp!=NULL){
        fprintf(save_list,"%s %.2f %d\n",tmp->product_name_sell,tmp->product_price_sell,tmp->product_amount_sell);
        tmp=tmp->next;
    }
    
    fclose(save_list);
}

//買家buy時 add detail 已修正 完成
void ADD_detail(customer_detail** detail_head, product_for_sell* product, char*name, int amount) {
    customer_detail* add = (customer_detail*)malloc(sizeof(customer_detail));
    char time[9];
    getTime(time);
    
    strcpy(add->product_name, product->product_name_sell);
    strcpy(add->buy_time, time);
    add->product_price = product->product_price_sell * (float)amount;
    add->product_amount = amount;
    add->detail_next = NULL;

    if (*detail_head == NULL) {
        *detail_head = add;
    } else {
        customer_detail* cur = *detail_head;
        while (cur->detail_next != NULL) {
            cur = cur->detail_next;
        }
        cur->detail_next = add;
    }
}

//印出list 完成
void list_product(product_for_sell** head){
    product_for_sell* cur = *head;
    printf("product list :\n\n");
    while(cur != NULL){
        printf("%-16s\t", cur->product_name_sell);
        printf("price: %.2f\t",cur->product_price_sell);
        printf("amount: %d\n\n",cur->product_amount_sell);
        cur = cur->next;
    }
    printf("---------------\n");
}

//印出customer overview 完成
void list_order_overview(customer_overview** head){
    FILE *seller_add_from_file = fopen("order_overview.txt","r");
    if(seller_add_from_file==NULL){
        printf("there is no order\n");
        return;
    }
    else{
        char getspace[100];
        while(fgets(getspace,100,seller_add_from_file)){
            printf("%s",getspace);
        }
    }
    fclose(seller_add_from_file);
}

//輸出customer overview 至 order_overview.txt 完成
void fileOUTPUT_order_overview(customer_overview** head){
    customer_overview *tmp=*head;
    if(tmp==NULL){
        return;
    }
    else{
        FILE *output_order_overview = fopen("order_overview.txt","a");
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        fprintf(output_order_overview,"total price:%.2f\n\n",tmp->total_price);
        fclose(output_order_overview);
    }
}

//檢查註冊帳號是否重複
int cheak_account_is_exist(char a[21]){
    FILE *cheak_is_account_repeat = fopen("buyer_account_list.txt","r");
    if(cheak_is_account_repeat!=NULL){
        char account_cheak[21]={"\0"},password_store[21]={"\0"};
        while(!feof(cheak_is_account_repeat)){
            fscanf(cheak_is_account_repeat,"%s %s",account_cheak,password_store);
            if(strstr(account_cheak,a)!=NULL && strlen(account_cheak)==strlen(a)){
                printf("this account is already exist !\n");
                return 1;
            }
        }
        return 0;
    }
}
