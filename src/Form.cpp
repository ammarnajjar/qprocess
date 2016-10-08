#include "Form.h"
#include <QRegExp>

Form::Form(QDialog* parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.goBtn, SIGNAL(clicked()),
			this, SLOT(execute_process()));

	QObject::connect(ui.cmdLine, SIGNAL(textChanged(const QString&)),
			this, SLOT(enable_goBtn(const QString&)));
}

// Form::~Form() { }

void Form::enable_goBtn(const QString& text)
{
	if (text != "") {
		ui.goBtn->setEnabled(true);
	} else {
		ui.goBtn->setEnabled(false);
	}
}

void Form::execute_process()
{
	ui.outputText->setPlainText("");
	std::shared_ptr<QProcess> process = std::make_shared<QProcess>();
	m_processes.push_back(process);

	QString command = ui.cmdLine->text().trimmed();
	QStringList cmd_list = command.split(" ");
	QString program = cmd_list[0];
	QStringList arguments;
	for (int i = 1; i < cmd_list.size(); ++i) {
		arguments.append(cmd_list[i]);
		fill_outputText(cmd_list[i]);
		fill_outputText("\n");
	}

	process->start(program, arguments);
	process->waitForFinished();
	fill_outputText(process->readAllStandardOutput());
	fill_outputText(process->readAllStandardError());
}

void Form::fill_outputText(const QString& text)
{
    ui.outputText->setPlainText(ui.outputText->toPlainText() + text);
}
