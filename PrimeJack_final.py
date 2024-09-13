import random

# Mensaje de bienvenida
print("********************************")
print("        ¡Bienvenido a PrimeJack!")
print("********************************\n")

# Solicitar la cantidad de jugadores
n = int(input("¿Cuántos jugadores participarán? "))

# Variables para almacenar el mejor puntaje y el ganador
mejor_puntaje = 0
ganador = None
empate = False

# Ciclo para manejar los turnos de cada jugador
for jugador in range(1, n + 1):
    print(f"\nTurno del Jugador {jugador}")
    puntaje = 0
    primer_lanzamiento = True
    seguir_jugando = True

    # Ciclo interno para los lanzamientos de un jugador
    while seguir_jugando:
        # Lanzamiento de los dados
        input("Presiona Enter para lanzar los dados...")
        dado1 = random.randint(1, 6)
        dado2 = random.randint(1, 6)
        print(f"Lanzaste {dado1} y {dado2}")

        # Caso de lanzar dos números iguales en el primer lanzamiento
        if primer_lanzamiento and dado1 == dado2:
            if dado1 == 6:
                opcion = input("¿Deseas 1) seguir normalmente, 2) dividir tu lanzamiento o 3) realizar un último lanzamiento con un dado? (1/2/3): ")
                if opcion == '2':
                    print("Lanzamiento 1 con tres dados:")
                    input("Presiona Enter para lanzar tres dados...")
                    dado1_1 = random.randint(1, 6)
                    dado1_2 = random.randint(1, 6)
                    dado1_3 = random.randint(1, 6)
                    lanzamiento1 = dado1_1 + dado1_2 + dado1_3
                    puntaje_total_1 = lanzamiento1 + dado1
                    print(f"Lanzaste {dado1_1}, {dado1_2}, {dado1_3} y tu puntaje total es: {puntaje_total_1}")

                    print("Lanzamiento 2 con tres dados:")
                    input("Presiona Enter para lanzar tres dados...")
                    dado2_1 = random.randint(1, 6)
                    dado2_2 = random.randint(1, 6)
                    dado2_3 = random.randint(1, 6)
                    lanzamiento2 = dado2_1 + dado2_2 + dado2_3
                    puntaje_total_2 = lanzamiento2 + dado1
                    print(f"Lanzaste {dado2_1}, {dado2_2}, {dado2_3} y tu puntaje total es: {puntaje_total_2}")

                    puntaje = max(puntaje_total_1, puntaje_total_2)
                    print(f"Tu mejor puntaje es: {puntaje}")
                    break
                elif opcion == '3':
                    input("Presiona Enter para lanzar un dado...")
                    dado_unico = random.randint(1, 6)
                    puntaje = 12 + dado_unico  # Sumar el valor del dado al puntaje
                    print(f"Lanzaste {dado_unico} y tu puntaje final es: {puntaje}")
                    break
            else:
                opcion = input("¿Deseas 1) seguir normalmente o 2) dividir tu lanzamiento? (1/2): ")
                if opcion == '2':
                    print("Lanzamiento 1 con tres dados:")
                    input("Presiona Enter para lanzar tres dados...")
                    dado1_1 = random.randint(1, 6)
                    dado1_2 = random.randint(1, 6)
                    dado1_3 = random.randint(1, 6)
                    lanzamiento1 = dado1_1 + dado1_2 + dado1_3
                    puntaje_total_1 = lanzamiento1 + dado1
                    print(f"Lanzaste {dado1_1}, {dado1_2}, {dado1_3} y tu puntaje total es: {puntaje_total_1}")

                    print("Lanzamiento 2 con tres dados:")
                    input("Presiona Enter para lanzar tres dados...")
                    dado2_1 = random.randint(1, 6)
                    dado2_2 = random.randint(1, 6)
                    dado2_3 = random.randint(1, 6)
                    lanzamiento2 = dado2_1 + dado2_2 + dado2_3
                    puntaje_total_2 = lanzamiento2 + dado1
                    print(f"Lanzaste {dado2_1}, {dado2_2}, {dado2_3} y tu puntaje total es: {puntaje_total_2}")

                    puntaje = max(puntaje_total_1, puntaje_total_2)
                    print(f"Tu mejor puntaje es: {puntaje}")
                    break

        # Acumulación del puntaje en los casos normales
        puntaje += dado1 + dado2
        print(f"Puntaje acumulado: {puntaje}")

        # Caso de pasar de 23 puntos
        if puntaje > 23:
            print("Te pasaste de 23, ¡has perdido!")
            puntaje = 0
            break

        # Preguntar si el jugador desea seguir lanzando
        if puntaje == 23 or input("¿Quieres seguir lanzando? (s/n): ").lower() != 's':
            break

        primer_lanzamiento = False

    # Verificación de si el puntaje actual es primo (sin funciones)
    es_primo_actual = True
    if puntaje <= 1:
        es_primo_actual = False
    else:
        for i in range(2, int(puntaje ** 0.5) + 1):
            if puntaje % i == 0:
                es_primo_actual = False
                break

    # Verificación de si el mejor puntaje es primo (sin funciones)
    es_primo_mejor = True
    if mejor_puntaje <= 1:
        es_primo_mejor = False
    else:
        for i in range(2, int(mejor_puntaje ** 0.5) + 1):
            if mejor_puntaje % i == 0:
                es_primo_mejor = False
                break

    # Comparar el puntaje del jugador actual con el mejor puntaje
    if puntaje > 0:
        if mejor_puntaje == 0:
            mejor_puntaje = puntaje
            ganador = jugador
            empate = False
        else:
            if puntaje == mejor_puntaje:
                empate = True
            elif es_primo_actual and es_primo_mejor:
                if puntaje > mejor_puntaje:
                    mejor_puntaje = puntaje
                    ganador = jugador
                    empate = False
            elif not es_primo_actual and not es_primo_mejor:
                if puntaje > mejor_puntaje:
                    mejor_puntaje = puntaje
                    ganador = jugador
                    empate = False
            elif es_primo_actual:
                mejor_puntaje = puntaje
                ganador = jugador
                empate = False

# Final del juego, mostrar resultado
if empate:
    print("\nEl juego ha terminado en empate.")
else:
    print(f"\nEl ganador es el Jugador {ganador} con un puntaje de {mejor_puntaje}.")
