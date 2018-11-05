#define PADDING_LEFT 30
#define PADDING_TOP 4
#define MAX_COL 10
#define MAX_ROW 10
#define C_SIZE 12

void ato_init(){
	displayCenteredBigTextLine(5,"Press any button");
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
		int st_x = x * C_SIZE + PADDING_LEFT;
		int st_y = y * C_SIZE + PADDING_TOP;
		fillRect(st_x , st_y , st_x + C_SIZE, st_y + C_SIZE);
}

void erasePlayer(int x, int y){
	int st_x = x * C_SIZE + PADDING_LEFT;
	int st_y = y * C_SIZE + PADDING_TOP;
	eraseRect(st_x , st_y , st_x + C_SIZE, st_y + C_SIZE);
	drawRect(st_x , st_y , st_x + C_SIZE, st_y + C_SIZE);
}

task main()
{
	int st_x, st_y = 0;
	int rnd_x=0, rnd_y=0;
	rnd_x = ato_getRandCoord();
	rnd_y = ato_getRandCoord();

	ato_init();
	eraseDisplay();
	for(int col = 0 ; col < MAX_COL ; col ++){
		for(int row = 0 ; row < MAX_ROW ; row++){
			st_x = col * C_SIZE + PADDING_LEFT;
			st_y = row * C_SIZE + PADDING_TOP;
			drawRect(st_x , st_y , st_x + C_SIZE, st_y + C_SIZE);
		}
	}
	drawPlayer(rnd_x,rnd_y);
	while(1){
		if(getButtonPress(buttonLeft) == 1 && rnd_x > 0 ){
			erasePlayer(rnd_x,rnd_y);
			rnd_x -= 1;
		}
		if(getButtonPress(buttonRight) == 1 && rnd_x < 9){
			erasePlayer(rnd_x,rnd_y);
			rnd_x += 1;
		}
		if(getButtonPress(buttonUp) == 1 && rnd_y < 9){
			erasePlayer(rnd_x,rnd_y);
			rnd_y += 1;
		}
		if(getButtonPress(buttonDown) == 1 && rnd_y > 0){
			erasePlayer(rnd_x,rnd_y);
			rnd_y -= 1;
		}
		drawPlayer(rnd_x,rnd_y);
    ato_waitForExit();
	}


}
