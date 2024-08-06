
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
	mov		rdx, rsi
	call	ft_strlen
	mov		rsi, rax
	inc		rsi
	call	malloc
	cmp		rax, 0
	je		.end
	mov		rdi, rax
	mov		rsi, rdx
	call	ft_strcpy
.end:
    ret
