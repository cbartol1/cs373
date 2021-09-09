#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int isStart;
	int isAccept;
	int *oneOutcomes;
	int *zeroOutcomes;
}states;

int *makeIntArray(int length){
	int *p = NULL;
	if( length > 0 ){
		p = (int *) malloc(length*sizeof(int));
	}
	return p;
}
void deleteIntArray(int *p){
	if( p != NULL ){
		free(p);
	}
}
int **makeIntMatrix(int width, int height){
	int **p = (int **) NULL;
	int *pData = (int *) NULL;
	if( (width > 0) && (height > 0) ){
		p = (int **) malloc(width*sizeof(int*));
		pData = (int *) malloc(width*height*sizeof(int));
		int i = 0;
		while( i < width ){
			p[i] = pData+(i*height);
			i = i+1;
		}
	}
	return p;
}
void deleteIntMatrix(int **p){
	if( p != NULL ){
		if( p[0] != NULL ){
			free(p[0]);
		}
	free(p);
	}
}

int main(int argc, char* argv[]){
	int *arr = makeIntArray(1000000);
	states statearr[1001];
	statearr[1].isStart = 1;
	statearr[7].isAccept = 1;
}

