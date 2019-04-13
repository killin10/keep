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
#include <map>
#include <utility>
#include <iostream>

#include <dlfcn.h>
#include <dirent.h>

#include "plugin.h"

const std::string kPluginDir = "plugins";
const std::string kCreateFuncName = "CreatePluginObject";

typedef Plugin* (CreateFuncType)();

// list to store opened .so handles.
std::list<void*> g_SOHandles;
// object map
std::map<int, Plugin*> g_Objects;

// To find all plugins in specified directory.
int WalkPluginDir(const std::string& plugin_dir);

// Process each plugin given.
int ProcessPlugin(const std::string& plugin_file);

// List all plugins provided.
void ListPlugins();

// Play specified plugin.
void PlayPlugin(int id);

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

    // find function address in .so file

    CreateFuncType* create =
        (CreateFuncType*) dlsym(handle, kCreateFuncName.c_str());
    if (NULL == create) {
        fprintf(stderr, "dlsym error, %s\n", dlerror());
        return -1;
    }

    Plugin* plugin = create();
    int id = plugin->Id();
    g_Objects.insert(std::make_pair(id, plugin));

    g_SOHandles.push_back(handle);
    handle = NULL;
    return 0;
}

void ListPlugins()
{
    printf("All plugins:\n");
    for (std::map<int, Plugin*>::iterator it = g_Objects.begin();
            it != g_Objects.end(); ++it) {
        printf("\t%d - %s\n", it->second->Id(), it->second->Desc());
    }
}

void PlayPlugin(int id)
{
    std::map<int, Plugin*>::iterator it = g_Objects.find(id);
    if (it == g_Objects.end()) {
        fprintf(stderr, "No such plugin!\n");
    } else {
        it->second->Print();
    }
}

void ClosePlugins()
{
    for (std::map<int, Plugin*>::iterator it = g_Objects.begin();
            it != g_Objects.end(); ++it) {
        delete it->second;
    }

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

    std::cout << "Please input the plugin id: ";
    int id = 0;
    std::cin >> id;

    PlayPlugin(id);

    ClosePlugins();
    return 0;
}

