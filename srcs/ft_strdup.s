
; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
; RDI buffer pointer
; RAX Result Return

extern	malloc
extern	ft_strcpy
extern	ft_strlen
global ft_strdup                       ; A global label to be declared for the linker ( GNU LD )

section .text                           ; Section to put code
ft_strdup:
	push	rcx
	mov		rcx, rsi
	call	ft_strlen
	mov		rsi, rax
	inc		rsi
	call	malloc
	cmp		rax, 0
	je		.end
	mov		rdi, rax
	mov		rsi, rcx
	call	ft_strcpy
.end:
	pop		rcx
    ret
