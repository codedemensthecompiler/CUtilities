/////////////////////////////////
/// This is a source file of CUtilities Toolset
///     by Dawid Jakubowski (Codedemens The Compiler)
///
///    Under MIT License
///
/// CUtilities is a preset of tools responsible for all sorts of IT work.
/// It ranges from development, programming, work, linux-related to hardening (IT Security) tools.
/////////////////////////////////
// CUtilities' configset

#include <common.h>

int main(int argc, char *argv[]) {
    
    std::vector<std::string> args = argsconv(argc, argv);

    if (hasa(args, {"--quiet", "--no-header"}) == false) {
        std::cout << "\033[0;92n-------------------------------------" << std::endl;
        std::cout << "\033[1;37mCUtilities' Configset" << std::endl;
        std::cout << "\033[0;37m TechBuild:   -           \033[1;37m" << techbuild << std::endl;
        std::cout << "\033[0;37m   Version:   -           \033[1;37m" << version << std::endl;
        std::cout << "\033[0;92n-------------------------------------" << std::endl;
    }
    if (hasa(args, {"--help", "--h", "-h"}) && hasa(args, {"--quiet"}) == false) {
        std::cout << "\033[0;92mPossible Commands:" << std::endl;
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
        std::cout << "\033[0;92n-------------------------------------" << std::endl;
    }


    return 0;
}