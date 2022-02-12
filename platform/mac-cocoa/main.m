#import "qui.h"

int qui_main_init(int argc, char **argv, int (*init)(QuApp *))
{
    int success = 0;
    QuApp *app = QuAppA();

    if (init)
        success = init(app);

    if (!success)
        qui_die("failed initialize app");

    app_run(app);
    app_cleanup(app);

    return 0;
}
