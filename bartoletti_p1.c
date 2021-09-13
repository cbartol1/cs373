#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
	int isStart;
	int isAccept;
	int beenSaid;
	//int *oneOutcomes;
	//int *zeroOutcomes;
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
	FILE *fp;
	int **trans = makeIntMatrix(1000000,3);
        int *arr = makeIntArray(1000000);
	char* buff = malloc(1000*sizeof(char));
        char **strs = malloc(1000000*sizeof(char*));
	for(int i = 0; i < 1000000; i++){
		strs[i] = malloc(1000*sizeof(char));
	}
        int counter = 0;
	int currState = 0;
	int beegCounter = 0;
	int nlines = 0;
	int n = 0;
        states *statearr = malloc(1001*sizeof(states));
	//int **sizes = makeIntMatrix(1001,10000);
	//for (int i = 0; i < 1001; i++){
		//for(int j = 0; j < 10000; j++){
			//sizes[i][j] = 0;
		//}
	//}
	fp = fopen(argv[1], "r");
	char looper = getc(fp);
	while(looper != EOF){
		if(looper == '\n') nlines++;
		looper = getc(fp);
	}
	fclose(fp);

	int sentinel = 0;

	fp = fopen(argv[1], "r");
	do{
		n++;
		//fp = fopen(argv[1], "r");
		fscanf(fp, "%s", buff);
		if(strcmp(buff, "state") == 0){
			fgets(buff, 1000, fp);
			buff++;
			int d = buff[0] - '0';
			buff = buff+2;
			//printf("%s\n", buff);
			if(strcmp(buff, "start\n") == 0){
				statearr[d].isStart = 1;
			}
			else if(strcmp(buff, "accept\n") == 0){
				statearr[d].isAccept = 1;
			}
			else{
				statearr[d].isStart = 1;
				statearr[d].isAccept = 1;
			}
			//printf("%d\n", d);
		}
		else if(strcmp(buff, "transition") == 0){
			int a,b,c;
			fgets(buff, 1000, fp);
			//printf("%s\n", buff);
			buff++;
			//printf("%s\n", buff);
			a = buff[0] - '0';
			buff = buff+2;
			b = buff[0] - '0';
			buff = buff+2;
			c = buff[0] - '0';
			trans[sentinel][0] = a;
			trans[sentinel][1] = b;
			trans[sentinel][2] = c;
			//printf("%d, %d, %d\n", trans[sentinel][0], trans[sentinel][1], trans[sentinel][2]);
			sentinel++;
			//printf("%d, %d, %d\n", a, b, c);
		}
		//n++;
		//printf("%s\n", buff);
		//fclose(fp);
	}while(n < nlines);
	fclose(fp);
	//printf("%d\n", nlines);
        //statearr[1].isStart = 1;
        //statearr[7].isAccept = 1;
        //statearr[1].zeroOutcomes = malloc(2*sizeof(int));
	//sizes[1][0] = 2;
        //statearr[1].zeroOutcomes = realloc(statearr[1].zeroOutcomes, 2 * sizeof(int));
        //statearr[1].zeroOutcomes[0] = 1;
        //statearr[1].zeroOutcomes[1] = 2;
        //statearr[1].oneOutcomes = malloc(sizeof(int));
	//sizes[1][1] = 1;
        //statearr[1].oneOutcomes[0] = 1;
        //statearr[2].zeroOutcomes = malloc(3*sizeof(int));
	//sizes[2][0] = 3;
        //statearr[2].zeroOutcomes[0] = 1;
        //statearr[2].zeroOutcomes[1] = 2;
        //statearr[2].zeroOutcomes[2] = 7;
        //statearr[2].oneOutcomes = malloc(sizeof(int));
	//sizes[2][1] = 1;
        //statearr[2].oneOutcomes[0] = 1;
        //statearr[7].zeroOutcomes = malloc(sizeof(int));
	//sizes[7][0] = 1;
        //statearr[7].zeroOutcomes[0] = 7;
        //statearr[7].oneOutcomes = malloc(sizeof(int));
	//sizes[7][1] = 1;
        //statearr[7].oneOutcomes[0] = 7;
        for(int i = 0; i < 1001; i++){
                if(statearr[i].isStart == 1){
                        arr[0] = i;
			//currState = i;
                        //printf("%d\n", i);
                        break;
                }
        }
        strcpy(strs[0], argv[2]);
	//printf("%ld\n",sizeof(int));
        do{
		currState = arr[beegCounter];
		//printf("%d\n", currState);
		char* temp = strs[beegCounter] + 1;
		int num = strs[beegCounter][0]-'0';
		//printf("%d\n", num);
		for(int i = 0; i < 1000000; i++){
			if(trans[i][1] == num && currState == trans[i][0]){
				counter++;
				//printf("%d\n", i);
				//printf("%d, %d, %d\n", trans[i][0], trans[i][1], trans[i][2]);
				arr[counter] = trans[i][2];
				strcpy(strs[counter], temp);
			}
		}
                //if(strs[beegCounter][0] == '0'){
                        //for(int i = 0; i < sizes[currState][0]; i++){
				//counter++;
				//arr[counter] = statearr[currState].zeroOutcomes[i];
				//strcpy(strs[counter], temp);
				//printf("%d\n",i);
			//}
                //}
		//else if(strs[beegCounter][0] == '1'){
			 //for(int i = 0; i < sizes[currState][1]; i++){
                                //counter++;
                                //arr[counter] = statearr[currState].oneOutcomes[i];
                                //strcpy(strs[counter], temp);
                        //}
		//}
		//printf("%s\n",strs[beegCounter]);
		beegCounter++;
        } while(strs[beegCounter][0] != '\0');
	int flag = 0;
	//char *output = malloc(10000*sizeof(char));
	for(int i = 0; i < 1000000; i++){
		//printf("%s, %d\n", strs[i], arr[i]);
		//printf("%d\n", statearr[arr[i]].isStart);
		//if(arr[i] == 0) break;
		if(strs[i][0] == '\0' && statearr[arr[i]].isAccept == 1 && statearr[arr[i]].beenSaid != 1){
			if(flag == 0) printf("Accept ");
			flag = 1;
			printf("%d ", arr[i]);
			statearr[arr[i]].beenSaid = 1;
		}
	}
	if(flag == 0){
		for(int i = 0; i < 1000000; i++){
                //printf("%s, %d\n", strs[i], arr[i]);
                //printf("%d\n", statearr[arr[i]].isStart);
                //if(arr[i] == 0) break;
                	if(strs[i][0] == '\0' && statearr[arr[i]].isAccept != 1 && statearr[arr[i]].beenSaid != 1 && arr[i] != 0){
                        	if(flag == 0) printf("Reject ");
                        	flag = 1;
                        	printf("%d ", arr[i]);
                        	statearr[arr[i]].beenSaid = 1;
                	}
        	}
	}
	printf("\n");
	//if(flag == 1) printf("%s\n", output);
}
