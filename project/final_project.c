#include"function.h"


char seller_account[]={"!"},seller_password[]={"@"};//預設的賣家帳號 密碼 可以改
char buyer_account[21],buyer_password[21];//用來存當前買家的帳號密碼
int seller_mode_login=0 , buyer_mode_login=0; //判斷模式的登入與否 0=沒登入 1=登入過 若有切換模式 請將狀態改變

//以價錢為依據 從高到低排 完成
void Sort_price_HighToLow(product_for_sell** head) {
    int swapped;
    product_for_sell* ptr1;
    product_for_sell* lptr = NULL;

    if ((*head) == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->product_price_sell < ptr1->next->product_price_sell) {
                float temp_price = ptr1->product_price_sell;
                int temp_amount = ptr1->product_amount_sell;
                char temp_name[NAME_LENGTH_MAX];

                ptr1->product_price_sell = ptr1->next->product_price_sell;
                ptr1->next->product_price_sell = temp_price;

                ptr1->product_amount_sell = ptr1->next->product_amount_sell;
                ptr1->next->product_amount_sell = temp_amount;

                strcpy(temp_name, ptr1->product_name_sell);
                strcpy(ptr1->product_name_sell, ptr1->next->product_name_sell);
                strcpy(ptr1->next->product_name_sell, temp_name);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

//以價錢為依據 從低到高排 完成
void Sort_price_LowToHigh(product_for_sell** head) {
    int swapped;
    product_for_sell* ptr1;
    product_for_sell* lptr = NULL;

    if ((*head) == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->product_price_sell > ptr1->next->product_price_sell) {
                float temp_price = ptr1->product_price_sell;
                int temp_amount = ptr1->product_amount_sell;
                char temp_name[NAME_LENGTH_MAX];

                ptr1->product_price_sell = ptr1->next->product_price_sell;
                ptr1->next->product_price_sell = temp_price;

                ptr1->product_amount_sell = ptr1->next->product_amount_sell;
                ptr1->next->product_amount_sell = temp_amount;

                strcpy(temp_name, ptr1->product_name_sell);
                strcpy(ptr1->product_name_sell, ptr1->next->product_name_sell);
                strcpy(ptr1->next->product_name_sell, temp_name);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

//以數量為依據 從高到低排 完成
void Sort_amount_HighToLow(product_for_sell** head) {
    int swapped;
    product_for_sell* ptr1;
    product_for_sell* lptr = NULL;

    if ((*head) == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->product_amount_sell < ptr1->next->product_amount_sell) {
                float temp_price = ptr1->product_price_sell;
                int temp_amount = ptr1->product_amount_sell;
                char temp_name[NAME_LENGTH_MAX];

                ptr1->product_price_sell = ptr1->next->product_price_sell;
                ptr1->next->product_price_sell = temp_price;

                ptr1->product_amount_sell = ptr1->next->product_amount_sell;
                ptr1->next->product_amount_sell = temp_amount;

                strcpy(temp_name, ptr1->product_name_sell);
                strcpy(ptr1->product_name_sell, ptr1->next->product_name_sell);
                strcpy(ptr1->next->product_name_sell, temp_name);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

//數量為依據 從低到高排 完成
void Sort_amount_LowToHigh(product_for_sell** head) {
    int swapped;
    product_for_sell* ptr1;
    product_for_sell* lptr = NULL;
    if ((*head) == NULL)
        return;
    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->product_amount_sell > ptr1->next->product_amount_sell) { // 修改比较符号
                float temp_price = ptr1->product_price_sell;
                int temp_amount = ptr1->product_amount_sell;
                char temp_name[NAME_LENGTH_MAX];

                ptr1->product_price_sell = ptr1->next->product_price_sell;
                ptr1->next->product_price_sell = temp_price;

                ptr1->product_amount_sell = ptr1->next->product_amount_sell;
                ptr1->next->product_amount_sell = temp_amount;

                strcpy(temp_name, ptr1->product_name_sell);
                strcpy(ptr1->product_name_sell, ptr1->next->product_name_sell);
                strcpy(ptr1->next->product_name_sell, temp_name);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

//主程式
int main(){
    product_for_sell *head_product_list=NULL;
    product_for_sell *cur_product_list=head_product_list;

    customer_overview *head_customer_list=NULL;
    customer_overview *cur_customer_list=head_customer_list;
    
    FILE *seller_add_from_file = fopen("product_list.txt","r");
    if(seller_add_from_file!=NULL){
        fclose(seller_add_from_file);
        seller_add_fileIO(&(head_product_list),"product_list.txt");
    }
    int first = 1;
    int buyer_or_seller=2; //buyer_or_seller=0 賣家模式 buyer_or_seller=1 買家模式
    while(buyer_or_seller!=0 && buyer_or_seller!=1){//初始模式選擇 + 防呆
        
        printf("---------------\n");
        printf("please choose the mode\n(input '0' to enter seller mode , input '1' to enter buyer mode)\n");
        printf("---------------\n");
        char input[10]={'\0'};
        scanf("%s",input);
        if(input[0]-'0'==0 && strlen(input)==1){
            buyer_or_seller=0;
        }
        else if(input[0]-'0'==1 && strlen(input)==1){
            buyer_or_seller=1;
        }
        else{
            printf("---------------\n");
            printf("***wrong command !\n");
            printf("---------------\n");
            continue;
        }
    }
    while(buyer_or_seller==0 || buyer_or_seller==1){
        //賣家模式 完成
        if(buyer_or_seller==0){
            printf("\n");
            printf("> seller mode\n");
            printf("---------------\n");
            char command_seller_mode[20]; //用於讀取命令
            if(seller_mode_login!=1 && buyer_mode_login==0){//登入賣家模式
                char seller_account_login[20], seller_password_login[20]; //儲存輸入的賣家帳號密碼
                printf("please enter the seller account: ");
                scanf("%s",seller_account_login);
                printf("please enter the seller password: ");
                scanf("%s",seller_password_login);

                int account_seller_right;//比對賣家帳號是否正確 正確=1 錯誤=0
                if(strstr(seller_account_login,seller_account)!=NULL && strcmp(seller_account_login,seller_account)==0){
                    account_seller_right=1;
                }
                else account_seller_right=0;

                int password_seller_right;//比對賣家密碼是否正確 正確=1 錯誤=0
                if(strstr(seller_password_login,seller_password)!=NULL && strcmp(seller_password_login,seller_password)==0){
                    password_seller_right=1;
                }
                else password_seller_right=0;
                if(account_seller_right==1 && password_seller_right==1){//若帳號密碼都無誤
                    printf("\n");
                    printf("welcome back, seller:%s\n",seller_account);
                    seller_mode_login=1;
                    continue;
                }
                if(account_seller_right==0 || password_seller_right==0){//若帳號或密碼有誤
                    int is_change_mode=100;//預設100使每次錯誤一定進入 下面的while迴圈 =1換模式 =0不換模式
                    printf("***account or password wrong !\n");//提示有錯
                    printf("---------------\n");
                    while(is_change_mode!=0 && is_change_mode!=1){
                        printf("do you want switch to buyer mode?\nenter '1' to switch , '0' to continue login in seller mode\n");
                        printf("---------------\n");
                        char input[10]={'\0'};
                        scanf("%s",input);
                        if(strstr(input,"0")!=NULL && strlen(input)==1){
                            is_change_mode=0;
                        }
                        else if(strstr(input,"1")!=NULL && strlen(input)==1){
                            is_change_mode=1;
                        }
                        else{
                            printf("***wrong command !\n");
                            printf("---------------\n");
                            continue;
                        }
                    }
                    if(is_change_mode==1){
                        buyer_or_seller=1;
                    }
                    if(is_change_mode==0){
                        buyer_or_seller=0;
                    }
                    continue; //重新回到最外的while 判斷buyer_or_seller的數值 進入對應的模式if
                }
            }
            if(seller_mode_login==1 && buyer_mode_login==0){
                //printf("hint : type '?' to get information about the command in seller mode\n");
                //printf("---------------\n");
                
                //移除問號查看
                    printf("command name:\n");

                    printf("add");
                    printf("       |");
                    printf("add new product to sell\n          |\n");
                    
                    printf("order");
                    printf("     |");
                    printf("show all detail about order\n");

                    printf("delete");
                    printf("    |");
                    printf("delete the product you have set\n          |\n");
                    
                    printf("buyer");
                    printf("     |");
                    printf("switch to buyer mode\n          |\n");

                    printf("exit");
                    printf("      |");
                    printf("end the program\n          |\n");

                    printf("product");
                    printf("   |");
                    printf("show all the product you have set\n");
                printf("---------------\n");
                scanf("%s",command_seller_mode);
                printf("---------------\n");
                int len=strlen(command_seller_mode);

                if(strstr(command_seller_mode,"add")!=NULL && len==3){//command=add 時 新增上架商品 需要有使用file input的功能
                                                                      //輸入add後 須有提示字元 提醒賣家輸入商品名稱 數量 價格等等 使用product_for_sell
                    int is_fileIO_seller_add=2;
                    while(is_fileIO_seller_add!=0 && is_fileIO_seller_add!=1){
                        printf("what way do you want to add your product information ?\n\n");
                        printf("enter '0' to add product information from your keyborad , '1' from text file\n");
                        printf("---------------\n");
                        char input[10]={'\0'};
                        scanf("%s",input);
                        if(input[0]-'0'==0 && strlen(input)==1){
                            is_fileIO_seller_add=0;
                        }
                        else if(input[0]-'0'==1 && strlen(input)==1){
                            is_fileIO_seller_add=1;
                        }
                        else{
                            printf("***wrong command !\n");
                            printf("---------------\n");
                            continue;
                        }
                    }
                    if(is_fileIO_seller_add==0){
                        seller_add_stdin(&(head_product_list));
                    }
                    if(is_fileIO_seller_add==1){
                        char filename[NAME_LENGTH_MAX];
                        printf("enter the file name you want read\n");
                        scanf("%s",filename);
                        seller_add_fileIO(&(head_product_list),filename);
                    }
                    
                }
                if(strstr(command_seller_mode,"order")!=NULL && len==5){//command=detail 時 需要有使用file output的功能 製作訂單資料
                    char sort_price_high_or_low[10]={"\0"};
                    list_order_overview(&head_customer_list);
                }
                if(strstr(command_seller_mode,"delete")!=NULL && len==6){//command=delete 時 刪除該商品資料
                    while(1){
                        list_product(&head_product_list);
                        printf("please enter the name of the product you want to delete :\n");
                        printf("enter ""!exit"" to get out buy section\n");
                        printf("---------------\n");
                        char product_delete[20];
                        scanf("%s", product_delete);
                        if(strstr(product_delete,"!exit")!=NULL && strlen(product_delete)==5) {
                            break;
                        }
                        DEL_product(&head_product_list,product_delete);
                    }
                }
                if(strstr(command_seller_mode,"buyer")!=NULL && len==5){//command=buyer 時 切換至買家模式
                    buyer_or_seller=1;
                    seller_mode_login=0;
                    memset(buyer_account,'\0',sizeof(buyer_account)/sizeof(buyer_account[0]));
                    memset(buyer_password,'\0',sizeof(buyer_password)/sizeof(buyer_password[0]));
                    save_product_fileIO(&head_product_list);
                    continue;
                }
                if(strstr(command_seller_mode,"exit")!=NULL && len==4){//command=exit 時 結束程式
                    buyer_or_seller=100;//防止錯誤跳回while迴圈
                    save_product_fileIO(&head_product_list);
                    break;
                }
                if(strstr(command_seller_mode,"product")!=NULL && len==7){
                    list_product(&head_product_list);
                    continue;
                }
            }
            save_product_fileIO(&head_product_list);
        }
        //買家模式
        if(buyer_or_seller==1){ 
            
            printf("\n");
            printf("> buyer mode\n");
            printf("---------------\n");
            char command_buyer_mode[20]; //用於讀取命令
            if(buyer_mode_login!=1 && seller_mode_login==0){//登入買家模式
                printf("do you want to sign up for a new account ? or you have a account already\n\n");
                int signup_or_login=100;//登入or註冊 =0 註冊 =1 登入 =2 切回賣家模式
                while(signup_or_login!=0 && signup_or_login!=1 && signup_or_login!=2){
                    printf("enter '0' to sign up for a new account , enter '1' to log in , or enter '2' to switch to seller mode\n");
                    printf("---------------\n");
                    char input[20]={'\0'};
                    scanf("%s",input);
                    if(input[0]-'0'==0 && strlen(input)==1){
                        signup_or_login=0;
                    }
                    else if(input[0]-'0'==1 && strlen(input)==1){
                        signup_or_login=1;
                    }
                    else if(input[0]-'0'==2 && strlen(input)==1){
                        signup_or_login=2;
                    }
                    else{
                        printf("***wrong command !\n");
                        continue;
                    }

                }
                if(signup_or_login==2){//切回賣家模式
                    buyer_or_seller=0;
                    continue;
                }
                if(signup_or_login==0){//註冊買家帳號
                    char buyer_accoun_for_signup[21]={'\0'} ,buyer_password_for_signup[21]={'\0'};

                    printf("please enter the account name you want :\n");
                    printf("---------------\n"); 
                    scanf("%s",buyer_accoun_for_signup);

                    printf("please enter the password you want :\n");
                    printf("---------------\n");
                    scanf("%s",buyer_password_for_signup);
                    if(cheak_account_is_exist(buyer_accoun_for_signup)==1){
                        continue;
                    }
                    strcpy(buyer_account,buyer_accoun_for_signup);   //註冊完將帳號密碼存入buyer_account buyer_password 之後建檔需要使用
                    strcpy(buyer_password,buyer_password_for_signup);
                    FILE *buyer_account_new=fopen("buyer_account_list.txt","a");
                    fprintf(buyer_account_new,"%s %s\n",buyer_account,buyer_password);
                    fclose(buyer_account_new);
                    printf("welcome new buyer :%s\n",buyer_account);
                    printf("---------------\n");
                    buyer_mode_login=1; //確認買家模式登入
                    if(head_customer_list==NULL){
                        customer_overview *tmp = (customer_overview*)malloc(sizeof(customer_overview));
                        strcpy(tmp->buyer_name,buyer_account);
                        tmp->next=NULL;
                        tmp->total_price = 0;
                        head_customer_list=tmp;
                        cur_customer_list=head_customer_list;
                        cur_customer_list->detail=NULL;
                        continue;
                    }
                    if(head_customer_list!=NULL){
                        customer_overview *cur=head_customer_list;
                        while(1){
                            if(cur->next==NULL){
                                break;
                            }
                            if(strstr(cur->buyer_name,buyer_account)!=NULL && strlen(cur->buyer_name)==strlen(buyer_account)){
                                break;
                            }
                            cur=cur->next;
                        }
                        if(strstr(cur->buyer_name,buyer_account)!=NULL && strlen(cur->buyer_name)==strlen(buyer_account)){
                            cur_customer_list=cur;
                            break;
                        }
                        customer_overview *tmp = (customer_overview*)malloc(sizeof(customer_overview));
                        strcpy(tmp->buyer_name,buyer_account);
                        tmp->next = NULL;  // 設置 tmp 的 next 指標為 NULL
                        tmp->total_price = 0;
                        cur->next= tmp;
                        cur_customer_list=tmp;
                        cur_customer_list->detail=NULL;
                    }
                }
                if(signup_or_login==1){//登入已存在的買家帳號
                    char buyer_account_for_login[21],buyer_password_for_login[21];
                    FILE *file_open_buyer_account_find=fopen("buyer_account_list.txt","r");//買家帳號存於同資料夾中的 buyer_account_list.txt檔案中
                    if(file_open_buyer_account_find==NULL){//buyer_account_list.txt開啟失敗或檔案不存在
                        printf("can mot open the file ""buyer_account_list.txt""\n");
                        printf("---------------\n");
                        continue;
                    }
                    int is_account_found=0;//判斷有無找到帳號
                    char buyer_account_for_login_cmp[21],buyer_password_for_login_cmp[21];//從buyer_account_list.txt檔案中讀取帳號密碼資料 用於比對
                    
                    printf("please enter your account name for buyer mode\n");//輸入買家帳號密碼
                    printf("---------------\n");
                    scanf("%s",buyer_account_for_login);
                    printf("please enter your password for buyer mode\n");
                    printf("---------------\n");
                    scanf("%s",buyer_password_for_login);

                    while(fscanf(file_open_buyer_account_find,"%s %s",buyer_account_for_login_cmp,buyer_password_for_login_cmp)==2){
                        //printf("%s %s\n",buyer_account_for_login_cmp,buyer_password_for_login_cmp);

                        int account_right=0 , password_right=0;//判斷帳號密碼對不對 0=不對 1=對
                        if(strstr(buyer_account_for_login,buyer_account_for_login_cmp)!=NULL && strcmp(buyer_account_for_login,buyer_account_for_login_cmp)==0){
                            account_right=1;
                        }
                        else{
                            account_right=0;
                        }
                        if(strstr(buyer_password_for_login,buyer_password_for_login_cmp)!=NULL && strcmp(buyer_password_for_login,buyer_password_for_login_cmp)==0){
                            password_right=1;
                        }
                        else{
                            password_right=0;
                        }
                        if(account_right==1 && password_right==1){//帳號密碼正確
                            strcpy(buyer_account,buyer_account_for_login);   
                            strcpy(buyer_password,buyer_password_for_login);
                            printf("welcome back, buyer : %s\n",buyer_account);
                            printf("---------------\n");
                            buyer_mode_login=1;
                            is_account_found=1;
                            
                            if(head_customer_list==NULL){
                                customer_overview *tmp = (customer_overview*)malloc(sizeof(customer_overview));
                                strcpy(tmp->buyer_name,buyer_account);
                                tmp->next=NULL;
                                head_customer_list=tmp;
                                cur_customer_list=head_customer_list;
                                cur_customer_list->total_price = 0;
                                cur_customer_list->detail=NULL;
                            continue;
                            }
                            if(head_customer_list!=NULL){
                                customer_overview *cur=head_customer_list;
                                while(1){
                                    if(cur->next==NULL){
                                        break;
                                    }
                                    if(strstr(cur->buyer_name,buyer_account)!=NULL && strlen(cur->buyer_name)==strlen(buyer_account)){
                                        break;
                                    }
                                    cur=cur->next;
                                }
                                if(strstr(cur->buyer_name,buyer_account)!=NULL && strlen(cur->buyer_name)==strlen(buyer_account)){
                                    cur_customer_list=cur;
                                    break;
                                }
                                customer_overview *tmp = (customer_overview*)malloc(sizeof(customer_overview));
                                strcpy(tmp->buyer_name,buyer_account);
                                tmp->next = NULL;  // 設置 tmp 的 neximage.pngt 指標為 NULL
                                tmp->total_price = 0;
                                cur->next= tmp;
                                cur_customer_list=tmp;
                                cur_customer_list->detail=NULL;
                            }
                            break;
                        }
                        if(account_right==1 && password_right!=1){//
                            printf("***wrong password\n");
                            buyer_mode_login=0;
                            is_account_found=1;
                            break;
                        }
                    }

                    if(is_account_found==0){
                        printf("***account not found !\n");
                        printf("---------------\n");
                        continue;
                    }
                    fclose(file_open_buyer_account_find);


                }
            }
            if(buyer_mode_login==1 && seller_mode_login==0){
                //printf("hint : type '?' to get information about the command in buyer mode\n\n");
                printf("current buyer account :%s\tSubtotal: %.2f\n",cur_customer_list->buyer_name,cur_customer_list->total_price); 
                printf("---------------\n");
                
                //移除問號查看
                    printf("command name:\n");
            
                    printf("seller");
                    printf("         |");
                    printf("switch to seller mode\n               |\n");

                    printf("list_buy");
                    printf("       |");
                    printf("show what you have bought\n               |\n");

                    printf("list_product");
                    printf("   |");
                    printf("show all the product that can buy\n               |\n");

                    printf("buy");
                    printf("            |");
                    printf("buy the product you want\n               |\n");

                    printf("exit");
                    printf("           |");
                    printf("end the program\n               |\n");

                    printf("change");
                    printf("         |");
                    printf("exchange the buyer mode account\n");
                    

                printf("---------------\n");
                scanf("%s",command_buyer_mode);
                printf("---------------\n");
                int len=strlen(command_buyer_mode);

                if(strstr(command_buyer_mode,"seller")!=NULL && len==6){//command=seller 時 切換至賣家模式
                    buyer_or_seller=0;
                    buyer_mode_login=0;
                    if(first == 0){
                        first = 1;
                        fileOUTPUT_order_overview(&head_customer_list);
                    }
                    continue;
                }
                if(strstr(command_buyer_mode,"list_buy")!=NULL && len==8){//command=list_buy 時 顯示購買的物品
                    customer_detail* cur = cur_customer_list->detail;
                    printf("---------------\n");
                    if(cur == NULL){
                        printf("you haven't bought anything yet.\n");
                        printf("---------------\n");
                    }
                    
                    while(cur != NULL){
                        printf("product: %s\n", cur->product_name);
                        printf("time: %s\n",cur->buy_time);
                        printf("amount: %d\n", cur->product_amount);
                        printf("price: %.2f\n", cur->product_price);
                        printf("---------------\n");
                        cur = cur->detail_next;
                    }
                    
                }
                if(strstr(command_buyer_mode,"list_product")!=NULL && len==12){//command=list_product 時 顯示可購買的物品
                    list_product(&head_product_list);
                    while(1){
                        char select[5] = {'\0'};
                        printf("if you want to have a sorted list:\n\nsorted by price from high to low enter: 0\n\nsorted by price from low to high enter: 1\n \
                        \nsorted by amount from high to low enter: 2\n\nsorted by amount from low to high enter: 3\n\nif you don't want to continue , enter no\n");
                        printf("---------------\n");
                        scanf("%s", select);
                        
                        if(strstr(select,"no") != NULL && strlen(select) == 2) break;
                        else if(strstr(select,"0") != NULL && strlen(select) == 1) Sort_price_HighToLow(&head_product_list);
                        else if(strstr(select,"1") != NULL && strlen(select) == 1) Sort_price_LowToHigh(&head_product_list);
                        else if(strstr(select,"2") != NULL && strlen(select) == 1) Sort_amount_HighToLow(&head_product_list); 
                        else if(strstr(select,"3") != NULL && strlen(select) == 1) Sort_amount_LowToHigh(&head_product_list); 
                        else{
                            printf("please enter the command mentioned above\n\n");
                            continue;
                        }
                        list_product(&head_product_list);
                    }
                }
                if(strstr(command_buyer_mode,"buy")!=NULL && len==3){
                    char buyer_product_name[20]={'\0'}, curTime[8]={'\0'};
                    //輸入!exit才會跳出迴圈
    
                    while(1){
                        product_for_sell* search = head_product_list;
                        int is_search_found=0;
                        list_product(&head_product_list);
                        printf("please enter the name of the product that you want to buy\n\n");
                        printf("enter ""!exit"" to get out buy section\n");
                        printf("---------------\n");
                        scanf("%s", buyer_product_name);
                        if(strstr(buyer_product_name,"!exit")!=NULL && strlen(buyer_product_name)==5) {
                            break;
                        }
                        while(search != NULL){
                            if(strcmp(search->product_name_sell,buyer_product_name) == 0){
                                is_search_found = 1;
                                break;
                            }
                            if(search->next == NULL){
                                printf("we don't provide this product\n");
                                printf("---------------\n");
                                break;
                            }
                            search = search->next;
                        }
                        if(is_search_found == 1){
                            printf("---------------\n");
                            printf("please enter the amount you want to buy\n");
                            printf("---------------\n");
                            int buyer_product_amount;
                            scanf("%d",&buyer_product_amount);

                            if(buyer_product_amount - search->product_amount_sell > 0){
                                printf("the amount is not enough\n");
                                printf("---------------\n");
                                break;
                            }
                            search->product_amount_sell -= buyer_product_amount;
                            
                            FILE *buyer_detail=fopen("order_overview.txt","a");
                            if(first == 1){
                                fprintf(buyer_detail,"%s %s\n","Account:",buyer_account);
                                --first;
                            }
                            fprintf(buyer_detail,"->%s %d\n",buyer_product_name,buyer_product_amount);
                            fclose(buyer_detail);
                            
                            ADD_detail(&(cur_customer_list->detail),search,buyer_product_name,buyer_product_amount);
                            
                            cur_customer_list->total_price+=(buyer_product_amount)*(search->product_price_sell);
                            save_product_fileIO(&head_product_list);
                        }
                        if(is_search_found == 0) break;
                    }
                }
                if(strstr(command_buyer_mode,"change")!=NULL && len==6){//command=change 時 變更買家帳號
                    buyer_or_seller=1;
                    buyer_mode_login=0;
                    if(first == 0){
                        first = 1;
                        fileOUTPUT_order_overview(&head_customer_list);
                    }
                    continue;
                }
                if(strstr(command_buyer_mode,"exit")!=NULL && len==4){//command=exit 時 結束程式
                    buyer_or_seller=100;//防止錯誤跳回while迴圈
                    if(first == 0)
                        fileOUTPUT_order_overview(&head_customer_list);
                    break;
                }
            }
        }
    }
}
