#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

bool search(Node* root, int target) {
    if (root == nullptr) return false;
    if (root->data == target) return true;
    return (target < root->data) ? search(root->left, target) : search(root->right, target);
}

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

void dfsUtil(const vector<vector<int>>& graph, int node, int target, vector<bool>& visited, bool& found) {
    if (found || visited[node]) return;
    
    visited[node] = true;
    if (node == target) {
        cout << "Tim thay " << target << " trong DFS.\n";
        found = true;
        return;
    }
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsUtil(graph, neighbor, target, visited, found);
        }
    }
}

void dfs(const vector<vector<int>>& graph, int start, int target) {
    vector<bool> visited(graph.size(), false);
    bool found = false;
    dfsUtil(graph, start, target, visited, found);
    if (!found) {
        cout << "Khong tim thay " << target << " trong DFS.\n";
    }
}

int main() {
    int choice, target, n, vertices, edges, start;
    vector<int> arr;
    Node* root = nullptr;
    vector<vector<int>> graph;

    do {
        cout << "\n=== Menu Tim Kiem ===\n";
        cout << "1. Nhap mang\n";
        cout << "2. Tim kiem tuyen tinh\n";
        cout << "3. Tim kiem nhi phan\n";
        cout << "4. Tim kiem trong cay nhi phan\n";
        cout << "5. Tim kiem do thi (BFS)\n";
        cout << "6. Tim kiem do thi (DFS)\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap so phan tu cua mang: ";
                cin >> n;
                arr.resize(n);
                cout << "Nhap cac phan tu cua mang:\n";
                for (int i = 0; i < n; ++i) {
                    cin >> arr[i];
                }
                break;

            case 2:
                if (arr.empty()) {
                    cout << "Mang chua duoc nhap. Hay chon chuc nang 1 de nhap mang truoc.\n";
                } else {
                    cout << "Nhap gia tri can tim kiem: ";
                    cin >> target;
                    int index;
                    index = linearSearch(arr, target);
                    cout << (index != -1 ? "Tim thay tai chi so " + to_string(index) : "Khong tim thay") << "\n";
                }
                break;

            case 3:
                if (arr.empty()) {
                    cout << "Mang chua duoc nhap. Hay chon chuc nang 1 de nhap mang truoc.\n";
                } else {
                    cout << "Nhap gia tri can tim kiem: ";
                    cin >> target;
                    int index;
                    index = binarySearch(arr, target);
                    cout << (index != -1 ? "Tim thay tai chi so " + to_string(index) : "Khong tim thay") << "\n";
                }
                break;

            case 4:
                cout << "Nhap so phan tu de chen vao cay nhi phan tim kiem: ";
                cin >> n;
                root = nullptr;
                cout << "Nhap cac phan tu:\n";
                for (int i = 0; i < n; ++i) {
                    int val;
                    cin >> val;
                    root = insert(root, val);
                }
                cout << "Nhap gia tri can tim kiem trong cay: ";
                cin >> target;
                cout << (search(root, target) ? "Tim thay" : "Khong tim thay") << "\n";
                break;

            case 5:
                cout << "Nhap so dinh va so canh cua do thi: ";
                cin >> vertices >> edges;
                graph.assign(vertices, vector<int>());
                cout << "Nhap cac canh (u v):\n";
                for (int i = 0; i < edges; ++i) {
                    int u, v;
                    cin >> u >> v;
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
                cout << "Nhap dinh bat dau va gia tri can tim kiem trong do thi (BFS): ";
                cin >> start >> target;
                bfs(graph, start, target);
                break;

            case 6:
                cout << "Nhap so dinh va so canh cua do thi: ";
                cin >> vertices >> edges;
                graph.assign(vertices, vector<int>());
                cout << "Nhap cac canh (u v):\n";
                for (int i = 0; i < edges; ++i) {
                    int u, v;
                    cin >> u >> v;
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
                cout << "Nhap dinh bat dau va gia tri can tim kiem trong do thi (DFS): ";
                cin >> start >> target;
                dfs(graph, start, target);
                break;

            case 0:
                cout << "Thoat chuong trinh.\n";
                break;

            default:
                cout << "Lua chon khong hop le.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
