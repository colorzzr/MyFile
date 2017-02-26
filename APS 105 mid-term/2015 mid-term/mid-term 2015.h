/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mid-term 2015 structure question.h
 * Author: user
 *
 * Created on February 24, 2017, 7:42 PM
 */

#ifndef MID_TERM_2015_STRUCTURE_QUESTION_H
#define MID_TERM_2015_STRUCTURE_QUESTION_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* MID_TERM_2015_STRUCTURE_QUESTION_H */

/*************************************
 * mid-term 2015 No.10               *
 * use ASCII code to sort your input *
 * is lower case or upper case       *
 * or number or special              * 
 *************************************/
void MidTerm2015No10() {
    int inputChar = 'A';
    
    printf("please enter your testing number: ");
    scanf("%c", &inputChar);
    
    //check the input by corrosponding ASCII number
    //Upper case
    if ((inputChar >= 'A') && (inputChar <= 'Z')){
        printf("Upper Case.");
    }
    
    //Lower Case
    else if ((inputChar >= 'a') && (inputChar <= 'z')){
        printf("Lower Case.");
    }
    
    //digital
    else if ((inputChar >= '0') && (inputChar <= '9')){
        printf("Number.");
    }
    
    //special case
    else {
        printf("Special.");
    }
}

/*********************************************
 * mid-term 2015 No.11                       *
 * function would flip the userinput number  *
 * Ex. userinput = 1234 output would be 4321 *
 *********************************************/
void MidTerm2015No11 (){
    int userInput, firstNum, secondNum, thirdNum, forthNum;
    
    printf("please enter your number: ");
    scanf("%d", &userInput);
    
    //divide the number into 4 digits
    firstNum = userInput / 1000;
    secondNum = (userInput - 1000 * firstNum) / 100;
    thirdNum = (userInput - 1000*firstNum - 100*secondNum) / 10;
    forthNum = userInput - 1000*firstNum - 100*secondNum - 10*thirdNum;
    
    printf("%d%d%d%d", forthNum, thirdNum, secondNum, firstNum);
    
    return;
}

/*************************************
 * mid-term 2015 No.12               *
 * this function would define the Pi *
 *************************************/
void MidTerm2015No12 (){
    double arc1 = 0;
    double arc2 = 0;
    double x1 = 1 / 5.0;
    double x2 = 1 / 239.0;
    int j;
    
    //Pi = 16 * arctan(1 / 5.0) - 4 * arctan(1 / 239.0)
    //arctan(x) = x-x^3/3 + x^5/5.....x^301/301
    
    for (int i = 1,j = 0; i <= 301; i += 2, j++){
        arc1 = arc1 + (pow(x1,i) / i)*pow(-1,j);
        
    }
    
    for (int i = 1,j = 0; i <= 301; i += 2,j++){
        arc2 = arc2 + (pow(x2,i) / i)*pow(-1,j);
        
    }
    
    arc1 = 16 * arc1 - 4 * arc2;
    printf("Pi is %.10lf", arc1);
    
    return;
}

/********************************************************
 * mid-term 2015 No.13                                  *
 * input a index it would print from index to index - 1 *
 * 10 * 10 matrix                                       *
 ********************************************************/
void MidTerm2015No13 (){
    int j;
    scanf("%d", &j);
    for (int i = 0; i < 10; i++){
        for (int x = 0; x < 10; x++, j++){
            printf("%d", (j + i) % 10);
        }
        printf("\n");
    }
}

/**********************************
 * mid-term 2015 No.14            *
 * Found the specific NAN pattern *
 **********************************/
void MidTerm2015No14(){
    char charCheck1, charCheck2, charCheck3;
    
    printf("please enter your char: ");
    scanf(" %c", &charCheck3);
    
    //input F to exit
    while (charCheck3 != 'F'){
        //find NAN pattern
        if(charCheck1 == 'N' && charCheck2 == 'A' && charCheck3 == 'N'){
            printf("Pattern Found !\n");
        }
        
        //use step up to pup up
        charCheck1 = charCheck2;
        charCheck2 = charCheck3;
        
        printf("please enter your char: ");
        scanf(" %c", &charCheck3);
        
    }
    
    return;
}

