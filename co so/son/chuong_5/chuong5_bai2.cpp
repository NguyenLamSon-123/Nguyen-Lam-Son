#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node cho danh sách móc nối kép
struct Node {
    int data;       // Dữ liệu
    Node* prev;    // Con trỏ đến node trước
    Node* next;    // Con trỏ đến node sau
};

// Hàm tạo một Node mới
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Hàm thêm Node vào đầu danh sách
void insertAtHead(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    
    if (head != nullptr) {
        head->prev = newNode; // Cập nhật con trỏ prev của node đầu
    }
    
    head = newNode; // Cập nhật head
}

// Hàm thêm Node vào cuối danh sách
void insertAtTail(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        newNode->prev = nullptr; // Nếu danh sách rỗng
        head = newNode;          // Đặt head trỏ đến node mới
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next; // Duyệt đến node cuối
    }

    temp->next = newNode; // Cập nhật con trỏ next của node cuối
    newNode->prev = temp; // Cập nhật con trỏ prev của node mới
}

// Hàm xóa Node có giá trị cụ thể
void deleteNodeByValue(Node*& head, int value) {
    if (head == nullptr) {
        cout << "Danh sach rong." << endl;
        return;
    }

    Node* temp = head;
    
    // Tìm node cần xóa
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    // Nếu không tìm thấy node cần xóa
    if (temp == nullptr) {
        cout << "Khong tim thay gia tri " << value << " trong danh sach." << endl;
        return;
    }

    // Nếu node cần xóa là node đầu
    if (temp == head) {
        head = head->next; // Cập nhật head
        if (head != nullptr) {
            head->prev = nullptr; // Cập nhật con trỏ prev của node mới đầu
        }
    } else {
        temp->prev->next = temp->next; // Cập nhật con trỏ next của node trước
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev; // Cập nhật con trỏ prev của node sau
    }

    delete temp; // Giải phóng bộ nhớ
    cout << "Da xoa phan tu co gia tri " << value << endl;
}

// Hàm hiển thị các phần tử trong danh sách từ đầu đến cuối
void displayForward(Node* head) {
    if (head == nullptr) {
        cout << "Danh sach rong." << endl;
        return;
    }
    
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

// Hàm hiển thị các phần tử trong danh sách từ cuối đến đầu
void displayBackward(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next; // Duyệt đến node cuối
    }

    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->prev; // Quay lại node trước
    }
    cout << "null" << endl;
}

// Hàm nhập các phần tử từ bàn phím và thêm vào danh sách
void inputMultipleElements(Node*& head) {
    int n, value;
    cout << "Nhap so luong phan tu can them: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu thu " << i + 1 << ": ";
        cin >> value;
        insertAtTail(head, value);
    }
    cout << "Danh sach sau khi them: ";
    displayForward(head); // Hiển thị danh sách sau khi thêm
}

int main() {
    Node* head = nullptr; // Khởi tạo danh sách
    int choice, value;

    while (true) {
        cout << "\n=== MENU ===\n";
        cout << "1. Them phan tu vao dau danh sach\n";
        cout << "2. Them phan tu vao cuoi danh sach\n";
        cout << "3. Them nhieu phan tu vao danh sach\n";
        cout << "4. Xoa phan tu theo gia tri\n";
        cout << "5. Hien thi danh sach tu dau den cuoi\n";
        cout << "6. Hien thi danh sach tu cuoi ve dau\n";
        cout << "7. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri can them vao dau danh sach: ";
                cin >> value;
                insertAtHead(head, value);
                cout << "Danh sach sau khi them: ";
                displayForward(head); // Hiển thị danh sách sau khi thêm
                break;
            case 2:
                cout << "Nhap gia tri can them vao cuoi danh sach: ";
                cin >> value;
                insertAtTail(head, value);
                cout << "Danh sach sau khi them: ";
                displayForward(head); // Hiển thị danh sách sau khi thêm
                break;
            case 3:
                inputMultipleElements(head);
                break;
            case 4:
                cout << "Nhap gia tri can xoa: ";
                cin >> value;
                deleteNodeByValue(head, value);
                cout << "Danh sach sau khi xoa: ";
                displayForward(head); // Hiển thị danh sách sau khi xóa
                break;
            case 5:
                cout << "Danh sach hien tai tu dau den cuoi: ";
                displayForward(head);
                break;
            case 6:
                cout << "Danh sach hien tai tu cuoi ve dau: ";
                displayBackward(head);
                break;
            case 7:
                cout << "Thoat chuong trinh.\n";
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
    }

    return 0;
}
