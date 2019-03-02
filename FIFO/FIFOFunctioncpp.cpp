#include"global.h"



int QfCreate( QueueFIFO* pQueue) // inicjalizuje kolejke zwraca 1 i 0 
{
	//!!!!!
	pQueue->pHead =	pQueue->pTail = NULL;
	return 1;
}
int QFEmpty( QueueFIFO* queue )	// zwraca 1 gdy pusta, else 0
{
	return !( queue->pHead );
}
void QFEnqueue( QueueFIFO* queue, int x )// wstawia na koniec kolejki
{
	QFIFOItem* nowy = ( QFIFOItem* ) calloc( 1, sizeof( QFIFOItem ) );	
	if( !nowy )
	{
		perror( "ERROR-BAD MEMORY ALLOCATION!!!" );
	}
	if( QFEmpty( queue ) )
	{
		queue->pHead = nowy;
	}
	else
	{
		queue->pTail->pNext = nowy;
	}
	queue->pTail = nowy;
	queue->pTail->nKey = x;
	queue->pTail->pNext = NULL;
	
	
}
int QFDequeue( QueueFIFO* queue ) //nie zwalnia pamieci, tylko zwraca wskaznik i wstawia tam NULL	  = sciagniecie ala pop
{
	if( !QFEmpty( queue ) )
	{
		int a = queue->pHead->nKey;
		QFDel( queue );
		return a;
	}
	printf( " Kolejka jest pusta" );
	return 0;

}
void QFClear( QueueFIFO* queue ) //czysci wszystkie podlaczone elementy dynamiczne- czysci kolejke, ustawia head i tail na nulla
{
	while( queue->pHead )
		QFDequeue( queue );
	
}
void QFRemove( QueueFIFO* queue )	//czysci cala kolejke, usuwa ja 
{
	free( queue->pHead );
	queue->pHead = NULL;
	queue->pTail = NULL;
}
void QFDel( QueueFIFO* queue )// usuwa tylko pierwszy element
{
	if( !QFEmpty( queue ) )
	{
		QFIFOItem * v= queue->pHead;
		queue->pHead = queue->pHead->pNext;
		if( !( queue->pHead ) )queue->pTail = NULL;
		free( v );
	}
	else
		printf( "Kolejka jest pusta" );
}

void QFPrint( QueueFIFO q )
{
	if( !QFEmpty( &q ) )
	{
		int i = 0;
		while((q.pHead) )
		{
			printf( "%d: %d\n", i++, q.pHead->nKey );
			q.pHead = q.pHead->pNext;
		}
	}
	else
		printf( "Kolejka jest pusta" );
}