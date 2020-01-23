.model small							;data segment begins here
.stack									;stack segment begins here

.data									;data segment begins here
	msg1 db "Enter the string > $"		;given string gets stored in msg1
	msg2 db "Reversed string: $"		;given string gets stored in msg2
	gstr db 100 DUP('$')				;intialize 'gstr' with size 100 & '$'
	rstr db 100 DUP('$')				;intialize 'rstr' with size 100 & '$'

.code									;code segment begins here
start:
	mov ax, @data						;moving base address of data to ax
	mov ds, ax							;moving contents of ax into ds
										;data section now gets initialize
	lea dx, msg1						;load the offset(or effective) address of msg1
	mov ah, 09h							;to display contents at dx
	int 21h								;call the kernel

	mov ah, 3fh							;to read contents from keyboard
	lea dx, gstr						;load the offset(or effective) address of gstr
	int 21h								;call the kernel

	mov si, 00h							;initilize si(source index) pointer with 0
	mov di, 00h							;initilize di(destination index) pointer with 0

L1:
	cmp gstr[si], '$'					;compare gstr[si] & '$'
	je L2								;if the above comparison yeilds 'equal' jump to label L2
	inc si								;if 'not equal' increment 'si'
	jmp L1								;then jump to label L1
L2:
	dec si								;decrement 'si'
	mov dl, gstr[si]					;move contents of gstr[si] to dl
	;mov ah, 02h						;to display the contents of dl
	;int 21h							;call the kernal => prints reverse string on the go comment line no 36 & 37
	mov rstr[di], dl					;move contents of dl to rsrt[di] => line no 33 & 34 cannot be combined as of now
	inc di								;increment 'di'
	jnz L2								;then jump to label L2

	lea dx, msg2						;load the offset(or effective) address of msg2
	mov ah, 09h							;to display contents at dx
	int 21h								;call the kernel

	lea dx, rstr						;load the offset(or effective) address of rstr
	mov ah, 09h							;to display contents at dx
	int 21h								;call the kernel

	mov ah,4ch 							;to terminate the program
	int 21h								;call the kernel
end										;end of program
