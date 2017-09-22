/*
 * @file main.cc
 * @brief Play all plugins in the "plugins" directory.
 *
 * @version 1.0
 * @date Wed Oct 31 19:34:50 2012
 *
 * @copyright Copyright (C) 2012 UESTC
 * @author shiwei<shiwei2012@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <string>

#include <dlfcn.h>
#include <dirent.h>

#include "print.h"

const std::string kPluginDir = "plugins";
const std::string kFuncName = "Print";

int PlayPlugin(const std::string& plugin_file)
{
    // open .so library file
    void* handle = NULL;
    handle = dlopen(plugin_file.c_str(), RTLD_LAZY);

    if (NULL == handle) {
        fprintf(stderr, "dlopen error, %s\n", dlerror());
        return -1;
    }

    // find function address in .so file
    typedef void (func_type)();

    func_type* print = NULL;
    print = (func_type*) dlsym(handle, kFuncName.c_str());

    if (NULL == print) {
        fprintf(stderr, "dlsym error, %s\n", dlerror());
        return -1;
    }

    // call that function
    print();

    // close .so file and release resource
    dlclose(handle);
    handle = NULL;

    return 0;
}

int main(int argc, char* argv[])
{
    DIR* dir = opendir(kPluginDir.c_str());
    if (NULL == dir) {
        fprintf(stderr, "opendir error, %s, %s\n", kPluginDir.c_str(),
                strerror(errno));
        return -1;
    }

    int rc = 0;
    struct dirent* ent = NULL;
    std::string base_path = kPluginDir + "/";

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(".", ent->d_name) == 0
                || strcmp("..", ent->d_name) == 0) {
            continue;
        }
        rc = PlayPlugin(base_path + ent->d_name);
        if (rc != 0) {
            fprintf(stderr, "play plugin %s error\n", ent->d_name);
        }
    }

    closedir(dir);

    return 0;
}


