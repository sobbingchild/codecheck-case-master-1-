function bad_01()
    return -- bad
    print("This code is unreachable")
end

function bad_02()
    if true then
        return -- bad
        print("This code is unreachable")
    end
end

function bad_03()
    for i = 0, 9 do
        if i > 5 then
            break
            -- bad
            local a = 1
        end
    end
end

function bad_04()
    local i = 5
    while i > 0 do
        i = i - 1
        if i < 2 then
            break
            -- bad
            local a = 1
        end
    end
end
