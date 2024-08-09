; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
; int ft_atoi_base(char *str, char *base)
; RDI source string pointer
; RSI base pointer
; RAX Result Return

section .text                           ; Section to put code
	extern	ft_strlen
	global ft_isspace
	global ft_count_char
	global ft_get_index
	global ft_validate_base
	global ft_trim_spaces
	global ft_get_sign
	global ft_atoui_base	
	global ft_atoi_base

;RDI	char to check
;RAX	return != 0 if is a character considered space
ft_isspace:
	push	rdi			;save rdi to recover its value later
	xor		rax,rax		;by default marck is not a space
	mov		dil, [rdi]  ;get byte
	cmp		dil, 0		;if equals 0 not a space
	je		.end		;so end to return
	cmp		dil, ' '	;if greater or equal ' ' is not a space
	jge		.end		;so end to return
	inc		rax			;else mark is a space
.end:
	pop		rdi			;recover rdi original value
	ret

; RDI	string to scan
; RSI	char to query
; RAX	return count of repetitions
ft_count_char:
	push	rdx							; save register to restablish its value
	push	rdi							; save input string to recover later
	xor		rax, rax
.loop:
	mov		dl, [rdi]
	cmp		dl, sil						; if cur char is not the queried
	jne		.skipinc					; skip the score inc
	inc		rax							; else score count
.skipinc:
	cmp		dl, 0						; if cur char \0 break loop
	je		.break_loop
	inc		rdi							; else next char
	jmp		.loop						;	and loop
.break_loop:	
	pop		rdi
	pop		rdx
	ret

; RDI	string to scan
; RSI	char to query
; RAX	return index position if found, else -1
ft_get_index:
	push	rdx							; save register to restablish its value
	push	rdi							; save input string to recover later
.loop:
	mov		dl, [rdi]
	cmp		dl, 0						; if cur char \0 break loop
	je		.not_found					; reached the end without finding it
	cmp		dl, sil						; if cur char is the queried
	je		.found						; found it
	inc		rdi							; else next char
	jmp		.loop						;	and loop
.found:
	mov		rax, rdi					; save position in rax
	pop		rdi							; recover original rdi value
	sub		rax, rdi					; evaluate index position (located pointer - starting pointer)
	pop		rdx							; recover original rdx value
	ret
.not_found:
	pop		rdi							; recover original rdi value
	mov		rax, -1						; set return, not found mark
	pop		rdx							; recover original rdx value
	ret

; RDI	string to scan
; RAX	return !=0 when valid
ft_validate_base:
	push	rdi							; save register to restablish its value
	push	rsi							; save register to restablish its value
	; while the first char in string is not repeated and neither + - or isspace
	call	ft_strlen
	cmp		rax, 2
	jle		.invalid					; go to invalid and leave
.loop:									; loop through all char to see if it's repeated later
	mov		sil, BYTE [rdi]				; take content of current position in rsi with is 2nd arg
	cmp		sil, 0						; if current value is \0 we finish the traverse of base
	je		.valid						; then break the loop to valid
	cmp		sil, '+'					; if current value is + we now is not valid, get out
	je		.invalid					; then break the loop to valid
	cmp		sil, '-'					; if current value is - we now is not valid, get out
	je		.invalid					; then break the loop to valid
	push	rdi							; save rdi recover value after isspace
	mov		rdi, rsi					; 1st arg in isspace needs current char
	call	ft_isspace
	pop		rdi							; recover rdi after call
	cmp		rax, 0						; if isspace, them rax != 0
	jne		.invalid					; then go to invalid and leave
	inc		rdi							; point rdi to the next position
	call	ft_get_index
	cmp		rax, -1						; if found it again on rest of string then is repeated
	jne		.invalid					; go to invalid and leave
	jmp		.loop						; continue loop
.valid:
	mov		rax, 1
	jmp		.end
.invalid:
	xor		rax, rax
.end:
	pop		rsi							; recover original register value
	pop		rdi							; recover original register value
	ret

; RDI	string to trim
; RAX	string trimmed
ft_trim_spaces:
	push	rdi				; save original string to recover later
.loop:
	call	ft_isspace
	cmp		rax, 0
	je		.break_loop		; if cur char is not space (including \0) break loop
	inc		rdi				; next char
	jmp		.loop			;	and loop
.break_loop:
	mov		rax, rdi		; cur char is now the start of string
	pop		rdi				; recover input string to its original value
	ret

; RDI	pointer to string to get sign, and pointer where there are no more signs
; RAX	return sign value (1 if positive, -1 if negative)
ft_get_sign:
	push	rdx							; save register to restablish its value
	push	rdi
	xor		rax, rax
.loop:
	mov		dl, [rdi]
	cmp		dl, '+'

	inc		rdi
	jmp		.loop
.break_loop:
	pop		rdi
	pop		rdx
	ret

; RDI	string to convert
; RSI	string to base string
; RAX	resulting unsigner int value
ft_atoui_base:
	push	rsi				; save register in stack to recover later
	push	rdi				; save register in stack to recover later



	pop		rdi				; recover register from stack
	pop		rsi				; recover register from stack
	ret


; RDI	string to convert
; RSI	string to base string
; RAX	resulting int value
ft_atoi_base:
	push	rsi				; save input base string to recover later
	push	rdi				; save input string to recover later
	call	ft_trim_spaces
	push	rax				; save in stack result of trimming to use later
	mov		rdi, rsi		; pass base string to validate as 1st arg
	call	ft_validate_base
	cmp		rax, 0
	je		.end			; if base not valid keep 0 in rax witch is the value to return as a result
	pop		rdi				; get into rdi from stack, what was pushed after trim_space, as 1st arg
	call	ft_get_sign		; returns in rdi the rest of string to parse
	push	rax				; save in stack return from get_sign to use it later
	call	ft_atoui_base   ; rdi remains being base string
	pop		rdi				; get into rdi from stack, what was pushed after get_sign that is sign
	cmp		rdi, -1			; if sign is not -1
	jne		.end			; leave reault as is
	neg		rax				; else negate result since sign is negative
.end:
	pop		rdi				; recover input string to its original value
	pop		rsi				; recover input base string to its original value
    ret