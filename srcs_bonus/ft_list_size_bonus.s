; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
; RDI destination pointer
; RSI source pointer
; RAX Result Return

section .text                           ; Section to put code
	global ft_list_size                       ; A global label to be declared for the linker ( GNU LD )

; int	ft_list_size(t_list *begin_list);
; RDI	contains begin list
; RAX	returns count of elements in list
ft_list_size:
	push	rdi							; save register to recover it later
	xor		rax, rax					; init counter
.loop:
	cmp		rdi, 0						; if current node is NULL, break loop
	je		.break_loop
	mov		rdi, [rdi + 8]				; point current to next node
	inc		rax
	jmp		.loop						; loop to next node
.break_loop:
	pop		rdi							; recover original value of register
    ret