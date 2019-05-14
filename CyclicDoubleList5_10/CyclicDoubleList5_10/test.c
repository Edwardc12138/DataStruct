#include "CyclicDoubleList.h"
#include <stdlib.h>

int main() {
	CDLNode* head;
	InitCDL(&head);

	//InsertData(head, 2, 2);
	//InsertData(head, 0, 1);
	//InsertData(head, 1, 2);
	//InsertData(head, 2, 3);
	//InsertData(head, 1, 4);
	//InsertData(head, 2, 5);
	//PrintCDL(head);

	//RemoveCDLNode(head, 8);
	//RemoveCDLNode(head, 1);
	//RemoveCDLNode(head, 0);
	//RemoveCDLNode(head, 2);
	//PrintCDL(head);

	PushFrontData(head, 3);
	PushFrontData(head, 1);
	PushFrontData(head, 2);
	//PrintCDL(head);
	//PopFrontCDLNode(head);
	//PopFrontCDLNode(head);
	//PopFrontCDLNode(head);
	//PrintCDL(head);

	PushBackData(head, 4);
	PushBackData(head, 6);
	PushBackData(head, 8);
	//PrintCDL(head);
	//PopBackCDLNode(head);
	//PopBackCDLNode(head);
	//PopBackCDLNode(head);
	//PrintCDL(head);

	//ClearCDL(head);
	//PrintCDL(head);
	//DesroyCDL(&head);

	//if (SearchCDLNode(head, 8)) {
	//	printf("找到了\n");
	//}
	//else {
	//	printf("没找到\n");
	//}

	PushFrontData(head, 3);
	PushFrontData(head, 1);
	PushFrontData(head, 2);
	PrintCDL(head);

	RemoveAllData(head, 2);
	PrintCDL(head);

	system("pause");
	return 0;
}