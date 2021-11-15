	global linearSearch
	
	section .text

linearSearch:
	;First parameter - int[] pointer rdi
	;Second parameter - int length	rsi
	;Third parameter - int target rdx
	
	xor r10, r10		;int i = 0
	push rbx		;push rbx onto stack because need to compare targets	
	
start:
	cmp r10, rsi		;if i == length; jump to end of the loop
	je notFound
	
	mov ebx, [rdi + 4*r10]	;moves a[i] into r11
	cmp ebx, edx		;if a[i] == target - compares last 32 bits
	je found
	
	inc r10			;Increment the counter
	jmp start		;Jump to the start of the loop

found:
	pop rbx			;pop rbx to restore value
	mov rax, r10		;return the index
	ret


notFound:
	pop rbx			;pop rbx to restore value
	mov rax, -1		;return -1
	ret
