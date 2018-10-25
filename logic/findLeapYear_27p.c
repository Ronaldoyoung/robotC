int leapYear[100];

bool checkLeapYear(int year){
	if((year%4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		return true;
	}
	return false;
}

void printArray(){
	int i=0;
	int page = 1;
	for(i=0;i<100;i++){
		if( i % 14 == 0 && i != 0){
			page++;
			waitForButtonPress();
			flushButtonMessages();
			eraseDisplay();
		}
		displayCenteredTextLine(0,"%d page / 8", page);
		displayTextLine(i % 14 + 1, "%d", leapYear[i]);
		sleep(500);
	}
}

task main()
{
	int year = 1909;
	int count = 0;
	while(count <100){
		if(checkLeapYear(year)){
			leapYear[count] = year;
			count++;
			year++;
			}else{
			year++;
		}

	}
	printArray();

}
