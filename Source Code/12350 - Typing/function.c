#include "function.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

Node *head, *tail;
int total_node = 1;

void insert(Node** cursor, char intype)
{
    Node *real_cursor = (*cursor);
    Node *cursor_next = real_cursor->ptr_to_next_node;
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->character = intype;
    new_node->ptr_to_prev_node = real_cursor;
    new_node->ptr_to_next_node = cursor_next;
    cursor_next->ptr_to_prev_node = new_node;
    real_cursor->ptr_to_next_node = new_node;
    total_node++;
    //printf("Total Nodes: %d\n",total_node);
}

void deletion(Node**cursor)
{
    Node *real_cursor = (*cursor);
    if(real_cursor->ptr_to_next_node == head)
    {
        return;
    }
    Node *delete_node = real_cursor->ptr_to_next_node;
    Node *cursor_next = real_cursor->ptr_to_next_node->ptr_to_next_node;
    real_cursor->ptr_to_next_node = cursor_next;
    cursor_next->ptr_to_prev_node = real_cursor;
    free(delete_node);
    total_node--;
    //printf("Total Nodes: %d\n",total_node);
}

void backspace(Node** cursor)
{
    Node *real_cursor = (*cursor);
    if(real_cursor == head)
    {
        return;
    }
    Node *cursor_prev = real_cursor->ptr_to_prev_node;
    Node *cursor_next = real_cursor->ptr_to_next_node;
    cursor_prev->ptr_to_next_node = cursor_next;
    cursor_next->ptr_to_prev_node = cursor_prev;
    Node *delete_node = real_cursor;
    real_cursor = cursor_prev;
    *cursor = real_cursor;
    free(delete_node);
    total_node--;
    //printf("Total Nodes: %d\n",total_node);
}

void go_left(Node** cursor, int num)
{
    Node *real_cursor = (*cursor);
    int i;
    int mod_num = num % total_node;
    for(i=0;i<mod_num;i++)
    {
        real_cursor = real_cursor->ptr_to_prev_node;
        /*if(real_cursor == head)
        {
            real_cursor = real_cursor->ptr_to_prev_node;
        }*/
    }
    *cursor = real_cursor;
}

void go_right(Node** cursor, int num)
{
    Node *real_cursor = (*cursor);
    int i;
    int mod_num = num % total_node;
    for(i=0;i<mod_num;i++)
    {
        real_cursor = real_cursor->ptr_to_next_node;
        /*if(real_cursor == head)
        {
            real_cursor = real_cursor->ptr_to_next_node;
        }*/
    }
    *cursor = real_cursor;
}

void go_home(Node** cursor)
{
    /*Node *real_cursor = (*cursor);
    while(real_cursor != head)
    {
        real_cursor = real_cursor->ptr_to_prev_node;
    }*/
    //real_cursor = real_cursor->ptr_to_next_node;
    *cursor = head;
}

void go_end(Node** cursor)
{
    /*Node *real_cursor = (*cursor);
    while(real_cursor != head)
    {
        real_cursor = real_cursor->ptr_to_next_node;
    }
    real_cursor = real_cursor->ptr_to_prev_node;*/
    *cursor = head->ptr_to_prev_node;
}
