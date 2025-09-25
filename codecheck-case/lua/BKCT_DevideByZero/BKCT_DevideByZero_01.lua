function bad_01()
    local a = 0

    local b = 1 / a
end

function bad_02()

    local b = 1 / 0
end

function bad_03()
    local a = 0
    local b = 1

    b = b / a
end

function bad_04()
    local a = nil
    local x = 10

    local z = x / a
end
