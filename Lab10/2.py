def fib(n, memo=None):
    if memo is None:
        memo = {}
        
    if n in memo:
        return memo[n]
        
    # base cases
    if n == 1 or n == 2:
        result = 1
        
    else:
        result = fib(n - 1, memo) + fib(n - 2, memo)
        
    # store in memo
    memo[n] = result
    
    return result

print(fib(50))