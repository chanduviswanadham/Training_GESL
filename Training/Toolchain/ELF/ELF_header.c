#include "ELF_declarations.h"

int header(struct ELF *ptr)
{
	int i = 0;
	int j = 0;
	FILE *fp = NULL;
	FILE *strfp = NULL;
	struct section *s_hdr = NULL; 
	char *buf = NULL; 

	printf("\nMagic:");
	for (i = 0; i < MAX; i++) {
		printf(" %.2x", ptr -> ident[i]);
	}
	
	printf("\nclass:\t\t\t\t\t");
	if (ptr -> ident[CLASS] == ELFCLASSNONE) {	
		printf("class is invalid");
	} else if (ptr -> ident[CLASS] == ELFCLASS32) {	
		printf("ELF32");
	} else if (ptr -> ident[CLASS] == ELFCLASS64) {	
		printf("ELF64");
	}
	
	printf("\nData:\t\t\t\t\t");
	if (ptr -> ident[DATA] == ELFDATANONE) {	
		printf("unknown dataformat");
	} else if (ptr -> ident[DATA] == ELFDATA2LSB) {	
		printf("2's complement, little -endian");
	} else if (ptr -> ident[CLASS] == ELFDATA2MSB) {	
		printf("2'S compliment, big-endian");
	}

	printf("\nVersion:\t\t\t\t");
	if (ptr -> ident[VERSION] == EV_NONE) {	
		printf("invalid version");
	} else if (ptr -> ident[VERSION] == EV_CURRENT) {	
		printf("1 (current)");
	}


	printf("\nOS/ABI:\t\t\t\t\t");
	if (ptr -> ident[OSABI] == OSABI_NONE) {
		printf("UNIX System V ABI");
	} else if (ptr -> ident[OSABI] == OSABI_SYSV) {
		printf("UNIX Systme V ABI");
	} else if (ptr -> ident[OSABI] == OSABI_HPUX) {
		printf("HP-UX ABI");
	} else if (ptr -> ident[OSABI] == OSABI_NETBSD) {
		printf("NetBSD ABI");
	} else if (ptr -> ident[OSABI] == OSABI_LINUX) {
		printf("Linux ABI");
	} else if (ptr -> ident[OSABI] == OSABI_SOLARIS) {
		printf("solaris ABI");
	} else if (ptr -> ident[OSABI] == OSABI_IRIX) {
		printf("IRTX ABI");
	} else if (ptr -> ident[OSABI] == OSABI_FREEBSD) {
		printf("FreeBSD ABI");
	} else if (ptr -> ident[OSABI] == OSABI_TRU64) {
		printf("TRU64 UNIX ABI");
	} else if (ptr -> ident[OSABI] == OSABI_ARM) {
		printf("ARM architecture");
	} else if (ptr -> ident[OSABI] == OSABI_STANDALONE) {
		printf("Stand-alone (embedded) ABI");
	}
	
	printf("\nABI Version:\t\t\t\t");	
	printf("%d", ptr -> ident[ABIVERSION]);

	printf("\nType:\t\t\t\t\t");
	if (ptr -> type == ET_NONE) {
		printf("An unknown type");
	} else if (ptr -> type == ET_REL) {
		printf("A relocatable file");
	} else if (ptr -> type == ET_EXEC) {
		printf("An executable file");
	} else if (ptr -> type == ET_DYN) {
		printf("A shared object");
	} else if (ptr -> type == ET_CORE) {
		printf("A core file");
	}
	
	printf("\nMachine:\t\t\t\t");
	if (ptr -> machine == EM_NONE) {
		printf("An unknown machine");
	} else if (ptr -> machine == EM_M32) {
		printf("AT&T WE 32100");
	} else if (ptr -> machine == EM_SPARC) {
		printf("Sun microsystems SPARC");
	} else if (ptr -> machine == EM_386) {
		printf("Intel 80386");
	} else if (ptr -> machine == EM_68K) {
		printf("Motorola 68000");
	} else if (ptr -> machine == EM_88K) {
		printf("Motorola 88000");
	} else if (ptr -> machine == EM_860) {
		printf("Intel 80860");
	} else if (ptr -> machine == EM_MIPS) {
		printf("MIPS RS3000");
	} else if (ptr -> machine == EM_PARISC) {
		printf("HP/PA");
	} else if (ptr -> machine == EM_SPARC32PLUS) {
		printf("SPARC with enhanced instruction set");
	} else if (ptr -> machine == EM_PPC) {
		printf("Power PC");
	} else if (ptr -> machine == EM_PPC64) {
		printf("PowerPC 64-bit");
	} else if (ptr -> machine == EM_S390) {
		printf("IBM s/390");
	} else if (ptr -> machine == EM_ARM) {
		printf("Advanced RISC machine");
	} else if (ptr -> machine == EM_SH) {
		printf("Renesas superH");
	} else if (ptr -> machine == EM_SPARCV9) {
		printf("SPARC v9 64-bit");
	} else if (ptr -> machine == EM_IA_64) {
		printf("Intel Itanium");
	} else if (ptr -> machine == EM_X86_64) {
		printf("AMD x86-64");
	} else if (ptr -> machine == EM_VAX) {
		printf("DEX Vax");
	}

	printf("\nVersion:\t\t\t\t");
	(ptr -> version) ? printf("0x%x", ptr -> version):printf("0x0");
	
	printf("\nEntry point address:\t\t\t0x%x", ptr -> entry);	
	
	printf("\nStart of program headder:\t\t%x(bytes into file)", ptr -> phoff);	
	printf("\nStart of section headder:\t\t%d(bytes into file)", ptr -> shoff);	
	printf("\nFlags:\t\t\t\t\t0x%x", ptr -> flags);	
	printf("\nSize of this headers:\t\t\t%d(bytes)", ptr -> ehsize);	
	printf("\nSize of program headers:\t\t%d(bytes)", ptr -> phentsize);	
	printf("\nNumber of this headers:\t\t\t%d", ptr -> phnum);	
	printf("\nSize of section headers:\t\t%d(bytes)", ptr -> shentsize);	
	printf("\nNUmber of section headers:\t\t%d", ptr -> shnum);	
	printf("\nSection header string table index:\t%d\n\n\n", ptr -> shstrndx);	
/*	
	section headder
	printf("\nsection header:");     
    printf("\n[Nr]\tName\t\tType\tAddress\tSize\tES\tflag\tLK\tInf\tAl\n");     
    if (NULL == (s_hdr = (struct section*)malloc(sizeof(struct section)))) {
		perror("malloc failes");
		exit(1);
	} 
    fseek(fp, (ptr -> shoff) + ((ptr -> shentsize) * (ptr -> shstrndx)), SEEK_SET);
    if (0 == (fread (s_hdr, sizeof(struct section), 1, fp))) {
		perror("reading failed....!");
		exit(1);
	}
    if (NULL == (buf = (char *)malloc(s_hdr -> sh_size))) {
		perror("malloc fails.....!");
		exit(1);
	}
    fseek(fp , s_hdr -> sh_offset, SEEK_SET);
	fread (buf, s_hdr -> sh_size, 1, fp); 
	fseek(fp, ptr -> shoff, SEEK_SET);
    for (j = 0; j < ptr -> shnum; j++) {
		
		if (0 == (fread (s_hdr, sizeof(struct section), 1, fp))) {
			perror("reading failed....!");
			exit(1);
		} 
		printf("\n[ %d]", j); 
		printf("\t%s", buf + s_hdr -> sh_name); 
 		switch (s_hdr -> sh_type) { 
         
    	case SHT_NULL: 
        	printf("\tNULL"); 
        	break; 
    	case SHT_PROGNITS: 
        	printf("\tPROGNITS"); 
        	break; 
    	case SHT_SYMTAB: 
        	printf("\tSYMTAB"); 
        	break; 
    	case SHT_STRTAB: 
        	printf("\tSTRTAB"); 
        	break; 
    	case SHT_RELA: 
        	printf("\tRELA"); 
	        break; 
		case SHT_HASH: 
	        printf("\tHASH");
    	    break;
	    case SHT_DYNAMIC:
    	    printf("\tDYNAMIC");
        	break;
	    case SHT_NOTE:
    	    printf("\tNOTE");
        	break;
	    case SHT_NOBITS:
    	    printf("\tNOBITS");
	        break;
	    case SHT_REL:
    	    printf("\tREL");
	        break;
	    case SHT_SHLIB:
    	    printf("\tSHLIB");
        	break;
	    case SHT_DYNSYM:
    	    printf("\tDYNSYM");
        	break;
	    case SHT_LOPROC:
    	    printf("\tLOLPROC");
        	break;
	    case SHT_HIPROC:
    	    printf("\tHIPROC");
        	break;
	    case SHT_LOUSER:
    	    printf("\tLOUSER");
        	break;
	    case SHT_HIUSER:
    	    printf("\tHIUSER");
       		 break;
    	}
	 	printf("\t%08x", s_hdr -> sh_addr);
    	printf("\t%06x", s_hdr -> sh_offset);
	    printf("\t%06x", s_hdr -> sh_size);
    	printf("\t%02x", s_hdr -> sh_entsize);

	    switch (s_hdr -> sh_flags) {

    	case SHF_WRITE:
        	printf("\tW");
	        break;
    	case SHF_ALLOC:
	        printf("\tA");
    	    break;
	    case SHF_EXXCINSTR:
    	    printf("\tEX");
        	break;
	    case SHF_MASKPROC:
    	    printf("\tMASK");
        	break;
    	}
    	printf("\t%d", s_hdr -> sh_link);
	    printf("\t%d", s_hdr -> sh_info);
	    printf("\t%d", s_hdr -> sh_addralign);
	}
	free(s_hdr);
	free(buf);
*/	return 0;
}
		
