#include <stdio.h>

// Insertion Algorithm
// 1. Start
// 2. Set J = N
// 3. Set N = N + 1
// 4. Repeat steps 5 and 6 while J >= K
// 5. Set LA[J+1] = LA[J]
// 6. Set J = J - 1
// 7. Set LA[K] = ITEM
// 8. Stop

int insert(int LA[], int N, int K, int ITEM) {
    int J = N;
    N = N + 1;
    
    while (J >= K) {
        LA[J + 1] = LA[J];
        J = J - 1;
    }
    
    LA[K] = ITEM;
    return N;
}

// Deletion Algorithm
// 1. Start
// 2. Set deletedItem = LA[K]
// 3. Repeat for i = K to N-2
// 4. Set LA[i] = LA[i+1]
// 5. Set N = N - 1
// 6. Stop

int delete(int LA[], int N, int K) {
    int deletedItem = LA[K];
    
    for (int i = K; i < N - 1; i++) {
        LA[i] = LA[i + 1];
    }
    
    printf("Deleted %d from position %d\n", deletedItem, K);
    return N - 1;
}

// Search Algorithm
// 1. Start
// 2. Repeat for i = 0 to N-1
// 3. If LA[i] == ITEM then return i
// 4. If not found return -1
// 5. Stop

int search(int LA[], int N, int ITEM) {
    for (int i = 0; i < N; i++) {
        if (LA[i] == ITEM) {
            return i;
        }
    }
    return -1;
}

int main() {
    int LA[100] = {10, 20, 30, 40, 50};
    int N = 5;
    
    printf("Original Array: ");
    for(int i=0; i<N; i++) printf("%d ", LA[i]);
    printf("\n");
    
    N = insert(LA, N, 2, 99);
    printf("After insertion: ");
    for(int i=0; i<N; i++) printf("%d ", LA[i]);
    printf("\n");
    
    int pos = search(LA, N, 99);
    if(pos != -1) 
        printf("Item 99 found at position %d\n", pos);
    
    N = delete(LA, N, 2);
    printf("After deletion: ");
    for(int i=0; i<N; i++) printf("%d ", LA[i]);
    
    return 0;

}
