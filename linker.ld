ENTRY (start) /* kernel entrance point function; start in boot.S */

SECTIONS
{
    . = 0x00100000;

    .text :
    {
        *(.text)
        *(.rodata)
    }

    .bss :
    {
        *(.bss)
    }
    /DISCARD/ :
    {
        *(.comment)
        *(.symtab)
        *(.strtab)
    }

}
