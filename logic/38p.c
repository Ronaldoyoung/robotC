#define PADDING_LEFT 30
#define PADDING_TOP 4
#define MAX_COL 10
#define MAX_ROW 10
#define C_SIZE 12

void ato_init(){
	displayCenteredTextLine(5,"Press any button!");
	waitForButtonPress();
}

void ato_waitForExit(){
	flushButtonMessages();
	waitForButtonPress();
}
int ato_getRandCoord(){
	int ret = abs(rand()%10);
	return ret;
}
void drawPlayer(int x, int y){
	int st_x = x*C_SIZE + PADDING_LEFT;
	int st_y = y*C_SIZE + PADDING_TOP;
	fillRect(st_x, st_y, st_x + C_SIZE, st_y + C_SIZE);
}
void erasePlayer(int x, int y){
	int st_x = x*C_SIZE + PADDING_LEFT;
	int st_y = y*C_SIZE + PADDING_TOP;
	eraseRect(st_x, st_y, st_x + C_SIZE, st_y + C_SIZE);
	drawRect(st_x, st_y, st_x + C_SIZE, st_y + C_SIZE);
}
task main()
{
	int st_x,st_y=0;
	int x=0,y=1;
	ato_init();

	eraseDisplay();
	for(int col = 0; col< MAX_COL; col++){
		for(int row = 0; row< MAX_ROW; row++){
			st_x = col*C_SIZE + PADDING_LEFT;
			st_y = row*C_SIZE + PADDING_TOP;
			drawRect(st_x, st_y, st_x+ C_SIZE, st_y+C_SIZE);
		}
	}
		while(1){
			for(int j=0; j< 10;j++){
				for(int i=0; i < 10; i++){
					drawPlayer(i,j);
				}
				sleep(1000);
				for(int i=0; i < 10; i++){
					erasePlayer(i,j);
				}
			}
		}
		ato_waitForExit();
}
