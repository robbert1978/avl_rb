#include <iostream>
#include <random>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define TESTCASE_LEN 1000000
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(-2147483648,2147483647);
int main(){
    srand(time(NULL));
    FILE* current_file;
    char* file_name = (char *)malloc(0x100);
    
    int get_int;
    for(size_t turn = 0;turn < 10;turn++){
        sprintf(file_name,"%zu_test",turn);
        puts(file_name);
        current_file = fopen(file_name,"w");
        if(current_file == NULL){
            perror(file_name);
            exit(-1);
        }
        std::vector<int> arr_test;
        for(size_t i = 0; i<TESTCASE_LEN;i++){
            ;
            while(1){
                get_int = distribution(generator);
                if(std::binary_search(arr_test.begin(), arr_test.end(), get_int) == 0){
                        arr_test.push_back(get_int);
                        break;
                }
            }
            fprintf(current_file,"%d\n",get_int);
        }
        arr_test.clear();
        fclose(current_file);
    }
    puts("Done!");
}