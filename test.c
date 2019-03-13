/*
EXAMPLE 1
00 80        se_mflr    r0  
18 21 06 F0  e_stwu     r1  0xfffffff0(r1) 
D5 01        se_stw     r0  0x14(r1) 
79 FF AF 09  e_bl       0xfdffaf08 
C5 01        se_lwz     r0  0x14(r1) 
00 D3        se_extsb   r3  
00 90        se_mtlr    r0  
20 F1        se_addi    r1  0x10 
00 04        se_blr

EXAMPLE 2
2D 07        se_bmaski  r7  0x10 
70 D8 E3 FE  e_lis      r6  0xfffc3fe 
70 0B 02 F0  e_li       r0  0x5af0 
6D C3        se_slwi    r3  0x1c 
44 30        se_or      r0  r3  
1C C6 C0 00  e_add16i   r6  r6  0xffffc000 
D1 06        se_stw     r0  0x4(r6) 
44 30        se_or      r0  r3  
02 78        se_mtar    r16 r7  
D1 06        se_stw     r0  0x4(r6) 
C0 06        se_lwz     r0  0x0(r6) 
66 40        se_btsti   r0  0x4 
E2 FE        se_bne     0xfffffe04 
00 04        se_blr

SE ONLY 3
04 7F        se_add     r15 r7  
21 EC        se_addi    r12 0x1f 
46 10        se_and     r0  r1  
47 01        se_and.    r1  r0  
45 32        se_andc    r2  r3  
2F 14        se_andi    r4  0x11 
E8 FA        se_b       0xfffffe0c 
E9 00        se_bl      0x0 
E7 14        se_bso     0x28 
61 2B        se_bclri   r11 0x12 
00 06        se_bctr    
00 07        se_bctrl   
63 17        se_bgeni   r7  0x11 
00 04        se_blr     
00 05        se_blrl    
2C 06        se_bmaski  r6  0x0 
64 10        se_bseti   r0  0x1 
66 74        se_btsti   r4  0x7 
0C 10        se_cmp     r0  r1  
0E CF        se_cmph    r15 r12 
0F 91        se_cmphl   r1  r9  
2B 63        se_cmpi    r3  0x16 
0D 76        se_cmpl    r6  r7  
22 BC        se_cmpli   r12 0xc 
00 D1        se_extsb   r1  
00 F2        se_extsh   r2  
00 CE        se_extzb   r14 
00 E8        se_extzh   r8  
00 00        se_illegal 
00 01        se_isync   
88 18        se_lbz     r1  0x20(r8) 
A9 84        se_lbh     r8  0x24(r4) 
4C F4        se_li      r4  0x4f 
CF 60        se_lwz     r6  0x3c(r0) 
03 07        se_mfar    r7  r8  
00 A3        se_mfctr   r3  
00 84        se_mflr    r4  
01 0F        se_mr      r15 r0  
02 2F        se_mtar    r23 r2  
00 B6        se_mtctr   r6  
00 9F        se_mtlr    r15 
05 43        se_mullw   r3  r4  
00 38        se_neg     r8  
00 29        se_not     r9  
44 10        se_or      r0  r1  
00 09        se_rfci    
00 0A        se_rfdi    
00 08        se_rfi     
00 02        se_sc      
42 65        se_slw     r6  
6C 77        se_slwi    r7  0x7 
41 E6        se_sraw    r14 
6A 89        se_srawi   r9  0x8 
40 0E        se_srw     r0  
69 9D        se_srwi    r13 0x19 
9A 02        se_stb     r0  0x28(r2) 
B6 1E        se_sth     r1  0x18(r14) 
D0 7D        se_stw     r7  0x0(r13) 
06 21        se_sub     r2  
07 AD        se_subf    r10 
25 77        se_subi    r7  0x18 
27 29        se_subi.   r9  0x13 
E9 C2        se_bl      0xfffffe7c 


E ONLY
1C 83 00 1B  e_add16i   r4  r3  0x1b 
70 C0 8C 56  e_add2i.   r0  0x3456 
71 01 93 21  e_add2is   r1  0x4321 
18 46 88 37  e_addi.    r2  r6  0x37 
18 65 81 37  e_addi     r3  r5  0x3700 
18 84 9A 37  e_addic.   r4  r4  0x370000 
18 E8 93 37  e_addic    r7  r8  0x37000000 
71 3F CE ED  e_and2i.   r9  0xffffeed 
71 40 E8 05  e_and2is.  r10 0x5 
19 AB C8 39  e_andi.    r11 r13 0x39 
19 EC C2 37  e_andi     r12 r15 0x370000 
78 00 00 EC  e_b        0xec 
78 00 00 01  e_bl       0x0 
7A 03 FF CC  e_bns      cr0 0xffffffcc 
7A 1F 00 01  e_beql     cr3 0x0 
70 C2 9B 33  e_cmp16i   r2  0x3333 
18 46 A9 37  e_cmpi     cr2 r6  0x3700 
7C 87 58 1C  e_cmph     cr0 r7  r11 
73 EC B5 EF  e_cmph16i  r12 0xfffffdef 
7C 06 40 5C  e_cmphl    cr0 r6  r8  
70 4D BA 34  e_cmphl16i r13 0x1234 
73 E1 AE E0  e_cmpl16i  r1  0xfffffee0 
18 A3 AB 37  e_cmpli    cr5 r3  0x37000000 
7F A3 02 02  e_crand    cr29 cr3 cr0 
7C 02 E9 02  e_crandc   cr0 cr2 cr29 
7D F0 8A 42  e_creqv    cr15 cr16 cr17 
7D E0 19 C2  e_crnand   cr15 cr0 cr3 
7D E0 18 42  e_crnor    cr15 cr0 cr3 
7D 8D 73 82  e_cror     cr12 cr13 cr14 
7E 72 8B 42  e_crorc    cr19 cr18 cr17 
7C 00 01 82  e_crxor    cr0 cr0 cr0 
30 E3 CC 0D  e_lbz      r7  0xffffcc0d(r3) 
18 E5 00 CC  e_lbzu     r7  0xffffffcc(r5) 
39 0A 01 FF  e_lha      r8  0x1ff(r10) 
19 01 03 FF  e_lhau     r8  0xffffffff(r1) 
58 E0 18 38  e_lhz      r7  0x1838(r0) 
18 E0 01 3E  e_lhzu     r7  0x3e(r0) 
70 06 1B 33  e_li       r0  0x33333 
70 26 E3 33  e_lis      r1  0x3333 
18 A3 08 18  e_lmw      r5  0x18(r3) 
50 A3 27 28  e_lwz      r5  0x2728(r3) 
18 C2 02 72  e_lwzu     r6  0x72(r2) 
7C 98 00 20  e_mcrf     cr1 cr6 
19 2A A0 37  e_mulli    r9  r10 0x37 
70 01 A6 68  e_mull2i   r1  0x668 
70 A4 C3 45  e_or2i     r5  0x2345 
70 B4 D3 45  e_or2is    r5  0xa345 
19 27 D8 37  e_ori.     r9  r7  0x37 
19 07 D1 37  e_ori      r8  r7  0x3700 
7E D2 02 30  e_rlw      r2  r18 r0  
7C 48 02 31  e_rlw.     r0  r8  r0  
7C 74 AA 70  e_rlwi     r0  r20 0x15 
7C 62 AA 71  e_rlwi.    r0  r2  0x15 
76 64 6A 1E  e_rlwimi   r4  r19 0xd 0x8 0xf 
74 24 68 63  e_rlwinm   r4  r1  0xd 0x1 0x11 
7E 6C 30 70  e_slwi     r2  r12 0x6 
7D 4C A0 71  e_slwi.    r1  r12 0x14 
7C 20 84 70  e_srwi     r0  r0  0x10 
7C 20 5C 71  e_srwi.    r0  r0  0xb 
34 61 55 F0  e_stb      r3  0x55f0(r1) 
1A 76 04 FC  e_stbu     r19 0xfffffffc(r22) 
5C 15 02 9A  e_sth      r0  0x29a(r21) 
18 37 05 FF  e_sthu     r1  0xffffffff(r23) 
18 03 09 04  e_stmw     r0  0x4(r3) 
54 60 3F 21  e_stw      r3  0x3f21(r0) 
1A C4 06 EE  e_stwu     r22 0xffffffee(r4) 
18 15 B2 37  e_subfic   r0  r21 0x370000 
1A C0 BB 37  e_subfic.  r22 r0  0x37000000 
18 75 E1 37  e_xori     r21 r3  0x3700 
1A 80 E8 37  e_xori.    r0  r20 0x37 
79 FF FF 82  e_b        0xfdffff82 
79 FF FE 67  e_bl       0xfdfffe66 
66 61        se_btsti   r1  0x6 

*/

#include "vle.h"
#include <stdio.h>

const uint8_t example_1 [] = {0x00, 0x80, 0x18, 0x21, 0x06, 0xF0, 0xD5, 0x01, 0x79, 0xFF, 0xAF, 0x09, 0xC5, 0x01, 0x00, 0xD3, 0x00, 0x90, 0x20, 0xF1, 0x00, 0x04};
const uint8_t example_2 [] = {0x2D, 0x07, 0x70, 0xD8, 0xE3, 0xFE, 0x70, 0x0B, 0x02, 0xF0, 0x6D, 0xC3, 0x44, 0x30, 0x1C, 0xC6, 0xC0, 0x00, 0xD1, 0x06, 0x44, 0x30, 0x02, 0x78, 0xD1, 0x06, 0xC0, 0x06, 0x66, 0x40, 0xE2, 0xFE, 0x00, 0x04};
const uint8_t se_only []   = {0x04, 0x7f, 0x21, 0xec, 0x46, 0x10, 0x47, 0x01, 0x45, 0x32, 0x2f, 0x14, 0xe8, 0xfa, 0xe9, 0x00, 0xe7, 0x14, 0x61, 0x2b, 0x00, 0x06, 0x00, 0x07, 0x63, 0x17, 0x00, 0x04, 0x00, 0x05, 0x2c, 0x06, 0x64, 0x10, 0x66, 0x74, 0x0c, 0x10, 0x0e, 0xcf, 0x0f, 0x91, 0x2b, 0x63, 0x0d, 0x76, 0x22, 0xbc, 0x00, 0xd1, 0x00, 0xf2, 0x00, 0xce, 0x00, 0xe8, 0x00, 0x00, 0x00, 0x01, 0x88, 0x18, 0xa9, 0x84, 0x4c, 0xf4, 0xcf, 0x60, 0x03, 0x07, 0x00, 0xa3, 0x00, 0x84, 0x01, 0x0f, 0x02, 0x2f, 0x00, 0xb6, 0x00, 0x9f, 0x05, 0x43, 0x00, 0x38, 0x00, 0x29, 0x44, 0x10, 0x00, 0x09, 0x00, 0x0a, 0x00, 0x08, 0x00, 0x02, 0x42, 0x65, 0x6c, 0x77, 0x41, 0xe6, 0x6a, 0x89, 0x40, 0x0e, 0x69, 0x9d, 0x9a, 0x02, 0xb6, 0x1e, 0xd0, 0x7d, 0x06, 0x21, 0x07, 0xad, 0x25, 0x77, 0x27, 0x29, 0xe9, 0xc2};
const uint8_t e_only []    = {0x1c, 0x83, 0x00, 0x1b, 0x70, 0xc0, 0x8c, 0x56, 0x71, 0x01, 0x93, 0x21, 0x18, 0x46, 0x88, 0x37, 0x18, 0x65, 0x81, 0x37, 0x18, 0x84, 0x9a, 0x37, 0x18, 0xe8, 0x93, 0x37, 0x71, 0x3f, 0xce, 0xed, 0x71, 0x40, 0xe8, 0x05, 0x19, 0xab, 0xc8, 0x39, 0x19, 0xec, 0xc2, 0x37, 0x78, 0x00, 0x00, 0xec, 0x78, 0x00, 0x00, 0x01, 0x7a, 0x03, 0xff, 0xcc, 0x7a, 0x1f, 0x00, 0x01, 0x70, 0xc2, 0x9b, 0x33, 0x18, 0x46, 0xa9, 0x37, 0x7c, 0x87, 0x58, 0x1c, 0x73, 0xec, 0xb5, 0xef, 0x7c, 0x06, 0x40, 0x5c, 0x70, 0x4d, 0xba, 0x34, 0x73, 0xe1, 0xae, 0xe0, 0x18, 0xa3, 0xab, 0x37, 0x7f, 0xa3, 0x02, 0x02, 0x7c, 0x02, 0xe9, 0x02, 0x7d, 0xf0, 0x8a, 0x42, 0x7d, 0xe0, 0x19, 0xc2, 0x7d, 0xe0, 0x18, 0x42, 0x7d, 0x8d, 0x73, 0x82, 0x7e, 0x72, 0x8b, 0x42, 0x7c, 0x00, 0x01, 0x82, 0x30, 0xe3, 0xcc, 0x0d, 0x18, 0xe5, 0x00, 0xcc, 0x39, 0x0a, 0x01, 0xff, 0x19, 0x01, 0x03, 0xff, 0x58, 0xe0, 0x18, 0x38, 0x18, 0xe0, 0x01, 0x3e, 0x70, 0x06, 0x1b, 0x33, 0x70, 0x26, 0xe3, 0x33, 0x18, 0xa3, 0x08, 0x18, 0x50, 0xa3, 0x27, 0x28, 0x18, 0xc2, 0x02, 0x72, 0x7c, 0x98, 0x00, 0x20, 0x19, 0x2a, 0xa0, 0x37, 0x70, 0x01, 0xa6, 0x68, 0x70, 0xa4, 0xc3, 0x45, 0x70, 0xb4, 0xd3, 0x45, 0x19, 0x27, 0xd8, 0x37, 0x19, 0x07, 0xd1, 0x37, 0x7e, 0xd2, 0x02, 0x30, 0x7c, 0x48, 0x02, 0x31, 0x7c, 0x74, 0xaa, 0x70, 0x7c, 0x62, 0xaa, 0x71, 0x76, 0x64, 0x6a, 0x1e, 0x74, 0x24, 0x68, 0x63, 0x7e, 0x6c, 0x30, 0x70, 0x7d, 0x4c, 0xa0, 0x71, 0x7c, 0x20, 0x84, 0x70, 0x7c, 0x20, 0x5c, 0x71, 0x34, 0x61, 0x55, 0xf0, 0x1a, 0x76, 0x04, 0xfc, 0x5c, 0x15, 0x02, 0x9a, 0x18, 0x37, 0x05, 0xff, 0x18, 0x03, 0x09, 0x04, 0x54, 0x60, 0x3f, 0x21, 0x1a, 0xc4, 0x06, 0xee, 0x18, 0x15, 0xb2, 0x37, 0x1a, 0xc0, 0xbb, 0x37, 0x18, 0x75, 0xe1, 0x37, 0x1a, 0x80, 0xe8, 0x37, 0x79, 0xff, 0xff, 0x82, 0x79, 0xff, 0xfe, 0x67}; 

//Regression tests for the reported issue #1
// Tested on Freescale Codewarrior 5.9.0 IDE, Compiler: PPC_eabi v4.3.0.224
// Proved by HW: MPC5643L(PPCe200)
const uint8_t testcase_1 [] = {
0x7C, 0xC0, 0x23, 0x78, //  or  r6,r0,r4  32bit Common
0x7C, 0xC0, 0x23, 0x79  //  or. r6,r0,r4  32bit Common
};
const uint8_t testcase_2 [] = {
0x44, 0x70				//  se_or  r0, r7  16bit VLE
};
const uint8_t testcase_3 [] = {
0x7C, 0x64, 0x18, 0xF8 //  not  r4,r3 | nor r4,r3,r3
};
const uint8_t testcase_4 [] = {
0x7C, 0xC0, 0x20, 0xF8, //  nor  r6 r0 r4
0x7C, 0xC0, 0x20, 0xF9  //  nor. r6 r0 r4
};

const uint8_t testcase_5 [] = {
0x7C, 0x80, 0x00, 0xA6, // mfmsr r4
0x7C, 0x80, 0x01, 0x24, // mtmsr r4
0x7C, 0x60, 0x82, 0xA6, // mfspr r3,0x200 gives:0x10 error!
0x7C, 0x60, 0x83, 0xA6, // mtspr 0x200, r3 gives 0x10 error!
0x7C, 0xA0, 0x00, 0x26, // mfcr r5
0x7C, 0x00, 0x04, 0xAC, // msync
0x7C, 0x00, 0x07, 0x64, // tlbre
0x7C, 0x00, 0x07, 0xA4  // tlbwe
};

const uint8_t testcase_6 [] = {
0x1C, 0xC3, 0xFF, 0xFF,  // e_add16i r6 r3 0xffffffff (ok)
0x1D, 0x81, 0x00, 0x10,  // e_add16i r12 r1 0x10 (ok)
0x1F, 0xFF, 0x58, 0x00   // e_add16i r31 r31 0x5800
};

const uint8_t testcase_7 [] ={
0x55,0xCB,0xFF,0xB8, //  e_stw r14 0xffffffb8(r11) (ok)
0x55,0xEB,0xFF,0xBC, //  e_stw r15 0xffffffbc(r11) (ok)
0x56,0x0B,0xFF,0xC0, //  e_stw r16 0xffffffc0(r11)
0x56,0x2B,0xFF,0xC4, //  e_stw r17 0xffffffc4(r11)
0x56,0x4B,0xFF,0xC8, //  e_stw r18 0xffffffc8(r11)
0x56,0x6B,0xFF,0xCC, //  e_stw r19 0xffffffcc(r11)
0x56,0x8B,0xFF,0xD0, //  e_stw r20 0xffffffd0(r11)
0x56,0xAB,0xFF,0xD4, //  e_stw r21 0xffffffd4(r11)
0x56,0xCB,0xFF,0xD8, //  e_stw r22 0xffffffd8(r11)
0x56,0xEB,0xFF,0xDC, //  e_stw r23 0xffffffdc(r11)
0x57,0x0B,0xFF,0xE0, //  e_stw r24 0xffffffe0(r11)
0x57,0x2B,0xFF,0xE4, //  e_stw r25 0xffffffe4(r11)
0x57,0x4B,0xFF,0xE8, //  e_stw r26 0xffffffe8(r11)
0x57,0x6B,0xFF,0xEC, //  e_stw r27 0xffffffec(r11)
0x57,0x8B,0xFF,0xF0, //  e_stw r28 0xfffffff0(r11)
0x57,0xAB,0xFF,0xF4, //  e_stw r29 0xfffffff4(r11)
0x57,0xCB,0xFF,0xF8, //  e_stw r30 0xfffffff8(r11)
0x57,0xEB,0xFF,0xFC  //  e_stw r31 0xfffffffc(r11)
};

const uint8_t testcase_8 [] ={
0x7C,0x64,0x29,0x2E, // stwx r3,r4,r5
0x7D,0x28,0x01,0x2E, // stwx  r9,r8,r0
0x25,0x77,			 // se_subi  r7,18
0x27,0x77,			 // se_subi. r7,18
0x63,0x17			 // se_bgeni r7,11
};

const uint8_t testcase_9 [] ={
0x51, 0xE3, 0x27, 0x28, // e_lwz r15 0x2728(r3)
0x52, 0x03, 0x27, 0x28, // e_lwz r16 0x2728(r3)
0x7A, 0x20, 0xFF, 0xF8, // e_bdnz 0xfffffff8
0x7A, 0x30, 0xFF, 0xF8, // e_bdz 0xfffffff8
0x7A, 0x20, 0xFF, 0xF9, // e_bdnzl 0xfffffff8
0x7A, 0x30, 0xFF, 0xF9, // e_bdzl 0xfffffff8
//0x7C,0x00,0x81,0x46, // ?? 5000011e
//0x55,0x0d // ?? 40001396
};


int decode(const uint8_t* buffer, const uint32_t size, const uint8_t req_rows) {
	int rows=0;
	uint32_t j;
	uint64_t addr = 0;
	char tmp[256];
	vle_t* instr = 0;
	vle_handle handle;
	if (vle_init(&handle, buffer, size)) {
		printf("failed to initialize handle\n");
		return rows;
	}
	while((instr = vle_next(&handle))) {
		vle_snprint(tmp, 256, addr, instr);
		if(instr->size == 2){
			printf ("%02X %02X        %s\n", handle.pos[0], handle.pos[1], tmp);
			rows++;
		} else {
			printf ("%02X %02X %02X %02X  %s\n", handle.pos[0], handle.pos[1], handle.pos[2], handle.pos[3], tmp);
			rows++;
		}
		addr += instr->size;
		vle_free(instr);
	};
	printf("Decoded rows: %i/%i\n",rows,req_rows);
	if (rows != req_rows){
		fprintf(stderr, "ERROR: testcase failed! Number of rows mismatched.\n");
	}else{
		fprintf(stderr, "INFO:  number of rows are equals. OK.\n");
	}
	return rows;
}

#define TEST(name, req_rows) \
 fprintf( stderr, #name "\n");\
 decode( name, sizeof(name), req_rows)

int main(int argc, char const *argv[]) {
	TEST(example_1, 9);
	TEST(example_2, 14);
	TEST(se_only, 63);
	TEST(e_only, 72);
	
	//These are wrong actually:
	TEST(testcase_1, 2);
	TEST(testcase_2, 1);
	TEST(testcase_3, 1);
	TEST(testcase_4, 2);
	TEST(testcase_5, 8);
	TEST(testcase_6, 3);
	TEST(testcase_7, 18);
	TEST(testcase_8, 5);
	TEST(testcase_9, 6);
	return 0;
}
