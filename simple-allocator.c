#define BUFSIZE 1000       // size of the allocator buffer
static char buf[BUFSIZE];  // buffer to allocate bytes from
char *next_free_ptr = buf; // pointer to starting of next free byte of buffer

// function to allocate n bytes of memory from buffer
char *alloc(int n) {
  // check if buffer has place to hold n bytes
  if (buf + BUFSIZE - next_free_ptr >= n) {
    next_free_ptr += n; // increment pointer by n as we have allocated n bytes
    return next_free_ptr - n; // return starting position of allocated byte
  } else {
    return 0;
  }
}

// function to free byte pointed by given pointer
void afree(char *p) {
  // check if pointer lies within the allocation buffer
  if (p >= buf && p + BUFSIZE) {
    next_free_ptr = p;
  }
}
