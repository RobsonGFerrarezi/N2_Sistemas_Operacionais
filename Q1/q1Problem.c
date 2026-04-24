#include < pthread .h >
#include < stdio .h >
#include < unistd .h >

pthread_mutex_t conta1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t conta2 = PTHREAD_MUTEX_INITIALIZER;

void *transferencia_1(void *arg)
{
    pthread_mutex_lock(&conta1);
    sleep(1);
    pthread_mutex_lock(&conta2);

    printf(" Transferencia 1 concluida \ n ");

    pthread_mutex_unlock(&conta2);
    pthread_mutex_unlock(&conta1);
    return NULL;
}

void *transferencia_2(void *arg)
{
    pthread_mutex_lock(&conta2);
    sleep(1);
    pthread_mutex_lock(&conta1);

    printf(" Transferencia 2 concluida \ n ");

    pthread_mutex_unlock(&conta1);
    pthread_mutex_unlock(&conta2);
    return NULL;
}