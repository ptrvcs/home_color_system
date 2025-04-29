import mido
from mido import open_input, get_input_names, Backend

backend = Backend('mido.backends.portmidi')

print(get_input_names())  # use backend here if needed
port = open_input('Akai APC40 0', backend=backend)

for msg in port:
    print(msg)