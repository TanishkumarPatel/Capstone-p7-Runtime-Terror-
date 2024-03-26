#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
class Node
{
public:
int data;
Node *next;
Node(int data)
{
this->data=data;
this->next=NULL;
}
};
void insertatHead(Node* head,int data)
{
Node *temp=new Node(data);
temp->next=head->next;
head->next=temp;
}
void insertatTail(Node* &tail,int data)
{
Node* temp=new Node(data);
tail->next=temp;
tail=tail->next;
}
void print(Node* head)
{
Node* temp=head->next;
while(temp!=NULL){
cout<<temp->data<<" ";
temp=temp->next;
}
cout<<"\n";
}
void deleteatn(Node* head,int key)
{
Node* temp=head->next;
Node *prev=head;
while (temp->data!=key)
{
temp=temp->next;
prev=prev->next;
}

prev->next=temp->next;
temp->next=NULL;
delete(temp);
}
int main(){
Node* node1=new Node(10);
Node* head=new Node(0);
Node *tail=node1;
head->next=node1;
insertatTail(tail,12);
insertatTail(tail,69);
insertatHead(tail,14);
insertatHead(head,11);
insertatHead(head,13);
deleteatn(head,10);
print(head);
return 0;
}