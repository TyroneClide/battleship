#include <stdio.h>
#include <stdlib.h>

struct player {
	char* board;
	char* shots;
};

const int W = 10, H = 10;

void initPlayer(struct player plyr);
void display(struct player plyr);

int main() {
    struct player plyr = {malloc((W*H)*sizeof(char))};
	initPlayer(plyr);
    display(plyr);
}

//Initializes a player's boards
void initPlayer(struct player plyr){
	for(int i = 0; i < W*H; i++){
    	plyr.board[i] = 'x';
    	plyr.shots[i] = 'x';
    }
}

//Displays the turn screen for a player
void display(struct player plyr){
	//Header
	printf("    ");
	for(int i = 0; i < W; i++){
    	if(i < 8) printf("%d  ", i + 1);
        else printf("%d ", i + 1);
    }
    printf("\n\n");    
    
    //Displays Both Boards
    for (int i = 0; i < H; i++) {
    	printf("%c | ", 'a'+i);
    	for (int j = 0; j < W; j++){
            printf("%c  ", plyr.board[i * H + j]);
			printf("			");            
            printf("%c  ", plyr.shots[i * H + j]);
        }
            
        printf("\n\n");
    }
}
