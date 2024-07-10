#include "DllManager.h"
bool DllManager::loadLib(const QString &dll)
{
    dylib.setFileName(dll);
    if(!dylib.load()){
        QMessageBox::information(nullptr,"Note",dylib.errorString());
        return false;
    }else{
        funcPtrs["bubbleSort"] = dylib.resolve("bubbleSort");
        funcPtrs["test"] = dylib.resolve("test");
        return true;
    }
}

QHash<QString, QFunctionPointer> DllManager::getAllFuncPtrs() const
{
    return funcPtrs;
}

QFunctionPointer DllManager::getBubble()
{
    return dylib.resolve("bubbleSort");
}

DllManager::~DllManager()
{
    dylib.unload();
}
