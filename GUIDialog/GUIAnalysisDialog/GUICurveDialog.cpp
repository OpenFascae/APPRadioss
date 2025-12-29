#include "GUICurveDialog.h"
#include "ui_GUICurveDialog.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Kernel/FITKAppFramework/FITKComponents.h"

#include "FITK_Component/FITKRadiossData/FITKRadiossCase.h"
#include "FITK_Component/FITKPlotWindow/FITKPlotWindowsInterface.h"
#include "FITK_Component/FITKPlotWindow/FITKXYPlotWindow.h"
#include "FITK_Component/FITKPlotWindow/FITKXYPlotProperty.h"
#include "FITK_Component/FITKPlotWindow/FITKXYCurveDrawManager.h"

#include <QMessageBox>
#include <QSplitter>

namespace GUI
{
    GUICurveDialog::GUICurveDialog(Radioss::FITKNonLinerCurve* curve,QWidget* parent) : QDialog(parent)
        , _curve(curve),_ui(new Ui::GUICurveDialog)
    {
        _ui->setupUi(this);

        // 设置对话框关闭时自动删除
        setAttribute(Qt::WA_DeleteOnClose);
        //去掉问号
        setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

        if (_curve)_isCreate = false;

        this->init();
    }

    GUICurveDialog::~GUICurveDialog()
    {
        if (_ui) delete _ui;
        _ui = nullptr;
    }

    void GUICurveDialog::init()
    {
        Radioss::FITKNonLinerCurveManager *curveMgr = this->getNonLinerCurveMgr();
        if (!curveMgr)return;

        //初始化名称
        _ui->lineEditName->setText(curveMgr->checkName("Curve-1"));
        //初始化坐标表格
        this->clearTable();

        if (!_isCreate)
        {
            QList<Radioss::FITKNonLinerCurve::FITKNonLinerCurvePoint> points = _curve->getPoints();
            _ui->lineEditName->setText(_curve->getDataObjectName());
            int row = points.isEmpty() ? 1 : points.size();
            _ui->tableWidget->setRowCount(row);
            for (int i = 0; i < points.size(); ++i) {
                _ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(points[i].x), i));
                _ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(points[i].y), i));
            }
        }
        else {
            _ui->tableWidget->setRowCount(1);
            _ui->tableWidget->setItem(0, 0, new QTableWidgetItem("0"));
            _ui->tableWidget->setItem(0, 1, new QTableWidgetItem("0"));
        }
        //初始化图表
        Plot::FITKPlotWindowsInterface* plotWindows = FITKAPP->getComponents()->getComponentTByName<Plot::FITKPlotWindowsInterface>("FITKPlotWindowsInterface");
        if (!plotWindows) return;
        _xyPlotWindow = dynamic_cast<Plot::FITKXYPlotWindow*>(plotWindows->getWidget(0));
        //禁用放大缩小拖动
        Plot::FITKXYPlotProperty* propCurvePlot = _xyPlotWindow->getPlotProperty();
        if (!propCurvePlot) return;
        propCurvePlot->setPlotMagnifier(false);
        propCurvePlot->setPlotPanner(false);
        propCurvePlot->disToolBar();
        propCurvePlot->setAxisMaxMajor(0, 8);
        propCurvePlot->setAxisMaxMajor(2, 8);

        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(_xyPlotWindow);
        _ui->widgetPlot->setLayout(layout);

        //触发坐标系图表刷新
        emit _ui->pushButtonUpdate->clicked();
    }

    Radioss::FITKNonLinerCurveManager * GUICurveDialog::getNonLinerCurveMgr()
    {
        Radioss::FITKRadiossCase* caseObj = FITKAPP->getGlobalData()->getPhysicsData<Radioss::FITKRadiossCase>();
        if (!caseObj) return nullptr;
        return caseObj->getNonLinerCurveManager();
    }

    QList<Radioss::FITKNonLinerCurve::FITKNonLinerCurvePoint> GUICurveDialog::getPointList(bool& ok)
    {
        //强制失去焦点，否则获取数据有错误
        _ui->tableWidget->setEnabled(false);
        _ui->tableWidget->setEnabled(true);

        QList<Radioss::FITKNonLinerCurve::FITKNonLinerCurvePoint> list{};
        int row = _ui->tableWidget->rowCount();
   
        for (int i = 0; i < row; ++i)
        {
            auto itemX = _ui->tableWidget->item(i, 0);
            if(!itemX) continue;
            auto itemY = _ui->tableWidget->item(i, 1);
            if (!itemY) { 
                if (i == row - 1)
                    --row;
                continue; 
            }
            double x = itemX->text().toDouble(&ok);
            if (!ok) {
                if (i == row - 1)
                    --row;
                continue;
            }
            double y = itemY->text().toDouble(&ok);
            if (!ok) continue;
            list.append(Radioss::FITKNonLinerCurve::FITKNonLinerCurvePoint{ x,y });
        }
        ok = true;
        if (row==0 || list.size() != row) ok = false;
        return list;
    }

    void GUICurveDialog::clearTable()
    {
        //坐标表格
        _ui->tableWidget->clear();
        _ui->tableWidget->setColumnCount(2);
        _ui->tableWidget->setHorizontalHeaderLabels(QStringList{ "x","y" });
        _ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    void GUICurveDialog::on_pushButtonApply_clicked()
    {
        Radioss::FITKNonLinerCurveManager *curveMgr = this->getNonLinerCurveMgr();
        if (!curveMgr)return;
        QString name = _ui->lineEditName->text();
        if (name.isEmpty()||curveMgr->getDataByName(name)) {
            if (curveMgr->getDataByName(name) != _curve) {
                QMessageBox::warning(this, "Warning", QString("The name already exists"));
                return;
            }
        }

        bool ok = false;
        QList<Radioss::FITKNonLinerCurve::FITKNonLinerCurvePoint> list = getPointList(ok);
        if (!ok|| list.isEmpty()) {
            QMessageBox::warning(this, "Warning", QString("The current curve data is invalid"));
            return;
        }

        //保存数据
        if (_isCreate) {
            Radioss::FITKNonLinerCurve* curve = new Radioss::FITKNonLinerCurve();
            curve->setDataObjectName(name);
            for (auto point : list) {
                curve->addPoint(point);
            }
            curveMgr->appendDataObj(curve);
        }
        else {
            if (!_curve)return;
            _curve->setDataObjectName(name);
            _curve->removeAllPoints();
            for (auto point : list) {
                _curve->addPoint(point);
            }
        }
        this->accept();
    }

    void GUICurveDialog::on_pushButtonUpdate_clicked()
    {
        bool ok = false;
        QList<Radioss::FITKNonLinerCurve::FITKNonLinerCurvePoint> list = getPointList(ok);
        if (!ok) {
            QMessageBox::warning(this, "Warning", QString("The current curve data is invalid"));
            return;
        }

        QVector<double> xData{}, yData{};
        for (auto point : list) {
            xData.append(point.x);
            yData.append(point.y);
        }
        //刷新曲线

        QString name = _ui->lineEditName->text();
        if (!_xyPlotWindow)return;
        Plot::FITKXYCurveDrawManager* curveDraw = _xyPlotWindow->getCurveManager();
        if (!curveDraw)return;
        curveDraw->clear();
        Plot::FITKXYCurveDrawProp* curveData = new Plot::FITKXYCurveDrawProp;
        curveData->setData(name, xData, yData);
        curveDraw->appendGraphObj(curveData);
        _xyPlotWindow->updataCanvas();
    }

    void GUICurveDialog::on_pushButtonCancel_clicked()
    {
        this->reject();
    }
}