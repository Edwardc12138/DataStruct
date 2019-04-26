#include <stdlib.h>
#include "SingleList.h"

int main() {
	SingleListPtr list = (SingleListPtr)malloc(sizeof(SingleList));
	InitSingleList(list);
	//for (int i = 0; i < 10; ++i) {
	//	InsertSLNode(list, i, i);
	//}
	//PrintSingleList(list);
	//RemoveAtSLNode(list, 0);
	//PrintSingleList(list);
	//RemoveAtSLNode(list, 5);
	//PrintSingleList(list);
	//RemoveAtSLNode(list, 7);
	//PrintSingleList(list);
	//RemoveAtSLNode(list, 10);
	//PrintSingleList(list);
	//ClearSingleList(list);
	//PrintSingleList(list);
	//RemoveAtSLNode(list, 0);
	//PrintSingleList(list);

	//PopFrontSLNode(list);	// ¿ÕÉ¾
	//PopBackSLNode(list);

	//PushFrontSLNode(list, 1);
	//PrintSingleList(list);
	//PopFrontSLNode(list);
	//PrintSingleList(list);
	//PushFrontSLNode(list, 1);
	//PushFrontSLNode(list, 2);
	//PrintSingleList(list);
	//PopFrontSLNode(list);
	//PrintSingleList(list);
	//PopFrontSLNode(list);
	//PrintSingleList(list);

	//PushBackSLNode(list, 1);
	//PrintSingleList(list);
	//PopBackSLNode(list);
	//PrintSingleList(list);
	//PushBackSLNode(list, 1);
	//PushBackSLNode(list, 2);
	//PrintSingleList(list);
	//PopBackSLNode(list);
	//PrintSingleList(list);
	//PopBackSLNode(list);
	//PrintSingleList(list);

	for (int i = 0; i < 10; ++i) {
		InsertSLNode(list, 2 * i, 3);
		InsertSLNode(list, 2 * i + 1, i);
	}
	//NodePtr p = SearchSLNode(list, 15);
	//RemoveSLNode(list, 9);
	RemoveAllSLNode(list, 3);
	PrintSingleList(list);
	printf("%d\n", SizeofSingleList(list));
	free(list);

	system("pause");
	return 0;
}