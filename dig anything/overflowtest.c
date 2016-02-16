#include <stdio.h>
main()
{
		short value1;
		__asm
		{
			xor ax, ax
			xor bx, bx
			mov ax, 0x7fff // 32767
			mov bx, 0xffff	// -1
			sub ax, bx // 00008000
			mov value1, ax
		}
			printf("%d", value1);
}