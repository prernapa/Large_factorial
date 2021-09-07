#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* previous;
};

 struct node* tail = NULL;
        


void multiply(struct node* tail, int n) {
    struct node* dummy = tail;
    struct node* prevnode = tail;
    
    int carry = 0;
    while(dummy != NULL) {
        int temp = dummy ->data * n + carry;
        dummy->data = temp % 10; //last digit of the multiplicative number and rest we will move into carry.
        carry = temp / 10;
        prevnode = dummy;
        dummy = dummy -> previous;
    }
    
    //creating new node for carry if required
    while(carry != 0) {
        struct node* for_carry = (struct node*) malloc (sizeof(struct node*));
        prevnode->previous = for_carry;
        prevnode->data = carry % 10;
        carry = carry / 10;
        prevnode = prevnode->previous;
        
    }
    
}

//printing linkedlist using recursion
void print_ll(struct node* tail) {
    if(tail == NULL) {
        return ;
    }
    print_ll(tail->previous);
    printf("%d",tail->data);
}


int main() {
    int t;// testcases
    scanf("%d",&t);
    while(t--) {
        int n;//number whose factorial need to be calculated
        scanf("%d",&n);
        tail->data = 1;
        tail->previous = NULL;
        print_ll(&tail);
        
        for(int i = 2; i <= n; i++) {
            multiply(&tail, i);
        }
        printf("factorial of %d is : ",n);
        print_ll(&tail);
        printf("\n");
    }
}
