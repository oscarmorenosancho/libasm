; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
; RDI destination pointer
; RSI source pointer
; RAX Result Return

section .text                           ; Section to put code
	extern malloc
	global ft_list_push_front                       ; A global label to be declared for the linker ( GNU LD )
	global ft_create_elem                       ; A global label to be declared for the linker ( GNU LD )

; RDI	contains pointer to data to store to as content
; RAX	pointer to list node created or NULL if allocation failed
ft_create_elem:
	push	rdi									; save content pointer for later
	mov		rdi, 16								; the size of node is 2 pointers so 16b
	call	malloc
	pop		rdi									; recover content into rdi
	cmp		rax, 0								; if malloc returns NULL
	je		.end								; than allocation failed, so get out
	mov		qword [rax], rdi					; set content of node point to data
	mov		qword [rax + 8], 0					; set pointer next to NULL
.end:
    ret
	
; RDI	contains pointer begin list
; RSI	contains pointer to data to store to as content
; RAX	return not used
ft_list_push_front:
	cmp		rdi, 0								; if begin list is NULL
	je		.end								; just end (can't add to nowhere)
	push	rdi									; save 1st arg o stack
	mov		rdi, rsi							; set content for node creation
	call	ft_create_elem
	cmp		rax, 0
	je		.end								; if node creation failed, just abort
	mov		rdi, [rsp]							; recover list poiter from last stack
	mov		rsi, [rdi]							; dereference 1st node of list, into rsi
	mov		[rax + 8], rsi						; set next to previuos list begin
	mov		[rdi], rax							; point new created element by list begin							
.abort:
	pop		rdi									; recover 1st arg into register
.end:
    ret