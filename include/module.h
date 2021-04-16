#ifndef __MODULE_H_
#define __MODULE_H_

// Gets called when module is loaded
extern int module_load();

// Gets called when something goes wrong
extern int module_cleanup();

// Gets called when module is unloaded
extern int module_unload();

#endif // __MODULE_H_
