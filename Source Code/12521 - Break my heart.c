#include<stdio.h>
typedef struct Node{
    int num;
    struct Node *next;
}Node;
int main(void)
{
    int i,n,ins_num,ins_l,ins_r,ins_flag,first_print;
    Node *head = malloc(sizeof(Node));
    head->num = -1;
    head->next = NULL;
    char ins_type[23] = {0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",&ins_type);
        if(ins_type[0] == 'i')
        {
            scanf("%d",&ins_num);
            //printf("%d\n",ins_num);
            Node *now = head;
            ins_flag = 0;
            while(now->next != NULL)
            {
                if(now->next->num > ins_num)
                {
                    ins_flag = 1;
                    break;
                }
                else if(now->next->num == ins_num)
                {
                    ins_flag = 2;
                    break;
                }
                now = now->next;
            }
            if(ins_flag == 0)
            {
                now->next = malloc(sizeof(Node));
                now->next->num = ins_num;
                now->next->next = NULL;
            }
            else if(ins_flag == 1)
            {
                Node *next_node = now->next;
                now->next = malloc(sizeof(Node));
                now->next->num = ins_num;
                now->next->next = next_node;
            }

        }
        else if(ins_type[0] == 'p')
        {
            Node *now = head->next;
            first_print = 1;
            while(now != NULL)
            {
                if(first_print == 1)
                {
                    printf("%d",now->num);
                    first_print = 2;
                }
                else
                {
                    printf(" %d",now->num);
                }
                now = now->next;
            }
            if(first_print == 2)
            {
                printf("\n");
            }
        }
        else if(ins_type[0] == 'm')
        {
            Node *now = head->next;
            if(now != NULL)
            {
                printf("%d\n",now->num);
            }
        }
        else if(ins_type[0] == 'r')
        {
            scanf("%d %d",&ins_l,&ins_r);
            Node *now = head;
            ins_flag = 0;
            while(now->next != NULL)
            {
                if(now->next->num >= ins_l)
                {
                    ins_flag = 1;
                    break;
                }
                now = now->next;
            }
            while(now->next != NULL)
            {
                if(now->next->num > ins_r)
                {
                    break;
                }
                Node *delete_node = now->next;
                Node *next_node = now->next->next;
                now->next = next_node;
                free(delete_node);

            }
        }
    }
    return 0;
}
