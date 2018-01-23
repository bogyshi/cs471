	.file	"gcd.c"
	.text
	.globl	gcdI
	.type	gcdI, @function
gcdI:
.LFB0:
	.cfi_startproc
	pushq	%rbp 1. The creation of the stack frame.
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp 
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp) 2. Argument storage and updates.
	movl	%esi, -8(%rbp)
	jmp	.L2
.L4:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jle	.L3
	movl	-8(%rbp), %eax
	subl	%eax, -4(%rbp)3. Local variable storage and updates.
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	subl	%eax, -8(%rbp)3. Local variable storage and updates.
.L2:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jne	.L4 4. Translation of the loop.
	movl	-4(%rbp), %eax 5. Some form of return result, and an exit from the function.
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret 5. Some form of return result, and an exit from the function.
	.cfi_endproc
.LFE0:
	.size	gcdI, .-gcdI
	.ident	"GCC: (Ubuntu 6.3.0-12ubuntu2) 6.3.0 20170406"
	.section	.note.GNU-stack,"",@progbits
