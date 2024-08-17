; Call convention arguments RDI, RSI, RDX, RCX, R8 y R9
; Return on RAX
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


;In the C locale, the complete list of whitespace characters is:
;‘ ’ Space character. 	32
;\f Form feed.			9 - 13
;\n New-line.
;\r Carriage return.
;\t Horizontal tab.
;\v And vertical tab.
; int		ft_isspace(char c);
;RDI	char to check
;RAX	return != 0 if is a character considered space
ft_isspace:
	push	rdi			;save rdi to recover its value later
	xor		rax,rax		;by default marck is not a space
	cmp		dil, ' '	;if is not a space ' '
	je		.is_space	;so end to return
	cmp		dil, 9		;less than 9
	jl		.end		;is not space
	cmp		dil, 13		;greate than 13
	jg		.end		;is not space
.is_space:
	inc		rax			;else mark is a space
.end:
	pop		rdi			;recover rdi original value
	ret

; size_t	ft_count_char(const char *str, char c);
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

; ssize_t	ft_get_index(const char *str, char c);
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

; int	ft_validate_base(const char *base);
; RDI	string to scan
; RAX	return !=0 when valid
ft_validate_base:
	push	rdi							; save register to restablish its value
	push	rsi							; save register to restablish its value
	cmp		rdi, 0						; if base is NULL
	je		.invalid					; go to invalid and leave
	call	ft_strlen
	cmp		rax, 2						; if length less than 2
	jl		.invalid					; go to invalid and leave
	; while the first char in string is not repeated and neither + - or isspace
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

; char	*ft_trim_spaces(const char *str);
; RDI	string to trim
; RAX	string trimmed
ft_trim_spaces:
	push	rdi				; save original string to recover later
	cmp		rdi, 0
	je		.break_loop		; if input string is NULL break loop
.loop:
	push	rdi				; save pointer to recover after call
	mov		dil, byte [rdi] ; pass the current char pointed as 1st arg
	call	ft_isspace
	pop		rdi				; recover pointer after call
	cmp		rax, 0
	je		.break_loop		; if cur char is not space (including \0) break loop
	inc		rdi				; next char
	jmp		.loop			;	and loop
.break_loop:
	mov		rax, rdi		; cur char is now the start of string
	pop		rdi				; recover input string to its original value
	ret

; int		ft_get_sign(char **str);
; RDI	pointer to string to get sign, and pointer where there are no more signs
; RAX	return sign value (1 if positive, -1 if negative)
ft_get_sign:
	cmp		rdi, 0
	je		.null_input					; if input pointer is NULL break loop
	push	rdx							; save register to restablish its value
	push	rdi
	xor		rax, rax					; counter of - init to 0
	mov		rdi, [rdi]					;dereference pointer to string to string
	cmp		rdi, 0
	je		.break_loop					; if input string is NULL break loop
.loop:
	mov		dl, [rdi]
	cmp		dl, '-'						; if cur value is - update count
	je		.update_count				; update count and continue loop
	mov		dl, [rdi]
	cmp		dl, '+'						; if cur value is + update count
	je		.continue_loop				; just continue loop
	jmp		.break_loop					; otherwise no more signs, break loop
.update_count:
	inc		rax
.continue_loop:
	inc		rdi
	jmp		.loop
.break_loop:
	and		rax, 0x1					; mask the last bit that says if result is even or odd
	neg		rax							; negate to turn odd (1) to negative (-1), if even (0) no change
	jnz		.end 						; after negate, if no flag zero rax is already -1, so go to end
	inc		rax							; otherwise result is positive, so just increment to change 0 to 1
.end:
	pop		rdx							; recover original rdi into rdx
	mov		[rdx], rdi					; save pointer to string to reference pointer
	pop		rdx
	ret
.null_input:
	mov		rax, 1
	ret

; long	ft_atoui_base(char *str, char *base);	
; RDI	string to convert
; RSI	string to base string
; RAX	resulting unsigner int value
ft_atoui_base:
	push	r8				; save register in stack to recover later
	push	rbx				; save register in stack to recover later
	push	rcx				; save register in stack to recover later
	push	rdx				; save register in stack to recover later
	push	rsi				; save register in stack to recover later
	push	rdi				; save register in stack to recover later
	mov		r8, rdi			; use r8 to iterate pointer instead of rdi since needs to use as arg for call
	mov		rbx, 0			; use rbx to acumulate result
	mov		rdi, rsi		; pass base to 1st arg
	call	ft_strlen		; the lenghh of base is the actual length
	mov		rcx, rax		; use rcx to keep the base number
.loop:
	mov		dl, byte [r8]	; get string character into rdx lower byte
	cmp		dl, 0
	je		.break_loop		; if cur char is \0, break loop
	mov		rdi, [rsp+8]	; pass base whitch is stored on stack as 2nd last to 1st arg
	mov		sil, byte [r8]  ; get string character into 2nd arg
	call	ft_get_index
	cmp		rax ,-1			; if char not found in base
	je		.break_loop		; parsing is finished
	mov		rsi, rax		; save rax in rsi temporally
	mov		rax, rbx		; preset the rax to first multiplier
	mul		rcx				; shift a digit to left by mult by base
	mov		rbx, rax		; put mult result back from rax into rbx
	add		rbx, rsi		; acumulate cur digit
	inc		r8
	jmp		.loop
.break_loop:
	mov		rax, rbx		; coopy acummulator register to result
	pop		rdi				; recover register from stack
	pop		rsi				; recover register from stack
	pop		rdx				; recover register from stack
	pop		rcx				; recover register from stack
	pop		rbx				; recover register from stack
	pop		r8				; recover register from stack
	ret

; int		ft_atoi_base(char *str, char *base);
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

	;pop		rdi			; get into rdi from stack, what was pushed after trim_space, as 1st arg
	mov		rdi, rsp		; last potition of stack contains pointer to the string
	call	ft_get_sign		; returns where rdi points of the rest of string to parse
	mov		rdi, [rsp]		; after call dereference rsp, witch contains remain str, into rdi
	push	rax				; save in stack return from get_sign to use it later
	call	ft_atoui_base   ; rdi remains being base string
	pop		rdi				; get into rdi from stack, return of get_sign pushed
	pop		rsi				; purge stack where the string remain position is into rsi no longer needed
	cmp		rdi, -1			; if sign is not -1
	jne		.end			; leave reault as is
	neg		rax				; negate 32bits result since sign is negative
.end:
	and		rax,0xFFFFFFFF	; take 32 bits
	pop		rdi				; recover input string to its original value
	pop		rsi				; recover input base string to its original value
    ret