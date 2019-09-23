#include "form_gui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	form_gui w;
	w.show();
	return a.exec();
}
