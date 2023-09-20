//
// Created by yy on 2023/9/20.
//

#ifndef INC_408_RUNNINGTIME_H
#define INC_408_RUNNINGTIME_H
#include <chrono>
#include <forward_list>

class RunningTime {
public:
    template <typename Func, typename... Args>
    static double calculate_execution_time(Func &&func, Args &&...args)
    {
        auto start_time = std::chrono::high_resolution_clock::now();
        std::forward<Func>(func)(std::forward<Args>(args)...);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        return duration.count(); // 返回执行时间（微妙）
    }
};


#endif //INC_408_RUNNINGTIME_H
