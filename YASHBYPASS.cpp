#define ONE_PIECE(RET, NAME, ARGS) \
  RET(*o##NAME) ARGS; \
  RET h##NAME ARGS

//@onebiecerr
ONE_PIECE(int __fastcall, sub_1A9DAC,(int a1, unsigned int a2, int a3))
{//@onebiecerr
 auto ret = reinterpret_cast<uintptr_t>(__builtin_return_address(0));
 if(a2>0xc00&&a2<=0xc99){
     return 0;
 }else{//@onebiecerr
    return osub_1A9DAC(a1,a2,a3);
 }
}//@onebiecerr

ONE_PIECE(int, sub_1608FC, ())
{//@onebiecerr
 while(true) {
  sleep(10000);
        }//@onebiecerr
return osub_1608FC();
}//@onebiecerr

ONE_PIECE(void* sub_149220, (int a1, const void *a2, int a3, void **a4))
{//@onebiecerr
 return 0;
} 
//@onebiecerr
ONE_PIECE(int, sub_14FE8C, (int a1, const char *a2, int a3))
{//@onebiecerr
  return 0;
}//@onebiecerr
ONE_PIECE(int sub_F31EA(int a1, unsigned char *a2, size_t a3))
{//@onebiecerr
    if (a3 == 0x62 || a3 == 0x4E)
       {
     return 0;
       }//@onebiecerr
    return osub_F31EA(a1, a2, a3);
}//@onebiecerr


HOOK_LIB("libanogs.so","0xF31EB",hsub_F31EA,osub_F31EA);  //CASE 35//@onebiecerr
HOOK_LIB("libanogs.so", "0x1A9DAC", hsub_1A9DAC, osub_1A9DAC);//case 35 caller tree starter2//@onebiecerr
HOOK_LIB("libanogs.so","0x1608FC",hsub_1608FC, osub_1608FC);//@onebiecerr
HOOK_LIB("libanogs.so", "0x149220",hsub_149220, osub_149220);//@onebiecerr
HOOK_LIB("libanogs.so", "0x14FE8C",hsub_14FE8C, osub_14FE8C);// offline ban fix//@onebiecerr
PATCH_LIB("libanogs.so", "0x6F338", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
PATCH_LIB("libanogs.so", "0x164974", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
PATCH_LIB("libanogs.so", "0x163A24", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
PATCH_LIB("libanogs.so", "0x163EC8", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
PATCH_LIB("libanogs.so", "0x1643CC", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
PATCH_LIB("libanogs.so","0x361FB8","00 20 70 47"); //here he use hook but can use this edit also //@onebiecerr


/*
this all fake hook 
//0x157994  this check_libanogs_crc_txt_elf dont use this//@onebiecerr
HOOK_LIB("libanogs.so", "0x2322B4", hMemcpyParent1, oMemcpyParent1);////@onebiecerr
HOOK_LIB("libanogs.so", "0x1DE8E0", hMemcpyParent2, oMemcpyParent2);////@onebiecerr
HOOK_LIB("libanogs.so","0x17859C", hsub_BypassFUNC, osub_BypassFUNC);//@onebiecerr
HOOK_LIB("libanogs.so","0x18F280", hsub_BypassFUNC, osub_BypassFUNC);//@onebiecerr
HOOK_LIB("libanogs.so","0x178438",hsub_178438, osub_178438);//@onebiecerr
HOOK_LIB("libanogs.so","0x178570",hsub_178570, osub_178570);//@onebiecerr
HOOK_LIB("libanogs.so", "0x19B5A4", hCryzerSetrings, oCryzerSetrings);//block caller strlen////@onebiecerr
HOOK_LIB("libanogs.so", "0x16D1A8", hCryzerSetrings, oCryzerSetrings);//block caller strlen////@onebiecerr*/
