/*
补充下列程序的代码，使得程序的输出为：
1,2
a,b
11
12
*/

int x = 1;
int y = 2;
int add_something(int index)
{
    return index + 1;
}
namespace nsB
{
    char x = 'a';
    char y = 'b';
    int add_something(int index)
    {
        return index + 2;
    }
}