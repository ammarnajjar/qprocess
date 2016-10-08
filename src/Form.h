#ifndef FORM_H_ZXKTCR5S
#define FORM_H_ZXKTCR5S

#include <QDialog>
#include <QString>
#include <memory>
#include <QProcess>
#include <vector>
#include "ui_dialog.h"

class Form : public QDialog
{
	Q_OBJECT

	public:
		Form(QDialog* parent = 0);
		// virtual ~Form();

	private slots:
		void enable_goBtn(const QString& text);
		void execute_process();

	private:
		void fill_outputText(const QString& text);
		std::vector<std::shared_ptr<QProcess>> m_processes;
		Ui::Dialog ui;
};

#endif /* end of include guard: FORM_H_ZXKTCR5S */

