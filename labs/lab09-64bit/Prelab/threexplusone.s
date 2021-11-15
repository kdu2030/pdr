;Name: Kevin Du
;Date: 11/14/2021
;ID: kd5eyn
;Filename: threexplusone.s

	global threexplusone

;rsi - the number n to follow the conjecture
threexplusone:
	cmp rsi, 1	;if n==1, jump to end		
	je one
	
	mov eax, esi	;move esi into eax - prepare for integer division
	mov edi, 2	;move the quotient into edi (32 bits of unused parameter register rdi)
	idiv edi	;result in eax, remainder in edx
	cmp edx, 0	
	je even		;jump to even
	
	shl rsi, 1	;3 * n (optimized as 2 * n + n)
	add rsi, rsi	;
	add rsi, 1
	call threexplusone ;threexplusone(3*n + 1)
	inc rax
	ret	  

one:
	mov rax, 0	;return 0
	ret
	
even:
	shr rsi, 1	;shift rsi over to the right one n/2
	call threexplusone	;threexplusone(n/2)
	inc rax		;add 1 to rax
	ret
	
	
