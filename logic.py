import pygame
import random
import sys

pygame.init()
ANCHO, ALTO = 800, 600
PANTALLA = pygame.display.set_mode((ANCHO, ALTO))
pygame.display.set_caption("Juego del Ahorcado")

BLANCO = (255, 255, 255)
NEGRO = (0, 0, 0)
ROJO = (255, 0, 0)
GAY = (128, 128, 128)

FUENTE = pygame.font.Font("C:\C\RubikDoodleShadow-Regular.ttf", 36)
FUENTE2 = pygame.font.Font("C:\C\RubikDoodleShadow-Regular.ttf", 16)
FUENTE3 = pygame.font.Font("C:\C\RubikDoodleShadow-Regular.ttf", 48)


def palabra_random():
    palabras = ["python", "prolog", "aristoteles", "compuerta", "paradoja", "negacion", "conjuncion"
                "disyuncion", "condicional", "morgan", "tautologia", "contradiccion", "silogismo", "jupyter", "pygame"]
    return random.choice(palabras)

def mostrar_tablero(palabra, letras_adivinadas):
    resultado = ""
    for letra in palabra:
        if letra in letras_adivinadas:
            resultado += letra + " "
        else:
            resultado += "_ "

    espacios = (ANCHO - FUENTE.size(resultado)[0]) // 2
    tablero_centralizado = " " * espacios + resultado.strip() + " " * espacios

    tablero_alt = ALTO - 150
    return tablero_centralizado, tablero_alt

def dibujar_ahorcado(intentos):
    ahorcado_y = ALTO // 4 - 50

    pygame.draw.line(PANTALLA, NEGRO, (ANCHO // 4, ahorcado_y), (ANCHO // 4, ahorcado_y + 300), 5)
    
    pygame.draw.line(PANTALLA, NEGRO, (ANCHO // 4, ahorcado_y), (ANCHO // 2, ahorcado_y), 5)
    pygame.draw.line(PANTALLA, NEGRO, (ANCHO // 2, ahorcado_y), (ANCHO // 2, ahorcado_y + 30), 5)

    if intentos >= 1:
        pygame.draw.circle(PANTALLA, NEGRO, (ANCHO // 2, ahorcado_y + 60), 30)  # Cabeza
    
    if intentos >= 2:
        pygame.draw.line(PANTALLA, NEGRO, (ANCHO // 2, ahorcado_y + 90), (ANCHO // 2, ahorcado_y + 170), 5)  
    
    if intentos >= 3:
        pygame.draw.line(PANTALLA, NEGRO, (ANCHO // 2, ahorcado_y + 110), (ANCHO // 2 - 20, ahorcado_y + 140), 5)  
    
    if intentos >= 4:
        pygame.draw.line(PANTALLA, NEGRO, (ANCHO // 2, ahorcado_y + 110), (ANCHO // 2 + 20, ahorcado_y + 140), 5) 
    
    if intentos >= 5:
        pygame.draw.line(PANTALLA, NEGRO, (ANCHO // 2, ahorcado_y + 170), (ANCHO // 2 - 20, ahorcado_y + 240), 5) 
    
    if intentos >= 6:
        pygame.draw.line(PANTALLA, NEGRO, (ANCHO // 2, ahorcado_y + 170), (ANCHO // 2 + 20, ahorcado_y + 240), 5) 
    
    if intentos >= 7:
        pygame.draw.line(PANTALLA, NEGRO, (ANCHO // 2 - 20, ahorcado_y + 240), (ANCHO // 2 - 30, ahorcado_y + 260), 5)  
    
    if intentos >= 8:
        pygame.draw.line(PANTALLA, NEGRO, (ANCHO // 2 + 20, ahorcado_y + 240), (ANCHO // 2 + 30, ahorcado_y + 260), 5)  

def mostrar_msj_salida():
    msj = "Presiona la tecla Esc para salir"
    msj_txt = FUENTE2.render(msj, True, NEGRO)
    PANTALLA.blit(msj_txt, (10, 10))

def pantalla_inicio():
    PANTALLA.fill((0, 255, 255))

    titulo = "Juego del Ahorcado"
    titulo_texto = FUENTE3.render(titulo, True, NEGRO)
    rect_titulo = titulo_texto.get_rect(center=(ANCHO // 2, ALTO // 4))
    PANTALLA.blit(titulo_texto, rect_titulo)

    pygame.draw.rect(PANTALLA, GAY, (ANCHO // 2 - 50, ALTO // 2, 100, 40))
    boton_txt = FUENTE2.render("Jugar", True, BLANCO)
    rect_boton = boton_txt.get_rect(center=(ANCHO // 2, ALTO // 2 + 20))
    PANTALLA.blit(boton_txt, rect_boton)

    pygame.display.flip()

    esperar_clic_salida()

def esperar_clic_salida():
    esperando = True
    while esperando:
        for evento in pygame.event.get():
            if evento.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif evento.type == pygame.MOUSEBUTTONDOWN:
                x, y = evento.pos
                if ANCHO // 2 - 50 <= x <= ANCHO // 2 + 50 and ALTO // 2 <= y <= ALTO // 2 + 40:
                    esperando = False

def felicitacion():
    PANTALLA.fill(BLANCO)

    m = "¡Felicidades! Has adivinado la palabra."

    f_m = pygame.font.Font("C:\C\RubikDoodleShadow-Regular.ttf", 20)
    m_txt = f_m.render(m, True, NEGRO)

    rect_m = m_txt.get_rect(center=(ANCHO // 2, ALTO // 2 - 50))
    PANTALLA.blit(m_txt, rect_m)

    pygame.display.flip()
    pygame.time.wait(3000) 
    pygame.quit()
    sys.exit()

def main():
    pantalla_inicio() 

    mensaje1 = "*Las palabras aquí mostradas forman parte de los temas vistos en lógica 1. Buena suerte!"
    mensaje1_txt = FUENTE2.render(mensaje1, True, NEGRO)
    rect1 = mensaje1_txt.get_rect(center=(ANCHO // 2, ALTO - 50))
    
    respuesta = palabra_random()
    letras_adivinadas = []
    intentos_max = 8  # Aumentado a 8 intentos
    intentos_actuales = 0

    while intentos_actuales < intentos_max:
        for evento in pygame.event.get():
            if evento.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        PANTALLA.fill(BLANCO)

        mostrar_msj_salida() 

        dibujar_ahorcado(intentos_actuales)

        palabra_mostrada, tablero_y = mostrar_tablero(respuesta, letras_adivinadas)
        palabra_mostrada_txy = FUENTE.render(palabra_mostrada, True, NEGRO)
        rect_tablero = palabra_mostrada_txy.get_rect(center=(ANCHO // 2, tablero_y))
        PANTALLA.blit(palabra_mostrada_txy, rect_tablero)

        PANTALLA.blit(mensaje1_txt, rect1)

        pygame.display.flip()

        letra_usuario = ""
        for evento in pygame.event.get():
            if evento.type == pygame.KEYDOWN:
                if evento.key == pygame.K_ESCAPE:
                    pygame.quit()
                    sys.exit()
                elif evento.key >= 97 and evento.key <= 122:  # Teclas de la A a la Z
                    letra_usuario = chr(evento.key)

        if letra_usuario:
            if letra_usuario in letras_adivinadas:
                pass
            elif letra_usuario in respuesta:
                letras_adivinadas.append(letra_usuario)
            else:
                intentos_actuales += 1

        if set(letras_adivinadas) == set(respuesta):
            felicitacion() 
            pygame.quit()
            sys.exit()

        if intentos_actuales == intentos_max:
            juego_perdido(respuesta)

    pygame.quit()
    sys.exit()


def juego_perdido(palabra_correcta):
    PANTALLA.fill(BLANCO)
    mensaje = "¡Oh no! Has agotado todos tus intentos. La palabra era:"

    fuente_msj = pygame.font.Font("C:\C\RubikDoodleShadow-Regular.ttf", 20)
    msj_txt = fuente_msj.render(mensaje, True, NEGRO)

    rect_m = msj_txt.get_rect(center=(ANCHO // 2, ALTO // 2 - 50))
    PANTALLA.blit(msj_txt, rect_m)

    resp_txt = fuente_msj.render(palabra_correcta, True, (0, 0, 255))  # Color azul
    rect_resp = resp_txt.get_rect(center=(ANCHO // 2, ALTO // 2))
    PANTALLA.blit(resp_txt, rect_resp)

    pygame.display.flip()
    pygame.time.wait(3000) 
    pygame.quit()
    sys.exit()

main()