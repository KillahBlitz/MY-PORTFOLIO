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
from PySide6.QtWidgets import (QApplication, QCheckBox, QComboBox, QLabel,
    QPushButton, QRadioButton, QSizePolicy, QVBoxLayout,
    QWidget)

class Ui_AnalisisdeDatos(object):
    def setupUi(self, AnalisisdeDatos):
        if not AnalisisdeDatos.objectName():
            AnalisisdeDatos.setObjectName(u"AnalisisdeDatos")
        AnalisisdeDatos.resize(1432, 720)
        self.LabelTitle = QLabel(AnalisisdeDatos)
        self.LabelTitle.setObjectName(u"LabelTitle")
        self.LabelTitle.setGeometry(QRect(40, 20, 251, 41))
        font = QFont()
        font.setFamilies([u"MS Outlook"])
        font.setPointSize(12)
        self.LabelTitle.setFont(font)
        self.widgetGrafica = QWidget(AnalisisdeDatos)
        self.widgetGrafica.setObjectName(u"widgetGrafica")
        self.widgetGrafica.setGeometry(QRect(40, 60, 981, 451))
        self.verticalLayoutWidget = QWidget(AnalisisdeDatos)
        self.verticalLayoutWidget.setObjectName(u"verticalLayoutWidget")
        self.verticalLayoutWidget.setGeometry(QRect(940, 590, 82, 71))
        self.verticalLayout = QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.buttoncsv = QPushButton(self.verticalLayoutWidget)
        self.buttoncsv.setObjectName(u"buttoncsv")

        self.verticalLayout.addWidget(self.buttoncsv)

        self.buttonsalir = QPushButton(self.verticalLayoutWidget)
        self.buttonsalir.setObjectName(u"buttonsalir")

        self.verticalLayout.addWidget(self.buttonsalir)

        self.widgetopciones = QWidget(AnalisisdeDatos)
        self.widgetopciones.setObjectName(u"widgetopciones")
        self.widgetopciones.setGeometry(QRect(290, 530, 601, 151))
        self.buttonbusqueda = QPushButton(self.widgetopciones)
        self.buttonbusqueda.setObjectName(u"buttonbusqueda")
        self.buttonbusqueda.setGeometry(QRect(520, 120, 81, 24))
        self.verticalLayoutWidget_3 = QWidget(self.widgetopciones)
        self.verticalLayoutWidget_3.setObjectName(u"verticalLayoutWidget_3")
        self.verticalLayoutWidget_3.setGeometry(QRect(290, 0, 201, 141))
        self.verticallayoutopciones = QVBoxLayout(self.verticalLayoutWidget_3)
        self.verticallayoutopciones.setObjectName(u"verticallayoutopciones")
        self.verticallayoutopciones.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_5 = QVBoxLayout()
        self.verticalLayout_5.setObjectName(u"verticalLayout_5")
        self.LabelFechas_4 = QLabel(self.verticalLayoutWidget_3)
        self.LabelFechas_4.setObjectName(u"LabelFechas_4")
        self.LabelFechas_4.setEnabled(False)
        self.LabelFechas_4.setFont(font)
        self.LabelFechas_4.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_5.addWidget(self.LabelFechas_4)

        self.checkmax = QCheckBox(self.verticalLayoutWidget_3)
        self.checkmax.setObjectName(u"checkmax")

        self.verticalLayout_5.addWidget(self.checkmax)

        self.checkmin = QCheckBox(self.verticalLayoutWidget_3)
        self.checkmin.setObjectName(u"checkmin")

        self.verticalLayout_5.addWidget(self.checkmin)

        self.checkm = QCheckBox(self.verticalLayoutWidget_3)
        self.checkm.setObjectName(u"checkm")

        self.verticalLayout_5.addWidget(self.checkm)


        self.verticallayoutopciones.addLayout(self.verticalLayout_5)

        self.verticalLayoutWidget_6 = QWidget(self.widgetopciones)
        self.verticalLayoutWidget_6.setObjectName(u"verticalLayoutWidget_6")
        self.verticalLayoutWidget_6.setGeometry(QRect(0, 0, 241, 141))
        self.verticallayoutseleccion = QVBoxLayout(self.verticalLayoutWidget_6)
        self.verticallayoutseleccion.setObjectName(u"verticallayoutseleccion")
        self.verticallayoutseleccion.setContentsMargins(0, 0, 0, 0)
        self.LabelFechas_5 = QLabel(self.verticalLayoutWidget_6)
        self.LabelFechas_5.setObjectName(u"LabelFechas_5")
        self.LabelFechas_5.setEnabled(False)
        self.LabelFechas_5.setFont(font)
        self.LabelFechas_5.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticallayoutseleccion.addWidget(self.LabelFechas_5)

        self.LabelFechas_6 = QLabel(self.verticalLayoutWidget_6)
        self.LabelFechas_6.setObjectName(u"LabelFechas_6")
        self.LabelFechas_6.setEnabled(False)
        self.LabelFechas_6.setFont(font)

        self.verticallayoutseleccion.addWidget(self.LabelFechas_6)

        self.comboboxanio = QComboBox(self.verticalLayoutWidget_6)
        self.comboboxanio.setObjectName(u"comboboxanio")

        self.verticallayoutseleccion.addWidget(self.comboboxanio)

        self.LabelFechas_7 = QLabel(self.verticalLayoutWidget_6)
        self.LabelFechas_7.setObjectName(u"LabelFechas_7")
        self.LabelFechas_7.setEnabled(False)
        self.LabelFechas_7.setFont(font)

        self.verticallayoutseleccion.addWidget(self.LabelFechas_7)

        self.comboboxmes = QComboBox(self.verticalLayoutWidget_6)
        self.comboboxmes.setObjectName(u"comboboxmes")

        self.verticallayoutseleccion.addWidget(self.comboboxmes)

        self.widgetseleccion = QWidget(AnalisisdeDatos)
        self.widgetseleccion.setObjectName(u"widgetseleccion")
        self.widgetseleccion.setGeometry(QRect(40, 530, 241, 141))
        self.verticalLayoutWidget_2 = QWidget(self.widgetseleccion)
        self.verticalLayoutWidget_2.setObjectName(u"verticalLayoutWidget_2")
        self.verticalLayoutWidget_2.setGeometry(QRect(0, 0, 241, 137))
        self.verticalLayout_2 = QVBoxLayout(self.verticalLayoutWidget_2)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.LabelFechas = QLabel(self.verticalLayoutWidget_2)
        self.LabelFechas.setObjectName(u"LabelFechas")
        self.LabelFechas.setEnabled(False)
        self.LabelFechas.setFont(font)
        self.LabelFechas.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_2.addWidget(self.LabelFechas)

        self.verticalLayout_6 = QVBoxLayout()
        self.verticalLayout_6.setObjectName(u"verticalLayout_6")
        self.radiobuttononeanio = QRadioButton(self.verticalLayoutWidget_2)
        self.radiobuttononeanio.setObjectName(u"radiobuttononeanio")

        self.verticalLayout_6.addWidget(self.radiobuttononeanio)

        self.radiobuttononemes = QRadioButton(self.verticalLayoutWidget_2)
        self.radiobuttononemes.setObjectName(u"radiobuttononemes")

        self.verticalLayout_6.addWidget(self.radiobuttononemes)

        self.buttonseleccion = QPushButton(self.verticalLayoutWidget_2)
        self.buttonseleccion.setObjectName(u"buttonseleccion")

        self.verticalLayout_6.addWidget(self.buttonseleccion)


        self.verticalLayout_2.addLayout(self.verticalLayout_6)

        self.widgetResultados = QWidget(AnalisisdeDatos)
        self.widgetResultados.setObjectName(u"widgetResultados")
        self.widgetResultados.setGeometry(QRect(1040, 70, 221, 441))
        self.LabelMaximo = QLabel(self.widgetResultados)
        self.LabelMaximo.setObjectName(u"LabelMaximo")
        self.LabelMaximo.setGeometry(QRect(0, 10, 221, 141))
        self.LabelMaximo.setAlignment(Qt.AlignmentFlag.AlignLeading|Qt.AlignmentFlag.AlignLeft|Qt.AlignmentFlag.AlignTop)
        self.LabelMinimo = QLabel(self.widgetResultados)
        self.LabelMinimo.setObjectName(u"LabelMinimo")
        self.LabelMinimo.setGeometry(QRect(0, 160, 221, 151))
        self.LabelMinimo.setAlignment(Qt.AlignmentFlag.AlignLeading|Qt.AlignmentFlag.AlignLeft|Qt.AlignmentFlag.AlignTop)
        self.LabelM = QLabel(self.widgetResultados)
        self.LabelM.setObjectName(u"LabelM")
        self.LabelM.setGeometry(QRect(0, 330, 221, 111))
        self.LabelM.setAlignment(Qt.AlignmentFlag.AlignLeading|Qt.AlignmentFlag.AlignLeft|Qt.AlignmentFlag.AlignTop)

        self.retranslateUi(AnalisisdeDatos)

        QMetaObject.connectSlotsByName(AnalisisdeDatos)
    # setupUi

    def retranslateUi(self, AnalisisdeDatos):
        AnalisisdeDatos.setWindowTitle(QCoreApplication.translate("AnalisisdeDatos", u"AnalisisdeDatos", None))
        self.LabelTitle.setText(QCoreApplication.translate("AnalisisdeDatos", u"Vizualizacion de datos en grafica", None))
        self.buttoncsv.setText(QCoreApplication.translate("AnalisisdeDatos", u"Cargar CSV", None))
        self.buttonsalir.setText(QCoreApplication.translate("AnalisisdeDatos", u"Salir", None))
        self.buttonbusqueda.setText(QCoreApplication.translate("AnalisisdeDatos", u"Aplicar", None))
        self.LabelFechas_4.setText(QCoreApplication.translate("AnalisisdeDatos", u"Selecciona que se busca", None))
        self.checkmax.setText(QCoreApplication.translate("AnalisisdeDatos", u"Mejor Pico", None))
        self.checkmin.setText(QCoreApplication.translate("AnalisisdeDatos", u"Peor Pico", None))
        self.checkm.setText(QCoreApplication.translate("AnalisisdeDatos", u"Media y Mediana", None))
        self.LabelFechas_5.setText(QCoreApplication.translate("AnalisisdeDatos", u"Seleccione el inicio del intervalo", None))
        self.LabelFechas_6.setText(QCoreApplication.translate("AnalisisdeDatos", u"a\u00f1o", None))
        self.comboboxanio.setPlaceholderText(QCoreApplication.translate("AnalisisdeDatos", u"Selecciona el a\u00f1o", None))
        self.LabelFechas_7.setText(QCoreApplication.translate("AnalisisdeDatos", u"mes", None))
        self.comboboxmes.setCurrentText("")
        self.comboboxmes.setPlaceholderText(QCoreApplication.translate("AnalisisdeDatos", u"Selecciona el mes", None))
        self.LabelFechas.setText(QCoreApplication.translate("AnalisisdeDatos", u"Seleccionar intervalo", None))
        self.radiobuttononeanio.setText(QCoreApplication.translate("AnalisisdeDatos", u"Por a\u00f1o", None))
        self.radiobuttononemes.setText(QCoreApplication.translate("AnalisisdeDatos", u"Por mes", None))
        self.buttonseleccion.setText(QCoreApplication.translate("AnalisisdeDatos", u"Aplicar", None))
        self.LabelMaximo.setText(QCoreApplication.translate("AnalisisdeDatos", u"Maximo:", None))
        self.LabelMinimo.setText(QCoreApplication.translate("AnalisisdeDatos", u"Minimo:", None))
        self.LabelM.setText(QCoreApplication.translate("AnalisisdeDatos", u"Media y Mediana:", None))
    # retranslateUi

