#ifndef SHARELIB_H
#define SHARELIB_H

#include "QtGlobal"
//Q_DECL_EXPORT 导出类
class Q_DECL_EXPORT ShareLib
{
public:
    ShareLib();
};

extern "C" Q_DECL_EXPORT void testFunction();

#endif // SHARELIB_H
