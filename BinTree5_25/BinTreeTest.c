#include <stdio.h>
#include "BinTree.h"
#include <string.h>
int main()
{
    
    // char str[] = "ABD###CE##F##";
    //char str[] = "ABCD#####";
    //char str[] = "A#B#C#D##";
    //char str[] = "ABDH##I##E##CFG##K##GL##M##";
    char str[] = "ABD##E##CF###";
    int size = strlen(str);
    BTNode* root = CreatBinTree(str, size, '#');
    printf("前序遍历: ");
    PreOrder(root);
    printf("\n");
    printf("中序遍历: ");
    InOrder(root);
    printf("\n");
    printf("后序遍历: ");
    PostOrder(root);
    printf("\n");
    printf("层序遍历: ");
    LevelOrder(root);
    printf("\n");
    printf("节点个数: %d\n", SizeBinTree(root));
    int k = 2;
    printf("第%d层节点个数: %d\n", k, LevelSizeBinTree(root, k));
    printf("叶节点个数: %d\n", LeafSizeBinTree(root));
    printf("深度: %d\n", HighBinTree(root));
    BTNode* p = SearchBTNode(root, 'C');
    if(p) {
        printf("找到了\n");
    }
    else {
        printf("未找到\n");
    }
    printf("拷贝: ");
    BTNode* pcopy = CopyBinTree(root);
    PreOrder(pcopy);
    printf("\n");
    printf("镜像: ");
    MirrorBinTree(root);
    PreOrder(root);
    printf("\n");
    MirrorBinTree(root);
    if(CompleteBinTree(root)) {
        printf("完全二叉树\n");
    }
    else {
        printf("不是完全二叉树\n");
    }
    DestroyBinTree(&root);
    return 0;
}

