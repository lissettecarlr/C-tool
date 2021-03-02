#include <stdio.h>
#include "linux_core_list.h"

typedef struct text
{
	int data;
	list_t list;
	int data2;
}test_t;

static test_t node1={1,{0,0},1};
static test_t node2={2,{0,0},2};;
static test_t node3={3,{0,0},3};;

void main()
{
    list_t head;
    test_t *object;

    list_init(&head);

    list_inster_after(&head,&node1.list);
    list_inster_after(&head,&node2.list);
    list_inster_after(&head,&node3.list);

    printf("len=%d\n",list_len(&head));

    list_t *temp=head.next;
    for(temp=head.next;temp!=&head;temp=temp->next)
    {
        object = LIST_ENTER(temp,test_t,list);
        printf("node:data=%d\n",object->data);
    }
  

}

//((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))