template <class T>
T get_sum(T* a, int n) 
{
    T result = 0;
    for(int i = 0; i < n;i++)
        result += a[i];

    return result;
}