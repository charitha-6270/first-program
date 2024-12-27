#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_STR_LEN 100

// Linked List Node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Binary Tree Node
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Graph
int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

// Function Prototypes
void linkedListMenu();
void binaryTreeMenu();
void graphMenu();
void advancedStatisticsMenu();
void textProcessingMenu();
void hangmanGame();
void mazeSolver();
void shellSimulation();
void memoryAllocationVisualization();

// Linked List Functions
Node* createNode(int data);
void insertAtEnd(Node** head, int data);
void deleteNode(Node** head, int key);
void displayLinkedList(Node* head);

// Binary Tree Functions
TreeNode* insertTreeNode(TreeNode* root, int data);
void inorderTraversal(TreeNode* root);
void preorderTraversal(TreeNode* root);
void postorderTraversal(TreeNode* root);

// Graph Functions
void bfs(int startNode, int totalNodes);
void dfs(int startNode, int totalNodes);

// Advanced Statistics Functions
void calculateCorrelation(int arrX[], int arrY[], int n);
void regressionLine(int arrX[], int arrY[], int n);

// Text Processing Functions
void wordFrequencyAnalysis(char* text);
void encryptText(char* text, int key);
void decryptText(char* text, int key);

// Simulation Functions
void startHangman();
void solveMaze(int maze[][5], int x, int y, int solution[][5]);
void displayMazeSolution(int solution[][5]);

// System Operations
void simulateShell();
void visualizeMemoryAllocation();

// Main Menu (Extended)
void extendedMenu() {
    int choice;
    while (1) {
        printLine();
        printf("Extended Features Menu\n");
        printf("1. Linked List Operations\n");
        printf("2. Binary Search Tree Operations\n");
        printf("3. Graph Algorithms\n");
        printf("4. Advanced Statistics\n");
        printf("5. Text Processing\n");
        printf("6. Hangman Game\n");
        printf("7. Maze Solver\n");
        printf("8. Shell Simulation\n");
        printf("9. Memory Allocation Visualization\n");
        printf("10. Exit to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                linkedListMenu();
                break;
            case 2:
                binaryTreeMenu();
                break;
            case 3:
                graphMenu();
                break;
            case 4:
                advancedStatisticsMenu();
                break;
            case 5:
                textProcessingMenu();
                break;
            case 6:
                hangmanGame();
                break;
            case 7:
                mazeSolver();
                break;
            case 8:
                shellSimulation();
                break;
            case 9:
                memoryAllocationVisualization();
                break;
            case 10:
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

/* Linked List Menu */
void linkedListMenu() {
    Node* head = NULL;
    int choice, data;
    while (1) {
        printLine();
        printf("Linked List Operations\n");
        printf("1. Insert at End\n");
        printf("2. Delete a Node\n");
        printf("3. Display List\n");
        printf("4. Return to Previous Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                displayLinkedList(head);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

/* Create a New Linked List Node */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insert at End of Linked List */
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

/* Delete a Node from Linked List */
void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

/* Display Linked List */
void displayLinkedList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Graph Menu */
void graphMenu() {
    int totalNodes, startNode, choice;

    printLine();
    printf("Graph Menu\n");
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &totalNodes);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < totalNodes; i++) {
        for (int j = 0; j < totalNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting node for traversal: ");
    scanf("%d", &startNode);

    while (1) {
        printLine();
        printf("1. Breadth-First Search (BFS)\n");
        printf("2. Depth-First Search (DFS)\n");
        printf("3. Return to Previous Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("BFS Traversal: ");
                bfs(startNode, totalNodes);
                break;
            case 2:
                printf("DFS Traversal: ");
                memset(visited, 0, sizeof(visited));
                dfs(startNode, totalNodes);
                break;
            case 3:
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

/* Breadth-First Search */
void bfs(int startNode, int totalNodes) {
    int queue[MAX_NODES], front = -1, rear = -1;
    int visited[MAX_NODES] = {0};

    queue[++rear] = startNode;
    visited[startNode] = 1;

    while (front < rear) {
        int currentNode = queue[++front];
        printf("%d ", currentNode);

        for (int i = 0; i < totalNodes; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}