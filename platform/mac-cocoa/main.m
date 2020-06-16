#import "qui.h"
#import "private.h"

int qui_main(int argc, char **argv)
{
    return qui_main_init(argc, argv, __app_default_init);
}

int qui_main_init(int argc, char **argv, int (*init)(struct app *))
{
    int success = 0;
    struct app *a = app_new();

    if (init)
        success = init(a);

    if (!success)
        qui_die("failed initialize app");

    app_run(a);
    app_cleanup(a);

    return 0;
}
