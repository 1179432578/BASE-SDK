//
//  macro.h
//  stl
//
//  Created by lewis on 16/5/18.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef macro_h
#define macro_h

//#define assert(e)  \
//((void) ((e) ? ((void)0) : __assert (#e, __FILE__, __LINE__)))
//#define __assert(e, file, line) \
//((void)printf ("%s:%u: failed assertion `%s'\n", file, line, e), abort())

//void CCLog(const char * pszFormat, ...)
//{
//    printf("Cocos2d: ");
//    char szBuf[kMaxLogLen+1] = {0};
//    va_list ap;
//    va_start(ap, pszFormat);
//    vsnprintf(szBuf, kMaxLogLen, pszFormat, ap);
//    va_end(ap);
//    printf("%s", szBuf);
//    printf("\n");
//}

//#ifndef CCAssert
//#if COCOS2D_DEBUG > 0
//extern bool CC_DLL cc_assert_script_compatible(const char *msg);
//#define CCAssert(cond, msg) do {                              \
//if (!(cond)) {                                          \
//if (!cc_assert_script_compatible(msg) && strlen(msg)) \
//cocos2d::CCLog("Assert failed: %s", msg);           \
//CC_ASSERT(cond);                                      \
//} \
//} while (0)
//#else
//#define CCAssert(cond, msg) ((void)(cond))
//#endif
//#endif  // CCAssert

#endif /* macro_h */
