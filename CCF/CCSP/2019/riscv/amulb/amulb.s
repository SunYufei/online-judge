# skeleton program for amulb

    .text
    .global amulb
amulb:
	# a in a0, b in a1
	# return value in a0
	mul a0,a0,a1
	ret
