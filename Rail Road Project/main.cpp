#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class rail
{
public:
    struct node *start = NULL;
    struct node *header;
    
    rail() // CONSTRUCTOR
    {
        header=new node;
        header->data=0;
        header->next=NULL;
    }
};

class llist : public rail
{
public:
//Creating a Linked List
struct node *create_ll(struct node **start)
{
         struct node *new_node, *ptr;
         int num;
         cout<<"\n Enter -1 to end"<<endl;
         cout<<"\n Enter the data : "<<endl;
         cin>>num;
while(num!=-1)
{
new_node = new node;
new_node -> data=num;
if(*start==NULL)
{
    header->next=new_node;
    header->data++;
    new_node -> next = NULL;
    *start = new_node;
}
else
{
    header->next=*start;
    header->data++;
    ptr=*start;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next = new_node;
    new_node->next=NULL;
}
cout<<"\n Enter the data : "<<endl;
scanf("%d", &num);
}
return *start;
}



//Inserting an element begining of the linked list
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    if(start!=NULL)
    {
    cout<<"Enter data to insert at beginning of the list\n"<<endl;
    cin>>num;
    new_node = new node;
    new_node->data=num;
    new_node->next=start;
    start=new_node;
        header->next=start;
        header->data++;
    }
    else
        cout<<"List does not exist\n"<<endl;
    return start;
}

//Insering element at end of the list
struct node *insert_end(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    if(start!=NULL)
    {
    cout<<"Enter data to add at end of list\n"<<endl;
    cin>>num;
    new_node=new node;
    new_node->data=num;
    new_node->next=NULL;
    ptr=start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=new_node;
        header->data++;
    }
    else
        cout<<"List does not exist\n"<<endl;
   return start;
}

//Inserting element before an element in a list
struct node *insert_before(struct node *start)
{
    struct node *new_node,*prev_ptr,*after_ptr;
    int num,x;
    if(start!=NULL)
    {
    cout<<"Enter the element before which data is to be added\n"<<endl;
    cin>>x;
        if(start->data==x)
            start=insert_beg(start);
        else
        {
    cout<<"Enter the data to be added before "<<x;
    cin>>num;
    new_node=new node;
    new_node->data=num;
    prev_ptr=start;
    after_ptr=start;
    while(after_ptr->data!=x)
    {
        prev_ptr=after_ptr;
        after_ptr=after_ptr->next;
    }
    new_node->next=after_ptr;
    prev_ptr->next=new_node;
            header->data++;
    }
    }
    else
        cout<<"List does not exist\n"<<endl;
    return start;
}

//Inserting an element after an element in a list
struct node *insert_after(struct node *start)
{
    struct node *new_node,*prev_ptr,*after_ptr,*ptr;
    int num,x;
    ptr=start;
    if(start!=NULL)
    {
    cout<<"Enter the element after which data is to be added\n"<<endl;
    cin>>x;
        {
    cout<<"Enter data to be added after "<<x<<endl;
    cin>>num;
    new_node=new node;
    new_node->data=num;
    prev_ptr=start;
    after_ptr=start;
    while(prev_ptr->data!=x)
    {
        prev_ptr=after_ptr;
        after_ptr=after_ptr->next;
    }
    new_node->next=after_ptr;
    prev_ptr->next=new_node;
            header->data++;
    }
    }
    else
        cout<<"List does not exist\n"<<endl;
    return start;
}

//Insert an element at the given position
struct node *insert_pos(struct node *start)
{
    struct node *new_node,*ptr,*prev_ptr;
    int num,pos,x=1,len=0;
    prev_ptr=start;
    ptr=start;
    while(ptr!=NULL)
    {
        len++;
        ptr=ptr->next;
    }
    ptr=start;
    cout<<"Enter the position to which the data is to be added\n"<<endl;
    cin>>pos;
    if(pos==1)
        start=insert_beg(start);
    else if(pos==len)
        start=insert_end(start);
    else if(pos>len || pos<0)
        cout<<"Invalid position \n"<<endl;
    else
    {
    cout<<"Enter the data to be added at position "<<pos<<endl;
    cin>>num;
    new_node=new node;
    new_node->data=num;
    while(x!=pos)
    {
        prev_ptr=ptr;
        x++;
        ptr=ptr->next;
    }
    new_node->next=ptr;
    prev_ptr->next=new_node;
        header->data++;
    }
    return start;
}

//Deleting an element at the begining of the list
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    if(start!=NULL)
    {
    ptr=start;
    start=ptr->next;
    free(ptr);
        header->next=start;
        header->data--;
    }
    else
        cout<<"List does not exist\n"<<endl;
    return start;
}

//Deleting an element at the end of the list
struct node *delete_end(struct node *start)
{
    struct node *ptr,*pre_ptr;
    if(start!=NULL)
    {
    ptr=start;
    pre_ptr=start;
    while(ptr->next!=NULL)
    {
        pre_ptr=ptr;
        ptr=ptr->next;
    }
    pre_ptr->next=NULL;
    free(ptr);
        header->data--;
    }
    else
        cout<<"List does not exist\n"<<endl;
    return start;
}

//Deleting an element after a given element in the list
struct node *delete_after(struct node *start)
{
    struct node *key,*prev_ptr;
    int x;
    if(start!=NULL)
    {
    cout<<"Enter the number to delete its next element\n"<<endl;
    cin>>x;
    prev_ptr=start;
    key=start;
    prev_ptr=start;
    while(prev_ptr->data!=x)
    {
        prev_ptr=key;
        key=key->next;
    }
    prev_ptr->next=key->next;
    free(key);
        header->data--;
    }
    else
        cout<<"List does not exist\n"<<endl;
    return start;
}

//Deleting an element before an element in a list
struct node *delete_before(struct node *start)
{
    struct node *ptr,*prev_ptr;
    int key;
    if(start!=NULL)
    {
    cout<<"Enter an element to delete its previous element\n"<<endl;
    cin>>key;
        if(start->next->data==key)
            start=delete_beg(start);
        else
        {
    ptr=start;
    prev_ptr=start;
    while(ptr->next->data!=key && ptr->next!=NULL)
    {
        prev_ptr=ptr;
        ptr=ptr->next;
    }
    prev_ptr->next=ptr->next;
    free(ptr);
            header->data--;
    }
    }
    else
        cout<<"List does not exist\n"<<endl;
    return start;
}

//Delete at a given position
struct node *delete_pos(struct node *start)
{
    struct node *ptr,*pre_ptr;
    int pos,x=1,len=0;
    ptr=start;
    pre_ptr=start;
    while(ptr!=NULL)
    {
        len++;
        ptr=ptr->next;
    }
    ptr=start;
    cout<<"Enter the position at which the data is to be deleted\n"<<endl;
    cin>>pos;
    if(pos==1)
        start=delete_beg(start);
    else if(pos==len)
        start=delete_end(start);
    else if(pos>len || pos<0)
        cout<<"Invalid position \n"<<endl;
    else
    {
    while(x!=pos)
    {
        pre_ptr=ptr;
        ptr=ptr->next;
        x++;
    }
    pre_ptr->next=ptr->next;
    free(ptr);
        header->data--;
    }
    return start;
}

//Searching a key element in the list
struct node *searching(struct node *start)
{
    struct node *ptr;
    int key,x=0,pos=1;
    if(start!=NULL)
    {
    ptr=start;
    cout<<"Enter the element to search\n"<<endl;
    cin>>key;
    while(ptr!=NULL)
    {
        if(ptr->data==key)
        {
            x++;
            cout<<key<<" is found at position - "<<pos<<endl;
        }
        pos++;
        ptr=ptr->next;
    }
    if(x==0)
        cout<<key<<" is not found\n";
        else
            cout<<key<<" is found - "<<x<<" time\n";
    }
    else
        cout<<"List does not exist\n"<<endl;
    return start;
}
    
    void display(struct node *start);
};
    //Displaying the linked list
    void llist::display(struct node *start)
    {
    struct node *ptr;
    ptr = start;
        cout<<endl;
        cout<<"ōō|["<<header->data<<"]|";
    while(ptr!=NULL)
    {
    cout<<"-----["<<ptr -> data<<"]";
    ptr = ptr -> next;
    }
        cout<<endl;
     
    return ;
    }

//Main function
int main()
{
    int trains;
    cout<<"*******************************************************************************\n\n";
    cout<<"                     RAIL ROAD USING LINKED LIST                                \n\n";
    cout<<"*******************************************************************************\n\n";
    
    cout<<"Enter number of trains you wanna create\n";
    cin>>trains;

    llist r[trains];
    int k;
    
    //CREATING
    for(k=0;k<trains;k++)
    {
        cout<<"\n\n------------------------------"<<"Train"<<k+1<<"------------------------------\n"<<endl;
    int ch;
    cout<<"Rail Road Menu:"<<endl;
    cout<<"1.Create"<<endl;
    cout<<"2.Display"<<endl;
    cout<<"3.Insert beginning"<<endl;
    cout<<"4.Insert end"<<endl;
    cout<<"5.Insert before"<<endl;
    cout<<"6.Insert after"<<endl;
    cout<<"7.Delete beginning"<<endl;
    cout<<"8.Delete end"<<endl;
    cout<<"9.Delete after"<<endl;
    cout<<"10.Delete before"<<endl;
    cout<<"11.Searching"<<endl;
    cout<<"12.Insert at given position"<<endl;
    cout<<"13.Delete at given position"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"\nEnter your choice"<<endl;
    cin>>ch;
        cout<<endl;
    while(ch!=0)
    {
    switch (ch)
    {
        case 1 :  r[k].start=r[k].create_ll(&r[k].start);
            break;
        case 2 :  r[k].display(r[k].start);
            break;
        case 3 :  r[k].start=r[k].insert_beg(r[k].start);
            break;
        case 4 : r[k].start=r[k].insert_end(r[k].start);
            break;
        case 5 : r[k].start=r[k].insert_before(r[k].start);
            break;
        case 6 : r[k].start=r[k].insert_after(r[k].start);
            break;
        case 7 : r[k].start=r[k].delete_beg(r[k].start);
            break;
        case 8 : r[k].start=r[k].delete_end(r[k].start);
            break;
        case 9 : r[k].start=r[k].delete_after(r[k].start);
            break;
        case 10 : r[k].start=r[k].delete_before(r[k].start);
            break;
        case 11 : r[k].start=r[k].searching(r[k].start);
            break;
        case 12 : r[k].start=r[k].insert_pos(r[k].start);
            break;
        case 13 : r[k].start=r[k].delete_pos(r[k].start);
            break;
    }
        
        cout<<"\n\n------------------------------"<<"Train"<<k+1<<"------------------------------\n"<<endl;
        cout<<"Rail Road Menu:"<<endl;
        cout<<"1.Create"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Insert beginning"<<endl;
        cout<<"4.Insert end"<<endl;
        cout<<"5.Insert before"<<endl;
        cout<<"6.Insert after"<<endl;
        cout<<"7.Delete beginning"<<endl;
        cout<<"8.Delete end"<<endl;
        cout<<"9.Delete after"<<endl;
        cout<<"10.Delete before"<<endl;
        cout<<"11.Searching"<<endl;
        cout<<"12.Insert at given position"<<endl;
        cout<<"13.Delete at given position"<<endl;
        cout<<"0.Exit"<<endl;
        
        cout<<"\nEnter your choice"<<endl;
        cin>>ch;
        cout<<endl;
    }
    }
    
    
    //EDITING
    char y_n;
    cout<<"\n\n************************************************************************\n\n";
    cout<<"Wanna edit any data[YES(Y)/NO(N)]?\n";
    cin>>y_n;
    if(y_n=='Y')
    {
      
        cout<<"Enter the train you wanna edit or Press 0 to exit\n";
        cin>>k;
        k=k-1;
        while(k!=-1)
        {
    
        cout<<"\n\n------------------------------"<<"Train"<<k+1<<"------------------------------\n"<<endl;
    int ch;
    cout<<"Rail Road Menu:"<<endl;
    cout<<"1.Create"<<endl;
    cout<<"2.Display"<<endl;
    cout<<"3.Insert beginning"<<endl;
    cout<<"4.Insert end"<<endl;
    cout<<"5.Insert before"<<endl;
    cout<<"6.Insert after"<<endl;
    cout<<"7.Delete beginning"<<endl;
    cout<<"8.Delete end"<<endl;
    cout<<"9.Delete after"<<endl;
    cout<<"10.Delete before"<<endl;
    cout<<"11.Searching"<<endl;
    cout<<"12.Insert at given position"<<endl;
    cout<<"13.Delete at given position"<<endl;
    cout<<"0.Exit"<<endl;
            
    cout<<"\nEnter your choice"<<endl;
    cin>>ch;
            cout<<endl;
    while(ch!=0)
    {
    switch (ch)
    {
        case 1 :  r[k].start=r[k].create_ll(&r[k].start);
            break;
        case 2 :  r[k].display(r[k].start);
            break;
        case 3 :  r[k].start=r[k].insert_beg(r[k].start);
            break;
        case 4 : r[k].start=r[k].insert_end(r[k].start);
            break;
        case 5 : r[k].start=r[k].insert_before(r[k].start);
            break;
        case 6 : r[k].start=r[k].insert_after(r[k].start);
            break;
        case 7 : r[k].start=r[k].delete_beg(r[k].start);
            break;
        case 8 : r[k].start=r[k].delete_end(r[k].start);
            break;
        case 9 : r[k].start=r[k].delete_after(r[k].start);
            break;
        case 10 : r[k].start=r[k].delete_before(r[k].start);
            break;
        case 11 : r[k].start=r[k].searching(r[k].start);
            break;
        case 12 : r[k].start=r[k].insert_pos(r[k].start);
            break;
        case 13 : r[k].start=r[k].delete_pos(r[k].start);
            break;
    }
        
        cout<<"------------------------------"<<"Train"<<k+1<<"------------------------------\n";
        
        cout<<"Rail Road Menu:"<<endl;
        cout<<"1.Create"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Insert beginning"<<endl;
        cout<<"4.Insert end"<<endl;
        cout<<"5.Insert before"<<endl;
        cout<<"6.Insert after"<<endl;
        cout<<"7.Delete beginning"<<endl;
        cout<<"8.Delete end"<<endl;
        cout<<"9.Delete after"<<endl;
        cout<<"10.Delete before"<<endl;
        cout<<"11.Searching"<<endl;
        cout<<"12.Insert at given position"<<endl;
        cout<<"13.Delete at given position"<<endl;
        cout<<"0.Exit"<<endl;
        
        cout<<"\nEnter your choice"<<endl;
        cin>>ch;
        cout<<endl;
    }
            cout<<"Enter the train you wanna edit or Press 0 to exit\n";
            cin>>k;
            k=k-1;
    }
    }
    cout<<"Display:\n";
    for(int k=0;k<trains;k++)
    {
        
        cout<<"Train "<<k+1<<endl;
        r[k].display(r[k].start);
        cout<<"\n\n";
    }
    
    cout<<"\n\n*************************************************************************\n\n";
    cout<<"                                 THANK YOU                                    ";
    cout<<"\n\n*************************************************************************\n\n";
    return 0;
}



