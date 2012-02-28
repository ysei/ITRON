OUTPUT_FORMAT("coff-h8300")
OUTPUT_ARCH(h8300h)
ENTRY("_startup")
MEMORY
{
	vectors : o = 0x000000,	l = 0x000100
	rom    	: o = 0x000100, l = 0x07ff00
	ram    	: o = 0xffbf20, l = 0x004000
	stack	: o = 0xffff00, l = 0x000000
}
SECTIONS 				
{ 					
.vectors : {
	*(.vectors)
	FILL(0xff)
        }  > vectors
.text  : {
	*(.text) 				
	*(.strings)
	*(.rodata) 				
   	 _etext = . ; 
	} > rom
.tors : {
	___ctors = . ;
	*(.ctors)
	___ctors_end = . ;
	___dtors = . ;
	*(.dtors)
	___dtors_end = . ;
	}  > rom
.data : AT ( ADDR(.tors) + SIZEOF(.tors) ){
	___data = . ;
	*(.data)
	*(.tiny)
	 _edata = .;
	} > ram
	data_size = SIZEOF(.data);
.bss : {
	 _bss_start = . ;
	*(.bss)
	*(COMMON)
	 _end = . ;  
	}  > ram
	bss_size = SIZEOF(.bss);
.stack : {
	 _stack = . ; 
	*(.stack)
	}  > stack
.stab 0 (NOLOAD) : {
	[ .stab ]
	}
.stabstr 0 (NOLOAD) : {
	[ .stabstr ]
	}
}
