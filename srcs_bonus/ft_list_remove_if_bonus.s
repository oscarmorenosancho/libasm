; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
; RDI destination pointer
; RSI source pointer
; RAX Result Return


section .text                           ; Section to put code
	extern free
	global ft_destroy_elem
	global ft_list_pop_front
	global ft_list_remove_front
	global ft_list_remove_if                       ; A global label to be declared for the linker ( GNU LD )

; void	ft_destroy_elem(t_list *node, void (*free_fct)(void *));
; RDI	contains pointer to node to destroy
; RSI	function pointer to free content
; RAX	return not used
ft_destroy_elem:
	cmp		rdi, 0						; if node is NULL
	je		.end						; just end (can't do anything to nothing)
	cmp		rsi, 0						; if free_fct is NULL
	je		.content_freed				; there no way to free the content
	cmp		qword [rdi], 0				; if content of node is null
	je		.content_freed				; content already freed
	push	rdi							; save register for later
	mov		rdi, qword [rdi]			; take content of node to pass to free_fct
	call	rsi							; call free_fct whitch is in rsi
	pop		rdi							; recover original value of rdi witch points to node
.content_freed:
	call	free						; free node
.end:
	ret

;t_list	*ft_list_pop_front(t_list **begin_list);
;RDI	contains pointer begin list
;RAX	return popped node
ft_list_pop_front:
	push	rsi							; save register to recover it
	xor		rax, rax
	cmp		rdi, 0						; if begin list is NULL
	je		.end						; just end (can't do anything to nowhere)
	cmp		qword [rdi], 0				; if begin list is empty
	je		.end						; just end (can't do anything to nowhere)
	mov		rax, qword [rdi]					; get first node of list into rax
	cmp		rax, 0						; if first node doesn't exist 
	je		.end						; nothing more to do just leave
	mov		rsi, qword [rax + 8]		; get next pointer of first node
	mov		qword [rdi], rsi			; set begin list to next node
.end:
	pop		rsi							; recover register to its original value
	ret

;void	ft_list_remove_front(t_list **begin_list, void (*free_fct)(void *));
;RDI	contains pointer begin list
;RSI	function pointer to free content
;RAX	return not used
ft_list_remove_front:
	cmp		rdi, 0						; if begin list is NULL
	je		.end						; just end (can't do anything to nowhere);
	push	rsi
	push	rdi
	call	ft_list_pop_front			; pop front node of list;
	cmp		rax, 0
	je		.nothing_popped
	mov		rdi, rax					; set node to destroy as 1st arg, 2nd arg already in place
	call	ft_destroy_elem				; destroy element popped
.nothing_popped:
	pop		rdi
	pop		rsi
.end:
	ret

;void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
;							void (*free_fct)(void *));
;(*cmp)(list_ptr->data, data_ref);
;(*free_fct)(list_ptr->data);
;RDI	contains pointer begin list
;RSI	data reference to compare
;RDX	function pointer to compare node
;RCX	function pointer to free content
;RAX	return not used
ft_list_remove_if:
	cmp		rdi, 0						; if begin list is NULL
	je		.end						; just end (can't do anything to nowhere);
	cmp		rdx, 0						; if can't compare don't know what to do
	je		.end						; just end (can't do enything to nowhere)
	push	r8							; save register to recover it later
	push	rdx							; save register to recover it later
	push	rcx							; save register to recover it later
	push	rdi							; save register to recover it later
	mov		r8, [rdi]					; dereference pointer to begin node
	cmp		r8, 0						; if node doesn't exist, nothing else to do
	je		.nothing_else
	mov		rdi, r8						; else place next pointer pointer to rdi
	add		rdi, 8						; .next is up 8 bytes from node start
	call	ft_list_remove_if			; and recurse the list pointed by next
	mov		rdi, [r8]					; 1st arg is node content
	mov		rdx, [rsp + 16]				; recover original value of rdx from stack to rdx
	call	rdx							; call cmp to see if this node must be removed
	cmp		rax, 0						; if cmp doesn't give 0
	jne		.nothing_else				; no need to remove node
	mov		rdi, [rsp]					; recover original value of rdi from stack
	mov		rsi, [rsp + 8]				; recover original value of rcx from stack to rsi
	call	ft_list_remove_front
.nothing_else:
	pop		rdi							; recover original value of register
	pop		rcx							; recover original value of register
	pop		rdx							; recover original value of register
	pop		r8							; recover original value of register
.end:
    ret
