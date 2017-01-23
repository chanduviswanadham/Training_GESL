#include <pthread.h>

int main()
{

	pthread_attr_t tattr;
	pthread_t tid;
	int ret;
	void *stackbase;

	int size = PTHREAD_STACK_MIN + 0x4000;
	stackbase = (void *) malloc(size);

	/* initialized with default attributes */
	ret = pthread_attr_init(&tattr);

	/* setting the size of the stack also */
	ret = pthread_attr_setstacksize(&tattr, size);

	/* setting the base address in the attribute */
	ret = pthread_attr_setstackaddr(&tattr, stackbase);

	/* address and size specified */
	ret = pthread_create(&tid, &tattr, func, arg);

	return 0;

