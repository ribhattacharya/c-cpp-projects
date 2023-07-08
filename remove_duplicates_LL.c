/*
Remove duplicates from doubly LL
C for Everyone: Structured Programming
Week 3
Rishabh Bhattacharya
Jul 7th, 2023


Program description: Create a doubly linked list using random elements. 
Use bubble sort to sort the list and remove duplicate elements.

--------------------OUTPUT-----------------------
Before removing duplicates,
      36       3      13      48      32      39      45      27      42      48
      28       7       1      18      20       7      40       3      10       5
       0      12       0      38      44      26      21      25      31      31
       0      39      49      11      42      19       2      40       2      27
      49      41      27      22      40      15      36       8      49      14
      24      40      32      46      23      37      23      42      32      25
      40      36       6      30      37       7       2      35      41      14
      42       9      24      11       0      27      47      25      25      29
      44      32      36      18      17      47      30       9      39      46
      21       2      24      33      14      25      22      49      17      34
      24      24      46      21      32       6      48       6      23      17
      27       1       0       0      28      20      34      43      18      45
      37      49      19      10      10      33      18      11       2       0
      10      36       7      45       3      23       8      41      30      13
       5       9      34       5       3      44       6      43      38      41
      29      42      44       1      25      30      41      27      43      15
      19      34      27      27      40      15       2      34      17      37
      28      44      39      25      16      37      24       2      43      31
      12      15      22      19      11       7       5      33      46       2
      19      37      11      10      31       9      10      18      40      31



After sorting,
       0       0       0       0       0       0       0       1       1       1
       2       2       2       2       2       2       2       2       3       3
       3       3       5       5       5       5       6       6       6       6
       7       7       7       7       7       8       8       9       9       9
       9      10      10      10      10      10      10      11      11      11
      11      11      12      12      13      13      14      14      14      15
      15      15      15      16      17      17      17      17      18      18
      18      18      18      19      19      19      19      19      20      20
      21      21      21      22      22      22      23      23      23      23
      24      24      24      24      24      24      25      25      25      25
      25      25      25      26      27      27      27      27      27      27
      27      27      28      28      28      29      29      30      30      30
      30      31      31      31      31      31      32      32      32      32
      32      33      33      33      34      34      34      34      34      35
      36      36      36      36      36      37      37      37      37      37
      37      38      38      39      39      39      39      40      40      40
      40      40      40      40      41      41      41      41      41      42
      42      42      42      42      43      43      43      43      44      44
      44      44      44      45      45      45      46      46      46      46
      47      47      48      48      48      49      49      49      49      49



After removing duplicates,
       0       1       2       3       5       6       7       8       9      10
      11      12      13      14      15      16      17      18      19      20
      21      22      23      24      25      26      27      28      29      30
      31      32      33      34      35      36      37      38      39      40
      41      42      43      44      45      46      47      48      49


Sorted and unique!
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define RANDOM_MIN 0
#define RANDOM_MAX 49
#define N_INTEGERS 200

typedef struct node{
    int data; 
    struct node *prev;
    struct node *next;
} Node;

typedef enum {false, true} bool;

Node* createNode(int d, Node *prev, Node *next){
    /*
    DESC: Creates new node from given data, previous pointer and next pointer.
    
    INPUTS:
        int d: Node data.
        Node *next: Pointer to previous Node;
        Node *prev: Pointer to next Node;
    OUTPUTS:
        Pointer to the newly created Node.
    */

    Node *new_node = malloc(sizeof(Node));
    new_node->data = d;
    new_node->prev = prev;
    new_node->next = next;

    return new_node;
}

Node* createDLL(int nums[], int SIZE) {
    /*
    DESC: Creates new doubly LL from given array and returns its head.
    
    INPUTS:
        int nums[]: LL node data.
        int SIZE: Length of LL/array.
    OUTPUTS:
        Head pointer to the newly created LL.
    */
    Node *head = NULL, *tail = NULL;
    
    for(int i=0; i<SIZE; i++){
        Node *new_node = createNode(nums[i], NULL, NULL);
        
        if (head == NULL){
            // First node in the list
            head = new_node;
            tail = new_node;
        } 
        else{
            // Linking the new node with the previous node
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    return head;
}

void printList(Node *head){
    /*
    DESC: Print LL.
    
    INPUTS:
        Node *head: LL head.
    */
    int element = 1;
    
    while (head != NULL){
        printf("%8d", head->data);
        head = head->next;
        
        if (element++ % 10 == 0) printf("\n");
    }
    printf("\n");
}

void removeNextNode(Node *cur){
    /*
    DESC: Remove next node from the list.
    
    INPUTS:
        Node *n: Node whose sucessor is to be removed.
    */
    Node *temp = cur->next;
    
    if (temp->next != NULL) // If cur is not the second last element, then fix prev.
        temp->next->prev = cur;

    cur->next = temp->next;
    
    free(temp);     // Deallocate memory
    temp = NULL;    // To prevent misuse of the pointer
}   

void removeDuplicates(Node *head){
    /*
    DESC: Remove duplicates from a list.
    
    INPUTS:
        Node *head: LL head.
    */
    while (head != NULL){
        // Keep removing nodes until a unique node is found
        while (head->next != NULL && head->data == head->next->data) 
            removeNextNode(head);
        
        head = head->next;
    }
}

int randInRange(){
    /*
    DESC: Return random integer.
    
    OUTPUTS:
        int : random integer within the range [RANDOM_MIN, RANDOM_MAX].
    */
    return rand() % (RANDOM_MAX - RANDOM_MIN + 1) + RANDOM_MIN;
}

void swap(int *d1, int *d2){
    /*
    DESC: Swap two values.
    
    INPUTS:
        int *d1: Data 1.
        int *d2: Data 2.
    */
    int temp = *d2;
    *d2 = *d1;
    *d1 = temp;
}

void bubbleSort(Node *head, int SIZE){
    /*
    DESC: Bubble sort the given LL head.
    
    INPUTS:
        Node *head: LL head.
        int SIZE: Length of LL.
    */
    for (int i=0; i<SIZE; i++) {
        Node *n = head;
        
        for (int j=SIZE-1; j>i; j--) {
            if (n->data > n->next->data)
                swap(&n->data, &n->next->data);
            n = n->next;
        }
    }
}

int checkResult(Node *head) {
    /*
    DESC: Check if final DLL is sorted and unique.
    
    INPUTS:
        Node *head: LL head.
    OUTPUTS:
        int: 0 (pass) or 1 (fail).
    */
    while(head->next != NULL){
        if (head->data >= head->next->data){
            if (head->data > head->next->data)
                printf("\n\nNot sorted! Aborting!\n");
            else
                printf("\n\nNot unique! Aborting!\n");
            
            return 1;
        }
        head = head->next;
    }
    printf("\n\nSorted and unique!\n");
    return 0;
}

int main(void){
    srand(time(NULL));
    
    // Populate array with random integers.
    // Can create LL directly, but an array helps while testing for bugs.
    int nums[N_INTEGERS] = {0};
    
    for(int i=0; i<N_INTEGERS; i++)
        nums[i] = randInRange();
    
    Node *head = createDLL(nums, N_INTEGERS);

    printf("\n\nBefore removing duplicates,\n");
    printList(head);
    
    bubbleSort(head, N_INTEGERS);
    printf("\n\nAfter sorting,\n");
    printList(head);

    removeDuplicates(head);
    printf("\n\nAfter removing duplicates,\n");
    printList(head);

    return checkResult(head);
}