#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node cho danh sách liên kết
struct Node {
    int data;      // Dữ liệu
    Node* next;   // Con trỏ đến node tiếp theo
};

// Hàm tạo một Node mới
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Hàm thêm Node vào đầu danh sách
void insertAtHead(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Hàm thêm Node vào cuối danh sách
void insertAtTail(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) { // Nếu danh sách rỗng
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) { // Duyệt đến node cuối
        temp = temp->next;
    }
    temp->next = newNode; // Thêm node mới vào cuối
}

// Hàm xóa Node có giá trị cụ thể
void deleteNodeByValue(Node*& head, int value) {
    if (head == nullptr) {
        cout << "Danh sach rong." << endl;
        return;
    }

    // Xóa phần tử đầu nếu nó có giá trị cần xóa
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Da xoa phan tu co gia tri " << value << endl;
        return;
    }

    // Tìm và xóa phần tử có giá trị cần xóa
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Khong tim thay gia tri " << value << " trong danh sach." << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    cout << "Da xoa phan tu co gia tri " << value << endl;
}

// Hàm hiển thị các phần tử trong danh sách
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "Danh sach rong." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

// Hàm nhập nhiều phần tử từ bàn phím và thêm vào danh sách
void inputMultipleElements(Node*& head) {
    int n, value;
    cout << "Nhap so luong phan tu can them: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu thu " << i + 1 << ": ";
        cin >> value;
        insertAtTail(head, value);
    }
}

int main() {
    Node* head = nullptr; // Khởi tạo danh sách rỗng
    int choice, value;

    while (true) {
        cout << "\n=== MENU ===\n";
        cout << "1. Them phan tu vao dau danh sach\n";
        cout << "2. Them phan tu vao cuoi danh sach\n";
        cout << "3. Xoa phan tu theo gia tri\n";
        cout << "4. Hien thi danh sach\n";
        cout << "5. Them nhieu phan tu vao danh sach\n";
        cout << "6. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri can them vao dau danh sach: ";
                cin >> value;
                insertAtHead(head, value);
                cout << "Danh sach sau khi them: ";
                displayList(head);
                break;
            case 2:
                cout << "Nhap gia tri can them vao cuoi danh sach: ";
                cin >> value;
                insertAtTail(head, value);
                cout << "Danh sach sau khi them: ";
                displayList(head);
                break;
            case 3:
                cout << "Nhap gia tri can xoa: ";
                cin >> value;
                deleteNodeByValue(head, value);
                cout << "Danh sach sau khi xoa: ";
                displayList(head);
                break;
            case 4:
                cout << "Danh sach hien tai: ";
                displayList(head);
                break;
            case 5:
                inputMultipleElements(head);
                cout << "Danh sach sau khi them nhieu phan tu: ";
                displayList(head);
                break;
            case 6:
                cout << "Thoat chuong trinh.\n";
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
    }

    return 0;
}
