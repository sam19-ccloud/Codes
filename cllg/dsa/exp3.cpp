#include <iostream>
using namespace std;

#define MAX 10

struct NODE {
    int val;
    NODE* next;
};

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow!\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = x;
    }

    int dequeue() {
        if (front == -1)
            return -1;

        int val = arr[front];

        if (front == rear)
            front = rear = -1;
        else
            front++;

        return val;
    }

    bool isEmpty() {
        return (front == -1);
    }
};

class GraphLandmark {
private:
    int GAM[MAX][MAX];        
    NODE* HeaderGAL[MAX];     
    int n;

    string Landmark[MAX] = {
        "Admin", "Canteen", "Sports", "Library",
        "Auditorium", "Lab", "Hostel", "Parking",
        "Garden", "Office"
    };

public:
    int VISITED[MAX];

    GraphLandmark() {
        initGraph();
        initVISITED();
    }

    void initGraph() {
        for (int i = 0; i < MAX; i++) {
            HeaderGAL[i] = NULL;
            for (int j = 0; j < MAX; j++)
                GAM[i][j] = 0;
        }
    }

    void initVISITED() {
        for (int i = 0; i < MAX; i++)
            VISITED[i] = 0;
    }

    void createGraph() {
        cout << "\nEnter number of nodes (max 10): ";
        cin >> n;

        int flag = 1;
        while (flag) {
            int s, d;
            cout << "\nEnter source node (1-" << n << "): ";
            cin >> s;

            cout << "Enter destination node (1-" << n << "): ";
            cin >> d;

            if (s < 1 || s > n || d < 1 || d > n) {
                cout << "Invalid node number!\n";
                continue;
            }

            GAM[s][d] = 1;

            NODE* p = new NODE;
            p->val = d;
            p->next = NULL;

            if (HeaderGAL[s] == NULL)
                HeaderGAL[s] = p;
            else {
                NODE* cur = HeaderGAL[s];
                while (cur->next != NULL)
                    cur = cur->next;
                cur->next = p;
            }

            cout << "Add more edges? (1-Yes / 0-No): ";
            cin >> flag;
        }
    }

    void displayGAM() {
        cout << "\nAdjacency Matrix:\n\t";
        for (int i = 1; i <= n; i++)
            cout << i << "\t";

        for (int i = 1; i <= n; i++) {
            cout << "\n" << i << "\t";
            for (int j = 1; j <= n; j++)
                cout << GAM[i][j] << "\t";
        }
        cout << endl;
    }

    void displayGAL() {
        cout << "\nAdjacency List:\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " (" << Landmark[i - 1] << ") -> ";
            NODE* temp = HeaderGAL[i];
            while (temp != NULL) {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    void DFS(int v) {
        VISITED[v] = 1;
        cout << Landmark[v - 1] << " -> ";

        for (int w = 1; w <= n; w++) {
            if (GAM[v][w] == 1 && VISITED[w] == 0)
                DFS(w);
        }
    }

    void BFS(int v) {
        Queue Qobj;
        initVISITED();

        Qobj.enqueue(v);
        VISITED[v] = 1;

        while (!Qobj.isEmpty()) {
            v = Qobj.dequeue();
            cout << Landmark[v - 1] << " -> ";

            NODE* cur = HeaderGAL[v];
            while (cur != NULL) {
                if (VISITED[cur->val] == 0) {
                    Qobj.enqueue(cur->val);
                    VISITED[cur->val] = 1;
                }
                cur = cur->next;
            }
        }
    }
};

int main() {
    GraphLandmark G;
    int choice = 0;

    while (choice != 6) {
        cout << "\n**** GRAPH MENU ****";
        cout << "\n1. Create Graph";
        cout << "\n2. Display Adjacency Matrix";
        cout << "\n3. Display Adjacency List";
        cout << "\n4. Traverse BFS";
        cout << "\n5. Traverse DFS";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            G.initGraph();
            G.createGraph();
            break;

        case 2:
            G.displayGAM();
            break;

        case 3:
            G.displayGAL();
            break;

        case 4: {
            int startNode;
            cout << "Enter starting node for BFS: ";
            cin >> startNode;
            cout << "BFS Traversal: ";
            G.BFS(startNode);
            cout << "NULL\n";
            break;
        }

        case 5: {
            int startNode;
            G.initVISITED();
            cout << "Enter starting node for DFS: ";
            cin >> startNode;
            cout << "DFS Traversal: ";
            G.DFS(startNode);
            cout << "NULL\n";
            break;
        }

        case 6:
            cout << "Thank you for using the program.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}