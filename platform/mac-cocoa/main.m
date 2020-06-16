#import "qui.h"
#import "private.h"

int qui_main(int argc, char **argv)
{
    return qui_main_init(argc, argv, __app_default_init);
}

int qui_main_init(int argc, char **argv, int (*init)(QuApp *))
{
    int success = 0;
    QuApp *app = app_new();

    if (init)
        success = init(app);

    if (!success)
        qui_die("failed initialize app");

    app_run(app);
    app_cleanup(app);

    return 0;
}
