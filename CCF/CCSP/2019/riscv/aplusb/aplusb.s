
# example program for aplusb

    .text
    .global aplusb
aplusb:
	# a in a0, b in a1
	# return value in a0
	add a0, a0, a1
	ret
