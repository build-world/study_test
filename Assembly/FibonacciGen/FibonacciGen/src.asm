title FibonacciGen

.386
.model flat, stdcall
.stack 4096

szArray = 100

.code
main proc
	mov ecx, lengthof arr
	
	mov eax, 0d
	mov ebx, 1d
	mov edi, offset arr
	mov [edi], eax
	add edi, type arr
	mov [edi], ebx
start:
	add edi, type arr
	mov edx, eax
	add edx, ebx
	mov [edi], edx
	mov eax, ebx
	mov ebx, edx
	loop start
	nop
main endp

.data


.data?
arr dword szArray dup(?)

end main