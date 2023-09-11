#ifndef CMAKE_COROUTINE_TASK_H
#define CMAKE_COROUTINE_TASK_H

#include <coroutine>

namespace coroutine_task
{
    /// @brief Generic return type for C++20 coroutine.
    /// @tparam T : return value type.
    template<class T>
    class Coroutine_Task
    {
    public:
        struct promise_type;
        using handle = std::coroutine_handle<promise_type>;

        /// Promise type
        struct promise_type 
        {
            T _result;
            
            std::coroutine_handle<> _next = nullptr;
            Coroutine_Task get_return_object()
            {
                return Coroutine_Task<T>(handle::from_promise(*this));
            }
            std::suspend_always initial_suspend() { return {}; }
            auto final_suspend() noexcept {
                struct next_awaiter
                {
                    promise_type* me;
                    bool await_ready() noexcept { return false; }
                    std::coroutine_handle<> await_suspend(handle h) noexcept
                    {
                        if(h.promise()._next)
                            return h.promise()._next;
                        else 
                            return std::noop_coroutine();
                    }
                    void await_resume() noexcept {}
                };
                return next_awaiter{this};
            }
            // co_return
            void return_value(T r) { _result = r; }
            void unhandled_exception() {}
        };

        /// awaitable interface
        bool await_ready() { return false; }
        void await_suspend(std::coroutine_handle<> h) { 
            _h.promise()._next = h;
            // TODO: real work
            _h.resume();
        }
        T await_resume() { return _h.promise()._result; }

    private:
        /// members
        handle _h;
        
    public:
        Coroutine_Task() = delete;
        Coroutine_Task(handle h) : _h(h) {}

        /// coroutine control
        void Resume()
        {
            _h.resume();
        }

        /// @brief return
        /// @return 
        T GetReturnValue()
        {
            return _h.promise()._result;
        }
    };
}

#endif
