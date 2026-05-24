#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};

class BST
{
private:
    Node* root;

    Node* insert(Node* node, int val)
    {
        if (!node) return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);

        return node;
    }

    bool search(Node* node, int val) 
    {
        if (!node) return false;
        if (node->data == val) return true;

        if (val < node->data)
            return search(node->left, val);

        return search(node->right, val);
    }

    void inorder(Node* node, long long& sum) 
    {
        if (!node) return;

        inorder(node->left, sum);
        sum += node->data;
        inorder(node->right, sum);
    }

    Node* findMin(Node* node)
    {
        while (node->left)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int val) 
    {
        if (!node) return NULL;

        if (val < node->data)
            node->left = deleteNode(node->left, val);

        else if (val > node->data)
            node->right = deleteNode(node->right, val);

        else
        {
            if (!node->left)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) 
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else 
            {
                Node* succ = findMin(node->right);
                node->data = succ->data;
                node->right = deleteNode(node->right, succ->data);
            }
        }
        return node;
    }

    void inorderPrint(Node* node)
    {
        if (!node) return;

        inorderPrint(node->left);
        cout << node->data << " ";
        inorderPrint(node->right);
    }

    void destroy(Node* node)
    {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:

    BST() { root = NULL; }
    ~BST() { destroy(root); }

    void insert(int val) { root = insert(root, val); }
    bool search(int val) { return search(root, val); }
    void deleteVal(int val) { root = deleteNode(root, val); }

    void inorder()
    {
        inorderPrint(root);
        cout << endl;
    }

    void inorderSum(long long& sum) 
    {
        inorder(root, sum);
    }
};

int main() 
{
    srand(time(0));

    BST tree;

    cout << "=== BST Operations ===\n";

    int values[] = { 50, 30, 70, 20, 40, 60, 80 };

    cout << "Inserting: ";
    for (int i = 0; i < 7; i++) {
        cout << values[i] << " ";
        tree.insert(values[i]);
    }
    cout << endl;

    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Search 40: ";
    if (tree.search(40))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << "Search 90: ";
    if (tree.search(90))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << "Deleting 30\n";
    tree.deleteVal(30);

    cout << "Inorder after delete: ";
    tree.inorder();

    cout << "\n=== Timing: 5 Sets of 100 Random Numbers ===\n\n";

    double insertTimes[5], travTimes[5];

    cout << "-------------------------------------------------\n";
    cout << "Set# | Insert Time (us) | Inorder Time (us)\n";
    cout << "-------------------------------------------------\n";

    for (int i = 0; i < 5; i++) 
    {
        BST t;
        int arr[100];

        for (int j = 0; j < 100; j++)
            arr[j] = rand() % 1000 + 1;

        auto start1 = high_resolution_clock::now();
        for (int j = 0; j < 100; j++)
            t.insert(arr[j]);
        auto end1 = high_resolution_clock::now();

        long long dummy = 0;
        auto start2 = high_resolution_clock::now();
        t.inorderSum(dummy);
        auto end2 = high_resolution_clock::now();

        insertTimes[i] =
            duration_cast<microseconds>(end1 - start1).count();

        travTimes[i] =
            duration_cast<microseconds>(end2 - start2).count();

        cout << "  " << (i + 1)
            << "  |   " << insertTimes[i]
            << " us          |   " << travTimes[i] << " us\n";
    }

    cout << "-------------------------------------------------\n";

    double avgIns = 0, avgTrav = 0;
    for (int i = 0; i < 5; i++) {
        avgIns += insertTimes[i];
        avgTrav += travTimes[i];
    }

    cout << "Avg  |   " << avgIns / 5
        << " us        |   " << avgTrav / 5 << " us\n";

    cout << "-------------------------------------------------\n";

    return 0;
}