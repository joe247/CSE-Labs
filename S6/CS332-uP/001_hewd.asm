;https://omkarnathsingh.wordpress.com/2015/11/05/write-assembly-language-program-to-print-hello-world-program/
.model tiny							;defines the memory model to be used for the ALP
.data								;data segment begins here
	msg db "Hello World$"			;String Hello World gets stored in msg # 10df,13df, gives output formating

.code								;code segment begins here
	mov ax, @data					;moving base address of data to ax
	mov ds, ax						;moving contents of ax into ds
									;data section now gets initialized
	lea dx, msg						;load the offset address of msg
	mov ah, 09h						;to display contents at dx
	int 21h							;call the kernel

	mov ah, 4ch						;to terminate the program
	int 21h							;call the kernel
end									;end of program
