//because windows sucks...

#ifndef QMUTEXUMAPQTSO_CROSSPLATFORMMACROS_HPP
#define QMUTEXUMAPQTSO_CROSSPLATFORMMACROS_HPP

#include <QtCore/QtGlobal>

//remember to define this variable in the .pro file
#if defined(QMUTEXUMAPQTSO_LIBRARY)
#  define EXPIMP_QMUTEXUMAPQTSO Q_DECL_EXPORT
#else
#  define EXPIMP_QMUTEXUMAPQTSO Q_DECL_IMPORT
#endif

#endif // QMUTEXUMAPQTSO_CROSSPLATFORMMACROS_HPP
