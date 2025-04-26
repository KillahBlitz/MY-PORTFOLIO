#programa para hacer colocao introduccion al IF

print("Vas a la cocina")
print("revisas la nevera")

SON = input("Hay leche en la nevera? S/N ")

if SON == 'S':
    print("pones la leche en la mesa")
    leche = 0
else:
    print("anotas comprar leche")
    leche = 1

print("revisas si tienes colacao en la lacena")

SON = input("Hay colacao en la lacena? S/N ")

if SON == 'S':
    print("pones el colacao en la mesa")
    colacao = 0
else:
    print("anotas comprar colacao")
    colacao = 1

if leche == 1 and colacao == 1:
    print("vas a la tienda compras leche y colacao")
elif leche == 1 and colacao == 0:
    print("vas a la tienda y compras leche")
elif leche == 0 and colacao == 1:
    print("vas a la tienda y compras colacao")

print("revisas si tienes vasos limpios")
SON = input("tienes vasos limpios? S/N ")

if SON == 'S':
    print("pones el vaso en la mesa")
    vaso = 0
else:
    vaso = 1

print("revisas si tienes cucharas limpias")
SON = input("tienes cucharas limpias? S/N ")

if SON == 'S':
    print("pones la cuchara en la mesa")
    cuchara = 0
else:
    cuchara = 1

if vaso == 1 and cuchara == 1:
    print("lavas el vaso y la cuchara")
elif vaso == 1 and cuchara == 0:
    print("lavas un vaso")
elif vaso == 0 and cuchara == 1:
    print("lavas una cuchara")

print("pones la leche en el vaso")
print("pones el colacao en la leche")
print("Mezclas con la cuchara")
print("puedes disfrutar de tu colacao")