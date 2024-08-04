; The approximate program is as follows
;
; start() {
;     print("Hello World !\n");
;     exit(0);
; }
; The first six integer or pointer arguments are passed in registers RDI, RSI, RDX, RCX, R8, and R9
; Floating-point arguments are passed in XMM0 through XMM7

section .data                           ; Section to define Memory
    message db "Hello World !", 10      ; Define string to the name "message" and 10 is new line ascii code ( db = Define Bytes )
    message_length equ $ - message      ; Assign the length of the string to the name "message_length"

section .text                           ; Section to put code
    global _start                       ; A global label to be declared for the linker ( GNU LD )

ft_write:
    push rax                            ;save previous values of resisters used in system call
	push rbp                            ;save rbp on stack
	mov	rbp, rsp                        ;base point set to stack pointer
	;sub	rsp, 0                      ;reserve 0 bytes to use as local variables,
    mov rax, 1                          ;rax SYS_WRITE System call
                                        ; CC matches whith system call
                                        ; already in place rdi File descriptor
                                        ; already in place rsi Pointer to string
                                        ; already in place rdx Length of the string
    syscall                             ; Call kernal
    mov rbp, rsp                        ;discard local variables
    pop rbp                             ;recover values of registers to its previous ones
    pop rax
    ret

_start:                                 ; Main global label ( Linker entry point )
    mov edi, 1                          ; STDOUT File descriptor, CC first arg on rdi
    mov esi, message                    ; Address of the string to write, CC 2nd arg on rsi
    mov edx, message_length             ; Length of the string, CC 3rd on rdx
    call    ft_write 
    call    _exit                       ; Call "_exit" label

_exit:                                  ; "_exit" label
    mov rax, 60                         ; SYS_EXIT System call
    mov rdi, 0                          ; Error code "0"
    syscall