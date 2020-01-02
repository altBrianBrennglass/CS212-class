struct Names {// part 3a
	char *first_name;
	char *last_name;
	char *jedi_name;
};

void *allocate(unsigned int size);
void deallocate(void *toBeFreed, int size);
void jedi_name(struct Names *name);
int test_name_length(char *name);
