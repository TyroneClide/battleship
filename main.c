#include <stdio.h>
#include <stdlib.h>

struct player {
	char* oceanGrid;
	char* targetGrid;
};

enum Boats {
    carrier = 5,
    battleship = 4,
    destroyer = 3,
    submarine = 3,
    patrolBoat = 2
};


const int W = 10, H = 10;

void initPlayer(struct player plyr);
void display(struct player plyr);

int main() {
    
    struct player plyr = {malloc((W*H)*sizeof(char)), malloc((W*H)*sizeof(char))};
    struct player comp = {malloc((W*H)*sizeof(char)), malloc((W*H)*sizeof(char))};
    
	initPlayer(plyr);
	initPlayer(comp);
    //display(plyr);
}

//Initializes a player's oceanGrids
void initPlayer(struct player plyr){
    //Initilaze blank grids
	for(int i = 0; i < W*H; i++){
    	plyr.oceanGrid[i] = ' ';
    	plyr.targetGrid[i] = ' ';
    }
    
    int unavailable[17];
    int r = rand()%100 + 1;
    for(i = 0; i < battleship
}

//Displays the turn screen for a player
void display(struct player plyr){
	//Header
	printf("`            Target Grid                               Ocean Grid\n");
	printf("`   ");
	for(int i = 0; i < W; i++){
    	if(i < 8) printf("%d  ", i + 1);
        else printf("%d ", i + 1);
    }
    printf("           ");
    for(int i = 0; i < W; i++){
    	if(i < 8) printf("%d  ", i + 1);
        else printf("%d ", i + 1);
    }
    printf("\n\n");    
    
    //Displays Both oceanGrids
    for (int i = 0; i < H; i++) {
    	printf("%c | ", 'a'+i);
    	for (int j = 0; j < W; j++)
            printf("%c  ", plyr.oceanGrid[i * H + j]);
        printf("      ");
    	printf("%c | ", 'a'+i);
        for (int j = 0; j < W; j++)
            printf("%c  ", plyr.targetGrid[i * H + j]);
        
            
        printf("\n\n");
    }
}

void addShip(ship
