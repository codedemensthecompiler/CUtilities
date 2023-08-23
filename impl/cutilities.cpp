/////////////////////////////////
/// This is a source file of CUtilities Toolset
///     by Dawid Jakubowski (Codedemens The Compiler)
///
///    Under MIT License
///
/// CUtilities is a preset of tools responsible for all sorts of IT work.
/// It ranges from development, programming, work, linux-related to hardening (IT Security) tools.
/////////////////////////////////
// CUtilities' cutilities

#include <common.h>

int main(int argc, char *argv[]) {

    std::vector<std::string> args = argsconv(argc, argv);

    if (hasa(args, {"--quiet", "--no-header"}) == false
        && hasa(args, {"--help-with", "--helpwith", "--hw", "-hw"}) == false
    ) {
        std::cout << "\033[0;92n-------------------------------------" << std::endl;
        std::cout << "\033[1;37mCUtilities" << std::endl;
        std::cout << "\033[0;37m TechBuild:   -           \033[1;37m" << techbuild << std::endl;
        std::cout << "\033[0;37m   Version:   -           \033[1;37m" << version << std::endl;
        std::cout << "\033[0;92n-------------------------------------" << std::endl;
    }

    initcmds({
        cmdpair("configset", CONFIGSET_ID),
        cmdpair("cutilities", CUTILITIES_ID),
        cmdpair("compilesetup", COMPILESETUP_ID),
        cmdpair("makesetup", MAKESETUP_ID),
        cmdpair("bashsetup", BASHSETUP_ID),
        cmdpair("cmakesetup", CMAKESETUP_ID),
        cmdpair("makesetup", MAKESETUP_ID),
        cmdpair("bashsetup", BASHSETUP_ID),
        cmdpair("cppsetup", CPPSETUP_ID),
        cmdpair("luasetup", LUASETUP_ID),
        cmdpair("configsetup", CONFIGSETUP_ID),
        cmdpair("jsonsetup", JSONSETUP_ID),
        cmdpair("encrypt", ENCRYPT_ID),
        cmdpair("decrypt", DECRYPT_ID)
        });

    if (hasa(args, {"--help", "--h", "-h"}) && hasa(args, {"--quiet"}) == false) {
        std::cout << "\033[0;92mPossible Commands:" << std::endl;
        std::cout << "\033[1;93mconfigset" << std::endl;
        std::cout << "\033[0;97m    Allows to configure cutilities configuration" << std::endl;
        std::cout << "\033[0;97m    This configuration can be further used for automation of utilities usage" << std::endl;
        std::cout << "\033[0;97m    it also gives the possibiltiy to manage the configuration sets in form of presets, databases" << std::endl;
        std::cout << "\033[0;97m    configuration files, and via IDs" << std::endl;
        std::cout << "\033[0;92m  Possible Arguments for \033[0;93mconfigset:" << std::endl;
        std::cout << "\033[1;92m--help --h -h \033[0;97m(help regarding configset)" << std::endl;
        std::cout << "            " << std::endl;
        std::cout << "\033[1;93mcompilesetup" << std::endl;
        std::cout << "\033[0;97m    Allows to setup compilation process for given context." << std::endl;
        std::cout << "\033[0;97m    You can choose CMake, Make, Linux Bash as elements of setup or complete setup" << std::endl;
        std::cout << "\033[0;97m See also:\033[0;93m cmakesetup";
        std::cout << "\033[0;97m, ";
        std::cout << "\033[0;93mmakesetup";
        std::cout << "\033[0;97m, ";
        std::cout << "\033[0;93mbashsetup" << std::endl;
        std::cout << "            " << std::endl;
        std::cout << "\033[1;93mcmakesetup" << std::endl;
        std::cout << "\033[0;97m    Setup the CMake Script dynamically " << std::endl;
        std::cout << "            " << std::endl;
        std::cout << "\033[1;93mmakesetup" << std::endl;
        std::cout << "\033[0;97m    Setup the Makefile(s) dynamically" << std::endl;
        std::cout << "\033[0;97m    " << std::endl;
        std::cout << "\033[1;93mbashsetup" << std::endl;
        std::cout << "\033[0;97m    Setup the Bash File for a specific context" << std::endl;
        std::cout << "\033[0;97m    " << std::endl;
        std::cout << "\033[1;93mcppsetup" << std::endl;
        std::cout << "\033[0;97m    Setup & code C++ application." << std::endl;
        std::cout << "\033[0;97m    " << std::endl;
        std::cout << "\033[1;93mluasetup" << std::endl;
        std::cout << "\033[0;97m    Setup lua code script(s)." << std::endl;
        std::cout << "\033[0;97m    " << std::endl;
        std::cout << "\033[1;93mconfigsetup" << std::endl;
        std::cout << "\033[0;97m    Setup configuration file(s)/db(s)." << std::endl;
        std::cout << "\033[0;97m    " << std::endl;
        std::cout << "\033[1;93mjsonsetup" << std::endl;
        std::cout << "\033[0;97m    Setup json configuration file(s)" << std::endl;
        std::cout << "\033[0;97m    " << std::endl;
        std::cout << "\033[1;93mencrypt" << std::endl;
        std::cout << "\033[0;97m    Encrypt specific file(s)" << std::endl;
        std::cout << "\033[0;97m    " << std::endl;
        std::cout << "\033[1;93mdecrypt" << std::endl;
        std::cout << "\033[0;97m    Decrypt specific file(s)" << std::endl;
        std::cout << "\033[0;97m    " << std::endl;
        std::cout << "\033[0;92n-------------------------------------" << std::endl;
        std::cout << "\033[0;92mPossible Variables:" << std::endl;
        std::cout << "            \033[1;93mConfigID\033[1;37m - Configration ID" << std::endl;
        std::cout << "            \033[1;93mConfigFile\033[1;37m - Configration File" << std::endl;
        std::cout << "            \033[1;93mConfigPreset\033[1;37m - Configration Preset" << std::endl;
        std::cout << "            \033[1;93mConfigRes\033[1;37m - Configration ID, Configuration File, or Configuration Preset" << std::endl;
        std::cout << "            \033[1;93mLog\033[1;37m - Log ID, Log File" << std::endl;
        std::cout << "            " << std::endl;
        std::cout << "\033[0;92n-------------------------------------" << std::endl;
        std::cout << "\033[0;92mGeneral Arguments:" << std::endl;
        std::cout << "\033[0;92m--help --h -h:" << std::endl;
        std::cout << "            \033[1;37mShows this help message" << std::endl;
        std::cout << "            " << std::endl;
        std::cout << "\033[0;92m--construct:" << std::endl;
        std::cout << "            \033[1;37mConstructs Utility Configuration" << std::endl;
        std::cout << "            \033[1;37mIf there are no arguments, flags or additional commands provided, " << std::endl;
        std::cout << "            \033[1;37mit generates then it from defaults" << std::endl;
        std::cout << "            " << std::endl;
        std::cout << "\033[0;92m--echo:" << std::endl;
        std::cout << "            \033[1;37mOutput Mode, shows all arguments regarding provided context." << std::endl;
        std::cout << "            \033[1;37mContexts:" << std::endl;
        std::cout << "            \033[1;93m    Configuration\033[1;37m (--config \033[1;93mConfigRes\033[1;37m)" << std::endl;
        std::cout << "            \033[1;93m    Log\033[1;37m (--config \033[1;93mLog\033[1;37m)" << std::endl;
        std::cout << "\033[0;92n-------------------------------------" << std::endl;
    } else if (hasa(args, {"--help-with", "--helpwith", "--hw", "-hw"})) {
        helpw(args, findc(args));
    }


    return 0;
}