/*
下列程序的功能是：输入数组下标和除数，从数组中取出下标对应的数组元素作为被除数，输出除法运算的结果。例如，
输入：9 5
输出：2

捕获程序数组下标越界错误，给出相应的提示，例如，
输入：10 5
输出：10 out of bound

输入：-1 5
输出：-1 out of bound

捕获程序数组下标除零错误，给出相应的提示，例如，
输入：9 0
输出：divide by 0

部分代码已给出，请将代码补充完整。

*/

struct A : public exception
{
    int err;
    A(int err)
    {
        this->err = err;
    }
};

struct B : public exception
{
    int err;
    B(int err)
    {
        this->err = err;
    }
};