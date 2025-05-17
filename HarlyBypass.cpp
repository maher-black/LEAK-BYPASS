
#define ONE_PIECE(RET, NAME, ARGS) \
  RET(*o##NAME) ARGS; \
  RET h##NAME ARGS

ONE_PIECE(int, CryzerSetrings, (int a1, const char *a2)){
  if ( strstr(a2, "com.tencent.ig")//@onebiecerr
    || strstr(a2, "com.pubg.krmobile")//@onebiecerr
    || strstr(a2, "com.rekoo.pubgm")//@onebiecerr
    || strstr(a2, "com.vng.pubgmobile")//@onebiecerr
    || strstr(a2, "signingInfo")//@onebiecerr
    || strstr(a2, "getApkContentsSigners")
    || strstr(a2, "signatures")
    || strstr(a2, "[Landroid/content/pm/Signature;")
    || strstr(a2, ".apk")
    || strstr(a2, "/data/app")
    || strstr(a2, "/lib/arm/")//@onebiecerr
    || strstr(a2, "/app_tbs/")
    || strstr(a2, "getPackageManager")
    || strstr(a2, "()Landroid/content/pm/PackageManager;")
    || strstr(a2, "()Landroid/")
    || strstr(a2, "android/content/pm/PackageManager")
    || strstr(a2, "android")
    || strstr(a2, "(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;")
    || strstr(a2, "java/lang/Class")
    || strstr(a2, "[Landroid/")
    || strstr(a2, "ro.build.version.sdk")
    || strstr(a2, "egl")
    || strstr(a2, "ro.boot.")//@onebiecerr
    || strstr(a2, "orange.")
    || strstr(a2, "unlocked.")
    || strstr(a2, "SHA-256")
    || strstr(a2, "/dev/")
    || strstr(a2, "sys.oem_unlock_allowed")
    || strstr(a2, "setAttestationChallenge")
    || strstr(a2, "/sdcard/")//@onebiecerr
    || strstr(a2, "/sys/")
    || strstr(a2, "/data/") )
  {
    return 0;
  }//@onebiecerr
  else
  {
    return oCryzerSetrings(a1, a2);//@onebiecerr
  }
}

ONE_PIECE(int, C16, (int a1, char* a2, int a3))
{
    auto ret = reinterpret_cast<uintptr_t>(__builtin_return_address(0));
    std::string str_a2(a2);  // Convert C-style string to std::string
    if//@onebiecerr
        (
            strstr(a2, "crash")////@onebiecerr
            || strstr(a2, "opcode")//
   || strstr(a2, "app")//
   || strstr(a2, "Mrpcs")////@onebiecerr
            || strstr(a2, "blur_exit")////@onebiecerr

            ) {
        return 0;
    }//@onebiecerr
    else
    {
        auto ret = oC16(a1, a2, a3);
        return ret;
    }//@onebiecerr
}

//@onebiecerr
ONE_PIECE(int, sub_E766C, (int a1))
{
 return 0;
}//@onebiecerr

ONE_PIECE(int, C35, (int a1, void* a2, size_t a3))
{  
    if (a3 == 0x62 || a3 == 0x4E)
       { 
    return 0;
      } }
CRYZER(int, MRPCS, (int a1, _BYTE* a2, const void* a3, size_t a4, int a5, int a6))
{
    LOGI("MRPCS");
    if (strstr((char*)a2, "mrpcs"))//@onebiecerr
    {
        return oMRPCS(a1, a2, a3, a4, a5, a6);
    }
    if (a2 && a3) return (unsigned char)*a2;
    else return a1;
}
ONE_PIECE(unsigned int, sub_163068, (int a1, int a2)) //@onebiecerr
{
    return 0;
}
ONE_PIECE(int, sub_1C2A4C, (int a1, int a2, int a3))
{//@onebiecerr
 return 0;
}
ONE_PIECE(int, sub_164DF8(int a1, int a2))
{
 return 0;//@onebiecerr
}
ONE_PIECE(int*, Monitor, (int* result, unsigned int a2))
{
    LOGI("GRD2| a2 : 0x%x", a2);//@onebiecerr
    if (a2 == 0x4) //GRD2
         return oMonitor(result, 5u);//DRD2
    else
        return oMonitor(result, a2);
}//@onebiecerr

HOOK_LIB_THUMB("libanogs.so", "0xFDAEC", hC16, oC16);////C16//@onebiecerr
HOOK_LIB_THUMB("libanogs.so", "0xF31EA", hC35, oC35);////C35 main//@onebiecerr
PATCH_LIB("libanogs.so", "0xF31F1", "00 00 B0 E3 1E FF 2F E1");//he edit  PUSH.W {R8} in case 35 he stupid i think//@onebiecerr
HOOK_LIB_THUMB("libanogs.so", "0xCFF84", hMRPCS, oMRPCS);////C34 MRPCS//@onebiecerr
HOOK_LIB_THUMB("libanogs.so", "0xE766C", hsub_E766C, osub_E766C);//FOR 1DAY BAN//@onebiecerr
HOOK_LIB("libanogs.so", "0x3797BD", hMonitor, oMonitor);// FIX 1DAY OFFLINE//@onebiecerr
HOOK_LIB("libanogs.so", "0x1C2A4C", hsub_1C2A4C, osub_1C2A4C);////@onebiecerr
HOOK_LIB("libanogs.so", "0x163068", hsub_163068, osub_163068);////@onebiecerr
HOOK_LIB("libanogs.so", "0x164DF8", hsub_164DF8, osub_164DF8);////@onebiecerr
HOOK_LIB("libanogs.so", "0x19B5A4", hCryzerSetrings, oCryzerSetrings);////block caller strlen//@onebiecerr
HOOK_LIB("libanogs.so", "0x16D1A8", hCryzerSetrings, oCryzerSetrings);////block caller strlen//@onebiecerr
PATCH_LIB("libanogs.so", "0x27f640", "00 20 70 47");////@onebiecerr
PATCH_LIB("libanogs.so", "0xf32d8", "00 20 70 47");// CASE 35p FIX ONLINE 10Y//@onebiecerr
PATCH_LIB("libanogs.so", "0x2702e8", "00 00 B0 E3 1E FF 2F E1");//FIX 10Y OFFLINE//@onebiecerr
PATCH_LIB("libanogs.so", "0x2322b4", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
PATCH_LIB("libanogs.so", "0x1de8e0", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
PATCH_LIB("libanogs.so", "0x6f338", "00 00 A0 E3 1E FF 2F E1");// fix crash lobby//@onebiecerr


0x4d49144 HOOK DRAW HUD
//@onebiecerr
PATCH_LIB("libUE4.so", "0x43bfc54", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x35beca0", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x35bf6c4", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x35bfd0c", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x35bfd28", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x35bfda8", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x35bff54", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x35f9c30", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3706a44", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3706af8", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x37ac7a0", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x37ac840", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3813314", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3813328", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x381358c", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x381362c", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x381376c", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x38138f4", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3813a4c", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3813b28", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3813c68", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3814068", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3881bb8", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x38abf44", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x38b0a18", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x38b0b8c", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x38b0f04", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x38b1004", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x38b31d4", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x38b3494", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x38b35e4", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x38b3734", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x38b3884", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x396afd8", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3975ce0", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3976120", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3975f34", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x39769a4", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3976cb0", "00 00 A0 E3 1E FF 2F E1");//@onebiecerr
PATCH_LIB("libUE4.so", "0x3976dc8", "00 00 A0 E3 1E FF 2F E1");
