#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 1. Tim kiem tuyen tinh (Linear Search)
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;  // Tra ve chi so neu tim thay
        }
    }
    return -1;  // Khong tim thay
}

// 2. Tim kiem nhi phan (Binary Search)
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;  // Tra ve chi so neu tim thay
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Khong tim thay
}

// 3. Tim kiem trong cay nhi phan tim kiem (Binary Search Tree)
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Ham chen mot phan tu vao cay
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Ham tim kiem trong cay
bool search(Node* root, int target) {
    if (root == nullptr) return false;
    if (root->data == target) return true;
    return (target < root->data) ? search(root->left, target) : search(root->right, target);
}

// 4. Tim kiem do thi (BFS, DFS)
void bfs(const vector<vector<int>>& graph, int start, int target) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == target) {
            cout << "Tim thay " << target << " trong BFS.\n";
            return;
        }
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << "Khong tim thay " << target << " trong BFS.\n";
}

void dfs(const vector<vector<int>>& graph, int node, int target, vector<bool>& visited) {
    if (node == target) {
        cout << "Tim thay " << target << " trong DFS.\n";
        return;
    }
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, target, visited);
        }
    }
}

// Ham main
int main() {
    int n, target;

    // Nhap mang cho tim kiem tuyen tinh va tim kiem nhi phan
    cout << "Nhap so phan tu trong mang: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Nhap " << n << " phan tu trong mang:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Nhap gia tri can tim
    cout << "Nhap gia tri can tim: ";
    cin >> target;

    // 1. Tim kiem tuyen tinh
    int index = linearSearch(arr, target);
    if (index != -1) {
        cout << "Tim thay " << target << " tai chi so " << index << " trong Tim kiem tuyen tinh.\n";
    } else {
        cout << "Khong tim thay " << target << " trong Tim kiem tuyen tinh.\n";
    }

    // 2. Tim kiem nhi phan
    sort(arr.begin(), arr.end());  // Can sap xep mang truoc khi tim kiem nhi phan
    index = binarySearch(arr, target);
    if (index != -1) {
        cout << "Tim thay " << target << " tai chi so " << index << " trong Tim kiem nhi phan.\n";
    } else {
        cout << "Khong tim thay " << target << " trong Tim kiem nhi phan.\n";
    }

    // 3. Tim kiem trong cay nhi phan tim kiem (Binary Search Tree)
    Node* root = nullptr;
    int numNodes;
    cout << "Nhap so luong phan tu cho cay nhi phan tim kiem: ";
    cin >> numNodes;
    cout << "Nhap " << numNodes << " phan tu cho cay:\n";
    for (int i = 0; i < numNodes; ++i) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    if (search(root, target)) {
        cout << "Tim thay " << target << " trong cay nhi phan tim kiem.\n";
    } else {
        cout << "Khong tim thay " << target << " trong cay nhi phan tim kiem.\n";
    }

    // 4. Tim kiem do thi (BFS, DFS)
    int numVertices, numEdges;
    cout << "Nhap so dinh cua do thi: ";
    cin >> numVertices;
    vector<vector<int>> graph(numVertices);
    cout << "Nhap so canh cua do thi: ";
    cin >> numEdges;
    cout << "Nhap " << numEdges << " canh cua do thi (dinh1 dinh2):\n";
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // Do thi vo huong
    }

    cout << "Nhap dinh can tim: ";
    cin >> target;

    // Tim kiem BFS
    cout << "\nTim kiem theo BFS:\n";
    bfs(graph, 0, target);  // Tim kiem tu node 0

    // Tim kiem DFS
    vector<bool> visited(graph.size(), false);
    cout << "\nTim kiem theo DFS:\n";
    dfs(graph, 0, target, visited);  // Tim kiem tu node 0

    return 0;
}
