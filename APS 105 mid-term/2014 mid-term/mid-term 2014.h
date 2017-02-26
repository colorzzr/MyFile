/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mid-term 2014 structure question.h
 * Author: user
 *
 * Created on February 24, 2017, 5:49 PM
 */

#ifndef MID_TERM_2014_STRUCTURE_QUESTION_H
#define MID_TERM_2014_STRUCTURE_QUESTION_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* MID_TERM_2014_STRUCTURE_QUESTION_H */

/*****************************************
 * mid-term 2014 No.10                   *
 * calculate the tax for personal income *
 *****************************************/
void MidTerm2014No10() {
    int income;
    printf("plz enter your income:");
    scanf("%d", &income);
    
    //check for 4 levels
    //Level1
    if (income < 43561)
        printf("tax is %.2lf", income * 0.15);
    
    //level2
    if (income < 87123 && income >= 43561)
        printf("tax is %.2lf", (income - 43561) * 0.22 + 6534.15);
    
    //level3
    if (income < 135054 && income >= 87123)
        printf("tax is %.2lf", (income - 87123) * 0.26 + 16118.79);
    
    //level4
    if (income >= 135054)
        printf("tax is %.2lf", (income - 135054) * 0.29 + 28580.85);
    
    return;
}

/***********************************
 * mid-term 2014 No.11             *
 * not use % to calculate reminder *
 ***********************************/
void MidTerm2014No11(){
    int firstNum, secondNum, count = 0;
    
    //ask user to input divided and divider
    printf("please enter your tow number: ");
    scanf("%d %d", &firstNum, &secondNum);
    
    //if one of number is below 0 then exit
    while ((firstNum > 0) && (secondNum > 0)){
 
        //not use the % to get reminder using loop to minus secondNum
        while ((firstNum - secondNum) > 0){
            firstNum = firstNum - secondNum;
            count++;
        }
        printf("%d %% %d = %d\n", firstNum + secondNum * count, secondNum, firstNum);
        
        //goback to loop
        printf("please enter your tow number: ");
        scanf("%d %d", &firstNum, &secondNum);
    }
    
    
    printf("Goodbye");
    return;
}

/***************************************************
 * mid-term 2014 No.12                             *
 * rearrange 3 input letters to alphabetical order *
 ***************************************************/
void MidTerm2014No12 () {
     /*************************************************
     * ------------!!! Color Warning !!!------------ *
     * string is same as array because character is  *
     * not same as integer (5 6 != 56  but A B == AB *
     * so scanf("%c%c%c") works for char             *
     * so as prinft ("%s") or for loop [i]           *
     *************************************************/
    char inputChar[3], a, b, c;
    int i = 0;
    char temp;
    
    //ask for 3 letter and store it as a string
    printf("please enter 3 letters: ");
    scanf("%s", &inputChar);
    
    //use bubble sort to filter the largest
    for (i = 2; i > 0; i --){
        for (int j = 0; j < i; j++){
            if (inputChar[j] > inputChar[j + 1]){
                temp = inputChar[j];
                inputChar[j] = inputChar[j + 1];
                inputChar[j + 1]= temp;
            }
        }
    }
    
    
    printf("%s", inputChar);
    
    return;
}

/****************************************************************
 * mid-term 2014 No.13                                          *
 * this function would use m1 and m2 to sum up and product      *
 * together the factors below max to get total sum and product  *
 * such as input 3 5 max: 10                                    *
 * factor would be 3 5 6 9 and sum is 23 product is 810         *
 ****************************************************************/
void MidTerm2014No13 (int multiple1, int multiple2, int max, int *sumPtr, int *productPtr){
    int count = 0;
    
    /*************************************************
    * Please think clearly before using / and % !!! *
    *************************************************/
    //check whether it is divided
    if ((max % multiple1) != 0){
        count = (max / multiple1) + 1;
    }
    else{
        count = (max / multiple1);
    }
    
    //get the sum and product for first one
    for (int i = 1; i < count; i++){
        *sumPtr = *sumPtr + multiple1 * i;
        *productPtr = *productPtr * multiple1 * i;
        printf("%d %d %d\n", *sumPtr, *productPtr, max);
    }
    
    //check whether it is divided
    if ((max % multiple2) != 0){
        count = (max / multiple2) + 1;
    }
    else{
        count = (max / multiple2);
    }
    
    //get product and sum for second one
    for (int i = 1; i < count; i++){
        *sumPtr = *sumPtr + multiple2 * i;
        *productPtr = *productPtr * multiple2 * i;
    }
    
    return;
}

