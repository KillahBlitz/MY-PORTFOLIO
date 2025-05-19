# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'form.ui'
##
## Created by: Qt User Interface Compiler version 6.9.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QHBoxLayout, QLabel, QPushButton,
    QSizePolicy, QWidget)

class Ui_AnalisisdeDatos(object):
    def setupUi(self, AnalisisdeDatos):
        if not AnalisisdeDatos.objectName():
            AnalisisdeDatos.setObjectName(u"AnalisisdeDatos")
        AnalisisdeDatos.resize(1432, 636)
        self.LabelTitle = QLabel(AnalisisdeDatos)
        self.LabelTitle.setObjectName(u"LabelTitle")
        self.LabelTitle.setGeometry(QRect(40, 20, 251, 41))
        font = QFont()
        font.setFamilies([u"MS Outlook"])
        font.setPointSize(12)
        self.LabelTitle.setFont(font)
        self.widgetGrafica = QWidget(AnalisisdeDatos)
        self.widgetGrafica.setObjectName(u"widgetGrafica")
        self.widgetGrafica.setGeometry(QRect(40, 60, 1051, 421))
        self.horizontalLayoutWidget = QWidget(AnalisisdeDatos)
        self.horizontalLayoutWidget.setObjectName(u"horizontalLayoutWidget")
        self.horizontalLayoutWidget.setGeometry(QRect(40, 530, 451, 51))
        self.horizontalLayout = QHBoxLayout(self.horizontalLayoutWidget)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.buttoncsv = QPushButton(self.horizontalLayoutWidget)
        self.buttoncsv.setObjectName(u"buttoncsv")

        self.horizontalLayout.addWidget(self.buttoncsv)

        self.buttoncsv_5 = QPushButton(self.horizontalLayoutWidget)
        self.buttoncsv_5.setObjectName(u"buttoncsv_5")

        self.horizontalLayout.addWidget(self.buttoncsv_5)

        self.buttoncsv_4 = QPushButton(self.horizontalLayoutWidget)
        self.buttoncsv_4.setObjectName(u"buttoncsv_4")

        self.horizontalLayout.addWidget(self.buttoncsv_4)

        self.buttoncsv_3 = QPushButton(self.horizontalLayoutWidget)
        self.buttoncsv_3.setObjectName(u"buttoncsv_3")

        self.horizontalLayout.addWidget(self.buttoncsv_3)

        self.buttoncsv_2 = QPushButton(self.horizontalLayoutWidget)
        self.buttoncsv_2.setObjectName(u"buttoncsv_2")

        self.horizontalLayout.addWidget(self.buttoncsv_2)


        self.retranslateUi(AnalisisdeDatos)

        QMetaObject.connectSlotsByName(AnalisisdeDatos)
    # setupUi

    def retranslateUi(self, AnalisisdeDatos):
        AnalisisdeDatos.setWindowTitle(QCoreApplication.translate("AnalisisdeDatos", u"AnalisisdeDatos", None))
        self.LabelTitle.setText(QCoreApplication.translate("AnalisisdeDatos", u"Vizualizacion de datos en grafica", None))
        self.buttoncsv.setText(QCoreApplication.translate("AnalisisdeDatos", u"Cargar CSV", None))
        self.buttoncsv_5.setText(QCoreApplication.translate("AnalisisdeDatos", u"Graficar", None))
        self.buttoncsv_4.setText(QCoreApplication.translate("AnalisisdeDatos", u"Graficar", None))
        self.buttoncsv_3.setText(QCoreApplication.translate("AnalisisdeDatos", u"Graficar", None))
        self.buttoncsv_2.setText(QCoreApplication.translate("AnalisisdeDatos", u"Graficar", None))
    # retranslateUi

