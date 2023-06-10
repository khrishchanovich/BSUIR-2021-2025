#ifndef _STRING_GLOBAL_H
#define _STRING_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_STRING_LIBRARY)
#  define _STRING_EXPORT Q_DECL_EXPORT
#else
#  define _STRING_EXPORT Q_DECL_IMPORT
#endif

#endif // _STRING_GLOBAL_H
