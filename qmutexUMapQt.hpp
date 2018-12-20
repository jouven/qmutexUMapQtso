#ifndef QMUTEXUMAPQTSO_QMUTEXUMAP_HPP
#define QMUTEXUMAPQTSO_QMUTEXUMAP_HPP

#include "crossPlatformMacros.hpp"

#include <QMutex>
#include <QMutexLocker>

#include <memory>
#include <string>
#include <unordered_map>

//FUTURE make a class instead and use the same formula as actonDataHuc_c from actonQtso

extern EXPIMP_QMUTEXUMAPQTSO std::unordered_map<std::string, std::unique_ptr<QMutex>> const & mutexUMap_ext_con_f();

//tries to get a mutex, if it doesn't exist adds it
extern EXPIMP_QMUTEXUMAPQTSO QMutex* getAddMutex_f(const std::string& key_par_con);

//tries to remove a mutex by key if found, returns true if something is removed
extern EXPIMP_QMUTEXUMAPQTSO bool removeMutex_f(const std::string& key_par_con);

#endif // QMUTEXUMAPQTSO_QMUTEXUMAP_HPP
