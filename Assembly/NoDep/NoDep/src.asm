TITLE first with less dep

.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD
; DumpRegs PROTO

szPool = 1024

.code
main PROC
	mov ax, 006ch
	aam
	nop

	mov eax, 0
	mov al, 39h
	add al, 31h
	aaa
	add al, 39h
	aaa
	nop

	add al, ah
	nop

	mov al, 7fh
	inc al
	inc al
	mov eax, 0d
	mov eax, 1b
	mov eax, 11b
	inc eax
	mov eax, 1111b
	mov eax, 0ffffffffh
	add eax, 1d


; movedata
	mov ecx, [len_arr]
	mov edx, 0d
	top:
	mov eax, [arr_src + edx * type arr_src]
	mov [arr_dest + edx * type arr_dest], eax
	inc edx
	loop top
; SelectSort
	mov ecx, [len_arr]
outer:
	mov edx, ecx
inner:

	loop inner
	mov ecx, edx
	loop outer


	mov eax, 0d
	mov eax, pobj
	mov eax, 0d
	mov eax, [pobj]
	mov eax, 0d
	mov eax, [[pobj]]
	mov eax, 0d
	mov edi, offset pobj
	mov esi, [pobj]
	mov ebx, esi
	mov eax, [esi]


	mov esi, offset	arr_src
	mov eax, [esi + 4d]

	mov eax, 0d
	mov al, 127d
	inc al
	add al, 1d
	add al, 1d
	inc al

	mov eax, 0d
	mov al, -128d
	sub al, 1d

	mov eax, 0d
	mov al, -128d
	add al, 0ffh

	mov eax, 1d
	sub eax, 2d

	mov eax, 1d
	add eax, 0fffffffeh

	mov eax, [var1]
	add eax, [var2]
	sub eax, [var3]
	mov [result], eax
	
	LAHF
	mov [flags_bk], AH
	mov ebx, [var4]
	add ebx, 1d
	add ebx, 1d
	mov ecx, [var5]
	add ecx, 1d
	add ecx, 1d
	mov edx, [var6]
	add edx, 1d
	add edx, 1d
	mov edx, [var7]
	add edx, 1d
	add edx, 1d

	mov eax, 1d
	neg eax

	mov ecx, 80000000h
	mov edx, 80000000h
	add ecx, edx
	inc ecx

	;call DumpRegs
	invoke ExitProcess, 0
main ENDP

pdword typedef ptr dword

.data
	obj dword 12345678h
	pobj pdword offset obj
	var1 dword 1d
	var2 dword 3d
	var3 dword 2d
	result dword ?
	str1 byte "Hello World!", 0d
	arr_src dword 7d, 9d, 4d, 8d, 0d, 3d, 1d, 6d, 2d, 5d
	len_arr = ($ - arr_src) / 4
	arr_dest dword len_arr DUP(?)
	flags_bk byte ?
	var4 dword 7fffffffh
	var5 dword 0ffffffffh
	var6 dword 0ffh
	var7 dword 0fh
	var8 byte ?
.data?
	mempool byte szPool DUP(?)

;fin
END main
