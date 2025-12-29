#include "FITKStaticStruPostVTK.h"
#include <QFile>

namespace Interface
{
    FITKStaticStruPostVTK::FITKStaticStruPostVTK(StruPostFileType type) :
        FITKAbstractStructuralPostVTK(type)
    {
    }
    FITKStaticStruPostVTK::~FITKStaticStruPostVTK()
    {
    }
    StruPostType FITKStaticStruPostVTK::getPostStructualType()
    {
        //静力分析类型
        return SPTStatic;
    }

    void FITKStaticStruPostVTK::setFile(const QString & file)
    {
        if (!QFile::exists(file)) return;
        _fileName = file;
        this->setInputFile(file);

        // 初始化显示分组All。
        this->resetDisplayGroup();
    }

}



