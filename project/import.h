#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define NAME_LENGTH_MAX 200
typedef struct list{                        //記錄每筆訂單的資訊
    char buyer_name[NAME_LENGTH_MAX];       //買家的名稱 會從登入的帳號抓
    float total_price;         //記錄此賣家的訂單總額
    struct list *next;                      //紀錄下一位買家的購買
    struct list_detail *detail;
} customer_overview;

typedef struct list_detail{
    char buy_time[9];                       //購買的時間 從系統抓時間 匯入buy_time[8]
    char product_name[NAME_LENGTH_MAX];     //商品的名稱
    float product_price;                    //商品的價格
    int product_amount;                     //買的商品數量
    struct list_detail *detail_next;        //紀錄同一買家的購買細節
} customer_detail;

typedef struct sell_list{                   //紀錄賣家上架的商品資訊
    char product_name_sell[NAME_LENGTH_MAX];//商品名稱
    float product_price_sell;               //商品價格
    int product_amount_sell;                //上架的商品數量
    struct sell_list *next;                 //下一種商品
} product_for_sell;


