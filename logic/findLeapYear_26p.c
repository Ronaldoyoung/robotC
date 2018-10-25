int leapYear[100];

bool checkLeapYear(int year){
	if((year%4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		writeDebugStreamLine("this year is leapyear");
		return true;
	}
	return false;
}

void printArray(){
	writeDebugStreamLine("printArray call");
	int i=0;
	for(i=0;i<100;i++){
		if( i % 15 == 0 && i != 0){
			waitForButtonPress();
			flushButtonMessages();
			eraseDisplay();
		}
		displayTextLine(i % 15, "%d", leapYear[i]);
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
