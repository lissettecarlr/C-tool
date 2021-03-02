//linux 内核链表
#ifndef LINUX_CORE_LIST_H_
#define LINUX_CORE_LIST_H_

/*!
 * 环形链表
 */
struct sList
{
    struct sList *next;                         
    struct sList *prev;                          
};
typedef struct sList list_t;                  

/*!
 * @brief 成员地址-成员偏移=首地址
 * &((type *)0)->member :将0转化为结构体指针，则起始地址为0，然后成员以0为基础进行偏移，所得的便是member成员的偏移量
 * (char *)(ptr)：控制运算时步长为1字节
 */
#define LIST_ENTER(ptr, type, member) \
    ((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))

/*!
 * @brief 初始化链表
 */
static __inline void list_init(list_t *l)
{
    l->next = l->prev = l;
}

/**
 * @brief 在指向链表节点前插入
 * @param l 插入的链表
 * @param n 新节点
 */
static __inline void list_inster_after(list_t *l, list_t *n)
{
    l->next->prev = n;
    n->next = l->next;

    l->next = n;
    n->prev = l;
}

/**
 * @brief 在指向链表节点后插入
 * @param l 插入的链表
 * @param n 新节点
 */
static __inline void list_insert_before(list_t *l, list_t *n)
{
    l->prev->next = n;
    n->prev = l->prev;

    l->prev = n;
    n->next = l;
}

/**
 * @brief 从链表中删除此节点
 * @param n 待删除节点.
 */
static __inline void list_remove(list_t *n)
{
    n->next->prev = n->prev;
    n->prev->next = n->next;

    n->next = n->prev = n;
}

/**
 * @brief 链表是否为空
 * @param l 测试链表.
 */
static __inline int rt_list_isempty(const list_t *l)
{
    return l->next == l;
}

/**
 * @brief 获取链表长度
 * @param l the list to get.
 */
static __inline unsigned int list_len(const list_t *l)
{
    unsigned int len = 0;
    const list_t *p = l;
    while (p->next != l)
    {
        p = p->next;
        len ++;
    }

    return len;
}


#endif
