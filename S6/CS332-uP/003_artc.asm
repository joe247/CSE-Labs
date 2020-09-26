;An assembly program to do arithmetic operations
disp_str macro msg							;print a string
	lea dx, msg
	mov ah, 09h
	int 21h
endm

input macro								;move values to ax & bx for execution
	call clear_reg
	mov ax, num1
	mov bx, num2
endm

output macro msg, num						;display numerical values
	disp_str msg
	mov ax, num
	call write
endm

.model small
.stack
.data
	msg1 db 0Ah,0Dh, "Enter the first number > $"
	msg2 db 0Ah,0Dh, "Enter the second number > $"
	msum db 0Ah,0Dh, "Sum = $"
	mdif db 0Ah,0Dh, "Difference = $"
	mprd db 0Ah,0Dh, "Product = $"
	mquo db 0Ah,0Dh, "Quotient = $"
	mrem db 0Ah,0Dh, "Remainder = $"

	num1 dw ?
	num2 dw ?
	temp dw 0
	rslt dw 0

.code
	mov ax, @data
	mov ds, ax
	main proc
		disp_str msg1
		call read
		mov num1, ax

		disp_str msg2
		call read
		mov num2, ax

		input
		add ax, bx
		mov rslt, ax
		output msum, rslt

		input
		sub ax, bx
		mov rslt, ax
		output mdif, rslt

		input
		mul bx
		mov rslt, ax
		output mprd, rslt

		input
		div bx
		mov rslt, ax
		mov temp, dx
		output mquo, rslt
		output mrem, temp

		mov ah, 4Ch
		int 21h
	main endp

	read proc
		mov ax, 00h
		mov cx, 04h
	L1:
		mov dl, 0Ah
		mul dx
		mov temp, ax
		mov ah, 01h
		int 21h
		sub al, 30h
		mov ah, 00h
		mov bx, temp
		add ax, bx
		loop L1
		ret
	read endp

	write proc
		mov bx, 0Ah
		mov cx, 00h
	L2:
		mov dx, 00h
		inc cx
		div bx
		push dx
		cmp ax, 00h
		jne L2
	L3:
		pop dx
		add dl, 30h
		mov ah, 02h
		int 21h
		loop L3
		ret
	write endp

	clear_reg proc						;clears all the registers
		xor ax, ax
		xor bx, bx
		xor cx, cx
		xor dx, dx
		ret
	clear_reg endp
end
