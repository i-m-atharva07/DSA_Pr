#include<iostream>
#include<string>
using namespace std;

class graph {
    int city[4][4];  // Adjacency matrix for the cities
    int span[4][4];  // Matrix to store the MST (Minimum Spanning Tree)

public:
    // Constructor to initialize the city and span arrays
    graph() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                city[i][j] = 0;
                span[i][j] = 0;
            }
        }
    }

    // Method to input the graph's distance matrix
    void readGraph() {
        string arr[] = {"Pune", "Chopda", "Jalgaon", "Mumbai"};

        // Read distances for the upper triangular matrix (since the distance is symmetric)
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                cout << "Enter distance between " << arr[i] << " and " << arr[j] << ": ";
                cin >> city[i][j];
                city[j][i] = city[i][j];  // Symmetric property
            }
        }
    }

    // Method to print the distance matrix (adjacency matrix)
    void printGraph() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << city[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Method to implement Prim's algorithm for MST
    void prims() {
        int visited[4] = {0};  // Array to track visited cities
        int distance[4];        // Distance array to track minimum edge to the MST
        int from[4];            // Array to track the previous node for MST edges

        // Initialize the distance array and from array
        for (int i = 0; i < 4; i++) {
            distance[i] = city[0][i];  // Initially, the distance from city 0
            from[i] = 0;
        }
        visited[0] = 1;  // Mark the first city as visited

        int edges = 3;   // We need to add 3 edges to the MST (for 4 nodes)
        int sum = 0;     // To store the sum of MST weights

        // Prim's algorithm to find the MST
        while (edges > 0) {
            int min = 1000;  // Set initial high value for min (infinity)
            int u, v;

            // Find the minimum edge that connects a visited node to a non-visited node
            for (int i = 1; i < 4; i++) {
                if (visited[i] == 0 && distance[i] < min) {
                    min = distance[i];
                    v = i;
                    u = from[i];
                }
            }

            // Include the edge in the MST and mark the vertex as visited
            span[u][v] = min;
            span[v][u] = min;
            visited[v] = 1;
            sum += min;
            edges--;

            // Update the distance array for the next potential edges
            for (int i = 1; i < 4; i++) {
                if (visited[i] == 0 && city[i][v] < distance[i]) {
                    distance[i] = city[i][v];
                    from[i] = v;
                }
            }
        }

        // Output the MST and its total weight
        cout << "Minimum Spanning Tree (MST) is: " << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (span[i][j] != 0)
                    cout << "Edge between " << i << " and " << j << " with weight " << span[i][j] << endl;
            }
        }
        cout << "Total weight of MST: " << sum << endl;
    }
};

int main() {
    graph obj;  // Create a graph object
    obj.readGraph();  // Read the graph
    obj.printGraph();
    obj.prims();  // Execute Prim's algorithm
    return 0;
}
