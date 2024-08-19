; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/08/18 19:03:26 by omoreno-          #+#    #+#              ;
;    Updated: 2024/08/19 20:50:37 by omoreno-         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text                           ; Section to put code
	global ft_strcpy                       ; A global label to be declared for the linker ( GNU LD )

; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX

; char 	*ft_strcpy(char *dest, const char *src);
; RDI destination pointer
; RSI source pointer
; RAX Result Return
ft_strcpy:
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
