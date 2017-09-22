/*
 * @file plugin.h
 * @brief Interface definition of a plugin.
 *
 * @version 1.0
 * @date Wed Oct 31 19:36:27 2012
 *
 * @copyright Copyright (C) 2012 UESTC
 * @author shiwei<shiwei2012@gmail.com>
 */

#ifndef PLUGIN_V4_PLUGIN_H_

class Plugin {
public:
    Plugin() {}
    virtual ~Plugin() {}
    virtual int Id() = 0;
    virtual const char* Desc() = 0;
    virtual void Print() = 0;
};

extern "C" {

Plugin* CreatePluginObject();

}

#endif   // PLUGIN_V4_PLUGIN_H_

