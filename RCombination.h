#ifndef HELPER_H
#define HELPER_H
#include <QString>

#define ERROR_R_VALUE   -1

typedef struct Node{
    int k_i;
    QString a_i;
} Node;

class RCombination
{
public:
    RCombination(QString combination_lineEdit, QString r_lineEdit);


    long calculate();

private:
    int F(int n, int r);
    int calACombination(const Node (&set)[], const int &setNum, int start, int r, int count);

private:
    QString combinationStr;
    int rValue;

    int setNum = 0;
    Node set[50];

    long answer = 0;

};

#endif // HELPER_H
