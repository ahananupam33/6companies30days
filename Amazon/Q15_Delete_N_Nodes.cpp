#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}


class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        if(!head)return;
        
        int cnt = 0;
        while(head!=NULL && head->next){
            cnt++;
            if(cnt==M){
                Node* curr = head;
                int temp = N;
                while(temp--){
                    if(curr->next)
                        curr = curr->next;
                }
                head->next = curr->next;
                cnt = 0;
            }
            head = head->next;
        }
    }
};


int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}