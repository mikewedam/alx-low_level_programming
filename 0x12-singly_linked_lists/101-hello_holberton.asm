section .data
	format db `Hello, Holberton\n`, 0

section .text
global main
extern printf

main:
	; Prepare arguments for printf
	mov rdi, format
	xor rax, rax

	; Call printf
	call printf

	; Return 0 from main
	mov rax, 0
	ret
