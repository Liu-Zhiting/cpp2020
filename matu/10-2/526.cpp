/*
编写一个表示链表节点的模板类node，实现链表节点的以下功能：
set_value函数：设置节点值
get_value函数：获取节点值
get_prev函数：获取上一个节点
get_next函数：获取下一个节点
insert函数：在当前节点的位置插入新节点（当前节点后移）

例如，下列程序中，
test1函数的输出应为：1 2 3
test2函数的输出应为：1.1 2.2 3.3
test3函数的输出应为：a b c

部分代码已给出，请将代码补充完整。
*/

template <class T>
class node
{
    private:
        node* previous,* next;
        T value;
    public:
        void set_value(T value)
        {
            this->value = value;
        }

        T get_value() const
        {
            return value;
        }
        
        node * get_prev() const
        {
            return previous;
        }

        node * get_next() const
        {
            return next;
        }

        void append(node * ptr)
        {
            this->next = ptr;
        }

        void insert(node * ptr)
        {
            node * p = this->previous;
            this->previous->next = ptr;
            ptr->previous = this->previous;
            ptr->next = this;
            this->previous = ptr;
        }
};