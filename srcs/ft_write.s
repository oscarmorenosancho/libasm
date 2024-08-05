extern	__errno_location
global ft_write                       ; A global label to be declared for the linker ( GNU LD )

section .text                           ; Section to put code
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
    jc          .ret_error                   ; error sets carry flag, rax = errno
.back:
    ;mov rbp, rsp                        ;discard local variables
    ;pop rbp                             ;recover values of registers to its previous ones
    ret
.ret_error:
    mov         r8, rax            ; save errno
    neg         r8
    call        __errno_location    ; retrieve address to errno
    mov         [rax], r8          ; put errno in return value of __error (pointer to errno)
    mov         rax, -1
    jmp         .back
