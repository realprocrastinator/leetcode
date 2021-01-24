/*
 * @lc app=leetcode id=1117 lang=c
 *
 * [1117] Building H2O
 */

// @lc code=start
typedef struct
{
    // User defined data may be declared here.
    pthread_cond_t cv_H;
    pthread_cond_t cv_O;
    pthread_mutex_t lock;
    int nH;

} H2O;

H2O *h2oCreate()
{
    H2O *obj = (H2O *)malloc(sizeof(H2O));
    if (pthread_mutex_init(&obj->lock, NULL))
    {
        printf("failed!\n");
        return NULL;
    }

    if (pthread_cond_init(&obj->cv_H, NULL))
    {
        printf("failed!\n");
        return NULL;
    }

    if (pthread_cond_init(&obj->cv_O, NULL))
    {
        printf("failed!\n");
        return NULL;
    }
    obj->nH = 0;
    // Initialize user defined data here.
    return obj;
}

void hydrogen(H2O *obj)
{
    pthread_mutex_lock(&obj->lock);
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    while (obj->nH == 2)
    {
        pthread_cond_broadcast(&obj->cv_O);
        pthread_cond_wait(&obj->cv_H, &obj->lock);
    }
    obj->nH++;
    releaseHydrogen();
    if (obj->nH == 2)
    {
        pthread_cond_broadcast(&obj->cv_O);
    }
    pthread_mutex_unlock(&obj->lock);
}

void oxygen(H2O *obj)
{
    pthread_mutex_lock(&obj->lock);
    // releaseOxygen() outputs "O". Do not change or remove this line.
    while (obj->nH != 2)
    {
        pthread_cond_wait(&obj->cv_O, &obj->lock);
    }
    obj->nH = 0;
    releaseOxygen();
    pthread_cond_broadcast(&obj->cv_H);
    pthread_mutex_unlock(&obj->lock);
}

void h2oFree(H2O *obj)
{
    // User defined data may be cleaned up here.
    pthread_mutex_destroy(&obj->lock);
    pthread_cond_destroy(&obj->cv_H);
    pthread_cond_destroy(&obj->cv_O);
    free(obj);
}
// @lc code=end
