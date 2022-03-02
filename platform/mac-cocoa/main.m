#import "qui.h"

int qu_main(int argc, char **argv, void (*init)(QuApp *))
{
    QuApp *app = QuAppA();

    if (init)
        init(app);

    app_run(app);
    app_cleanup(app);

    return 0;
}
