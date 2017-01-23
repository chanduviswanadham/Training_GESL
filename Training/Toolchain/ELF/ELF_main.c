#include "ELF_declarations.h"
int main(int argc, char *argv[]) 
{
    FILE *fp = NULL;
    int i = 1;
	int j = 0;
    struct ELF *ptr = NULL;
    struct section * s_hdr = NULL;
    struct section * buf = NULL;
	ptr = (struct ELF *) malloc(sizeof(struct ELF));
	s_hdr = (struct section *) malloc(sizeof(struct section));
    while ( i < argc) {
		if ( NULL == (fp = fopen( argv[i], "r"))) {
        	perror("the file is not opened.....!");
        	exit (1);
    	}
    	if ( 0 == fread(ptr, sizeof(struct ELF), 1, fp)) {
        	perror("unable to read from file");
        	exit(1);
    	}
		if (argc > 1) {
			printf("headder:%s", argv[i]);
		}
		header(ptr);
		section_header(argv[i]);
//		program_header(ptr);

/*		printf("\nSection header:");
		printf("\n[Nr]\tName\t\tType\tAddress\toffset\tSize\tES\tflag\tLK\tInf\tAl\n");
		s_hdr = (struct section *)malloc(sizeof(struct section));
		fseek(fp, (ptr -> shoff) + ((ptr -> shentsize) * (ptr -> shstrndx)), SEEK_SET);
		fread(s_hdr, sizeof(struct section), 1, fp);
		buf = (struct section *) malloc(s_hdr -> sh_size);
		fread(buf, s_hdr -> sh_size, s_hdr -> sh_offset, s_hdr);
		rewind(fp);
		fread(s_hdr, sizeof(struct section), 1, fp);
		for ( j = 0; j < ptr -> shnum; j++) {
			
			if(0 == fread(s_hdr, sizeof(struct section), 1, fp)) {
				perror("\nfile is not opened @section header\n");
				exit(1);
			}
			printf("\n[ %d]", j);
			section_header(s_hdr, buf);
		}
*/		i++;
	}
	free(ptr);
	return 0;
}


