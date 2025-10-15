#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
} TreeNode;

TreeNode *getNode();

TreeNode *findElement(TreeNode *bt, int data);

void InsertItem(TreeNode **bt, int data);

TreeNode *treeSearch(TreeNode *bt, int data);

TreeNode *removeElement(TreeNode **bt, int data);

TreeNode *inOrderSucc(TreeNode **bt);

TreeNode *reduceExternal(TreeNode **pdel, TreeNode **del, TreeNode **ps, TreeNode **s);

int isExternal(TreeNode *bt);

int isInternal(TreeNode *bt);

TreeNode *getSibling(TreeNode *bt);

void PreOrderTraverse(TreeNode *bt);

void LLRotate(TreeNode **bt);

void LRRotate(TreeNode **bt);

void RRRotate(TreeNode **bt);

void RLRotate(TreeNode **bt);

int isBalanced(TreeNode *bt);

int getDiff(TreeNode *bt);

int updateHeight(TreeNode **bt, int height);

int getHeight(TreeNode *bt);

void searchAndFixAfterInsertion(TreeNode **bt);

TreeNode *AVLInsert(TreeNode **bt, int data);

int getMaxHeight(TreeNode *bt);

int main() {
    TreeNode *root = NULL;

    while (1) {
        char op;
        scanf("%c", &op);
        getchar();

        int data;

        switch (op) {
            case 'i': scanf("%d", &data);
                getchar();
                InsertItem(&root, data);
                //AVLInsert(&root, data);
                break;
            case'd':
                scanf("%d", &data);
                getchar();
                TreeNode *delNode = removeElement(&root, data);
                if (delNode == NULL) {
                    printf("X\n");
                } else {
                    free(delNode);
                    printf("%d\n", data);
                }
                break;
            case's':
                scanf("%d", &data);
                getchar();
                if (treeSearch(root, data) == NULL) printf("X\n");
                else printf("%d\n", data);
                break;
            case'p':
                PreOrderTraverse(root);
                printf("\n");
                break;
            default: break;
        }
        if (op == 'q') break;
    }


    return 0;
}

TreeNode *getNode() {
    TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

TreeNode *findElement(TreeNode *bt, int data) {
    if (bt == NULL) return NULL;
    if (bt->data == data) return bt;

    TreeNode *left = findElement(bt->left, data);
    if (left != NULL) return left;

    return findElement(bt->right, data);
}

void InsertItem(TreeNode **bt, int data) {
    TreeNode *newNode = getNode();
    newNode->data = data;

    if (*bt == NULL) {
        *bt = newNode;
        (*bt)->height = 0;
        return; //return 필수~
    } //루트노드인경우

    TreeNode *pNode = NULL;
    TreeNode *cNode = *bt;
    while (cNode != NULL) {
        if (data == cNode->data) return; //동일키인경우
        pNode = cNode;
        if (cNode->data > data)
            cNode = pNode->left;
        else cNode = pNode->right;
    }

    if (pNode->data < data)
        pNode->right = newNode;
    else
        pNode->left = newNode;
}

TreeNode *treeSearch(TreeNode *bt, int data) {
    if (bt == NULL || bt->data == data) return bt;

    if (data < bt->data) {
        return treeSearch(bt->left, data);
    } else
        return treeSearch(bt->right, data);
}

TreeNode *removeElement(TreeNode **bt, int data) {
    TreeNode *pVRoot = getNode();
    TreeNode *root = *bt;
    pVRoot->right = root;

    //삭제할 노드랑 삭제노드의 부모 노드!!!
    TreeNode *delNode = *bt;
    TreeNode *pdelNode = NULL;

    while (delNode != NULL && delNode->data != data) {
        pdelNode = delNode;

        if (delNode->data < data)
            delNode = delNode->right;
        else delNode = delNode->left;
    }


    if (delNode == NULL) return NULL;

    //삭제 대상이 단말노드인 경우
    if (isExternal(delNode)) {
        if (pdelNode->right == delNode)
            pdelNode->right = NULL;
        else pdelNode->left = NULL;
    }

    //삭제 대상이 하나의 자식노드를 갖는 경우
    else if (delNode->left == NULL || delNode->right == NULL) {
        //reduceExternal(delNode,pdelNode);
        TreeNode *child = delNode->left;
        if (delNode->left == NULL)
            child = delNode->right;

        if (pdelNode->right == delNode)
            pdelNode->right = child;
        else
            pdelNode->left = child;
    }

    //두 개의 자식 노드를 모두 갖는 경우
    else {
        TreeNode *psucc = delNode;
        TreeNode *succ = delNode->right;

        while (succ->left != NULL) {
            psucc = succ;
            succ = succ->left;
        }
        //psucc = inOrderSucc(&delNode);
        succ = psucc->left;

        int tmp = delNode->data;
        delNode->data = succ->data;
        succ->data = tmp;

        if (psucc->left == succ)
            psucc->left = succ->right;
        else
            psucc->right = succ->right;
        //항상 오른쪽자식만 있다.

        delNode = succ;
    }
    //루트노드삭제할경우
    if (pVRoot->right != *bt)
        *bt = pVRoot->right;

    free(pVRoot);

    return delNode;
}

TreeNode *inOrderSucc(TreeNode **bt) {
    TreeNode *s = (*bt)->right;
    TreeNode *ps = *bt;
    while (s->left != NULL) {
        ps = s;
        s = s->left;
    }

    return ps;
}

int isExternal(TreeNode *bt) {
    if (bt->left == NULL && bt->right == NULL)
        return 1;
    return 0;
}

int isInternal(TreeNode *bt) {
    if (bt->left != NULL || bt->right != NULL)
        return 1;
    return 0;
}

void PreOrderTraverse(TreeNode *bt) {
    if (bt == NULL) return;

    printf(" %d", bt->data);
    PreOrderTraverse(bt->left);
    PreOrderTraverse(bt->right);
}

void LLRotate(TreeNode **bt) {
    TreeNode *pNode = *bt;
    TreeNode *cNode = (*bt)->left;

    pNode->left = cNode->right;
    cNode->right = pNode;


    //회전참여 노드 높이 갱신
    pNode->height = getMaxHeight(pNode) + 1;
    cNode->height = getMaxHeight(cNode) + 1;

    *bt = cNode;
}

void LRRotate(TreeNode **bt) {
    RRRotate(&(*bt)->left);
    LLRotate(bt);
}

void RRRotate(TreeNode **bt) {
    TreeNode *pNode = *bt;
    TreeNode *cNode = (*bt)->right;

    pNode->right = cNode->left;
    cNode->left = pNode;

    *bt = cNode;
}

void RLRotate(TreeNode **bt) {
    LLRotate(&(*bt)->right);
    RRRotate(bt);
}

int getHeight(TreeNode *bt) {
    if (bt == NULL) return 0;
    return bt->height;
}

TreeNode *AVLInsert(TreeNode **pRoot, int data) {
    if (*pRoot == NULL) {
        *pRoot = getNode();
        (*pRoot)->height = 1;
        (*pRoot)->data = data;
        return *pRoot;
    }

    if (data < (*pRoot)->data)
        AVLInsert(&(*pRoot)->left, data);
    else if (data > (*pRoot)->data)
        AVLInsert(&(*pRoot)->right, data);
    else
        return NULL; //중복허용 x

    int maxHeight = getMaxHeight(*pRoot);

    (*pRoot)->height = maxHeight + 1;
    searchAndFixAfterInsertion(pRoot);

    return *pRoot;
}

int getDiff(TreeNode *bt) {
    if (bt == NULL) return 0;

    int diff = getHeight(bt->left) - getHeight(bt->right);
    return diff;
}

void searchAndFixAfterInsertion(TreeNode **bt) {
    int diff = getDiff(*bt);

    if (diff > 1) //균형인수 2 이상
    {
        if (getDiff((*bt)->left) > 0)
            LLRotate(bt);
        else
            LRRotate(bt);
    } else if (diff < -1) {
        if (getDiff((*bt)->right) < 0)
            RRRotate(bt);
        else
            RLRotate(bt);
    }
    //회전 후 높이 재계산
}

int getMaxHeight(TreeNode *bt) {
    int maxHeight = getHeight(bt->left);
    if (maxHeight < getHeight(bt->right))
        maxHeight = getHeight(bt->right);
    return maxHeight;
}
