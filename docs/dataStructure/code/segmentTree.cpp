// 陣列版本
#define LC(x) ((x << 1))     // 左子節點的 ID
#define RC(x) ((LC(x)) | 1)  // 左子節點的 ID
int seg[(N << 4)];

// 指標版本
struct Node{
    Node *lc, *rc;
};