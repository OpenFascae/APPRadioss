#include "GUIInitialFieldAXISDialog.h"
#include "ui_GUIInitialFieldAXISDialog.h"
#include "FITK_Kernel/FITKCore/FITKOperatorRepo.h"
#include "FITK_Kernel/FITKCore/FITKActionOperator.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Interface/FITKInterfaceModel/FITKComponentManager.h"
#include "FITK_Interface/FITKInterfaceModel/FITKModelSet.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossCase.h"
#include "FITK_Component/FITKRadiossData/FITKAbstractInitialField.h"
#include "FITK_Component/FITKRadiossData/FITKInitialField.h"
#include "OperatorsInterface/GraphEventOperator.h"
#include <QAction>
#include <QMessageBox>

namespace GUI
{
    GUIInitialFieldAXISDialog::GUIInitialFieldAXISDialog(Radioss::FITKInitialFieldAxis* obj, Core::FITKActionOperator* oper, QWidget* parent/* = nullptr*/)
        : Core::FITKDialog(parent), _obj(obj), _oper(oper), _ui(new Ui::GUIInitialFieldAXISDialog())
    {
        _ui->setupUi(this);
        //设置对话框关闭时自动删除 去掉问号
        setAttribute(Qt::WA_DeleteOnClose);
        setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
        //创建标志
        _isCreate = false;
        //获取RadiossCase
        Radioss::FITKRadiossCase* caseObj = FITKAPP->getGlobalData()->
            getPhysicsData<Radioss::FITKRadiossCase>();
        if (caseObj == nullptr) return;
        //获取管理器
        _mgr = caseObj->getInitialFieldManager();
        this->initWidget();
        this->init();
    }

    GUIInitialFieldAXISDialog::GUIInitialFieldAXISDialog(Core::FITKActionOperator * oper, QWidget * parent)
        : Core::FITKDialog(parent), _oper(oper), _ui(new Ui::GUIInitialFieldAXISDialog())
    {
        _ui->setupUi(this);
        //设置对话框关闭时自动删除 去掉问号
        setAttribute(Qt::WA_DeleteOnClose);
        setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
        //创建标志
        _isCreate = true;
        _obj = new Radioss::FITKInitialFieldAxis;
        //获取RadiossCase
        Radioss::FITKRadiossCase* caseObj = FITKAPP->getGlobalData()->
            getPhysicsData<Radioss::FITKRadiossCase>();
        if (caseObj == nullptr) return;
        //获取管理器
        _mgr = caseObj->getInitialFieldManager();
        this->initWidget();
        this->init();
    }

    GUIInitialFieldAXISDialog::~GUIInitialFieldAXISDialog()
    {
        // 清除界面
        if (_ui != nullptr) delete _ui;
        _ui = nullptr;
    }

    void GUIInitialFieldAXISDialog::init()
    {
        if (_obj == nullptr || _mgr == nullptr) return;
        //获取参数
        int nodeID = _obj->getSetID();
        double velocity[3] = { 0.0, 0.0, 0.0 };
        velocity[0] = _obj->getValue(0);
        velocity[1] = _obj->getValue(1);
        velocity[2] = _obj->getValue(2);
        QString dir = _obj->getDir();
        int frameID = _obj->getFrameID();
        double vr = _obj->getVr();
        //设置名称
        if (_isCreate)
            _ui->lineEdit_Name->setText(_mgr->checkName("InitialField-1"));
        else
            _ui->lineEdit_Name->setText(_obj->getDataObjectName());
        //设置界面参数
        _ui->widgetSet->findNodeGroup(nodeID);
        int index = _ui->comboBox_Dir->findText(dir);
        _ui->comboBox_Dir->setCurrentIndex(index);
        index = _ui->comboBox_FrameID->findData(frameID);
        _ui->comboBox_FrameID->setCurrentIndex(index);
        _ui->lineEdit_Vr->setText(QString::number(vr));
        _ui->lineEditVX->setText(QString::number(velocity[0]));
        _ui->lineEditVY->setText(QString::number(velocity[1]));
        _ui->lineEditVZ->setText(QString::number(velocity[2]));
    }

    void GUIInitialFieldAXISDialog::on_pushButton_OK_clicked()
    {
        //点击确定按键动作
        if (!_obj || !_oper) return;
        if (_isCreate)
        {
            if (!this->createObjData())
                return;
        }
        else
        {
            if (!this->editObjData())
                return;
        }
        _oper->execProfession();
        this->accept();
    }

    void GUIInitialFieldAXISDialog::on_pushButton_Cancel_clicked()
    {
        //点击取消按键动作
        this->reject();
    }

    void GUIInitialFieldAXISDialog::initWidget()
    {
        //开启信号拦截
        this->blockSignals(true);
        //初始化组件
        this->initFrameComboBox();
        //初始化
        _ui->comboBox_Dir->addItems({ "X", "Y", "Z" });
        _ui->widgetSet->setWidgetGroupType(WidgetGroupType::Set_Node);
        _ui->widgetSet->setFirstNodeGroup(tr("None"), 0);
        _ui->lineEdit_Type->setText("AXIS");
        _ui->lineEdit_KeyWord->setText(Radioss::FITKInitialFieldAxis::GetFITKInitialFieldAxisRadiossKeyWord());
        //关闭信号拦截
        this->blockSignals(false);
    }

    void GUIInitialFieldAXISDialog::initFrameComboBox()
    {
        _ui->comboBox_FrameID->addItem("None", -1);
    }

    bool GUIInitialFieldAXISDialog::createObjData()
    {
        if (!_mgr || !_oper || !_obj) return false;

        //获取板名称-查重处理
        QString name = _ui->lineEdit_Name->text();
        if (_mgr->getDataByName(name)) {
            QMessageBox::warning(this, "", tr("\"%1\" already exists and cannot be overwritten.").arg(name), QMessageBox::Ok);
            return false;
        }
        //设置名称
        _obj->setDataObjectName(name);
        //设置界面数据
        this->getDataFormWidget();
        //设置数据
        _mgr->appendDataObj(_obj);
        _oper->setArgs("objID", _obj->getDataObjectID());
        return true;
    }

    bool GUIInitialFieldAXISDialog::editObjData()
    {
        if (!_mgr || !_oper || !_obj) return false;

        //获取板名称-查重处理
        QString name = _ui->lineEdit_Name->text();
        //名称重复判断
        if (name != _obj->getDataObjectName())
            if (_mgr->getDataByName(name)) {
                QMessageBox::warning(this, "", tr("\"%1\" already exists and cannot be overwritten.").arg(name), QMessageBox::Ok);
                return false;
            }
        //设置名称
        _obj->setDataObjectName(name);
        //设置界面数据
        this->getDataFormWidget();
        _oper->setArgs("objID", _obj->getDataObjectID());
        return true;
    }

    void GUIInitialFieldAXISDialog::getDataFormWidget()
    {
        if (!_obj) return;
        //获取参数
        int nodeID = _ui->widgetSet->getNodeGroupId();
        double velocity[3] = { 0.0,0.0,0.0 };
        velocity[0] = _ui->lineEditVX->text().toDouble();
        velocity[1] = _ui->lineEditVY->text().toDouble();
        velocity[2] = _ui->lineEditVZ->text().toDouble();
        double vr = _ui->lineEdit_Vr->text().toDouble();
        QString dir = _ui->comboBox_Dir->currentText();
        int frameID = _ui->comboBox_FrameID->currentData().toInt();
        //设置参数
        _obj->setSetID(nodeID);
        _obj->setValue(velocity);
        _obj->setVr(vr);
        _obj->setDir(dir);
        _obj->setFrameID(frameID);
    }

}