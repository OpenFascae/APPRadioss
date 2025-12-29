/**
 * 
 * @file   FITKAbaConnectorAssignment.h
 * @brief  连接器截面赋予类
 * @author LiJin (1003680421@qq.com)
 * @date   2024-06-20
 * 
 */
#ifndef FITKABACONNECTORASSIGNMENT_H
#define FITKABACONNECTORASSIGNMENT_H
#include "FITK_Interface/FITKInterfacePhysics/FITKSectionAssign.h"
#include "FITKInterfaceStructuralAPI.h"


namespace Interface {

class FITKInterfaceStructuralAPI FITKAbaConnectorAssignment: public FITKSectionAssign
{
    Q_OBJECT
    FITKCLASS(Interface, FITKAbaConnectorAssignment)
public:
    FITKAbaConnectorAssignment() = default;
    ~FITKAbaConnectorAssignment() = default;
    virtual QString getSectionType() override;
    bool copy(FITKAbstractDataObject* obj) override;
    int getCsysId1() const;
    void setCsysId1(int newCsysId1);
    int getCsysId2() const;
    void setCsysId2(int newCsysId2);

protected:
    virtual FITKAbstractDataObject* getSectionObj() override;

private:
    int m_csysId1{0};
    int m_csysId2{0};
};
}
#endif // FITKABACONNECTORASSIGNMENT_H
