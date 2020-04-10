-- define uma função fatorial
function fact(n)
    if n == 0 then 
        return 1
    else
        if n < 0 then
            n = n * -1
            c =  n * fact(n-1)
            c = c * -1
            return c
        else
            if n > 0 then
                return n * fact(n-1)
            end
        end
    end
end
---[[
print("entre com um número: ")
a = io.read("*number") -- lê um número
print(fact(a))
--]]