	global product
	global power

	section .data
	one DD 1 ;Declare double word 1 - 32 bits
	
	section .text

product:
	xor rax, rax	;zero out the return register
	xor r10, r10	;zero out the counter i

loopStart:
	;both x and y are integers
	;x is in rdi, y is in rsi
	cmp r10, rsi 	;Sees if r10(i) and rsi(y) have the same value
	je loopEnd 	;If they have the same value, jump to end
	add rax, rdi	;Add rdi to rax
	inc r10   	;Increment r10 register (i++)
	jmp loopStart   ;Jump to the start of the loop always

loopEnd:
	ret		;return value in rax
power:
	cmp rsi, 0	;Is y == 0?
	je zero		;Jump to zero if y == 0
	sub rsi, 1      ;Subtract 1 from y
	call power      ;power(x, y-1)
	mov rsi,rax	;Copy result of power(x, y-1) into rsi (parameter register)
	call product 	;Call product(x, power(x,y-1))
	ret		;Return the result of product(x, power(x,y-1))
	
zero:
	mov rax, 1	;Return 1
	ret

