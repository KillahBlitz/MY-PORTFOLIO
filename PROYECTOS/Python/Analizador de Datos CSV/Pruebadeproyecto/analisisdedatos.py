#librerias para diseño de la interfaz grafica
import sys #import de libreria para el manejo de archivos
from ui_form import Ui_AnalisisdeDatos #import de la interfaz grafica como tal
from PySide6.QtWidgets import QApplication, QWidget, QFileDialog, QMessageBox, QVBoxLayout #import de elementos graficos

#librerias empleadas para analisis de datos
import pandas as pd
#librerias para graficar
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure

#definicion de la clase principal que es la que contiene como tal la interfaz grafica pero pertenece al archivo .ui como el archhivo .py
class AnalisisdeDatos(QWidget):
    def __init__(self, parent=None): #constructor de la clase
        super().__init__(parent) #llamada del constructor de la clase padre
        self.ui = Ui_AnalisisdeDatos() #inicializo la interfaz grafica
        self.ui.setupUi(self) #configuracion de la interfaz grafica
        ###hasta aqui son configuraciones default que te proporciona el archivo .ui con QT###

        #inicializa los widgets que tienen almacenados elementos graficos que se ocupan en el programa
        #se ocultan hasta que se necesiten (metodo hide)
        self.ui.widgetResultados.hide() 
        self.ui.widgetopciones.hide()
        self.ui.widgetseleccion.hide()

        #cambiar de color los labels de la interfaz grafica
        self.ui.LabelMaximo.setStyleSheet("color: green;")
        self.ui.LabelMinimo.setStyleSheet("color: red;")
        self.ui.LabelM.setStyleSheet("color: yellow;")

        #Inicializacion de botones y elementos graficos que se ocupan al principio del programa con su funcion especifica
        self.ui.buttoncsv.setText("Cargar CSV") #se cambia el texto del boton, linea innecesaria pero ayuda a ver la iinicializacion del elemento
        self.ui.buttoncsv.clicked.connect(self.cargar_csv) #se conecta el boton con el metodo cargar_csv
        self.ui.buttonsalir.setText("Salir") #se cambia el texto del boton, linea innecesaria pero ayuda a ver la iinicializacion del elemento
        self.ui.buttonsalir.clicked.connect(self.close) #se conecta el boton con el close para cerrar el programa
        self.ui.buttonseleccion.setText("Seleccionar") #se cambia el texto del boton, linea innecesaria pero ayuda a ver la iinicializacion del elemento
        self.ui.buttonseleccion.clicked.connect(self.marcarseleccion) #se conecta el boton con el metodo marcarseleccion
        self.ui.buttonbusqueda.clicked.connect(self.recorteygraficacion) #se conecta el boton con el recorteygraficacion



    #funcion de cargar el archivo
    def cargar_csv(self):
        # Lista de etiquetas clave esperadas en nombres de columnas
        etiquetas_numericas = ["precio", "cantidad", "piezas", "monto", "total", "valor", "importe","price", "amount", "quantity", "pieces", "total", "value", "cost"]
        # Palabras clave para buscar columnas de máximos y mínimos
        etiquetas_high = ['high', 'alto', 'max', 'maximo']
        etiquetas_low = ['low', 'bajo', 'min', 'minimo']

        #abro el archivo y lo igualo a la variable archivo
        archivo, _ = QFileDialog.getOpenFileName(self, "Selecciona un archivo CSV", "", "CSV Files (*.csv)")
        global namearch 
        namearch = archivo.split("/")[-1] #obtengo el nombre del archivo
        if archivo: #pregunto si existe archivo
            try: #intento hacer el proceso de leer el archivo
                df = pd.read_csv(archivo) #con pandas leo el archivo
                global df_clean #defino un dataframe global para que se pueda usar en las siguientes funciones
                df_clean = pd.DataFrame()  # Inicializar df_clean como un DataFrame vacío

                # Buscar columna de fecha y crear df_clean
                for col in df.columns:
                    convertida = pd.to_datetime(df[col], errors='coerce') #intento convertir la columna a datetime
                    if convertida.notna().sum() > 0: #si la conversion es correcta
                        df_clean = pd.DataFrame({col: convertida}) #creo el df_clean
                        df_clean.rename(columns={col: "Date"}, inplace=True) #renombro la columna a Date
                        break #salgo del for

                # Encontrar la columna que habla sobre una cantidad
                columnacantidad = None #columna auxiliar
                for col in df.columns: #recorro las columnas de df
                    col_lower = col.lower() #guardo la columna en una variable
                    if any(etiqueta in col_lower for etiqueta in etiquetas_numericas): #comparo las etiquetas con el nombre de la columna
                        columnacantidad = col #si es asi se guarda en otra variable
                        df_clean['cantidad'] = pd.concat([df[columnacantidad].copy()], axis=1) #se concatena la columna a el df limpio
                        break #salgo del for

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
                for col in df_clean.columns: #entro en todas las columnas del nuevo df limpio
                    # Verifica si la columna es de tipo objeto (texto)
                    if df_clean[col].dtype == 'object': #pregunto si la columna es de tipo objeto
                        # Verifica si al menos un valor tiene coma
                        if df_clean[col].astype(str).str.contains(',').any(): #pregunto si tiene comas en los numeros
                            df_clean[col] = df_clean[col].str.replace(',', '', regex=False) #remplazo las comas por nada
                            # Convierte a numérico si es posible
                            df_clean[col] = pd.to_numeric(df_clean[col], errors='coerce')

                #Confirmar carga exitosa
                QMessageBox.information(self, "Éxito", f"Archivo cargado con {len(df_clean)} filas.")
                self.ui.widgetseleccion.show() #muestro el widget de seleccion
                #impresion en consola para consulta personal
                print("DataFrame limpio:") 
                print(df_clean.head())
                #Imprimir gráfica
                self.imprimir_grafica(df_clean, namearch)


            #manejo de algun error que se presente el cargar el archivo CSV
            except Exception as e:
                QMessageBox.critical(self, "Error", f"No se pudo cargar el archivo:\n{e}") #mensaje de error



    #funcion para marcar la seleccion si sera por año o por mes el analisis
    def marcarseleccion(self):
        global seleccion, anios, anio, meses, mes #defino variables globales para que se puedan usar en las siguientes funciones
        meses = ['Enero','febrero','Marzo','Abril','Mayo','Junio','Julio','Agosto','Septiembre','Octubre','Noviembre','Diciembre'] 
        anios = df_clean['Date'].dt.year.unique() #cargo solo los años que tiene el dataframe


        if(self.ui.radiobuttononeanio.isChecked()): #en caso de seleccionar por año
            #muestro el widget de opciones
            self.ui.widgetopciones.show()
            seleccion = 1 #guardo que se selecciono por año
            print("se selecciono por anio") #consulta de consola
            #limpiar el combobox de meses y anios para que no se repitan en la reseleccion
            self.ui.comboboxanio.clear()
            self.ui.comboboxmes.clear()
            #cambiar el texto del combobox de año
            self.ui.comboboxanio.setPlaceholderText("Seleccione un año")
            #cambiar el texto del combobox de meses
            self.ui.comboboxmes.setPlaceholderText("No se puede seleccionar mes")
            self.ui.comboboxanio.addItems(anios.astype(str).tolist()) #añado los años al combo box para que se puedan seleccionar
        elif(self.ui.radiobuttononemes.isChecked()): #en caso de seleccionar por mes
            #muestro el widget de opciones
            self.ui.widgetopciones.show()
            seleccion = 2 #guardo que se selecciono por mes
            print("se selecciono por mes") #consulta de consola
            #limpiar el combobox de meses y anios para que no se repitan en la reseleccion
            self.ui.comboboxanio.clear()
            self.ui.comboboxmes.clear()
            #cambiar el texto del combobox de meses
            self.ui.comboboxmes.setPlaceholderText("Seleccione un mes")
            #cambiar el texto del combobox de meses
            self.ui.comboboxanio.setPlaceholderText("Seleccione un año")
            self.ui.comboboxanio.addItems(anios.astype(str).tolist()) #añado los años al combo box para que se puedan seleccionar
            self.ui.comboboxmes.addItems(meses) #añado los meses al combo box para que se puedan seleccionar
        elif(self.ui.radiobuttonall.isChecked()):
            #muestro el widget de opciones
            self.ui.widgetopciones.show()
            seleccion = 0 #guardo que se selecciono todo el csv
            print("se pide analizar todo el CSV")
            #limpiar el combobox de meses y anios para que no se repitan en la reseleccion
            self.ui.comboboxanio.clear()
            self.ui.comboboxmes.clear()
            #cambiar el texto del combobox de meses
            self.ui.comboboxmes.setPlaceholderText("No se puede seleccionar mes")
            #cambiar el texto del combobox de año
            self.ui.comboboxanio.setPlaceholderText("No se puede seleccionar año")



    #funcion para recortar el dataframe y graficarlo
    def recorteygraficacion(self): 
        self.ui.widgetResultados.show() #muestro el widget para ver que pedira el usuario
        anio = self.ui.comboboxanio.currentText() #obtengo el año seleccionado
        mes = self.ui.comboboxmes.currentText() #obtengo el mes sleccionado
        nombres_semanas = ["primera", "segunda", "tercera", "cuarta", "quinta"] #defino los nombres de las semanas para un proceso posterior
        # Convertir el año y mes a enteros
        if(anio == ""):
            anio = 0
        else:
            anio = int(anio)
        if(mes == ""): #si el mes seleccionado es nulo
            mes = 0 #no ponemos mes porque no se selecciono absolutamente nada
        else: #caso contrario
            mes = meses.index(mes) + 1 #connvertimos el mes a su equivalente numerico

        if(seleccion == 1): #si se selecciono por año
            # Filtrar solo por el año seleccionado
            mes = 0 #no se pone un mes porque es una consulta por año
            df_new = df_clean[df_clean['Date'].dt.year == anio] #encuento el año solicitado
        elif(seleccion == 2): #si se selecciono por mes
            # Filtrar por año y mes exactos seleccionados
            df_new = df_clean[(df_clean['Date'].dt.year == anio) & (df_clean['Date'].dt.month == mes)] #encuentro el año y mes solicitado
        else:
            df_new = df_clean

        self.imprimir_grafica(df_new, namearch) #imprimo la grafica con el recorte solicitado 

        if(self.ui.checkmax.isChecked()): #si se selecciona el maximo 
            print("se selecciono el maximo") #consulta en consola
            max = df_new['cantidad'].max() #buscamos el maximo
            #recuperar el dia exacto de cuando fue el maximo
            fila_max = df_new.loc[df_new['cantidad'] == max].iloc[0] #se busca la fila donde se encontro el maximo
            fecha_max = fila_max['Date'] #se guarda la fecha de ese maximo
            dia_max = fecha_max.strftime('%Y-%m-%d') #se guarda el dia completo y exacto
            semana = self.obtener_semana_del_mes(dia_max) #se obtiene la semana del mes con otra funcion
            nombre_semana = nombres_semanas[semana - 1] #se asigna el nombre a la semana que se encontro
            nombre_mes = meses[fecha_max.month - 1] #se asigna el nombre al mes que se encontro

            #se imprime el resultado en la etiqueta de la interfaz grafica
            self.ui.LabelMaximo.setText(f"MAXIMO\nEl maximo de la grafica es: {max}\nFue el dia: {dia_max}\nFue en la {nombre_semana} semana de {nombre_mes}")
        else: #en caso de que no se consulte el maximo
            self.ui.LabelMaximo.setText(f"no se consulto el maximo")

        if(self.ui.checkmin.isChecked()): #si se selecciona el minimo
            print("se selecciono el minimo") #consulta de cosonla
            min = df_new['cantidad'].min() #buscamos el minimo
            #recuperar el dia exacto de cuando fue el minimo
            fila_min = df_new.loc[df_new['cantidad'] == min].iloc[0] #se busca la fila donde se encontro el minimo
            fecha_min = fila_min['Date'] #se guarda la fecha del minimo
            dia_min = fecha_min.strftime('%Y-%m-%d') #se guarda el dia completo y exacto
            semana = self.obtener_semana_del_mes(fecha_min) #se obtiene la semana del mes con otra funcion
            nombre_semana = nombres_semanas[semana - 1] #se asigna un nombre a la semana que se encontro
            nombre_mes = meses[fecha_min.month - 1] #se asigna un nombre al mes que se encontro

            #se imprime el resultado en la etiqueta de la interfaz grafica
            self.ui.LabelMinimo.setText(f"MINIMO\nEl minimo de la grafica es: {min}\nFue el dia: {dia_min}\nFue en la {nombre_semana} semana de {nombre_mes}")
        else: #en caso de que no se consulte el minimo
            self.ui.LabelMinimo.setText(f"No se consulto el minimo")

        if(self.ui.checkm.isChecked()): #si se selecciona la media y mediana 
            print("se selecciono media y mediana") #consulta de consola
            media = df_new['cantidad'].mean() #buscamos la media 
            mediana = df_new['cantidad'].median() #buscamos la mediana

            #se imprimen los resultados
            self.ui.LabelM.setText(f"MEDIA Y MEDIANA\nLa media es: {media} \nLa mediana es: {mediana}")
        else: #en caso de que no se consulte la media y mediana
            self.ui.LabelM.setText(f"No se consulto la media y la mediana")



    #funcion para obtener que semana del mes fue la que acontecio el evento
    def obtener_semana_del_mes(self, fecha): 
        if isinstance(fecha, str): #si el dato mandado es un string
            fecha = pd.to_datetime(fecha) #entonces lo convierto a tipo datetime
        dia = fecha.day #obtengo el dia de la fecha
        return (dia - 1) // 7 + 1 #hago una operacion para obtener la semana del mes



    #funcion para imprimir la grafica
    def imprimir_grafica(self, df, namearch):
        # Eliminar el layout anterior si existe
        layout_viejo = self.ui.widgetGrafica.layout()
        if layout_viejo is not None: # Verifica si hay un layout existente
            while layout_viejo.count(): # Elimina todos los widgets del layout
                item = layout_viejo.takeAt(0) # Toma el primer widget del layout
                widget = item.widget() # Obtiene el widget
                if widget is not None: # Verifica si el widget no es None
                    widget.setParent(None) # Libera el widget
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


#funcion principal para correr el programa
if __name__ == "__main__":
    app = QApplication(sys.argv)
    widget = AnalisisdeDatos()
    widget.show()
    sys.exit(app.exec())
