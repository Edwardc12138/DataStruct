#pragma once

typedef char BTDataType;

typedef struct BTNode {
    BTDataType _data;   // 数据
    struct BTNode* _left;   // 左子节点
    struct BTNode* _right;  // 右子节点
} BTNode;

// 创建树,invalid表示空节点
BTNode* CreatBinTree(BTDataType* arr, int size, BTDataType invalid);

// 销毁
void DestroyBinTree(BTNode** root);

// 前序遍历
void PreOrder(BTNode* root);

// 中序遍历
void InOrder(BTNode* root);

// 后序遍历
void PostOrder(BTNode* root);

// 层序遍历
void LevelOrder(BTNode* root);

// 节点个数
int SizeBinTree(BTNode* root);

// 第k层节点个数
int LevelSizeBinTree(BTNode* root, int k);

// 获取叶节点个数
int LeafSizeBinTree(BTNode* root);

// 获取深度
int HighBinTree(BTNode* root);

// 查找
BTNode* SearchBTNode(BTNode* root, BTDataType data);

// 拷贝二叉树
BTNode* CopyBinTree(BTNode* root);

// 二叉树镜像
void MirrorBinTree(BTNode* root);

// 是否是完全二叉树
int CompleteBinTree(BTNode* root);
