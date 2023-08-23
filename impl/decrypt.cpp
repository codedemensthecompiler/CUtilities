/////////////////////////////////
/// This is a source file of CUtilities Toolset
///     by Dawid Jakubowski (Codedemens The Compiler)
///
///    Under MIT License
///
/// CUtilities is a preset of tools responsible for all sorts of IT work.
/// It ranges from development, programming, work, linux-related to hardening (IT Security) tools.
/////////////////////////////////
// CUtilities' decrypt

#include <common.h>

int main(int argc, char *argv[]) {

    std::vector<std::string> args = argsconv(argc, argv);

    if (hasa(args, {"--quiet", "--no-header"}) == false
        && hasa(args, {"--help-with", "--helpwith", "--hw", "-hw"}) == false
    ) {
        std::cout << "\033[0;92n-------------------------------------" << std::endl;
        std::cout << "\033[1;37mCUtilities' Decrypt" << std::endl;
        std::cout << "\033[0;37m TechBuild:   -           \033[1;37m" << techbuild << std::endl;
        std::cout << "\033[0;37m   Version:   -           \033[1;37m" << version << std::endl;
        std::cout << "\033[0;92n-------------------------------------" << std::endl;
    }

    if (hasa(args, {"--help", "--h", "-h"}) && hasa(args, {"--quiet"}) == false) {
        std::cout << "\033[0;92n-------------------------------------" << std::endl;
        std::cout << "\033[0;92mPossible Variables:" << std::endl;
        std::cout << "            \033[1;93mFile\033[1;37m - Filepath to file(s)" << std::endl;
        std::cout << "            " << std::endl;
        std::cout << "\033[0;92n-------------------------------------" << std::endl;
    } else if (hasa(args, {"--help-with", "--helpwith", "--hw", "-hw"})) {
        helpw(args, findc(args));
    }
}