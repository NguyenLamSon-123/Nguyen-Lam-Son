#include <iostream>
#include <queue>
using namespace std;

// Cấu trúc Node cho cây nhị phân
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor để khởi tạo node
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Hàm duyệt cây theo tiền tự (Pre-order)
void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";  // Xử lý node hiện tại
    preOrder(root->left);       // Duyệt cây con trái
    preOrder(root->right);      // Duyệt cây con phải
}

// Hàm duyệt cây theo trung tự (In-order)
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);        // Duyệt cây con trái
    cout << root->data << " ";  // Xử lý node hiện tại
    inOrder(root->right);       // Duyệt cây con phải
}

// Hàm duyệt cây theo hậu tự (Post-order)
void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);      // Duyệt cây con trái
    postOrder(root->right);     // Duyệt cây con phải
    cout << root->data << " ";  // Xử lý node hiện tại
}

// Hàm duyệt cây theo cấp (Level-order) sử dụng Queue
void levelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";  // Xử lý node hiện tại

        if (current->left != nullptr) q.push(current->left);   // Thêm con trái vào hàng đợi
        if (current->right != nullptr) q.push(current->right); // Thêm con phải vào hàng đợi
    }
}

// Hàm chèn phần tử vào cây nhị phân tìm kiếm (BST)
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Hàm tìm kiếm phần tử trong cây nhị phân tìm kiếm (BST)
Node* search(Node* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);  // Tìm trong cây con trái
    } else {
        return search(root->right, value); // Tìm trong cây con phải
    }
}

// Hàm tìm phần tử thay thế (node nhỏ nhất trong cây con phải)
Node* minNode(Node* root) {
    Node* current = root;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Hàm xóa phần tử khỏi cây nhị phân tìm kiếm (BST)
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node cần xóa là node hiện tại
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node có hai con, thay thế bằng node nhỏ nhất trong cây con phải
        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    int n, value;

    // Nhập số lượng phần tử muốn chèn vào cây
    cout << "Nhap so luong phan tu muon chen vao cay: ";
    cin >> n;

    // Nhập giá trị các phần tử vào cây
    cout << "Nhap cac phan tu vao cay: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    // Duyệt cây theo các cách khác nhau
    cout << "Duyet tien tu (Pre-order): ";
    preOrder(root);
    cout << endl;

    cout << "Duyet trung tu (In-order): ";
    inOrder(root);
    cout << endl;

    cout << "Duyet hau tu (Post-order): ";
    postOrder(root);
    cout << endl;

    cout << "Duyet theo cap (Level-order): ";
    levelOrder(root);
    cout << endl;

    // Tìm kiếm phần tử trong cây
    cout << "Nhap gia tri can tim: ";
    cin >> value;
    Node* foundNode = search(root, value);
    if (foundNode != nullptr) {
        cout << "Tim thay node co gia tri: " << foundNode->data << endl;
    } else {
        cout << "Khong tim thay node" << endl;
    }

    // Xóa phần tử
    cout << "Nhap gia tri can xoa: ";
    cin >> value;
    root = deleteNode(root, value);
    cout << "Duyet trung tu sau khi xoa node " << value << ": ";
    inOrder(root);
    cout << endl;

    return 0;
}
