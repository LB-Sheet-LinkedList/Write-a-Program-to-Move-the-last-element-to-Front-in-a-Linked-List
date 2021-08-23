/*
See logic in noteboook

Time Complexity: O(n) 
Space Complexity: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node 
{
    int data;              //node ka data
    struct Node* next;     //node ka next pointer
    
    //Taaki naya node jo bne usme already ek input ho and ek NULL pointer ho
    Node(int data)         //constructor
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList     
{
    struct Node *head;     //head pointer declare kiya of type Node
    
    //jab bhi nayi linked list bnaegi aur chaahe kitni bhi bane. agar usme abbhi tak kuch push nhi kiya hai to vo 
    // head1->NULL  head2->NULL ... isi form me hogi
	
	LinkedList()           //constructor
	{ 
		head = NULL;
		//ab jab bhi ek LL banegi tab ek head pointer automatically bnega alag se bnane ki garaz nhi 
	}
 
    /* Function to reverse the linked list */
    void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node *current = head;
        Node *prev = NULL; 
		Node *next = NULL;
 
        while (current != NULL) 
		{
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
    
    void Move2Front()
    {
    	/*
		2 pointers bnao jisme ek pointer me seond last ka address store ho and second me last ka address
		phir second last ka address null kar do and last ka next head kar do
		*/
		
		//agar LL pehle se khaali hai to loda kuch nhi ho sakta ab		
		if(head->next==NULL)
		{
			cout<<"\nNOT POSSIBBLE";
			return;
		}
		
		/*AGAR SIRF 2 ELEMENTS HOGE TO USKI CONDITION ADD KARO*/
		
		//2 pointers
		Node *last=head;
		Node *seclast=NULL;
		
		while(last->next!=NULL)
		{
			seclast=last;
			last=last->next;
		}
		last->next=head;  //next pointer ko change kiya
		seclast->next=NULL;
		head=last;  //naya head
	}
    
    /* Function to print linked list */
    void print()
    {
    	cout<<"\n";
        struct Node* temp = head;  //pointer hai jo head ki taraf point karega
        while (temp != NULL) 
		{
            cout << temp->data << "->";
            temp = temp->next;  //next element pe point karo
        }
        cout<<"NULL"<<endl;
    }
 
 	//push function define kiya
    void push(int data)
    {
    	//Node type ka hi iterator bnaya jaise int i bnaate apan
        Node* temp = new Node(data);
        
        temp->next = head;
        head = temp;
    }
};

/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    
    //tail me ek ek bharte jaao
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.push(5);
 
    cout << "Given linked list\n";
    ll.print();
 
 	/*
    ll.reverse();
 
    cout << "\nReversed Linked list \n";
    */
    
    cout << "\nModified LL => \n";
    ll.Move2Front();
    ll.print();
    return 0;
}
