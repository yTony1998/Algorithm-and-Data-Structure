#ifndef QUEUELINKED
#define QUEUELINKED
#include <assert.h>

template <class Type> class QueueLinked;
template <class Type> class QueueNode
{
friend class QueueLinked<Type>;
private:
    Type data;
    QueueNode<Type> *link;
    QueueNode(Type d=0, QueueNode *l=NULL):data(d),link(l){}

};

template <class Type> class QueueLinked
{
private:
    QueueNode<Type> *front, *rear;
public:
    QueueLinked():rear(NULL),front(NULL){}
    ~QueueLinked();
    void EnQueue(const Type& item);
    Type DeQueue();
    Type GetFront();
    void MakeEmpty();
    int IsEmpty() const {return front == NULL;}
};

template <class Type> QueueLinked<Type>::~QueueLinked()
{
    QueueNode<Type> *p;
    while(front!=NULL)
    {
        p = front; front=front->link; delete p;
    }
}

template <class Type> void QueueLinked<Type>::EnQueue(const Type& item)
{
    //将新元素item插入到队列的对尾
    if(front == NULL)
        front = rear = new QueueNode <Type>(item, NULL);
    else
        rear = rear->link = new QueueNode<Type>(item, NULL);
}

template <class Type> Type QueueLinked<Type>::DeQueue()
{
    //删去队列头节点，并返回队列头节点元素的值
    assert(!IsEmpty());
    QueueNode<Type> *p=front;
    Type retvalue = p->data;
    front = front->link;
    if(front==NULL) rear = NULL;
    delete p;
    return retvalue;

}

template<class Type> Type QueueLinked<Type>::GetFront()
{
    assert(!IsEmpty());
    return front->data;
}

template <class Type> void QueueLinked<Type>::MakeEmpty()
{
    QueueNode<Type> *p;
    while(front!=NULL)
    {
        p = front; front=front->link; delete p;
    }
}
#endif QUEUELINKED