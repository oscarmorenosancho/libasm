; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
; RDI destination pointer
; RSI source pointer
; RAX Result Return

section .text                           ; Section to put code
	extern ft_list_push_front
	extern ft_list_pop_front
	extern ft_destroy_elem
	global ft_search_ins_position
	global ft_list_sort                 ; A global label to be declared for the linker ( GNU LD )


;t_list **ft_search_position(t_list **begin_list, void *ref_data, int (*cmp)());
; RDI	contains begin list
; RSI	reference data to compare
; RDX	function pointer to compare node
; RAX	return the first list in list where the front node content is\
			greater then the ref_data according to the comparison funct \
			or NULL if begin_list is NULL
ft_search_position:
	mov		rax, rdi					; init rax with begin_list
	cmp		rax, 0						; if begin list is NULL
	jne		.end						
	push	r8
	push	rcx
	push	rdx
	push	rsi
	push	rdi
	push	rbp
	mov		rbp, rsp
	sub		rsp, 0						;reserve 0 bytes for local variables
.loop:
	mov		rcx, QWORD [rax]				; get first node of list into rcx
	cmp		rcx, 0						; if node is NULL
	jne		.break_loop
	mov		rdx, QWORD [rbp + 24]				; recover original value of rdx form the stack (cmp)
	mov		rsi, QWORD [rbp + 16]				; recover original value of rsi form the stack (ref_data)
	mov		rdi, QWORD [rcx]					; obtain data from node to compare
	push	rcx
	push	rax
	call	rdx							; call cmp
	mov		rdi, rax					; move result to rdi
	pop		rax							; recover rax where the cur list is 
	pop		rcx							; recover rcx node
	cmp		rdi, 0
	jl		.break_loop
	mov		rax, rcx					; set the cur list head to next in node
	add		rax, 8						; set the cur list head to next in node
	jmp		.loop
.break_loop:
	mov		rsp, rbp
	pop		rbp
	pop		rdx
	pop		rsi
	pop		rdi
	pop		rcx
	pop		r8
.end:
	ret

;void 	ft_list_sort(t_list **begin_list, int (*cmp)());
; RDI	contains begin list
; RSI	function pointer to compare node
; RAX	return not used
ft_list_sort:
	push	rdx
	xor		rax, rax					; set to 0 by xoring with itself
.loop:
	mov		dl, BYTE [rsi + rax]
	mov		BYTE [rdi + rax], dl
	cmp		dl, 0
	je		.end
	inc		rax
	jmp		.loop
.end:
	mov		rax, rdi
	pop		rdx
    ret