#include "interactiveinput.h"
#include "ui_interactiveinput.h"

InteractiveInput::InteractiveInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InteractiveInput)
{
    ui->setupUi(this);
}

InteractiveInput::~InteractiveInput()
{
    delete ui;
}

