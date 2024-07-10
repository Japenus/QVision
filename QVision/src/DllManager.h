#ifndef DLLMANAGER_H
#define DLLMANAGER_H
#include "Api.h"
#include <QLibrary>
#include <QMessageBox>
class DllManager
{
public:
    QFunctionPointer getBubble();
    bool loadLib(const QString &dll);
    QHash<QString, QFunctionPointer> getAllFuncPtrs() const;
    ~DllManager();
private:
    QLibrary dylib;
    QHash<QString, QFunctionPointer> funcPtrs;
};

#endif // DLLMANAGER_H
