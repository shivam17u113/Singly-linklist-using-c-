#include<iostream>
using namespace std;

typedef struct linklist
{
int data;
struct linklist *next;
}node;

node* getdata()
{
node *record=new node;

cout<<" enter the element      ";  cin>>record->data;
record->next=NULL;

return record;

}

node* insert_end(node *first)
{
node* newnode= getdata();
if(first ==NULL)
first=newnode;

else
{
node*move;
move=first;

while(move->next!=NULL)
move=move->next;

move->next=newnode;

}
return first;
}

node *insert_beg(node *first)
{
node *move, *newnode;
newnode=getdata();
move=first;

if(first==NULL)
first=newnode;
else
{
newnode->next=first;
first=newnode;
}
return first;
}

node*insert_pos(node *first)
{
node*move,*newnode;
newnode=getdata();
move=first;
int pos,count=1;

if(first==NULL)
first=newnode;

else
{
cout<<" \n enter the positon to insert     "; cin>>pos;

while(count!=pos-1)
{
move=move->next;
count++;
}

newnode->next=move->next;
move->next=newnode;
}
return first;
}

void display(node *first)
{
node*move;
if(first==NULL)
cout<<" list is empty     ";
else
{
move=first;

while(move!=NULL)
{
cout<<move->data;   cout<<"       ";
move=move->next;

}

}

}

node *delete_beg(node *first)
{
if(first==NULL)
cout<<" \n list is empty    ";
else
{
node *move;
move=first;

first=move->next;
move->next=NULL;

cout<<"\n deleted record is      "; cout<<move->data;

delete move;
}
return first;
}

node* delete_pos(node*first)
{
int pos ,count=1;
if(first==NULL)
cout<<" \n list is empty    ";
else
{
node *move,*temp;
move=first;

cout<<" \n enter the position     ";cin>>pos;

while(count!=pos)
{
temp=move;
move=move->next;
count++;

}
temp->next=move->next;


cout<<"\n deleted record is      "; cout<<move->data;

delete move;

}

return first;
}

node* delete_end(node *first)
{

if(first==NULL)
cout<<" \n list is empty    ";
else
{
node *move,*temp;
move=first;

while(move->next!=NULL)
{
temp=move;
move=move->next;

}

temp->next=NULL;
cout<<"\n deleted record is      "; cout<<move->data;

delete move;

}

return first;

}

void search(node *first)
{
int id,count=1;
cout<<" \n enter the record you want to search    ";cin>>id;
node *move;
move=first;

while(move!=NULL && move->data !=id)
{
move=move->next;
count++;
}

if(move==NULL)
cout<<"  \n element not found     ";
else
{
cout<<" the element found!!!!! at"<<count;

}


}




int main()
{
int ch;
node *first;
first=NULL;
do
{
cout<<"\n 1. insert at end \n 2. insert at beginig \n 3. insert at position \n 4.display  \n 5.delete at beginning \n 6. delete at end  \n 7. delete at position  \n 8. search \n0.exit";
cin>>ch;

switch(ch)
{
case 1:
first= insert_end(first);
break;

case 2:
first = insert_beg(first );
break;

case 3:
first = insert_pos(first);
break;

case 4:
display(first);
break;

case 5:
first=delete_beg(first);
break;

case 6:
first= delete_end(first);
break;

case 7:
first= delete_pos(first);
break;

case 8:
search(first);
break;
default :
cout<<" enter the correct option      ";

}
cout<<endl<<endl;
}while(ch!=0);


return 0;
}




















