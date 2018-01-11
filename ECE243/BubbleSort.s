#########################################
#	for(int i = size - 1; i > 1; i--){	#
#		for(int j = 0; j < i; j++){		#
#			if(array[j] > array[j+1]){	#
#				int temp = array[j];	#
#				array[j] = array[j+1];	#
#				array[j+1] = temp;		#
#			}							#
#		}								#
#	}									#
#########################################

Input_List:
	.word 7, 2, 5 ,4

.global _start
_start:
	# when there is only 2 in the array finish
    movi r8, 1
    
    # r9 and r10 is the index of i and j
    movi r9, 3
    movi r10, 0
    
    # r11 is the pointer to the Input_List
    # r12 is a temp pointer
    # NOTE: the Input_List is 32-bits
    movia r11, Input_List
    movia r12, Input_List
    
Loopi:
	# if i == size, then finish sort
	beq r9, r8, Finish
    
Loopj:
	# if j == i, then fhinsih netloop go to loop
	beq r10, r9, LoopiIncre
  
   	# take the two value in array[j] and array[j+1]
    ldw r13, 0(r12)
    ldw r14, 4(r12)
    
    # compare if j > j+1 swap, else do nothing
    blt r13, r14, LoopjIncre
    
    # swap
    stw r14, 0(r12)
    stw r13, 4(r12)
    
	
LoopjIncre:
	# j++
    addi r10, r10, 1
    # move r12 to next place
    addi r12, r12, 4
    # go back to Loopj
    beq r0, r0, Loopj
      
LoopiIncre:
	# j = 0
	mov r10, r0
    # i--
    subi r9, r9, 1
    # move to next place add + 4, reset (temp)r12 to (input)r11
    addi r11, r11, 4
    mov r12, r11
    
	beq r0, r0, Loopi

    
Finish:	