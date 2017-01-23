#ifndef _ELF_DECLARATIONS_
#define _ELF_DECLARATIONS_
#include <stdio.h>
#include <stdlib.h>
#define MAX 16

#define MAG0 0 
#define MAG1 1 
#define MAG2 2
#define MAG3 3
#define CLASS 4
#define DATA 5
#define VERSION 6
#define OSABI 7
#define ABIVERSION 8
#define PAD 9
#define NIDENT 10 

#define ELFCLASSNONE 0
#define ELFCLASS32 1
#define ELFCLASS64 2

#define ELFDATANONE 0
#define ELFDATA2LSB 1
#define ELFDATA2MSB 2

#define EV_NONE 0
#define EV_CURRENT 1

#define OSABI_NONE 0
#define OSABI_SYSV 1
#define OSABI_HPUX 2
#define OSABI_NETBSD 3 
#define OSABI_LINUX 4
#define OSABI_SOLARIS 5
#define OSABI_IRIX 6
#define OSABI_FREEBSD 7
#define OSABI_TRU64 8
#define OSABI_ARM 9
#define OSABI_STANDALONE 10
#define ET_NONE 0
#define ET_REL 1
#define ET_EXEC 2
#define ET_DYN 3
#define ET_CORE 4

#define EM_NONE 0
#define EM_M32 1
#define EM_SPARC 2
#define EM_386 3
#define EM_68K 4
#define EM_88K 5
#define EM_860 6
#define EM_MIPS 7
#define EM_PARISC 8
#define EM_SPARC32PLUS 9
#define EM_PPC 10
#define EM_PPC64 11
#define EM_S390 12
#define EM_ARM 13
#define EM_SH 14
#define EM_SPARCV9 15
#define EM_IA_64 16
#define EM_X86_64 17
#define EM_VAX 18

#define SHT_NULL 0                                                              
#define SHT_PROGNITS 1                                                          
#define SHT_SYMTAB 2                                                            
#define SHT_STRTAB 3                                                            
#define SHT_RELA 4                                                              
#define SHT_HASH 5                                                              
#define SHT_DYNAMIC 6                                                           
#define SHT_NOTE 7                                                              
#define SHT_NOBITS 8                                                            
#define SHT_REL 9                                                               
#define SHT_SHLIB 10                                                            
#define SHT_DYNSYM 11                                                           
#define SHT_LOPROC 0x70000000                                                   
#define SHT_HIPROC 0x7fffffff                                                   
#define SHT_LOUSER 0x80000000                                                   
#define SHT_HIUSER 0xffffffff                                                   


#define SHF_WRITE 0                                                             
#define SHF_ALLOC 1                                                             
#define SHF_EXXCINSTR 2                                                         
#define SHF_MASKPROC 3                                                          
                                                                                
struct ELF {
    unsigned char ident[MAX];
    unsigned short type;
    unsigned short machine;
    unsigned int version;
    unsigned int entry;
    unsigned int phoff;
    unsigned int shoff;
    unsigned int flags;
    unsigned short ehsize;
    unsigned short phentsize;
    unsigned short phnum;
    unsigned short shentsize;
    unsigned short shnum;
    unsigned short shstrndx;

};

struct section {                                                                
    unsigned int sh_name;                                                       
    unsigned int sh_type;                                                       
    unsigned int sh_flags;                                                      
    unsigned int sh_addr;                                                       
    unsigned int sh_offset;                                                     
    unsigned int sh_size;                                                       
    unsigned int sh_link;                                                       
    unsigned int sh_info;                                                       
    unsigned int sh_addralign;                                                  
    unsigned int sh_entsize;                                                    
}; 

#endif     
