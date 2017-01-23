#include "ELF_declarations.h"

void section_header(char *argv)
{
	char *buff = NULL;
	int i;

	struct ELF *hdr = (struct ELF *) malloc (sizeof (struct ELF));
	struct section *s_hdr = (struct section *) malloc (sizeof (struct section));

	FILE *fp = NULL;
	FILE *strfp = NULL;

	if(NULL == (fp = fopen(argv, "rb"))) {
		perror("fopen failed\n");
		exit(1);
	}

	if(NULL == (strfp = fopen(argv, "rb"))) {
		perror("fopen failed\n");
		exit(1);
	}

	if(0 == (fread(hdr, sizeof(struct ELF), 1, fp))) {
		perror("fread failed\n");
		exit(1);
	}

	fseek(fp, hdr -> shoff, SEEK_SET);

	fseek(strfp, (hdr -> shoff) + (hdr -> shentsize) * (hdr -> shstrndx), SEEK_SET);
	fread(s_hdr, sizeof (struct section), 1, strfp);

	if(NULL == (buff = (char *) malloc (s_hdr -> sh_size))){
			printf ("malloc for buffer failed.....\n");
			exit(1);
	}
	
	fseek(strfp, s_hdr -> sh_offset, SEEK_SET);
	fread(buff, s_hdr -> sh_size, 1, strfp);

	printf("\nSection Header\n\n[Nr]  Name\t\t\bType\tAddr\t  Offset  Size\t  ES\tFlag\tLk\tInf\tAl\n");

	for( i = 0; i < hdr -> shnum; i++) {

		fread(s_hdr, sizeof(struct section), 1, fp); 

		printf("\n[%2d] ", i);
		printf("%-18s", buff + s_hdr -> sh_name);
		switch (s_hdr -> sh_type) {
		
		case SHT_NULL:
			printf("NULL");
			break;
		case SHT_PROGNITS:
			printf("PROGNITS");
			break;
		case SHT_SYMTAB:
			printf("SYMTAB");
			break;
		case SHT_STRTAB:
			printf("STRTAB");
			break;
		case SHT_RELA:
			printf("RELA");
			break;
		case SHT_HASH:
			printf("HASH");
			break;
		case SHT_DYNAMIC:
			printf("DYNAMIC");
			break;
		case SHT_NOTE:
			printf("NOTE");
			break;
		case SHT_NOBITS:
			printf("NOBITS");
			break;
		case SHT_REL:
			printf("REL");
			break;
		case SHT_SHLIB:
			printf("SHLIB");
			break;
		case SHT_DYNSYM:
			printf("DYNSYM");
			break;
		case SHT_LOPROC:
			printf("LOLPROC");
			break;
		case SHT_HIPROC:
			printf("HIPROC");
			break;
		case SHT_LOUSER:
			printf("LOUSER");
			break;
		case SHT_HIUSER:
			printf("HIUSER");
			break;
		}
		printf("\t%08x", s_hdr -> sh_addr);
		printf("  %06x", s_hdr -> sh_offset);
		printf("  %06x", s_hdr -> sh_size);
		printf("  %02x", s_hdr -> sh_entsize);
		
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
		default:
			printf("\t");
		}
		printf("\t%d", s_hdr -> sh_link);
		printf("\t%d", s_hdr -> sh_info);
		printf("\t%d", s_hdr -> sh_addralign);

	}
	printf("\n");
}
