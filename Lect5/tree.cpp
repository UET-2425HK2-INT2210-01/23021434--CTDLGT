#include<iostream>
using namespace std;
struct Node {
    int value; 
    Node* left; 
    Node* right; 

    // Constructor khởi tạo giá trị nút
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};
class Tree {
    Node* root;

public:
    // Constructor khởi tạo cây rỗng
    Tree() : root(nullptr) {}
    // Hàm tìm một nút trong cây
    Node* find(Node* node, int value) {
        if (!node) return nullptr; 
        if (node->value == value) return node;
        Node* leftSearch = find(node->left, value); 
        if (leftSearch) return leftSearch;
        return find(node->right, value);
    }
    // Hàm chèn nút con vào cây
    void them_canh(int parent, int child) {
        Node* parentNode = find(root, parent); // Tìm nút cha trong cây
        if (!parentNode) { 
            if (!root) { 
                root = new Node(parent);
                root->left = new Node(child);
            }
            return;
        }
        if (!find(root, child)) { 
            if (!parentNode->left) parentNode->left = new Node(child);
            else if (!parentNode->right) parentNode->right = new Node(child); 
        }
    }
    // Hàm tính chiều cao của cây (tính theo số cạnh)
    int tinh_chieu_cao(Node* node) {
        if (!node) return -1; // Nếu nút không tồn tại, trả về -1 để tính số cạnh
        return 1 + max(tinh_chieu_cao(node->left), tinh_chieu_cao(node->right)); // Tính chiều cao 
    }

    // Duyệt cây theo thứ tự trước (Preorder)
    void preorder(Node* node) {
        if (!node) return;
        cout << node->value << " ";
        preorder(node->left); 
        preorder(node->right); 
    }

    // Duyệt cây theo thứ tự sau (Postorder)
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left); 
        postorder(node->right); 
        cout << node->value << " "; 
    }

    // Duyệt cây theo thứ tự giữa (Inorder)
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left); 
        cout << node->value << " ";
        inorder(node->right);
    }

    // Kiểm tra xem cây có phải là cây nhị phân tìm kiếm (BST) hay không
    bool is_binary_tree(Node* node) {
        if (!node) return true;
        int count = 0;
        if (node->left) {
            if (node->left->value >= node->value) return false;
            count++;
        }
        if (node->right) {
            if (node->right->value <= node->value) return false;
            count++;
        }
        if (count > 2) return false;
        return is_binary_tree(node->left) && is_binary_tree(node->right);
    }

    // In thông tin cây theo yêu cầu
    void print_tree() {
        cout << tinh_chieu_cao(root) << endl; // In chiều cao của cây
        preorder(root); // In thứ tự duyệt trước
        cout << endl;
        postorder(root); // In thứ tự duyệt sau
        cout << endl;

        
        if (is_binary_tree(root)) {
            inorder(root);
            cout << endl;
        }
        else {
            cout << "NOT BINARY TREE" << endl;
        }
    }
};
// hàm main
int main() {
    int n, m;
    cin >> n >> m; // Nhập số lượng nút và số cạnh
    Tree tree;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // Nhập cạnh giữa hai nút
        tree.them_canh(u, v); // Thêm cạnh vào cây
    }

    tree.print_tree(); // In thông tin cây
    return 0;
}