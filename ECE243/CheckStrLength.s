#########################
#	length = 0;			#
#						#
#	while (*s != 0){	#
#	  length++;			#
#	  s++;				#
#	}					#
#########################
String:
	.word 1, 3, 5, 6, 8, 0
.global _start
_start:
	# r8 = *s
    movi r8, String
    
    # r9 = length
    mov r9, r0
CheckLength:
	# r10 is the temperary word space
    ldw r10, 0(r8)
    
	beq r10, r0, Done
    
    addi r8, r8, 4
    addi r9, r9, 1
    br CheckLength
Done: