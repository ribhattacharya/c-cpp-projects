/*
Sort linked list using bubble sort
C for Everyone: Structured Programming
Week 3
Rishabh Bhattacharya
Jul 7th, 2023


Program description: Create a linked list using random elements. Use bubble sort to sort the list.

--------------------OUTPUT-----------------------
Before sorting,
     210      82     656     994     306
     644     618     313     995     819
      82     103     181     612     327
     352     804       7     468     782
     302     374     580     627      26
     430     308     661     399     906
     208     446     651     720     851
     413     490      70     980     545
     930     832     427     760     807
     666     945     324     576     533
     994     865     770      96     478
     462     437     923     396     451
     906     732     609      36     866
     222    1000     887     747     995
      37     835     263     302     530
     484     833     893     128     276
      80     539     232     812     450
     711     540     686     179     515
     350     318     284     818     750
     978     304    1000      80     845


After sorting,
       7      26      36      37      70
      80      80      82      82      96
     103     128     179     181     208
     210     222     232     263     276
     284     302     302     304     306
     308     313     318     324     327
     350     352     374     396     399
     413     427     430     437     446
     450     451     462     468     478
     484     490     515     530     533
     539     540     545     576     580
     609     612     618     627     644
     651     656     661     666     686
     711     720     732     747     750
     760     770     782     804     807
     812     818     819     832     833
     835     845     851     865     866
     887     893     906     906     923
     930     945     978     980     994
     994     995     995    1000    1000


Sorted!
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define RANDOM_MIN 0
#define RANDOM_MAX 1000
#define N_INTEGERS 100

typedef struct node {int data; struct node *next;} Node;

Node* createNode(int d, Node *next){
    /*
    DESC: Creates mnew node from given data and next pointer.
    
    INPUTS:
        int d: Node data.
        Node *next: Pointer to next Node;
    OUTPUTS:
        Pointer to the newly created Node.
    */

    Node *new_node = malloc(sizeof(Node));
    new_node->data = d;
    new_node->next = next;

    return new_node;
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

int randInRange(){
    /*
    DESC: Return random integer.
    
    OUTPUTS:
        int : random integer within the range [RANDOM_MIN, RANDOM_MAX].
    */
    return rand() % (RANDOM_MAX - RANDOM_MIN + 1) + RANDOM_MIN;
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
        
        if (element++ % 5 == 0) printf("\n");
    }
}

int main(void){
    srand(time(NULL));
    
    Node *head = NULL;
    Node *n = head;
    
    for(int i=0; i<N_INTEGERS; i++){
        if (i > 0){
            // Can also be written as,
            // n = (n->next = createNode(randInRange(), NULL), n->next);
            n->next = createNode(randInRange(), NULL);
            n = n->next;
        }
        else{
            // Can also be written as,
            // head = (n = createNode(randInRange(), NULL), n);
            n = createNode(randInRange(), NULL);
            head = n;
        }
    }

    printf("\n\nBefore sorting,\n");
    printList(head);
    bubbleSort(head, N_INTEGERS);
    printf("\n\nAfter sorting,\n");
    printList(head);

    // Check if sorted by traversing over the entire LL.
    n = head;
    while(n->next != NULL){
        if (n->data > n->next->data){
            printf("\n\nNot sorted! Aborting!\n");
            return 1;
        }
        n = n->next;
    }
    
    printf("\n\nSorted!\n");
    return 0;
}