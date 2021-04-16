#ifndef __MODULEMANAGER_H_
#define __MODULEMANAGER_H_

extern int mmanager_init();

// extern int mmanager_module_load(char *modulepath);

// extern int mmanager_config_load(char *configpath);

// extern int mmanager_config_save(char *configpath);

extern int mmanager_module_cleanup();

extern int mmanager_cleanup();

extern int mmanager_exit();

#endif // __MODULEMANAGER_H_
