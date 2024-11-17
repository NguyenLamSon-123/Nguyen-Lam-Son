#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class DoThi {
private:
    int soDinh;
    vector<vector<int>> danhSachKe; // Danh sach ke

public:
    // Khoi tao do thi voi so dinh cho truoc
    DoThi(int dinh) : soDinh(dinh) {
        danhSachKe.resize(dinh + 1); // Danh so dinh tu 1
    }

    // Them canh vao do thi
    void themCanh(int u, int v) {
        danhSachKe[u].push_back(v);
        danhSachKe[v].push_back(u); // Do thi vo huong
    }

    // Duyet do thi theo chieu sau (DFS) va hien thi tung buoc
    void DFS(int dinhBatDau) {
        vector<bool> daTham(soDinh + 1, false);
        stack<int> nganXep;
        nganXep.push(dinhBatDau);

        cout << "Duyet DFS tu dinh " << dinhBatDau << ": ";

        while (!nganXep.empty()) {
            int dinh = nganXep.top();
            nganXep.pop();

            if (!daTham[dinh]) {
                cout << dinh << " ";
                daTham[dinh] = true;
            }

            // Day cac dinh ke vao ngan xep neu chua duoc tham
            for (auto it = danhSachKe[dinh].rbegin(); it != danhSachKe[dinh].rend(); ++it) {
                if (!daTham[*it]) {
                    nganXep.push(*it);
                }
            }
        }
        cout << endl;
    }

    // Duyet do thi theo chieu rong (BFS) va hien thi tung buoc
    void BFS(int dinhBatDau) {
        vector<bool> daTham(soDinh + 1, false);
        queue<int> hangDoi;
        hangDoi.push(dinhBatDau);
        daTham[dinhBatDau] = true;

        cout << "Duyet BFS tu dinh " << dinhBatDau << ": ";

        while (!hangDoi.empty()) {
            int dinh = hangDoi.front();
            hangDoi.pop();
            cout << dinh << " ";

            // Dua cac dinh ke vao hang doi neu chua duoc tham
            for (int ke : danhSachKe[dinh]) {
                if (!daTham[ke]) {
                    daTham[ke] = true;
                    hangDoi.push(ke);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Tao do thi voi 5 dinh
    DoThi g(5);
    
    // Them cac canh vao do thi theo hinh
    g.themCanh(1, 2);
    g.themCanh(1, 3);
    g.themCanh(1, 5);
    g.themCanh(2, 3);
    g.themCanh(3, 4);
    g.themCanh(4, 5);

    // Hien thi cac buoc duyet DFS va BFS
    g.DFS(1); // Duyet DFS tu dinh 1
    g.BFS(1); // Duyet BFS tu dinh 1

    return 0;
}
