int array[100];

void ato_bubble(){
	writeDebugStreamLine("ato_bubble call()");
	int length = sizeof(array)/sizeof(int);
	int temp;
	for(int i=0;i<length - 1;i++){
		for(int j=0; j<length - 1; j++){
			if(array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	writeDebugStreamLine("hello");
}

void ato_printEnter(){
	displayCenteredBigTextLine(1,"Fill Random");
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			displayStringAt((j+1)*15,(i+1)*10,"%d ",array[i*10+j]);
		}
	}
}

task main()
{
		for(int i=0; i < 100; i++){
			array[i] = (unsigned)rand()%100 + 1;
		}
		ato_printEnter();

		waitForButtonPress();
		flushButtonMessages();
		if(getButtonPress(buttonEnter)){
			writeDebugStreamLine("getButtonPress");
			eraseDisplay();
			ato_bubble();
		}
		ato_printEnter();
		waitForButtonPress();
}
