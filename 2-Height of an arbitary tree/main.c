#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
int max(int a,int b);
struct node
{
    int key;
    int kidsNum;
    node *kids[5]; //array of kids nodes
};

node *createNode(int key);
void addChild(node *head,int key,int parentKey);
void traveseTillFindAkey(node *head , int key);
void printTree(node *head);
int calculateHeight(node *head);


node * global;
int flag=0;

int main()
{
    node *head = createNode(1);
    head->kidsNum=0;

    addChild(head,2,1);
    addChild(head,3,1);
    addChild(head,6,3);
    addChild(head,4,3);
    addChild(head,4,3);

    int h = calculateHeight(head);
    printf("%d",h);

    return 0;
}

int arrMax(int arr[],int numOfelements)
{
    int max=0;
    for(int i=0; i<numOfelements ;i++)
        if(arr[i]>max) max = arr[i];
    return max;
}

node *createNode(int key)
{
    node *rtnNode = (node*) malloc(sizeof(node));
    rtnNode->key = key;
    rtnNode->kidsNum = 0;
    rtnNode->kids[0] = NULL;
    return rtnNode;
}

void addChild(node *head,int key,int parentKey)
{
    node *child = createNode(key);
    global = NULL;
    traveseTillFindAkey(head,parentKey);
    node *tmp = global;
    if(tmp != NULL)
    {
        tmp->kids[tmp->kidsNum] = createNode(key);
        tmp->kidsNum++;
    }
}


int max(int a,int b)
{
    return a>b ? a:b;
}



void traveseTillFindAkey(node *head , int key)
{
    if(head == NULL) return;
    if(flag) return; //end recursion
    if(head->key == key) {global = head; flag = 1;}

    for(int i=0; i< head->kidsNum; i++)
        traveseTillFindAkey(head->kids[i],key);
    flag = 0;
}

void printTree(node *head) //pre-order traversal
{
    if(head == NULL) return;
    printf("%d\n", head->key);
    for(int i=0; i< head->kidsNum; i++)
        printTree(head->kids[i]);
}



int calculateHeight(node *head)
{
    int count[10]={0};
    if(head->kidsNum == 0) return 1;

    else
    {
        for(int i=0; i < (head->kidsNum) ; i++)
            count[i] = 1+calculateHeight(head->kids[i]);
        return (arrMax(count,head->kidsNum));
    }
}



