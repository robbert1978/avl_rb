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
    int* arr_test = new int[TESTCASE_LEN];
    printf("logN = %lf\n",log2(TESTCASE_LEN));
    printf("1.45logN = %lf\n",1.45*log2(TESTCASE_LEN));
    puts("|\tTest\t|\tAVL\t|\tRB\t|");
    for(size_t turn = 0 ; turn < 10 ;turn++){
        rb_root.root = NULL;
        avl_root = NULL;
        sprintf(file_name,"test_cases/%zu_test",turn);
        current_file = fopen(file_name,"r");
        if(current_file == NULL){
            perror(file_name);
            exit(-1);
        }
        for(size_t i = 0; i < TESTCASE_LEN ; i++){
            fscanf(current_file,"%d",&arr_test[i]);
        }
        if(turn == 0)
            std::sort(arr_test,arr_test+TESTCASE_LEN);
        if(turn == 0)
            std::sort(arr_test,arr_test+TESTCASE_LEN);
        else if(turn == 9)
            std::sort(arr_test,arr_test+TESTCASE_LEN,std::greater<int>());
        for(size_t i = 0; i < TESTCASE_LEN ; i++){
            AVL::insert(avl_root,arr_test[i]);
            rb_root.insert(arr_test[i]);
        }
        fflush(stdout);
        printf("|\t%zu\t|\t%zu\t|\t%zu\t|\n",
                    turn,AVL::caculate_height(avl_root),RED_BLACK::caculate_height(rb_root.root)
        );
        fclose(current_file);
    }

};