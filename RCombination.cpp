#include "RCombination.h"
#include <QStringList>
#include <QDebug>
/**
 * @brief RCombination::RCombination
 * @param combination_lineEdit
 * @param r_lineEdit
 */
RCombination::RCombination(QString combination_lineEdit, QString r_lineEdit){
    combinationStr = combination_lineEdit;
    rValue = r_lineEdit.toInt();

    //以 ','分割字符串   不计空窜（连续两个','）
    //4*a1,3*a2,4*a3,5*a4     34
    //3*a1,7*a2,2*a3,15*a4     96
    QStringList list = combinationStr.split(',', QString::SkipEmptyParts);
    setNum = 0;
    //正则匹配输入格式  ^[0-9]+\*[A-Za-z0-9]+
    QRegExp rx(QString("^[0-9]+[*][A-Za-z0-9_]{1,}$"));
    foreach(QString s, list){
        if(!rx.exactMatch(s)){
            answer = -1;
            return;
        }
        int key = s.indexOf('*');
        set[setNum].k_i = s.left(key).toInt();
        set[setNum].a_i = s.right(s.length() - key - 1);

        setNum += 1;
    }

}

/**
 * @brief 计算F(n, r)
 * @param n
 * @param r
 * @return
 */
long long RCombination::F(int n, int r){
    if(r < 0)
        return 0;
    int max_num = n + r -1;
    int k = r;
    long long molecule = 1;   //分子
    long long denominator = 1;    //分母
    while(k > 0){
        molecule *= max_num;
        max_num -= 1;
        denominator *= k;
        k -= 1;
    }
    return molecule / denominator;
}

/**
 * @brief 容斥原理计算 r-组合 计数
 * @return
 */
long long RCombination::calculate(){
    answer = F(setNum, rValue);   // 首先计算 |S|
    for (int count = 1, key = -1; count <= setNum; count += 1) {
        answer += key * calACombination(set, setNum, 0, rValue, count);
        key *= -1;
    }
    return answer;
}


/**
 * @brief 计算count个Ai交集的组合个数
 * @param setNum  集合中ai种类数
 * @param start  选择Ai的起始位置 下标从0开始
 * @param r     剩余的r值
 * @param count  计数的Ai个数
 * @return
 */
long long RCombination::calACombination(const Node (&set)[50], const int &setNum, int start, int r, int count){
    if(r < 0 || count <= 0)
        return 0;
    if(setNum - start < count)  //set[start...end] 个数 < count
        return 0;

    long long sum = 0;
    int end = setNum - count;    //保证能选count个Ai的最大下标
    count -= 1;
    for(int index = start; index <= end; index+=1){
        if(count > 0){
            sum += calACombination(set, setNum, index+1, r-set[index].k_i-1, count);
        }
        else {
            sum += F(setNum, r-set[index].k_i-1);
        }
    }

    return sum;
}

