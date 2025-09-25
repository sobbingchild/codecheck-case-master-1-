local BKCT_ForwardNull_01 = {}

function BKCT_ForwardNull_01:badMethod1()
    local str = nil
    if str == nil then
        -- bad
        print(#str) -- 在为空的分支中使用
    end
end

function BKCT_ForwardNull_01:badMethod2()
    local str = nil
    if str ~= nil then
        return
    end
    -- bad
    print(#str) -- 在为空的分支中使用
end

function BKCT_ForwardNull_01:badMethod3(str)
    if str ~= nil then
        str = nil
    end
    -- bad
    print(#str) -- 在不再次检查是否为空的情况下使用
end

function BKCT_ForwardNull_01:badMethod4(str)
    if str == nil then
        -- do nothing
    end
    -- bad
    print(#str) -- 在不再次检查是否为空的情况下使用
end

function BKCT_ForwardNull_01:goodMethod1()
    local str = nil
    if str ~= nil then
        -- good
        print(#str)
    end
end

function BKCT_ForwardNull_01:goodMethod2()
    local str = nil
    if str == nil then
        return
    end
    -- good
    print(#str)
end

function BKCT_ForwardNull_01:goodMethod3(str)
    if str == nil then
        str = "aaa"
    end
    -- good
    print(#str)
end

function BKCT_ForwardNull_01:goodMethod4(str)
    if str == nil then
        return
    end
    -- good
    print(#str)
end

return BKCT_ForwardNull_01
