#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include "FaroBT.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    // Initialize Main Logger
    auto logger = spdlog::basic_logger_mt("main", "logs/main.log");                     // Create logger "main"; writes in file latest.log
    spdlog::flush_on(spdlog::level::info);                                              // Instantly save all lines
    spdlog::get("main")->set_pattern("%l [%H:%M:%S-%e %p] {%n - %s:%#} >>> %v");        // Custom layout
    SPDLOG_LOG_INFO("main", "Starting logger 'main' and opening file 'latest.log'");

    QApplication a(argc, argv);
    FaroBT w;
    w.showMaximized();
    w.show();

    return a.exec();
}
