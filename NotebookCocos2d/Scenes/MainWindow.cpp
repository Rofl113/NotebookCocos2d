#include "MainWindow.h"
// Common
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
{
	m_ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete m_ui;
}

QtWidgetCocos2d* MainWindow::getViewCore() const
{
	return m_ui->openGLWidget;
}
