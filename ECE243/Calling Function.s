
List: .word 2, 3, 5, 6    


.global _start
_start:
	# r8 is the array of List
    movia r8, List
    
    # r4, r5 are the argu of function
    ldw r4, 0(r8)
    ldw r5, 4(r8)
    
    # call function
    call add
    # go to finish
	br finish
add:
	# add r2 = r4 + r5
	add r2, r4, r5
    # return
    ret
finish:
	# fetch the number from r2
	mov r9, r2
    # and push in to stack
    stw r9, 0(sp)
    
    