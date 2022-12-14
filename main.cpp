#include <QApplication>

#include <pqPVApplicationCore.h>

#include "ParaViewMainWindow.h"

int main(int argc, char* argv[])
{
	QApplication::setApplicationName("qtguitest");
	QApplication::setApplicationVersion("0.0.1");
	QApplication::setOrganizationName("APM");

	QApplication app(argc, argv);

	setlocale(LC_NUMERIC, "C");
	QLocale::setDefault(QLocale::c());

	pqPVApplicationCore appCore(argc, argv, true, nullptr);

	ParaViewMainWindow w;

	w.show();

	return app.exec();
}
