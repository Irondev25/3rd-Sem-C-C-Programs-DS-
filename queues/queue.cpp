// #include<iostream>

// using namespace std;

// struct node{
//     static struct node *head;
//     static struct node *rear;
//     int data;
//     struct node *link;
// };

// struct node * node::head = NULL;
// struct node * node::rear = NULL;

// void display(){
//     struct node *temp = node::head;
//     while (temp != NULL)
//     {
//         cout << " " << temp->data << " ";
//         temp = temp->link;
//     }
// }

// void enqueue(int data){
//     struct node* new_node = (struct node *)malloc(sizeof(struct node));
//     new_node->data = data;
//     new_node->link = NULL;
//     if(node::head == NULL && node::rear == NULL){
//         node::head = new_node;
//         node::rear = new_node;
//     }
//     else{
//         node::rear->link = new_node;
//         node::rear = new_node;
//     }
//     cout<<node::rear->data<<" is enqueued"<<endl;
//     display();
// }

// void denqueue(){
//     struct node *temp = node::head;
//     if(temp == NULL){
//         cout<<"Queue Empty"<<endl;
//         return;
//     }
//     node::head = node::head->link;
//     cout<<temp->data<<" is dequeued."<<endl;
//     free(temp);
//     display();
// }



// int menu(){
//     int ch;
//     cout<<"\n**Menu**\n1.Enqueue Data\n2.Dequeue Data\n3.Display Queue\n4.Exit\nEnter your choice: ";
//     cin>>ch;
//     return ch;
// }


// int main(){
//     int data;
//     while(1){
//         switch(menu()){
//             case 1:
//                 cout<<"Enter data to insert in queue: ";
//                 cin>>data; 
//                 enqueue(data);
//                 break;
//             case 2: denqueue();
//                 break;
//             case 3: display();
//                 break;
//             case 4: exit(0);
//                 break;
//             default: cout<<"Wrong Choice!!"<<endl;
//         }
//     }
//     return 0;
// }