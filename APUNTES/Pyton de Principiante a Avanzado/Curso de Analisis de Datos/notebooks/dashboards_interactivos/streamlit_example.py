import streamlit as st
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

st.title('Interactive Dashboard - Streamlit')

st.sidebar.header('User Input Features')
num_points = st.sidebar.slider('Number of points', 10, 100, 50)

data = {'x': np.random.randn(num_points), 'y': np.random.randn(num_points)}
df = pd.DataFrame(data)

st.subheader('Scatter Plot')
plt.figure(figsize=(5, 3))
plt.scatter(df['x'], df['y'], color='red')
plt.title('Scatter Plot')
plt.grid()
st.pyplot(plt)
