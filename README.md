# Coroutine_Task

A very thin wrapping around C++20 coroutine. This library provides a type `Coroutine_Task` as the return of a coroutine:

```
Coroutine_Task<int> Task1()
{
    log("Task1: running");
    co_return 1;
}
```

Template type is the type of the return value. 

`Coroutine_Task` is also an awaitable type, which allows a coroutine task to co_await another coroutine task:
```
Coroutine_Task<int> Task2()
{
    int r = co_await Task1() + co_await Task1();
    co_return r;
}
```
The behavior of co_await here is:
- pause the current coroutine (`Task2`);
- resume the callee coroutine (`Task1`);
- after the caller coroutine returned (completed the co_return statement), the execution would be jumped back to the caller.

TODO:
- More flexiable scheduling between coroutine task.
- More flexiable multi-thread model.
