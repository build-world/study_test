TITLE ArraySort

.386
.model flat, stdcall
.stack 4096

;Global
.data
arr_src sdword 7d, 9d, 4d, 8d, 0d, 3d, 1d, 6d, 2d, 5d
arr_len = ($ - arr_src) / 4
arr_dest sdword arr_len DUP(?)
RetAddr dword ?
pArr dword ?

.code
MoveData PROC
	pop [RetAddr]
	;bcakup return stack and pop param
	pop ecx
	pop edi
	pop esi
	mov edx, 0d
top:
	mov eax, [esi]
	mov [edi], eax
	add esi, type arr_src
	add edi, type arr_dest
	loop top
	;move finish recover return stack
	push [RetAddr]
	ret
MoveData ENDP

SelectSort PROC
	pop [RetAddr]
	;bcakup return stack and pop param
	pop ecx
	sub ecx, 1d
	;pop [arr_dest]
	mov esi, 0
outer:
	;outer loop condition
	cmp esi, ecx
	jge esc_outer
	;outer loop body start
	mov edx, [arr_dest + esi * type arr_dest]
	mov edi, esi
	add edi, 1d
inner:
	cmp edi, ecx
	jg esc_inner
	;inner loop body start
	cmp [arr_dest + edi * type arr_dest], edx
	jge esc_if1
	mov edx, [arr_dest + edi * type arr_dest]
	mov eax, edi
esc_if1:
	;inner loop body end
	inc edi
	jmp inner
esc_inner:
	;exchange num if found minimum
	cmp edx, [arr_dest + esi * type arr_dest]
	je esc_if2
	;exchange num
	mov edi, eax;eax backup minimum index
	mov eax, [arr_dest + esi * type arr_dest]
	xchg eax, [arr_dest + edi * type arr_dest]
	mov [arr_dest + esi * type arr_dest], eax
esc_if2:
	;outer loop body end
	inc esi
	jmp outer
esc_outer:
	;recover return stack
	push [RetAddr]
	ret
SelectSort ENDP

main PROC
	;movedata
	push offset arr_src
	push offset arr_dest
	push dword ptr arr_len
	call MoveData
	;selectsort
	;push offset arr_dest
	push dword ptr arr_len
	call SelectSort
	nop
main ENDP

END main