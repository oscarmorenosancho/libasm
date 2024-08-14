; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
; RDI destination pointer
; RSI source pointer
; RAX Result Return

section .text                           ; Section to put code
	extern ft_list_push_node_front
	extern ft_list_pop_front
	extern ft_destroy_elem
	global ft_list_search_pos
	global ft_list_sort                 ; A global label to be declared for the linker ( GNU LD )


;t_list **ft_list_search_pos(t_list **begin_list, void *ref_data, int (*cmp)());
; RDI	contains begin list
; RSI	reference data to compare
; RDX	function pointer to compare node
; RAX	return the first list in list where the front node content is\
			greater then the ref_data according to the comparison funct \
			or NULL if begin_list is NULL
ft_list_search_pos:
	mov		rax, rdi					; init rax with begin_list
	cmp		rax, 0						; if begin list is NULL
	je		.end						
	push	r8
	push	rcx
	push	rdx
	push	rsi
	push	rdi
	push	rbp
	mov		rbp, rsp
	;sub		rsp, 0						;reserve 0 bytes for local variables
.loop:
	mov		rcx, QWORD [rax]				; get first node of list into rcx
	cmp		rcx, 0							; if node is NULL
	je		.break_loop
	mov		rdx, QWORD [rbp + 24]				; recover original value of rdx form the stack (cmp)
	mov		rsi, QWORD [rbp + 16]				; recover original value of rsi form the stack (ref_data)
	mov		rdi, QWORD [rcx]					; obtain data from node to compare
	push	rcx
	push	rax
	call	rdx							; call cmp
	mov		rdi, rax					; move result to rdi
	pop		rax							; recover rax where the cur list is 
	pop		rcx							; recover rcx node
	cmp		di, 0
	jge		.break_loop
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
; local variables saved
; [rsp + 16]	popped node data
; [rsp + 8]		popped node
; [rsp]			termporary destination list
ft_list_sort:
	cmp		rdi, 0					; if begin list is NULL
	je		.end						
	push	rdx
	push	rsi
	push	rdi
	push	rbp
	mov		rbp, rsp
	sub		rsp, 24					; reserve 24 bytes for local variables 
	mov		QWORD [rsp + 8], 0		; init popped node to null
	mov		QWORD [rsp], 0			; init destination with an empty list
.loop:
	; pop from destination list while there is a node
	call	ft_list_pop_front		; rdi already begin list points rest o list
	cmp		rax, 0					; if return by pop 0 no more
	je		.break_loop
	mov		QWORD [rsp + 8], rax	; save popped node on its local var
	mov		rax, [rax]				; derreference node content into rda
	mov		QWORD [rsp + 16], rax	; save popped node content on its local var
	
	; search the list position where has to be inserted the popped node
	mov		rdi, rsp				; top stack is the location of destination list
	mov		rsi, QWORD [rsp + 16]	; recover popped node content from stack
	mov		rdx, QWORD [rbp + 16]   ; recover original rsi from stack (cmp) into rdx
	call	ft_list_search_pos

	; push this node at front of the position list found
	mov		rdi, rax				; list where to insert node 
	mov		rsi, QWORD [rsp + 8]	; recover popped node from stack
	call	ft_list_push_node_front

	jmp		.loop
.break_loop:
	mov		rax, QWORD [rsp]		; save destination sorted list into rax
	mov		QWORD [rdi], rax		; save it as the resut list
	mov		rsp, rbp
	pop		rbp
	pop		rdi
	pop		rsi
	pop		rdx
.end:
    ret