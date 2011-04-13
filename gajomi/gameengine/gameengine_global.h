#ifndef GAMEENGINE_GLOBAL_H
#define GAMEENGINE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GAMEENGINE_LIBRARY)
#  define GAMEENGINESHARED_EXPORT Q_DECL_EXPORT
#else
#  define GAMEENGINESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GAMEENGINE_GLOBAL_H