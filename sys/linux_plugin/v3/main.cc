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
#include <list>

#include <dlfcn.h>
#include <dirent.h>

const std::string kPluginDir = "plugins";
const std::string kIdFuncName = "Id";
const std::string kDescFuncName = "Desc";

// Id function in .so files
typedef int (id_func_type)();
// Desc function in .so files
typedef const char* (desc_func_type)();

// list to store opened .so handles.
std::list<void*> g_SOHandles;
// lists to store function addresses in plugins.
std::list<id_func_type*> g_IdFuncs;
std::list<desc_func_type*> g_DescFuncs;

// To find all plugins in specified directory.
int WalkPluginDir(const std::string& plugin_dir);

// Process each plugin given.
int ProcessPlugin(const std::string& plugin_file);

// List all plugins provided.
void ListPlugins();

// Close all opened .so files.
void ClosePlugins();

int WalkPluginDir(const std::string& plugin_dir)
{
    DIR* dir = opendir(plugin_dir.c_str());
    if (NULL == dir) {
        fprintf(stderr, "opendir error, %s, %s\n", plugin_dir.c_str(),
                strerror(errno));
        return -1;
    }

    int rc = 0;
    struct dirent* ent = NULL;
    std::string base_path = plugin_dir + "/";

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(".", ent->d_name) == 0
                || strcmp("..", ent->d_name) == 0) {
            continue;
        }
        rc = ProcessPlugin(base_path + ent->d_name);
        if (rc != 0) {
            fprintf(stderr, "process plugin %s error\n", ent->d_name);
            return -1;
        }
    }

    closedir(dir);
    return 0;
}

int ProcessPlugin(const std::string& plugin_file)
{
    // open .so library file
    void* handle = NULL;
    handle = dlopen(plugin_file.c_str(), RTLD_LAZY);

    if (NULL == handle) {
        fprintf(stderr, "dlopen error, %s\n", dlerror());
        return -1;
    }

    // find function addresses in .so file

    id_func_type* id =
        (id_func_type*) dlsym(handle, kIdFuncName.c_str());
    if (NULL == id) {
        fprintf(stderr, "dlsym error, %s\n", dlerror());
        return -1;
    }
    g_IdFuncs.push_back(id);
    desc_func_type* desc =
        (desc_func_type*) dlsym(handle, kDescFuncName.c_str());
    if (NULL == desc) {
        fprintf(stderr, "dlsym error, %s\n", dlerror());
        return -1;
    }
    g_DescFuncs.push_back(desc);

    g_SOHandles.push_back(handle);
    handle = NULL;
    return 0;
}

void ListPlugins()
{
    printf("All plugins:\n");
    int rc = 0;
    std::list<desc_func_type*>::iterator desc_it = g_DescFuncs.begin();
    for (std::list<id_func_type*>::iterator id_it = g_IdFuncs.begin();
            id_it != g_IdFuncs.end(); ++id_it) {
        printf("\t%d - %s\n", (*id_it)(), (*desc_it)());
        ++desc_it;
    }
}

void ClosePlugins()
{
    for (std::list<void*>::iterator it = g_SOHandles.begin();
            it != g_SOHandles.end(); ++it) {
        dlclose(*it);
    }
}

int main(int argc, char* argv[])
{
    int rc = 0;
    rc = WalkPluginDir(kPluginDir);
    if (rc != 0) {
        fprintf(stderr, "walk plugin directory %s error\n",
                kPluginDir.c_str());
        return -1;
    }

    ListPlugins();
    ClosePlugins();
    return 0;
}

