/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mid-term 2013 structure question.h
 * Author: user
 *
 * Created on February 24, 2017, 7:02 PM
 */

#ifndef MID_TERM_2013_STRUCTURE_QUESTION_H
#define MID_TERM_2013_STRUCTURE_QUESTION_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* MID_TERM_2013_STRUCTURE_QUESTION_H */

/************************
 * mid-term 2013 No.10  *
 * input 123 output 231 *
 ************************/
void MidTerm2013No10(int a, int b, int c){
    //rotate the a and b
    int temp;
    temp = a;
    a = b;
    b = temp;
    
    //rotate the b(a) and c
    temp = b;
    b = c;
    c = temp;
    
    printf("a:%d b:%d c:%d\n", a, b, c);
    
    return;
}

/*******************************************
 * mid-term 2013 No.11                     *
 * add 1 to 1000 with following conditions *
 * 1) can be divided by 3                  *
 * 2) odd                                  *
 * 3) no 5 in tenth                        *
 *******************************************/
void MidTerm2013No11(){
    //initialize to 6 cs the 6 is valid
    int sum = 6;
    
    for (int i = 1; i <= 1000; i++){
        if (i % 3 == 0 && i % 2 == 0 && !((i/10) % 5 == 0)){
            sum = sum + i;
            printf("%d\n" , i);
        }
    }
    
    printf("%d", sum);
    
    return;
}


/**********************************
 * mid-term 2013 No.12            *
 * calculate 126 = 6 + 2 ^ 2 +1^3 *
 * which oneth ^ 1 and tenth ^ 2  *
 **********************************/
void MidTerm2013No12(){
    int num ;
    int temp; 
    int count = 0;
    int array[count];
    int sum = 0;
   
    printf("please enter your number");
    scanf("%d", &num);
    temp = num;
    
    
    //check the length
    while (temp != 0){
        temp = temp / 10;
        count++;
    }

    //cal
    for (int i = count; i > 0; i--){

        array[i] = num / (pow(10,i -1));
        sum =sum + pow(array[i],i);
        num=num - ((pow(10, i - 1)) * array[i]);
        
        printf("%d ", array[i]);
        printf("%d ",num);
        printf("%d\n",sum);    
       
    }
    return;
}

/*****************************************
 * mid-term 2013 No.13                   *
 * print the calender for specific month *
 * starting day from Sunday to Saturday  *
 *****************************************/
void MidTerm2013No13(){
    int month, startDay;
    
    printf("Enter the number of corresponding to month (1=Jan, 12=Dec): ");
    scanf("%d", &month);
    printf("Enter the Starting day of the week(1=Sun, 7=Sat): ");
    scanf("%d", &startDay);
    
    //print the headers
    printf("Su Mo Tu We Th Fr Sa\n");
    
    //leave the space for starting day
    for(int i = 1; i< startDay; i++){
        printf("   ");
    }
     
    //print out the calender
    //for the 31days months
    if(month == 1 && month == 3&& month == 5&& month == 7&& month == 8&& month == 10&& month == 12){
        for (int i = 1; i <= 31; i++){
            printf("%2d ", i);
        
            //change line for next week
            if ((startDay - 1 +i)%7 == 0){
                printf("\n");
            }
        }
    }
    
    //for 30days month
    if(month == 4 && month == 6&& month == 9&& month == 11){
        for (int i = 1; i <= 30; i++){
            printf("%2d ", i);
        
            //change line for next week
            if ((startDay - 1 +i)%7 == 0){
                printf("\n");
            }
        }
    }
    
    //for feb
    else{
        for (int i = 1; i <= 28; i++){
            printf("%2d ", i);
        
            //change line for next week
            if ((startDay - 1 +i)%7 == 0){
                printf("\n");
            }
        }
    }
    
    return;
}

/***********************************
 * mid-term 2013 No.14             *
 * input 3 would print ABC BCA CAB *
 * input 10 would print ABCDEFGHIJ *
 *                      BCDEFGHIJA *
 *                      .......... *
 ***********************************/
void MidTerm2013No14(int a) {
	for (int row = 0; row < a; row++) {
		for (int col = 0; col < a; col++) {
			
			//repeat to the first letter
			printf("%c", 'A' + ((col + row) % a));
		}
		printf("\n");
	}
}