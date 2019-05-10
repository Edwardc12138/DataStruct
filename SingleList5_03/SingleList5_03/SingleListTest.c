#include <stdio.h>
#include <stdlib.h>
#include "SingleList.h"

int main() {
	SLNodePtr head;
	InitSingleList(&head);
	PrintSL(head);

	//InsertData(&head, 0, 9);
	//InsertData(&head, 5, 0);
	//InsertData(&head, 1, 4);
	//InsertData(&head, 0, 3);
	//PrintSL(head);

	//RemoveSLNode(&head, 2);
	//PrintSL(head);
	//RemoveSLNode(&head, 0);
	//PrintSL(head);
	//RemoveSLNode(&head, 0);
	//RemoveSLNode(&head, 0);
	//RemoveSLNode(&head, 0);
	//PrintSL(head);

	//PushFrontData(&head, 4);
	//PushFrontData(&head, 3);
	//PushFrontData(&head, 2);
	//PushFrontData(&head, 1);
	//PrintSL(head);
	//PopFrontSLNode(&head);
	//PopFrontSLNode(&head);
	//PopFrontSLNode(&head);
	//PopFrontSLNode(&head);
	//PopFrontSLNode(&head);
	//PopFrontSLNode(&head);
	//PrintSL(head);

	//PushBackData(&head, 1);
	//PushBackData(&head, 2);
	//PushBackData(&head, 3);
	//PushBackData(&head, 4);
	//PrintSL(head);
	//PopBackSLNode(&head);
	//PopBackSLNode(&head);
	//PopBackSLNode(&head);
	//PopBackSLNode(&head);
	//PopBackSLNode(&head);
	//PopBackSLNode(&head);
	//PrintSL(head);

	//ClearSL(&head);
	//PrintSL(head);

	//if (FindnSLNode(head, 5)) {
	//	printf("找到了\n");
	//}
	//else {
	//	printf("没找到\n");
	//}

	PushBackData(&head, 1);
	PushBackData(&head, 2);
	PushBackData(&head, 3);
	PushBackData(&head, 4);
	PushBackData(&head, 2);
	PushBackData(&head, 3);
	PushBackData(&head, 3);
	PushBackData(&head, 4);
	PushBackData(&head, 2);
	PrintSL(head);

	RemoveAllSLNode(&head, 2);
	PrintSL(head);
	
	system("pause");
	return 0;
}