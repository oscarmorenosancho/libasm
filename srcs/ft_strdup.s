
; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
; RDI buffer pointer
; RAX Result Return

section .text                           ; Section to put code
	extern	malloc
	extern	ft_strlen
	extern	ft_strcpy
	global ft_strdup                       ; A global label to be declared for the linker ( GNU LD )


ft_strdup:
	push	rdi							;save source str witch came on rdi on stack
	call	ft_strlen
	mov		rdi, rax					;prepare buffer size for malloc with lenght
	inc		rdi							;add 1 byte to store \0
	call	malloc
	pop		rsi							;recover source str from stack to rsi, where its needed for strcpy
	cmp		rax, 0						
	je		.end						;if malloc returned NULL, errno is already set, just go to end
	mov		rdi, rax 					;source is already ready, just prepare destination to copy with malloc ret
	call	ft_strcpy
.end:
    ret

