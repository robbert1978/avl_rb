#include <iostream>
#include <algorithm>
#include <cmath>
namespace AVL{
    #include "avl.cpp"
};
namespace RED_BLACK{
    #include "red_black.cpp"
};
#define TESTCASE_LEN 1000000
int main(){
    AVL::AVLNode* avl_root;
    RED_BLACK::RedBlackTree rb_root;
    // rb_Root
    FILE* current_file;
    char* file_name = (char *)malloc(0x100);
    int* arr_test = new int[TESTCASE_LEN+1024];
    puts("|\tTest\t|\t N \t|\t lgN \t|\t 1.45lgN \t|\tAVL\t|\t RB \t|");
    for(size_t turn = 0 ; turn < 10 ;turn++){
        rb_root.root = NULL;
        avl_root = NULL;
        sprintf(file_name,"test_cases/%zu_test",turn);
        current_file = fopen(file_name,"r");
        if(current_file == NULL){
            perror(file_name);
            exit(-1);
        }
        size_t len_;
        fscanf(current_file,"Count: %zu",&len_);
        for(size_t i = 0; i < len_ ; i++){
            fscanf(current_file,"%d",&arr_test[i]);
        }
        if(turn == 0)
            std::sort(arr_test,arr_test+len_);
        else if(turn == 9)
            std::sort(arr_test,arr_test+len_,std::greater<int>());
        for(size_t i = 0; i < len_ ; i++){
            avl_root = AVL::insert(avl_root,arr_test[i]);
            rb_root.insert(arr_test[i]);
        }
        fflush(stdout);
        printf("|\t%4zu\t|\t%3zu\t|\t%5g\t|\t%9g\t|\t%3zu\t|\t%4zu\t|\n",
                    turn,len_,log2(len_),1.45*log2(len_),
                    AVL::caculate_height(avl_root),RED_BLACK::caculate_height(rb_root.root)
        );
        fclose(current_file);
    }

};