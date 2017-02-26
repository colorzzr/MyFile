/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mid-term 2012.h
 * Author: user
 *
 * Created on February 24, 2017, 11:09 PM
 */

#ifndef MID_TERM_2012_H
#define MID_TERM_2012_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* MID_TERM_2012_H */

/**************************************************
 * mid-term 2012 No.11                            *
 * function are able to guess the secrete number  *
 * which the user choosen                         *
 **************************************************/
void MidTerm2012No11 (){
    int guess;
    int min, max;
    bool result = false;
   
    //ask for the max and min value 
    printf("please enter your min and max value: ");
    scanf("%d %d", &min, &max);
    
    /***************************************************************
     * check the value in the interval min ~ min + (min + max) / 2 *
     * or in the interval (min + max) / 2 ~ max                    *
     ***************************************************************/
    while (result != true){
        printf("is your secrete number in the %d ~ %d (1 for yes 0 for no)?", min, ((max - min) / 2) + min);
        scanf("%d", &guess);
        
        //yes means number is in first interval no for second interval
        if (guess == 0){
            min = ((max - min) / 2) + min + 1;
        }
        else if (guess == 1){
            max = ((max - min) / 2) + min;
        }
        
        //check for the secrete number
        if (min == max){
            result = true;
        }
    
    }
    
    printf("the secrete number is %d", min);

    return;
}

/*************************************************
 * mid-term 2012 No.12                           *
 * the function would print from 1 to user input *
 * when userInput % 3 == 0 print Bizz            *
 * when userInput % 5 == 0 print Buzz            *
 * when both print BizzBuzz                      *
 * otherwise sum up and print it                 *
 *************************************************/
void Midterm2012No12 () {
    int userInput, sum = 0;
    
    printf("Enter number; ");
    scanf("%d" , &userInput);
    
    //use loop to check the number whether is factor of 5 or 3 or both
    for (int i = 1; i <= userInput; i++){
        //both
        if (i % 5 == 0 && i % 3 == 0){
            printf("BizzBuzz\n");
        }
        
        //%3
        else if (i % 3 == 0){
            printf("Bizz\n");
        }
        
        //%5
        else if (i % 5 == 0){
            printf("Buzz\n");
        }
        
        //if not sum up and print it
        else {
            printf("%d\n", i);
            sum = sum + i;
        }
    }
    
    printf("Sum is %d", sum);
    
    return;
}

/********************************************************* 
 * mid-term 2012 No.13                                   *
 * the function would ask for 3 input                    *
 * input number n, replaced number d and placed number r *
 * Ex n = 2565, d = 5, r = 3.                            *
 * Output would be 2363                                  *
 *********************************************************/
void Midterm2012No13 (int n, int d, int r){
    int count = 0, temp = n;
    
    //check the length of input
    while (temp > 0){
        temp = temp / 10;
        count++;
    }
    printf("count is %d\n",count);
    
    
    //throw out specific place of number
    for (int i = 0; i < count; i++){
        /*******************************************
         * ----------Color Warning !!!_----------- *
         * careful when you do integer division    *
         * in the pow function                     *
         * 234 / pow(10, 1) * 10 would not get 230 *
         * it would get 234 instead                *
         * why the computer so smart               *
         * do not ask me how you know it           *
         ******************************************/
        temp = (n / pow(10, i + 1));
        temp = (n / pow(10, i)) - temp * 10;
        //temp = (n / pow(10, i))- (n / pow(10, i + 1))* 10;
        
        //replace number
        if (temp == d){
            n = n - (temp - r)*pow(10,i);
        }

    }
    
    printf("%d", n);
}

/*******************************
 * mid-term 2012 No.14         *
 * E = 2.718281845             *
 * check the prime number in E *
 *******************************/
void MidTerm2012No14() {
    const double E = 2.718281828459045;
    int firstPrime;
    double temp;
    bool result = false;
        
    //iretate one by one 
    for(int i = 1; i < 16 && result == false; i++){
        //step up one by one
        temp = E * pow(10, i);
        printf("temp is %lf\n",temp);
          
        //use loop to get away the decimals
        for (firstPrime = 0; firstPrime < temp; firstPrime++){}
           
        //only get two digits
        firstPrime = (firstPrime - 1) % 100;
          
        //initialize to true for loop
        result = true;
        
        //check the prime number
        for (int j = 2; j < firstPrime; j++){
            if((firstPrime % j) == 0){
                result = false;
            }
        }
    }
    printf("the first prime is %d", firstPrime);
    
    return;
}
