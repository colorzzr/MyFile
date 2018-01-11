Input_List:
	.word 1
    .word 2
    .word 5
    .word 4
	.word 3
.global _start
_start:

	movia r11, Input_List
    
    # r7 is current add
    mov r7, r11
    
    # r6 is total number in list
    movia r6, 5
	
    # r8 is max
    ldw r8, 0(r11)
loop:    
	# check if it is finished
	beq r9, r6, after

    # increament r7 by 4
    addi r7, r7, 4
    
    # r9 is temp
    ldw r9, 0(r7)
    
    #####################################################
    # if current number(r9) is greater then max(r8) 	#
    # then overwrite r8, else do nothing				#
    #####################################################
    blt r8, r9, then
    
    # go back to loop
    beq r0, r0, loop
then:
	mov r8, r9
    beq r0, r0, loop
after: