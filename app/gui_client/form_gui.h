#ifndef __FORM_GUI_H
#define __FORM_GUI_H



#include <QtWidgets/QWidget>


#include "ui_form_gui.h"
#include "framework_file.h"
#include "hardware_file.h"


class form_gui : public QWidget
{
	Q_OBJECT
public:
	form_gui(QWidget *parent = 0);

public:
	Ui::Form ui;
	
	
protected:
	framework_file xfrm;
	hardware_file xhal;	
};


#endif


