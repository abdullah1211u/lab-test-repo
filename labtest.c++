#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node*next;
    Node(int value)
    {
        data=value;
        next=NULL;
    }
};

struct stack
{

    Node*head;

    stack()
    {

        head=NULL;
    }

    void push(int value)
    {
        Node*newNode=new Node(value);
        newNode->next=head;
        head=newNode;
    }

    int pop2nd()
    {
        if(head == NULL || head->next == NULL)
        {
            cout<<"Not enough Elements"<<endl;
            return -1;
        }
        Node*secondNode = head->next;
        head->next= secondNode->next;

        delete secondNode;
        return secondNode->data;

    }
    void display()
    {
        Node*current=head;
        while(current != NULL)
        {
            cout<<current->data<<endl;
            current=current->next;
        }
        cout<<endl;

    }

};

struct queueNode
{

    int data;
    queueNode*next;

    queueNode(int value)
    {
        data=value;
        next=NULL;
    }
};

struct Queue
{
    queueNode*front;
    queueNode*rear;

    Queue(int value)
    {
        front=nullptr;
        rear=nullptr;
    }

    bool empty()
    {
        return front ==NULL;
    }


    void enqueue(int value)
    {
        queueNode*newNode=new queueNode(value);

        if(empty())
        {
            front=rear=newNode;
        }
        else
        {
            rear->next=newNode;
            rear=newNode;
        }
    }

    void dequeue()
    {
        if(!empty())
        {
            queueNode*temp=front;
            front=front->next;
            delete temp;
        }
    }

    int frontValue()
    {
        if(!empty())
        {
            return front->data;
        }
        return -1;
    }

    void display()
    {
        queueNode* current=front;
        while(current != NULL)
        {
            cout<<current->data<<endl;
            current=current->next;
        }
        cout<<endl;

    }

};



int main()

{

    stack mystack;
    Queue queue(50);

    int numElements;
    cout<<"Enter Number of elements:";
    cin>>numElements;

    for(int i=0; i<numElements; i++)
    {
        int value;
        cout<<"Enter elements:";
        cin>>value;
        mystack.push(value);

    }
    cout<<"Elements After push:"<<endl;
    mystack.display();
    mystack.pop2nd();
    mystack.pop2nd();
    cout<<"Elements after Pop second:"<<endl;
    mystack.display();



    //for insert popped value from stack poped

    int popvalue = mystack.pop2nd();

    if(popvalue !=-1)
    {
       queue.enqueue(popvalue);
    }

    cout<<"queue elements after pop value:";


    while(!queue.empty())
    {
      cout<<queue.frontValue()<<" "<<endl;
      queue.dequeue();
    }


    queue.display();



    return 0;
}
