// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *Create_list(struct node *head);
void insert_node_End(struct node *start,int data);
struct node *insert_node_Beginning(struct node *head,int data);
void print_list(struct node *head);
int count_nodes_list(struct node *head);
void search_list(struct node *head,int data);
void print_second_last_node(struct node *head);
void print_last_node(struct node *head);
void predecessor_ptr_node(struct node *head,int data);
void get_ptr_node(struct node *head, int position);
const int n=8;
int main() {
    struct node *newnode, *temp, *head=NULL;
    int count_nodes = 0;
    head=Create_list(head);
    print_list(head);
    count_nodes = count_nodes_list(head);
    printf("list count = %d \n\r",count_nodes);
    search_list(head,18);
    print_last_node(head);
    print_second_last_node(head);
    predecessor_ptr_node(head,88);
    get_ptr_node(head,8);
    printf("\n\r New node added in Beginning");
    head = insert_node_Beginning(head,99);
    print_list(head);
    printf("\n\r New node added in Beginning");
    insert_node_End(head,100);
    print_list(head);
}
struct node *insert_node_Beginning(struct node *head,int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->link = head;
    head = newnode;
    return newnode;
}
void insert_node_End(struct node *start,int data)
{
    struct node *newnode,*temp;
    temp = start;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->link = NULL;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newnode;
}
struct node *Create_list(struct node *head)
{
    int data[8] = {12,22,33,44,55,66,77,88};
    head = insert_node_Beginning(head,data[0]);

    for(int i = 1;i<8; i++)
    {
        insert_node_End(head,data[i]);
    }
    return head;
}
void print_list(struct node *head)
{
    struct node *temp;
    temp =head;
    printf(" \n\r head --> %p,",temp);
    while(temp!= NULL)
    {
        printf("\n\r %d --> %p,",temp->info,temp->link);
        temp = temp->link;
    }
}
int count_nodes_list(struct node *head)
{
    struct node *temp;
    temp =head;
    int count = 0;
    while(temp!= NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}
void search_list(struct node *head,int data)
{
    struct node *temp;
    temp =head;
    int pos = 1;
    int data_flag = 0;
    while(temp!= NULL)
    {
        if( temp->info == data)
        {
            printf("%d is at position %d\n",data,pos);
            data_flag = 1;
        }
        temp = temp->link;
        pos ++;
    }
    if(data_flag == 0)
    {
        printf("%d not found in list\n",data);
    }
}
void print_second_last_node(struct node *head)
{
    struct node *temp;
    temp =head;
    int pos = 1;
    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp->link->link!= NULL)
    {
        pos ++;
        temp = temp->link;
    }
    printf(" \n\rsecond last node :%d at position : %d",temp->info,pos);
}
void print_last_node(struct node *head)
{
    struct node *temp;
    temp =head;
    int pos = 1;
    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp->link!= NULL)
    {
        pos ++;
        temp = temp->link;
    }
    printf("\n\rLast node :%d at position : %d",temp->info,pos);
}
void predecessor_ptr_node(struct node *head,int data)
{
    struct node *temp;
    temp =head;
    int pos = 1;
    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp->link!= NULL)
    {
        pos++;
        if(temp->link->info == data)
            break;
        temp = temp->link;
    }
    printf(" \n\rdata : %d predecessor node pinter:%p at position : %d",data,temp->link,pos);
}
void get_ptr_node(struct node *head, int position)
{
    struct node *temp;
    temp =head;
    int pos = 0;
    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL)
    {
        pos++;
        if(pos == position)
            break;
        temp = temp->link;
    }
    printf(" \n\rdata : %d node pointer:%p at position : %d",temp->info,temp->link,pos);
}