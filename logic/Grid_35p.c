#define PADDING_LEFT 4
#define PADDING_TOP 4
#define MAX_COL 10
#define MAX_ROW 10
#define C_SIZE 10

void ato_init(){
	displayCenteredBigTextLine(5, "Press any button");
	waitForButtonPress();
}

void ato_waitForExit(){
	flushButtonMessages();
	waitForButtonPress();
}

task main()
{
	int st_x, st_y = 0;
	ato_init();

	for(int col = 0; col < MAX_COL; col++){
		for(int row = 0; row < MAX_ROW; row++){
			st_x = col*C_SIZE + PADDING_LEFT;
			st_y = row*C_SIZE + PADDING_TOP;
			drawRect(st_x, st_y, st_x+C_SIZE, st_y+C_SIZE);
		}
	}
	ato_waitForExit();
}
