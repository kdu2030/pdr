;Name: Kevin Du
;Date: 11/17/2021
;ID: kd5eyn
;Filename: binarySearch.s

	global binarySearch
	
;rdi - the array pointer
;rsi - left
;rdx - right
;rcx - target
binarySearch:

loop:	

	cmp rsi, rdx	;if low > right, exit loop
	jg exit
	
	mov r8, rsi	;int mid = (left + right)/2  -> r8
	add r8, rdx
	shr r8, 1

	mov r9, [rdi + 4*r8]	;copy a[mid] into r9
	cmp r9d, ecx	; if(a[mid] == target)
	je found
	
	cmp r9d, ecx		;if a[mid] < target
	jl less

	cmp r9d, ecx		;if a[mid] > target
	jg greater

less:
	mov rsi, r8		;left = mid+1
	inc rsi
	jmp loop

greater:
	mov rdx, r8		;right = mid-1
	dec rdx
	jmp loop
	
exit:
	mov rax, -1		;return -1
	ret

found:				;return mid
	mov rax, r8
	ret			
