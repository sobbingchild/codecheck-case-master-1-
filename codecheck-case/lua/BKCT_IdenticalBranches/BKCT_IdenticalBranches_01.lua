function bad_01(x, y, z)
    -- bad
    if x == 2 then
        y = 32
        z = y * 2
    else
        y = 32
        z = y * 2
    end
end

function bad_02(condition)
    -- bad
    if condition then
        print("Repeated code")
    else
        print("Repeated code")
    end
end

function good_01(condition)
    -- good
    if condition then
        print("Repeated code")
    else
        print("Another different branch")
    end
end
