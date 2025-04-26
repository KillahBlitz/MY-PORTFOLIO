import dash
from dash import dcc, html
import plotly.express as px
import pandas as pd
import numpy as np

app = dash.Dash(__name__)

np.random.seed(42)
df = pd.DataFrame({
    'x': np.random.randn(100),
    'y': np.random.randn(100),
    'category': np.random.choice(['A', 'B', 'C'], 100)
})

app.layout = html.Div([
    html.H1("Interactive Dashboard - Dash"),
    dcc.Dropdown(
        id='dropdown-category',
        options=[{'label': i, 'value': i} for i in df['category'].unique()],
        value='A',
        clearable=False
    ),
    dcc.Graph(id='scatter-plot')
])

@app.callback(
    dash.dependencies.Output('scatter-plot', 'figure'),
    [dash.dependencies.Input('dropdown-category', 'value')]
)
def update_graph(selected_category):
    filtered_df = df[df['category'] == selected_category]
    fig = px.scatter(filtered_df, x='x', y='y', title=f"Category: {selected_category}")
    return fig

if __name__ == '__main__':
    app.run_server(debug=True)


