; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
; RDI s1 pointer
; RSI s2 pointer
; RAX Result Return

global ft_strcmp                       ; A global label to be declared for the linker ( GNU LD )

section .text                           ; Section to put code
ft_strcmp:
	xor		rax, rax					; set to 0 by xoring with itself
	xor		rdx, rdx					; set to 0 by xoring with itself
	xor		rcx, rcx					; set to 0 by xoring with itself
.loop:
	mov		dl, BYTE [rdi + rax]
	mov		cl, BYTE [rsi + rax]
	xor		r8, r8					; set to 0 by xoring with itself
	mov		r8b, dl
	sub		r8b, cl
	jne		.end
	cmp		dl, 0
	je		.end
	cmp		cl, 0
	je		.end
	inc		rax
	jmp		.loop
.end:
	movsx		rax, r8b
    ret