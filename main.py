import pygame
import mido
import threading

# --- MIDI Setup ---
midi_input_name = next(name for name in mido.get_input_names() if 'Akai' in name or 'MIDI' in name)
midi_input = mido.open_input(midi_input_name)

# Shared color state
circle_color = [255, 255, 255]

# Background thread to listen to MIDI and update color
def midi_listener():
    global circle_color
    for msg in midi_input:
        if msg.type == 'control_change':
            # Map controller 0, 1, 2 to RGB channels
            if msg.channel == 0:
                circle_color[0] = int(msg.value / 127 * 255)
            elif msg.channel == 1:
                circle_color[1] = int(msg.value / 127 * 255)
            elif msg.channel == 2:
                circle_color[2] = int(msg.value / 127 * 255)

threading.Thread(target=midi_listener, daemon=True).start()

# --- Pygame Setup ---
pygame.init()
screen = pygame.display.set_mode((400, 400))
pygame.display.set_caption("MIDI Circle Color")
clock = pygame.time.Clock()

running = True
while running:
    # for msg in midi_input:
    #     print(msg)
    screen.fill((0, 0, 0))
    pygame.draw.circle(screen, circle_color, (200, 200), 100)
    pygame.display.flip()

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    clock.tick(60)

pygame.quit()
