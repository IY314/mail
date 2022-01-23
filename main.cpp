#include "argparse/argparse.hpp"
#include <curl/curl.h>
#include <iostream>
#include <vector>

enum Command {
    cmd_register,
    cmd_inbox,
    cmd_see,
    cmd_send,
};

Command get_command(argparse::ArgumentParser *args, int argc, char *argv[]) {
    const std::vector<std::string> commands{"register", "inbox", "see", "send"};

    if (argc < 2) {
        std::cerr << "mail: invalid command" << std::endl;
        std::exit(127);
    }
    args->add_argument("command")
        .help("the command to execute");
    try {
        args->parse_args(2, argv);
    } catch (std::runtime_error &error) {
        std::cerr << "mail: " << error.what() << std::endl << *args;
        std::exit(1);
    }
    std::string cmd = args->get("command");
    if (cmd == "register") return cmd_register;
    else if (cmd == "inbox") return cmd_inbox;
    else if (cmd == "see") return cmd_see;
    else if (cmd == "send") return cmd_send;
    else {
        std::cerr << "mail: unknown command '" << cmd << "'\n";
        std::exit(127);
    }
}

void mail_register(argparse::ArgumentParser *args, int argc, char *argv[]) {

}

int main(int argc, char *argv[]) {
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
    if (curl) {
        CURLcode res;

        curl_easy_setopt(curl, CURLOPT_URL, "https://");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL)
    }

    return 0;
}
