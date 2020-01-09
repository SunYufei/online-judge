
# skeleton program for fib

    .text
    .global fib
fib:
	# n in a0, m in a1
	# return value in a0
	
	li a2,1	#const
	li a3,1 #a
	li a4,1 #b
	li a5,3 #i
	li a6,2 #const
	
	bgt a0,a6,loop

end:
	rem a0,a4,a1
	ret

loop:
	add a4,a3,a4
	sub a3,a4,a3
	add a5,a5,a2
	ble a5,a0,loop

	j end
