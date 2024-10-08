; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/08/19 19:57:33 by omoreno-          #+#    #+#              ;
;    Updated: 2024/08/19 20:46:51 by omoreno-         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text                           ; Section to put code
	global ft_strcmp                       ; A global label to be declared for the linker ( GNU LD )

; int		ft_strcmp(const char *s1, const char *s2);
; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
; RDI s1 pointer
; RSI s2 pointer
; RAX Result Return
ft_strcmp:
	xor		rax, rax					; set to 0 by xoring with itself
.loop:
	mov		dl, BYTE [rdi + rax]
	mov		cl, BYTE [rsi + rax]
	cmp		dl, cl
	jne		.end
	cmp		dl, 0
	je		.end
	cmp		cl, 0
	je		.end
	inc		rax
	jmp		.loop
.end:
	xor		rdx, rdx					; set to 0 by xoring with itself
	xor		rcx, rcx					; set to 0 by xoring with itself
	mov		dl, BYTE [rdi + rax]
	mov		cl, BYTE [rsi + rax]
	sub		rdx, rcx
	mov		rax, rdx
    ret
