#pragma once
#include <QMainWindow>

namespace Ui { class MainWindow; }

class QtWidgetCocos2d;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	QtWidgetCocos2d* getViewCore() const;

private:
	Ui::MainWindow* m_ui = nullptr;
};
