; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
; RDI buffer pointer
; RAX Result Return

section .text                           ; Section to put code
	global ft_strlen                       ; A global label to be declared for the linker ( GNU LD )

ft_strlen:
	xor		rax, rax					; set to 0 by xoring with itself
.loop:
	cmp		BYTE [rdi + rax], 0
	je		.end
	inc		rax
	jmp		.loop
.end:
    ret
