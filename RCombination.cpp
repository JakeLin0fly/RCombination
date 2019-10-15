#include "RCombination.h"

RCombination::RCombination()
{

}

int RCombination::F(int n, int r){
    if(r < 0)
        return ERROR_R_VALUE;   //错误
    int max_num = n + r -1;
    int k = r;
    int molecule = 1;   //分子
    int denominator = 1;    //分母
    while(k > 0){
        molecule *= max_num;
        max_num -= 1;
        denominator *= k;
        k -= 1;
    }

    return molecule / denominator;
}
