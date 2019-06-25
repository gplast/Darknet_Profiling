#include "image.h"
#include "http_stream.h"


//
// a single-threaded, multi client(using select), debug webserver - streaming out mjpg.
//  on win, _WIN32 has to be defined, must link against ws2_32.lib (socks on linux are for free)
//

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
#include <mutex>
using std::cerr;
using std::endl;

#include "gettimeofday.h"
#include <time.h>

#include <chrono>
#include <iostream>

static std::chrono::steady_clock::time_point steady_start, steady_end;
static double total_time;
static double time_per_layer[23] = {0};

double get_time_point() {
    std::chrono::steady_clock::time_point current_time = std::chrono::steady_clock::now();
    //uint64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(current_time.time_since_epoch()).count();
    return std::chrono::duration_cast<std::chrono::microseconds>(current_time.time_since_epoch()).count();
}

void start_timer() {
    steady_start = std::chrono::steady_clock::now();
}

void stop_timer() {
    steady_end = std::chrono::steady_clock::now();
}

double get_time() {
    double took_time = std::chrono::duration<double>(steady_end - steady_start).count();
    total_time += took_time;
    return took_time;
}

void stop_timer_and_show() {
    stop_timer();
    std::cout << get_time() * 1000 << std::endl;
    // std::cout << " " << get_time() * 1000 << " msec" << std::endl;
}

void stop_timer_and_show_per_layer(int i, int average) {
    if (average == 0){
        stop_timer();
        time_per_layer[i] += get_time() * 1000;
        //std::cout << time_per_layer[i] << std::endl;
    }
    else{
        for(int j = 0; j < 23; j++){
            std::cout << time_per_layer[j]/average << std::endl;
        }
    }
    // std::cout << " " << get_time() * 1000 << " msec" << std::endl;
}

void stop_timer_and_show_name(char *name) {
    stop_timer();
    std::cout << " " << name;
    std::cout << " " << get_time() * 1000 << " msec" << std::endl;
}

void show_total_time() {
    std::cout << " Total: " << total_time * 1000 << " msec" << std::endl;
}
