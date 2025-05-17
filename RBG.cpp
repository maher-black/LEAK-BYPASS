
#define ONE_PIECE(RET, NAME, ARGS) \
  RET(*o##NAME) ARGS; \
  RET h##NAME ARGS

//@onebiecerr
ONE_PIECE(int, sub_1C2A4C, (int a1, int a2, int a3))
{//@onebiecerr
 return 0;
}//@onebiecerr
ONE_PIECE(int, sub_E766C, (int a1))
{//@onebiecerr
 return 0;
}//@onebiecerr
ONE_PIECE(unsigned int, sub_163068, (int a1, int a2))
{//@onebiecerr
    return 0;
}//@onebiecerr
ONE_PIECE(int, MemcpyParent2, (const void* Source, size_t Size)) //@onebiecerr
{
    return 0;//@onebiecerr
}
//@onebiecerr
int Cryzer_Ret0()
{//@onebiecerr
 return 0;//@onebiecerr
}
HOOK_LIB_NO_ORIG("libanogs.so", "0x6bd0c", Cryzer_Ret0);////@onebiecerr
HOOK_LIB_THUMB("libanogs.so", "0xE766C", hsub_E766C, osub_E766C);////@onebiecerr
HOOK_LIB("libanogs.so", "0x1C2A4C", hsub_1C2A4C, osub_1C2A4C);////@onebiecerr
HOOK_LIB("libanogs.so", "0x163068", hsub_163068, osub_163068);////@onebiecerr
HOOK_LIB("libanogs.so", "0x1DE8E0", hMemcpyParent2, oMemcpyParent2);////@onebiecerr
PATCH_LIB("libanogs.so", "0xf32d8", "00 20 70 47"); ////@onebiecerr
PATCH_LIB("libanogs.so", "0x27f640", "00 20 70 47"); ////@onebiecerr
PATCH_LIB("libanogs.so", "0x2702e8", "00 00 B0 E3 1E FF 2F E1"); ////@onebiecerr
PATCH_LIB("libanogs.so", "0x2322b4", "00 00 A0 E3 1E FF 2F E1"); ////@onebiecerr
PATCH_LIB("libanogs.so", "0x163a24", "00 00 A0 E3 1E FF 2F E1"); ////@onebiecerr
PATCH_LIB("libanogs.so", "0x163ec8", "00 00 A0 E3 1E FF 2F E1"); ////@onebiecerr
PATCH_LIB("libanogs.so", "0x1643cc", "00 00 A0 E3 1E FF 2F E1"); ////@onebiecerr
PATCH_LIB("libanogs.so", "0x164974", "00 00 A0 E3 1E FF 2F E1"); ////@onebiecerr
PATCH_LIB("libanogs.so", "0x6f33c", "00 00 A0 E3 1E FF 2F E1"); ////@onebiecerr
