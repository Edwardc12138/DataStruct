#include "BinTree.h"
#include <malloc.h>
#include <assert.h>
#include "Queue.h"

// 创建节点
BTNode* _NewNode(BTDataType ch) {
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    if(!node) {
        return NULL;
    }
    node->_data = ch;
    node->_left = NULL;
    node->_right = NULL;
    return node;
}

// 创建子树
BTNode* _CreatSubTree(BTDataType* arr, int* index, int size, BTDataType invalid) {
    // 数组为空,索引为空,索引到达数组末尾,待创建节点数据为空
    if(!arr || !index || *index == size || arr[*index] == invalid) {
        return NULL;
    }
    // 创建节点
    BTNode* root = _NewNode(arr[*index]);
    if(!root) {
        return NULL;
    }

    // 创建左子树
    ++(*index);
    root->_left = _CreatSubTree(arr, index, size, invalid);
    // 创建右子树
    ++(*index);
    root->_right = _CreatSubTree(arr, index, size, invalid);

    return root;
}

BTNode* CreatBinTree(BTDataType* arr, int size, BTDataType invalid) {
    int index = 0;
    return _CreatSubTree(arr, &index, size, invalid);
}

// 销毁子树
void _DestroySubTree(BTNode* root) {
    if(!root) {
        return;
    }

    // 销毁左子树
    _DestroySubTree(root->_left);
    // 销毁右子树
    _DestroySubTree(root->_right);
    // 释放当前节点
    free(root);
}

void DestroyBinTree(BTNode** root) {
    if(!root) {
        return;
    }

    _DestroySubTree(*root);
    *root = NULL;
}

void PreOrder(BTNode* root) {
    if(!root) {
        return;
    }

    // 根
    printf("%c ", root->_data);
    // 左
    PreOrder(root->_left);
    // 右
    PreOrder(root->_right);
}

void InOrder(BTNode* root) {
    if(!root) {
        return;
    }

    // 左
    InOrder(root->_left);
    // 根
    printf("%c ", root->_data);
    // 右
    InOrder(root->_right);
}

void PostOrder(BTNode* root) {
    if(!root) {
        return;
    }

    // 左
    PostOrder(root->_left);
    // 右
    PostOrder(root->_right);
    // 根
    printf("%c ", root->_data);
}

void LevelOrder(BTNode* root) {
    if(!root) {
        return;
    }

    Queue queue;
    InitQueue(&queue);
    PushQueue(&queue, root);
    // 队列不为空
    while(!EmptyQueue(&queue)) {
        BTNode* pcur = HeadOfQueue(&queue);
        PopQueue(&queue);
        printf("%c ", pcur->_data);
        // 左节点不为空
        if(pcur->_left) {
            // 左节点入队
            PushQueue(&queue, pcur->_left);
        }
        if(pcur->_right) {
            // 右节点入队
            PushQueue(&queue, pcur->_right);;
        }
    }
    ClearQueue(&queue);
}

int SizeBinTree(BTNode* root) {
    if(!root) {
        return 0;
    }
    // 左子树节点个数和右子树节点个数和根节点
    return SizeBinTree(root->_left) + SizeBinTree(root->_right) + 1;
}

int LevelSizeBinTree(BTNode* root, int k) {
    if(k < 1 || !root) {
        return 0;
    }

    if(k == 1) {
        return 1;
    }
    // 左子树第k-1层节点个数和右子树第k-1层节点个数
    return LevelSizeBinTree(root->_left, k - 1) + LevelSizeBinTree(root->_right, k - 1);
}

int LeafSizeBinTree(BTNode* root) {
    if(!root) {
        return 0;
    }
    
    if(!root->_left && !root->_right) {
        return 1;
    }
    // 左子树的叶节点个数和右子树叶节点个数
    return LeafSizeBinTree(root->_left) + LeafSizeBinTree(root->_right);
}

int HighBinTree(BTNode* root) {
    if(!root) {
        return 0;
    }
    // 左子树的高度和当前节点
    int high_l = HighBinTree(root->_left) + 1;
    int high_r = HighBinTree(root->_right) + 1;
    // 返回深的一个
    if(high_l > high_r) {
        return high_l;
    }
    else {
        return high_r;
    }
}

BTNode* SearchBTNode(BTNode* root, BTDataType data) {
    if(!root) {
        return NULL;
    }
    if(root->_data == data) {
        return root;
    }
    // 查找左子树
    BTNode* ret =  SearchBTNode(root->_left, data);

    // 左子树中未找到
    if(!ret) {
        // 查找右子树
        ret = SearchBTNode(root->_right, data);
    }
    return ret;
}

BTNode* CopyBinTree(BTNode* root) {
    if(!root) {
        return NULL;
    }
    
    // 拷贝当前节点
    BTNode* root_new = _NewNode(root->_data);
    if(!root_new) {
        return NULL;
    }
    // 拷贝左子树
    root_new->_left = CopyBinTree(root->_left);
    // 拷贝右子树
    root_new->_right = CopyBinTree(root->_right);
    
    return root_new;
}

// 交换
void _Swap(BTNode** left, BTNode** right) {
    BTNode* tmp = *left;
    *left = *right;
    *right = tmp;
}

void MirrorBinTree(BTNode* root) {
    if(!root) {
        return;
    }
    // 交换左右节点
    _Swap(&root->_left, &root->_right);
    // 镜像左子树
    MirrorBinTree(root->_left);
    // 镜像右子树
    MirrorBinTree(root->_right);
}

int CompleteBinTree(BTNode* root) {
    if(!root) {
        return 0;
    }

    Queue queue;
    InitQueue(&queue);
    PushQueue(&queue, root);
    while(!EmptyQueue(&queue)) {
        BTNode* pcur = HeadOfQueue(&queue);
        PopQueue(&queue);

        // 节点有右没左不是完全二叉树
        if(!pcur->_left && pcur->_right) {
            return 0;
        }

        if(pcur->_left) {
            PushQueue(&queue, pcur->_left);
        }
        if(pcur->_right) {
            PushQueue(&queue, pcur->_right);
        }

        // 右节点为空,之后所有的节点不应有子节点,有则不是完全二叉树
        if(!pcur->_right) {
            while(!EmptyQueue(&queue)) {
                BTNode* next = HeadOfQueue(&queue);
                PopQueue(&queue);
                if(next->_left || next->_right) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
