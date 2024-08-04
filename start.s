section .data                           ; Section to define Memory
    message db "Hello World !", 10      ; Define string to the name "message" and 10 is new line ascii code ( db = Define Bytes )
    message_length equ $ - message      ; Assign the length of the string to the name "message_length"

section .text                           ; Section to put code
    global _start                       ; A global label to be declared for the linker ( GNU LD )
	extern ft_write

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
