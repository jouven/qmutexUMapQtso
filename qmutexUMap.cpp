#include "qmutexUMap.hpp"
//#include "essentialQtso/essentialQt.hpp"

std::unordered_map<std::string, std::unique_ptr<QMutex>>& mutexUMap_ext_f()
{
    static std::unordered_map<std::string, std::unique_ptr<QMutex>> mutexUMap_sta;
    return mutexUMap_sta;
}

const std::unordered_map<std::string, std::unique_ptr<QMutex>>& mutexUMap_ext_con_f()
{
    return mutexUMap_ext_f();
}


QMutex* getAddMutex_f(const std::string &key_par_con)
{
    auto findResult(mutexUMap_ext_f().find(key_par_con));
    if (findResult != mutexUMap_ext_f().end())
    {
        return findResult->second.get();
    }
    else
    {
       auto emplaceResult(mutexUMap_ext_f().emplace(key_par_con, new QMutex));
       return emplaceResult.first->second.get();
    }
}

bool removeMutex_f(const std::string &key_par_con)
{
    return mutexUMap_ext_f().erase(key_par_con);
}

