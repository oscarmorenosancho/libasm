; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
; int ft_atoi_base(char *str, char *base)
; RDI source string pointer
; RSI base pointer
; RAX Result Return

section .text                           ; Section to put code
	extern	ft_strlen
	global ft_atoi_base                       ; A global label to be declared for the linker ( GNU LD )


ft_validate_base:

ret

ft_trim_spaces:

ret

ft_get_sign:

ret

ft_atoui_base:

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