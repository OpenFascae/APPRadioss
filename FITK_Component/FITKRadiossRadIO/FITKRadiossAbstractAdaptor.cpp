#include "FITKRadiossAbstractAdaptor.h"

namespace Radioss
{
    QHash<QString, std::function<FITKRadiossAbstractAdaptor*()>> FITKRadiossAbstractAdaptor::_adaptorCreators
        = QHash<QString, std::function<FITKRadiossAbstractAdaptor*()>>();

    FITKRadiossAbstractAdaptor::~FITKRadiossAbstractAdaptor()
    {
    }

    void FITKRadiossAbstractAdaptor::setFileReader(FITKRadiossRadReader * reader)
    {
        //设置读取器
        _reader = reader;
    }

    void FITKRadiossAbstractAdaptor::setFileWriter(FITKRadiossRadWriter * writer)
    {
        //设置写入器
        _writer = writer;
    }

    void FITKRadiossAbstractAdaptor::setCaseData(FITKRadiossCase * casedata)
    {
        //设置案例数据
        _caseData = casedata;
    }

    void FITKRadiossAbstractAdaptor::registerAdaptor(const QString &keywords, 
        std::function<FITKRadiossAbstractAdaptor*()> creator)
    {
        //注册适配器
        _adaptorCreators.insert(keywords.toUpper(), creator);
    }

    FITKRadiossAbstractAdaptor* FITKRadiossAbstractAdaptor::createAdaptor(const QString & keywords)
    {
        std::function<FITKRadiossAbstractAdaptor*()> creator = _adaptorCreators.value(keywords.toUpper());
        if (creator)
        {
            return creator();
        }
        return nullptr;
    }


}
