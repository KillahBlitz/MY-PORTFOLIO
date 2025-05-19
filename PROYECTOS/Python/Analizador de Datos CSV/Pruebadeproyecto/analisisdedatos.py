import sys
from PySide6.QtWidgets import QApplication, QWidget, QFileDialog, QMessageBox, QVBoxLayout, QLabel
from ui_form import Ui_AnalisisdeDatos

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

        self.ui.buttoncsv.setText("Cargar CSV")
        self.ui.buttoncsv.clicked.connect(self.cargar_csv)


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
                print("DataFrame limpio:")
                print(df_clean.head())
                # 5. Imprimir gráfica
                self.imprimir_grafica(df_clean, namearch)


            #manejo de algun error que se presente el cargar el archivo CSV
            except Exception as e:
                QMessageBox.critical(self, "Error", f"No se pudo cargar el archivo:\n{e}") #mensaje de error


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
