; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/08/18 19:03:41 by omoreno-          #+#    #+#              ;
;    Updated: 2024/08/19 20:50:19 by omoreno-         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text                           ; Section to put code
	global ft_strlen                       ; A global label to be declared for the linker ( GNU LD )

; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX

; size_t	ft_strlen(const char *s);
; RDI buffer pointer
; RAX Result Return
ft_strlen:
	xor		rax, rax					; set to 0 by xoring with itself
.loop:
	cmp		BYTE [rdi + rax], 0
	je		.end
	inc		rax
	jmp		.loop
.end:
    ret
