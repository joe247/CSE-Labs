.model small					;defines the memory model to be used for the ALP
.stack						;stack segment begins here

.data						;data segment begins here
	msg1 db "Enter the string > $"		;given string gets stored in msg1
	msg2 db "The string is: $"		;given string gets stored in msg2
	gstr db 100 DUP('$')			;intialize 'gstr' with size 100 & '$'

.code						;code segment begins here
start:
	mov ax, @data				;moving base address of data to ax
	mov ds, ax				;moving contents of ax into ds
						;data section now gets initialized
	lea dx, msg1				;load the offset(or effective) address of msg1
	mov ah, 09h				;to display contents at dx
	int 21h					;call the kernel

	mov ah, 3fh				;to read contents from keyboard
	lea dx, gstr				;load the effective address of gstr <=> mov dx, offset gstr
	int 21h					;call the kernel

	lea dx, msg2				;load the offset(or effective) address of msg2
	mov ah, 09h				;to display contents at dx
	int 21h					;call the kernel

	lea dx, gstr				;load the offset(or effective) address of gstr
	mov ah, 09h				;to display contents at dx
	int 21h					;to display contents at dx

	mov ah,4ch 				;to terminate the program
	int 21h					;call the kernel
end						;end of program
