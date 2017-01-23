ELF Header:
  Magic:   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           Intel 80386
  Version:                           0x1
  Entry point address:               0x8048370
  Start of program headers:          52 (bytes into file)
  Start of section headers:          4472 (bytes into file)
  Flags:                             0x0
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         9
  Size of section headers:           40 (bytes)
  Number of section headers:         30
  Section header string table index: 27

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .interp           PROGBITS        08048154 000154 000013 00   A  0   0  1
  [ 2] .note.ABI-tag     NOTE            08048168 000168 000020 00   A  0   0  4
  [ 3] .note.gnu.build-i NOTE            08048188 000188 000024 00   A  0   0  4
  [ 4] .gnu.hash         GNU_HASH        080481ac 0001ac 000020 04   A  5   0  4
  [ 5] .dynsym           DYNSYM          080481cc 0001cc 000060 10   A  6   1  4
  [ 6] .dynstr           STRTAB          0804822c 00022c 000067 00   A  0   0  1
  [ 7] .gnu.version      VERSYM          08048294 000294 00000c 02   A  5   0  2
  [ 8] .gnu.version_r    VERNEED         080482a0 0002a0 000030 00   A  6   1  4
  [ 9] .rel.dyn          REL             080482d0 0002d0 000008 08   A  5   0  4
  [10] .rel.plt          REL             080482d8 0002d8 000020 08   A  5  12  4
  [11] .init             PROGBITS        080482f8 0002f8 000023 00  AX  0   0  4
  [12] .plt              PROGBITS        08048320 000320 000050 04  AX  0   0 16
  [13] .text             PROGBITS        08048370 000370 0001e2 00  AX  0   0 16
  [14] .fini             PROGBITS        08048554 000554 000014 00  AX  0   0  4
  [15] .rodata           PROGBITS        08048568 000568 00000b 00   A  0   0  4
  [16] .eh_frame_hdr     PROGBITS        08048574 000574 00002c 00   A  0   0  4
  [17] .eh_frame         PROGBITS        080485a0 0005a0 0000b0 00   A  0   0  4
  [18] .init_array       INIT_ARRAY      08049f08 000f08 000004 00  WA  0   0  4
  [19] .fini_array       FINI_ARRAY      08049f0c 000f0c 000004 00  WA  0   0  4
  [20] .jcr              PROGBITS        08049f10 000f10 000004 00  WA  0   0  4
  [21] .dynamic          DYNAMIC         08049f14 000f14 0000e8 08  WA  6   0  4
  [22] .got              PROGBITS        08049ffc 000ffc 000004 04  WA  0   0  4
  [23] .got.plt          PROGBITS        0804a000 001000 00001c 04  WA  0   0  4
  [24] .data             PROGBITS        0804a01c 00101c 000008 00  WA  0   0  4
  [25] .bss              NOBITS          0804a024 001024 000004 00  WA  0   0  1
  [26] .comment          PROGBITS        00000000 001024 00004d 01  MS  0   0  1
  [27] .shstrtab         STRTAB          00000000 001071 000106 00      0   0  1
  [28] .symtab           SYMTAB          00000000 001628 000440 10     29  45  4
  [29] .strtab           STRTAB          00000000 001a68 00026f 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings)
  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)
  O (extra OS processing required) o (OS specific), p (processor specific)

There are no section groups in this file.

Program Headers:
  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
  PHDR           0x000034 0x08048034 0x08048034 0x00120 0x00120 R E 0x4
  INTERP         0x000154 0x08048154 0x08048154 0x00013 0x00013 R   0x1
      [Requesting program interpreter: /lib/ld-linux.so.2]
  LOAD           0x000000 0x08048000 0x08048000 0x00650 0x00650 R E 0x1000
  LOAD           0x000f08 0x08049f08 0x08049f08 0x0011c 0x00120 RW  0x1000
  DYNAMIC        0x000f14 0x08049f14 0x08049f14 0x000e8 0x000e8 RW  0x4
  NOTE           0x000168 0x08048168 0x08048168 0x00044 0x00044 R   0x4
  GNU_EH_FRAME   0x000574 0x08048574 0x08048574 0x0002c 0x0002c R   0x4
  GNU_STACK      0x000000 0x00000000 0x00000000 0x00000 0x00000 RW  0x10
  GNU_RELRO      0x000f08 0x08049f08 0x08049f08 0x000f8 0x000f8 R   0x1

 Section to Segment mapping:
  Segment Sections...
   00     
   01     .interp 
   02     .interp .note.ABI-tag .note.gnu.build-id .gnu.hash .dynsym .dynstr .gnu.version .gnu.version_r .rel.dyn .rel.plt .init .plt .text .fini .rodata .eh_frame_hdr .eh_frame 
   03     .init_array .fini_array .jcr .dynamic .got .got.plt .data .bss 
   04     .dynamic 
   05     .note.ABI-tag .note.gnu.build-id 
   06     .eh_frame_hdr 
   07     
   08     .init_array .fini_array .jcr .dynamic .got 

Dynamic section at offset 0xf14 contains 24 entries:
  Tag        Type                         Name/Value
 0x00000001 (NEEDED)                     Shared library: [libc.so.6]
 0x0000000c (INIT)                       0x80482f8
 0x0000000d (FINI)                       0x8048554
 0x00000019 (INIT_ARRAY)                 0x8049f08
 0x0000001b (INIT_ARRAYSZ)               4 (bytes)
 0x0000001a (FINI_ARRAY)                 0x8049f0c
 0x0000001c (FINI_ARRAYSZ)               4 (bytes)
 0x6ffffef5 (GNU_HASH)                   0x80481ac
 0x00000005 (STRTAB)                     0x804822c
 0x00000006 (SYMTAB)                     0x80481cc
 0x0000000a (STRSZ)                      103 (bytes)
 0x0000000b (SYMENT)                     16 (bytes)
 0x00000015 (DEBUG)                      0x0
 0x00000003 (PLTGOT)                     0x804a000
 0x00000002 (PLTRELSZ)                   32 (bytes)
 0x00000014 (PLTREL)                     REL
 0x00000017 (JMPREL)                     0x80482d8
 0x00000011 (REL)                        0x80482d0
 0x00000012 (RELSZ)                      8 (bytes)
 0x00000013 (RELENT)                     8 (bytes)
 0x6ffffffe (VERNEED)                    0x80482a0
 0x6fffffff (VERNEEDNUM)                 1
 0x6ffffff0 (VERSYM)                     0x8048294
 0x00000000 (NULL)                       0x0

Relocation section '.rel.dyn' at offset 0x2d0 contains 1 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
08049ffc  00000306 R_386_GLOB_DAT    00000000   __gmon_start__

Relocation section '.rel.plt' at offset 0x2d8 contains 4 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
0804a00c  00000107 R_386_JUMP_SLOT   00000000   printf
0804a010  00000207 R_386_JUMP_SLOT   00000000   __stack_chk_fail
0804a014  00000307 R_386_JUMP_SLOT   00000000   __gmon_start__
0804a018  00000407 R_386_JUMP_SLOT   00000000   __libc_start_main

The decoding of unwind sections for machine type Intel 80386 is not currently supported.

Symbol table '.dynsym' contains 6 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 00000000     0 FUNC    GLOBAL DEFAULT  UND printf@GLIBC_2.0 (2)
     2: 00000000     0 FUNC    GLOBAL DEFAULT  UND __stack_chk_fail@GLIBC_2.4 (3)
     3: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __gmon_start__
     4: 00000000     0 FUNC    GLOBAL DEFAULT  UND __libc_start_main@GLIBC_2.0 (2)
     5: 0804856c     4 OBJECT  GLOBAL DEFAULT   15 _IO_stdin_used

Symbol table '.symtab' contains 68 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 08048154     0 SECTION LOCAL  DEFAULT    1 
     2: 08048168     0 SECTION LOCAL  DEFAULT    2 
     3: 08048188     0 SECTION LOCAL  DEFAULT    3 
     4: 080481ac     0 SECTION LOCAL  DEFAULT    4 
     5: 080481cc     0 SECTION LOCAL  DEFAULT    5 
     6: 0804822c     0 SECTION LOCAL  DEFAULT    6 
     7: 08048294     0 SECTION LOCAL  DEFAULT    7 
     8: 080482a0     0 SECTION LOCAL  DEFAULT    8 
     9: 080482d0     0 SECTION LOCAL  DEFAULT    9 
    10: 080482d8     0 SECTION LOCAL  DEFAULT   10 
    11: 080482f8     0 SECTION LOCAL  DEFAULT   11 
    12: 08048320     0 SECTION LOCAL  DEFAULT   12 
    13: 08048370     0 SECTION LOCAL  DEFAULT   13 
    14: 08048554     0 SECTION LOCAL  DEFAULT   14 
    15: 08048568     0 SECTION LOCAL  DEFAULT   15 
    16: 08048574     0 SECTION LOCAL  DEFAULT   16 
    17: 080485a0     0 SECTION LOCAL  DEFAULT   17 
    18: 08049f08     0 SECTION LOCAL  DEFAULT   18 
    19: 08049f0c     0 SECTION LOCAL  DEFAULT   19 
    20: 08049f10     0 SECTION LOCAL  DEFAULT   20 
    21: 08049f14     0 SECTION LOCAL  DEFAULT   21 
    22: 08049ffc     0 SECTION LOCAL  DEFAULT   22 
    23: 0804a000     0 SECTION LOCAL  DEFAULT   23 
    24: 0804a01c     0 SECTION LOCAL  DEFAULT   24 
    25: 0804a024     0 SECTION LOCAL  DEFAULT   25 
    26: 00000000     0 SECTION LOCAL  DEFAULT   26 
    27: 00000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    28: 08049f10     0 OBJECT  LOCAL  DEFAULT   20 __JCR_LIST__
    29: 080483b0     0 FUNC    LOCAL  DEFAULT   13 deregister_tm_clones
    30: 080483e0     0 FUNC    LOCAL  DEFAULT   13 register_tm_clones
    31: 08048420     0 FUNC    LOCAL  DEFAULT   13 __do_global_dtors_aux
    32: 0804a024     1 OBJECT  LOCAL  DEFAULT   25 completed.6591
    33: 08049f0c     0 OBJECT  LOCAL  DEFAULT   19 __do_global_dtors_aux_fin
    34: 08048440     0 FUNC    LOCAL  DEFAULT   13 frame_dummy
    35: 08049f08     0 OBJECT  LOCAL  DEFAULT   18 __frame_dummy_init_array_
    36: 00000000     0 FILE    LOCAL  DEFAULT  ABS ds_obj.c
    37: 00000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    38: 0804864c     0 OBJECT  LOCAL  DEFAULT   17 __FRAME_END__
    39: 08049f10     0 OBJECT  LOCAL  DEFAULT   20 __JCR_END__
    40: 00000000     0 FILE    LOCAL  DEFAULT  ABS 
    41: 08049f0c     0 NOTYPE  LOCAL  DEFAULT   18 __init_array_end
    42: 08049f14     0 OBJECT  LOCAL  DEFAULT   21 _DYNAMIC
    43: 08049f08     0 NOTYPE  LOCAL  DEFAULT   18 __init_array_start
    44: 0804a000     0 OBJECT  LOCAL  DEFAULT   23 _GLOBAL_OFFSET_TABLE_
    45: 08048550     2 FUNC    GLOBAL DEFAULT   13 __libc_csu_fini
    46: 00000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_deregisterTMCloneTab
    47: 080483a0     4 FUNC    GLOBAL HIDDEN    13 __x86.get_pc_thunk.bx
    48: 0804a01c     0 NOTYPE  WEAK   DEFAULT   24 data_start
    49: 00000000     0 FUNC    GLOBAL DEFAULT  UND printf@@GLIBC_2.0
    50: 0804a024     0 NOTYPE  GLOBAL DEFAULT   24 _edata
    51: 08048554     0 FUNC    GLOBAL DEFAULT   14 _fini
    52: 00000000     0 FUNC    GLOBAL DEFAULT  UND __stack_chk_fail@@GLIBC_2
    53: 0804a01c     0 NOTYPE  GLOBAL DEFAULT   24 __data_start
    54: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __gmon_start__
    55: 0804a020     0 OBJECT  GLOBAL HIDDEN    24 __dso_handle
    56: 0804856c     4 OBJECT  GLOBAL DEFAULT   15 _IO_stdin_used
    57: 00000000     0 FUNC    GLOBAL DEFAULT  UND __libc_start_main@@GLIBC_
    58: 080484e0    97 FUNC    GLOBAL DEFAULT   13 __libc_csu_init
    59: 0804a028     0 NOTYPE  GLOBAL DEFAULT   25 _end
    60: 08048370     0 FUNC    GLOBAL DEFAULT   13 _start
    61: 08048568     4 OBJECT  GLOBAL DEFAULT   15 _fp_hw
    62: 0804a024     0 NOTYPE  GLOBAL DEFAULT   25 __bss_start
    63: 0804846d   109 FUNC    GLOBAL DEFAULT   13 main
    64: 00000000     0 NOTYPE  WEAK   DEFAULT  UND _Jv_RegisterClasses
    65: 0804a024     0 OBJECT  GLOBAL HIDDEN    24 __TMC_END__
    66: 00000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_registerTMCloneTable
    67: 080482f8     0 FUNC    GLOBAL DEFAULT   11 _init

Histogram for `.gnu.hash' bucket list length (total of 2 buckets):
 Length  Number     % of total  Coverage
      0  1          ( 50.0%)
      1  1          ( 50.0%)    100.0%

Version symbols section '.gnu.version' contains 6 entries:
 Addr: 0000000008048294  Offset: 0x000294  Link: 5 (.dynsym)
  000:   0 (*local*)       2 (GLIBC_2.0)     3 (GLIBC_2.4)     0 (*local*)    
  004:   2 (GLIBC_2.0)     1 (*global*)   

Version needs section '.gnu.version_r' contains 1 entries:
 Addr: 0x00000000080482a0  Offset: 0x0002a0  Link: 6 (.dynstr)
  000000: Version: 1  File: libc.so.6  Cnt: 2
  0x0010:   Name: GLIBC_2.4  Flags: none  Version: 3
  0x0020:   Name: GLIBC_2.0  Flags: none  Version: 2

Displaying notes found at file offset 0x00000168 with length 0x00000020:
  Owner                 Data size	Description
  GNU                  0x00000010	NT_GNU_ABI_TAG (ABI version tag)
    OS: Linux, ABI: 2.6.24

Displaying notes found at file offset 0x00000188 with length 0x00000024:
  Owner                 Data size	Description
  GNU                  0x00000014	NT_GNU_BUILD_ID (unique build ID bitstring)
    Build ID: c7fc292a8c1e468bd13569bb77b8df4a07b7fab4
