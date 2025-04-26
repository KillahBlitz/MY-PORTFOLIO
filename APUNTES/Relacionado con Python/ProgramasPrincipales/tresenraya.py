import PySimpleGUI as sui

PLAYER_ONE = "x"
PLAYER_TWO = "O"
turno_actual = PLAYER_ONE
working = True
# DICCIONARIO PARA GUARDAR LOS VALORES DE LOS BOTONES
button_states = {
    "-1-": "", "-2-": "", "-3-": "",
    "-4-": "", "-5-": "", "-6-": "",
    "-7-": "", "-8-": "", "-9-": ""
}


def change_turn(first, second, turno_actual):
    current_turn_x = turno_actual
    if current_turn_x == first:
        current_turn_x = second
        return current_turn_x
    else:
        current_turn_x = first
        return current_turn_x


# Limpia los botones
def clear_buttons_values(diccionary):
    for key in diccionary:
        diccionary[key] = ""


def clear_buttons(layout_x):
    for row in layout_x:
        for element in row:
            if isinstance(element, sui.Button) and element.Key != "-end-" and element.key != "-reboot-":
                window[element.Key].update(" ")


# Función para verificar al ganador
def check_winner(states, player):
    for pattern in win_patterns:
        if all(states[key] == player for key in pattern):
            return True
    return False


win_patterns = [
    ["-1-", "-2-", "-3-"],
    ["-4-", "-5-", "-6-"],
    ["-7-", "-8-", "-9-"],
    ["-1-", "-5-", "-9-"],

    ["-3-", "-5-", "-7-"],
    ["-1-", "-4-", "-7-"],
    ["-2-", "-5-", "-8-"],
    ["-3-", "-6-", "-9-"]
]

button_size = (7, 3)

layout = [
    [  # First Row
        sui.Button("", key="-1-", size=button_size),
        sui.Button("", key="-2-", size=button_size),
        sui.Button("", key="-3-", size=button_size)
    ],

    [  # Second Row
        sui.Button("", key="-4-", size=button_size),
        sui.Button("", key="-5-", size=button_size),
        sui.Button("", key="-6-", size=button_size)
    ],

    [  # Third Row
        sui.Button("", key="-7-", size=button_size),
        sui.Button("", key="-8-", size=button_size),
        sui.Button("", key="-9-", size=button_size)
    ],
    [sui.Button("S4L1R", key="-end-")],
    [sui.Button("R3B00T", key="-reboot-")]
]

window = sui.Window("Totito", layout)

while working:
    event, values = window.read()
    print(event)
    if event == sui.WIN_CLOSED or event == "-end-":  # Si se cierra la ventana, termina el bucle
        working = False
    elif event == "-reboot-":
        sui.popup("3L JU3G0 S3 HA R31N1C14D0")
        clear_buttons_values(button_states)
        clear_buttons(layout)

    if event in button_states and button_states[event] == "" and event != "-reboot-":
        # Actualizar el texto del botón y el estado en button_states
        window[event].update(text=turno_actual)
        button_states[event] = turno_actual  # Actualizar el diccionario

    window.Element(event).Update(text=turno_actual)
    if check_winner(button_states, turno_actual):
        sui.popup(f"¡{turno_actual} ha ganado!")
    turno_actual = change_turn(PLAYER_ONE, PLAYER_TWO, turno_actual)


window.close()  # Cierra la ventana al finalizar