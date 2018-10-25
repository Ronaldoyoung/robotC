task main()
{
	int array[5];
	int length = sizeof(array)/sizeof(int);
	int temp;
	int cnt;
	for(int i=0; i<5; i++){
		array[i] = (unsigned)rand()%5;
		displayTextLine(i+1,"%d",array[i]);
	}

	for(int i=0;i<length-1;i++){
		for(int j=0;j<length-1;j++){
			if(array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
			cnt++;
		}
	}
	for(int i=0; i<5; i++){
		displayTextLine(i+10,"%d",array[i]);
	}

	displayTextLine(7,"%d switch", cnt);
	waitForButtonPress();
	flushButtonMessages();

}
