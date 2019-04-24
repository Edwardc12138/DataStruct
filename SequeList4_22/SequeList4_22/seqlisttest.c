#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SeqList.h"

int main()
{
	SeqListPtr seqlist = (SeqListPtr)malloc(sizeof(SeqList));
	InitSeqList(seqlist, 10);
	//printf("%d\n", EmptySeqList(seqlist));
	//for (int i = 0; i < 5; ++i)
	//{
	//	InsertSeqList(seqlist, i, i);
	//}
	//printf("%d\n", EmptySeqList(seqlist));
	//PrintSeqList(seqlist);
	//EraseSeqList(seqlist, 1);
	//PrintSeqList(seqlist);
	//// ·Ç·¨¼ì²â
	//InsertSeqList(seqlist, 9, 9);
	//PrintSeqList(seqlist);
	//EraseSeqList(seqlist, 9);
	//PrintSeqList(seqlist);

	//for (int i = 0; i < 10; ++i)
	//{
	//	PushBackSeqList(seqlist, 10 + i);
	//}

	//PushBackSeqList(seqlist, 5);
	//PrintSeqList(seqlist);
	//PopBackSeqList(seqlist);
	//PrintSeqList(seqlist);

	//PushFrontSeqList(seqlist, 6);
	//PrintSeqList(seqlist);
	//PopFrontSeqList(seqlist);
	//PrintSeqList(seqlist);

	//printf("%d\n", SearchSeqList(seqlist, 10));
	//printf("%d\n", SearchSeqList(seqlist, 30));

	//printf("%d\n", SizeSeqList(seqlist));
	//printf("%d\n", CapSeqList(seqlist));

	////ClearSeqList(seqlist);
	////PrintSeqList(seqlist);

	//DelSeqList(seqlist, 10);
	//PrintSeqList(seqlist);
	//DelSeqList(seqlist, 30);
	//PrintSeqList(seqlist);
	srand((unsigned)time(NULL));
	for (int i = 0; i < 50; ++i)
	{
		PushBackSeqList(seqlist, rand() % 2);
	}
	//BubbleSortSeqList(seqlist);
	PrintSeqList(seqlist);
	//printf("%d\n", BinarySearchSeqList(seqlist, 9));

	RemoveAllSeqList(seqlist, 1);
	PrintSeqList(seqlist);

	DestroySeqList(seqlist);
	free(seqlist);

	system("pause");
	return 0;
}