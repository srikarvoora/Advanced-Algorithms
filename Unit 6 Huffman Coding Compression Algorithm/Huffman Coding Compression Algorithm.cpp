#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Huffman tree node
struct Node {
    char data;       // Character stored in the node
    int freq;       // Frequency of the character
    Node* left;     // Left child
    Node* right;    // Right child

    // Constructor
    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq; // Min-heap based on frequency
    }
};

// Function to assign codes to characters
void assignCodes(Node* node, string code, map<char, string>& huffmanCodes) {
    if (node == NULL) {
        return;
    }

    // If it's a leaf node, save the code
    if (node->data != '$') {
        huffmanCodes[node->data] = code;
    }

    // Traverse left and right children
    assignCodes(node->left, code + "0", huffmanCodes);
    assignCodes(node->right, code + "1", huffmanCodes);
}

// Function to build Huffman tree and print codes
void buildHuffmanTree(string S, int f[], int N) {
    // Create a priority queue to store nodes
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create leaf nodes and push them into the priority queue
    for (int i = 0; i < N; i++) {
        Node* node = new Node(S[i], f[i]);
        pq.push(node);
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top(); // Extract the two nodes with the smallest frequency
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        // Create a new internal node with these two nodes as children
        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent); // Push the new node back into the priority queue
    }

    // Print Huffman codes
    Node* root = pq.top(); // The root of the Huffman tree
    string code = "";
    map<char, string> huffmanCodes;

    assignCodes(root, code, huffmanCodes); // Start code assignment

    // Print the Huffman codes
    cout << "Huffman Codes:" << endl;
    for (map<char, string>::iterator it = huffmanCodes.begin(); it != huffmanCodes.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }
}

// Main function
int main() {
    string S = "abcdef"; // Characters
    int f[] = {5, 9, 12, 13, 16, 45}; // Corresponding frequencies
    int N = sizeof(f) / sizeof(f[0]); // Number of characters

    buildHuffmanTree(S, f, N); // Build and display Huffman codes

    return 0;
}

