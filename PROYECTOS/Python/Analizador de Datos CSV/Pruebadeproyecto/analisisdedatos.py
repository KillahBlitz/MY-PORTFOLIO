import sys
from ui_form import Ui_AnalisisdeDatos
from PySide6.QtWidgets import QApplication, QWidget, QFileDialog, QMessageBox, QVBoxLayout

#librerias empleadas para analisis de datos
import pandas as pd
#librerias para graficar
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure

class AnalisisdeDatos(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.ui = Ui_AnalisisdeDatos()
        self.ui.setupUi(self)

        self.ui.widgetResultados.hide()
        self.ui.widgetopciones.hide()
        self.ui.widgetseleccion.hide()

        self.ui.buttoncsv.setText("Cargar CSV")
        self.ui.buttoncsv.clicked.connect(self.cargar_csv)
        self.ui.buttonsalir.setText("Salir")
        self.ui.buttonsalir.clicked.connect(self.close)
        self.ui.buttonseleccion.setText("Seleccionar")
        self.ui.buttonseleccion.clicked.connect(self.marcarseleccion)
        self.ui.buttonbusqueda.clicked.connect(self.recorteygraficacion)

    #funcion de cargar el archivo
    def cargar_csv(self):
        # Lista de etiquetas clave esperadas en nombres de columnas
        etiquetas_numericas = ["precio", "cantidad", "piezas", "monto", "total", "valor", "importe","price", "amount", "quantity", "pieces", "total", "value", "cost"]
        # Palabras clave para buscar columnas de máximos y mínimos
        etiquetas_high = ['high', 'alto', 'max', 'maximo']
        etiquetas_low = ['low', 'bajo', 'min', 'minimo']

        #abro el archivo y lo igualo a la variable archivo
        archivo, _ = QFileDialog.getOpenFileName(self, "Selecciona un archivo CSV", "", "CSV Files (*.csv)")
        namearch = archivo.split("/")[-1] #obtengo el nombre del archivo
        if archivo: #pregunto si existe archivo
            try: #intento hacer el proceso de leer el archivo
                df = pd.read_csv(archivo)
                global df_clean
                df_clean = pd.DataFrame()  # Inicializar df_clean como un DataFrame vacío

                # Buscar columna de fecha y crear df_clean
                for col in df.columns:
                    convertida = pd.to_datetime(df[col], errors='coerce')
                    if convertida.notna().sum() > 0:
                        df_clean = pd.DataFrame({col: convertida})
                        df_clean.rename(columns={col: "Date"}, inplace=True)
                        break

                columnacantidad = None #columna auxiliar
                for col in df.columns: #recorro las columnas de df
                    col_lower = col.lower() #guardo la columna en una variable
                    if any(etiqueta in col_lower for etiqueta in etiquetas_numericas): #comparo las etiquetas con el nombre de la columna
                        columnacantidad = col #si es asi se guarda en otra variable
                        df_clean['cantidad'] = pd.concat([df[columnacantidad].copy()], axis=1) #se concatena la columna a el df limpio
                        break #termino el for

                #se repite el proceso para encontrar la columna de maximos
                col_high = None
                for col in df.columns:
                    col_lower = col.lower()
                    if any(etiqueta in col_lower for etiqueta in etiquetas_high):
                        col_high = col
                        df_clean['maximo'] = pd.concat([df[col_high].copy()], axis=1)
                        break

                #se repite el proceso para encontra la columna de minimos
                col_low = None
                for col in df.columns:
                    col_lower = col.lower()
                    if any(etiqueta in col_lower for etiqueta in etiquetas_low):
                        col_low = col
                        df_clean['minimo'] = pd.concat([df[col_low].copy()], axis=1)
                        break

                #aqui limpio las comas de los datos numericos si lo tienen y los vuelvo variables numericas
                for col in df_clean.columns:
                    # Verifica si la columna es de tipo objeto (texto)
                    if df_clean[col].dtype == 'object':
                        # Verifica si al menos un valor tiene coma
                        if df_clean[col].astype(str).str.contains(',').any():
                            df_clean[col] = df_clean[col].str.replace(',', '', regex=False)
                            # Convierte a numérico si es posible
                            df_clean[col] = pd.to_numeric(df_clean[col], errors='coerce')

                # 4. Confirmar carga exitosa
                QMessageBox.information(self, "Éxito", f"Archivo cargado con {len(df_clean)} filas.")
                self.ui.widgetseleccion.show()
                print("DataFrame limpio:")
                print(df_clean.head())
                # 5. Imprimir gráfica
                self.imprimir_grafica(df_clean, namearch)


            #manejo de algun error que se presente el cargar el archivo CSV
            except Exception as e:
                QMessageBox.critical(self, "Error", f"No se pudo cargar el archivo:\n{e}") #mensaje de error



    def marcarseleccion(self):
        global seleccion, anios, anio, meses, mes
        meses = ['Enero','febrero','Marzo','Abril','Mayo','Junio','Julio','Agosto','Septiembre','Octubre','Noviembre','Diciembre']
        anios = df_clean['Date'].dt.year.unique()

        self.ui.widgetopciones.show()
        
        if(self.ui.radiobuttononeanio.isChecked()):
            seleccion = 1
            print("se selecciono por anio")
            #limpiar el combobox de meses y anios para que no se repitan en la reseleccion
            self.ui.comboboxanio.clear()
            self.ui.comboboxmes.clear()
            #cambiar el texto del combobox de meses
            self.ui.comboboxmes.setPlaceholderText("No se puede seleccionar mes")
            self.ui.comboboxanio.addItems(anios.astype(str).tolist())
        elif(self.ui.radiobuttononemes.isChecked()):
            seleccion = 2
            print("se selecciono por mes")
            #limpiar el combobox de meses y anios para que no se repitan en la reseleccion
            self.ui.comboboxanio.clear()
            self.ui.comboboxmes.clear()
            self.ui.comboboxmes.setPlaceholderText("Seleccione un mes")
            self.ui.comboboxanio.addItems(anios.astype(str).tolist())
            self.ui.comboboxmes.addItems(meses)





    def recorteygraficacion(self):
        self.ui.widgetResultados.show()
        anio = self.ui.comboboxanio.currentText()
        mes = self.ui.comboboxmes.currentText()
        print(seleccion)
        print(anios)
        print(meses)

        # Convertir el año y mes a enteros
        anio = int(anio)
        nombres_semanas = ["primera", "segunda", "tercera", "cuarta", "quinta"]
        if(mes == ""):
            mes = 0
        else:
            mes = meses.index(mes) + 1

        print(mes)
        print(anio)


        if(seleccion == 1):
            # Filtrar solo por el año seleccionado
            mes = 0
            df_new = df_clean[df_clean['Date'].dt.year == anio]
        else:
            # Filtrar por año y mes exactos seleccionados
            df_new = df_clean[(df_clean['Date'].dt.year == anio) & (df_clean['Date'].dt.month == mes)]

        self.imprimir_grafica(df_new, "recorte por anio")

        if(self.ui.checkmax.isChecked()):
            print("se selecciono el maximo")
            max = df_new['cantidad'].max()
            #recuperar el dia exacto de cuando fue el maximo
            fila_max = df_new.loc[df_new['cantidad'] == max].iloc[0]
            fecha_max = fila_max['Date']
            dia_max = fecha_max.strftime('%Y-%m-%d')
            semana = self.obtener_semana_del_mes(dia_max)
            nombre_semana = nombres_semanas[semana - 1]
            nombre_mes = meses[fecha_max.month - 1]

            self.ui.LabelMaximo.setText(f"MAXIMO\nEl maximo de la grafica es: {max}\nFue el dia: {dia_max}\nFue en la {nombre_semana} semana de {nombre_mes}")
        else:
            self.ui.LabelMaximo.setText(f"no se consulto el maximo")

        if(self.ui.checkmin.isChecked()):
            print("se selecciono el minimo")
            min = df_new['cantidad'].min()
            #recuperar el dia exacto de cuando fue el minimo
            fila_min = df_new.loc[df_new['cantidad'] == min].iloc[0]
            fecha_min = fila_min['Date']
            dia_min = fecha_min.strftime('%Y-%m-%d')
            semana = self.obtener_semana_del_mes(fecha_min)
            nombre_semana = nombres_semanas[semana - 1]
            nombre_mes = meses[fecha_min.month - 1]
            self.ui.LabelMinimo.setText(f"MINIMO\nEl minimo de la grafica es: {max}\nFue el dia: {dia_min}\nFue en la {nombre_semana} semana de {nombre_mes}")
        else:
            self.ui.LabelMinimo.setText(f"No se consulto el minimo")

        if(self.ui.checkm.isChecked()):
            print("se selecciono media y mediana")
            media = df_new['cantidad'].mean()
            mediana = df_new['cantidad'].median()
            self.ui.LabelM.setText(f"MEDIA Y MEDIANA\nLa media es: {media} \nLa mediana es: {mediana}")
        else:
            self.ui.LabelM.setText(f"No se consulto la media y la mediana")

    def obtener_semana_del_mes(self, fecha):
        if isinstance(fecha, str):
            fecha = pd.to_datetime(fecha)
        dia = fecha.day
        return (dia - 1) // 7 + 1

    #funcion para imprimir la grafica
    def imprimir_grafica(self, df, namearch):
        # Eliminar el layout anterior si existe
        layout_viejo = self.ui.widgetGrafica.layout()
        if layout_viejo is not None:
            while layout_viejo.count():
                item = layout_viejo.takeAt(0)
                widget = item.widget()
                if widget is not None:
                    widget.setParent(None)
            QWidget().setLayout(layout_viejo)  # Libera el layout viejo

        # Crear un nuevo layout limpio
        self.layout_grafica = QVBoxLayout()
        self.ui.widgetGrafica.setLayout(self.layout_grafica)

        # Crear figura y canvas de Matplotlib
        fig = Figure(figsize=(6, 4))
        canvas = FigureCanvas(fig)
        ax = fig.add_subplot(111)

        # Graficar la tendencia del valor en el tiempo
        ax.plot(df['Date'], df['cantidad'], color='blue', linewidth=2, marker='o', markersize=3)

        # Estilizar gráfica
        ax.set_title(namearch, fontsize=12)
        ax.set_xlabel("Fecha", fontsize=10)
        ax.set_ylabel("Cantidad", fontsize=10)
        ax.grid(True)
        fig.autofmt_xdate()  # Rotar fechas para mejor legibilidad

        # Agregar el canvas al layout del widgetGrafica
        self.layout_grafica.addWidget(canvas)



if __name__ == "__main__":
    app = QApplication(sys.argv)
    widget = AnalisisdeDatos()
    widget.show()
    sys.exit(app.exec())
