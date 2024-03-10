	.file	"size.c"
	.text
	.globl	_getArraySize
	.def	_getArraySize;	.scl	2;	.type	32;	.endef
_getArraySize:
LFB0:
	.cfi_startproc
	movl	4(%esp), %edx
	cmpl	$-1, (%edx)
	je	L4
	movl	$0, %eax
L3:
	addl	$1, %eax
	cmpl	$-1, (%edx,%eax,4)
	jne	L3
	rep ret
L4:
	movl	$0, %eax
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
