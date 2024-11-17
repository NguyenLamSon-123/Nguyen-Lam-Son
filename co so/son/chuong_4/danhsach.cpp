#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node (mỗi phần tử trong danh sách)
struct Node {
    int data;    // Dữ liệu của node
    Node* next;  // Con trỏ đến node tiếp theo
};

// Hàm thêm phần tử vào cuối danh sách liên kết
void themVaoCuoi(Node*& head, int newElement) {
    Node* newNode = new Node();
    newNode->data = newElement;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hàm xóa phần tử đầu tiên
void xoaDau(Node*& head) {
    if (head == nullptr) {
        cout << "Danh sach rong, khong the xoa." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;  // Giải phóng bộ nhớ của phần tử bị xóa
}

// Hàm xóa phần tử cuối cùng
void xoaCuoi(Node*& head) {
    if (head == nullptr) {
        cout << "Danh sach rong, khong the xoa." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Hàm xóa phần tử tại một vị trí
void xoaTaiViTri(Node*& head, int viTri) {
    if (head == nullptr) {
        cout << "Danh sach rong, khong the xoa." << endl;
        return;
    }
    if (viTri == 0) {
        xoaDau(head);
        return;
    }

    Node* temp = head;
    for (int i = 0; i < viTri - 1; i++) {
        if (temp == nullptr) {
            cout << "Vi tri khong hop le." << endl;
            return;
        }
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Vi tri khong hop le." << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Hàm hiển thị danh sách liên kết
void hienThiDanhSach(Node* head) {
    Node* temp = head;
    cout << "Danh sach lien ket: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Hàm giải phóng bộ nhớ
void xoaDanhSach(Node*& head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr; // Khởi tạo danh sách rỗng

    // Nhập số lượng phần tử cần thêm vào danh sách
    int n;
    cout << "Nhap so luong phan tu muon them vao danh sach: ";
    cin >> n;

    // Thêm các phần tử vào danh sách
    for (int i = 0; i < n; i++) {
        int newElement;
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> newElement;
        themVaoCuoi(head, newElement); // Thêm phần tử vào cuối danh sách
    }

    // Hiển thị danh sách sau khi thêm phần tử
    hienThiDanhSach(head);

    int luaChon;
    do {
        cout << "\nChon 1 de xoa dau, 2 de xoa cuoi, 3 de xoa tai vi tri, 4 de thoat: ";
        cin >> luaChon;

        if (luaChon == 1) {
            xoaDau(head);
            cout << "Danh sach sau khi xoa dau: ";
            hienThiDanhSach(head);
        } else if (luaChon == 2) {
            xoaCuoi(head);
            cout << "Danh sach sau khi xoa cuoi: ";
            hienThiDanhSach(head);
        } else if (luaChon == 3) {
            int viTri;
            cout << "Nhap vi tri can xoa: ";
            cin >> viTri;
            xoaTaiViTri(head, viTri);
            cout << "Danh sach sau khi xoa tai vi tri " << viTri << ": ";
            hienThiDanhSach(head);
        } else if (luaChon == 4) {
            cout << "Thoat chuong trinh.\n";
        } else {
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (luaChon != 4); // Lặp lại cho đến khi chọn thoát

    // Giải phóng bộ nhớ
    xoaDanhSach(head);

    return 0;
}
