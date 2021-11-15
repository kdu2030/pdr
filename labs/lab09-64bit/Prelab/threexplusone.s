;Name: Kevin Du
;Date: 11/14/2021
;ID: kd5eyn
;Filename: threexplusone.s

	global threexplusone

;rdi - the number n to follow the conjecture
threexplusone:
	cmp rdi, 1	;if n==1, jump to end		
	je one
	
	xor edx, edx	
	mov eax, edi	;move edi into eax - prepare for integer division
	mov esi, 2	;move the quotient into edi (32 bits of unused parameter register rsi)
	idiv esi	;result in eax, remainder in edx
	cmp edx, 0	
	je even		;jump to even
	
	mov r10, rdi	;copy over rdi into r10 (saving n)
	shl rdi, 1	;3 * n (optimized as 2 * n + n)
	add rdi, r10	;add r10 to rdi (adding n)
	add rdi, 1
	call threexplusone ;threexplusone(3*n + 1)
	inc rax
	ret	  

one:
	mov rax, 0	;return 0
	ret
	
even:
	shr rdi, 1	;shift rsi over to the right one n/2
	call threexplusone	;threexplusone(n/2)
	inc rax		;add 1 to rax
	ret
	
	
