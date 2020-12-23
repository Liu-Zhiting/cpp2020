/*
编写一个模板函数get_min，接收两个参数：数组和数组的长度，
返回该数组中最小的元素的值。部分代码已给出，请将代码补充完整。
*/
template <class T>
T get_min(T* a, int n)
{
    T result = a[0];
    for(int i = 0; i < n; i++)
    {
        if(a[i] < result)
            result = a[i];
    }

    return result;
}