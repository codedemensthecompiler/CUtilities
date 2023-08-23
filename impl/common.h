/////////////////////////////////
// This is a source file of CUtilities Toolset
//     by Dawid Jakubowski (Codedemens The Compiler)
//
//    Under MIT License
//
// CUtilities is a preset of tools responsible for all sorts of IT work.
// It ranges from development, programming, work, linux-related to hardening (IT Security) tools.
/////////////////////////////////

#ifndef CUTILITIES_COMMON_H
#define CUTILITIES_COMMON_H

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <map>
#include <set>

/////////////////////////////////
extern std::string techbuild;
extern std::string version;
/////////////////////////////////
enum CMDID {
    CMDUNKNOWN_ID,
    CUTILITIES_ID,
    CONFIGSET_ID,
    COMPILESETUP_ID,
    MAKESETUP_ID,
    BASHSETUP_ID,
    CMAKESETUP_ID,
    CPPSETUP_ID,
    LUASETUP_ID,
    CONFIGSETUP_ID,
    JSONSETUP_ID,
    ENCRYPT_ID,
    DECRYPT_ID
};



#define cmdpair(a, b) std::pair<std::string, CMDID>(a, b)
/////////////////////////////////
class Cmds {
public:
    typedef std::map<std::string, CMDID> _CmdsStringSorted;
    typedef std::map<CMDID, std::string> _CmdsIDsSorted;

    Cmds();

    inline std::set<std::string> findc(const std::vector<std::string>& args) {
        std::set<std::string> found;
        for (const auto & arg : args) {
            auto it = string_sorted.find(arg);
            if (it != string_sorted.end()) {
                found.insert(it->first);
            }
        }
        return found;
    }
    inline bool Exists(const std::string& cmd_name) {
        auto it = string_sorted.find(cmd_name);
        return it != string_sorted.end();
    }
    inline bool Exists(const CMDID& id) {
        auto it = ids_sorted.find(id);
        return it != ids_sorted.end();
    }
    inline bool Add(const std::string& cmd_name, const CMDID& cmd_id) {
        auto ip = ids_sorted.insert(std::make_pair(cmd_id, cmd_name));
        auto ip2 = string_sorted.insert(std::make_pair(cmd_name, cmd_id));

        return (ip.second && ip2.second);
    }
protected:


    _CmdsStringSorted string_sorted;
    _CmdsIDsSorted ids_sorted;
};
/////////////////////////////////
extern Cmds cmds;
/////////////////////////////////
inline bool hasa(const std::vector<std::string>& args, const std::string& arg) {
    for (int i = 0; i < args.size(); ++i) {
        if (arg.compare(args.at(i)) == 0) {
            return true;
        }
    }
    return false;
}
inline bool hasc(const std::vector<std::string>& args, const std::string& cmd) {
    return hasa(args, cmd);
}
inline bool hasc(const std::vector<std::string>& args, const CMDID& id) {
    return cmds.Exists(id);
}
inline bool hasa(const std::vector<std::string>& args, std::initializer_list<std::string> arg) {
    for (int i = 0; i < args.size(); ++i) {
        for (auto & a : arg) {
            if (a.compare(args.at(i)) == 0) {
                return true;
            }
        }
    }
    return false;
}
inline std::string findc(const std::vector<std::string>& args) {
    std::set<std::string> commands = cmds.findc(args);
    if (commands.size() == 1) {
        return commands.begin().operator*();
    }
    return "";
}
inline bool helpw(const std::vector<std::string>& args, const std::string& cmd) {
    if (hasc(args, cmd)) {
        std::string s = "./" + cmd + " --help";


        system(s.c_str());

        return true;
    }
    return false;
}
inline std::vector<std::string> argsconv(int argc, char *argv[]) {
    std::vector<std::string> args;
    for (int i = 0; i < argc; ++i) {
        args.emplace_back(argv[i]);
    }
    return args;
}
inline void initcmds(std::initializer_list<std::pair<std::string, CMDID>> initcmds) {
    for (auto & initcmd : initcmds) {
        cmds.Add(initcmd.first, initcmd.second);
    }
}

#endif //CUTILITIES_COMMON_H
