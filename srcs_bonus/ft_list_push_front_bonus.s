; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
; RDI destination pointer
; RSI source pointer
; RAX Result Return

global ft_list_push_front                       ; A global label to be declared for the linker ( GNU LD )
global ft_create_elem                       ; A global label to be declared for the linker ( GNU LD )

section .text                           ; Section to put code
ft_create_elem:
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
	
ft_atoi_base:
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