//Linked list implementation
//Ref: Sayef Reyadh

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *link;

};


//insert
void insertFront(node *header, int data);
void insertLast(node *header, int data);
void insertAt(node *header, int data, int index);
void insertBeforeValue(node *header, int data, int value);
void insertSortedOrder(node *header, int data);

//update
void updateFront(node *header, int data);
void updateLast(node *header, int data);
void updateAt(node *header, int data, int index);
void updateValue(node *header, int data, int value);

//delete
void deleteFront(node *header);
void deleteLast(node *header);
void deleteAt(node *header, int index);
void deleteValue(node *header, int value);

//search
int searchIndexOfValue(node *header, int data);
int valueOfIndex(node *header, int index);

//print
void printList(node *header);

int main()
{   
    node *header;

    header = (node *)malloc(sizeof(node));

    if(header == NULL){
        cout << "Memory Not Available" << endl;
        return 0;
    }

    header->data = INT_MAX;
    header->link = NULL;

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int num = rand()%1000;
        cout << num << " ";
        insertSortedOrder(header, num);
    }
    cout << endl;

    // printList(header);
    // updateAt(header, 5000, 5);
    // printList(header);
    // deleteAt(header, 5);
    // printList(header);
    // deleteFront(header);
    // deleteLast(header);
    // printList(header);

    // updateAt(header, 1000, 5);

    // printList(header);

    // int value;
    // cin>>value;

    // cout << searchIndexOfValue(header, value) << endl;

    // insertAt(header, 200, 3);

    // cout << valueOfIndex(header, 3) << endl;
}


// head - n0 - n1 - n2 - n3 - n4 - n5
void printList(node *header)
{
    node *ptr = header->link;

    while( ptr != NULL ){
        cout << ptr->data << " ";
        ptr = ptr->link;
    }

    cout << endl;
}


// head - n0 - n1 - n2 - n3 - n4 - n5
int searchIndexOfValue(node *header, int data)
{
    node *ptr = header->link;
    int index = 0;

    while(ptr->data != data && ptr != NULL){
        index++;
        ptr = ptr->link;
    }

    if(ptr->data == data){
        return index;
    }
    else{
        return -1;
    }
}


// head - n0 - n1 - n2 - newNode - n3 - n4 - n5
int valueOfIndex(node *header, int index)
{
    node *ptr = header->link;
    int i=0;

    do{
        if(ptr == NULL){
            cout << "Out of bound or empty list" << endl;
            return -999999999;
        }
        else{
            i++;
            ptr = ptr->link;
        }
    }while(i != index);

    return ptr->data;
}


// head - newNode - n0 - n1 - n2 - n3 - n4 - n5
void insertFront(node *header, int data)
{
    node *newNode; 

    newNode = (node *)malloc(sizeof(node));

    if(newNode == NULL){
        cout << "Memory not available" << endl;
    }
    else{
        newNode->data = data;
        newNode->link = header->link;
        header->link = newNode;
    }

}


// head - n0 - n1 - n2 - n3 - n4 - n5 - newNode
void insertLast(node *header, int data)
{
    node *ptr = header;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }

    node *newNode;
    newNode = (node *)malloc(sizeof(node));

    if(newNode == NULL){
        cout << "Memory not available" << endl;
    }
    else{
        newNode->data = data;
        newNode->link = ptr->link;
        ptr->link = newNode;
    }
}


// head - n0 - n1 - n2 - newNode - n3 - n4 - n5
void insertAt(node *header, int data, int index)
{
    node *ptr = header;

    int indexCheck = -1;

    while(indexCheck < index - 1 && ptr->link != NULL){
        indexCheck++;
        ptr = ptr->link;
    }

    if(indexCheck+1 != index){
        cout << "Out of bound" << endl;
    }
    else{
        node *newNode;
        newNode = (node *)malloc(sizeof(node));

        if(newNode == NULL){
            cout << "Memory not available" << endl;
        }
        else{
            newNode->data = data;
            newNode->link = ptr->link;
            ptr->link = newNode;
        }
    }

}


void insertSortedOrder(node *header, int data)
{
    node *ptr = header->link;
    node *pred;
    node *newNode = (node *)malloc(sizeof(node));

    if(ptr == NULL || ptr->data > data){    // '<' for descending order
        newNode->data = data;
        newNode->link = ptr;
        header->link = newNode;
    }
    else{
        pred = header;
        while(ptr != NULL && ptr->data < data){    // '>' for descending order
            pred = ptr;
            ptr = ptr->link;
        }
        newNode->data = data;
        newNode->link = pred->link;
        pred->link = newNode;
    }
}


//head - n0 - n1 - n2 - n3 - n4 - n5
void insertBeforeValue(node *header, int data, int value)
{
    int index = searchIndexOfValue(header, value);
    insertAt(header, data, index);
}


//head - n0
void updateFront(node *header, int data)
{
    // node *ptr = header->link;
    // ptr->data = data;

    header->link->data = data;
}


//head - n0 - n1 - n2 - n3 - n4 - n5
void updateLast(node *header, int data)
{
    node *ptr = header;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }

    ptr->data = data;
}


//head - n0 - n1 - n2 - n3 - n4 - n5
void updateAt(node *header, int data, int index)
{
    node *ptr = header;
    int indexCheck = -1;

    while(indexCheck < index - 1 && ptr->link != NULL){
        indexCheck++;
        ptr = ptr->link;
    }

    if(indexCheck+1 != index){
        return;
    }

    ptr->link->data = data;
}


void updateValue(node *header, int data, int value)
{
    int index = searchIndexOfValue(header, value);
    updateAt(header, data, index);
}


//head - n0 - n1 - n2 - n3 - n4 - n5
void deleteFront(node *header)
{
    if(header->link == NULL){
        return;
    }

    node *ptr = header->link;

    header->link = ptr->link;

    free(ptr);
}


//head - n0 - n1 - n2 - n3 - n4 - n5
void deleteLast(node *header)
{
    if(header->link == NULL){
        return;
    }

    node *ptr = header;

    while(ptr->link->link != NULL){
        ptr = ptr->link;
    }

    free(ptr->link);

    ptr->link = NULL;
}


//head - n0 - n1 - n2 - n3 - n4 - n5
void deleteAt(node *header, int index)
{
    if(header->link == NULL){
        return;
    }

    node *ptr = header;
    int indexCheck = -1;

    while(indexCheck < index - 1 && ptr->link != NULL){
        indexCheck++;
        ptr = ptr->link;
    }

    if(indexCheck + 1 != index){
        return;
    }

    node *temp = ptr->link->link;
    free(ptr->link);
    ptr->link = temp;
}


void deleteValue(node *header, int value)
{
    int index = searchIndexOfValue(header, value);
    deleteAt(header, index);
}