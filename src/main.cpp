// main.cpp — entry point. Wires config and subsystems together.

#include "humanizeaitext/settings.h"
#include "humanizeaitext/humanizer.h"
#include "humanizeaitext/patterns.h"
#include "humanizeaitext/paraphrase.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    humanizeaitext::Settings settings = humanizeaitext::Settings::load_default();
    humanizeaitext::Humanizer humanizer(settings.store_path);
    humanizeaitext::Patterns patterns(settings.store_path);
    humanizeaitext::Paraphrase paraphrase(settings.store_path);
    std::fprintf(stderr, "[humanize-ai-text] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
