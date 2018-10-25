int player_x;
int player_y;
int ddong_x1[5];
int ddong_y1[5];
int ddong_flag[5];
int life;

void playerDraw(){
	drawRect(player_x,player_y,player_x+10,player_y+10);
}
void ddongDraw(int x){
	eraseEllipse(ddong_x1[x],ddong_y1[x],ddong_x1[x]+10,ddong_y1[x]+10);
	ddong_y1[x]--;
	switch(x){
	case 0:
		ddong_y1[x]--;
		break;
	case 1:
		ddong_y1[x]-=0.1;
		break;
	case 2:
		ddong_y1[x]-=0.5;
		break;
	case 3:
		ddong_y1[x]--;
		break;
	case 4:
		ddong_y1[x]-=0.8;
		break;
	}
	drawEllipse(ddong_x1[x],ddong_y1[x],ddong_x1[x]+10,ddong_y1[x]+10);
	if(ddong_y1[x]<0||((player_x-5 < ddong_x1[x])&&(ddong_x1[x]<player_x +15)&&(ddong_y1[x] < player_y+10))){
		eraseEllipse(ddong_x1[x],ddong_y1[x],ddong_x1[x]+10,ddong_y1[x]+10);
		ddong_y1[x] = 110;
		ddong_flag[x] = 1;
		if(player_x-5 < ddong_x1[x] && ddong_x1[x]<player_x +15 && player_y+10){
			life--;
		}
	}else{
		ddong_flag[x] = 0;
	}
}
void MainInit(){
	int i=0;
	eraseDisplay();
	player_x = 77;
	player_y = 10;
	life = 3;
	for(i=0; i<5; i++){
		ddong_x1[i] = 0;
		ddong_y1[i] = 110;
		ddong_flag[i] = 0;
	}
}
void PlayerAct(){
	if((player_x > 0 ) && (player_x < 177)){
		if(getButtonPress(buttonLeft) == 1){
			eraseRect(player_x,player_y,player_x+10,player_y+10);
			player_x--;
			playerDraw();
		}
		if(getButtonPress(buttonRight) == 1){
			eraseRect(player_x,player_y,player_x+10,player_y+10);
			player_x++;
			playerDraw();
		}
	}
}
task main()
{
	int ddong_number=0;
	MainInit();
	playerDraw();
	while(1){
		int i=0;
		for(i=0;i<ddong_number+1;i++){
			if(ddong_flag[i] == 1 || ddong_y1[i] == 110){
				ddong_x1[i] = (unsigned)rand()%177 + 10 ;
			}
			ddongDraw(i);
		}
		PlayerAct();
		ddong_number++;
		if(ddong_number==5){
			ddong_number=4;
		}
		displayBigStringAt(5, 110, "%d", life);
		if(life == 0) {
			break;
		}
		sleep(50);
	}
	eraseDisplay();
	displayBigTextLine(5,"Game Over");
	sleep(5000);
}
