#include <stdio.h>
#include <stdlib.h>
#include<string.h>

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
	//printf("beans\n");
        int *arr = makeIntArray(1000000);
        char **strs = malloc(1000000*sizeof(char*));
	for(int i = 0; i < 1000000; i++){
		strs[i] = malloc(1000*sizeof(char));
	}
        int counter = 0;
	int currState = 0;
	int beegCounter = 0;
        states *statearr = malloc(1001*sizeof(states));
	int **sizes = makeIntMatrix(1001,2);
        statearr[1].isStart = 1;
        statearr[7].isAccept = 1;
        statearr[1].zeroOutcomes = malloc(2*sizeof(int));
	sizes[1][0] = 2;
        //statearr[1].zeroOutcomes = realloc(statearr[1].zeroOutcomes, 2 * sizeof(int));
        statearr[1].zeroOutcomes[0] = 1;
        statearr[1].zeroOutcomes[1] = 2;
        statearr[1].oneOutcomes = malloc(sizeof(int));
	sizes[1][1] = 1;
        statearr[1].oneOutcomes[0] = 1;
        statearr[2].zeroOutcomes = malloc(3*sizeof(int));
	sizes[2][0] = 3;
        statearr[2].zeroOutcomes[0] = 1;
        statearr[2].zeroOutcomes[1] = 2;
        statearr[2].zeroOutcomes[2] = 7;
        statearr[2].oneOutcomes = malloc(sizeof(int));
	sizes[2][1] = 1;
        statearr[2].oneOutcomes[0] = 1;
        statearr[7].zeroOutcomes = malloc(sizeof(int));
	sizes[7][0] = 1;
        statearr[7].zeroOutcomes[0] = 7;
        statearr[7].oneOutcomes = malloc(sizeof(int));
	sizes[7][1] = 1;
        statearr[7].oneOutcomes[0] = 7;
        for(int i = 0; i < 1001; i++){
                if(statearr[i].isStart == 1){
                        arr[0] = i;
			//currState = i;
                        //printf("%d\n", i);
                        break;
                }
        }
        strcpy(strs[0], "000");
	//printf("%ld\n",sizeof(int));
        do{
		currState = arr[beegCounter];
		//printf("%d\n", currState);
		char* temp = strs[beegCounter] + 1;
                if(strs[counter][0] == '0'){
                        for(int i = 0; i < sizes[currState][0]; i++){
				counter++;
				arr[counter] = statearr[currState].zeroOutcomes[i];
				strcpy(strs[counter], temp);
				printf("%d\n",i);
			}
                }
		else{
			 for(int i = 0; i < sizes[currState][1]; i++){
                                counter++;
                                arr[counter] = statearr[currState].oneOutcomes[i];
                                strcpy(strs[counter], temp);
                        }
		}
		beegCounter++;
        } while(strs[beegCounter][0] != '\0');
	for(int i = 0; i < 1000000; i++){
		if(strs[i][0] == '\0' && arr[i] == 7){
			printf("ggez top gap go next ur outclassed\n");
			break;
		}
	}
}
