#!/usr/bin/env python
# coding: utf-8

# ![NEURONA.png](attachment:NEURONA.png)

# ![NEURO2.png](attachment:NEURO2.png)

# In[67]:


import math
import random

class Neurona():
    def __init__(self):
        random.seed(1) #semilla
        self.pesos = [random.uniform(-1,1),random.uniform(-1,1),random.uniform(-1,1)]
        self.bias = random.uniform(-1,1)
        
    def __sumatoria(self,neurona_entrada):
        suma = 0
        for indice, neurona_entrada in enumerate(neurona_entrada):
            suma += self.pesos[indice] * neurona_entrada
        return suma
    
    def __sigmoide(self,suma):
        return 1 / (1 + math.exp(-suma))
    
    def respuesta(self,neurona_entrada):
        suma = self.__sumatoria(neurona_entrada)
        neurona_respuesta = self.__sigmoide(suma) + self.bias
        return neurona_respuesta
    
    def __gradiente(self,neurona_respuesta):
        return neurona_respuesta * (1-neurona_respuesta)
    
  

    def entrenamiento(self,ejemplos,epocas):
        for iteracion in range(epocas):
            for ejemplo in ejemplos:
                prediccion = self.respuesta(ejemplo["entradas"])
                error = ejemplo["salida"]-prediccion
                
                for indice in range(len(self.pesos)):
                    neurona_entrada = ejemplo["entradas"][indice]
                    ajustar_peso =  neurona_entrada * error * self.__gradiente(prediccion)
                    
                    self.pesos[indice] += ajustar_peso
                
                self.bias += error * self.__gradiente(prediccion)
                    
    
neurona1 = Neurona()
print("pesos" + str(neurona1.pesos))


        
   
        


        

ejemplos = [{"entradas": [0,0,1],"salida":1},
           {"entradas": [1,0,0],"salida":0},
           {"entradas": [0,1,0],"salida":0},
           {"entradas": [1,1,1],"salida":1},
           {"entradas": [0,1,1],"salida":1}]
    

neurona1.entrenamiento(ejemplos, epocas= 200)
print("Nuevos pesos: " + str(neurona1.pesos))

examen = [0,0,0]
valor_predecido = neurona1.respuesta(examen)
print("respuesta: " + str(valor_predecido))


# ![image.png](attachment:image.png)

# ![image.png](attachment:image.png)

# ![image.png](attachment:image.png)

# 
# ![image.png](attachment:image.png)

# 
# ![image.png](attachment:image.png)

# ![image.png](attachment:image.png)

# In[ ]:




