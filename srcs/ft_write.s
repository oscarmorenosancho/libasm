; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/08/18 19:03:56 by omoreno-          #+#    #+#              ;
;    Updated: 2024/08/19 20:52:15 by omoreno-         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text                           ; Section to put code
    extern	__errno_location
    global ft_write                       ; A global label to be declared for the linker ( GNU LD )

; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX

; ssize_t	ft_write(int fd, const void *buf, size_t count);
; RDI file descriptor
; RSI buffer pointer
; RDX Length of string
; RAX Result Return
ft_write:
	;push rbp                            ;save rbp on stack
	;mov	rbp, rsp                        ;base point set to stack pointer
	;sub	rsp, 0                      ;reserve 0 bytes to use as local variables,
    mov rax, 1                          ;rax SYS_WRITE System call
                                        ; CC matches whith system call
                                        ; already in place rdi File descriptor
                                        ; already in place rsi Pointer to string
                                        ; already in place rdx Length of the string
    syscall                             ; Call kernal
    cmp		rax, 0
	jl		.ret_error			; if ret < 0 then ret_error()
    ;mov rbp, rsp                        ;discard local variables
    ;pop rbp                             ;recover values of registers to its previous ones
    ret
.ret_error:
    mov         r8, rax            ; save errno
    neg         r8
    call        __errno_location    ; retrieve address to errno
    mov         [rax], r8          ; put errno in return value of __error (pointer to errno)
    mov         rax, -1
    ret
